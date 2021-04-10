//     >>>>>  MEGA COMPILATION for ESP8266/ESP8285  GPL v3 <<<<
//                    >>>>>  MEGA Tiny Joypad  <<<<
//                      Programmer: Daniel C 2019
//             Contact EMAIL: electro_l.i.b@tinyjoypad.com
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


#include "spritebank_TBOMBER.h"
#define Frame_Rate_TBOMBER 0


// var public
uint8_t SPEEDBOMBER_TBOMBER=0;
int8_t BOMBXY_TBOMBER[4]={-10,-10,0,0};
uint8_t live_TBOMBER;
uint8_t INGAME_TBOMBER;
int8_t Level_TBOMBER;
uint8_t Frame_TBOMBER;
uint8_t BlocBombMem_TBOMBER[14];  
// fin var public


uint8_t RecupeBacktoCompV_TBOMBER(uint8_t SpriteCheck,PERSONAGE_TBOMBER *Sprite);
uint8_t RecupeBacktoCompH_TBOMBER(uint8_t SpriteCheck,PERSONAGE_TBOMBER *Sprite);

void Sound_TBOMBER(uint8_t freq,uint8_t dur);
uint8_t background_TBOMBER(uint8_t x,uint8_t y);
uint8_t return_if_sprite_present_TBOMBER(uint8_t x,PERSONAGE_TBOMBER  *Sprite,uint8_t SpriteNumber);
uint8_t SpriteWrite_TBOMBER(uint8_t x,uint8_t y,PERSONAGE_TBOMBER  *Sprite);
uint8_t SplitSpriteDecalageY_TBOMBER(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN);
uint8_t BOOLREAD_TBOMBER(uint8_t Numero);
void BOOLWRITE0_TBOMBER(uint8_t BoolNumber);
uint8_t BlockBomb_TBOMBER(uint8_t x,uint8_t y,uint8_t Divx);
uint8_t BombBlitz_TBOMBER(uint8_t x,uint8_t y);
uint8_t Explose_TBOMBER(uint8_t x,uint8_t y);
uint8_t PrintLive_TBOMBER(uint8_t x,uint8_t y);
void Tiny_Flip_TBOMBER(uint8_t render0_picture1,PERSONAGE_TBOMBER *Sprite);

uint8_t ScanHRecupe_TBOMBER(uint8_t UporDown,uint8_t Decalage);
uint8_t Trim_TBOMBER(uint8_t Y1orY2,uint8_t TrimValue,uint8_t Decalage);

uint8_t CheckCollisionWithBlock_TBOMBER(uint8_t SpriteCheck,PERSONAGE_TBOMBER *Sprite);
uint8_t CheckCollisionWithBomb_TBOMBER(uint8_t SpriteCheck,PERSONAGE_TBOMBER *Sprite);
uint8_t CheckCollisionWithBack_TBOMBER(uint8_t SpriteCheck,uint8_t HorVcheck,PERSONAGE_TBOMBER *Sprite);
void RefreshCaracter_TBOMBER(PERSONAGE_TBOMBER *Sprite);
uint8_t CollisionTiny2Caracter_TBOMBER(PERSONAGE_TBOMBER *Sprite);
uint8_t COLLISION11_TBOMBER(uint8_t x1,uint8_t y1,uint8_t w1,uint8_t h1,uint8_t x2,uint8_t y2,uint8_t w2,uint8_t h2);
void DestroyEnemy_TBOMBER(PERSONAGE_TBOMBER *Sprite);
void DestroyBloc_TBOMBER(void);
void DeadSong_TBOMBER(void);
uint8_t CheckLevelEnded_TBOMBER(PERSONAGE_TBOMBER *Sprite);
void StartGame_TBOMBER(void);
void resetBomb_TBOMBER(void);
void resetMonster_TBOMBER(PERSONAGE_TBOMBER *Sprite);
void ResetVar_TBOMBER(PERSONAGE_TBOMBER * Sprite);
void LoadLevel_TBOMBER(uint8_t LeveL);






                                                                                                                                 
void LoadLevel_TBOMBER(uint8_t LeveL){
for (uint8_t t=0;t<14;t++){
BlocBombMem_TBOMBER[t]=pgm_read_byte(&level_TBOMBER[t+(LeveL*14)]);
}}

