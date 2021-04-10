//     >>>>>  MEGA COMPILATION for ESP8266/ESP8285  GPL v3 <<<<
//                    >>>>>  MEGA Tiny Joypad  <<<<
//                      Programmer: Daniel C 2019
//            Contact EMAIL: electro_l.i.b@tinyjoypad.com
//              official website: www.tinyjoypad.com
//       or  https://sites.google.com/view/arduino-collection

//  MEGA COMPILATION is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.

//  You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.


#include "spritebank_TGILBERT.h"
#define Frame_Rate_TGILBERT 0 

uint8_t Map_TGILBERT[8][34]={{0}};
uint8_t timer_TGILBERT=0;
int8_t scrool_TGILBERT=0;
int8_t step4_TGILBERT=0;
uint8_t MainAnim_TGILBERT=0,LorR_TGILBERT=1;
int8_t Jump_TGILBERT=0;
int8_t  jumpcancel_TGILBERT=0;
const float VSlide_TGILBERT[9]={1,2,4,8,16,32,64,128,256};
uint8_t key_TGILBERT[20][2]={{0}};
uint8_t keyS_TGILBERT=0;
float VSlideOut_TGILBERT=0;
uint8_t LevelMult_TGILBERT=0,levelType_TGILBERT=0;
uint8_t ByteMem_TGILBERT=0;
uint8_t visible_TGILBERT=1;
uint8_t injur_TGILBERT=0;
uint8_t LIVE_TGILBERT=0;


void Tiny_Flip_TGILBERT(DriftSprite_TGILBERT* DSprite);
uint16_t RETURN_1024_POS_TGILBERT(void);
void SpriteShiftInitialise_TGILBERT(DriftSprite_TGILBERT* DSprite);
void TinyMainShift_TGILBERT(DriftSprite_TGILBERT* DSprite);
void NextLevel_TGILBERT(void);
void ResetVarNextLevel_TGILBERT(void);
void ResetVar_TGILBERT(void);
int8_t CollisionCheck_TGILBERT(DriftSprite_TGILBERT* DSprite);
void JumpProcedure_TGILBERT(DriftSprite_TGILBERT* DSprite);
void GravityUpdate_TGILBERT(DriftSprite_TGILBERT* DSprite);
void UpdateVerticalSlide_TGILBERT(DriftSprite_TGILBERT* DSprite);
void ScrollUpdate_TGILBERT(DriftSprite_TGILBERT* DSprite);
void draw_bmp_TGILBERT(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, const uint8_t bitmap[]);
void fillscreen_TGILBERT(uint8_t VALUE);
void sound_TGILBERT(uint8_t SND);
void Sound_TGILBERT(uint8_t freq,uint8_t dur);
uint8_t delKey_TGILBERT(uint8_t Xin,uint8_t Yin);



uint8_t delKey_TGILBERT(uint8_t Xin,uint8_t Yin){
int8_t x=0;  
for (x=0;x<23;x++){
if   ((key_TGILBERT[x][0]==0) && (key_TGILBERT[x][1]==0)) {return 11;}
if ((key_TGILBERT[x][0]==Xin) && (key_TGILBERT[x][1]==Yin)) {return 0;}  }
return 11;}

void Sound_TGILBERT(uint8_t freq,uint8_t dur){
  ESP.wdtFeed();
for (uint8_t t=0;t<dur;t++){
if (freq!=0)digitalWrite(PIN_,SOUND_ON_OFF); 
for (uint8_t t=0;t<(255-freq);t++){
My_delay_us(1);}
digitalWrite(PIN_,LOW);
for (uint8_t t=0;t<(255-freq);t++){
My_delay_us(1); }}}


void sound_TGILBERT(uint8_t SND){
if (SND==1) {Sound_TGILBERT(210,10);Sound_TGILBERT(240,2);Sound_TGILBERT(180,5);}
if (SND==2){for (uint8_t x=255;x>2;x--){ Sound_TGILBERT(x,1);}
}
}

void fillscreen_TGILBERT(uint8_t VALUE){
for (uint16_t t=0;t<1024;t++){
display.buffer[t] =(VALUE);
}
display.display();    
}

