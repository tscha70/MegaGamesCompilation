//     >>>>>  MEGA COMPILATION for ESP8266/ESP8285  GPL v3 <<<<
//                    >>>>>  MEGA Tiny Joypad  <<<<
//                     Programmer: Daniel C 2019
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


#include "spritebank_TPINBALL.h"
#include <math.h>

#define Frame_Rate_TPINBALL 0//28 original attiny85 speed



//<<<<<<<<<<<<<<<<<<<VARIABLE PUBLIQUE>>>>>>>>>>>>>>>>>

#define SSD64x32 0 //1 pour 64 x 32 : 0 pour 128 x 64
#define SPRINGLONG 72
uint8_t SCANLINE=0;
uint8_t totalBall=4;
uint8_t totalpush=0;
uint8_t FIRSTTIME=0;
uint16_t bouncePush=0; 
uint8_t frameCount=0; 
uint8_t SpringBar=SPRINGLONG;
uint8_t MemExa[3][3]={{0}};
int8_t trigFlipG=0;
int8_t trigFlipD=0;
typedef struct BALL{
float x=0;
float y=0;
float Speedx=0;
float Speedy=0;
float SIMx=0;
float SIMy=0;
float SIMSpeedx=0;
float SIMSpeedy=0;
float DecelX=0;
float DecelY=0;
uint8_t resetBall=0;
uint8_t grid[2][3]={{0}};
}BALL;
//<<<<<<<<<<<<<<<<<<<FIN VARIABLE PUBLIQUE>>>>>>>>>>>>>>>>>
void MURDGE_LOW_AND_HIGH_RES_TPINBALL(void);
void Tiny_Flip2_TPINBALL(BALL *B);
uint16_t RETURN_1024_POS_TPINBALL(void);
uint8_t SliceByte_TPINBALL(uint8_t Vertical,uint8_t Byte);
uint8_t PixelConvert_TPINBALL(uint8_t horiz,uint8_t verti,BALL *B);
uint8_t PixelAsign_TPINBALL(uint8_t Value);
uint8_t RecupeSpring_TPINBALL(uint8_t x,uint8_t y);
uint8_t RecupeFlip_TPINBALL(uint8_t x,uint8_t y);
uint8_t addBin_TPINBALL(uint8_t a,uint8_t b,uint8_t c,uint8_t d);
uint8_t RecupeScreen_TPINBALL(uint8_t nn,uint8_t mm);
uint8_t ColisionCheck_TPINBALL(float x,float y,BALL *B);
void SimulateMove(BALL *B);
void WriteMoveBounce_TPINBALL(BALL *B);
void WriteMove_TPINBALL(BALL *B);
void TrimBallOnSpring_TPINBALL(BALL *B);
uint8_t CheckColisionType_TPINBALL(BALL *B);
void SimulateRebounce_TPINBALL(uint8_t Sim,BALL *B);
void TrimXY(BALL *B);
uint8_t SelectByte_TPINBALL(uint8_t ByteSelect,uint8_t FFx0);
void BallupDate_TPINBALL(BALL *B);
void Sound_TPINBALL(uint8_t freq,uint8_t dur);
void falseBall_TPINBALL(void);
void draw_bmp_TPINBALL(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, const uint8_t bitmap[]);
void fillscreen_TPINBALL(uint8_t VALUE);
//<<<<<<<<<<<<<<<<<<<MAIN>>>>>>>>>>>>>>>>>

void fillscreen_TPINBALL(uint8_t VALUE){
for (uint16_t t=0;t<1024;t++){
display.buffer[t] =(VALUE);
}
display.display();    
}

