bool checkAlt(float alt)
{
  static int count = 0;
  static float arr[5];
  if(count<5)
  {
    arr[count] = alt;
    count++;
    return false;
  }

  
  
  int mean=0;

  for(int i=0; i<5; i++)
    mean+= arr[i];

    mean = mean/5;

    if(abs(mean-alt)>error)
    {
      return false;
    }

  for(int i=0;i<4;i++)
    arr[i] = arr[i+1];
 
  arr[4] = alt;

  return true;
}
