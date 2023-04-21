#include <string>
#include <SoftwareSerial.h>

#define xbeeSerial Serial8
#define xbeeBaud 9600

String xbeeCommandinput = "";
void xbeeSetup(){
    xbeeSerial.begin(xbeeBaud);
}

void sendDataTelemetry(String telemetry)
{
    xbeeSerial.println(telemetry);
}

bool packetAvailable(){
    return( xbeeCommandinput.length() != 0 );
}

void recieveDataTelemetry()
{
    while ( xbeeSerial.available() ){
        String newCmd = xbeeSerial.readStringUntil('\n');
        xbeeCommandinput += newCmd ;
        xbeeCommandinput += "|";
    }
}

String getOnePacket(){
    String packet = xbeeCommandinput.substring(0,xbeeCommandinput.indexOf('|'));
    xbeeCommandinput = xbeeCommandinput.substring(xbeeCommandinput.indexOf('|')+1);
    return packet;
}
