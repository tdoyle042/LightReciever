#include <SoftwareSerial.h>

#define LIGHT_ONE 3
#define LIGHT_TWO 5
#define LIGHT_THREE 6

#define FADE_CONST 10
#define SLEEP_TIME 25

SoftwareSerial portOne(10,11);

short l1Val = 0;
short l2Val = 0;
short l3Val = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(LIGHT_ONE,OUTPUT);
  pinMode(LIGHT_TWO,OUTPUT);
  pinMode(LIGHT_THREE,OUTPUT);
}

void loop()
{
  if(Serial.available()) {
    char inByte = Serial.read();
    Serial.write(inByte);
    
    if(inByte == 'j') {
      l1Val = 255;
    } else if (inByte == 'k') {
      l2Val = 255;
    } else if (inByte == 'l') {
      l3Val = 255;
    }
  }
  
  if(l1Val > FADE_CONST) {
      analogWrite(LIGHT_ONE, l1Val);
      l1Val -= FADE_CONST; 
    } else {
      l1Val = 0;
      analogWrite(LIGHT_ONE, l1Val);
    }
    
    if(l2Val > FADE_CONST) {
      analogWrite(LIGHT_TWO, l2Val);
      l2Val -= FADE_CONST;
    } else {
      l2Val = 0;
      analogWrite(LIGHT_TWO, l2Val);
    }
    
    if(l3Val > FADE_CONST) {
      analogWrite(LIGHT_THREE, l3Val);
      l3Val -= FADE_CONST;
    } else {
      l3Val = 0;
      analogWrite(LIGHT_THREE, l3Val);
    }
    
    Serial.println(l1Val,DEC);
    Serial.println(l2Val,DEC);
    Serial.println(l3Val,DEC);
    delay(SLEEP_TIME);
  
  
}
  
  
