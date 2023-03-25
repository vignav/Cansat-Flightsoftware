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
bool HS_deployed = false;
bool PC_deployed = false;
bool MAST_raised = false;


float zero_alt_calib = 0;
bool telemetry = true;
bool tilt_calibration = false ;
bool simulation_enabled = false;

float voltage = 1.1;

float temprature = 0 , altitude = 0 , pressure = 0 ; 
bool bmpValid = false ;

float xAngle = 0 , yAngle = 0 , zAngle = 0 , acceleration = 0 ;
bool bnoValid = false ;

float noSats = 0 , lat = 0 , lng = 0 , gpsAltitude = 0 ;
bool satsValid = false, locValid = false, altValid = false;

int gpsSecond = 0 , gpsMinute = 0 , gpsHour = 0  , gpsDay = 0 , gpsMonth = 0, gpsYear = 0 ;
bool timeValid =false , dateValid =false ;

#include "eeprom_rw.h"
#include "actuators.h"
#include "telemetry.h"
#include "cmdProcessing.h"
#include "./sensors/bmpsensor.h"
#include "./sensors/gpssensor.h"
#include "xbeeComms.h"
#include "smartDelay.h"
#include "./sensors/bnosensor.h"

void setup(){
  // put your setup code here, to run once:
  // Go to EEPROM and get values of state, mode, packet_count and zero_alt_calibration
  currentState = EEreadInt(1);
  currentMode = EEreadInt(2);
  packet_count = EEreadInt(3);
  zero_alt_calib = EEreadFloat(4);
  HS_deployed = EEreadInt(5);
  PC_deployed = EEreadInt(6);
  MAST_raised = EEreadInt(7);
  bnoSetup();
  bmpSetup();
  gpsSetup();

}

void loop() {
  // put your main code here, to run repeatedly:
  switch(currentState){
    case IDLE:
      if(tilt_calibration){
        int tilt_cal_status = bnoCalibration();
        sendDataTelemetry(String("Tilt Calibration: ")+String(tilt_cal_status)+String("|"));
        if ( !tilt_cal_status ){
          tilt_calibration = false;
        }
      }
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
  smartDelay(1000); 
  repetitive_Task();
}


void repetitive_Task( ){
    packet_count ++;
    
    // Read Sensor Data
    //GPS data
    gpsGetTime( &gpsSecond , &gpsMinute, &gpsHour , &gpsDay, &gpsMonth , &gpsYear , &dateValid , &timeValid);        
    gpsReading(&noSats , &lat , &lat , &gpsAltitude , &satsValid, &locValid  , &altValid );
    //BNO data
    bnoGetValues( &xAngle , &yAngle , &zAngle , &acceleration, &bnoValid );
    //BMP data
    if ( currentMode == FLIGHT ){
      bmpGetValues(&temprature, &altitude ,&pressure, &bmpValid);
    }

    // Apply filter
    

    //Process recieved commmands
    String CMD_ECHO="";

    //get packet 
    if( packetAvailable() ){
      String packetRecieved = getOnePacket();
      packetCheck(packetRecieved);
    }

    //Make telemetry packet
    String telemetry_string = makeTelemetryPacket( packet_count, currentMode,currentState, altitude, HS_deployed, PC_deployed , MAST_raised , temprature, pressure, voltage, gpsSecond ,gpsMinute,gpsHour, gpsAltitude, lat , lng , noSats, xAngle,yAngle,CMD_ECHO , timeValid , altValid , locValid ,satsValid,bmpValid, bnoValid);
    Serial.println(telemetry_string);
    //Transmit data to GCS over Xbee
    if ( telemetry  ){
        sendDataTelemetry(telemetry_string);
    }
    
    //Save Data to sd card
    
    // Save state to EEPROM
    EEwriteInt(currentState , 1);
    EEwriteInt(currentMode, 2);
    EEwriteInt(packet_count, 3);
}
