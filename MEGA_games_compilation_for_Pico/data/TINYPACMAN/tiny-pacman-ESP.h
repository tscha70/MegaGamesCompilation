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


#include "spritebank_TPACMAN.h"

#define Frame_Rate_TPACMAN 0

// var public
uint8_t LEVELSPEED_TPACMAN;
uint8_t GobbingEND_TPACMAN;
uint8_t LIVE_TPACMAN;
uint8_t INGAME_TPACMAN;
uint8_t Gobeactive_TPACMAN;
uint8_t TimerGobeactive_TPACMAN;
uint8_t add_TPACMAN;
uint8_t dotsMem_TPACMAN[9];
int8_t dotscount_TPACMAN;
uint8_t Frame_TPACMAN;
// fin var public
void Sound_TPACMAN(uint8_t freq,uint8_t dur);
uint8_t background_TPACMAN(uint8_t x,uint8_t y);
uint8_t return_if_sprite_present_TPACMAN(uint8_t x,PERSONAGE_TPACMAN  *Sprite,uint8_t SpriteNumber);
uint8_t SpriteWrite_TPACMAN(uint8_t x,uint8_t y,PERSONAGE_TPACMAN  *Sprite);
uint8_t SplitSpriteDecalageY_TPACMAN(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN);
void DotsDestroy_TPACMAN(uint8_t DotsNumber);
uint8_t checkDotPresent_TPACMAN(uint8_t  DotsNumber);
uint8_t DotsWrite_TPACMAN(uint8_t x,uint8_t y,PERSONAGE_TPACMAN *Sprite);
uint8_t LiveWrite_TPACMAN(uint8_t x,uint8_t y);
uint8_t FruitWrite_TPACMAN(uint8_t x,uint8_t y);
void Tiny_Flip_TPACMAN(uint8_t render0_picture1,PERSONAGE_TPACMAN *Sprite);
uint8_t RecupeBacktoCompH_TPACMAN(uint8_t SpriteCheck,PERSONAGE_TPACMAN *Sprite);
uint8_t ScanHRecupe_TPACMAN(uint8_t UporDown,uint8_t Decalage);
uint8_t Trim_TPACMAN(uint8_t Y1orY2,uint8_t TrimValue,uint8_t Decalage);
uint8_t RecupeBacktoCompV_TPACMAN(uint8_t SpriteCheck,PERSONAGE_TPACMAN *Sprite);
uint8_t CheckCollisionWithBack_TPACMAN(uint8_t SpriteCheck,uint8_t HorVcheck,PERSONAGE_TPACMAN *Sprite);
void RefreshCaracter_TPACMAN(PERSONAGE_TPACMAN *Sprite);
uint8_t CollisionPac2Caracter_TPACMAN(PERSONAGE_TPACMAN *Sprite);
void StartGame_TPACMAN(PERSONAGE_TPACMAN *Sprite);
void ResetVar_TPACMAN(void);






enum {PACMAN=0,FANTOME=1,FRUIT=2};

void ResetVar_TPACMAN(void){
LEVELSPEED_TPACMAN=200;
GobbingEND_TPACMAN=0;
LIVE_TPACMAN=3;
Gobeactive_TPACMAN=0;
TimerGobeactive_TPACMAN=0;
add_TPACMAN=0;
INGAME_TPACMAN=0;
for(uint8_t t=0;t<9;t++){
dotsMem_TPACMAN[t]=0xff;}
dotscount_TPACMAN=0;
Frame_TPACMAN=0;}


void StartGame_TPACMAN(PERSONAGE_TPACMAN *Sprite){
if (INGAME_TPACMAN==0) {
Sprite[1].x=76;
Sprite[1].y=3;
Sprite[2].x=75;
Sprite[2].y=4;
Sprite[3].x=77;
Sprite[3].y=3;
Sprite[4].x=76;
Sprite[4].y=4;
INGAME_TPACMAN=1;}}

