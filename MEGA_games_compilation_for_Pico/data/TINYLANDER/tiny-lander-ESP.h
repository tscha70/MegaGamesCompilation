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

#include "spritebank.h"
#include "gameinterface.h"

//prototype
void loop_TLANDER();
void TINYJOYPAD_INIT(void);
void SetLandingMap(uint8_t level, GAME *game);
void SETNEXTLEVEL(uint8_t level, GAME *game);
uint8_t GETLANDSCAPE(uint8_t x, uint8_t y, uint8_t level);
void SPLITDIGITS(uint16_t val, uint8_t *d);
void SOUND(uint8_t freq, uint8_t dur);
void INTROSOUND();
void VICTORYSOUND();
void ALERTSOUND();
void HAPPYSOUND();
void initGame (GAME * game);
void showAllScoresAndBonuses(GAME *game, DIGITAL *score, DIGITAL *velX, DIGITAL *velY);
void changeSpeed(GAME * game);
void moveShip(GAME * game);
void fillData(long myValue, DIGITAL * data);
uint8_t ScoreDisplay(uint8_t x, uint8_t y, DIGITAL * score);
uint8_t VelocityDisplay(uint8_t x, uint8_t y, DIGITAL * velocity, uint8_t horizontal);
uint8_t LanderDisplay(uint8_t x, uint8_t y, GAME * game);
uint8_t getLanderSprite(uint8_t x, GAME * game);
uint8_t FuelDisplay(uint8_t x, uint8_t y, GAME * game);
uint8_t GameDisplay(uint8_t x, uint8_t y, GAME * game);
uint8_t StarsDisplay(uint8_t x, uint8_t y, GAME * game);
uint8_t LivesDisplay(uint8_t x, uint8_t y, GAME * game);
void Tiny_Flip(uint8_t mode, GAME * game, DIGITAL * score, DIGITAL * velX, DIGITAL * velY);

uint8_t BACKSCROLL(uint8_t xPASS,uint8_t yPASS, GAME *game);
uint8_t RecupeDecalageY_TLANDER(uint8_t Valeur);
int8_t RecupeLineY_TLANDER(int8_t Valeur);
uint8_t SplitSpriteDecalageY_TLANDER(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN);
uint8_t blitzSprite_TLANDER(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES);

#define GAME_FRAME_CONTROL_TLANDER while((currentMillis-MemMillis)<1){currentMillis=millis();}MemMillis=currentMillis

void loop_TLANDER() {
ESP.wdtDisable();
ESP.wdtFeed();
  DIGITAL score;
  DIGITAL velX;
  DIGITAL velY;
  GAME game;

BEGIN:
  game.Level = 1;
  game.Score = 0;
  game.Lives = 4;
  while (1) {
  ESP.wdtFeed();
    Tiny_Flip(1, &game, &score, &velX, &velY);
    if (BUTTON_DOWN) {
      if (TINYJOYPAD_UP==0){ 
        game.Level = 10;
        ALERTSOUND();
      }
      else if (TINYJOYPAD_DOWN==0) {
        game.Lives = 255;
        ALERTSOUND();
      }
      else {
        SOUND(100, 125);
        SOUND(50, 125);
      }

      goto START;
    }
  }

START:
  initGame(&game);
  INTROSOUND();
  ESP.wdtDisable();
ESP.wdtFeed();
  while (1) {
ESP.wdtFeed();
  GAME_FRAME_CONTROL_TLANDER;
    fillData(game.Score, &score);
    fillData(game.velocityX, &velX);
    fillData(game.velocityY, &velY);
    moveShip(&game);
    changeSpeed(&game);

    Tiny_Flip(0, &game, &score, &velX, &velY);
    if (game.EndCounter > 8) {
      if (game.HasLanded)
      {
        showAllScoresAndBonuses(&game, &score, &velX, &velY);
        delay(500);
        goto START;
      }
      else
      {
        delay (2000);
        if (game.Lives > 0)
          goto START;
        goto BEGIN;
      }

    }
    if (game.ShipExplode > 0 || game.Collision)
      game.EndCounter++;
    if (game.HasLanded)
      game.EndCounter = 10;
  }
}

