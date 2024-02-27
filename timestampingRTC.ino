#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

void setup()
{
   Serial.begin(9600);
   if(!rtc.begin())
   {
    Serial.println("Couldn't find RTC!");
   }

   if(!rtc.isrunning())
   {
    Serial.println("RTC is NOT running, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
   }

   rtc.writeSqwPinMode(DS1307_SquareWave1HZ);
}

void loop()
{
  DateTime now =rtc.now();

  Serial.print(now.year(), DEC);
  Serial.print("/");
  Serial.print(now.month(),DEC);
  Serial.print("/");
  Serial.print(now.day(),DEC);
  Serial.print("/");Serial.print(now.hour(),DEC);
  Serial.print("/");Serial.print(now.minute(),DEC);
  Serial.print("/");Serial.println(now.second(),DEC);
  delay(1000);
}
