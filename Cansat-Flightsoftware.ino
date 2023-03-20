#include "eeprom_rw.h"
#include "actuators.h"
#include "telemetry.h"
#include "./sensors/bnosensor.h"
#include "./sensors/bmpsensor.h"
#include "./sensors/gpssensor.h"

enum states {
  IDLE ,
  LAUNCH_WAIT ,
  ASCENT ,
  DECENT ,
  PAYLOAD_SEPARATED , 
  PARACHUTE_DEPLOYED ,
  LANDED
};
enum modes {
  FLIGHT,
  SIMULATION
};

int currentState = IDLE ;
int currentMode = FLIGHT ;
int packet_count=0;
float zero_alt_calib;
bool telemetry = true;

float temprature = 0 , altitude = 0 , pressure = 0 ; 
bool bmpValid = false ;

float xAngle = 0 , yAngle = 0 , zAngle = 0 , acceleration = 0 ;
bool bnoValid = false ;

float noSats = 0 , latitude = 0 , lat = 0 , gpsAltitude = 0 ;
bool satsValid = false, locValid = false, altValid = false;

int gpsSecond = 0 , gpsMinute = 0 , gpsHour = 0  , gpsDay = 0 , gpsMonth = 0, gpsYear = 0 ;
bool timeValid =false , dateValid =false ;


void setup(){
  // put your setup code here, to run once:
  // Go to EEPROM and get values of state, mode, packet_count and zero_alt_calibration
  currentState = EEreadInt(1);
  currentMode = EEreadInt(2);
  packet_count = EEreadInt(3);
  zero_alt_calib = EEreadFloat(4);

  bnoSetup();
  bmpSetup();
  gpsSetup();

}

void loop() {
  // put your main code here, to run repeatedly:
  switch(currentState){
    case IDLE:
      break;
    case LAUNCH_WAIT:
      // check if cansat has started accending if yes change state
      break;
    case ASCENT:
      // check if cansat has stopped accent and started going downwards ( decreasing altitude)
      break;
    case DECENT:
      // Check if altitude is less than 500m if yes change state to payload_separated 
      break;
    case PAYLOAD_SEPARATED:
      //Check if altitude is 200m then change state and relase parachute 
      deployProbe();
      break;
    case PARACHUTE_DEPLOYED:
      //deploy parachute function
      deployParachute();
      //If there is no movement then move to landed state
      break;
    case LANDED:
      // Open flag and just wait do nothing
      // Turn off heatsheild motor
      break;
    default:
      break;


  }
  smartDelay(0); 
}


void repetitive_Task( ){
    String Telemetry_string;
    packet_count ++;
    
    // Read Sensor Data

    //GPS data
    gpsGetTime( &gpsSecond , &gpsMinute, &gpsHour , &gpsDay, &gpsMonth , &gpsYear , &dateValid , &timeValid);        
    gpsReading(&noSats , &latitude , &lat , &gpsAltitude , &satsValid, &locValid  , &altValid );

    //BNO data
    bnoGetValues( &xAngle , &yAngle , &zAngle , &acceleration, &bnoValid );

    //BMP data
    bmpGetValues(&temprature, &altitude ,&pressure, &bmpValid);

    // Apply filter on pressure data
    
    //Make telemetry packet
    String telemetry_string ;

    //Transmit data to GCS over Xbee
    if ( telemetry  ){
        sendDataTelemetry(telemetry_string);
    }
    
    //Save Data to sd card
    
    // Save state to EEPROM
    EEwriteInt(currentState , 1);
    EEwriteInt(currentMode, 2);
    EEwriteInt(packet_count, 3);
    
    //Process recieved commmands
    
    //get packet 
    //process it 



}
