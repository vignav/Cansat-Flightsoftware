
// This custom version of delay() ensures that the gps object
// is being "fed".
static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
      recieveDataTelemetry(); 
      processGps();
      if ( currentMode == FLIGHT ){
        bmpGetValues(&temprature, &altitude ,&pressure, &bmpValid);
        updateAlt(altitude);
      }
  } while (millis() - start < ms);
}
