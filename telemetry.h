#include<iostream>
#include<string.h>
using namespace std;

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
string CX(string *p)
{
    if (p[3] == "ON")
    {
        return "ON";
    }

    if (p[3] == "OFF")
    {
        return "OFF";
    }
    else
    {
        return "invalid";
    }
}

string *ST(string *p)
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
    return arr ;
}

string SIM(string *p)
{
    if (p[3] == "ENABLE")
    {
        return "ENABLE";
    }

    if (p[3] == "DISABLE")
    {
        return "DISABLE";
    }
    else
    {
        return "invalid";
    }
}

string SIMP(string *p)
{
    return p[3] ;
}

string CAL(string *p)
{
    return 0;
}

string CAM(string *p)
{
    if (p[3] == "ON")
    {
        return "ON";
    }

    if (p[3] == "OFF")
    {
        return "OFF";
    }
    else
    {
        return "invalid";
    }
}

string START(string *p)
{
    return "ON";
}

string IDLE(string *p)
{
    return "IDLE";
}

string MODE(string *p)
{
    if (p[3] == "F")
    {
        return "F";
    }

    if (p[3] == "S")
    {
        return "S";
    }
    else
    {
        return "invalid";
    }
}

string CAL_TILT(string *p)
{
    return "CALIBRATE TILT" ;
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

