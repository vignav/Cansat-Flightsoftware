#include<string.h>
using namespace std;

string makeTelemetryPacket( /* inputs required to do it  */ ){
    string packet = "";
    // using returnString function and the inputs make strings and combine them with commas and make the packet 
    // has to be implimented 
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
