const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(13,OUTPUT);
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(20);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(100);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   if(cm>11){
    Serial.print("\t LED OFF \t");
    digitalWrite(13,LOW);
   }
   else if(cm>6 && cm<=7){
    Serial.print("\t LED BLINK \t");
    digitalWrite(13,HIGH);
    delay (50);
    digitalWrite(13,LOW);
    delay(50);
   }
   else if(cm>8 && cm<=11){
    Serial.print("\t LED BLINK \t");
    digitalWrite(13,HIGH);
    delay (500);
    digitalWrite(13,LOW);
    delay(500);
   }
   else if(cm>7 && cm<=8){
    Serial.print("\t LED BLINK \t");
    digitalWrite(13,HIGH);
    delay (800);
    digitalWrite(13,LOW);
    delay(400);
   }
   
   else if(cm<=6){
   Serial.print("\t LED ON \t");
   digitalWrite(13,HIGH);
   }
   Serial.print(inches);
   Serial.print("in, ");
   
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   
   delay(450);
   

}

long microsecondsToInches( double microseconds) {
   return microseconds / 74 / 2;
     
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}