void draw_bmp_TGILBERT(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, const uint8_t bitmap[]){
  uint16_t j = 0;
  uint8_t y, x;
  uint16_t START_A=0;
  for (y = y0; y < y1; y++)
  { 
    for (x = x0; x < x1; x++)
    {
      START_A=x+(y*128);
      display.buffer[START_A] =(pgm_read_byte(&bitmap[j++]));
    }}
display.display();    
}

void loop_TGILBERT() {
ESP.wdtDisable();
RESTARTGAME:
sound_TGILBERT(1);sound_TGILBERT(2);sound_TGILBERT(2);sound_TGILBERT(1);sound_TGILBERT(2);sound_TGILBERT(2);
My_delay_ms(200);
ResetVar_TGILBERT();
fillscreen_TGILBERT(0xff);
draw_bmp_TGILBERT(32, 4, 96, 8,start_TGILBERT);
My_delay_ms(400);
 while(1){
ESP.wdtFeed();
if (BUTTON_DOWN) {sound_TGILBERT(1);break;}}
RESTARTLEVEL:
ResetVarNextLevel_TGILBERT();
NEXTLEVEL:
if (levelType_TGILBERT>9) {goto RESTARTGAME;}
My_delay_ms(400);
DriftSprite_TGILBERT MainSprite;
SpriteShiftInitialise_TGILBERT(&MainSprite);
fillscreen_TGILBERT(0x00);
#define RBACKUP  if  ((CollisionCheck_TGILBERT(&MainSprite)==1)){MainSprite.x4decalage--;}
#define LBACKUP  if  ((CollisionCheck_TGILBERT(&MainSprite)==1)) {MainSprite.x4decalage++;}   
while(1){
ESP.wdtFeed();
if (TINYJOYPAD_RIGHT==0)  {
if (timer_TGILBERT%4==0) {
MainAnim_TGILBERT++;if (MainAnim_TGILBERT>2) {MainAnim_TGILBERT=0;}
}
LorR_TGILBERT=0;
MainSprite.x4decalage++;RBACKUP;if (MainSprite.x4decalage>3) {MainSprite.x4decalage=0;MainSprite.MainPositionOnGridH++;}
}
if (TINYJOYPAD_LEFT==0) {
if (timer_TGILBERT%4==0) {
MainAnim_TGILBERT++;if (MainAnim_TGILBERT>2) {MainAnim_TGILBERT=0;}
}
LorR_TGILBERT=1;
MainSprite.x4decalage--;LBACKUP;if (MainSprite.x4decalage<0) {MainSprite.x4decalage=3;MainSprite.MainPositionOnGridH--;}
} 
ScrollUpdate_TGILBERT(&MainSprite); 
#define exclude(Spick) (ByteMem_TGILBERT==Spick)
#define SpritePickup (exclude(11))
if (MainSprite.MainPositionOnGridV>=7) {sound_TGILBERT(2);LIVE_TGILBERT--;if (LIVE_TGILBERT==0) {goto RESTARTGAME;}goto RESTARTLEVEL;}
for (uint8_t x = 0; x < 33; x++)
{
#define LevelS (x+scrool_TGILBERT)/4 //(x+scrool_TGILBERT)/4
  switch (levelType_TGILBERT){
  case(0):LevelMult_TGILBERT=pgm_read_byte(&Level0_TGILBERT[LevelS]);break;
  case(1):LevelMult_TGILBERT=pgm_read_byte(&Level1_TGILBERT[LevelS]);break;
  case(2):LevelMult_TGILBERT=pgm_read_byte(&Level2_TGILBERT[LevelS]);break;
  case(3):LevelMult_TGILBERT=pgm_read_byte(&Level3_TGILBERT[LevelS]);break;
  case(4):LevelMult_TGILBERT=pgm_read_byte(&Level4_TGILBERT[LevelS]);break;
  case(5):LevelMult_TGILBERT=pgm_read_byte(&Level5_TGILBERT[LevelS]);break;
  case(6):LevelMult_TGILBERT=pgm_read_byte(&Level6_TGILBERT[LevelS]);break;
  case(7):LevelMult_TGILBERT=pgm_read_byte(&Level7_TGILBERT[LevelS]);break;
  case(8):LevelMult_TGILBERT=pgm_read_byte(&Level8_TGILBERT[LevelS]);break;
  case(9):LevelMult_TGILBERT=pgm_read_byte(&Level9_TGILBERT[LevelS]);break;
  default:goto RESTARTGAME;}
#define LevelShift (((x+scrool_TGILBERT)%4)+(LevelMult_TGILBERT*4))
  ByteMem_TGILBERT=pgm_read_byte(&map1couche2_TGILBERT[LevelShift]);
  if ((SpritePickup)) {Map_TGILBERT[1][x]=delKey_TGILBERT(x+scrool_TGILBERT,1);}else{Map_TGILBERT[1][x]=ByteMem_TGILBERT;}
  ByteMem_TGILBERT=pgm_read_byte(&map1couche3_TGILBERT[LevelShift]);
  if ((SpritePickup)) {Map_TGILBERT[2][x]=delKey_TGILBERT(x+scrool_TGILBERT,2);}else{Map_TGILBERT[2][x]=ByteMem_TGILBERT;}
  ByteMem_TGILBERT=pgm_read_byte(&map1couche4_TGILBERT[LevelShift]);
  if ((SpritePickup)) {Map_TGILBERT[3][x]=delKey_TGILBERT(x+scrool_TGILBERT,3);}else{Map_TGILBERT[3][x]=ByteMem_TGILBERT;}
  ByteMem_TGILBERT=pgm_read_byte(&map1couche5_TGILBERT[LevelShift]);
  if ((SpritePickup)) {Map_TGILBERT[4][x]=delKey_TGILBERT(x+scrool_TGILBERT,4);}else{Map_TGILBERT[4][x]=ByteMem_TGILBERT;}
  ByteMem_TGILBERT=pgm_read_byte(&map1couche6_TGILBERT[LevelShift]);
  if ((SpritePickup)) {Map_TGILBERT[5][x]=delKey_TGILBERT(x+scrool_TGILBERT,5);}else{Map_TGILBERT[5][x]=ByteMem_TGILBERT;}
  ByteMem_TGILBERT=pgm_read_byte(&map1couche7_TGILBERT[LevelShift]);
  if ((SpritePickup)) {Map_TGILBERT[6][x]=delKey_TGILBERT(x+scrool_TGILBERT,6);}else{Map_TGILBERT[6][x]=ByteMem_TGILBERT;}
  ByteMem_TGILBERT=pgm_read_byte(&map1couche8_TGILBERT[LevelShift]);
  if ((SpritePickup)) {Map_TGILBERT[7][x]=delKey_TGILBERT(x+scrool_TGILBERT,7);}else{Map_TGILBERT[7][x]=ByteMem_TGILBERT;}
}
if (Jump_TGILBERT==0) {GravityUpdate_TGILBERT(&MainSprite);}
if ((BUTTON_DOWN)&&(Jump_TGILBERT==0)&&(jumpcancel_TGILBERT==0)&&(CollisionCheck_TGILBERT(&MainSprite)==0)){
if (MainSprite.y8decalage==0) {Jump_TGILBERT=3;}
}
if (BUTTON_UP) {jumpcancel_TGILBERT=0;}
if (Jump_TGILBERT>0) {JumpProcedure_TGILBERT(&MainSprite);}
#define pickup(Vadd,Hadd,SPRITE) (Map_TGILBERT[MainSprite.MainPositionOnGridV+Vadd][MainSprite.MainPositionOnGridH+Hadd]==SPRITE)
#define Pictup2(SP) ((pickup(0,0,SP))||(pickup(0,1,SP))||(pickup(0,2,SP)))
#define Pictup4(SP2) (Pictup2(SP2)||(pickup(1,0,SP2))||(pickup(1,1,SP2))||(pickup(1,2,SP2)))
if ((MainSprite.y8decalage==0)) {
if( pickup(0,0,11)) {key_TGILBERT[keyS_TGILBERT][1]=MainSprite.MainPositionOnGridV;key_TGILBERT[keyS_TGILBERT][0]=scrool_TGILBERT+MainSprite.MainPositionOnGridH;keyS_TGILBERT++;sound_TGILBERT(1);}
if( pickup(0,1,11)) {key_TGILBERT[keyS_TGILBERT][1]=MainSprite.MainPositionOnGridV;key_TGILBERT[keyS_TGILBERT][0]=scrool_TGILBERT+MainSprite.MainPositionOnGridH+1;keyS_TGILBERT++;sound_TGILBERT(1);}
if( pickup(0,2,11)) {key_TGILBERT[keyS_TGILBERT][1]=MainSprite.MainPositionOnGridV;key_TGILBERT[keyS_TGILBERT][0]=scrool_TGILBERT+MainSprite.MainPositionOnGridH+2;keyS_TGILBERT++;sound_TGILBERT(1);}
if ((Pictup2(8))&&(injur_TGILBERT==0)) {LIVE_TGILBERT--;if (LIVE_TGILBERT==0) {goto RESTARTGAME;}Jump_TGILBERT=2;injur_TGILBERT=30;sound_TGILBERT(2);}
if (Pictup2(13)||Pictup2(14)) {if ((pgm_read_byte(&KeyinLevel_TGILBERT[levelType_TGILBERT])==keyS_TGILBERT)&&(Jump_TGILBERT>0)) {NextLevel_TGILBERT();goto NEXTLEVEL;}}
Map_TGILBERT[MainSprite.MainPositionOnGridV][MainSprite.MainPositionOnGridH]=MainSprite.DriftGrid[0][0];
Map_TGILBERT[MainSprite.MainPositionOnGridV][MainSprite.MainPositionOnGridH+1]=MainSprite.DriftGrid[0][1];}else{
if( pickup(0,0,11)) {key_TGILBERT[keyS_TGILBERT][1]=MainSprite.MainPositionOnGridV;key_TGILBERT[keyS_TGILBERT][0]=scrool_TGILBERT+MainSprite.MainPositionOnGridH;keyS_TGILBERT++;sound_TGILBERT(1);}
if( pickup(0,1,11)) {key_TGILBERT[keyS_TGILBERT][1]=MainSprite.MainPositionOnGridV;key_TGILBERT[keyS_TGILBERT][0]=scrool_TGILBERT+MainSprite.MainPositionOnGridH+1;keyS_TGILBERT++;sound_TGILBERT(1);}
if( pickup(0,2,11)) {key_TGILBERT[keyS_TGILBERT][1]=MainSprite.MainPositionOnGridV;key_TGILBERT[keyS_TGILBERT][0]=scrool_TGILBERT+MainSprite.MainPositionOnGridH+2;keyS_TGILBERT++;sound_TGILBERT(1);}
if( pickup(1,0,11)) {key_TGILBERT[keyS_TGILBERT][1]=MainSprite.MainPositionOnGridV+1;key_TGILBERT[keyS_TGILBERT][0]=scrool_TGILBERT+MainSprite.MainPositionOnGridH;keyS_TGILBERT++;sound_TGILBERT(1);}
if( pickup(1,1,11)) {key_TGILBERT[keyS_TGILBERT][1]=MainSprite.MainPositionOnGridV+1;key_TGILBERT[keyS_TGILBERT][0]=scrool_TGILBERT+MainSprite.MainPositionOnGridH+1;keyS_TGILBERT++;sound_TGILBERT(1);}
if( pickup(1,2,11)) {key_TGILBERT[keyS_TGILBERT][1]=MainSprite.MainPositionOnGridV+1;key_TGILBERT[keyS_TGILBERT][0]=scrool_TGILBERT+MainSprite.MainPositionOnGridH+2;keyS_TGILBERT++;sound_TGILBERT(1);}   
if ((Pictup2(8))&&(injur_TGILBERT==0)) {LIVE_TGILBERT--;if (LIVE_TGILBERT==0) {goto RESTARTGAME;}Jump_TGILBERT=2;injur_TGILBERT=30;sound_TGILBERT(2);}
if (Pictup4(13)||Pictup4(14)) {if ((pgm_read_byte(&KeyinLevel_TGILBERT[levelType_TGILBERT])==keyS_TGILBERT)&&(Jump_TGILBERT>0)) {NextLevel_TGILBERT();goto NEXTLEVEL;}}
Map_TGILBERT[MainSprite.MainPositionOnGridV][MainSprite.MainPositionOnGridH]=MainSprite.DriftGrid[0][0];
Map_TGILBERT[MainSprite.MainPositionOnGridV][MainSprite.MainPositionOnGridH+1]=MainSprite.DriftGrid[0][1];
Map_TGILBERT[MainSprite.MainPositionOnGridV+1][MainSprite.MainPositionOnGridH]=MainSprite.DriftGrid[1][0];
Map_TGILBERT[MainSprite.MainPositionOnGridV+1][MainSprite.MainPositionOnGridH+1]=MainSprite.DriftGrid[1][1];
}
if (timer_TGILBERT%2==0)  {if (injur_TGILBERT>0) {if (visible_TGILBERT==1) {visible_TGILBERT=0;}else{visible_TGILBERT=1;}injur_TGILBERT--;}}
UpdateVerticalSlide_TGILBERT(&MainSprite);

while((currentMillis-MemMillis)<Frame_Rate_TGILBERT){
currentMillis=millis();
}
MemMillis=currentMillis;
Tiny_Flip_TGILBERT(&MainSprite);
timer_TGILBERT++;
if (timer_TGILBERT>60) {timer_TGILBERT=0;}
}}
////////////////////////////////// main end /////////////////////////////////

