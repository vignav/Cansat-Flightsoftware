#include <Servo.h>
//#include<iostream>

#define probePin 1
#define probeDeployAngle 120
#define probeLockAngle 50

#define parachutePin 2
#define parachuteDeployAngle 180
#define parachuteLockAngle 60

#define flagPin 3
#define flagRaiseAngle 120
#define flagDownAngle 60

Servo probeServo;
Servo paraServo;
Servo flagServo;
void actuatorSetup()
{
     
    probeServo.attach(probePin);
    paraServo.attach(parachutePin);
    flagServo.attach(flagPin);
}
void deployProbe()
{
    // Turn servo to deploy probe
   
    probeServo.write(probeDeployAngle);
    return ;
}

void lockProbe()
{
    // Turn servo to lock probe
    
    probeServo.write(probeLockAngle);
    return ;
}

void deployHeatSheild()
{
    // Turn motor ( Turn pin High )
    return ;
}

void stopDeployingHeatSheild()
{
    // Stop turning motor ( Turn pin Low )
    return ;
}

void deployPrachute()
{
    // Turn servo to deploy prachute
   
    paraServo.write(parachuteDeployAngle);
    return ;
}

void lockPrachute()
{
    // Turn servo to lock prachute
   
    paraServo.write(parachuteLockAngle);
    return ;
}

void raiseFlag()
{
    // Turn servo to raise flag
   
    flagServo.write(flagRaiseAngle);
    return;
}

void lowerFlag()
{
    // Turn servo lower the flag
   
    flagServo.write(flagDownAngle);
    return;
}