void TINYJOYPAD_INIT(void) {

}


void SetLandingMap(uint8_t level, GAME *game)
{
  uint8_t i;
  uint8_t prev=0;
  game->LandingPadLEFT = 0;
  game->LandingPadRIGHT = 255;
  for (i = 0; i < 27; i++)
  {
    uint8_t val = pgm_read_byte(&GAMEMAP[(level - 1) * 2][i]);

    if ((prev == 0 && (val != 0 || i == 26)) && game->LandingPadRIGHT == 0)
    {
      game->LandingPadRIGHT  = i * 4;
    }

    if (val == 0 && game->LandingPadLEFT == 0)
    {
      game->LandingPadLEFT = i * 4;
      game->LandingPadRIGHT = 0;
    }

    prev = val;
  }
}

void SETNEXTLEVEL(uint8_t level, GAME *game)
{
  if ( level > NUMOFGAMES)
    level = 1;
  game->Level = level;
  SetLandingMap(level, game);
  game->ShipPosX = pgm_read_byte(&GAMELEVEL[level - 1][0]);
  game->ShipPosY = pgm_read_byte(&GAMELEVEL[level - 1][1]);
  game->Fuel = 100 * pgm_read_byte(&GAMELEVEL[level - 1][2]);
  game->LevelScore = pgm_read_byte(&GAMELEVEL[level - 1][3]);
  game->FuelBonus = 100 * pgm_read_byte(&GAMELEVEL[level - 1][4]);
}

uint8_t GETLANDSCAPE(uint8_t x, uint8_t y, uint8_t level)
{
  const uint8_t height = 63;
  uint8_t frame = 0x00;
  uint8_t t =  x % 4;
  uint8_t ind = x / 4;
  uint8_t val = height - pgm_read_byte(&GAMEMAP[level][ind]);
  uint8_t valT = height - pgm_read_byte(&GAMEMAP[level + 1][ind]);
  if (x > 0 && t != 0)
  {
    if ( (ind + 1) < 27)
    {
      if (val < height)
      { uint8_t val2 = height - pgm_read_byte(&GAMEMAP[level][ind + 1]);
        val += ((val2 - val) / 4) * ( t);
      }
      uint8_t valT2 = height - pgm_read_byte(&GAMEMAP[level + 1][ind + 1]);
      valT += ((valT2 - valT) / 4) * ( t);
    }
  }

  uint8_t b = val / 8;
  uint8_t bT = valT / 8;
  if (b == y)
  {
    // draw the landing-platform
    if (val == height)
      if (x % 2 == 0)
        frame |= 0xB8;
      else
        frame |= 0x58;
    else
      // draw pixel on the correct height
      frame |= (0xFF << (val - (b * 8)) ) ;
  }
  if (bT == y)
    frame |= (0xFF >>  (7 - (valT - (bT * 8))));
  if (y > b || y < bT )
    frame |= 0xFF;

  return frame;
}

// splits each digit in it's own byte
void SPLITDIGITS(uint16_t val, uint8_t *d)
{
  d[4] = val / 10000;
  d[3] = (val - (d[4] * 10000)) / 1000;
  d[2] = (val - (d[3] * 1000) - (d[4] * 10000)) / 100;
  d[1] = (val - (d[2] * 100) - (d[3] * 1000) - (d[4] * 10000)) / 10;
  d[0] = val - (d[1] * 10) - (d[2] * 100) - (d[3] * 1000) - (d[4] * 10000);
}

void SOUND(uint8_t freq_, uint8_t dur) {
ESP.wdtFeed();
if (freq_==0) {My_delay_ms(dur);goto END;}
for (uint8_t t=0;t<dur;t++){
if (freq_!=0){
digitalWrite(PIN_,SOUND_ON_OFF);
}
for (uint8_t t=0;t<(255-freq_);t++){
My_delay_us(1); }
digitalWrite(PIN_,LOW);
for (uint8_t t=0;t<(255-freq_);t++){
My_delay_us(1); }}
END:;
digitalWrite(PIN_,LOW);
}