void ScrollUpdate_TGILBERT(DriftSprite_TGILBERT* DSprite){
if ((DSprite->MainPositionOnGridH)<10) {if ((scrool_TGILBERT>0)&&(step4_TGILBERT<=3)) {step4_TGILBERT=step4_TGILBERT+1;}if ((step4_TGILBERT>3)&&(scrool_TGILBERT>0)) {step4_TGILBERT=0;scrool_TGILBERT--;DSprite->MainPositionOnGridH=DSprite->MainPositionOnGridH+1;}}
if ((DSprite->MainPositionOnGridH)>18) {step4_TGILBERT=step4_TGILBERT-1;if (step4_TGILBERT<0) {step4_TGILBERT=3;scrool_TGILBERT++;DSprite->MainPositionOnGridH=DSprite->MainPositionOnGridH-1;}}
}

void UpdateVerticalSlide_TGILBERT(DriftSprite_TGILBERT* DSprite){
if (DSprite->y8decalage==0) {
if (visible_TGILBERT==1){
DSprite->DriftGrid[0][0]=5;
DSprite->DriftGrid[0][1]=6;}else{
DSprite->DriftGrid[0][0]=0;
DSprite->DriftGrid[0][1]=0;
}}else{
if (visible_TGILBERT==1){
DSprite->DriftGrid[0][0]=5;
DSprite->DriftGrid[0][1]=6;
DSprite->DriftGrid[1][0]=55;
DSprite->DriftGrid[1][1]=66;}else{
DSprite->DriftGrid[0][0]=0;
DSprite->DriftGrid[0][1]=0;
DSprite->DriftGrid[1][0]=0;
DSprite->DriftGrid[1][1]=0;   
}}}