void ResetVar_TBOMBER(PERSONAGE_TBOMBER * Sprite){
live_TBOMBER=3;
Level_TBOMBER=-1;
INGAME_TBOMBER=0;
SPEEDBOMBER_TBOMBER=0;
resetMonster_TBOMBER(Sprite);
}

void resetMonster_TBOMBER(PERSONAGE_TBOMBER *Sprite){
Sprite[1].dead=0;
Sprite[2].dead=0;
Sprite[3].dead=0;
Sprite[4].dead=0;
}

void resetBomb_TBOMBER(void){
BOMBXY_TBOMBER[0]=-10; 
BOMBXY_TBOMBER[1]=-10; 
BOMBXY_TBOMBER[2]=0; 
BOMBXY_TBOMBER[3]=0; 
}


void StartGame_TBOMBER(void){
if (INGAME_TBOMBER==0) {
 while(1){if (BUTTON_UP){break;}}
INGAME_TBOMBER=1;}
}

void loop_TBOMBER() {
ESP.wdtDisable();
ESP.wdtFeed();
PERSONAGE_TBOMBER Sprite_TBOMBER[5];
NEWGAME:
ResetVar_TBOMBER(&Sprite_TBOMBER[0]);
while(1){
ESP.wdtFeed();
Tiny_Flip_TBOMBER(1,&Sprite_TBOMBER[0]);
if (BUTTON_DOWN) {StartGame_TBOMBER();break;}
}
NEWLEVEL:
if (Level_TBOMBER<2) {
if (Level_TBOMBER>-1) {
{for(uint8_t t=0;t<=4;t++){Sound_TBOMBER(80,100);My_delay_ms(300);}
}}

Level_TBOMBER++;
}else{
{for(uint8_t t=0;t<=4;t++){Sound_TBOMBER(80,100);My_delay_ms(300);}}
SPEEDBOMBER_TBOMBER=1;Level_TBOMBER=0;}
resetMonster_TBOMBER(Sprite_TBOMBER);
LoadLevel_TBOMBER(Level_TBOMBER);
RESTARTLEVEL:
resetBomb_TBOMBER();
Sprite_TBOMBER[0].type=0;
Sprite_TBOMBER[0].x=9;
Sprite_TBOMBER[0].y=7;
Sprite_TBOMBER[0].Decalagey=0;
Sprite_TBOMBER[0].DirectionV=2;
Sprite_TBOMBER[0].DirectionH=2;
Sprite_TBOMBER[0].DirectionAnim=0;
Sprite_TBOMBER[0].dead=0;
Sprite_TBOMBER[1].type=1;
Sprite_TBOMBER[1].x=56;
Sprite_TBOMBER[1].y=1;
Sprite_TBOMBER[1].Decalagey=0;
Sprite_TBOMBER[2].type=1;
Sprite_TBOMBER[2].x=120;
Sprite_TBOMBER[2].y=2;
Sprite_TBOMBER[2].Decalagey=0;
Sprite_TBOMBER[3].type=1;
Sprite_TBOMBER[3].x=119;
Sprite_TBOMBER[3].y=7;
Sprite_TBOMBER[3].Decalagey=0;
Sprite_TBOMBER[4].type=1;
Sprite_TBOMBER[4].x=24;
Sprite_TBOMBER[4].y=5;
Sprite_TBOMBER[4].Decalagey=0;
//INGAME:
while(1){
ESP.wdtFeed();
if (BUTTON_DOWN) {StartGame_TBOMBER();}
if (INGAME_TBOMBER==2) {
if (TINYJOYPAD_LEFT==0){Sprite_TBOMBER[0].DirectionV=0;}
else if (TINYJOYPAD_RIGHT==0) {Sprite_TBOMBER[0].DirectionV=1;}else{if (((Sprite_TBOMBER[0].x)%8)==0) Sprite_TBOMBER[0].DirectionV=2;}
if (TINYJOYPAD_DOWN==0) {Sprite_TBOMBER[0].DirectionH=1;}
else if (TINYJOYPAD_UP==0) {Sprite_TBOMBER[0].DirectionH=0;}else{if (Sprite_TBOMBER[0].Decalagey==0) Sprite_TBOMBER[0].DirectionH=2;}
if ((BUTTON_DOWN)&&(BOMBXY_TBOMBER[2]==0)) {
  BOMBXY_TBOMBER[0]=(uint8_t((Sprite_TBOMBER[0].x+3)/8))*8;
  BOMBXY_TBOMBER[1]=(uint8_t(((Sprite_TBOMBER[0].y*8)+(Sprite_TBOMBER[0].Decalagey)+3)/8));
  BOMBXY_TBOMBER[2]=5;
{uint8_t t;for(t=155;t<255;t++){Sound_TBOMBER(2+t,2);Sound_TBOMBER(25+t,1);}}
}}
if (Frame_TBOMBER<24) {Frame_TBOMBER++;}else{Frame_TBOMBER=0;}
if (CollisionTiny2Caracter_TBOMBER(&Sprite_TBOMBER[0])==0) {
RefreshCaracter_TBOMBER(&Sprite_TBOMBER[0]);}
else{
DeadSong_TBOMBER();
if (live_TBOMBER>0) {live_TBOMBER--;goto RESTARTLEVEL;}else{
My_delay_ms(200);
{for(uint8_t t=0;t<5;t++){Sound_TBOMBER (100,100);Sound_TBOMBER (1,100);}} 
goto NEWGAME;}}
if ((Frame_TBOMBER==0)||(Frame_TBOMBER==8)||(Frame_TBOMBER==16)) {
if (BOMBXY_TBOMBER[2]>1) {                               
if (BOMBXY_TBOMBER[3]<2) {BOMBXY_TBOMBER[3]++;}else{BOMBXY_TBOMBER[3]=0;BOMBXY_TBOMBER[2]--;} 
}}
if (Frame_TBOMBER%4==0) {
  if (BOMBXY_TBOMBER[2]==1) {                             
  if (BOMBXY_TBOMBER[3]<2) {
  if (BOMBXY_TBOMBER[3]==1) {DestroyEnemy_TBOMBER(&Sprite_TBOMBER[0]);DestroyBloc_TBOMBER();}
  BOMBXY_TBOMBER[3]++;
  }else{
resetBomb_TBOMBER();
{for(uint8_t t=210;t<255;t++){Sound_TBOMBER(2+t,1);Sound_TBOMBER(255-t,2);}
}}}}

while((currentMillis-MemMillis)<Frame_Rate_TBOMBER){
currentMillis=millis();
}
MemMillis=currentMillis;

if (Frame_TBOMBER%2==0) {
Tiny_Flip_TBOMBER(0,&Sprite_TBOMBER[0]);
if (INGAME_TBOMBER==1){INGAME_TBOMBER=2;
{for (uint8_t t=0;t<=41;t=t+2){Sound_TBOMBER(pgm_read_byte(&Music_TBOMBER[t]),pgm_read_byte(&Music_TBOMBER[t+1]));}
My_delay_ms(500);
}}}
if (Sprite_TBOMBER[0].dead==1) {if (live_TBOMBER>0) {DeadSong_TBOMBER();live_TBOMBER--;goto RESTARTLEVEL;}else{DeadSong_TBOMBER();
My_delay_ms(200);
{for(uint8_t t=0;t<5;t++){Sound_TBOMBER (100,100);Sound_TBOMBER (1,100);}}
goto NEWGAME;}}
if (Frame_TBOMBER==12) {
if (CheckLevelEnded_TBOMBER(&Sprite_TBOMBER[0])==1) goto NEWLEVEL;
}}}
////////////////////////////////// main end /////////////////////////////////

