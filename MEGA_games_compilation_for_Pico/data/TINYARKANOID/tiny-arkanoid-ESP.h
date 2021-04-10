//     >>>>>  MEGA COMPILATION for ESP8266/ESP8285  GPL v3 <<<<
//                    >>>>>  MEGA Tiny Joypad  <<<<
//                    Programmer: Daniel C 2019
//              Contact EMAIL: electro_l.i.b@tinyjoypad.com
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


#include "spritebank_TARKANOID.h"

#define Frame_Rate_TARKANOID 0

void RsVarNewGame_TARKANOID(GROUPE_TARKANOID *VAR);
void ResetBall_TARKANOID(GROUPE_TARKANOID *VAR);
void ResetVar_TARKANOID(GROUPE_TARKANOID *VAR);
void LoadLevel_TARKANOID(uint8_t Level,GROUPE_TARKANOID *VAR);
void Sound_TARKANOID(uint8_t freq,uint8_t dur);
uint8_t PannelLive_TARKANOID(uint8_t X,uint8_t Y,GROUPE_TARKANOID *VAR);
uint8_t TrackBar_TARKANOID(uint8_t X,uint8_t Y,GROUPE_TARKANOID *VAR);
uint8_t SplitSpriteDecalageY_TARKANOID(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN);
uint8_t Ball_TARKANOID(uint8_t X,uint8_t Y,GROUPE_TARKANOID *VAR);
uint8_t RecupeDecalageY_TARKANOID(uint8_t Valeur);
uint8_t Block_TARKANOID(uint8_t X,uint8_t Y,GROUPE_TARKANOID *VAR);
uint8_t PannelLevel_TARKANOID(uint8_t X,uint8_t Y,GROUPE_TARKANOID *VAR);
void Tiny_Flip_TARKANOID(uint8_t render0_picture1,GROUPE_TARKANOID *VAR);
void WriteBallMove_TARKANOID(GROUPE_TARKANOID *VAR);
uint8_t CheckCollisionWithTRACKBAR_TARKANOID(GROUPE_TARKANOID *VAR);
uint8_t RecupeYPositionOnGrid_TARKANOID(GROUPE_TARKANOID *VAR);
uint8_t RecupeXPositionOnGrid_TARKANOID(GROUPE_TARKANOID *VAR);
void RecupePositionOnGrid_TARKANOID(GROUPE_TARKANOID *VAR);
uint8_t CheckCollisionWithBLOCK_TARKANOID(GROUPE_TARKANOID *VAR);
uint8_t CheckCollisionBall_TARKANOID(GROUPE_TARKANOID *VAR);
void SimulMove_TARKANOID(uint8_t Sim,GROUPE_TARKANOID *VAR);
void TestMoveBALL_TARKANOID(GROUPE_TARKANOID *VAR);
void RecupeBALLPosForSIM_TARKANOID(GROUPE_TARKANOID *VAR);
void UpdateBall_TARKANOID(GROUPE_TARKANOID *VAR);
uint8_t CheckLevelEnded_TARKANOID(GROUPE_TARKANOID *VAR);
uint8_t BallMissing_TARKANOID(GROUPE_TARKANOID *VAR);
void PLAYMUSIC_TARKANOID(void);
uint8_t background_TARKANOID(uint8_t X,uint8_t Y);


void RsVarNewGame_TARKANOID(GROUPE_TARKANOID *VAR){
VAR->LEVELSPEED=16;
VAR->LEVEL=1;
VAR->live=3;
VAR->ANIMREFLECT=0;
LoadLevel_TARKANOID(0,VAR);
}

