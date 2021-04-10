#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define BUFFER_LENGTH 1024
#define PIXELWIDTH 128


// I have not found any difference between the two constructors yet
U8G2_SSD1309_128X64_NONAME0_F_4W_SW_SPI _u8g2(U8G2_R0, /* clock=*/ 18, /* data=*/ 19, /* cs=*/ 17, /* dc=*/ 16, /* reset=*/ 20);

// emulator class in order to emulate the behavior of the SSD1306 library with the U8G2 library
class DisplayEmulator
{

  public:
    uint8_t buffer[BUFFER_LENGTH];

    void display(void)
    {
      _convertVerticalToHorizontalBitmap();
      _u8g2.drawBitmap(0, 0, 16, 64, _bitmap);
      _u8g2.sendBuffer();
    }

    void init(void)
    {
      _u8g2.begin();
      //_u8g2.setBusClock(8000000);
      _u8g2.clearBuffer();
      _u8g2.setDrawColor(1);
    }

    void flipScreenVertically()
    {
      _u8g2.setDisplayRotation(U8G2_R0);
    }

    void setContrast(uint8_t contrast)
    {
      // do nothing
    }

  private:
    uint8_t _bitmap[BUFFER_LENGTH];

    // Bibsi Babsi Algo:
    void _convertVerticalToHorizontalBitmap()
    {
      const uint8_t COLS = PIXELWIDTH / 8;
      uint8_t mask;

      // initialize the array (_bitmap)
      for (int r = 0; r < BUFFER_LENGTH; r++) _bitmap[r] = 0;

      for (uint8_t y = 0; y < BUFFER_LENGTH / PIXELWIDTH; y++)
      {
        // for a byte scan all 8 lines
        for (uint8_t line = 0; line < 8; line++)
        {
          // mask must be shifted for each line
          mask = 0x01 << line;

          // scan all pixels from left to right and then shift one line down
          for (uint8_t pix = 0; pix < PIXELWIDTH; pix++)
          {
            // add up the bits for the new byte (vertical to horizontal transformation)
            _bitmap[(pix / 8) + (line * COLS) + (y * PIXELWIDTH)] += ( (buffer[pix + (y * PIXELWIDTH)] & mask) != 0) << (7 - (pix % 8));
          }
        }
      }
    }
};

// just a dummy in order to keep the existing code running
class ESPDummy
{
  public:
  void wdtFeed(void)
  {
    // do nothing;
  }
  void wdtDisable(void)
  {
    // do nothing
  }

};
