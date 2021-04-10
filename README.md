# MEGA_games_compilation_for_Pico
Addapted MEGA games compilation from https://www.tinyjoypad.com/esp8285


Components:
1) RPI PICO RP2040
2) SSD1309 128x64 SPI OLED DISPLAY
4) piezzo buzzer
5) 5 push-buttons
6) breadboards
7) multiple jumper calbles
8) optional pull-down resistors (10 Ohm), can be just wire
9) optional electrolytic condenser rated for at least 10V and 220uF


Libraries used for display:

u8g2 library:
https://github.com/olikraus/u8g2/wiki/u8g2reference

Connections:

FOR OLED DISPLAY (SPI):
--------------------------------
GND -->  Display GND
3V3(OUT) -> Display VCC
GP16 -> Display DC  (Data Command)
GP17 -> Display CS  (Channel Select)
GP18 -> Display SCL (Clock)
GP19 -> Display SDA (MOSI)
GP20 -> Display RES (Reset)

FOR BUTTONS:
--------------------------------
GP15 -> button UP
GP14 -> button DOWN
GP13 -> button LEFT
GP12 -> button RIGHT
GP11 -> button FIRE
(all buttons to GND) 

FOR BUZZER:
--------------------------------
GP10 -> Buzzer(+)
GND -> Buzzer(-)
