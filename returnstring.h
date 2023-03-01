#include <iostream>
#include <string.h>
#include <iomanip>
#include <sstream>
using namespace std;

string printFloat(double str, int len,bool valid)
{
  string s="";
  string stri="";
  
  if (valid)
  {
    string dot = ".";
    stringstream s;
    s<<str;
    stri = s.str();
    size_t a = stri.find(dot);
    
    for (int i=a-1; i<len; ++i)
      stri+=("'");
  }
  else
  {
    
    for (int i=0; i<len; i++)
      stri+="*";
  }
  return stri;
}

string printInt(unsigned long val, int len, bool valid)
{
  string str="";
  if (valid)
  {
    str = to_string(val);
    for (int i=str.size(); i<len; ++i)
      str+=(' ');
  }

  else
  {
    for (int i=0; i<len; i++)
      str+="*";
  }
  return(str);
}
 



string printStr(const char *str, int len, bool valid)
{

    string stri="";
    if (valid)
    {
      int slen = strlen(str);
      for (int i=0; i<len; ++i)
          if (i<slen)
              stri+=str[i];
          else
              stri+=" ";
    }
    else
    {
      for (int i=0; i<len; ++i)
        stri+="*";
    }
    return stri;

}

string printDate(int day, int month, int year, bool valid)
{
    string date="";
    if (valid)
    {
        stringstream sday;
        sday<<setw(2)<<setfill('0') << day;
        string sDay = sday.str();
        
        stringstream smonth;
        smonth<<setw(2)<<setfill('0') << month;
        string sMonth = smonth.str();
        
        stringstream syear;
        syear<<setw(4)<<setfill('0') << year;
        string sYear = syear.str();
        
        date = date + sDay + ":" + sMonth + ":" + sYear;
    }
    else
    {
        date="**********" ;  
    }
    return date;
}

string printTime(int hour, int minute, int second, bool valid)
{
    string tim="";
    if (valid)
    {
        stringstream shour;
        shour<<setw(2)<<setfill('0') << hour;
        string sHour = shour.str();
        
        stringstream sminute;
        sminute<<setw(2)<<setfill('0') << minute;
        string sMinute = sminute.str();
        
        stringstream ssecond;
        ssecond<<setw(2)<<setfill('0') << second;
        string sSecond = ssecond.str();
        
        tim = tim + sHour + ":" + sMinute + ":" + sSecond;
    }
    else
    {
        tim="**********" ;  
    }
    return tim;
}
