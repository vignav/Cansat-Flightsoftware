#define MOVINGAVG 5
bool checkAlt(float alt , float lessthanAlti)
{
  static int count = 0;
  static float arr[MOVINGAVG];
  if(count<MOVINGAVG)
  {
    arr[count] = alt;
    count++;
    return false;
  }
  
  int mean=0;
  for(int i=0; i<MOVINGAVG; i++){
    mean+= arr[i];
  }
  mean = mean/MOVINGAVG;
  
  for(int i=0;i<MOVINGAVG-1;i++){
    arr[i] = arr[i+1];
  }
  arr[MOVINGAVG-1] = alt;

  if( mean > lessthanAlti  )
  {
    return false;
  }
  else{
    return true;
  }
}
