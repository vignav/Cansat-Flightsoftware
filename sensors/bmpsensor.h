#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <utility/imumaths.h>
#include "Adafruit_BMP3XX.h"

Adafruit_BMP3XX bmp;

int BMPsetup(){
  if (!bmp.begin_I2C()) {   // hardware I2C mode, can pass in address & alt Wire
    //Failed to connect
    return(1);
  }

  // Set up oversampling and filter initialization
  bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
  bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
  bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
  bmp.setOutputDataRate(BMP3_ODR_50_HZ);
  return(0);
}

int BMPreading(){
  if (! bmp.performReading()) {
    //Failed to read DATA
    return(1);
  }
  return (0);
}

float bmpTemp(){
  return(bmp.temperature);
} 
float bmpAlt(){
  return(bmp.readAltitude(SEALEVELPRESSURE_HPA));
} 
float bmpPressure(){
  return(bmp.pressure / 100.0);
}  