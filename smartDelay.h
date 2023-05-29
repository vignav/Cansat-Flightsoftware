
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
        updateAlt(adjusted_alt);
      }
      if (resetShort()){

        currentState = IDLE ;
        currentMode = FLIGHT ;
        packet_count = 0;
        HS_deployed = false;
        PC_deployed = false;
        MAST_raised = false;
        zero_alt_calib = 0;
        
        EEwriteInt(currentState , 1);
        EEwriteInt(currentMode, 2);
        EEwriteInt(packet_count, 3);
        EEwriteInt(zero_alt_calib, 4);
        EEwriteInt(HS_deployed, 5);
        EEwriteInt(PC_deployed, 6);
        EEwriteInt(MAST_raised, 7);
        
        telemetry = true;
        tilt_calibration = false ;
        simulation_enabled = false;

      }
      if( !SD_works){
        SDsetup();
      }
  } while (millis() - start < ms );

}
