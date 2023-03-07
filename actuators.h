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


void deployProbe()
{
    // Turn servo to deploy probe
    Servo probeServo;
    probeServo.attach(probePin);
    probeServo.write(probeDeployAngle);
    return ;
}

void lockProbe()
{
    // Turn servo to lock probe
    Servo probeServo;
    probeServo.attach(probePin);
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
    Servo paraServo;
    paraServo.attach(parachutePin);
    paraServo.write(parachuteDeployAngle);
    return ;
}

void lockPrachute()
{
    // Turn servo to lock prachute
    Servo paraServo;
    paraServo.attach(parachutePin);
    paraServo.write(parachuteLockAngle);
    return ;
}

void raiseFlag()
{
    // Turn servo to raise flag
    Servo flagServo;
    flagServo.attach(flagPin);
    flagServo.write(flagRaiseAngle);
    return;
}

void lowerFlag()
{
    // Turn servo lower the flag
    Servo flagServo;
    flagServo.attach(flagPin);
    flagServo.write(flagDownAngle);
    return;
}
