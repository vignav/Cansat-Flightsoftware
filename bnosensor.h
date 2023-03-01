#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>


Adafruit_BNO055 bno = Adafruit_BNO055();

float SEALEVELPRESSURE_HPA = 1013.25;
float BMPtemprature,BMPpressure,BMPaltitude;

//BNO code 

//return 0 if calibrated 
//returns accel calibration if not calibrated
//Run in loop until output turns 0
int bnoCalibration()
{
  uint8_t system, gyro, accel, mg = 0;
  bno.getCalibration(&system, &gyro, &accel, &mg);
  if (gyro == 3 && accel == 3)
      return(0);
  return (int) (accel+1);
}

float bnoYAngle()
{
  sensors_event_t event;
  bno.getEvent(&event);
  return (float)event.orientation.y;
}

float bnoXAngle()
{
  sensors_event_t event;
  bno.getEvent(&event);
  return (float)event.orientation.x;
}

float bnoZAngle()
{
  sensors_event_t event;
  bno.getEvent(&event);
  return (float)event.orientation.z;
}

float bnoAcc()
{
  imu::Vector<3> acc = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
  return (sqrt(acc.x() * acc.x() + acc.y() * acc.y() + acc.z() * acc.z()));
}