void GravityUpdate_TGILBERT(DriftSprite_TGILBERT* DSprite){
int8_t memy8decalage=DSprite->y8decalage;
int8_t memMainPositionOnGridV=DSprite->MainPositionOnGridV;
DSprite->y8decalage=DSprite->y8decalage+2;
if (DSprite->y8decalage>7) {
DSprite->y8decalage=0;
DSprite->MainPositionOnGridV++;
}
if (CollisionCheck_TGILBERT(DSprite)>=1){
DSprite->MainPositionOnGridV=memMainPositionOnGridV;
DSprite->y8decalage=memy8decalage;
}}

void JumpProcedure_TGILBERT(DriftSprite_TGILBERT* DSprite){
int8_t memo2=0;
if ((Jump_TGILBERT>0)){
memo2=DSprite->MainPositionOnGridV;
DSprite->y8decalage=DSprite->y8decalage-(Jump_TGILBERT*2);
if (DSprite->y8decalage<0)   {DSprite->y8decalage=7; DSprite->MainPositionOnGridV--;Jump_TGILBERT--;
if ((DSprite->MainPositionOnGridV<=0)||(jumpcancel_TGILBERT==1)||(CollisionCheck_TGILBERT(DSprite)>=1)) {
Jump_TGILBERT=0;
jumpcancel_TGILBERT=1; 
DSprite->y8decalage=0;
DSprite->MainPositionOnGridV=memo2;
Jump_TGILBERT=0;jumpcancel_TGILBERT=1;}
if (Jump_TGILBERT==0) {jumpcancel_TGILBERT=1;}
}}}  

