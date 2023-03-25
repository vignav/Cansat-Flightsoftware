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
#define pressLen 8
#define altiLen 7
#define latiLen 7
#define longiLen 7
#define satLen 2
#define tiltLen 6
#define voltlen 4
String str_states[] = { "              IDLE","         LAUNCH_WAIT" , "            ASCENT" ,  "           DESCENT" ,  " PAYLOAD_SEPARATED" , "PARACHUTE_DEPLOYED" , "            LANDED"};
String str_modes[] = { "F" , "S" };

String makeTelemetryPacket( int packet_count, int MODE, int STATE, float alt, bool HS_DEPLOYED, bool PC_DEPLOYED, bool MAST_RAISED, float temp, float pressure, float voltage, int gpss, int gpsm, int gpsh , float gps_altitude, float gps_latitude, float gps_longitude, int gps_sats, float tilt_x, float tilt_y, String CMD_ECHO , bool gpstimeValid , bool gpsaltValid , bool gpslocValid , bool satsValid , bool bmpValid, bool bnoValid)
{
    String MISSION_TIME = printTime( RTChour() ,RTCminute() , RTCseconds(), true  );
    String PACKET_COUNT = printInt(packet_count, packetLength, true); 
    String ALTITUDE = printFloat(alt, altitudeLen, 1,bmpValid);
    String TEMPERATURE = printFloat(temp, tempLen, 1,bmpValid);
    String PRESSURE = printFloat(pressure, pressLen, 1, bmpValid);
    String VOLTAGE = printFloat(voltage, voltlen, 1, true);
    String GPS_TIME = printTime( gpsh ,gpsm, gpss, gpstimeValid  );
    String GPS_ALTITUDE = printFloat(gps_altitude, altiLen, 1, gpsaltValid);
    String GPS_LATITUDE = printFloat(gps_latitude, latiLen, 4, gpslocValid);
    String GPS_LONGITUDE = printFloat(gps_longitude, longiLen, 4, gpslocValid);
    String GPS_SATS = printInt(gps_sats, satLen, satsValid);
    String TILT_X = printFloat(tilt_x, tiltLen, 2, bnoValid);
    String TILT_Y = printFloat(tilt_y, tiltLen, 2, bnoValid);
    String comma = ",";

    String packet = "1062";
    packet += comma + MISSION_TIME + comma + PACKET_COUNT + comma + str_modes[MODE] + comma + str_states[STATE]+ comma + ALTITUDE + comma + (HS_DEPLOYED?"P":"N") + comma + (PC_DEPLOYED?"C":"N") + comma + (MAST_RAISED?"M":"N") + comma + TEMPERATURE + comma + PRESSURE + comma + VOLTAGE + comma + GPS_TIME + comma + GPS_ALTITUDE + comma + GPS_LATITUDE + comma + GPS_LONGITUDE + comma + GPS_SATS + comma + TILT_X + comma + TILT_Y + comma + CMD_ECHO;
    return packet;
}
