#include <TinyGPSPlus.h>
#include "returnstring.h"

TinyGPSPlus gps;
#define gpsSerial Serial1
#define gpsBaud 9600

void gpsSetup(){
  gpsSerial.begin(GPSBaud);
}

void gpsGetValues ( int *sats , bool *satsValid , float *lat , float *lng , bool *locValid , float *alt , bool *altValid ){
  *sats = gps.satellites.value();
  *satsValid = gps.satellites.isValid();
  
  *lat = gps.location.lat();
  *lng = gps.location.lng();
  *locValid = gps.location.isValid();
  
  *altValid = gps.altitude.isValid();
  *alt = gps.altitude.meters();
}

void gpsGetTime( int *hour , int *min , int *seconds , bool *timeValid , bool *dateValid , int *month , int *date , int *year ){
  *timeValid = gps.time.isValid();
  *dateValid = gps.date.isValid();
  
  *month = gps.date.month(); 
  *date = gps.date.day(); 
  *year = gps.date.year();
  *hour = gps.time.hour(); 
  *min = gps.time.minute(); 
  *seconds = gps.time.second();
}

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