void INTROSOUND()
{
  SOUND(80, 55);My_delay_ms(20); SOUND(90, 55); My_delay_ms(20); SOUND(100, 55); SOUND(115, 255); SOUND(115, 255);
}
void VICTORYSOUND()
{
  SOUND(111, 100); My_delay_ms(20); SOUND(111, 90);My_delay_ms(20); SOUND(144, 255); SOUND(144, 255); SOUND(144, 255);
}

void ALERTSOUND()
{
  SOUND(150, 100); My_delay_ms(100); SOUND(150, 90); My_delay_ms(100); SOUND(150, 100);
}

void HAPPYSOUND()
{
  SOUND(75, 90); My_delay_ms(10); SOUND(114, 90); SOUND(121, 90);
}



void initGame (GAME * game)
{
  SETNEXTLEVEL(game->Level, game);

  game->velocityY = 0;
  game->velocityX = 0;
  game->velXCounter = 0;
  game->velYCounter = 0;
  game->ShipExplode = 0;
  game->Toggle = true;
  game->Collision = false;
  game->HasLanded = false;
  game->EndCounter = 0;
  game->Stars = 0;
}

void showAllScoresAndBonuses(GAME *game, DIGITAL *score, DIGITAL *velX, DIGITAL *velY)
{
  VICTORYSOUND();
  game->Level++;
  delay (1000);
  uint8_t bonusPoints = 0;

  // add bonus points
  if ((abs(game->velocityY)) <= BONUSSPEED2)
    bonusPoints++;
  if ((abs(game->velocityY)) <= BONUSSPEED1)
    bonusPoints++;
  if (game->Fuel >= game->FuelBonus)
    bonusPoints++;

  for (game->Stars = 1; game->Stars <= bonusPoints; game->Stars++)
  {
    Tiny_Flip(2, game, score, velX, velY);
    HAPPYSOUND();
    delay(500);
  }
  game->Stars--;

  uint16_t newScore = game->Score + game->LevelScore  + (game->LevelScore * bonusPoints );
  while (game->Score < newScore)
  {
    game->Score++;
    fillData(game->Score, score);
	if (game->Score % ((newScore - game->Score) / 20) == 0)
    {
       Tiny_Flip(2, game, score, velX, velY);
       SOUND(129, 2);
	}
  }
  Tiny_Flip(2, game, score, velX, velY);
}

void changeSpeed(GAME * game)
{
  game->ThrustLEFT = (TINYJOYPAD_LEFT==0);
  game->ThrustRIGHT = (TINYJOYPAD_RIGHT==0);
  game->ThrustUP = BUTTON_DOWN;
  game->Toggle = !game->Toggle;

  if (game->ThrustLEFT && game->Fuel > 0)
  {
    game->Fuel -= (FULLTHRUST / 2);
    game->velocityX += TrustX;
    if ((game->velocityX) > VLimit)
      game->velocityX  = VLimit;
  }
  else if (game->ThrustRIGHT && game->Fuel > 0)
  {
    game->Fuel -= (FULLTHRUST / 2);
    game->velocityX -= TrustX;
    if ((game->velocityX) < -VLimit)
      game->velocityX  = -VLimit;
  }

  if (game->ThrustUP && game->Fuel > 0)
  {
    game->Fuel -= (FULLTHRUST * 2);
    game->velocityY += TrustY;
    if ((game->velocityY) > VLimit)
      game->velocityY  = VLimit;
  }
  else
  {
    game->velocityY -= (GRAVITYDECY);
    if ((game->velocityY) < -VLimit)
      game->velocityY  = -VLimit;
  }

  if ((game->Fuel) <= 0)
    game->Fuel = 0;
}