void loop_TPACMAN() {
ESP.wdtDisable();
uint8_t t;
PERSONAGE_TPACMAN Sprite[5];
NEWGAME:
ResetVar_TPACMAN();
LIVE_TPACMAN=3;
goto New;
NEWLEVEL:
if (LEVELSPEED_TPACMAN>10) {LEVELSPEED_TPACMAN=LEVELSPEED_TPACMAN-10;
if ((LEVELSPEED_TPACMAN==160)||(LEVELSPEED_TPACMAN==120)||(LEVELSPEED_TPACMAN==80)||(LEVELSPEED_TPACMAN==40)||(LEVELSPEED_TPACMAN==10)){    
if (LIVE_TPACMAN<3) {LIVE_TPACMAN++; for(t=0;t<=4;t++){
Sound_TPACMAN(80,100);My_delay_ms(300);
}}}}
New:
GobbingEND_TPACMAN=(LEVELSPEED_TPACMAN/2);
for(t=0;t<9;t++){
dotsMem_TPACMAN[t]=0xff;
}
RESTARTLEVEL:
Gobeactive_TPACMAN=0;
Sprite[0].type=PACMAN;
Sprite[0].x=64;
Sprite[0].y=3;
Sprite[0].Decalagey=5;
Sprite[0].DirectionV=2;
Sprite[0].DirectionH=2;
Sprite[0].DirectionAnim=0;
Sprite[1].type=FANTOME;
Sprite[1].x=76;
Sprite[1].y=4;
Sprite[1].guber=0;
Sprite[2].type=FANTOME;
Sprite[2].x=75;
Sprite[2].y=5;
Sprite[2].guber=0;
Sprite[3].type=FANTOME;
Sprite[3].x=77;
Sprite[3].y=4;
Sprite[3].guber=0;
Sprite[4].type=FANTOME;
Sprite[4].x=76;
Sprite[4].y=5;
Sprite[4].guber=0;
while(1){
ESP.wdtFeed();
//joystick
if (BUTTON_DOWN) {StartGame_TPACMAN(&Sprite[0]);}
if (INGAME_TPACMAN) {
if (TINYJOYPAD_LEFT==0) {Sprite[0].DirectionV=0;}
else if (TINYJOYPAD_RIGHT==0) {Sprite[0].DirectionV=1;}
if (TINYJOYPAD_DOWN==0) {Sprite[0].DirectionH=1;}
else if (TINYJOYPAD_UP==0) {Sprite[0].DirectionH=0;}
//fin joystick
if (TimerGobeactive_TPACMAN>1)  {TimerGobeactive_TPACMAN--;}else{if (TimerGobeactive_TPACMAN==1) {TimerGobeactive_TPACMAN=0;Gobeactive_TPACMAN=0;}}}
if (Frame_TPACMAN<24) {Frame_TPACMAN++;}else{Frame_TPACMAN=0;}
if (CollisionPac2Caracter_TPACMAN(&Sprite[0])==0) {RefreshCaracter_TPACMAN(&Sprite[0]);}else{
Sound_TPACMAN(100,200);Sound_TPACMAN(75,200);Sound_TPACMAN(50,200);Sound_TPACMAN(25,200);Sound_TPACMAN(12,200);delay(400);
if (LIVE_TPACMAN>0) {LIVE_TPACMAN--;goto RESTARTLEVEL;}else{goto NEWGAME;}}
while((currentMillis-MemMillis)<Frame_Rate_TPACMAN){
currentMillis=millis();
}
MemMillis=currentMillis;
if (Frame_TPACMAN%2==0) {
Tiny_Flip_TPACMAN(0,&Sprite[0]);
if (INGAME_TPACMAN==1){
for (uint8_t t=0;t<=139;t=t+2){
Sound_TPACMAN(pgm_read_byte(&Music_TPACMAN[t])-8,(pgm_read_byte(&Music_TPACMAN[t+1])-100)); 
}INGAME_TPACMAN=2;}
}else{
for(t=0;t<63;t++){
if (checkDotPresent_TPACMAN(t)) {break;}else{if (t==62) { for(uint8_t r=0;r<60;r++){Sound_TPACMAN(2+r,10);Sound_TPACMAN(255-r,20);}My_delay_ms(1000);goto NEWLEVEL;}}
}}
if ((Gobeactive_TPACMAN)&&(Frame_TPACMAN%2==0)) {Sound_TPACMAN((255-TimerGobeactive_TPACMAN),1);}
}}
////////////////////////////////// main end /////////////////////////////////

