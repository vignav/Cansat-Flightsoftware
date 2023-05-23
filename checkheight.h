#define MOVINGAVG 5
#define ERR_DIFF 1
float arr[MOVINGAVG]={0,0,0,0,0}; // add more zeros here if u are increasing MOVINGAVG
void updateAlt(float alt  )
{
  for(int i=0;i<MOVINGAVG-1;i++){
    arr[i] = arr[i+1];
  }
  arr[MOVINGAVG-1] = alt;
}
bool checkAlt(float lessthanAlti) {
  int mean=0;
  for(int i=0; i<MOVINGAVG; i++){
    mean+= arr[i];
  }
  mean = mean/MOVINGAVG;

  if( mean > lessthanAlti  )
  {
    return false;
  }
  else{
    return true;
  }
}
bool movingUp(){
  int j = 0;
  for(int i=1;i<MOVINGAVG ;i++){
    if ( arr[i] > arr[i-1] ){
      j++;
    }
  }
  if ( j*5 > 3*MOVINGAVG ){
    return true;
  }
  else {
    return false;
  }
}

bool movingDown(){
  int j = 0;
  for(int i=1;i<MOVINGAVG ;i++){
    if ( arr[i] < arr[i-1] ){
      j++;
    }
  }
  if ( j*5 > 3*MOVINGAVG ){
    return true;
  }
  else {
    return false;
  }
}

bool notMoving (){
  int j = 0;
  for(int i=1;i<MOVINGAVG ;i++){
    if ( arr[i] < arr[i-1]+ERR_DIFF || arr[i] > arr[i-1]-ERR_DIFF ){
      j++;
    }
  }
  if ( j*5 > 3*MOVINGAVG ){
    return true;
  }
  else {
    return false;
  }
}