void moveShip(GAME * game)
{
  if (game->ShipExplode > 0 || game->Collision || game->HasLanded) return;

  game->velXCounter += abs(game->velocityX);
  game->velYCounter += abs(game->velocityY);

  if ((game->velXCounter) >= MoveX) {
    game->velXCounter = 0;
    if ((game->velocityX) > 0)
      game->ShipPosX += 1;
    if ((game->velocityX) < 0)
      game->ShipPosX -= 1;
  }

  if (game->velYCounter >= MoveY) {
    uint8_t inc = (abs(game->velocityY) / ACCELERATOR) + 1;
    (game->velYCounter) = 0;
    if ((game->velocityY) > 0)
      game->ShipPosY -= inc;
    if (game->velocityY < 0)
      game->ShipPosY += inc;
  }

  // boundaries....
  if (game->ShipPosX > 121)
  {
    game->ShipPosX = 121;
  }
  else if (game->ShipPosX < 23)
  {
    game->ShipPosX = 23;
  }
  if (game->ShipPosY > 55)
  {
    game->ShipPosY = 55;
  }
}

void fillData(long myValue, DIGITAL * data)
{
  SPLITDIGITS(abs(myValue), data->D);
  data->IsNegative = (myValue < 0);
}

uint8_t ScoreDisplay(uint8_t x, uint8_t y, DIGITAL * score) {
  // show score within the give limits on lin 1
  if  ((y != 1) || (x < SCOREOFFSET) || (x > (SCOREOFFSET + (SCOREDIGITS * DIGITSIZE) - 1))) {
    return 0;
  }
  // show all of the file digits
  uint8_t part =  (x - SCOREOFFSET) / (DIGITSIZE);
  return pgm_read_byte(&DIGITS[x - SCOREOFFSET - (DIGITSIZE * part) + (score->D[(SCOREDIGITS - 1) - part] * DIGITSIZE)]);
}

uint8_t VelocityDisplay(uint8_t x, uint8_t y, DIGITAL * velocity, uint8_t horizontal)
{
  // if on line 4 or 5  for horizontal(4) an vertical(4) speed
  if ((horizontal == 1 && y != 4) || (horizontal == 0 && y != 5)) {
    return 0;
  }
  // display velocity within the limits ...
  if ((x < VELOOFFSET) || (x > (VELOOFFSET + (VELODIGITS * DIGITSIZE)) - 1)) {
    return 0;
  }
  // show plus or minus sign
  if ((x >= VELOOFFSET) && (x < (VELOOFFSET + DIGITSIZE))) {
    return pgm_read_byte(&DIGITS[x - VELOOFFSET + ((10 + (velocity->IsNegative)) * DIGITSIZE)]);
  }
  // show just 3 digits
  uint8_t part =  ((x - VELOOFFSET) / (DIGITSIZE));
  return pgm_read_byte(&DIGITS[x - VELOOFFSET - (DIGITSIZE * part) + (velocity->D[(VELODIGITS - 1) - part] * DIGITSIZE)]);
}
uint8_t DashboardDisplay(uint8_t x, uint8_t y)
{
  if ( x <= 22) {
    return pgm_read_byte(&DASHBOARD[x + y * 23]);
  }
  return 0x00;
}

uint8_t LanderDisplay(uint8_t x, uint8_t y, GAME * game) {
  uint8_t line = game->ShipPosY / 8;
  uint8_t offset = game->ShipPosY % 8;
  if (y == line || ((y == line + 1) && offset > 0))
  {
    if (((x - game->ShipPosX) >= 0) && ((x - game->ShipPosX) < 7)) {
      uint8_t sprite = getLanderSprite (x, game);
      if (offset == 0 && y == line)
        return sprite;
      if (offset > 0 && y == line)
        return sprite << offset;
      if (offset > 0 && y == (line + 1))
        return sprite >> (8 - offset);
    }
  }
  return 0x00;
}

