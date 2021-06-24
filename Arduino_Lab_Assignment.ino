//Arduino Lab Assignment
//Minghui YU, Yazz Andersson Linderholm

// Declaring Pins
const int buzzerPin = 2;
const int ledPin = 4;

const int lightPin = A0;
const int tiltPin = A2;


//for light sensor reading
int lightReading; 
//for tilt sensor reading
int tiltReading;

void setup()
{
  Serial.begin(9600); 
  
  //The Following are the output
  pinMode(ledPin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);

  //tilt and light is the Input
  pinMode(tiltPin, INPUT);
  pinMode(lightPin, INPUT);
  
}

void loop()
{

  lightReading = analogRead(lightPin);  //read light sensor valur from pin0
  Serial.println("light reading is: ");
  Serial.println(lightReading);  // print the analog reading
   
  tiltReading = analogRead(tiltPin);  //read tilt sensor value 
  
  //if tilt is detected, buzzer rings and LED is turned on
  if (tiltReading == HIGH) {  
   tone(buzzerPin, 1000);
   digitalWrite(ledPin, HIGH);
   delay(500);
       
   Serial.println("tilt sensor status: "); //print tilt reading
   Serial.println(tiltReading);
  } 
  //if no tilt detected, no sound and LED is off
  else {
   noTone(buzzerPin);
   digitalWrite(ledPin, LOW);
   delay(500);
  }
  
  
 // use light sensor to control LED 
  if (lightReading < 10){ //if light reading is less than 10)
    
    digitalWrite(ledPin, HIGH); //LED is light up and blinks 
    delay(500);   
  }
  
}
