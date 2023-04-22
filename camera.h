#define cameraPin 7

void cameraSetup(){
    pinMode(cameraPin,OUTPUT);
}

void cameraStart( ){
    digitalWrite(cameraPin,HIGH);
    smartDelay(200);
    digitalWrite(cameraPin,LOW);
}

void cameraStop( ){
    digitalWrite(cameraPin,HIGH);
    smartDelay(1000);
    digitalWrite(cameraPin,LOW);
}
