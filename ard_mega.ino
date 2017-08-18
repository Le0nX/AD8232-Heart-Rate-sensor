int count = 0;
int count1 = 500;
int count2 = 1000;

unsigned long  sum=0;
unsigned long  res=0;

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  pinMode(10, INPUT); // Setup for leads off detection LO +
  pinMode(11, INPUT); // Setup for leads off detection LO -

}

void loop() {
  
  if((digitalRead(10) == 1)||(digitalRead(11) == 1)){
    Serial.println("nope");
  }
  else{
    
      //Serial.println(analogRead(A0)); send to processing
      
      sum += analogRead(A0);
      count++; 
         
      if (count > 30){
        res = sum / count;
        //Serial.println("\n");
        //Serial.println("\n");
        Serial.println(res);
        delay(500);
        count = 0;
        sum = 0;
        res = 0;  
      }
  }
  
  //Wait for a bit to keep serial data from saturating
  delay(1);
}