uint8_t CollisionPac2Caracter_TPACMAN(PERSONAGE_TPACMAN *Sprite){
uint8_t ReturnCollision=0;
#define xmax(I) (Sprite[I].x+6)
#define xmin(I) (Sprite[I].x)
#define ymax(I) ((Sprite[I].y*8)+Sprite[I].Decalagey+6)
#define ymin(I) ((Sprite[I].y*8)+Sprite[I].Decalagey)
if ((INGAME_TPACMAN)) {    
for (uint8_t t=1;t<=4;t++){
if ((xmax(0)<xmin(t))||(xmin(0)>xmax(t))||(ymax(0)<ymin(t))||(ymin(0)>ymax(t))) {}else{ 
if (Gobeactive_TPACMAN) {if (Sprite[t].guber!=1) {Sound_TPACMAN(20,100);Sound_TPACMAN(2,100);}Sprite[t].guber=1;ReturnCollision=0;}else{ if (Sprite[t].guber==1) {ReturnCollision=0;}else{ReturnCollision=1;}}
}}}return ReturnCollision;}

void RefreshCaracter_TPACMAN(PERSONAGE_TPACMAN *Sprite){
uint8_t memx,memy,memdecalagey;
for (uint8_t t=0;t<=4;t++){
memx=Sprite[t].x;
memy=Sprite[t].y;
memdecalagey=Sprite[t].Decalagey;
if ((Sprite[t].y>-1)&&(Sprite[t].y<8)) {
if ((Frame_TPACMAN%2==0)||(t==0)||(LEVELSPEED_TPACMAN<=160)) {
if (Sprite[t].DirectionV==1) {Sprite[t].x++;}
if (Sprite[t].DirectionV==0) {
if (t==0) {
if ((Sprite[0].y==3)&&(Sprite[0].x==86)){}else{Sprite[t].x--;}
}else{Sprite[t].x--;}
}}}
if (CheckCollisionWithBack_TPACMAN(t,1,Sprite)) {
if (t!=0) {Sprite[t].DirectionV=random(2);}else{ Sprite[t].DirectionV=2;}
Sprite[t].x=memx;
}
if ((Frame_TPACMAN%2==0)||(t==0)||(LEVELSPEED_TPACMAN<=160)) {
if (Sprite[t].DirectionH==1) {if (Sprite[t].Decalagey<7) {Sprite[t].Decalagey++;}else{Sprite[t].Decalagey=0;Sprite[t].y++;if (Sprite[t].y==9) {Sprite[t].y=-1;}}}
if (Sprite[t].DirectionH==0) {if (Sprite[t].Decalagey>0) {Sprite[t].Decalagey--;}else{Sprite[t].Decalagey=7;Sprite[t].y--;if (Sprite[t].y==-2) {Sprite[t].y=8;}}}
}
if (CheckCollisionWithBack_TPACMAN(t,0,Sprite)) {
if (t!=0) {Sprite[t].DirectionH=random(2);}else{Sprite[t].DirectionH=2;}
Sprite[t].y=memy;
Sprite[t].Decalagey=memdecalagey;
}
if (t==0) {
if (Frame_TPACMAN%2==0) {
if (Sprite[t].DirectionH==1) {Sprite[t].DirectionAnim=0;}
if (Sprite[t].DirectionH==0) {Sprite[t].DirectionAnim=(2*3);} 
if (Sprite[t].DirectionV==1) {Sprite[t].DirectionAnim=(3*3);}
if (Sprite[t].DirectionV==0) {Sprite[t].DirectionAnim=(1*3);}
}}else{
if ((Frame_TPACMAN==0)||(Frame_TPACMAN==12)) {
Sprite[t].DirectionAnim=0;
if (Sprite[t].DirectionH==1) {Sprite[t].DirectionAnim=0;}
if (Sprite[t].DirectionH==0) {Sprite[t].DirectionAnim=2;}
}}
if (t==0) {
if (Frame_TPACMAN%2==0) {
if (Sprite[0].switchanim==0) {
if (Sprite[0].anim<2) {Sprite[0].anim++;}else{Sprite[0].switchanim=1;} 
}else{
if (Sprite[0].anim>0) {Sprite[0].anim--;}else{Sprite[0].switchanim=0;}  
}}}else{
if ((Sprite[t].guber==1)&&(Sprite[t].x>=74)&&(Sprite[t].x<=76)&&(Sprite[t].y>=2)&&(Sprite[t].y<=4)) {Sprite[t].guber=0;}
if  (Frame_TPACMAN%2==0) {
if (Sprite[t].anim<1) {Sprite[t].anim++;}else{Sprite[t].anim=0; } 
}}}}

