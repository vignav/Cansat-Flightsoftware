#include <EEPROM.h>

float EEreadFloat( int n ){
      unsigned int eeAddress = ( sizeof(float)>sizeof(int) ? sizeof(float) : sizeof(int)) *n;
      float data = 0.00f;  
      EEPROM.get( eeAddress , data );
      return data;
}

int EEreadInt( int n ){
      unsigned int eeAddress = ( sizeof(float)>sizeof(int) ? sizeof(float) : sizeof(int)) *n;
      int data = 0;  
      EEPROM.get( eeAddress , data );
      return data;
}

void EEwriteFloat( float data , int n ){
      unsigned int eeAddress = ( sizeof(float)>sizeof(int) ? sizeof(float) : sizeof(int)) *n;
      EEPROM.put( eeAddress , data );
}

void EEwriteInt( int data , int n ){
      unsigned int eeAddress = ( sizeof(float)>sizeof(int) ? sizeof(float) : sizeof(int)) *n;
      EEPROM.put( eeAddress , data );
}