uint8_t CheckLevelEnded_TBOMBER(PERSONAGE_TBOMBER *Sprite){
for (uint8_t t=1;t<=4;t++){
if (Sprite[t].dead==0) {return 0;}  
}return 1;}

void DeadSong_TBOMBER(void){
for (uint8_t t=1;t<255;t++){
Sound_TBOMBER(t,1);
Sound_TBOMBER(255-t,2);   
}My_delay_ms(300);}

void DestroyBloc_TBOMBER(void){
uint8_t x=((BOMBXY_TBOMBER[0]-8)/8);
uint8_t y=(BOMBXY_TBOMBER[1]-1);
if (y!=0) BOOLWRITE0_TBOMBER(x+((y-1)*15));
BOOLWRITE0_TBOMBER(x+((y)*15));
if (y!=6) BOOLWRITE0_TBOMBER(x+((y+1)*15));
if (x!=0) BOOLWRITE0_TBOMBER((x-1)+((y)*15));
if (x!=14) BOOLWRITE0_TBOMBER((x+1)+((y)*15));
}

void DestroyEnemy_TBOMBER(PERSONAGE_TBOMBER *Sprite){
#define xminf(I) (Sprite[I].x)
#define yminf(I) ((Sprite[I].y*8)+Sprite[I].Decalagey)
for (uint8_t t=0;t<=4;t++){
if (COLLISION11_TBOMBER(xminf(t),yminf(t),7,7,BOMBXY_TBOMBER[0]+1,(BOMBXY_TBOMBER[1]*8)-6,6,21)) {
Sprite[t].y=0; 
Sprite[t].Decalagey=0;
if (Sprite[t].dead!=1)  {Sprite[t].dead=1;}}}
for (uint8_t t=0;t<=4;t++){
if (COLLISION11_TBOMBER(xminf(t),yminf(t),7,7,BOMBXY_TBOMBER[0]-6,(BOMBXY_TBOMBER[1]*8)+1,21,6)) {
Sprite[t].y=0; 
Sprite[t].Decalagey=0;
if (Sprite[t].dead!=1) {Sprite[t].dead=1;}
}}}