void loop_TARKANOID() {
ESP.wdtDisable();

GROUPE_TARKANOID VARIABLE_TARKANOID;
NEWGAME:;
Tiny_Flip_TARKANOID(1,&VARIABLE_TARKANOID);
while(1){
ESP.wdtFeed();
if (BUTTON_DOWN) {break;}}
RsVarNewGame_TARKANOID(&VARIABLE_TARKANOID);
Tiny_Flip_TARKANOID(2,&VARIABLE_TARKANOID);
PLAYMUSIC_TARKANOID();
LoadLevel_TARKANOID(VARIABLE_TARKANOID.LEVEL-1,&VARIABLE_TARKANOID);
goto ONE;
NEXTLEVEL:;
Sound_TARKANOID(60,100);
Sound_TARKANOID(80,100);
Sound_TARKANOID(100,100);
Sound_TARKANOID(120,100);
Sound_TARKANOID(140,100);
if (VARIABLE_TARKANOID.LEVELSPEED>8) {VARIABLE_TARKANOID.LEVELSPEED=VARIABLE_TARKANOID.LEVELSPEED-2;}
Tiny_Flip_TARKANOID(2,&VARIABLE_TARKANOID);
My_delay_ms(400);
ResetVar_TARKANOID(&VARIABLE_TARKANOID);
VARIABLE_TARKANOID.LEVEL++;
goto ONE;
RESTARTLEVEL:;
Sound_TARKANOID(200,100);
Sound_TARKANOID(150,100);
Sound_TARKANOID(100,100);
Sound_TARKANOID(50,100);
if (VARIABLE_TARKANOID.live>0) {VARIABLE_TARKANOID.live--;}else{goto NEWGAME;}
ONE:;
ResetBall_TARKANOID(&VARIABLE_TARKANOID);
while(1){
ESP.wdtFeed();
if (VARIABLE_TARKANOID.Frame%8==0) {
if (TINYJOYPAD_DOWN==0) {if (VARIABLE_TARKANOID.TrackBaryDecal<7) {if (VARIABLE_TARKANOID.TrackBaryDecal+(VARIABLE_TARKANOID.TrackBary*8)<44){ VARIABLE_TARKANOID.TrackBaryDecal++;}}else{VARIABLE_TARKANOID.TrackBaryDecal=0;VARIABLE_TARKANOID.TrackBary++;}}
if (TINYJOYPAD_UP==0) {if (VARIABLE_TARKANOID.TrackBaryDecal>0) {if (VARIABLE_TARKANOID.TrackBaryDecal+(VARIABLE_TARKANOID.TrackBary*8)>4){ VARIABLE_TARKANOID.TrackBaryDecal--;}}else{VARIABLE_TARKANOID.TrackBaryDecal=7;VARIABLE_TARKANOID.TrackBary--;}}
if ((VARIABLE_TARKANOID.launch==0)&&(BUTTON_DOWN)) {VARIABLE_TARKANOID.launch=1;}
if (VARIABLE_TARKANOID.launch==0) {VARIABLE_TARKANOID.Ballypos=((VARIABLE_TARKANOID.TrackBary*8)+VARIABLE_TARKANOID.TrackBaryDecal)+10;VARIABLE_TARKANOID.SIMBallypos=VARIABLE_TARKANOID.Ballypos;}
}
if ((VARIABLE_TARKANOID.Frame%VARIABLE_TARKANOID.LEVELSPEED==0)) {UpdateBall_TARKANOID(&VARIABLE_TARKANOID);}
if (VARIABLE_TARKANOID.Frame%32==0) {
  while((currentMillis-MemMillis)<Frame_Rate_TARKANOID){
currentMillis=millis();
}
MemMillis=currentMillis;
  Tiny_Flip_TARKANOID(0,&VARIABLE_TARKANOID);}



if (VARIABLE_TARKANOID.Frame==48) {
if (VARIABLE_TARKANOID.ANIMREFLECT<3) {VARIABLE_TARKANOID.ANIMREFLECT++;}
if (BallMissing_TARKANOID(&VARIABLE_TARKANOID)) {goto RESTARTLEVEL;}
if (CheckLevelEnded_TARKANOID(&VARIABLE_TARKANOID)) {goto NEXTLEVEL;}
}
if (VARIABLE_TARKANOID.Frame<64) {VARIABLE_TARKANOID.Frame++;}else{VARIABLE_TARKANOID.Frame=1;}

}
}
////////////////////////////////// main end /////////////////////////////////

void PLAYMUSIC_TARKANOID(void){
for (uint8_t t=0;t<92;t=t+2){
Sound_TARKANOID((pgm_read_byte(&Music1_TARKANOID[t])==0)?0:pgm_read_byte(&Music1_TARKANOID[t])-20,(pgm_read_byte(&Music1_TARKANOID[t+1])-100));
}}