int8_t CollisionCheck_TGILBERT(DriftSprite_TGILBERT* DSprite){
int8_t xscan=0,yscan=0;
 //varable de la grille
#define M_X DSprite->MainPositionOnGridH
#define M_Y DSprite->MainPositionOnGridV
#define MXDRIFT DSprite->x4decalage
#define MYDRIFT DSprite->y8decalage
#define x_1 (M_X*4)+MXDRIFT
#define y_1 (M_Y*8)+MYDRIFT
#define x_2 (M_X*4)+MXDRIFT+7
#define y_2 (M_Y*8)+MYDRIFT
#define x_3 (M_X*4)+MXDRIFT
#define y_3 (M_Y*8)+MYDRIFT+7
#define x_4 (M_X*4)+MXDRIFT+7
#define y_4 (M_Y*8)+MYDRIFT+7
#define b_x1 (M_X+xscan)*4
#define b_y1 (M_Y+yscan)*8
#define b_x2 ((M_X+xscan)*4)+3
#define b_y2 (M_Y+yscan)*8
#define b_x3 (M_X+xscan)*4
#define b_y3 ((M_Y+yscan)*8)+7
#define b_x4 ((M_X+xscan)*4)+3
#define b_y4 ((M_Y+yscan)*8)+7
#define NoTested ((Map_TGILBERT[M_Y+yscan][M_X+xscan]!=8)&&(Map_TGILBERT[M_Y+yscan][M_X+xscan]!=0)&&(Map_TGILBERT[M_Y+yscan][M_X+xscan]!=13)&&(Map_TGILBERT[M_Y+yscan][M_X+xscan]!=14)&&(Map_TGILBERT[M_Y+yscan][M_X+xscan]!=11)&&(Map_TGILBERT[M_Y+yscan][M_X+xscan]!=5)&&(Map_TGILBERT[M_Y+yscan][M_X+xscan]!=6)&&(Map_TGILBERT[M_Y+yscan][M_X+xscan]!=55)&&(Map_TGILBERT[M_Y+yscan][M_X+xscan]!=66))
for (yscan=-1;yscan<3;yscan++){
for (xscan=-1;xscan<3;xscan++){
if (NoTested) { 
if ((x_1>b_x2)||(x_2<b_x1)||(y_1>b_y3)||(y_3<b_y1)) {}else{return 1;}
}}}
return 0;
}