uint8_t COLLISION11_TBOMBER(uint8_t x1,uint8_t y1,uint8_t w1,uint8_t h1,uint8_t x2,uint8_t y2,uint8_t w2,uint8_t h2){
if ((x1+w1<x2)||(y1+h1<y2)||(x1>x2+w2)||(y1>y2+h2)) {return 0;}else{return 1;}
}

uint8_t CollisionTiny2Caracter_TBOMBER(PERSONAGE_TBOMBER *Sprite){
uint8_t ReturnCollision=0;
#define xmax(I) (Sprite[I].x+6)
#define xmin(I) (Sprite[I].x)
#define ymax(I) ((Sprite[I].y*8)+Sprite[I].Decalagey+6)
#define ymin(I) ((Sprite[I].y*8)+Sprite[I].Decalagey)
if ((INGAME_TBOMBER)) {    
for (uint8_t t=1;t<=4;t++){
if (Sprite[t].dead!=1) {
if ((xmax(0)<xmin(t))||(xmin(0)>xmax(t))||(ymax(0)<ymin(t))||(ymin(0)>ymax(t))) {}else{ 
ReturnCollision=1;
}}
}}return ReturnCollision;}

void RefreshCaracter_TBOMBER(PERSONAGE_TBOMBER *Sprite){
uint8_t memx,memy,memdecalagey;
for (uint8_t t=0;t<=4;t++){
if (((t!=0)&&(SPEEDBOMBER_TBOMBER==1))||(Frame_TBOMBER%2==0)){
memx=Sprite[t].x;
memy=Sprite[t].y;
memdecalagey=Sprite[t].Decalagey;
if (Sprite[t].DirectionV==1) {Sprite[t].x++;}
if (Sprite[t].DirectionV==0) {Sprite[t].x--;}
if (CheckCollisionWithBack_TBOMBER(t,1,Sprite)) {
if (t!=0) {Sprite[t].DirectionV=random(2);}else{ Sprite[t].DirectionV=2;}
Sprite[t].x=memx;}
if (Sprite[t].DirectionH==1) {if (Sprite[t].Decalagey<7) {Sprite[t].Decalagey++;}else{Sprite[t].Decalagey=0;Sprite[t].y++;}}
if (Sprite[t].DirectionH==0) {if (Sprite[t].Decalagey>0) {Sprite[t].Decalagey--;}else{Sprite[t].Decalagey=7;Sprite[t].y--;}}
if (CheckCollisionWithBack_TBOMBER(t,0,Sprite)) {
if (t!=0) {Sprite[t].DirectionH=random(2);}else{Sprite[t].DirectionH=2;}
Sprite[t].y=memy;
Sprite[t].Decalagey=memdecalagey;}
if (t==0) {
if (Frame_TBOMBER%2==0) {
if (Sprite[t].DirectionH==1) {Sprite[t].DirectionAnim=0;}
if (Sprite[t].DirectionH==0) {Sprite[t].DirectionAnim=(2*3);} 
if (Sprite[t].DirectionV==1) {Sprite[t].DirectionAnim=(3*3);}
if (Sprite[t].DirectionV==0) {Sprite[t].DirectionAnim=(1*3);}
}}else{
if ((Frame_TBOMBER==0)||(Frame_TBOMBER==12)) {
Sprite[t].DirectionAnim=0;
if (Sprite[t].DirectionH==1) {Sprite[t].DirectionAnim=0;}
if (Sprite[t].DirectionH==0) {Sprite[t].DirectionAnim=0;}
}}
if (t==0) {
if (Frame_TBOMBER%2==0) {
if (Sprite[0].switchanim==0) {
if ((Sprite[0].anim<2)&&((Sprite[t].DirectionH!=2)||(Sprite[t].DirectionV!=2))) {Sprite[0].anim++;}else{Sprite[0].switchanim=1;} 
}else{
if (Sprite[0].anim>0) {Sprite[0].anim--;}else{Sprite[0].switchanim=0;}  
}}}else{
if  (Frame_TBOMBER%6==0) {
if (Sprite[t].anim<2) {Sprite[t].anim++;}else{Sprite[t].anim=0;} 
}}}}}

