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
        string d = to_string(day);
        string m = to_string(month);
        string yr = to_string(year);

         if(day/10 == 0)
        {
          d = "0" + d;
        }

        if (month/10==0)
        {
          m = "0" + m;
        }
        if (year/10==0)
        {
          yr = "0" + yr;
        }

        date = yr + ":" + m + ":" + d;
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
        string hr = to_string(hour);
        string min = to_string(minute);
        string sec = to_string(second);
        if(hour/10 == 0)
        {
          hr = "0" + hr;
        }

        if (minute/10==0)
        {
          min = "0" + min;
        }
        if (second/10==0)
        {
          sec = "0" + sec;
        }
        
        

        tim = hr + ":" + min + ":" +sec;
    }
    else
    {
        tim="**********" ;  
    }
    return tim;
}