uint8_t BallMissing_TARKANOID(GROUPE_TARKANOID *VAR){
if (VAR->Ballxpos<0) {return 1;}
return 0; 
}

uint8_t CheckLevelEnded_TARKANOID(GROUPE_TARKANOID *VAR){
uint8_t h,v,res=1;
for(v=0;v<5;v++){
for(h=0;h<6;h++){
if ((VAR->BlocsGrid[h][v]!=255)&&(VAR->BlocsGrid[h][v]!=5)) {res=0;}
}}
return res;
}

void UpdateBall_TARKANOID(GROUPE_TARKANOID *VAR){
VAR->TrackAngleOut=0;
for (uint8_t T1=0;T1<=6;T1++) {
RecupeBALLPosForSIM_TARKANOID(VAR);
if (VAR->launch==0) goto FIN;
SimulMove_TARKANOID(T1,VAR);
TestMoveBALL_TARKANOID(VAR);
if (CheckCollisionBall_TARKANOID(VAR)==0) {goto FIN;}
}
FIN:;
WriteBallMove_TARKANOID(VAR);
}

void RecupeBALLPosForSIM_TARKANOID(GROUPE_TARKANOID *VAR){
VAR->SIMBallxpos=VAR->Ballxpos;
VAR->SIMBallypos=VAR->Ballypos;
VAR->SIMBallSpeedx=VAR->BallSpeedx;
VAR->SIMBallSpeedy=VAR->BallSpeedy;
}

void TestMoveBALL_TARKANOID(GROUPE_TARKANOID *VAR){
VAR->SIMBallxpos=VAR->SIMBallxpos+VAR->SIMBallSpeedx;
VAR->SIMBallypos=VAR->SIMBallypos+VAR->SIMBallSpeedy;
}

void SimulMove_TARKANOID(uint8_t Sim,GROUPE_TARKANOID *VAR){
switch(Sim){
  case (0):VAR->SIMBallSpeedx=VAR->BallSpeedx;VAR->SIMBallSpeedy=VAR->BallSpeedy;break;
  case (1):VAR->SIMBallSpeedx=-VAR->BallSpeedx;VAR->SIMBallSpeedy=VAR->BallSpeedy;break;
  case (2):VAR->SIMBallSpeedx=VAR->BallSpeedx;VAR->SIMBallSpeedy=-VAR->BallSpeedy;break;
  case (3):VAR->SIMBallSpeedx=-VAR->BallSpeedx;VAR->SIMBallSpeedy=-VAR->BallSpeedy;break;
  case (4):VAR->SIMBallSpeedx=-VAR->BallSpeedy;VAR->SIMBallSpeedy=-VAR->BallSpeedx;break;
  case (5):VAR->SIMBallxpos=VAR->Ballxpos+1;VAR->SIMBallypos=VAR->Ballypos;VAR->SIMBallSpeedx=-1;VAR->SIMBallSpeedy=1;break;
  case (6):VAR->SIMBallxpos=VAR->Ballxpos+1;VAR->SIMBallypos=VAR->Ballypos;VAR->SIMBallSpeedx=-1;VAR->SIMBallSpeedy=-1;break;
  default:break;
}}

uint8_t CheckCollisionBall_TARKANOID(GROUPE_TARKANOID *VAR){
if (VAR->SIMBallxpos>106) {return 1;}
if (VAR->SIMBallypos>59) {return 1;}
if (VAR->SIMBallypos<4) {return 1;}
if (CheckCollisionWithTRACKBAR_TARKANOID(VAR)) {Sound_TARKANOID(60,10);return 1;}
if (CheckCollisionWithBLOCK_TARKANOID(VAR)) {return 1;}
return 0;
}