uint8_t CheckCollisionWithBack_TBOMBER(uint8_t SpriteCheck,uint8_t HorVcheck,PERSONAGE_TBOMBER *Sprite){
uint8_t BacktoComp;
if (HorVcheck==1) {
BacktoComp=RecupeBacktoCompV_TBOMBER(SpriteCheck,Sprite); 
}else{
BacktoComp=RecupeBacktoCompH_TBOMBER(SpriteCheck,Sprite);}
BacktoComp=BacktoComp+CheckCollisionWithBlock_TBOMBER(SpriteCheck,Sprite);
BacktoComp=BacktoComp+CheckCollisionWithBomb_TBOMBER(SpriteCheck,Sprite);
if ((BacktoComp)!=0) {return 1;}else{return 0;}}

uint8_t CheckCollisionWithBomb_TBOMBER(uint8_t SpriteCheck,PERSONAGE_TBOMBER *Sprite){
if (SpriteCheck==0) {return 0;}
return COLLISION11_TBOMBER(Sprite[SpriteCheck].x,(Sprite[SpriteCheck].y*8)+Sprite[SpriteCheck].Decalagey,7,7,BOMBXY_TBOMBER[0],(BOMBXY_TBOMBER[1]*8),7,7);
}

uint8_t CheckCollisionWithBlock_TBOMBER(uint8_t SpriteCheck,PERSONAGE_TBOMBER *Sprite){
#define A_TBOMBER (Sprite[SpriteCheck].x)
#define AA_TBOMBER ((A_TBOMBER+7))
uint8_t B=((((Sprite[SpriteCheck].y-1)*8)+Sprite[SpriteCheck].Decalagey)/8);
uint8_t BB=(((((Sprite[SpriteCheck].y-1)*8)+Sprite[SpriteCheck].Decalagey)+7)/8);
uint8_t Rest=0;
uint8_t ReadBloc=pgm_read_byte(&BlocDetect_TBOMBER[A_TBOMBER]);
if ((ReadBloc!=0xff)&&(ReadBloc!=0xfE)) {
Rest=Rest+BOOLREAD_TBOMBER(ReadBloc+(B*15));
Rest=Rest+BOOLREAD_TBOMBER(ReadBloc+(BB*15));
}
ReadBloc=pgm_read_byte(&BlocDetect_TBOMBER[AA_TBOMBER]);
if ((ReadBloc!=0xff)&&(ReadBloc!=0xfE))  {
Rest=Rest+BOOLREAD_TBOMBER(ReadBloc+(B*15));
Rest=Rest+BOOLREAD_TBOMBER(ReadBloc+(BB*15));
}return Rest;}