uint8_t CheckCollisionWithBack_TPACMAN(uint8_t SpriteCheck,uint8_t HorVcheck,PERSONAGE_TPACMAN *Sprite){
uint8_t BacktoComp;
if (HorVcheck==1) {
BacktoComp=RecupeBacktoCompV_TPACMAN(SpriteCheck,Sprite); 
}else{
BacktoComp=RecupeBacktoCompH_TPACMAN(SpriteCheck,Sprite);}
if ((BacktoComp)!=0) {return 1;}else{return 0;}}

uint8_t RecupeBacktoCompV_TPACMAN(uint8_t SpriteCheck,PERSONAGE_TPACMAN *Sprite){
uint8_t Y_1=0b00000000;
uint8_t Y_2=Y1;
#define SpriteWide 6
#define MAXV (Sprite[SpriteCheck].x+SpriteWide)
#define MINV (Sprite[SpriteCheck].x)
if (Sprite[SpriteCheck].DirectionV==1) {
Y_1=pgm_read_byte(&back_TPACMAN[((Sprite[SpriteCheck].y)*128)+(MAXV)]);
Y_2=pgm_read_byte(&back_TPACMAN[((Sprite[SpriteCheck].y+1)*128)+(MAXV)]);
}else if (Sprite[SpriteCheck].DirectionV==0) {
Y_1=pgm_read_byte(&back_TPACMAN[((Sprite[SpriteCheck].y)*128)+(MINV)]);
Y_2=pgm_read_byte(&back_TPACMAN[((Sprite[SpriteCheck].y+1)*128)+(MINV)]);
}else{Y_1=0;Y_2=0;}
//decortique
Y_1=Trim_TPACMAN(0,Y_1,Sprite[SpriteCheck].Decalagey);
Y_2=Trim_TPACMAN(1,Y_2,Sprite[SpriteCheck].Decalagey);
if (((Y_1)!=0b00000000)||((Y_2)!=0b00000000) ) {return 1;}else{return 0;}
}

uint8_t Trim_TPACMAN(uint8_t Y1orY2,uint8_t TrimValue,uint8_t Decalage){
uint8_t Comp;
if (Y1orY2==0) {
Comp=0b01111111<<Decalage;
return (TrimValue&Comp);
}else{
Comp=(0b01111111>>(8-Decalage));
return (TrimValue&Comp);
}}

uint8_t ScanHRecupe_TPACMAN(uint8_t UporDown,uint8_t Decalage){
if (UporDown==0){
return 0b01111111<<Decalage;}
else{
return 0b01111111>>(8-Decalage);
}}

uint8_t RecupeBacktoCompH_TPACMAN(uint8_t SpriteCheck,PERSONAGE_TPACMAN *Sprite){
uint8_t TempPGMByte;
if (Sprite[SpriteCheck].DirectionH==0) {
uint8_t RECUPE=(ScanHRecupe_TPACMAN(0,Sprite[SpriteCheck].Decalagey));
for(uint8_t t=0;t<=6;t++){
if ((((Sprite[SpriteCheck].y)*128)+(Sprite[SpriteCheck].x+t)>1023)||(((Sprite[SpriteCheck].y)*128)+(Sprite[SpriteCheck].x+t)<0)) {TempPGMByte=0x00;}else{
 TempPGMByte=(pgm_read_byte(&back_TPACMAN[((Sprite[SpriteCheck].y)*128)+(Sprite[SpriteCheck].x+t)])); 
}
#define CHECKCOLLISION ((RECUPE)&(TempPGMByte))
if  (CHECKCOLLISION!=0) {return 1;}
}}else if (Sprite[SpriteCheck].DirectionH==1) {
uint8_t tadd=0;
if (Sprite[SpriteCheck].Decalagey>2) { tadd=1;}else{tadd=0;}
uint8_t RECUPE=(ScanHRecupe_TPACMAN(tadd,Sprite[SpriteCheck].Decalagey));
for(uint8_t t=0;t<=6;t++){
if (((((Sprite[SpriteCheck].y+tadd)*128)+(Sprite[SpriteCheck].x+t))>1023)||((((Sprite[SpriteCheck].y+tadd)*128)+(Sprite[SpriteCheck].x+t))<0)) {TempPGMByte=0x00;}else{
TempPGMByte=pgm_read_byte(&back_TPACMAN[((Sprite[SpriteCheck].y+tadd)*128)+(Sprite[SpriteCheck].x+t)]);
}
#define CHECKCOLLISION2 ((RECUPE)&(TempPGMByte))
if  (CHECKCOLLISION2!=0) {return 1;}
}}return 0;}

