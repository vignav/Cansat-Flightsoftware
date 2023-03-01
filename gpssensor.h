#include <TinyGPSPlus.h>

TinyGPSPlus gps;
#define ss Serial1

static const uint32_t GPSBaud = 9600;

// This custom version of delay() ensures that the gps object
// is being "fed".
static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}
