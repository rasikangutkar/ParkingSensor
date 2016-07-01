int dataPin = 22;
const int bufferSize =512;
int data[bufferSize];
const int repeat = 5;
long time1=0.0;
long time2=0.0;

void setup() {
  // put your setup code here, to run once:
  pinMode(dataPin,INPUT);
  Serial.begin(115200);
}

void collectData(){
  for(int i = 0 ; i < bufferSize; i++){
    //data[i]=pulseIn(dataPin,HIGH);
   // i=i+1;
   time2=micros();
    data[i]=pulseIn(dataPin,LOW);
    if(time2-time1>1000){
      i=i+1;
      data[i]=999;
      }
      time1=time2;
    }
  
  }
void displayData(){
  for(int i = 0 ; i < bufferSize; i++){
    
    //if(data[i]<70){
      
      
    if(data[i]>6){
      
      
    Serial.print(data[i]);  
     
    Serial.print(" ");
    //i=i+1;
    //Serial.print(data[i]);  
     
      }
    //}
      if(data[i]>0 && data[i]<6){
      
    Serial.print("-1-");  
     
    Serial.print(" ");
        
        }
      }
   // Serial.print(" ");
   
    
  }
void loop() {
  
  // put your main code here, to run repeatedly:
  collectData();
  displayData();
  Serial.println();
while(1);
}