void ResetVar_TGILBERT(void){
ResetVarNextLevel_TGILBERT();
levelType_TGILBERT=0;
LIVE_TGILBERT=7;
}

void ResetVarNextLevel_TGILBERT(void){
scrool_TGILBERT=0;
step4_TGILBERT=0;
MainAnim_TGILBERT=0;
LorR_TGILBERT=1;
Jump_TGILBERT=0;
jumpcancel_TGILBERT=0;
VSlideOut_TGILBERT=0;
for (uint8_t x=0;x<20;x++){
key_TGILBERT[x][0]=0;
key_TGILBERT[x][1]=0;}
keyS_TGILBERT=0;
LevelMult_TGILBERT=0;}

void NextLevel_TGILBERT(void){
ResetVarNextLevel_TGILBERT();
levelType_TGILBERT++; 
sound_TGILBERT(2);sound_TGILBERT(2);sound_TGILBERT(2);sound_TGILBERT(2);}

void TinyMainShift_TGILBERT(DriftSprite_TGILBERT* DSprite){
DSprite->DriftGrid[0][0]=5;
DSprite->DriftGrid[0][1]=6;
DSprite->DriftGrid[1][0]=5;
DSprite->DriftGrid[1][1]=6;}

void SpriteShiftInitialise_TGILBERT(DriftSprite_TGILBERT* DSprite){
DSprite->DriftGrid[0][0]=0; //bas gauche
DSprite->DriftGrid[0][1]=0; //bas droite
DSprite->DriftGrid[1][0]=0; //haut gauche
DSprite->DriftGrid[1][1]=0; //haut droite
DSprite->x4decalage=0;
DSprite->y8decalage=0;
DSprite->MainPositionOnGridH=11;
DSprite->MainPositionOnGridV=3;
}


