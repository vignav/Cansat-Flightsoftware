#define redLED 4
#define blueLED 3
#define greenLED 2
#define buzzerPIN 5

void led_buzzer_Setup(){
    pinMode(redLED,OUTPUT);
    pinMode(blueLED,OUTPUT);
    pinMode(greenLED,OUTPUT);
    pinMode(buzzer,OUTPUT);
}

void buzzerON(){
    digitalWrite(buzzer,HIGH);
}
void buzzerOFF(){
    digitalWrite(buzzer,LOW);
}

//LED ON
void redON(){
    digitalWrite(redLED,HIGH);
}
void blueON(){
    digitalWrite(blueLED,HIGH);
}
void greenON(){
    digitalWrite(greenLED,HIGH);
}

// LED OFF
void redOFF(){
    digitalWrite(redLED,LOW);
}
void blueOFF(){
    digitalWrite(blueLED,LOW);
}
void greenOFF(){
    digitalWrite(greenLED,LOW);
}
