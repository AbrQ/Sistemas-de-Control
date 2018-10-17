#include "binary.h"

int valorLDR;
int val = 0;

int pinled1 = 12;
int pinled2 = 11;
int pinled3 = 10;
int pinled4 = 9;
int pinled5 = 8;

int pinLDR = A0;
int inPin = 13;



void setup() {
  // put your setup code here, to run once:
  
  pinMode(pinled1, OUTPUT);
  pinMode(pinled2, OUTPUT);
  pinMode(pinled3, OUTPUT);
  pinMode(pinled4, OUTPUT);
  pinMode(pinled5, OUTPUT);
  pinMode(inPin, INPUT);

  analogReference(EXTERNAL);




}

void loop() {
  // put your main code here, to run repeatedly:

  // Routine that read the DIP Switch configuration


valorLDR = analogRead(pinLDR);
val = digitalRead(inPin);

switch(val){
  case 1:
    if (valorLDR >= 1023 ){
    digitalWrite(pinled1, LOW);
    digitalWrite(pinled2, LOW);
    digitalWrite(pinled3, LOW);
    digitalWrite(pinled4, LOW);
    digitalWrite(pinled5, LOW);
  }

  else if((valorLDR >= 823) & (valorLDR < 1023)){
    digitalWrite(pinled1, HIGH);
    digitalWrite(pinled2, LOW);
    digitalWrite(pinled3, LOW);
    digitalWrite(pinled4, LOW);
    digitalWrite(pinled5, LOW);
  }

  else if((valorLDR >= 623) & (valorLDR < 823)){
    digitalWrite(pinled1, HIGH);
    digitalWrite(pinled2, HIGH);
    digitalWrite(pinled3, LOW);
    digitalWrite(pinled4, LOW);
    digitalWrite(pinled5, LOW);
  }

  else if((valorLDR >= 423) & (valorLDR < 623)){
    digitalWrite(pinled1, HIGH);
    digitalWrite(pinled2, HIGH);
    digitalWrite(pinled3, HIGH);
    digitalWrite(pinled4, LOW);
    digitalWrite(pinled5, LOW);
  }

  else if((valorLDR >= 223) & (valorLDR < 423)){
    digitalWrite(pinled1, HIGH);
    digitalWrite(pinled2, HIGH);
    digitalWrite(pinled3, HIGH);
    digitalWrite(pinled4, HIGH);
    digitalWrite(pinled5, LOW);
  }

  else{
    digitalWrite(pinled1, HIGH);
    digitalWrite(pinled2, HIGH);
    digitalWrite(pinled3, HIGH);
    digitalWrite(pinled4, HIGH);
    digitalWrite(pinled5, HIGH);
  }
  break;
  case 0:
  if (valorLDR >= 623){
    digitalWrite(pinled1, LOW);
    digitalWrite(pinled2, LOW);
    digitalWrite(pinled3, LOW);
    digitalWrite(pinled4, LOW);
    digitalWrite(pinled5, LOW);
  }
  else{
    digitalWrite(pinled1, HIGH);
    digitalWrite(pinled2, HIGH);
    digitalWrite(pinled3, HIGH);
    digitalWrite(pinled4, HIGH);
    digitalWrite(pinled5, HIGH);
  }
    break;
}

}

   
