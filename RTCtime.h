#include <TimeLib.h>
#include <Wire.h>
#include <DS1307RTC.h>

void setTimeGps()
{

    return ;
}

void setTime_td( int h , int m , int s , int d , int month_ , int year_ ){
    //setTime(hours, minutes, seconds, days, months, years);
    setTime( h , m , s , d , month_ , year_); 
}

void setTime_td( int h , int m , int s ){
    //setTime(hours, minutes, seconds, days, months, years);
    setTime( h , m , s ,  day() , month() , year());
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
int RTCseconds(){
    return(second());
}
int RTChour(){
    return(hour());
}
int RTCminute(){
    return(minute());
}
