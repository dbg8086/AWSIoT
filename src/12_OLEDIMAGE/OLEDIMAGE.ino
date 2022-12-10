#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

static const uint8_t image_data_save[1024] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x55, 0xff, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x55, 0x7f, 0xff, 0xff, 0xd5, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbb, 0xff, 0xff, 0xff, 0xbb, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0x55, 0x55, 0x55, 0x55, 0x55, 0x7f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xae, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0x5d, 0x55, 0x55, 0x55, 0x55, 0x5f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xfb, 0xbb, 0xbb, 0xbf, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0x55, 0x55, 0x55, 0x55, 0x55, 0x5f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xee, 0xbf, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xd5, 0xd5, 0x55, 0x55, 0x55, 0x5f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbb, 0xbb, 0xbb, 0xbf, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0x75, 0x55, 0x55, 0x55, 0x55, 0x55, 0x7f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xee, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xdd, 0x55, 0x55, 0x55, 0x55, 0x55, 0x7f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xbb, 0xbb, 0xbf, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x5f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff, 0xef, 0xee, 0xef, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xfd, 0xdc, 0x00, 0x15, 0x55, 0x55, 0x55, 0x57, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x0b, 0xbb, 0xaa, 0xbb, 0xaf, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0x7d, 0x54, 0x00, 0x15, 0x55, 0x40, 0x05, 0x57, 0x7f, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x02, 0xab, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xfd, 0x55, 0x55, 0x55, 0x55, 0x55, 0x01, 0x55, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbb, 0xfb, 0xbb, 0xbb, 0xbb, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xf5, 0x55, 0x51, 0x55, 0x55, 0x55, 0x55, 0x55, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xff, 0xff, 0xee, 0xea, 0xeb, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xf5, 0xd5, 0x41, 0x55, 0x55, 0x54, 0x55, 0x55, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xbb, 0xbb, 0xb8, 0x3b, 0xbb, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0x75, 0x55, 0x51, 0x55, 0x55, 0x50, 0x15, 0x55, 0x7f, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xf8, 0x2e, 0xae, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xd5, 0x55, 0x55, 0x55, 0x55, 0x54, 0x55, 0x55, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xfa, 0xbb, 0xbb, 0xbb, 0xbb, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xf5, 0x55, 0x55, 0x54, 0x05, 0x55, 0x55, 0x55, 0x7f, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x0f, 0xee, 0xee, 0xea, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xd5, 0xd5, 0x55, 0xfc, 0x07, 0xd5, 0x55, 0x55, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbb, 0xff, 0x1f, 0xfb, 0xbb, 0xbb, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0x75, 0x55, 0x55, 0x77, 0x57, 0x55, 0x55, 0x55, 0x7f, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xee, 0xab, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xf5, 0x55, 0x55, 0xff, 0xfd, 0xd5, 0x55, 0x55, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xfb, 0xff, 0xff, 0xfb, 0xbb, 0xbb, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xf5, 0x55, 0x55, 0x77, 0x77, 0x55, 0x55, 0x55, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xea, 0xea, 0xaf, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xf5, 0x55, 0x55, 0x55, 0x5d, 0x55, 0x55, 0x55, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xfb, 0xbf, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0x75, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x57, 0x7f, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xee, 0xae, 0xaa, 0xaf, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xfd, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x57, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbf, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x57, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xaf, 0xef, 0xef, 0xee, 0xea, 0xaa, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0x5d, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x5f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xbf, 0xab, 0xbb, 0xbb, 0xbb, 0xab, 0xab, 0xbf, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x7f, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xea, 0xae, 0xaa, 0xaa, 0xaa, 0xab, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xd5, 0x51, 0x55, 0x55, 0x55, 0x55, 0x55, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xfb, 0xba, 0xbb, 0xba, 0xaa, 0xaa, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0x55, 0x54, 0x55, 0x55, 0x45, 0x55, 0x57, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xea, 0xaa, 0xaa, 0xaa, 0xaa, 0xaf, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xd5, 0x55, 0x55, 0x55, 0x55, 0x55, 0x17, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xbb, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xab, 0xff, 0xff, 0xff, 0xff, 0xff
};
 
void setup() {
  Serial.begin(115200);
 
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000); // Pause for 2 seconds
 
  // Clear the buffer.
  display.clearDisplay();
  
  // Draw bitmap on the screen
  display.drawBitmap(0, 0, image_data_save, 128, 64, 1);
  display.display();
}
 
void loop() {
  
}