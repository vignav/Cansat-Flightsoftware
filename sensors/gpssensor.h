#include <TinyGPSPlus.h>
#include "returnstring.h"

TinyGPSPlus gps;
#define gpsSerial Serial1
#define gpsBaud 9600

void gpsSetup(){
  gpsSerial.begin(GPSBaud);
}

bool gpsSatsValid(){
 return (gps.satellites.isValid());
}

float gpsAlt(){
  return ( gps.altitude.meters() );
}
/*
void gpsReading(){
  printInt(gps.satellites.value(), , 5);
  printFloat(gps.location.lat(), gps.location.isValid(), 11, 6);
  printFloat(gps.location.lng(), gps.location.isValid(), 12, 6);
  gps.date; gps.time;
  gps.altitude.isValid();
}

void gpsTime(){
  gps.date.isValid();
  gps.time.isValid();
  gps.date.month(); gps.date.day(); gps.date.year();
  gps.time.hour(); gps.time.minute(); gps.time.second();
}
*/
// This custom version of delay() ensures that the gps object
// is being "fed".
static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (gpsSerial.available())
      gps.encode(gpsSerial.read());
  } while (millis() - start < ms);
}
