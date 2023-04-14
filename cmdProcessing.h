void parsePacket( String packet , String *arr , int n , char a = ',')
{
    unsigned int pos = 0;
    for (int i = 0 ; (pos = packet.indexOf(',')) != packet.length() && i < n-1 ; i++ )
    {
        arr[i] = packet.substring(0, pos);
        packet = packet.substring(pos + 1);
    }   
    arr[n-1] = packet;
}

void ST(String p[])
{   
    if ( p[3] == "GPS" ){
        //set time using gps
        setTimeGps();
    }
    else{
        String arr[3];
        parsePacket(p[3],arr,3,':');
        int hr = arr[0].toInt();
        int min = arr[1].toInt();
        int sec = arr[2].toInt();
        //set RTCtime 
        setTime_td(hr,min,sec);
    }
}

void packetCheck(String packet)
{
    int no_of_fields = 4;
    String p[no_of_fields];
    parsePacket(packet,p,no_of_fields);

    if (p[2] == "CX")
    {
        if (p[3] == "ON"){
            telemetry = true;
        }
        else if (p[3] == "OFF")
        {
            telemetry = false;
        }
    }
    else if (p[2] == "ST")
    {
        ST(p);
    }
    else if (p[2] == "SIM")
    {
        if ( currentState == IDLE ){
            if (p[3] == "ENABLE"){
                simulation_enabled = true ;
            }
            else if (p[3] == "DISABLE"){
                simulation_enabled = false;
                currentMode = FLIGHT;
            }
            else if (p[3] == "ACTIVATE" && simulation_enabled){
                currentMode = SIMULATION;
            }
        }
    }
    else if (p[2] == "SIMP")
    {
        //Set pressure to recieved value 
        if ( currentMode == SIMULATION ){
            pressure = p[3].toFloat();
        }
    }
    else if (p[2] == "CAL")
    {
        //Set zero alt calibration ( only if in idle mode )
        if ( currentState == IDLE ){
            zero_alt_calib = altitude; 
        }
        //u can use altValid to give error
    }
    else if (p[2] == "CAM")
    {
        if (p[3] == "ON"){
            
        }
        else if (p[3] == "OFF"){
            
        }
    }
    else if (p[2] == "START")
    {
        //only if in idle mode
        if( currentState == IDLE ){
            currentState = LAUNCH_WAIT;
        }
    }
    else if (p[2] == "IDLE")
    {
        currentState = IDLE;
    }
    else if (p[2] == "LAUNCH_WAIT")
    {
        currentState = LAUNCH_WAIT;
    }
    /*
     * no need because it is taken care by SIM command
    else if (p[2] == "MODE")
    {
        //only if in idle mode
        if (p[3] == "F")
        {
           currentMode = FLIGHT; 
        }
    }*/
    else if (p[2] == "CAL_TILT")
    {
        if ( currentState == IDLE ){
            tilt_calibration = true;
        }
    }
}
