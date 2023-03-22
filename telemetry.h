#include <string>
#include "RTCtime.h"
#include "returnstring.h"

//TEAM_ID, MISSION_TIME, PACKET_COUNT, MODE, STATE, ALTITUDE,
//11
//HS_DEPLOYED, PC_DEPLOYED, MAST_RAISED, TEMPERATURE, VOLTAGE,
//PRESSURE, GPS_TIME, GPS_ALTITUDE, GPS_LATITUDE, GPS_LONGITUDE,
//GPS_SATS, TILT_X, TILT_Y, CMD_ECHO [,,OPTIONAL_DATA]

#define TEAM_ID 1062
#define packetLength 6
#define altitudeLen 5
#define tempLen 5
#define pressLen 5
#define altiLen 7
#define latiLen 7
#define longiLen 7
#define satLen 2
#define tiltLen 6
#define voltlen 2

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
String str_states[] = { "IDLE","LAUNCH_WAIT" , "ASCENT" ,  "DECENT" ,  "PAYLOAD_SEPARATED" , "PARACHUTE_DEPLOYED" , "LANDED"};
String str_modes[] = { "F" , "S" };

String makeTelemetryPacket( int packet_count, int MODE, int STATE, float alt, bool HS_DEPLOYED, bool PC_DEPLOYED, bool MAST_RAISED, float temp, float pressure, float voltage, int gpss, int gpsm, int gpsh , float gps_altitude, float gps_latitude, float gps_longitude, int gps_sats, float tilt_x, float tilt_y, String CMD_ECHO , bool gpstimeValid , bool gpsaltValid , bool gpslocValid , bool satsValid , bool bmpValid, bool bnoValid)
{
    String MISSION_TIME = printTime( RTChour() ,RTCminute() , RTCseconds(), true  );
    String PACKET_COUNT = printInt(packet_count, packetLength, true); 
    String ALTITUDE = printFloat(alt, altitudeLen, 1,bmpValid);
    String TEMPERATURE = printFloat(temp, tempLen, 1,bmpValid);
    String PRESSURE = printFloat(pressure, pressLen, 1, bmpValid);
    String VOLTAGE = printFloat(voltlen, voltlen, 1, true);
    String GPS_TIME = printTime( gpsh ,gpsm, gpss, gpstimeValid  );
    String GPS_ALTITUDE = printFloat(gps_altitude, altiLen, 1, gpsaltValid);
    String GPS_LATITUDE = printFloat(gps_latitude, latiLen, 4, gpslocValid);
    String GPS_LONGITUDE = printFloat(gps_longitude, longiLen, 4, gpslocValid);
    String GPS_SATS = printInt(gps_sats, satLen, satsValid);
    String TILT_X = printFloat(tilt_x, tiltLen, 2, bnoValid);
    String TILT_Y = printFloat(tilt_y, tiltLen, 2, bnoValid);
    String comma = ",";

    String packet = "1062";
    packet = comma + MISSION_TIME + comma + PACKET_COUNT + comma + str_modes[MODE] + comma + str_states[STATE]+ comma + ALTITUDE + comma + (HS_DEPLOYED?"P":"N") + comma + (PC_DEPLOYED?"C":"N") + comma + (MAST_RAISED?"M":"N") + comma + TEMPERATURE + comma + PRESSURE + comma + VOLTAGE + comma + GPS_TIME + comma + GPS_ALTITUDE + comma + GPS_LATITUDE + comma + GPS_LONGITUDE + comma + GPS_SATS + comma + TILT_X + comma + TILT_Y + comma + CMD_ECHO;
    return packet;
}

void parsePacket( String packet , String *arr , int n , char a = ',')
{
    unsigned int pos = 0;
    for (int i = 0 ; (pos = packet.indexOf(',')) != packet.length() && i < n-1 ; i++ )
    {
        arr[i] = packet.substring(0, pos);
        packet = packet.substring(pos + 1);
    }   
    arr[n-1] = packet;
}

void CX(String *p)
{
    if (p[3] == "ON"){
        
    }
    else if (p[3] == "OFF")
    {
        
    }
    else
    {
        
    }
}

void ST(String p[])
{   
    if ( p[3] == "GPS" ){
        //set time using gps
        setTimeGps();
    }
    else{
        String arr[3];
        parsePacket(p[3],arr,3,':');
        int hr = arr[0].toInt();
        int min = arr[1].toInt();
        int sec = arr[2].toInt();
        //set RTCtime 
        setTime_td(hr,min,sec);
    }
}

void SIM(String *p)
{
    if (p[3] == "ENABLE"){
        
    }
    else if (p[3] == "DISABLE"){
        
    }
    else{
        
    }
}

void SIMP(String *p)
{
   //Set pressure to recieved value 
}

void CAL(String *p)
{
   //Run calibration  
}

void CAM(String *p)
{
    if (p[3] == "ON"){
        
    }
    else if (p[3] == "OFF"){
        
    }
    else{
        
    }
}

void START(String *p)
{
    
}

void idleComReceived(String *p)
{
    
}

void MODE(String *p)
{
    if (p[3] == "F")
    {
        
    }

    if (p[3] == "S")
    {
        
    }
    else
    {
        
    }
}

void CAL_TILT(String *p)
{
    
}

void packetCheck(String packet)
{
    int no_of_fields = 4;
    String p[no_of_fields];
    parsePacket(packet,p,no_of_fields);

    if (p[2] == "CX")
    {
        CX(p);
    }

    if (p[2] == "ST")
    {
        ST(p);
    }

    if (p[2] == "SIM")
    {
        SIM(p);
    }

    if (p[2] == "SIMP")
    {
        SIMP(p);
    }

    if (p[2] == "CAL")
    {
        CAL(p);
    }

    if (p[2] == "CAM")
    {
        CAM(p);
    }

    if (p[2] == "START")
    {
        START(p);
    }

    if (p[2] == "IDLE")
    {
        idleComReceived(p);
    }

    if (p[2] == "MODE")
    {
        MODE(p);
    }

    if (p[2] == "CAL_TILT")
    {
        CAL_TILT(p);
    }

    else
    {
        // Fake command recieved just write that in SD card
    }
}
