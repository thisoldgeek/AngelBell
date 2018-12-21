#include <SoftRcPulseOut.h>
SoftRcPulseOut myservo;


/*
  Based on Blink
  Turns on a solenoid for just 82 msec, 
  then delay a random number of secs between min and max
 
  This example code is in the public domain.
 */

SoftRcPulseOut servo1;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
          
int pos = 0;    // variable to store the servo position  
 
long randNumber;
// first two for testing,short delays
 //long minDelay = 2000;
 //long maxDelay = 3000;

// next two for production, long delays between activation
long minDelay = 30000;
long maxDelay = 120000;
int servo_pin = 5;

void setup() {
// setup servo
  pinMode(servo_pin, OUTPUT);     
  servo1.attach(servo_pin);
  servo1.setMaximumPulse(2200);

// setup solenoid
  pinMode(2, OUTPUT);
   randomSeed(analogRead(0));  // unconnected analog pin 0 creates noise used for random number generation
}   

void loop() {
  randNumber = random(minDelay, maxDelay);
  delay(randNumber);              // wait for a moment
  //delay(3000);              // wait used for testing
  
  digitalWrite(2, HIGH);   // activate solenoid
  delay(82);              // wait for a moment
  digitalWrite(2, LOW);    // solenoid off

  wave_flag();            // wave the flag back and forth
  }

void wave_flag()
  {
    uint32_t StartMs;

  digitalWrite(servo_pin, HIGH);   // turn the servo_pin on (HIGH is the voltage level)
  //servo1.write(30);
  servo1.write(290);
  /* Refresh pos during 2 sec */
  StartMs=millis();
  while(millis() - StartMs < 500UL)
  {
    SoftRcPulseOut::refresh(); //without argument, refresh occurs every 20 ms (internal to the lib)
  }

  digitalWrite(servo_pin, LOW);    // turn the servo_pin off by making the voltage LOW
  //servo1.write(130);
  servo1.write(60);
  /* Refresh pos during 2 sec */
  StartMs=millis();
  while(millis() - StartMs < 500UL)
  {
    SoftRcPulseOut::refresh(); //without argument, refresh occurs every 20 ms (internal to the lib)
  }

   digitalWrite(servo_pin, HIGH);   // turn the servo_pin on (HIGH is the voltage level)
  //servo1.write(30);
  servo1.write(290);
  // Refresh pos during 2 sec
  StartMs=millis();
  while(millis() - StartMs < 500UL)
  {
    SoftRcPulseOut::refresh(); //without argument, refresh occurs every 20 ms (internal to the lib)
  }

  digitalWrite(servo_pin, LOW);    // turn the servo_pin off by making the voltage LOW
  //servo1.write(130);
  servo1.write(60);
  // Refresh pos during 2 sec 
  StartMs=millis();
  while(millis() - StartMs < 500UL)
  {
    SoftRcPulseOut::refresh(); //without argument, refresh occurs every 20 ms (internal to the lib)
  }

digitalWrite(servo_pin, HIGH);   // turn the servo_pin on (HIGH is the voltage level)
  //servo1.write(30);
  servo1.write(290);
  // Refresh pos during 2 sec
  StartMs=millis();
  while(millis() - StartMs < 500UL)
  {
    SoftRcPulseOut::refresh(); //without argument, refresh occurs every 20 ms (internal to the lib)
  }

  digitalWrite(servo_pin, LOW);    // turn the servo_pin off by making the voltage LOW
  //servo1.write(130);
  servo1.write(60);
  // Refresh pos during 2 sec 
  StartMs=millis();
  while(millis() - StartMs < 500UL)
  {
    SoftRcPulseOut::refresh(); //without argument, refresh occurs every 20 ms (internal to the lib)
  }

 // return to start position
   digitalWrite(servo_pin, HIGH);   // turn the servo_pin on (HIGH is the voltage level)
  //servo1.write(30);
  servo1.write(0);
  /* Refresh pos during 2 sec */
  StartMs=millis();
  while(millis() - StartMs < 500UL)
  {
    SoftRcPulseOut::refresh(); //without argument, refresh occurs every 20 ms (internal to the lib)
  }
}