uint8_t RecupeBacktoCompV_TBOMBER(uint8_t SpriteCheck,PERSONAGE_TBOMBER *Sprite){
uint8_t Y1_=0b00000000;
uint8_t Y2_=Y1;
#define SpriteWide 6
#define MAXV (Sprite[SpriteCheck].x+SpriteWide)
#define MINV (Sprite[SpriteCheck].x)
if (Sprite[SpriteCheck].DirectionV==1) {
Y1_=pgm_read_byte(&back_TBOMBER[((Sprite[SpriteCheck].y)*128)+(MAXV)]);
Y2_=pgm_read_byte(&back_TBOMBER[((Sprite[SpriteCheck].y+1)*128)+(MAXV)]);
}else if (Sprite[SpriteCheck].DirectionV==0) {
Y1_=pgm_read_byte(&back_TBOMBER[((Sprite[SpriteCheck].y)*128)+(MINV)]);
Y2_=pgm_read_byte(&back_TBOMBER[((Sprite[SpriteCheck].y+1)*128)+(MINV)]);
}else{Y1_=0;Y2_=0;}
//decortique
Y1_=Trim_TBOMBER(0,Y1_,Sprite[SpriteCheck].Decalagey);
Y2_=Trim_TBOMBER(1,Y2_,Sprite[SpriteCheck].Decalagey);
if (((Y1_)!=0b00000000)||((Y2_)!=0b00000000) ) {return 1;}else{return 0;}
}

uint8_t Trim_TBOMBER(uint8_t Y1orY2,uint8_t TrimValue,uint8_t Decalage){
uint8_t Comp;
if (Y1orY2==0) {
Comp=0b01111111<<Decalage;
return (TrimValue&Comp);
}else{
Comp=(0b01111111>>(8-Decalage));
return (TrimValue&Comp);
}}


uint8_t ScanHRecupe_TBOMBER(uint8_t UporDown,uint8_t Decalage){
if (UporDown==0){
return 0b01111111<<Decalage;}
else{
return 0b01111111>>(8-Decalage);
}}

uint8_t RecupeBacktoCompH_TBOMBER(uint8_t SpriteCheck,PERSONAGE_TBOMBER *Sprite){
uint8_t TempPGMByte;
if (Sprite[SpriteCheck].DirectionH==0) {
uint8_t RECUPE=(ScanHRecupe_TBOMBER(0,Sprite[SpriteCheck].Decalagey));
for(uint8_t t=0;t<=6;t++){
if ((((Sprite[SpriteCheck].y)*128)+(Sprite[SpriteCheck].x+t)>1023)||(((Sprite[SpriteCheck].y)*128)+(Sprite[SpriteCheck].x+t)<0)) {TempPGMByte=0x00;}else{
 TempPGMByte=(pgm_read_byte(&back_TBOMBER[((Sprite[SpriteCheck].y)*128)+(Sprite[SpriteCheck].x+t)])); 
}
#define CHECKCOLLISION ((RECUPE)&(TempPGMByte))
if  (CHECKCOLLISION!=0) {return 1;}
}}else if (Sprite[SpriteCheck].DirectionH==1) {
uint8_t tadd=0;
if (Sprite[SpriteCheck].Decalagey>2) { tadd=1;}else{tadd=0;}
uint8_t RECUPE=(ScanHRecupe_TBOMBER(tadd,Sprite[SpriteCheck].Decalagey));
for(uint8_t t=0;t<=6;t++){
if (((((Sprite[SpriteCheck].y+tadd)*128)+(Sprite[SpriteCheck].x+t))>1023)||((((Sprite[SpriteCheck].y+tadd)*128)+(Sprite[SpriteCheck].x+t))<0)) {TempPGMByte=0x00;}else{
TempPGMByte=pgm_read_byte(&back_TBOMBER[((Sprite[SpriteCheck].y+tadd)*128)+(Sprite[SpriteCheck].x+t)]);
}
#define CHECKCOLLISION2 ((RECUPE)&(TempPGMByte))
if  (CHECKCOLLISION2!=0) {return 1;}
}}return 0;}

