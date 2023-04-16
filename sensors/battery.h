
#define battPin 38
#define r1 1
#define r2 2
 
void battSetup()
{
  pinMode(battPin, INPUT);
}

void readVoltage()
{
  float vJun = map(analogRead(battPin), 0, 1023, 0, 3.3); 
  voltage = ((r1 + r2)/r2)*vJun;
}
