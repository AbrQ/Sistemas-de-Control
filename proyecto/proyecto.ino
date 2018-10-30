#include "binary.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int valorLDR;
int val = 0;

int pinled1 = 12;
int pinled2 = 11;
int pinled3 = 10;
int pinled4 = 9;
int pinled5 = 8;

int pinLDR = A0;
int inPin = 13;

void mensaje(String mens){
//comandos para mensaje en pantalla
  lcd.begin(16,2);
  lcd.home();
  //lcd.clear();
  lcd.print("Lazo Cerrado");
  lcd.setCursor(0,1);
  lcd.print(""+String(mens)); 
  delay(1000);
}

void mensajeAbierto(String mensaj){
//comandos para mensaje en pantalla
  lcd.begin(16,2);
  lcd.home();
  //lcd.clear();
  lcd.print("Lazo Abierto");
  lcd.setCursor(0,1);
  lcd.print(""+String(mensaj)); 
  delay(1000);
}

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
    mensaje("Val>: "+String(valorLDR)+" Ohms");
    digitalWrite(pinled1, LOW);
    digitalWrite(pinled2, LOW);
    digitalWrite(pinled3, LOW);
    digitalWrite(pinled4, LOW);
    digitalWrite(pinled5, LOW);
  }

  else if((valorLDR >= 823) & (valorLDR < 1023)){
    mensaje("Val>823 & <1023 Ohms");
    digitalWrite(pinled1, HIGH);
    digitalWrite(pinled2, LOW);
    digitalWrite(pinled3, LOW);
    digitalWrite(pinled4, LOW);
    digitalWrite(pinled5, LOW);
  }

  else if((valorLDR >= 623) & (valorLDR < 823)){
    mensaje("Val>623 & <823 Ohms");
    digitalWrite(pinled1, HIGH);
    digitalWrite(pinled2, HIGH);
    digitalWrite(pinled3, LOW);
    digitalWrite(pinled4, LOW);
    digitalWrite(pinled5, LOW);
  }

  else if((valorLDR >= 423) & (valorLDR < 623)){
    mensaje("Val>423 & <623 Ohms");
    digitalWrite(pinled1, HIGH);
    digitalWrite(pinled2, HIGH);
    digitalWrite(pinled3, HIGH);
    digitalWrite(pinled4, LOW);
    digitalWrite(pinled5, LOW);
  }

  else if((valorLDR >= 223) & (valorLDR < 423)){
    mensaje("Val>223 & <423 Ohms");
    digitalWrite(pinled1, HIGH);
    digitalWrite(pinled2, HIGH);
    digitalWrite(pinled3, HIGH);
    digitalWrite(pinled4, HIGH);
    digitalWrite(pinled5, LOW);
  }

  else{
    mensaje("Val< 223 Ohms");
    digitalWrite(pinled1, HIGH);
    digitalWrite(pinled2, HIGH);
    digitalWrite(pinled3, HIGH);
    digitalWrite(pinled4, HIGH);
    digitalWrite(pinled5, HIGH);
  }
  break;
  case 0:
  if (valorLDR >= 623){
    mensajeAbierto("Val>: "+String(valorLDR)+" Ohms");
    digitalWrite(pinled1, LOW);
    digitalWrite(pinled2, LOW);
    digitalWrite(pinled3, LOW);
    digitalWrite(pinled4, LOW);
    digitalWrite(pinled5, LOW);
  }
  else{
    mensajeAbierto("Val<: "+String(valorLDR)+" Ohms");
    digitalWrite(pinled1, HIGH);
    digitalWrite(pinled2, HIGH);
    digitalWrite(pinled3, HIGH);
    digitalWrite(pinled4, HIGH);
    digitalWrite(pinled5, HIGH);
  }
    break;
}

}

   
