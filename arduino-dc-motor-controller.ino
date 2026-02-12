const int joypin = A0;   
const int motorfwd = 9;  
const int motorbck = 12;   
const int motoren = 11; 

int joy;                 
int joyneutral;            
const int deadzone = 20;    
int motorspeed;            

void setup() { 
  pinMode(motorfwd,OUTPUT);
  pinMode(motorbck,OUTPUT);
  pinMode(motoren,OUTPUT);

  joyneutral = analogRead(joypin);
  Serial.begin(9600);
}

void loop() {  

  joy = analogRead(joypin);
  Serial.print(joy);

  if((joy-joyneutral) < -deadzone){
    digitalWrite(motorfwd,HIGH);
    digitalWrite(motorbck,LOW);
    motorspeed = map(joy,joyneutral,0,0,255);
    Serial.print(" fwd ");
  }
  else if((joy-joyneutral) > deadzone){
    digitalWrite(motorfwd,LOW);
    digitalWrite(motorbck,HIGH);
    motorspeed = map(joy,joyneutral,1023,0,255);
    Serial.print(" back ");
  }
  else{
    digitalWrite(motorfwd,LOW);
    digitalWrite(motorbck,LOW);  
    Serial.print(" stop ");    
    motorspeed = 0; 
  }
  Serial.println(motorspeed);
  analogWrite(motoren,motorspeed);
  
}