uint8_t getLanderSprite(uint8_t x,  GAME * game)
{
  uint8_t sprite = 0x00;

  if (game->ShipExplode > 0)
  {
    sprite = pgm_read_byte(&LANDER[(x - game->ShipPosX) + ((8 - (game->ShipExplode)) * 7) ]);
    SOUND(20 * game->ShipExplode, 10);
    (game->ShipExplode)--;
    if (game->ShipExplode < 1)
      game->ShipExplode = 3;
    return sprite;
  }

  // top sprite (4 bit)
  if (game->ThrustLEFT)
    sprite = pgm_read_byte(&LANDER[(x - game->ShipPosX) + 21]);
  else if (game->ThrustRIGHT)
    sprite = pgm_read_byte(&LANDER[(x - game->ShipPosX) + 28]);
  else
    sprite = pgm_read_byte(&LANDER[(x - game->ShipPosX) ]);

  // bottom spite (4 bit)
  if (game->ThrustUP && game->Toggle && game->Fuel > 0)
    return (sprite |= pgm_read_byte(&LANDER[(x - game->ShipPosX) + 14]));
  else
    return (sprite |= pgm_read_byte(&LANDER[(x - game->ShipPosX) + 7]));
}

uint8_t FuelDisplay(uint8_t x, uint8_t y, GAME * game)
{
  if (y != 6) return 0x00;
  if (x > 4 && x <= 19)
  {
    // max fuel = 15.000 Liter - each liter = 1 fuel-bar we have 15 bars
    if ((game->Fuel / 1000) + 1 > x - 4 || ((x - 4 == 1) && game->Fuel > 0))
      return 0xF8;
    else
      return 0x00;
  }
  return 0x00;
}

uint8_t GameDisplay(uint8_t x, uint8_t y, GAME * game)
{
  const uint8_t offset = 23;
  if (x >= offset)
  {
    uint8_t frame;
    if (x == offset || x == 127)
      // left and right border-line
      frame = 0xFF;
    else
      // draw the map from the coordinates given by the GAMEMAP
      frame = GETLANDSCAPE(x - offset,y, ((game->Level - 1) * 2));

    uint8_t ship = LanderDisplay(x, y, game);

    if (y == 7 && x >= (game->LandingPadLEFT + offset) && x <= (game->LandingPadRIGHT + offset))
    {
      if (ship != 0 && (0xFC | ship) != (0xFC + ship))
      {
        if (abs(game->velocityY) <= LANDINGSPEED && (game->ShipPosX >= game->LandingPadLEFT + offset) && (game->ShipPosX + 7 <= game->LandingPadRIGHT + offset) )
        {
          game->HasLanded = true;
          return frame | ship;
        }
        else
        {
          if (!game->Collision)
            game->Lives--;
          game->ShipExplode = 3;
          game->Collision = true;

          return frame | LanderDisplay(x, y, game);
        }
      }
    }
    else if  ((frame != 0 && ship != 0) && (frame | ship) != (frame + ship))
    {
      if (!game->Collision)
        game->Lives--;
      game->ShipExplode = 3;
      game->Collision = true;
      return frame | LanderDisplay(x, y, game);
    }

    return frame | ship;
  }
  return 0x00;
}

uint8_t StarsDisplay(uint8_t x, uint8_t y, GAME * game)
{
  const uint8_t o1 = 23;
  uint8_t bg = 0x00;
  if (y == 0 && x > o1)
  {
    bg |= 0x01;
  }
  if (x == o1)
  {
    bg |= 0xFF;
  }
  if (x == 127)
  {
    bg |= 0xFF;
  }
  if (y == 7 && x > o1)
  {
    bg |= 0x80;
  }

  const uint8_t offset = 40;
  if (y > 1 && y < 5)
  {
    if (x > offset &&  x < (offset + 72))
    {
      if (game->Stars > (x - offset) / 24)
      {
        return pgm_read_byte(&STARFULL[((x - offset) % 24) + ((y - 2) * 24)] );
      }
      else
      {
        return pgm_read_byte(&STAROUTLINE[((x - offset) % 24) + ((y - 2) * 24)] );
      }
    }
  }
  return bg;
}

uint8_t LivesDisplay(uint8_t x, uint8_t y, GAME * game)
{
  const uint8_t offset = 1;
  if (y == 7 && x >= offset && x < (4 * 5) + offset)
  {
    if (game->Lives > (x - offset) / 5)
      return pgm_read_byte(&LIVE[(x - offset) % 5]);
  }
  return 0x00;
}

