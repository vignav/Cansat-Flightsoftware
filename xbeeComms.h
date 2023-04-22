#include <string>
#include <SoftwareSerial.h>

#define xbeeSerial Serial8
#define xbeeBaud 9600

String xbeeCommandinput = "";
void xbeeSetup(){
    xbeeSerial.begin(xbeeBaud);
    xbeeSerial.setTimeout(100);
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
    xbeeCommandinput += xbeeSerial.readString();
}

String getOnePacket(){
    String packet = xbeeCommandinput.substring(0,xbeeCommandinput.indexOf('\n'));
    xbeeCommandinput = xbeeCommandinput.substring(xbeeCommandinput.indexOf('\n')+1);
    return packet;
}