void Tiny_Flip_TPACMAN(uint8_t render0_picture1,PERSONAGE_TPACMAN *Sprite){
uint8_t y,x; 
dotscount_TPACMAN=-1;
for (y = 0; y < 8; y++){ 
for (x = 0; x < 128; x++){
if (render0_picture1==0) {
if (INGAME_TPACMAN) {display.buffer[x+(y*128)] =(background_TPACMAN(x,y)|SpriteWrite_TPACMAN(x,y,Sprite)|DotsWrite_TPACMAN(x,y,Sprite)|LiveWrite_TPACMAN(x,y)|FruitWrite_TPACMAN(x,y));}else{
display.buffer[x+(y*128)] =(0xff-(background_TPACMAN(x,y)|SpriteWrite_TPACMAN(x,y,Sprite)));
}}else if (render0_picture1==1){
display.buffer[x+(y*128)] =(pgm_read_byte(&back_TPACMAN[x+(y*128)]));}}

}
display.display(); 
}

uint8_t FruitWrite_TPACMAN(uint8_t x,uint8_t y){
switch(y){
  case 7:if (x<=7) {return pgm_read_byte(&fruits_TPACMAN[x]);}break;
  case 6:if ((LEVELSPEED_TPACMAN<=190)&&(x<=7)) {return pgm_read_byte(&fruits_TPACMAN[x+8]);}break;
  case 5:if ((LEVELSPEED_TPACMAN<=180)&&(x<=7)) {return pgm_read_byte(&fruits_TPACMAN[x+16]);}break;
  case 4:if ((LEVELSPEED_TPACMAN<=170)&&(x<=7)) {return pgm_read_byte(&fruits_TPACMAN[x+24]);}break;
}return 0;}

uint8_t LiveWrite_TPACMAN(uint8_t x,uint8_t y){
if (y<LIVE_TPACMAN) {if (x<=7) {return pgm_read_byte(&caracters_TPACMAN[x+(1*8)]);}else{return 0;}
}return 0x00;}

uint8_t DotsWrite_TPACMAN(uint8_t x,uint8_t y,PERSONAGE_TPACMAN *Sprite){
uint8_t Menreturn=0;
uint8_t mem1=pgm_read_byte(&dots_TPACMAN[x+(128*y)]);
if (mem1!=0b00000000) {
dotscount_TPACMAN++;
 switch(dotscount_TPACMAN){
  case 0:  
  case 1: 
  case 12: 
  case 13: 
  case 50:
  case 51:
  case 62:
  case 63:Menreturn=1;break;
  default:Menreturn=0;break;
}
if (checkDotPresent_TPACMAN(dotscount_TPACMAN)==0b00000000) {mem1=0x00;}else{
if ((Sprite[0].type==PACMAN)&&((Sprite[0].x<x)&&(Sprite[0].x>x-6))&&(((Sprite[0].y==y)&&(Sprite[0].Decalagey<6))||((Sprite[0].y==y-1)&&(Sprite[0].Decalagey>5)))) {DotsDestroy_TPACMAN(dotscount_TPACMAN);if (Menreturn==1) {TimerGobeactive_TPACMAN=LEVELSPEED_TPACMAN;Gobeactive_TPACMAN=1;}else{Sound_TPACMAN(10,4);Sound_TPACMAN(50,4);}}
}}
if (Menreturn==1) {
if (((Frame_TPACMAN>=6)&&(Frame_TPACMAN<=12))||((Frame_TPACMAN>=18)&&(Frame_TPACMAN<=24))) {
return 0x00;
}else{return mem1;}
}else{return mem1;}}

