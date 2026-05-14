#include <Adafruit_NeoPixel.h> //ספריית רצועת הלדים
#include <LiquidCrystal_I2C.h> //ספריית תקשורת של מסך הlcd דרך i2c
#include <Wire.h> //ספריית תקשורת של I2C
#include "RTClib.h"

#define NUM_LEDS 16 //כמות הלדים
#define LED_PIN 16 //הדק הלדים
#define LDRpin 35 //הדק חיישן ldr
#define rainPin 36 //הדק חיישן גשם
#define LM75_ADDR 0x48 //כתובת החיישן טמפרטורה
#define fanPin 17 //הדק המאוורר
#define bulbPin 18 //הדק המנורת חימום
#define HumidPin 33 //הדק חיישן לחות האדמה
#define PumpPin 19 //הדק המשאבה
#define motor1Pin1 27 // הגדרת הדק IN1 של המנוע
#define motor1Pin2 26 //הגדרת הדק IN2 של המנוע
#define enable1Pin 14 //הגדרת הדק ena1 של המנוע

RTC_Millis rtc;
byte second,minute,hour;

int freq = 30000, pwmChannel = 0, resolution = 8 ,dutyCycle = 200;

int rainval, LDRval, humidVal; 
int LDRswitch, raw, msb, lsb;
float tempval;
bool LEDtoken, FanToken, BulbToken;

unsigned long PumpTimer = 0;

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800); //יצירת אובייקט ניאופיקסל
LiquidCrystal_I2C lcd(0x27, 20, 4); //יצירת אובייקט LiquidCrystal בשם lcd, 4 שורות 20 טורים

void setup() {

  Serial.begin(115200); //קביעת קצב תקשורת טורית בין מיקרובקר למחשב ל115200  
  Wire.begin(21, 22); //מפעילים את פרוטוקול I2C על הדקים 21, 22
 
  pinMode(fanPin, OUTPUT); //הגדרת הדק ממסר המאוורר כיציאה
  pinMode(bulbPin, OUTPUT); //הגדרת הדק ממסר המנורת חימום כיציאה
  pinMode(HumidPin, OUTPUT); //הגדרת הדק חיישן לחות כיציאה
  pinMode(PumpPin, OUTPUT); //הגדרת הדק ממסר משאבת המים כיציאה
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);

  ledcAttachChannel(enable1Pin, freq, resolution, pwmChannel);

  strip.begin(); //אתחול הלדים
  strip.show(); //כיבוי ראשוני (סוג של איפוס לדים)

  lcd.init(); //הדלקת המסך
  lcd.backlight(); //הדלקת האור מאחורי המסך (אין טקסט)

  analogSetAttenuation(ADC_11db); // קביעת טווח המדידה של חיישן הגשם ההדק ל0-3.3v
    
  rtc.begin(DateTime(F(__DATE__),F(__TIME__)));

}

void loop() {
  LDRval = LDRread(); //משתנה הערך של חיישן האור קורא לפונקציה שקוראת את הערך
  rainval = rainRead(); //משתנה הערך של חיישן הגשם קורא לפונקציה שקוראת את הערך
  tempval = tempRead(); //משתנה הערך של חיישן הטמפרטורה קורא לפונקציה שקוראת את הערך
  humidVal = humidRead(); //משתנה הערך של חיישן הלחות אדמה קורא לפונקציה שקוראת את הערך
  RTCtime();

  LEDswitch(LDRval); //קוראים לפונקצית הלדים ושולחים לה את ערך חיישן האור
  LCDscreen(LEDtoken, BulbToken, FanToken, LDRval, rainval, humidVal, tempval, hour, minute, second); //קוראים לפונקציית המסך ושולחים לה את ערך הטמפרטורה, ערך הגשם וערך חיישן האור
  fanSwitch(tempval); //קוראים לפונקצייה של המאוורר ושולחים לה את ערך הטמפרטורה
  BulbSwitch(tempval); //קוראים לפונקצייה של המנורת חימום ושולחים לה את ערך הטמפרטורה
  delay(1000);
  PumpSwitch(humidVal, rainval, hour, minute); //קוראים לפונקצייה של המשאבה ושולחים לה את הערך של חיישן לחות האדמה

}