uint16_t Pos_1024=0;
#define POS_1024 RETURN_1024_POS_TGILBERT ()

uint16_t RETURN_1024_POS_TGILBERT(void){
if (Pos_1024<1024) {Pos_1024++;}
return  (Pos_1024-1); 
}


/////////////////////////////////////////////////////
void Tiny_Flip_TGILBERT(DriftSprite_TGILBERT* DSprite){
uint8_t nn,x,m,n,t,Start,decal;
uint8_t while1=1;
#define PrecessQuit nn++;if (nn>127) {while1=0;break;}
Pos_1024=0;
for (x=0;x<LIVE_TGILBERT-1;x++){
for(t=0;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite26_TGILBERT[t]));}
for(t=0;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite27_TGILBERT[t]));}
}
for (x=0;x<11+(3-(LIVE_TGILBERT-1));x++){
for(t=0;t<8;t++){display.buffer[POS_1024] =(0x00);}}
if ((pgm_read_byte(&KeyinLevel_TGILBERT[levelType_TGILBERT])==keyS_TGILBERT)&&(timer_TGILBERT<=30)) {
for (x=0;x<4;x++){
display.buffer[POS_1024] =(pgm_read_byte(&sprite12_TGILBERT[x]));}
for (x=0;x<3;x++){
for (t=0;t<4;t++){display.buffer[POS_1024] =(0x00);}
}
}else{
for (x=0;x<4;x++){
for (t=0;t<4;t++){display.buffer[POS_1024] =(0x00);}
}}  
for (m = 1; m < 8; m++)
{

n=0; 
nn=0;  
while1=1;
Start=3-step4_TGILBERT; 
#define decalIN for(decal=0;decal<DSprite->x4decalage;decal++){display.buffer[POS_1024] =(0X00);PrecessQuit}// for main sprite scr pix2pix
#define decalOUT for(decal=0;decal<4-DSprite->x4decalage;decal++){display.buffer[POS_1024] =(0X00);PrecessQuit}// for main sprite scr pix2pix
while(while1){
if ((Map_TGILBERT[m][n]==7)&&(while1!=0)) {
for(t=Start;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite7_TGILBERT[t]));PrecessQuit}Start=0;
// main sprite 
}else if (((Map_TGILBERT[m][n]==5)||(Map_TGILBERT[m][n]==55))&&(while1!=0)) {
if (Map_TGILBERT[m][n]==55) {VSlideOut_TGILBERT=((100/VSlide_TGILBERT[8-DSprite->y8decalage])/100);}else{VSlideOut_TGILBERT=VSlide_TGILBERT[DSprite->y8decalage];}
decalIN;
if (LorR_TGILBERT==1){
if (MainAnim_TGILBERT==0) {
for(t=0;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite20_TGILBERT[t])*VSlideOut_TGILBERT);PrecessQuit}Start=0;
}
if (MainAnim_TGILBERT==1) { 
for(t=0;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite22_TGILBERT[t])*VSlideOut_TGILBERT);PrecessQuit}Start=0;
}
if (MainAnim_TGILBERT==2) {
for(t=0;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite24_TGILBERT[t])*VSlideOut_TGILBERT);PrecessQuit}Start=0; 
} 
}else{  
if (MainAnim_TGILBERT==0) {
for(t=0;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite26_TGILBERT[t])*VSlideOut_TGILBERT);PrecessQuit}Start=0;   
}
if (MainAnim_TGILBERT==1) {
for(t=0;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite28_TGILBERT[t])*VSlideOut_TGILBERT);PrecessQuit}Start=0;   
}
if (MainAnim_TGILBERT==2) {
for(t=0;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite30_TGILBERT[t])*VSlideOut_TGILBERT);PrecessQuit}Start=0;  
}}
}else if (((Map_TGILBERT[m][n]==6)||(Map_TGILBERT[m][n]==66))&&(while1!=0)) {
if (Map_TGILBERT[m][n]==66) {VSlideOut_TGILBERT=((100/VSlide_TGILBERT[8-DSprite->y8decalage])/100);}else{VSlideOut_TGILBERT=VSlide_TGILBERT[DSprite->y8decalage];}
if (LorR_TGILBERT==1){
if (MainAnim_TGILBERT==0) {
for(t=0;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite21_TGILBERT[t])*VSlideOut_TGILBERT);PrecessQuit Start=DSprite->x4decalage;}
}
if (MainAnim_TGILBERT==1) {
for(t=0;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite23_TGILBERT[t])*VSlideOut_TGILBERT);PrecessQuit Start=DSprite->x4decalage;}
}
if (MainAnim_TGILBERT==2) {
for(t=0;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite25_TGILBERT[t])*VSlideOut_TGILBERT);PrecessQuit Start=DSprite->x4decalage;}
} }else{  
if (MainAnim_TGILBERT==0) {
for(t=0;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite27_TGILBERT[t])*VSlideOut_TGILBERT);PrecessQuit Start=DSprite->x4decalage;}
}
if (MainAnim_TGILBERT==1) {
for(t=0;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite29_TGILBERT[t])*VSlideOut_TGILBERT);PrecessQuit Start=DSprite->x4decalage;} 
}
if (MainAnim_TGILBERT==2) {
for(t=0;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite31_TGILBERT[t])*VSlideOut_TGILBERT);PrecessQuit Start=DSprite->x4decalage;}
}}
//fin main sprite
}else if ((Map_TGILBERT[m][n]==1)&&(while1!=0)) {
for(t=Start;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite1_TGILBERT[t]));PrecessQuit}Start=0;
}else if ((Map_TGILBERT[m][n]==2)&&(while1!=0)) {
for(t=Start;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite2_TGILBERT[t]));PrecessQuit}Start=0;
}else if ((Map_TGILBERT[m][n]==3)&&(while1!=0)) {
for(t=Start;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite3_TGILBERT[t]));PrecessQuit}Start=0;
}else if ((Map_TGILBERT[m][n]==4)&&(while1!=0)) {
for(t=Start;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite4_TGILBERT[t]));PrecessQuit}Start=0;
}else if ((Map_TGILBERT[m][n]==8)&&(while1!=0)) {
for(t=Start;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite8_TGILBERT[t]));PrecessQuit}Start=0;
}else if ((Map_TGILBERT[m][n]==15)&&(while1!=0)) {
for(t=Start;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite15_TGILBERT[t]));PrecessQuit}Start=0;
}else if ((Map_TGILBERT[m][n]==16)&&(while1!=0)) {
for(t=Start;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite16_TGILBERT[t]));PrecessQuit}Start=0;
}
else if ((Map_TGILBERT[m][n]==11)&&(while1!=0)) {
if (timer_TGILBERT>30){
for(t=Start;t<4;t++){
display.buffer[POS_1024] =(pgm_read_byte(&sprite11_TGILBERT[t]));PrecessQuit}Start=0;
}else{
for(t=Start;t<4;t++){
display.buffer[POS_1024] =(pgm_read_byte(&sprite12_TGILBERT[t]));PrecessQuit}Start=0;
}}else if ((Map_TGILBERT[m][n]==13)&&(while1!=0)) {
for(t=Start;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite13_TGILBERT[t]));PrecessQuit}Start=0;
}else if ((Map_TGILBERT[m][n]==14)&&(while1!=0)) {
for(t=Start;t<4;t++){display.buffer[POS_1024] =(pgm_read_byte(&sprite14_TGILBERT[t]));PrecessQuit}Start=0;
}
else{if (while1!=0){
for(t=Start;t<4;t++){
display.buffer[POS_1024]=(0x00);PrecessQuit}Start=0;
}}
if (while1!=0) {n++; }
}

}
display.display();   
}
