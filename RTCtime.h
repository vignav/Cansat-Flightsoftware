#include <TimeLib.h>
#include <Wire.h>
#include <DS1307RTC.h>

void setTimeGps()
{

    return ;
}

void setTimeUtc()
{

    return ;
}

void setTime_td( int h , int m , int s , int d , int month , int year ){
    //setTime(hours, minutes, seconds, days, months, years);
    setTime( h , m , s , d , month , year); 
}

int RTCseconds(){
    return(second());
}
int RTChour(){
    return(hour());
}
int RTCminute(){
    return(minute());
}
int RTCday(){
    return(day());
}
int RTCmonth(){
    return( month());
}
int RTCyear(){
    return(year());
}
