#include <Metro.h>

#include "SPI.h"
#include "ILI9341_t3n.h"

boolean changeCol = true;
Metro screenRate = Metro(2000);

#define TFT_DC  9
#define TFT_CS  10
#define TFT_RST 8
#define screenW  320
#define screenH  240
ILI9341_t3n tft = ILI9341_t3n (TFT_CS, TFT_DC, TFT_RST);
DMAMEM uint16_t screenBuffer[screenW * screenH];   // Screen Buffer

void initScreen () {

  tft.begin();                            // Connect to LCD Screen
  tft.setRotation(3);                   // Rotate Screen 90 Degrees
  tft.setFrameBuffer(screenBuffer);   // Initialize Frame Buffer
  tft.useFrameBuffer(1);                // Use Frame Buffer

  tft.fillScreen(ILI9341_BLACK);      // Clear Screen

}

void screenTest (Metro = screenRate) {
  if (screenRate.check()) {
    changeCol = !changeCol;
  }
  if (changeCol == true) {
    tft.fillScreen(ILI9341_BLACK);
//    Serial.println (black);
  } else {
    tft.fillScreen(ILI9341_WHITE);
  //  Serial.println (white);
  }
}