void Tiny_Flip_TBOMBER(uint8_t render0_picture1,PERSONAGE_TBOMBER *Sprite){
uint8_t y,x; 
uint8_t Div2x=0;
for (y = 0; y < 8; y++){ 
for (x = 0; x < 128; x++){
if (render0_picture1==0) {
if (INGAME_TBOMBER) {display.buffer[x+(y*128)] =(PrintLive_TBOMBER(x,y)&((background_TBOMBER(x,y)|SpriteWrite_TBOMBER(x,y,Sprite)|BlockBomb_TBOMBER(x,y,Div2x)|BombBlitz_TBOMBER(x,y)|Explose_TBOMBER(x,y))));}else{
}}else if (render0_picture1==1){
display.buffer[x+(y*128)] =((pgm_read_byte(&BackBlitz_TBOMBER[x+(y*128)])));}Div2x=!Div2x;}

}
display.display();  
}

uint8_t PrintLive_TBOMBER(uint8_t x,uint8_t y){
uint8_t rest=0xFF;
if ((x>7)||(x<1)) return 0xFF;
switch (live_TBOMBER){
  case 0:if (y==6) rest=0x00;
  case 1:if (y==5) rest=0x00;
  case 2:if (y==4) rest=0x00;
  case 3:
  default:break;
}return rest;}

uint8_t Explose_TBOMBER(uint8_t x,uint8_t y){
#define XPOSFIRE (BOMBXY_TBOMBER[0]-8)
#define YPOSFIRE (BOMBXY_TBOMBER[1]-1)
if (BOMBXY_TBOMBER[2]==1) {   
if ((x>7)&&(y>0)){                         
if ((x>=XPOSFIRE)&&(x<XPOSFIRE+24)&&(y>=YPOSFIRE)&&(y<=YPOSFIRE+2)) {
return pgm_read_byte(&fire_TBOMBER[((x-(XPOSFIRE))+((y-(YPOSFIRE))*72))+(BOMBXY_TBOMBER[3]*24)]);
}}}return 0x00;}

uint8_t BombBlitz_TBOMBER(uint8_t x,uint8_t y){
if ((x>=BOMBXY_TBOMBER[0])&&(x<=BOMBXY_TBOMBER[0]+7)&&(y==BOMBXY_TBOMBER[1])) {
return pgm_read_byte(&bomb_TBOMBER[(x-BOMBXY_TBOMBER[0])+(BOMBXY_TBOMBER[3]*8)]);
}else{return 0x00;}
}

uint8_t BlockBomb_TBOMBER(uint8_t x,uint8_t y,uint8_t Divx){
if ((y>0)){
uint8_t BLOCVAL=pgm_read_byte(&BlocDetect_TBOMBER[x]);
if (BLOCVAL==0xFE) BLOCVAL=0x01;
if (BLOCVAL==0xFF) return 0x00;
if (BOOLREAD_TBOMBER(BLOCVAL+((y-1)*15))){
if (Divx==0) {
return 0b10101010;  
}else{
return 0b01010101;}
}}return 0x00;}

