
int dataPin = 22;
const int bufferSize = 512;
int data[bufferSize];
long time1=0.0;
long time2=0.0;
int indexCell=0;
int zone;

void setup() {
  pinMode(dataPin, INPUT);
  Serial.begin(115200);
}

void collectData(){
  for(int i = 0 ; i < bufferSize; i++){
   time2 = micros();
    data[i] = pulseIn(dataPin, LOW);
    if(time2 - time1 > 1000){
      i = i + 1;
      data[i] = 999;
      }
      time1 = time2;
    }
  }


//detecting '4' and '5' addresses in the data array 
int addressDetection(int startNumber){
  int counter = 0;
  int i = startNumber + 1;
  while(data[i] == 1){
    counter = counter + 1;
    i = i + 1;
  }
  switch(counter){
    case 2:
    //address '4' detected
     indexCell = i;
     return 4;
    case 3:
    //address '5' detected
      indexCell = i;
      return 5;
    default:
    //neither detected
      indexCell = 666;
      return 666;
    }
  }

//checking wave with address '5' for zone  
int waveCheckFive(){
  int counter = 0;
  int i = indexCell;
  if(data[i] < 12 && data[i] > 6){
    Serial.println("A B sensors");
    i = i + 1;
    while(data[i] == 1){
      counter = counter + 1;
      i = i + 1;
      }
      switch(counter){
        case 2:
        //3 possible zones
          if(data[i] > 50 && data[i] < 90){
            Serial.println("    Zone 1 ____BACKUP_____");
            return 51;         
            }  
            if(data[i]>11 && data[i]<20){
              Serial.println("    Zone 2");
              return 52;
            }        
            
            if(data[i]>6 && data[i]<12){
              Serial.println("    Zone 3");
              return 53;
            }        
          break;
        case 5:
          Serial.println("    Zone 4");
          return 54;
        case 6:
          Serial.println("    Zone 5");
          return 55;
        case 7:
          Serial.println("    Zone 6");
          return 56;
        case 8:
        case 11:
          Serial.println("    Zone 0----SUPER DUPER SAFE...unless you haven't connected your sensors");
          return 50;
        default:
          Serial.println("    No match found");
          return 555;
        }
    }
  }

//checking wave with address '4' for zone  
int waveCheckFour(){
  int counter = 0;
  int i = indexCell;
  if(data[i] < 12 && data[i] > 6){
    Serial.println("C D sensors");
  }
  i = i + 1;
  while(data[i] == 1){
      counter = counter + 1;
      i = i + 1;
  }

    switch(counter){
        case 3:
        //3 possible zones
          if(data[i] > 50 && data[i] < 90){
            Serial.println("    ZONE 1____BACKUP_____");
            return 41;         
            }  
          if(data[i] > 11 && data[i] < 20){
            Serial.println("    Zone 2");
            return 42;
            }        
            
          if(data[i] > 6 && data[i] < 12){
            Serial.println("    Zone 3");
            return 43;
            }        
            break;
        case 6:
            Serial.println("    Zone 4");
            return 44;
        
        case 7:
            Serial.println("    Zone 5");
            return 45;
        
        case 8:
            Serial.println("    Zone 6");
            return 46;
        
        case 9:
        case 12:
            Serial.println("    Zone 0----SUPER DUPER SAFE...unless you haven't connected your sensors");
            return 40;
          
        default:
            Serial.println("    No match found");
            return 444;
        }
         
    }

//detecting zone   
void zoneDetection(){
  int address = 0;
  for(int startNumber = 0; startNumber < bufferSize; startNumber++){
    //Detect starting 999
    if(data[startNumber] == 999){
      address = addressDetection(startNumber);
      switch (address){
        case 4:
          zone = waveCheckFour();
          break;
        case 5:
          zone = waveCheckFive();
          break;
        default:
          break;
       }
    }
  }
}

  
void displayData(){
  for(int i = 0 ; i < bufferSize; i++){
    if(data[i] > 6){
      Serial.print(data[i]);  
      Serial.print(" ");
     }
    if(data[i] > 0 && data[i] < 6){
      Serial.print("-1-");  
      Serial.print(" ");    
     }
   }
  }

void loop() {
  collectData();
  //displayData();
  zoneDetection();
  Serial.println();
  while(1);
}