uint8_t CheckCollisionWithBLOCK_TARKANOID(GROUPE_TARKANOID *VAR){
RecupePositionOnGrid_TARKANOID(VAR);
if ((VAR->Px==255)||(VAR->Py==255)) {return 0;}
if (VAR->BlocsGrid[VAR->Py][VAR->Px]==5) {Sound_TARKANOID(210,50);VAR->ANIMREFLECT=0;return 1;}
if (VAR->BlocsGrid[VAR->Py][VAR->Px]==255) {return 0;}
Sound_TARKANOID(150,10);
VAR->BlocsGrid[VAR->Py][VAR->Px]=255;
return 1;
}

void RecupePositionOnGrid_TARKANOID(GROUPE_TARKANOID *VAR){
VAR->Px=RecupeXPositionOnGrid_TARKANOID(VAR);
VAR->Py=RecupeYPositionOnGrid_TARKANOID(VAR);
}

uint8_t RecupeXPositionOnGrid_TARKANOID(GROUPE_TARKANOID *VAR){
if ((VAR->SIMBallxpos>=66)&&(VAR->SIMBallxpos<72))  return 0;
else if ((VAR->SIMBallxpos>=72)&&(VAR->SIMBallxpos<78)) return 1;
else if ((VAR->SIMBallxpos>=78)&&(VAR->SIMBallxpos<84)) return 2;
else if ((VAR->SIMBallxpos>=84)&&(VAR->SIMBallxpos<90))  return 3;
else if ((VAR->SIMBallxpos>=90)&&(VAR->SIMBallxpos<96))  return 4;  
return 255;
}

uint8_t RecupeYPositionOnGrid_TARKANOID(GROUPE_TARKANOID *VAR){
if ((VAR->SIMBallypos>=8)&&(VAR->SIMBallypos<16)) return 0;
else if ((VAR->SIMBallypos>=16)&&(VAR->SIMBallypos<23))  return 1;
else if ((VAR->SIMBallypos>=23)&&(VAR->SIMBallypos<31))  return 2;
else if ((VAR->SIMBallypos>=31)&&(VAR->SIMBallypos<40))  return 3;
else if ((VAR->SIMBallypos>=40)&&(VAR->SIMBallypos<48))  return 4; 
else if ((VAR->SIMBallypos>=48)&&(VAR->SIMBallypos<55))  return 5;   
return 255;
}

uint8_t CheckCollisionWithTRACKBAR_TARKANOID(GROUPE_TARKANOID *VAR){
uint8_t TRACK=(VAR->TrackBary*8)+VAR->TrackBaryDecal;
if ((VAR->SIMBallxpos>6)||(VAR->SIMBallxpos<5)) {return 0;}
if (TRACK>VAR->SIMBallypos) {return 0;}
if ((TRACK+16)<VAR->SIMBallypos) {return 0;}
VAR->TrackAngleOut=(((VAR->SIMBallypos-TRACK)*200)/16)-100;
return 1;
}

void WriteBallMove_TARKANOID(GROUPE_TARKANOID *VAR){
float CORECTIONY=(VAR->SIMBallSpeedy)+(VAR->TrackAngleOut/100.00);
if (CORECTIONY<-1) {CORECTIONY=-1;}
if (CORECTIONY>1) {CORECTIONY=1;}
VAR->Ballxpos=VAR->SIMBallxpos;
VAR->Ballypos=VAR->SIMBallypos;
VAR->BallSpeedx=VAR->SIMBallSpeedx;
VAR->BallSpeedy=CORECTIONY;
VAR->BALLyDecal=RecupeDecalageY_TARKANOID(VAR->Ballypos-1);
VAR->Ypos=((VAR->Ballypos-1)/8);
}

void Tiny_Flip_TARKANOID(uint8_t render0_picture1,GROUPE_TARKANOID *VAR){
uint8_t y,x; 
for (y = 0; y < 8; y++){ 
for (x = 0; x < 128; x++){
if (render0_picture1==0) {
display.buffer[x+(y*128)] =(Block_TARKANOID(x,y,VAR)|Ball_TARKANOID(x,y,VAR)|TrackBar_TARKANOID(x,y,VAR)|background_TARKANOID(x,y)|PannelLive_TARKANOID(x,y,VAR)|PannelLevel_TARKANOID(x,y,VAR));
}else if (render0_picture1==1) {
display.buffer[x+(y*128)] =(pgm_read_byte(&MAIN_TARKANOID[x+(y*128)]));
}else if (render0_picture1==2) {
display.buffer[x+(y*128)] =(background_TARKANOID(x,y));
}}

}
display.display(); 
}

