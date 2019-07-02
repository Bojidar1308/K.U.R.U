int leftMotorPin1 = ; 
int leftMotorPin2 = ; 
int rightMotorPin1 = ; 
int rightMotorPin2 = ; 

int turnSignalFL = ; 
int turnSignalFR = ; 
int turnSignalRL = ; 
int turnSignalRR = ; 

int stopLightRL = ; 
int stopLightRR = ; 

int lightFL = ; 
int lightFR = ; 

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
    
}
