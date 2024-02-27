#include <Wire.h>
#include "RTClib.h"
#include <SPI.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();
RTC_DS1307 rtc;


const int potentio = 36; // Analog pin connected to the microphone output
int potentioValue = 0;  


const int ldr = 39; // Analog pin connected to the microphone output
int ldrValue = 0;  

void setup()
{
   Serial.begin(9600);
   if(!rtc.begin())
    Serial.println("Couldn't find RTC!");
  
  if(!rtc.isrunning())
   {
    Serial.println("RTC is NOT running, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
   }

   rtc.writeSqwPinMode(DS1307_SquareWave1HZ);


   tft.init();
  tft.setRotation(3); // Adjust the rotation if necessary (0 to 3)
  Serial.println("hello...");
  tft.fillScreen(TFT_BLACK); // Fill the screen with white color
  tft.setTextColor(TFT_WHITE); // Set text color to white
  tft.setTextSize(2); // Set text size to 2
  tft.setCursor(2, 2); // Set the cursor position
  tft.println("Setup success!");
  tft.setCursor(50, 100); // Set the cursor position (display on 100th pixel position from top, in that line starts at 50 th pixel position)
  tft.setTextColor(TFT_RED); // Set text color to red


  pinMode(potentio, INPUT);
  pinMode(ldr, INPUT);
}

void loop()
{
  DateTime now =rtc.now();
   potentioValue = analogRead(potentio);
   ldrValue = analogRead(ldr);


  tft.fillScreen(TFT_BLACK);
  tft.setCursor(50, 50);
  tft.print(now.year(), DEC);
  tft.print("/");
  tft.print(now.month(),DEC);
  tft.print("/");
  tft.print(now.day(),DEC);
  tft.print("/");tft.print(now.hour(),DEC);
  tft.print("/");tft.print(now.minute(),DEC);
  tft.print("/");tft.println(now.second(),DEC);

  tft.println("\n");
  tft.print("Potentiometer value: ");
  tft.println(potentioValue);
  tft.print("LDR value: ");
  tft.println(ldrValue);
  delay(1000);
}
