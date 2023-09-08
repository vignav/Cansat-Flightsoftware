#include <string>
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
#define pressLen 8
#define altiLen 7
#define latiLen 7
#define longiLen 7
#define satLen 2
#define tiltLen 6
#define voltlen 4
String str_states[] = { 
    "              IDLE",
    "       LAUNCH_WAIT", 
    "            ASCENT",
    "           DESCENT",
    " PAYLOAD_SEPARATED",
    "PARACHUTE_DEPLOYED",
    "            LANDED"
};
String str_modes[] = { "F" , "S" };

String makeTelemetryPacket()
{
    String MISSION_TIME = printTime( RTChour() ,RTCminute() , RTCseconds(), true  );
    String PACKET_COUNT = printInt(packet_count, packetLength, true); 
    String ALTITUDE = printFloat(adjusted_alt, altitudeLen, 1,pressureValid);
    String TEMPERATURE = printFloat(temprature, tempLen, 1,bmpValid);
    String VOLTAGE = printFloat(voltage, voltlen, 1, true);
    String PRESSURE = printFloat(adjusted_pressure, pressLen, 1, pressureValid);
    String GPS_TIME = printTime( gpsHour ,gpsMinute, gpsSecond, timeValid  );
    String GPS_ALTITUDE = printFloat(gpsAltitude, altiLen, 1, altValid);
    String GPS_LATITUDE = printFloat(lat, latiLen, 6, locValid);
    String GPS_LONGITUDE = printFloat(lng, longiLen, 6, locValid);
    String GPS_SATS = printInt(noSats, satLen, satsValid);
    String TILT_X = printFloat(xAngle, tiltLen, 2, bnoValid);
    String TILT_Y = printFloat(yAngle, tiltLen, 2, bnoValid);
    String comma = ",";

    String packet = "1062";
    packet += comma + MISSION_TIME + comma + PACKET_COUNT + comma + str_modes[currentMode] + comma + str_states[currentState]+ comma + ALTITUDE + comma + (HS_deployed?"P":"N") + comma + (PC_deployed?"C":"N") + comma + (MAST_raised?"M":"N") + comma + TEMPERATURE + comma + VOLTAGE + comma + PRESSURE  + comma + GPS_TIME + comma + GPS_ALTITUDE + comma + GPS_LATITUDE + comma + GPS_LONGITUDE + comma + GPS_SATS + comma + TILT_X + comma + TILT_Y + comma + CMD_ECHO;
    CMD_ECHO = "" ;
    return packet;
}
