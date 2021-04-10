//   >>>>>  T-I-N-Y  L-A-N-D-E-R v1.0 for ATTINY85  GPLv3 <<<<
//              Programmer: (c) Roger Buehler 2020
//              Contact EMAIL: tscha70@gmail.com
//        Official repository:  https://github.com/tscha70/
//  Tiny Lander v1.0 is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.

//  You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//     
//  This game uses features or part of code created by 
//  Daniel C (Electro L.I.B) https://www.tinyjoypad.com under GPLv3
//  to work with tinyjoypad game console's standard.

#define NUMOFGAMES 10
#define VLimit 100
#define MoveY 15
#define MoveX 15
#define TrustY 1
#define TrustX 1
#define GRAVITYDECY 1
#define FULLTHRUST 18
#define ACCELERATOR 35
#define LANDINGSPEED 35
#define BONUSSPEED1 13
#define BONUSSPEED2 24

#define DIGITSIZE 4
#define SCOREOFFSET 1
#define SCOREDIGITS 5
#define VELODIGITS 4
#define VELOOFFSET 5


void SOUND(uint8_t freq_, uint8_t dur);
void TINYJOYPAD_INIT(void);
void INTROSOUND(void);
void VICTORYSOUND(void);
void ALERTSOUND(void);
void HAPPYSOUND(void);
void SPLITDIGITS(uint16_t val, uint8_t *digits);

// GameLevel: Level, ShipPosX, ShipPosY, Fuel / 100, LevelScore, FuelBonus
const uint8_t GAMELEVEL [][5] PROGMEM = {
  {44, 33, 150, 10, 75},   // entry-level (L1)
  {110, 33, 150, 20, 75},  // canyon (L2)
  {34, 30, 150, 20, 50},   // b-level (L1)
  {42, 25, 100, 40, 20},   // the-drop (L2)
  {29, 40, 100, 40, 20},   // pik (L2)
  {35, 40, 75, 60, 10},    // pinnacles (L3)
  {113, 30, 120, 60, 10},  // funnel (L3)
  {28, 10, 150, 120, 10},  // journey (L4)
  {30, 5, 150, 120, 10},   // the-zack (L4)
  {26, 49, 150, 240, 5},   // slalom (L5)
};

// GameMap
const uint8_t GAMEMAP [][27] PROGMEM = {
  // entry-level (1)
  {63, 44, 32, 22, 12, 6, 4, 6, 10, 18, 16, 20, 12, 36, 38, 30, 28, 26, 10, 2, 0, 0, 0, 2, 10, 28, 40},
  {63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63,  63,  63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63},

  // canyon (2)
  {63, 10, 0, 0, 0, 14, 18, 14, 30, 20, 16, 19, 12, 25, 30, 30, 27, 28, 26, 4, 1, 1, 4, 4, 10, 15, 63},
  {63, 63, 63, 45, 40, 50, 63, 63, 63, 63, 55, 63, 63, 63, 63, 50, 55, 45, 50, 63, 63, 63, 63, 55, 60, 60, 63},

  // b-level (1)
  {1, 1, 9, 15, 18, 20, 22, 20, 18, 15, 9, 1, 1, 9, 15, 18, 20, 22, 20, 18, 15, 9, 1, 0, 0, 0, 0},
  {38, 38, 38, 63, 63, 63, 63, 58, 53, 48, 43, 38, 43, 48, 53, 58, 63, 63, 63, 63, 38, 38, 38, 38, 38, 38, 38},

  // the-drop (2)
  {63, 40, 30, 20, 15, 12, 10, 12, 15, 20, 30, 40, 45, 46, 45, 36, 30, 28, 15, 10, 5, 0, 0, 0, 0, 4, 63},
  {63, 63, 63, 63, 55, 63, 60, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 55, 45, 40, 30, 30, 63, 63, 63, 63},

  // pik (2)
  {30, 2, 3, 3, 2, 12, 12, 1, 20, 20, 15, 10, 7, 5, 5, 7, 12, 20, 22, 22, 22, 22, 18, 0, 0, 0, 0},
  {30, 54, 60, 50, 50, 40, 59, 40, 48, 40, 45, 50, 53, 55, 55, 53, 47, 40, 38, 38, 38, 60, 38, 60, 34, 32, 25},

  // pinnacles (3)
  {5, 3, 2, 2, 5, 12, 10, 12, 15, 40, 42, 40, 0, 0, 0, 40, 45, 40, 10, 8, 5, 2, 2, 2, 7, 8, 9},
  {63, 55, 63, 63, 55, 63, 55, 63, 63, 60, 63, 63, 63, 63, 63, 63, 63, 63, 55, 55, 57, 57, 63, 63, 63, 63, 63},

  // funnel (3)
  {0, 0, 0, 0, 20, 23, 1, 23, 22, 1, 20, 19, 18, 1, 16, 15, 1, 13, 12, 11, 10, 1, 8, 7, 6, 5, 4},
  {20, 30, 36, 36, 62, 36, 36, 37, 63, 39, 40, 41, 42, 63, 44, 63, 46, 47, 63, 49, 50, 62, 52, 63, 54, 55, 56},

  // journey (4)
  {35, 35, 25, 5, 5, 5, 5, 10, 10, 5, 5, 30, 40, 45, 45, 40, 30, 20, 40, 20, 20, 48, 0, 0, 0, 7, 40},
  {63, 63, 63, 63, 63, 35, 30, 30, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63},

  // the-zack (4)
  {45, 45, 45, 20, 20, 20, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 20, 1, 1, 1, 1, 1, 35, 0, 0, 0, 0},
  {63, 63, 63, 62, 62, 62, 63, 40, 40, 63, 60, 20, 40, 63, 63, 63, 63, 40, 40, 63, 63, 63, 63, 61, 61, 61, 61},

  // slalom (5)
  {1, 1, 1, 5, 41, 44, 41, 5, 1, 1, 1, 1, 1, 1, 1, 5, 41, 44, 41, 5, 1, 1, 2, 1, 0, 0, 0},
  {45, 63, 55, 63, 63, 60, 63, 63, 63, 59, 34, 17, 34, 59, 63, 63, 63, 59, 63, 63, 63, 59, 23, 20, 55, 23, 25}
};

typedef struct GAME {
  uint16_t Score = 0;
  uint8_t Stars = 0;
  uint8_t ShipPosX;
  uint8_t ShipPosY;
  uint8_t ThrustUP;
  uint8_t ThrustLEFT;
  uint8_t ThrustRIGHT;
  short Fuel;
  short FuelBonus;

  short velocityY;
  short velocityX;
  uint16_t velXCounter;
  uint16_t velYCounter;

  bool Toggle;
  uint8_t ShipExplode;
  bool Collision;
  bool HasLanded;
  uint8_t EndCounter;

  uint8_t Level;
  uint8_t LevelScore;
  uint8_t LandingPadLEFT;
  uint8_t LandingPadRIGHT;

  uint8_t Lives;
} GAME;

uint8_t GETLANDSCAPE(uint8_t x, uint8_t y, uint8_t level, GAME *game);
void SETNEXTLEVEL(uint8_t level, GAME *game);

typedef struct DIGITAL {
  uint8_t D[5];
  bool IsNegative;
} DIGITAL;