void Tiny_Flip(uint8_t mode, GAME * game, DIGITAL * score, DIGITAL * velX, DIGITAL * velY) {
  uint8_t y, x;
  for (y = 0; y < 8; y++)
  {

    for (x = 0; x < 128; x++)
    {
      if (mode == 0) {
        display.buffer[x+(y*128)] =(GameDisplay(x, y, game) | LivesDisplay(x, y, game) | DashboardDisplay(x, y) | ScoreDisplay(x, y, score) | VelocityDisplay(x, y, velX, 1) | VelocityDisplay(x, y, velY, 0) | FuelDisplay(x, y, game)|BACKSCROLL(x,y,game));
      } else if (mode == 1) {
        display.buffer[x+(y*128)] =(pgm_read_byte(&INTRO[x + (y * 128)]));
      }
      else if (mode == 2)
      {
        display.buffer[x+(y*128)] =(StarsDisplay ( x, y, game) | LivesDisplay(x, y, game) | DashboardDisplay(x, y) | ScoreDisplay(x, y, score) | VelocityDisplay(x, y, velX, 1) | VelocityDisplay(x, y, velY, 0) | FuelDisplay(x, y, game)/*|BACKSCROLL(x,y,game)*/);
      }
    }
    if (mode == 0 || mode == 2) {
    }
  }
  display.display();
}

uint8_t BACKSCROLL(uint8_t xPASS,uint8_t yPASS, GAME *game){
/*uint16_t TMP=xPASS+(yPASS*128);
if (TMP) {}
return pgm_read_byte(&BackScroll[TMP]);*/
if (xPASS<24) return 0;
uint8_t Xcep=(map(game->ShipPosX,0,127,32,0))-16;
uint8_t Ycep=(map(game->ShipPosY,0,63,32,0))-16;;
return blitzSprite_TLANDER(Xcep,Ycep-16,xPASS,yPASS,0,BackScroll);
}

uint8_t blitzSprite_TLANDER(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES){
uint8_t OUTBYTE;
uint8_t WSPRITE=(pgm_read_byte(&SPRITES[0]));
uint8_t HSPRITE=(pgm_read_byte(&SPRITES[1]));
uint16_t Wmax=((HSPRITE*WSPRITE)+1);
uint16_t PICBYTE=FRAME*(Wmax-1);
int8_t RECUPELINEY=RecupeLineY_TLANDER(yPos);
if ((xPASS>((xPos+(WSPRITE-1))))||(xPASS<xPos)||((RECUPELINEY>yPASS)||((RECUPELINEY+(HSPRITE))<yPASS))) {return 0x00;}
int8_t SPRITEyLINE=(yPASS-(RECUPELINEY));
uint8_t SPRITEyDECALAGE=(RecupeDecalageY_TLANDER(yPos));
uint16_t ScanA=(((xPASS-xPos)+(SPRITEyLINE*WSPRITE))+2);
uint16_t ScanB=(((xPASS-xPos)+((SPRITEyLINE-1)*WSPRITE))+2);
if (ScanA>Wmax) {OUTBYTE=0x00;}else{OUTBYTE=SplitSpriteDecalageY_TLANDER(SPRITEyDECALAGE,pgm_read_byte(&SPRITES[ScanA+(PICBYTE)]),1);}
if ((SPRITEyLINE>0)) {
uint8_t OUTBYTE2=SplitSpriteDecalageY_TLANDER(SPRITEyDECALAGE,pgm_read_byte(&SPRITES[ScanB+(PICBYTE)]),0);
if (ScanB>Wmax) {return OUTBYTE;}else{return OUTBYTE|OUTBYTE2;}
}else{return OUTBYTE;}
}


uint8_t SplitSpriteDecalageY_TLANDER(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN){
if (UPorDOWN) {return Input<<decalage;}
return Input>>(8-decalage);
}

int8_t RecupeLineY_TLANDER(int8_t Valeur){
return (Valeur>>3); 
}

uint8_t RecupeDecalageY_TLANDER(uint8_t Valeur){
return (Valeur-((Valeur>>3)<<3));
}
