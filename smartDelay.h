
// This custom version of delay() ensures that the gps object
// is being "fed".
static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
      if ( !bnoValid ){
        bno.begin();
        bnoValid = true;
     }
      if(!bmpValid){
        bmpSetup();
      }
      recieveDataTelemetry(); 
      processGps();
      if ( currentMode == FLIGHT ){
        bmpGetValues();
        updateAlt(altitude);
      }
  } while (millis() - start < ms);
}
