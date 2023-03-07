#include<string.h>
//using namespace std;

// string makeTelemetryPacket( /* inputs required to do it  */ ){
//     string packet = "";
//     // using returnString function and the inputs make strings and combine them with commas and make the packet 
//     // has to be implimented 
//     return packet;
// }

//TEAM_ID, MISSION_TIME, PACKET_COUNT, MODE, STATE, ALTITUDE,
//11
//HS_DEPLOYED, PC_DEPLOYED, MAST_RAISED, TEMPERATURE, VOLTAGE,
//PRESSURE, GPS_TIME, GPS_ALTITUDE, GPS_LATITUDE, GPS_LONGITUDE,
//GPS_SATS, TILT_X, TILT_Y, CMD_ECHO [,,OPTIONAL_DATA]
#include "returnstring.h"

#define TEAM_ID 1020
#define packetLength 6
#define altitudeLen 5
#define tempLen 5
#define pressLen 5
#define altiLen 7
#define latiLen 7
#define longiLen 7
#define satLen 2
#define tiltLen 6

String makeTelemetryPacket(String MISSION_TIME, int packet_count, String MODE, String STATE, float alt, String HS_DEPLOYED, String PC_DEPLOYED, String MAST_RAISED, float temp, float pressure, String VOLTAGE, String GPS_TIME, float gps_altitude, float gps_latitude, float gps_longitude, int gps_sats, float tilt_x, float tilt_y, String CMD_ECHO)
{
    String PACKET_COUNT = printInt(packet_count, packetLength, true);
    String ALTITUDE = printFloat(alt, altitudeLen, 1, true);
    String TEMPERATURE = printFloat(temp, tempLen, 1,true);
    String PRESSURE = printFloat(pressure, pressLen, 1, true);
    String GPS_ALTITUDE = printFloat(gps_altitude, altiLen, 1, true);
    String GPS_LATITUDE = printFloat(gps_latitude, latiLen, 4, true);
    String GPS_LONGITUDE = printFloat(gps_longitude, longiLen, 4, true);
    String GPS_SATS = printInt(gps_sats, satLen, true);
    String TILT_X = printFloat(tilt_x, tiltLen, 2, true);
    String TILT_Y = printFloat(tilt_y, tiltLen, 2, true);
    
    String packet = "";
    packet = TEAM_ID + "," + MISSION_TIME + "," + PACKET_COUNT + "," + MODE + "," + STATE + "," + ALTITUDE + "," + HS_DEPLOYED + "," + PC_DEPLOYED + "," + MAST_RAISED + "," + TEMPERATURE + "," + PRESSURE + "," + VOLTAGE + "," + GPS_TIME + "," + GPS_ALTITUDE + "," + GPS_LATITUDE + "," + GPS_LONGITUDE + "," + GPS_SATS + "," + TILT_X + "," + TILT_Y + "," + CMD_ECHO;
    return packet;
}

void sendDataTelemetry(string telemetry)
{

    return ;
}

string recieveDataTelemetry()
{
    // Recieve one packet
    return ;
}

string *parsePacket( string packet )
{
    int len = strlen("packet");
    string comma = ",";
    size_t pos = 0;
    string data;
    string arr[4];
    int i = 0;
    while ((pos = packet.find(comma)) != string::npos)
    {
        data = packet.substr(0, pos);
        arr[i] = data;
        packet.erase(0, pos + comma.length());
        i++;
    }   
    arr[3] = packet;
    return arr;  
    //Parse the packet and slit it into all the nessasary ints and floats 
}
void CX(string *p)
{
    if (p[3] == "ON")
    {
        
    }

    if (p[3] == "OFF")
    {
        
    }
    else
    {
        
    }
}

void *ST(string *p)
{   
    string arr[3];
    string a = p[3];
    string colon = ":";
    size_t pos = 0;
    string data;
    int i=0;
    int dat;
    while ((pos = a.find(colon)) != string::npos)
    {
        data = a.substr(0, pos);
        arr[i] = data;
        a.erase(0, pos + colon.length());
        i++;
    }  
    arr[2] = a;
    int hour = 0;
    int minute = 0;
    int second = 0;
    string h = arr[0];
    string m = arr[1];
    string s = arr[2];
    for(int i=0; i<h.length(); i++)
    {
        if(h[i]>47 && h[i]<58)
        {
            hour += h[i] - 48;
        }
    }

    for(int i=0; i<m.length(); i++)
    {
        if(m[i]>47 && m[i]<58)
        {
            minute += m[i] - 48;
        }
    }

    for(int i=0; i<s.length(); i++)
    {
        if(s[i]>47 && s[i]<58)
        {
            second += s[i] - 48;
        }
    }
}

void SIM(string *p)
{
    if (p[3] == "ENABLE")
    {
        
    }

    if (p[3] == "DISABLE")
    {
        
    }
    else
    {
        
    }
}

void SIMP(string *p)
{
    
}

void CAL(string *p)
{
    
}

void CAM(string *p)
{
    if (p[3] == "ON")
    {
        
    }

    if (p[3] == "OFF")
    {
        
    }
    else
    {
        
    }
}

void START(string *p)
{
    
}

void IDLE(string *p)
{
    
}

void MODE(string *p)
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

void CAL_TILT(string *p)
{
    
}

string packetCheck(string packet)
{
    string *p = parsePacket(packet);
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
        IDLE(p);
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
        cout<<"invalid";
    }
}