uint8_t checkDotPresent_TPACMAN(uint8_t  DotsNumber){
uint8_t REST=DotsNumber;
uint8_t DOTBOOLPOSITION=0;
DECREASE:
if (REST>=8) {REST=REST-8;DOTBOOLPOSITION++;goto DECREASE;}
return ((dotsMem_TPACMAN[DOTBOOLPOSITION])&(0b10000000>>REST));
}

void DotsDestroy_TPACMAN(uint8_t DotsNumber){
uint8_t REST=DotsNumber;
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
dotsMem_TPACMAN[DOTBOOLPOSITION]=dotsMem_TPACMAN[DOTBOOLPOSITION]&SOUSTRAIRE;
}

uint8_t SplitSpriteDecalageY_TPACMAN(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN){
if (UPorDOWN) {
return Input<<decalage;
}else{
return Input>>(8-decalage); 
}}

uint8_t SpriteWrite_TPACMAN(uint8_t x,uint8_t y,PERSONAGE_TPACMAN  *Sprite){
uint8_t var1=0;
uint8_t AddBin=0b00000000;
while(1){ 
if (Sprite[var1].y==y) {
AddBin=AddBin|SplitSpriteDecalageY_TPACMAN(Sprite[var1].Decalagey,return_if_sprite_present_TPACMAN(x,Sprite,var1),1);
}else if (((Sprite[var1].y+1)==y)&&(Sprite[var1].Decalagey!=0)) {
AddBin=AddBin|SplitSpriteDecalageY_TPACMAN(Sprite[var1].Decalagey,return_if_sprite_present_TPACMAN(x,Sprite,var1),0);
}
var1++;
if (var1==5) {break;}
}return AddBin;}
  
uint8_t return_if_sprite_present_TPACMAN(uint8_t x,PERSONAGE_TPACMAN  *Sprite,uint8_t SpriteNumber){
uint8_t ADDgobActive;
uint8_t ADDGober;
if  ((x>=Sprite[SpriteNumber].x)&&(x<(Sprite[SpriteNumber].x+8))) { 
if (SpriteNumber!=0) { 
if (Sprite[SpriteNumber].guber==1) {
ADDgobActive=1*(4*8);
ADDGober=Sprite[SpriteNumber].guber*(4*8);
}else{
if ((((Frame_TPACMAN>=6)&&(Frame_TPACMAN<=12))||((Frame_TPACMAN>=18)&&(Frame_TPACMAN<=24)))||(TimerGobeactive_TPACMAN>GobbingEND_TPACMAN)) {ADDgobActive=Gobeactive_TPACMAN*(4*8);}else{ADDgobActive=0;}
ADDGober=0;
}}else{
ADDGober=0;
ADDgobActive=0;
}
if ((INGAME_TPACMAN==0)&&(SpriteNumber==0)) {  return 0;}     
return pgm_read_byte(&caracters_TPACMAN[((x-Sprite[SpriteNumber].x)+(8*(Sprite[SpriteNumber].type*12)))+(Sprite[SpriteNumber].anim*8)+(Sprite[SpriteNumber].DirectionAnim*8)+(ADDgobActive)+(ADDGober)]);
}return 0;}

uint8_t background_TPACMAN(uint8_t x,uint8_t y){
return pgm_read_byte(&BackBlitz_TPACMAN[((y)*128)+((x))]);
}

void Sound_TPACMAN(uint8_t freq,uint8_t dur){
ESP.wdtFeed();
for (uint8_t t=0;t<dur;t++){
if (freq!=0)digitalWrite(PIN_,SOUND_ON_OFF); 
for (uint8_t t=0;t<(255-freq);t++){
My_delay_us(1);}
digitalWrite(PIN_,LOW);
for (uint8_t t=0;t<(255-freq);t++){
My_delay_us(1); }}}

