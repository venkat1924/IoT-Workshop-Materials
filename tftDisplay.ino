// Make sure library is installed like C:\Users\badari\Documents\Arduino\libraries\TFT_eSPI
// Make sure in the file User_Setup.h, file definitions related ESP32 DEVELOPMENT BOARD ARE UNCOMMENTED, refer file,ReadMe-TFT Display_kb.doc
#include <SPI.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
  tft.init();
  tft.setRotation(3); // Adjust the rotation if necessary (0 to 3)
  Serial.begin(115200);
  Serial.println("hello...");
  tft.fillScreen(TFT_BLACK); // Fill the screen with white color
  tft.setTextColor(TFT_WHITE); // Set text color to white
  tft.setTextSize(2); // Set text size to 2
  tft.setCursor(2, 2); // Set the cursor position
  tft.println("Setup success!");
  tft.setCursor(50, 100); // Set the cursor position (display on 100th pixel position from top, in that line starts at 50 th pixel position)
  tft.setTextColor(TFT_RED); // Set text color to red
  tft.setTextSize(3); // Set text size to 2
  tft.println("RV-IOT-Board");
}
void loop()
{
  
}
