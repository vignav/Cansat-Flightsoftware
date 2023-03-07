//#include <iostream>
//#include <String.h>
//#include <iomanip>
//#include <sstream>
//using namespace std;



// string printFloat(double str, int len,bool valid)
// {
//   string s="";
//   string stri="";
  
//   if (valid)
//   {
//     string dot = ".";
//     stringstream s;
//     s<<str;
//     stri = s.str();
//     size_t a = stri.find(dot);
    
//     for (int i=a-1; i<len; ++i)
//       stri+=("'");
//   }
//   else
//   {
    
//     for (int i=0; i<len; i++)
//       stri+="*";
//   }
//   return stri;
// }

String addZeroSuffix(String st, int n)
{
  for(int i=1;i<=n;i++)
    st = st + "0";
  
  return st;
}

String addZeroToPrefix(String st, int n)
{
  for(int i=1;i<=n;i++)
    st = "0" + st;

  return st;
}

String printFloat(double str, int len, int lenAfterDecimal, bool valid)
{
  String finalStri;
  if (valid)
  {
    String s = String(str);
    size_t indexOfPt = s.indexOf(".");

    if((len)-(indexOfPt+1) >= lenAfterDecimal)
      finalStri = s.substring(0, (indexOfPt+1+lenAfterDecimal));
    else
    {
      int zeroToSuffix = lenAfterDecimal - (len - (indexOfPt+1));
      finalStri = addZeroSuffix(s, zeroToSuffix);
    }

      size_t lenBeforeDecimal = len - (lenAfterDecimal + 1);

      if(lenBeforeDecimal >= indexOfPt)
      {
        int zeroToPrefix = lenBeforeDecimal - indexOfPt;
        finalStri = addZeroToPrefix(finalStri, zeroToPrefix);
      }
      else
        return "INVALID";

      return finalStri;
  }
  else
  {
    
    for (int i=0; i<len; i++)
      finalStri+="*";
  }
  return finalStri;
}

// string printInt(unsigned long val, int len, bool valid)
// {
//   string str="";
//   if (valid)
//   {
//     str = to_string(val);
//     for (int i=str.size(); i<len; ++i)
//       str+=(' ');
//   }

//   else
//   {
//     for (int i=0; i<len; i++)
//       str+="*";
//   }
//   return(str);
// }
 
 String printInt(unsigned long val, int len, bool valid)
{
  String finalStr="";
  if (valid)
  {
    String st = String(val);
    size_t zeroAtPrefix = len - (st.length());
    finalStr = addZeroToPrefix(st, zeroAtPrefix);
    return finalStr;
  }

  else
  {
    for (int i=0; i<len; i++)
      finalStr+="*";
  }
  return(finalStr);
}



String printStr(const char *str, int len, bool valid)
{

    String stri="";
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

String printDate(int day, int month, int year, bool valid)
{
    String date="";
    if (valid)
    {
        String d = String(day);
        String m = String(month);
        String yr = String(year);

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

String printTime(int hour, int minute, int second, bool valid)
{
    String tim="";
    if (valid)
    {
        String hr = String(hour);
        String min = String(minute);
        String sec = String(second);
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