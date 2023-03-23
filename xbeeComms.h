#include <string>


#define xbeeSerial Serial
#define xbeeBaud 9600

String xbeeCommandinput = "";
void xbeeSetup(){
    xbeeSerial.begin(xbeeBaud);
}

void sendDataTelemetry(String telemetry)
{
    xbeeSerial.println(telemetry+String("\n"));
}

bool packetAvailable(){
    return( xbeeCommandinput.length() != 0 );
}

String recieveDataTelemetry()
{
    while ( xbeeSerial.available() ){
        char nextchar = xbeeSerial.read();
        if ( nextchar == '\n'){
            xbeeCommandinput += "|";
        }
        else {
            xbeeCommandinput += String(nextchar);
        }
    }
}

String getOnePacket(){
    String packet = xbeeCommandinput.subString(0,xbeeCommandinput.indexOf('|'));
    xbeeCommandinput = xbeeCommandinput.subString(xbeeCommandinput.indexOf('|')+1);
    return packet;
}
