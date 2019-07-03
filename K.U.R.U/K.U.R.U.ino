int leftMotorPin1 = 11; 
int leftMotorPin2 = 10; 
int rightMotorPin1 = 12; 
int rightMotorPin2 = 13; 

int turnSignalFL = 4; 
int turnSignalFR = 6; 
int turnSignalRL = 2; 
int turnSignalRR = 9; 

int stopLightRL = 3; 
int stopLightRR = 8; 

int lightFL = 5; 
int lightFR = 7; 

int state;
int flag=0;        
int stateStop=0;

void setup() 
{
    // sets the pins as outputs:
    pinMode(leftMotorPin1, OUTPUT);
    pinMode(leftMotorPin2, OUTPUT);
    pinMode(rightMotorPin1, OUTPUT);
    pinMode(rightMotorPin2, OUTPUT);

    pinMode(turnSignalFL, OUTPUT);
    pinMode(turnSignalFR, OUTPUT);
    pinMode(turnSignalRL, OUTPUT);
    pinMode(turnSignalRR, OUTPUT);

    pinMode(stopLightRL, OUTPUT);
    pinMode(stopLightRR, OUTPUT);
    
    pinMode(lightFL, OUTPUT);
    pinMode(lightFR, OUTPUT);
    
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}

void loop() 
{
    if(Serial.available() > 0)
    {     
      state = Serial.read();   
      flag=0;
    }   
     if (state == 'F') 
    {
      digitalWrite(lightFL, HIGH);
      digitalWrite(lightFR, HIGH);
      digitalWrite(stopLightRL, LOW);
      digitalWrite(stopLightRR, LOW);
      digitalWrite(turnSignalFL, LOW);
      digitalWrite(turnSignalFR, LOW);
      digitalWrite(turnSignalRL, LOW);
      digitalWrite(turnSignalRR, LOW);
      
      digitalWrite(leftMotorPin1, HIGH);
      digitalWrite(leftMotorPin2, LOW); 
      digitalWrite(rightMotorPin1, LOW);
      digitalWrite(rightMotorPin2, HIGH);
      if(flag == 0)
      {
        Serial.println("FORWARD");
        flag=1;
      }
    }
    else if (state == 'R') 
    {
      digitalWrite(lightFL, HIGH);
      digitalWrite(lightFR, HIGH);
      digitalWrite(stopLightRL, LOW);
      digitalWrite(stopLightRR, LOW);
      digitalWrite(turnSignalFL, HIGH);
      digitalWrite(turnSignalFR, LOW);
      digitalWrite(turnSignalRL, HIGH);
      digitalWrite(turnSignalRR, LOW);
      
      digitalWrite(leftMotorPin1, HIGH); 
      digitalWrite(leftMotorPin2, LOW); 
      digitalWrite(rightMotorPin1, LOW);
      digitalWrite(rightMotorPin2, LOW);
      if(flag == 0)
      {
        Serial.println("LEFT");
        flag=1;
      }
      delay(1500);
      state=3;
      stateStop=1;
    }
     else if (state == 'S' || stateStop == 1) 
    {
      digitalWrite(lightFL, HIGH);
      digitalWrite(lightFR, HIGH);
      digitalWrite(stopLightRL, HIGH);
      digitalWrite(stopLightRR, HIGH);
      digitalWrite(turnSignalFL, LOW);
      digitalWrite(turnSignalFR, LOW);
      digitalWrite(turnSignalRL, LOW);
      digitalWrite(turnSignalRR, LOW);
      
      digitalWrite(leftMotorPin1, LOW); 
      digitalWrite(leftMotorPin2, LOW); 
      digitalWrite(rightMotorPin1, LOW);
      digitalWrite(rightMotorPin2, LOW);
      if(flag == 0)
      {
        Serial.println("STOP");
        flag=1;
      }
      stateStop=0;
      }
    else if (state == 'L') 
    {
      digitalWrite(lightFL, HIGH);
      digitalWrite(lightFR, HIGH);
      digitalWrite(stopLightRL, LOW);
      digitalWrite(stopLightRR, LOW);
      digitalWrite(turnSignalFL, LOW);
      digitalWrite(turnSignalFR, HIGH);
      digitalWrite(turnSignalRL, LOW);
      digitalWrite(turnSignalRR, HIGH);
      
      digitalWrite(leftMotorPin1, LOW); 
      digitalWrite(leftMotorPin2, LOW); 
      digitalWrite(rightMotorPin1, LOW);
      digitalWrite(rightMotorPin2, HIGH);
      if(flag == 0){
        Serial.println("RIGHT");
        flag=1;
      }
      delay(1500);
      state=3;
      stateStop=1;
    }
     else if (state == 'B') 
    {
      digitalWrite(lightFL, LOW);
      digitalWrite(lightFR, LOW);
      digitalWrite(stopLightRL, LOW);
      digitalWrite(stopLightRR, LOW);
      digitalWrite(turnSignalFL, HIGH);
      digitalWrite(turnSignalFR, HIGH);
      digitalWrite(turnSignalRL, HIGH);
      digitalWrite(turnSignalRR, HIGH);
      
      digitalWrite(leftMotorPin1, LOW); 
      digitalWrite(leftMotorPin2, HIGH);
      digitalWrite(rightMotorPin1, HIGH);
      digitalWrite(rightMotorPin2, LOW);
      if(flag == 0)
      {
        Serial.println("REVERSE");
        flag=1;
      }
    }
}
