#include <EEPROM.h>

float readFloat( int n ){
      unsigned int eeAddress = ( sizeof(float)>sizeof(int) ? sizeof(float) : sizeof(int)) *n;
      float data = 0.00f;  
      EEPROM.get( eeAddress , data );
      return data;
}

int readInt( int n ){
      unsigned int eeAddress = ( sizeof(float)>sizeof(int) ? sizeof(float) : sizeof(int)) *n;
      int data = 0;  
      EEPROM.get( eeAddress , data );
      return data;
}

void writeFloat( float data , int n ){
      unsigned int eeAddress = ( sizeof(float)>sizeof(int) ? sizeof(float) : sizeof(int)) *n;
      EEPROM.put( eeAddress , data );
}

void writeInt( int data , int n ){
      unsigned int eeAddress = ( sizeof(float)>sizeof(int) ? sizeof(float) : sizeof(int)) *n;
      EEPROM.put( eeAddress , data );
}