uint8_t PannelLevel_TARKANOID(uint8_t X,uint8_t Y,GROUPE_TARKANOID *VAR){
if ((Y<5)||(Y>6)||(X<117)||(X>123)) return 0x00;
#define VAl10 (VAR->LEVEL/10)
#define VAl01 (VAR->LEVEL-(VAl10*10))
if (Y==5) {return (pgm_read_byte(&DIGITAL_TARKANOID[(X-117)+(VAl10*7)]));}
else if (Y==6) {return (pgm_read_byte(&DIGITAL_TARKANOID[(X-117)+(VAl01*7)]));}
return 0x00;
}

uint8_t Block_TARKANOID(uint8_t X,uint8_t Y,GROUPE_TARKANOID *VAR){
uint8_t XValue=255;
if ((X>=67)&&(X<97)&&(Y>=1)&&(Y<=6)) {
if ((X>=67)&&(X<73)) XValue=0;
else if ((X>=73)&&(X<79)) XValue=1;
else if ((X>=79)&&(X<85)) XValue=2;
else if ((X>=85)&&(X<91)) XValue=3;
else if ((X>=91)&&(X<97)) XValue=4;
if (XValue==255) return 0x00;
//uint8_t XValue=((X-67)/6);
if (VAR->BlocsGrid[(Y-1)][XValue]==255) return 0x00;
if (VAR->BlocsGrid[(Y-1)][XValue]==5) {return pgm_read_byte(&BLOCKREFLECT_TARKANOID[((X-67)-(XValue*6))+(VAR->ANIMREFLECT*6)])|pgm_read_byte(&BLOCK_TARKANOID[((X-67)-(XValue*6))+((VAR->BlocsGrid[(Y-1)][XValue])*6)]);}
return pgm_read_byte(&BLOCK_TARKANOID[((X-67)-(XValue*6))+((VAR->BlocsGrid[(Y-1)][XValue])*6)]);
}return 0x00;}

uint8_t RecupeDecalageY_TARKANOID(uint8_t Valeur){
while(Valeur>7){Valeur=Valeur-8;}
return Valeur;
}

uint8_t Ball_TARKANOID(uint8_t X,uint8_t Y,GROUPE_TARKANOID *VAR){
#define BALLXPOS (VAR->Ballxpos-1)
#define BALLYPOS (VAR->Ballypos-1)
 if (Y<VAR->Ypos) return 0x00;
 if (Y>(VAR->Ypos+1)) return 0x00;
 if ((X-uint8_t(BALLXPOS))<0) return 0x00;
 if (X<BALLXPOS) return 0x00;
 if (X>BALLXPOS+2) return 0x00;
if (VAR->BALLyDecal==0)  {
if (Y==VAR->Ypos ) {return (pgm_read_byte(&BALL_TARKANOID[(X-uint8_t(BALLXPOS))]));}
  }else{
uint8_t DECAL=RecupeDecalageY_TARKANOID(BALLYPOS);
if (Y==VAR->Ypos) { return SplitSpriteDecalageY_TARKANOID(DECAL,pgm_read_byte(&BALL_TARKANOID[(X-uint8_t(BALLXPOS))]),1);}
if (Y==(VAR->Ypos)+1) { return SplitSpriteDecalageY_TARKANOID(DECAL,pgm_read_byte(&BALL_TARKANOID[(X-uint8_t(BALLXPOS))]),0);}
}return 0x00;}

uint8_t SplitSpriteDecalageY_TARKANOID(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN){
if (UPorDOWN) {
return Input<<decalage;
}else{
return Input>>(8-decalage); 
}}