void BOOLWRITE0_TBOMBER(uint8_t BoolNumber){
uint8_t REST=BoolNumber;
uint8_t DOTBOOLPOSITION=0;
uint8_t SOUSTRAIRE;
DECREASE:
if (REST>=8) {REST=REST-8;DOTBOOLPOSITION=DOTBOOLPOSITION+1;goto DECREASE;}
switch(REST){
  case (0):SOUSTRAIRE=0b01111111;break;
  case (1):SOUSTRAIRE=0b10111111;break;
  case (2):SOUSTRAIRE=0b11011111;break;
  case (3):SOUSTRAIRE=0b11101111;break;
  case (4):SOUSTRAIRE=0b11110111;break;
  case (5):SOUSTRAIRE=0b11111011;break;
  case (6):SOUSTRAIRE=0b11111101;break;
  case (7):SOUSTRAIRE=0b11111110;break;
}
BlocBombMem_TBOMBER[DOTBOOLPOSITION]=BlocBombMem_TBOMBER[DOTBOOLPOSITION]&SOUSTRAIRE;
}

uint8_t BOOLREAD_TBOMBER(uint8_t Numero){
if (Numero>105) return 0;
uint8_t BYTECHECK=Numero;
uint8_t INT8CHOSE=0;
while(BYTECHECK>7){
BYTECHECK=BYTECHECK-8; 
INT8CHOSE++;}
uint8_t Var0=0;
switch (BYTECHECK){
  case 0:Var0=0b10000000;break;
  case 1:Var0=0b01000000;break;
  case 2:Var0=0b00100000;break;
  case 3:Var0=0b00010000;break;
  case 4:Var0=0b00001000;break;
  case 5:Var0=0b00000100;break;
  case 6:Var0=0b00000010;break;
  case 7:Var0=0b00000001;break;
  default:Var0=0b00000000;break;}
if ((BlocBombMem_TBOMBER[INT8CHOSE]&Var0)!=0) {return 1;}else{return 0;}
}

uint8_t SplitSpriteDecalageY_TBOMBER(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN){
if (UPorDOWN) {
return Input<<decalage;
}else{
return Input>>(8-decalage); 
}}

uint8_t SpriteWrite_TBOMBER(uint8_t x,uint8_t y,PERSONAGE_TBOMBER  *Sprite){
uint8_t var1=0;
uint8_t AddBin=0b00000000;
while(1){ 
if (Sprite[var1].y==y) {
if (Sprite[var1].dead!=1) AddBin=AddBin|SplitSpriteDecalageY_TBOMBER(Sprite[var1].Decalagey,return_if_sprite_present_TBOMBER(x,Sprite,var1),1);
}else if (((Sprite[var1].y+1)==y)&&(Sprite[var1].Decalagey!=0)) {
if (Sprite[var1].dead!=1) AddBin=AddBin|SplitSpriteDecalageY_TBOMBER(Sprite[var1].Decalagey,return_if_sprite_present_TBOMBER(x,Sprite,var1),0);
}var1++;
if (var1==5) {break;}
}return AddBin;}

uint8_t return_if_sprite_present_TBOMBER(uint8_t x,PERSONAGE_TBOMBER  *Sprite,uint8_t SpriteNumber){
if  ((x>=Sprite[SpriteNumber].x)&&(x<(Sprite[SpriteNumber].x+8))) { 
if ((INGAME_TBOMBER==0)&&(SpriteNumber==0)) {  return 0;}     
return pgm_read_byte(&caracters_TBOMBER[((x-Sprite[SpriteNumber].x)+(8*(Sprite[SpriteNumber].type*12)))+(Sprite[SpriteNumber].anim*8)+(Sprite[SpriteNumber].DirectionAnim*8)]);
}return 0;}

uint8_t background_TBOMBER(uint8_t x,uint8_t y){
return pgm_read_byte(&BackBlitz_TBOMBER[((y)*128)+((x))]);
}

void Sound_TBOMBER(uint8_t freq,uint8_t dur){
ESP.wdtFeed();
for (uint8_t t=0;t<dur;t++){
if (freq!=0) digitalWrite(PIN_,SOUND_ON_OFF);
for (uint8_t t=0;t<(255-freq);t++){
My_delay_us(1);}
digitalWrite(PIN_,LOW);
for (uint8_t t=0;t<(255-freq);t++){
My_delay_us(1); }}}

