//MomenElhelw
#define echoPin 3
#define trigPin 2
long duration;
int distance;
char val;
char x = 0x00 ;
char x1 = 0x00 ;
char x2 = 0x00 ;
char x3 = 0x00 ;
int counter = 0;
#define H HIGH
#define L LOW
void setup()
{

  pinMode(10, OUTPUT); //declare 7 seg Digit1 pin as output
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600);
}

void loop() {

                             while (Serial.available() > 0)
                            {
                            val = Serial.read();
                            Serial.println(val);
                            } 
                            // Clears the trigPin
                            digitalWrite(trigPin, LOW);
                            delayMicroseconds(200);
                           // Sets the trigPin on HIGH state for 10 micro seconds
                           digitalWrite(trigPin, HIGH);
                            delayMicroseconds(10);
                            digitalWrite(trigPin, LOW);
                            // Reads the echoPin, returns the sound wave travel time in microseconds
                            duration = pulseIn(echoPin, HIGH);
                            // Calculating the distance
                            distance= duration*0.034;
                            distance/=2;


digitalWrite(10, HIGH);
//display NO
digitalWrite(4,x);
digitalWrite(5,x1);
digitalWrite(6,x2);
digitalWrite(7,x3);


                            if (distance < 10 && (counter == 0 /*|| counter == 1*/))
                            {
                            x   = 0x01;
                            x1  = 0x00;
                            x2  = 0x00;
                            delay(1000);
                            do
                            {
                            digitalWrite(trigPin, LOW);
                            delayMicroseconds(200);
                           // Sets the trigPin on HIGH state for 10 micro seconds
                           digitalWrite(trigPin, HIGH);
                            delayMicroseconds(10);
                            digitalWrite(trigPin, LOW);
                            // Reads the echoPin, returns the sound wave travel time in microseconds
                            duration = pulseIn(echoPin, HIGH);
                            // Calculating the distance
                            distance= duration*0.034;
                            distance/=2;
                            delay(500);
                            }
                            while(distance <= 50);                  
                            counter++;
                            }

                            else if (distance < 10 && (counter == 1 || counter == 2))
                            {
                            //display 2
                            x  = 0x00;
                            x1 = 0x01;
                            x2 = 0x00;
                            delay(1000);
                            do
                            {
                            digitalWrite(trigPin, LOW);
                            delayMicroseconds(200);
                           // Sets the trigPin on HIGH state for 10 micro seconds
                           digitalWrite(trigPin, HIGH);
                            delayMicroseconds(10);
                            digitalWrite(trigPin, LOW);
                            // Reads the echoPin, returns the sound wave travel time in microseconds
                            duration = pulseIn(echoPin, HIGH);
                            // Calculating the distance
                            distance= duration*0.034;
                            distance/=2;
                            delay(500);
                            }
                            while(distance <= 50);  
                            counter++;
                            }

                            else if (distance < 10 && (counter == 3 || counter == 4))
                            {
                             //display 3
                            x   = 0x01;
                            x1  = 0x01;
                            x2  = 0x00;
                            delay(1000);
                            do
                            {
                            digitalWrite(trigPin, LOW);
                            delayMicroseconds(200);
                           // Sets the trigPin on HIGH state for 10 micro seconds
                           digitalWrite(trigPin, HIGH);
                            delayMicroseconds(10);
                            digitalWrite(trigPin, LOW);
                            // Reads the echoPin, returns the sound wave travel time in microseconds
                            duration = pulseIn(echoPin, HIGH);
                            // Calculating the distance
                            distance= duration*0.034;
                            distance/=2;
                            delay(500);
                            }
                            while(distance <= 50);                              
                            counter++;
                            }

                            else if (distance < 10 && (counter == 5 || counter == 6 || counter == 7 ))
                            {
                            //display 4
                            x   = 0x00;
                            x1  = 0x00;
                            x2  = 0x01;
                            delay(500);
                            do
                            {
                            digitalWrite(trigPin, LOW);
                            delayMicroseconds(200);
                           // Sets the trigPin on HIGH state for 10 micro seconds
                           digitalWrite(trigPin, HIGH);
                            delayMicroseconds(10);
                            digitalWrite(trigPin, LOW);
                            // Reads the echoPin, returns the sound wave travel time in microseconds
                            duration = pulseIn(echoPin, HIGH);
                            // Calculating the distance
                            distance= duration*0.034;
                            distance/=2;
                            delay(500);
                            }
                            while(distance <= 50); 
                            counter++;
                            if(counter == 8)
                            {
                            counter=0;
                            x=0x00;
                            x1=0x00;
                            x2=0x00;
                            delay(3000);
                            }
                            
                            }
}