uint8_t TrackBar_TARKANOID(uint8_t X,uint8_t Y,GROUPE_TARKANOID *VAR){
if (X>6) return 0;
if (X<3) return 0;
if (Y>=(3+VAR->TrackBary)) return 0;
if (Y<(VAR->TrackBary)) return 0;
if (VAR->TrackBaryDecal==0){if (Y!=VAR->TrackBary+2){ return (pgm_read_byte(&TRACKBAR_TARKANOID[(X-3)+((Y-VAR->TrackBary)*4)]));
}}else{
if (Y==VAR->TrackBary) {return SplitSpriteDecalageY_TARKANOID(VAR->TrackBaryDecal,pgm_read_byte(&TRACKBAR_TARKANOID[(X-3)]),1);}
else if (Y==VAR->TrackBary+1) {return SplitSpriteDecalageY_TARKANOID(VAR->TrackBaryDecal,pgm_read_byte(&TRACKBAR_TARKANOID[(X-3)]),0)|SplitSpriteDecalageY_TARKANOID(VAR->TrackBaryDecal,pgm_read_byte(&TRACKBAR_TARKANOID[(X-3)+4]),1);}
else if ((Y==VAR->TrackBary+2)&&(VAR->TrackBaryDecal!=0)) {return SplitSpriteDecalageY_TARKANOID(VAR->TrackBaryDecal,pgm_read_byte(&TRACKBAR_TARKANOID[(X-3)+4]),0);}
}return 0x00;}

uint8_t PannelLive_TARKANOID(uint8_t X,uint8_t Y,GROUPE_TARKANOID *VAR){
if ((Y<1)||(Y>VAR->live)||(X>121)||(X<119)) return 0x00;
return (pgm_read_byte(&LIVE_TARKANOID[X-119]));}

uint8_t SWIFT_TEXTURE=0;
uint8_t background_TARKANOID(uint8_t X,uint8_t Y){ 
if (X==0) SWIFT_TEXTURE=0;
if (X<=105){
if (SWIFT_TEXTURE<14) {SWIFT_TEXTURE++;}else{SWIFT_TEXTURE=0;}
switch(Y){
  case 0:return (pgm_read_byte(&back_UP_TARKANOID[X]));break;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:return pgm_read_byte(&texture_TARKANOID[SWIFT_TEXTURE]);break;
  case 7:return pgm_read_byte(&back_DOWN_TARKANOID[X]);break;
  default:break;  
}

}else{
return (pgm_read_byte(&back_RIGHT_TARKANOID[(X-106)+(Y*22)]));    
    }
return 0x00;
}

void Sound_TARKANOID(uint8_t freq,uint8_t dur){
ESP.wdtFeed();
if (freq==0) {My_delay_ms(dur);goto END;}
for (uint8_t t=0;t<dur;t++){
if (freq!=0)digitalWrite(PIN_,SOUND_ON_OFF);
for (uint8_t t=0;t<(255-freq);t++){
My_delay_us(1);}
digitalWrite(PIN_,LOW);
for (uint8_t t=0;t<(255-freq);t++){
My_delay_us(1); }}
END:;
}

void LoadLevel_TARKANOID(uint8_t Level,GROUPE_TARKANOID *VAR){
uint8_t a,b;
for(b=0;b<5;b++){
for(a=0;a<6;a++){
VAR->BlocsGrid[a][b]=pgm_read_byte(&LEVEL_TARKANOID[(Level*30)+b+(a*5)]);
}}}

void ResetVar_TARKANOID(GROUPE_TARKANOID *VAR){
uint8_t f=VAR->LEVEL;
while(1){if (f>4) {f=f-5;}else{break;}}
LoadLevel_TARKANOID(f,VAR);
VAR->launch=0;}

void ResetBall_TARKANOID(GROUPE_TARKANOID *VAR){
VAR->ANIMREFLECT=0;
VAR->TrackBary=2;
VAR->TrackBaryDecal=4;
VAR->Ballxpos=8;
VAR->SIMBallxpos=8;
VAR->Ballypos=32;
VAR->SIMBallypos=32;
VAR->BallSpeedx=1;
VAR->SIMBallSpeedx=1;
if (VAR->Frame>32) {
VAR->BallSpeedy=.41;
VAR->SIMBallSpeedy=.41;
}else{
VAR->BallSpeedy=.47;
VAR->SIMBallSpeedy=.47;  
}
VAR->launch=0;
}



