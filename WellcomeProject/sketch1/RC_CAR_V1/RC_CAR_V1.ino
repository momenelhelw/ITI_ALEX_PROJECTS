#define echoPin 3
#define trigPin 2

int m1a = 9;  //back the two right wheels
int m1b = 10; //forward the two right wheels
int m2a = 11; //forward the two left wheels
int m2b = 12; //back the two left wheels
long duration;
int distance;
char val;
const int buzzer = 6; //buzzer to arduino pin 6

void setup() 
{
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(buzzer, OUTPUT); // Set buzzer - pin 6 as an output
pinMode(m1a, OUTPUT);  // Digital pin 9 set as output Pin
pinMode(m1b, OUTPUT);  // Digital pin 10 set as output Pin
pinMode(m2a, OUTPUT);  // Digital pin 11 set as output Pin
pinMode(m2b, OUTPUT);  // Digital pin 12 set as output Pin
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600);
}

void loop()
{
  while (Serial.available() > 0)
  {
  val = Serial.read();
  Serial.println(val);
  }
  // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034;
distance/=2;

if (distance < 20)
{
do{
digitalWrite(m1a, LOW);
digitalWrite(m1b, LOW);
digitalWrite(m2a, LOW);
digitalWrite(m2b, LOW);

  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(10);          // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(10);          // ...for 1sec
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);    // turn the LED on (HIGH is the voltage level)
      delay(100);               // wait for a second
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);     // turn the LED off by making the voltage LOW
      delay(100);               // wait for a second

  delay(200);
   digitalWrite(m1a, HIGH);       //right wheel back
    digitalWrite(m1b, LOW);       //right wheel forward
    digitalWrite(m2a, LOW);       //left wheel forward
    digitalWrite(m2b, HIGH);      //left wheel back
    delay(200);
   digitalWrite(m1a, LOW);
   digitalWrite(m1b, LOW);
   digitalWrite(m2a, LOW);
   digitalWrite(m2b, LOW);    
    break;    
  
}while(distance < 20);

}
else
{
  
   
  if( val == 'F') // Forward
    {
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);
      digitalWrite(8, HIGH);        
    }
  else if(val == 'B') // Backward
    {

      tone(buzzer, 1000);    // Send 1KHz sound signal...
        delay(10);            // ...for 1 sec
        noTone(buzzer);        // Stop sound...
        delay(10);              // ...for 1sec
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);    // turn the LED on (HIGH is the voltage level)
      delay(100);               // wait for a second
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);     // turn the LED off by making the voltage LOW // wait for a second
      digitalWrite(m1a, HIGH);  //right wheel back
      digitalWrite(m1b, LOW);   //right wheel forward
      digitalWrite(m2a, LOW);   //left wheel forward
      digitalWrite(m2b, HIGH);  //left wheel back      
    }
  
    else if(val == 'L') //Left
    {
      digitalWrite(8, LOW);
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, HIGH);
    }
    
    else if(val == 'R') //Right
    { 
      digitalWrite(8, LOW);   
    digitalWrite(m1a, HIGH);  //right wheel back
    digitalWrite(m1b, LOW);   //right wheel forward
    digitalWrite(m2a, HIGH);  //left wheel forward
    digitalWrite(m2b, LOW);   //left wheel back
    }
    
   else if(val == 'S') //Stop
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 
    }
    
  else if(val == 'I') //Forward Right
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
    }
    
  else if(val == 'J') //Backward Right
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, HIGH);
    }
    
   else if(val == 'G') //Forward Left
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, LOW);  
    digitalWrite(m2b, LOW);
    }
    
   else if(val == 'H') //Backward Left
    {
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 
    }
    
    else if(val == 'U')
    {
        digitalWrite(7, HIGH); // turn the LED on (HIGH is the voltage level)
        delay(1000);
    }
    
    else if (val == 'u')
    {
        digitalWrite(7, LOW); // turn the LED on (HIGH is the voltage level)
        delay(1000);
    }
    
    else if(val == 'W')
    {
        digitalWrite(8, HIGH); // turn the LED on (HIGH is the voltage level)
        delay(1000);
    }
    
    else if (val == 'w')
    {
        digitalWrite(8, LOW); // turn the LED on (HIGH is the voltage level)
        delay(1000);
    }

    else if(val == 'V')
    {
        tone(buzzer, 1000); // Send 1KHz sound signal...
        delay(1000);
    }
    
    else if (val == 'v')
    {
        noTone(buzzer);
        delay(1000);
    } 


// Prints the distance on the Serial Monitor
}
Serial.print("Distance: ");
Serial.println(distance);

}