void draw_bmp_TPINBALL(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, const uint8_t bitmap[]){
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


void loop_TPINBALL() {
ESP.wdtDisable();
NEWGAME:
totalpush=0;
totalBall=5;
fillscreen_TPINBALL(0xff);
My_delay_ms(500);
if (SSD64x32==0) {draw_bmp_TPINBALL(0, 0, 128, 8, intro_TPINBALL);}else{
draw_bmp_TPINBALL(0, 0, 128, 8, intro_TPINBALL);}
for (uint8_t t=255;t>0;t--){
Sound_TPINBALL(t,2);}
for (uint8_t t=0;t<255;t++){
Sound_TPINBALL(t,2);}
My_delay_ms(1000);
while(1){
ESP.wdtFeed();
random(255);
if ((TINYJOYPAD_DOWN==0)||(BUTTON_DOWN)||(TINYJOYPAD_UP==0)) {
fillscreen_TPINBALL(0x00);
if (SSD64x32==0) {draw_bmp_TPINBALL(27+32, 3, 37+32, 5, READY_TPINBALL);}else{
draw_bmp_TPINBALL(27+32, 5, 37+32, 7, READY_TPINBALL);
}
FIRSTTIME=1;
My_delay_ms(1000);
break;}}
start:
if (totalBall!=0) {totalBall--;}else{
My_delay_ms(300);
if (SSD64x32==0) {draw_bmp_TPINBALL(22+32, 2, 41+32, 6, GameOver_TPINBALL);}else{
draw_bmp_TPINBALL(22+32, 4, 41+32, 8, GameOver_TPINBALL);}

 for(uint8_t t=0;t<5;t++){
  Sound_TPINBALL (100,100);
  Sound_TPINBALL (1,100);}
My_delay_ms(1000);goto NEWGAME;}
#define XSTART 46.0
#define YSTART 30.0;
#define XSTARTSPEED 0
#define YSTARTSPEED 0
BALL ball;
ball.resetBall=0;
ball.x=XSTART;
ball.y=YSTART;
ball.Speedx=XSTARTSPEED ;
ball.Speedy=YSTARTSPEED;
ball.SIMx=XSTART;
ball.SIMy=YSTART;
ball.SIMSpeedx=XSTARTSPEED ;
ball.SIMSpeedy=YSTARTSPEED ;

while(1){
ESP.wdtFeed();  
BallupDate_TPINBALL(&ball);

while((currentMillis-MemMillis)<Frame_Rate_TPINBALL){
currentMillis=millis();
}
MemMillis=currentMillis;
Tiny_Flip2_TPINBALL(&ball);My_delay_ms(3);if (SCANLINE<1) {SCANLINE++;}else{SCANLINE=0;}
if (ball.x<.5) {falseBall_TPINBALL();FIRSTTIME=1;goto start;}
if ((ball.y>=29)&&(ball.x>=18)) {if ((TINYJOYPAD_DOWN==0)||(BUTTON_DOWN)) {if (SpringBar>54) {SpringBar=SpringBar-2;}}else{if ((SpringBar>SPRINGLONG-10)&&(SpringBar<SPRINGLONG)) {SpringBar=SPRINGLONG;} if (SpringBar<SPRINGLONG) {SpringBar=SpringBar+8;}}}else{SpringBar=SPRINGLONG;}
if (TINYJOYPAD_UP==0) {if (trigFlipG<3) {trigFlipG++;}}else{if (trigFlipG>0) {trigFlipG--;}}
if ((TINYJOYPAD_DOWN==0)||(BUTTON_DOWN)) {if (trigFlipD<3) {trigFlipD++;}}else{if (trigFlipD>0) {trigFlipD--;}}
}}
//<<<<<<<<<<<<<<<<<<<MAIN FIN>>>>>>>>>>>>>>>

void falseBall_TPINBALL(void){
uint8_t t;
for (t=50;t>0;t--){
Sound_TPINBALL(t,6);}}

void Sound_TPINBALL(uint8_t freq,uint8_t dur){
ESP.wdtFeed();
for (uint8_t t=0;t<dur;t++){
digitalWrite(PIN_,SOUND_ON_OFF);
for (uint8_t t=0;t<(255-freq);t++){
My_delay_us(1);}
digitalWrite(PIN_,LOW);
for (uint8_t t=0;t<(255-freq);t++){
My_delay_us(1); }
}}

void BallupDate_TPINBALL(BALL *B){
SimulateMove(B);
if (ColisionCheck_TPINBALL(B->SIMx,B->SIMy,B)) {
CheckColisionType_TPINBALL(B);
if ((B->y<7)||(B->y>24)||(B->x<31)||(B->x>48)){
WriteMove_TPINBALL(B);
if (B->y<29) {Sound_TPINBALL(1,6);}
}else{
WriteMoveBounce_TPINBALL(B);
bouncePush=256;
if (totalpush<7) {totalpush++;}else{
 if (totalBall<4) {totalBall++;}
 totalpush=0;
for(uint8_t ttt=60;ttt<240;ttt=ttt+20){Sound_TPINBALL(ttt,6);}
}}
if ((B->SIMSpeedy>=0.15)) {B->SIMSpeedy=(B->SIMSpeedy-.1);} 
if ((B->SIMSpeedy<=-0.15)) {B->SIMSpeedy=(B->SIMSpeedy+.1);}
}else{WriteMove_TPINBALL(B);}
if ((B->y>29)&&(B->x>22)) {B->y=30;}
if ((round(B->x)>=49)&&(round(B->y)==30)) {
B->x=50; 
B->y=29; 
B->Speedx=0.8-(random(10.0)/100.0);  
B->Speedy=-1.0+(random(30.0)/100.0);  
}}

uint8_t SelectByte_TPINBALL(uint8_t ByteSelect,uint8_t FFx0){
uint8_t ByteRecup=0;
switch (ByteSelect){
  case(0):ByteRecup=0b10000000;break;
  case(1):ByteRecup=0b01000000;break;
  case(2):ByteRecup=0b00100000;break;
  case(3):ByteRecup=0b00010000;break;
  case(4):ByteRecup=0b00001000;break;
  case(5):ByteRecup=0b00000100;break;
  case(6):ByteRecup=0b00000010;break;
  case(7):ByteRecup=0b00000001;break;
  default:ByteRecup=0;break;
}
if ((ByteRecup&FFx0)!=0b00000000) {return 1;}else{return 0;}
}


void TrimXY(BALL *B){
if (B->Speedx>1) B->Speedx=1;
if (B->Speedx<-1) B->Speedx=-1;
if (B->Speedy>1) B->Speedy=1;
if (B->Speedy<-1) B->Speedy=-1;}

void SimulateRebounce_TPINBALL(uint8_t Sim,BALL *B){
B->SIMx=B->x;
B->SIMy=B->y;
switch(Sim){
  case (0):B->SIMSpeedx=B->Speedx;B->SIMSpeedy=B->Speedy;break;
  case (1):B->SIMSpeedx=-B->Speedx;B->SIMSpeedy=B->Speedy;break;
  case (2):B->SIMSpeedx=B->Speedx;B->SIMSpeedy=-B->Speedy;break;
  case (3):B->SIMSpeedx=-B->Speedx;B->SIMSpeedy=-B->Speedy;break;
  case (4):B->SIMSpeedx=-B->Speedy;B->SIMSpeedy=-B->Speedx;break;
  case (5):B->SIMx=B->x+1;B->SIMy=B->y;B->SIMSpeedx=-0.2;B->SIMSpeedy=0.2;break;
  case (6):B->SIMx=B->x+1;B->SIMy=B->y;B->SIMSpeedx=-0.2;B->SIMSpeedy=-0.2;break;
  default:break;}}

uint8_t CheckColisionType_TPINBALL(BALL *B){
TrimXY(B);
B->SIMx=B->x;
B->SIMy=B->y;
B->SIMSpeedx=B->Speedx;
B->SIMSpeedy=B->Speedy;
if ((B->SIMy==30)&&(B->SIMx<=(79-32))){ 
if (!ColisionCheck_TPINBALL(B->SIMx,B->SIMy,B)){
SimulateMove(B);
return 0;}else{
TrimBallOnSpring_TPINBALL(B);
if (B->SIMSpeedx<=0) {B->SIMSpeedx=-B->SIMSpeedx;}
SimulateMove(B);
return 0;}}
uint8_t sim=0;
while(1){                       
SimulateRebounce_TPINBALL(sim,B);          
SimulateMove(B);
if (!ColisionCheck_TPINBALL(B->SIMx,B->SIMy,B)) {return 0;}
sim++;if (sim==7) {sim=0;}
}}

void TrimBallOnSpring_TPINBALL(BALL *B){
uint8_t counter=0;
if ((B->SIMx+32)<(SpringBar-1)) {
DAS:
if ((B->SIMx+32)<(SpringBar-1)) { B->SIMx++;counter++;goto DAS;}
if (counter>4) {
B->SIMSpeedx=2;
}}}

void WriteMove_TPINBALL(BALL *B){ 
B->x=B->SIMx;
B->y=B->SIMy;
B->Speedx=B->SIMSpeedx;
B->Speedy=B->SIMSpeedy;}

void WriteMoveBounce_TPINBALL(BALL *B){ 
B->x=B->SIMx;
B->y=B->SIMy;
B->SIMSpeedx=B->SIMSpeedx*8;
B->SIMSpeedy=B->SIMSpeedy*8;
if (B->SIMSpeedx>1.4) B->SIMSpeedx=1.4;
if (B->SIMSpeedx<-1.4) B->SIMSpeedx=-1.4;
if (B->SIMSpeedy>1.4) B->SIMSpeedy=1.4;
if (B->SIMSpeedy<-1.4) B->SIMSpeedy=-1.4;
B->Speedx=B->SIMSpeedx;
B->Speedy=B->SIMSpeedy;}

void SimulateMove(BALL *B){
TrimXY(B);
if (B->SIMx>=0) {
if ((B->SIMSpeedx>-1)) {if (B->SIMSpeedx-0.05>-1) {B->SIMSpeedx=B->SIMSpeedx-0.05;}}
B->SIMx=B->SIMx+B->SIMSpeedx;}else{B->resetBall=1;}
B->SIMy=B->SIMy+B->SIMSpeedy;}

uint8_t ColisionCheck_TPINBALL(float x,float y,BALL *B){
TrimXY(B);
uint16_t serialcount=0;
uint8_t X=round(x);
uint8_t Y=round(y);
uint8_t verticalStrip=((Y)/8); //0 to 3
serialcount=((verticalStrip*64)+X);
#define BACK (pgm_read_byte(&start_TPINBALL[serialcount])&PixelAsign_TPINBALL(Y))!=0b00000000)
if ((X>=4)&&(X<=9)&&(Y>=11)&&(Y<=14)){
if (trigFlipG==0) {
if ((((pgm_read_byte(&FLIPGAUCHE_TPINBALL[(X-4)+(trigFlipG*6)]))&(PixelAsign_TPINBALL(Y)))!=0b00000000)||(BACK) {return 1;}else{return 0;} 
}else if ((((pgm_read_byte(&FLIPDETGAUCHE_TPINBALL[(X-4)]))&(PixelAsign_TPINBALL(Y)))!=0b00000000)||(BACK){if (trigFlipG!=3) {B->SIMSpeedx=2;
Sound_TPINBALL(20,12);
}else{B->SIMSpeedx=1;Sound_TPINBALL(1,6);}return 0;}
} else if ((X>=4)&&(X<=9)&&(Y>=17)&&(Y<=20)){
if (trigFlipD==0) {
if ((((pgm_read_byte(&FLIPDROITE_TPINBALL[(X-4)+(trigFlipD*6)]))&(PixelAsign_TPINBALL(Y)))!=0b00000000)||(BACK) {return 1;}else{return 0;} 
}else if ((((pgm_read_byte(&FLIPDETDROIT_TPINBALL[(X-4)]))&(PixelAsign_TPINBALL(Y)))!=0b00000000)||(BACK){if (trigFlipD!=3) {B->SIMSpeedx=2;
Sound_TPINBALL(20,12);
}else{B->SIMSpeedx=1;Sound_TPINBALL(1,6);}return 0;}
}else{
if (((X+32)<(SpringBar))&&(B->y==30)) {return 1;}
if ((pgm_read_byte(&start_TPINBALL[serialcount])&PixelAsign_TPINBALL(Y))!=0b00000000) {return 1;}
return 0;}return 0x00;}

uint8_t RecupeScreen_TPINBALL(uint8_t nn,uint8_t mm){
uint8_t ScreenCount=nn-90;  
switch(mm){
case(4): return pgm_read_byte(&ScreenBallA_TPINBALL[ScreenCount+(totalBall*6)]);break;
case(5): return pgm_read_byte(&ScreenBallB_TPINBALL[ScreenCount+(totalBall*6)]);break;
case(6): return pgm_read_byte(&PusherA_TPINBALL[ScreenCount+(totalpush*6)]);break;
case(7): return pgm_read_byte(&PusherB_TPINBALL[ScreenCount+(totalpush*6)]);break;
}return 0x00;}

////////////////////////////////SCREEN FLIP PROCEDURE/////////////////////////////////////////////


uint8_t addBin_TPINBALL(uint8_t a,uint8_t b,uint8_t c,uint8_t d){
return a|b|c|d;}

uint8_t RecupeByte_TPINBALL(uint8_t x,uint8_t y){
return pgm_read_byte(&start_TPINBALL [((x-32)+(((y)-4)*64))+bouncePush]);}

uint8_t RecupeFlip_TPINBALL(uint8_t x,uint8_t y){
uint8_t TRIGG=0;
uint8_t TRIDD=0;
if (trigFlipG>2) {TRIGG=2;}else{TRIGG=trigFlipG;}
if (trigFlipD>2) {TRIDD=2;}else{TRIDD=trigFlipD;}
if ((y==5)&&(x>35&&x<42)){
return pgm_read_byte(&FLIPGAUCHE_TPINBALL[(x-36)+(TRIGG*6)]);
}else if ((y==6)&&(x>35&&x<42)) {
return pgm_read_byte(&FLIPDROITE_TPINBALL[(x-36)+(TRIDD*6)]);}else{
return 0x00;}}

uint8_t RecupeSpring_TPINBALL(uint8_t x,uint8_t y){
if (((y==7)&&(x>53&&x<SpringBar))){
return 0b01000000;}else{
return 0x00;}
}

uint8_t PixelAsign_TPINBALL(uint8_t Value){
while(Value>=8){
Value=Value-8;}
switch(Value){
case  (0):return 0b00000001;break;
case  (1):return 0b00000010;break;
case  (2):return 0b00000100;break;
case  (3):return 0b00001000;break;
case  (4):return 0b00010000;break;
case  (5):return 0b00100000;break;
case  (6):return 0b01000000;break;
case  (7):return 0b10000000;break;
default:return 0x00;break;
}}

uint8_t PixelConvert_TPINBALL(uint8_t horiz,uint8_t verti,BALL *B){
uint8_t ballx (round(B->x)+32);
uint8_t bally (round(B->y)+32);
if ((horiz>31)&&(horiz<97)&&(verti>3)) {
if ((trunc((bally)/8)==verti)&&(ballx==horiz)) {return PixelAsign_TPINBALL(bally);}else{return 0x00;}
}else{return 0x00;}}

uint8_t SliceByte_TPINBALL(uint8_t Vertical,uint8_t Byte){
uint8_t toto=0;
 if ((Vertical%2)!=0)  {
 if ((Byte&0b10000000)!=0) {toto=toto|0b11000000;}
 if ((Byte&0b01000000)!=0) {toto=toto|0b00110000;}
 if ((Byte&0b00100000)!=0) {toto=toto|0b00001100;}
 if ((Byte&0b00010000)!=0) {toto=toto|0b00000011;}
 } else {
 if ((Byte&0b00001000)!=0) {toto=toto|0b11000000;}
 if ((Byte&0b00000100)!=0) {toto=toto|0b00110000;}
 if ((Byte&0b00000010)!=0) {toto=toto|0b00001100;}
 if ((Byte&0b00000001)!=0) {toto=toto|0b00000011;}
  }return toto;}

uint16_t Pos_1024_TPINBALL=0;
#define POS_1024_TPINBALL RETURN_1024_POS_TPINBALL ()

uint16_t RETURN_1024_POS_TPINBALL(void){
if (Pos_1024_TPINBALL<1024) {Pos_1024_TPINBALL++;}
return  (Pos_1024_TPINBALL-1); 
}





void Tiny_Flip2_TPINBALL(BALL *B){
  Pos_1024_TPINBALL=0;  
uint8_t m,x,y,n,mem;
for (y = 0; y <= 7; y++){  
m=(trunc(y/2))+4;
for (x = 0; x < 64; x++){
n=(x)+32;
if ((n<90)) {
mem=SliceByte_TPINBALL(y,addBin_TPINBALL(PixelConvert_TPINBALL(n,m,B),RecupeByte_TPINBALL(n,m),RecupeFlip_TPINBALL(n,m),RecupeSpring_TPINBALL(n,m)));
display.buffer[POS_1024_TPINBALL] =(mem);
display.buffer[POS_1024_TPINBALL] =(mem);
   }else{    
mem=SliceByte_TPINBALL(y,RecupeScreen_TPINBALL(n,m));
display.buffer[POS_1024_TPINBALL] =(mem);
display.buffer[POS_1024_TPINBALL] =(mem);

}}}
if (bouncePush==256) {
frameCount++;
if (frameCount>1) {
Sound_TPINBALL(1,20);Sound_TPINBALL(20,20);Sound_TPINBALL(1,20);
bouncePush=0;frameCount=0;}}
FIRSTTIME=0;
MURDGE_LOW_AND_HIGH_RES_TPINBALL();
display.display(); 
}

void MURDGE_LOW_AND_HIGH_RES_TPINBALL(void){
for (uint16_t R=0;R<1024;R++){
display.buffer[R]=display.buffer[R]|pgm_read_byte(&plateauHD1_TPINBALL[R]);
}
}


