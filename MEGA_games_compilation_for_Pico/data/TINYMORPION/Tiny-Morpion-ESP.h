//        >>>>>  T-I-N-Y  M-O-R-P-I-O-N for ATTINY85  GPL v3 <<<<<
//                    Programmer: Daniel C 2020
//             Contact EMAIL: electro_l.i.b@tinyjoypad.com
//                    https://WWW.TINYJOYPAD.COM
//          https://sites.google.com/view/arduino-collection

//  tiny-Morpion is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.

//  You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

//for TINY JOYPAD rev2 (attiny85)
//the code work at 16MHZ internal
//and use ssd1306xled Library for SSD1306 oled display 128x64
//Program chip with arduino uno as isp at 16 mhz internal!

#include "ELECTROLIB.h"
#include "spritebank_TMORPION.h"

//PUBLIC VAR
uint8_t DIVIDE_BY_2=0;
uint8_t BOARD[3][3];
uint8_t Players[2];
uint8_t MyTurn; //0=cpu_PLAY  1=player_PLAY
uint8_t POS_XY[2];
uint8_t WinPLY;
uint8_t WinCPU;
uint8_t ENDGAME;
uint8_t SELECT=1;

//PROTOTYPE
void INIT_M_DATA_TMORPION(void);
void Assigner_x_Main_TMORPION(uint8_t CPU0_PLY1);
void loop_TMORPION();
void SND_BOX_TMORPION(uint8_t SND_);
void CPU_PLAY_TMORPION(void);
uint8_t CPU_REPLICATE_TMORPION(void);
uint8_t CPU_DOUBLE_TMORPION(void);
uint8_t  CPU_CORNER_TMORPION(void);
uint8_t COMPACT_MAP_TMORPION(uint8_t PLAYER_);
uint8_t CPU_MIDDLE_TMORPION(void);
void Check_WIN_TMORPION(uint8_t O_X);
void NULL_GAME_TMORPION(void);
void BLINK_WINNER_TMORPION(void);
uint8_t COMPLETED_PROCEDURE_TMORPION(void);
uint8_t RECUPE_POS_GRID_TMORPION(uint8_t Pos_);
uint8_t CPU_TERMINATION_TMORPION(uint8_t PLYs_);
void CPU_RND_TMORPION(void);
void REFRESH_SCREEN_TMORPION(void);
uint8_t RECUPE_UP_X_BOARD_TMORPION(uint8_t xPASS);
uint8_t RECUPE_MIDDLE_X_BOARD_TMORPION(uint8_t xPASS);
uint8_t RECUPE_DOWN_X_BOARD_TMORPION(uint8_t xPASS);
uint8_t RECUPE_UP_TMORPION(uint8_t xPASS,uint8_t yPASS);
uint8_t RECUPE_MIDDLE_TMORPION(uint8_t xPASS,uint8_t yPASS);
uint8_t RECUPE_DOWN_TMORPION(uint8_t xPASS,uint8_t yPASS);
uint8_t RECUPE_POINTER_TMORPION(uint8_t xPASS,uint8_t yPASS);
uint8_t Display_TMORLPION(uint8_t xPASS,uint8_t yPASS);
uint8_t RECUPE_BACK_TMORPION(uint8_t xPASS,uint8_t yPASS);
uint8_t Recupe_TMORPION(uint8_t xPASS,uint8_t yPASS);
void Tiny_Flip_TMORPION(uint8_t POINTER_,uint8_t START_,uint8_t END_);
uint8_t Recupe_MENU_TMORPION(uint8_t xPASS,uint8_t yPASS);
void Tiny_MENU_TMORPION(uint8_t POINTER_);

uint8_t Mymap_TMORPION(uint8_t x, uint8_t in_min, uint8_t in_max, uint8_t out_min, uint8_t out_max);
uint8_t blitzSprite_TMORPION(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES);
uint8_t SPEED_BLITZ_TMORPION(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES);
uint8_t SplitSpriteDecalageY_TMORPION(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN);
int8_t RecupeLineY_TMORPION(int8_t Valeur);
uint8_t RecupeDecalageY_TMORPION(uint8_t Valeur);
uint8_t Trace_LINE_TMORPION(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t xPASS,uint8_t yPASS);
uint8_t DIRECTION_LINE_TMORPION(uint8_t DESACTIVE_,uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t xPASS,uint8_t yPASS);
uint8_t Return_Full_Byte_TMORPION(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t xPASS,uint8_t yPASS);
void Universal_Swap_TMORPION(uint8_t *A_,uint8_t *B_);
uint8_t RECONSTRUCT_BYTE_TMORPION(uint8_t Min_,uint8_t Max_);
void Sound_TMORPION(uint8_t freq_,uint8_t dur);
void TINYJOYPAD_INIT_TMORPION(void);


void INIT_M_DATA_TMORPION(void){
MyTurn=1;
ENDGAME=0;
WinPLY=0;
WinCPU=0;
POS_XY[0]=1; 
POS_XY[1]=1; 
for (uint8_t y_=0;y_<3;y_++){
for (uint8_t x_=0;x_<3;x_++){
BOARD[y_][x_]=2;
}}
}

void Assigner_x_Main_TMORPION(uint8_t CPU0_PLY1){
Players[0]=(CPU0_PLY1==0)?1:0;
Players[1]=(CPU0_PLY1==0)?0:1;
MyTurn=(CPU0_PLY1==0)?0:1;
}

////////////////////////////////// main  ////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
void loop_TMORPION() {
ESP.wdtDisable();
ESP.wdtFeed();
NEW_GAME:;
Tiny_MENU_TMORPION(22+(SELECT*7));
while(1){
ESP.wdtDisable();
ESP.wdtFeed();
if (TINYJOYPAD_DOWN==0)  {
  DEBOUNCE(TINYJOYPAD_DOWN==0) {
SELECT=(SELECT<2)?SELECT+1:SELECT;
Tiny_MENU_TMORPION(22+(SELECT*7));
Sound_TMORPION(200,3);
  }
while(1){
ESP.wdtDisable();
ESP.wdtFeed();
if (TINYJOYPAD_DOWN==0){}else{break;}}
  }
if (TINYJOYPAD_UP==0) {
  DEBOUNCE(TINYJOYPAD_UP==0) {
SELECT=(SELECT>0)?SELECT-1:SELECT;
Tiny_MENU_TMORPION(22+(SELECT*7));
Sound_TMORPION(200,3);
}
while(1){
ESP.wdtDisable();
ESP.wdtFeed();
if (TINYJOYPAD_UP==0){}else{break;}}
  } 
  if (BUTTON_DOWN) {break;}}
while(1){
ESP.wdtDisable();
ESP.wdtFeed();
if (BUTTON_UP) {break;}}
uint8_t No_Ripple=0;
INIT_M_DATA_TMORPION();
Assigner_x_Main_TMORPION(1);
Tiny_Flip_TMORPION(0,0,8);
SND_BOX_TMORPION(6);
My_delay_ms(500);
while(1){
ESP.wdtFeed();
if (MyTurn) {
if (TINYJOYPAD_RIGHT==0) {
  DEBOUNCE(TINYJOYPAD_RIGHT==0) {
  if (No_Ripple==0) {No_Ripple=1;POS_XY[0]=(POS_XY[0]<2)?POS_XY[0]+1:2;}
}
  }else if (TINYJOYPAD_LEFT==0) {
    DEBOUNCE(TINYJOYPAD_LEFT==0) {
  if (No_Ripple==0) {No_Ripple=1;POS_XY[0]=(POS_XY[0]>0)?POS_XY[0]-1:0;}
}
    }else if (TINYJOYPAD_DOWN==0) {
     DEBOUNCE(TINYJOYPAD_DOWN==0) {
      if (No_Ripple==0) {No_Ripple=1;POS_XY[1]=(POS_XY[1]<2)?POS_XY[1]+1:2;}
    }
  }else if (TINYJOYPAD_UP==0) {
    DEBOUNCE(TINYJOYPAD_UP==0) {
    if (No_Ripple==0) {No_Ripple=1;POS_XY[1]=(POS_XY[1]>0)?POS_XY[1]-1:0;}
  }
    }else{No_Ripple=0;}   
if ((No_Ripple==0)&&(BUTTON_DOWN)) {
  if (BOARD[POS_XY[1]][POS_XY[0]]==2) {
    BOARD[POS_XY[1]][POS_XY[0]]=Players[1];REFRESH_SCREEN_TMORPION();SND_BOX_TMORPION(Players[1]);Check_WIN_TMORPION(Players[1]);MyTurn=0;No_Ripple=1;    
  }
  }}else{
if (MyTurn==0) {
  CPU_PLAY_TMORPION();
  REFRESH_SCREEN_TMORPION();
  SND_BOX_TMORPION(Players[0]);
  Check_WIN_TMORPION(Players[0]);
  MyTurn=1;
  }
  }
if (ENDGAME>0) {goto NEW_GAME;}
Tiny_Flip_TMORPION(0,0,8);

}
}
////////////////////////////////// main end /////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void SND_BOX_TMORPION(uint8_t SND_){
uint8_t t;
switch (SND_){
  case 1:for (t=0;t<100;t+=10){Sound_TMORPION(t,4);}My_delay_ms(50); break;
  case 0:for (t=100;t<200;t+=10){Sound_TMORPION(t,3);}My_delay_ms(50);break;
  case 2:COMPLETED_PROCEDURE_TMORPION();break;
  case 3:NULL_GAME_TMORPION();break;
  case 4:for(t=1;t<20;t++){Sound_TMORPION(4,80);Sound_TMORPION(100,80);}break;
  case 5:for(t=200;t>10;t--){Sound_TMORPION(200-t,3);Sound_TMORPION(t,12);}break;
  case 6:Sound_TMORPION(100,250);Sound_TMORPION(20,250);break;
  default:break;
}
}

void CPU_PLAY_TMORPION(void){
//PROCEDURAL EVOLUTIF POSSIBILITY
if (CPU_TERMINATION_TMORPION(Players[0])) goto GoOut;
if (SELECT>0) if (CPU_TERMINATION_TMORPION(Players[1])) goto GoOut;
if (SELECT>0) if (BOARD[1][1]==2) {BOARD[1][1]=Players[0];goto GoOut;}
if (SELECT>0) if (CPU_MIDDLE_TMORPION()) {goto GoOut;}
if (SELECT>1) if (CPU_CORNER_TMORPION()){goto GoOut;}
if (SELECT>1) if (CPU_CORNER_TMORPION()){goto GoOut;}
if (SELECT>1) if (CPU_REPLICATE_TMORPION()){goto GoOut;}
CPU_RND_TMORPION();
GoOut:;
}

uint8_t CPU_REPLICATE_TMORPION(void){
uint8_t *p=&BOARD[0][0];
uint8_t t=rand()%4;
#define RE(ZET) pgm_read_byte(&CPU_RNDALT_TMORPION[(t*4)+ZET])
if (p[RE(0)]==2) {p[RE(0)]=Players[0];return 1;}
if (p[RE(1)]==2) {p[RE(1)]=Players[0];return 1;}
if (p[RE(2)]==2) {p[RE(2)]=Players[0];return 1;}
if (p[RE(3)]==2) {p[RE(3)]=Players[0];return 1;}
return 0;
}

uint8_t CPU_DOUBLE_TMORPION(void){
uint8_t Byte_Comp=COMPACT_MAP_TMORPION(2);
uint8_t *p=&BOARD[0][0];
if (Byte_Comp==0xff) {
 switch(rand()%4){
  case 0:p[2]=Players[0];return 1;break;
  case 1:p[6]=Players[0];return 1;break;
  case 2:p[8]=Players[0];return 1;break;
  case 3:p[0]=Players[0];return 1;break;
  default:break;
 }
  }
  return 0;
}

uint8_t  CPU_CORNER_TMORPION(void){
uint8_t Byte_Comp=COMPACT_MAP_TMORPION(Players[1]);
uint8_t Byte_TMP=0;
uint8_t Byte_TMP2=0;
uint8_t t_,t_2;
uint8_t *p=&BOARD[0][0];
for (t_=2;t_<18;t_++){
Byte_TMP=pgm_read_byte(&CPU_CHECK_MIDDLE_TMORPION[t_*2]);
if ((Byte_TMP&Byte_Comp)==(Byte_TMP)) {
  Byte_TMP2=pgm_read_byte(&CPU_CHECK_MIDDLE_TMORPION[(t_*2)+1]);
  for (t_2=0;t_2<8;t_2++){
  if ((Byte_TMP2&(1<<t_2))!=0) {if (p[RECUPE_POS_GRID_TMORPION(t_2)]==2) {p[RECUPE_POS_GRID_TMORPION(t_2)]=Players[0];return 1;} 
  }
  }
}}
return 0;
}

uint8_t COMPACT_MAP_TMORPION(uint8_t PLAYER_){
uint8_t t_,Byte_Comp=0;
uint8_t *p=&BOARD[0][0];
for (t_=0;t_<4;t_++){  if (p[t_]==PLAYER_) {Byte_Comp|=(0b00000001<<t_);}}
for (t_=5;t_<9;t_++){  if (p[t_]==PLAYER_) {Byte_Comp|=(0b00000001<<(t_-1));}}
return Byte_Comp;
}

uint8_t CPU_MIDDLE_TMORPION(void){
 uint8_t t_,t_2;
  if (BOARD[1][1]==Players[0]) {
uint8_t Byte_Comp=0;
uint8_t Byte_TMP=0;
uint8_t Byte_TMP2=0;
uint8_t *p=&BOARD[0][0];
Byte_Comp=COMPACT_MAP_TMORPION(Players[1]);
 for (t_=0;t_<2;t_++){   
    Byte_TMP=pgm_read_byte(&CPU_CHECK_MIDDLE_TMORPION[t_*2]);
    if ((Byte_TMP&Byte_Comp)==(Byte_TMP)) {
      Byte_TMP2=pgm_read_byte(&CPU_CHECK_MIDDLE_TMORPION[(t_*2)+1]);
     for (t_2=0;t_2<8;t_2++){if ((Byte_TMP2&(1<<t_2))!=0) {if (p[RECUPE_POS_GRID_TMORPION(t_2)]==2) {p[RECUPE_POS_GRID_TMORPION(t_2)]=Players[0];return 1;}}}
    }}}
return 0;
}

void Check_WIN_TMORPION(uint8_t O_X){
uint8_t x_;
uint8_t Byte_Comp=0;
uint8_t Byte_TMP=0;
uint8_t *p=&BOARD[0][0];
uint8_t Counter_1=0;
Byte_Comp=COMPACT_MAP_TMORPION(O_X);
for (x_=0;x_<8;x_++){
Byte_TMP=Byte_Comp&pgm_read_byte(&LINE_CHECK_TMORPION[x_]);
if (Byte_TMP==pgm_read_byte(&LINE_CHECK_TMORPION[x_])) {
switch (x_){ case 0 ... 3:if (p[4]==O_X) {if (COMPLETED_PROCEDURE_TMORPION()){goto GO_OUT;}}break; 
default:if (COMPLETED_PROCEDURE_TMORPION()){goto GO_OUT;}break;}
}}
for (x_=0;x_<9;x_++){if (p[x_]==2) {Counter_1=1;}}
if (Counter_1==0) {NULL_GAME_TMORPION();}
GO_OUT:;
}

void NULL_GAME_TMORPION(void){
uint8_t *p=&BOARD[0][0];
uint8_t S;
for (S=0;S<30;S++){
Sound_TMORPION(10,4);
My_delay_ms(4);
Sound_TMORPION(100,4);}
for (uint8_t t_=0;t_<9;t_++){
p[t_]=2;
}
MyTurn=0;
REFRESH_SCREEN_TMORPION();
}

void BLINK_WINNER_TMORPION(void){
uint8_t *p=&BOARD[0][0];
uint8_t t,S;
uint8_t pMEM[9];
for (t=0;t<9;t++){
pMEM[t]=p[t];}
for (S=0;S<10;S++){
Sound_TMORPION(140,10);Sound_TMORPION(220,4);
for (t=0;t<9;t++){if (p[t]==Players[MyTurn]) {p[t]=2;}}
REFRESH_SCREEN_TMORPION();
My_delay_ms(24);
for (t=0;t<9;t++){p[t]=pMEM[t];}
Sound_TMORPION(10,4);
REFRESH_SCREEN_TMORPION();
My_delay_ms(24);
}}

uint8_t COMPLETED_PROCEDURE_TMORPION(void){
BLINK_WINNER_TMORPION();
uint8_t TMP_OUT=0;
uint8_t *p=&BOARD[0][0];
for (uint8_t t_=0;t_<9;t_++){
p[t_]=2;
}
switch (MyTurn){
 case 0:if (WinCPU<9){WinCPU++;}else{SND_BOX_TMORPION(5);ENDGAME=1;TMP_OUT=1;}break;
 case 1:if (WinPLY<9){WinPLY++;}else{SND_BOX_TMORPION(4);ENDGAME=2;TMP_OUT=1;}break;
 default:break;
}
MyTurn=0;
REFRESH_SCREEN_TMORPION();
return TMP_OUT;
}

uint8_t RECUPE_POS_GRID_TMORPION(uint8_t Pos_){
switch (Pos_){
  case 0 ... 3 :return Pos_;break;
  case 4 ... 7 :return (Pos_+1);break;
  default:return 0;break;
}}

uint8_t CPU_TERMINATION_TMORPION(uint8_t PLYs_){ //WORK in PROGRESS
uint8_t x_;
uint8_t t2_;
uint8_t Counter_1;
uint8_t Byte_Comp=0;
uint8_t Byte_TMP=0;
uint8_t Byte_TMP2=0;
uint8_t *p=&BOARD[0][0];
Byte_Comp=COMPACT_MAP_TMORPION(PLYs_);
for (x_=4;x_<8;x_++){ 
Byte_TMP2=pgm_read_byte(&LINE_CHECK_TMORPION[x_]);
Byte_TMP=Byte_Comp&Byte_TMP2;
Counter_1=0;
for (t2_=0;t2_<8;t2_++){
if ((Byte_TMP&(1<<t2_))!=0) {Counter_1++;}
}
if (Counter_1!=2) {goto GoNext;}
for (t2_=0;t2_<8;t2_++){
if ((Byte_TMP2&(1<<t2_))!=(Byte_TMP&(1<<t2_))) {if (p[RECUPE_POS_GRID_TMORPION(t2_)]==2) {p[RECUPE_POS_GRID_TMORPION(t2_)]=Players[0];return 1;} }
} 
GoNext:; 
}
for (x_=0;x_<4;x_++){ 
Byte_TMP2=pgm_read_byte(&LINE_CHECK_TMORPION[x_]);
Byte_TMP=Byte_Comp&Byte_TMP2;
Counter_1=0;
for (t2_=0;t2_<8;t2_++){
if ((Byte_TMP&(1<<t2_))!=0) {Counter_1++;}
}
switch (Counter_1) {
  case 1:if (p[4]==PLYs_) {goto PUTCORNER;}break;
  case 2:if (p[4]==2) {p[4]=Players[0];return 1;}break;
  default:goto GoNext2;break;
}
goto GoNext2;
PUTCORNER:;
for (t2_=0;t2_<8;t2_++){
if ((Byte_TMP2&(1<<t2_))!=(Byte_TMP&(1<<t2_))) {if (p[RECUPE_POS_GRID_TMORPION(t2_)]==2) {p[RECUPE_POS_GRID_TMORPION(t2_)]=Players[0];return 1;}}
} 
GoNext2:; 
}
return 0;
}

void CPU_RND_TMORPION(void){
uint8_t x_;
uint8_t y_;
while(1){
ESP.wdtDisable();
ESP.wdtFeed();
x_=rand()%3;
y_=rand()%3;
if (BOARD[y_][x_]==2) {BOARD[y_][x_]=Players[0];break;}
}}

void REFRESH_SCREEN_TMORPION(void){
Tiny_Flip_TMORPION(1,0,8);
}

uint8_t RECUPE_UP_X_BOARD_TMORPION(uint8_t xPASS){
  switch(xPASS) {
    case 36 ... 53 :return 0;break;
    case 56 ... 73 :return 1;break;
    case 75 ... 92 :return 2;break;
    default:return 4;break;
  }}

uint8_t RECUPE_MIDDLE_X_BOARD_TMORPION(uint8_t xPASS){
  switch(xPASS) {
    case 25 ... 50 :return 0;break;
    case 52 ... 77 :return 1;break;
    case 78 ... 103 :return 2;break;
    default:return 4;break;
  }}

uint8_t RECUPE_DOWN_X_BOARD_TMORPION(uint8_t xPASS){
  switch(xPASS) {
    case 11 ... 46 :return 0;break;
    case 47 ... 81 :return 1;break;
    case 82 ... 117 :return 2;break;
    default:return 4;break;
  }}

uint8_t RECUPE_UP_TMORPION(uint8_t xPASS,uint8_t yPASS){
uint8_t CaseX=RECUPE_UP_X_BOARD_TMORPION(xPASS);
if (CaseX==4) {return 0;}
uint8_t Sprite_=BOARD[0][CaseX];
if ((CaseX==POS_XY[0])&&(POS_XY[1]==0)) {Sprite_=(DIVIDE_BY_2==1)?2:Sprite_;}else{
if (Sprite_==2) {return 0;}}
uint8_t TMP_X_=pgm_read_byte(&UP_POS_TMORPION[CaseX]);
return pgm_read_byte(&UP_TMORPION[(Sprite_*108)+(CaseX*36)+(xPASS-TMP_X_)+((yPASS-2)*18)]);
}

uint8_t RECUPE_MIDDLE_TMORPION(uint8_t xPASS,uint8_t yPASS){
uint8_t CaseX=RECUPE_MIDDLE_X_BOARD_TMORPION(xPASS);
if (CaseX==4) {return 0;}
uint8_t Sprite_=BOARD[1][CaseX];
if ((CaseX==POS_XY[0])&&(POS_XY[1]==1)) {Sprite_=(DIVIDE_BY_2==1)?2:Sprite_;}else{
if (Sprite_==2) {return 0;}}
uint8_t TMP_X_=pgm_read_byte(&MIDDLE_POS_TMORPION[CaseX]);
return pgm_read_byte(&MIDDLE_TMORPION[(Sprite_*78)+(CaseX*26)+(xPASS-TMP_X_)+((yPASS-4)*26)]);
}

uint8_t RECUPE_DOWN_TMORPION(uint8_t xPASS,uint8_t yPASS){
uint8_t CaseX=RECUPE_DOWN_X_BOARD_TMORPION(xPASS);
if (CaseX==4) {return 0;}
uint8_t Sprite_=BOARD[2][CaseX];
if ((CaseX==POS_XY[0])&&(POS_XY[1]==2)) {Sprite_=(DIVIDE_BY_2==1)?2:Sprite_;}else{
if (Sprite_==2) {return 0;}}
uint8_t TMP_X_=pgm_read_byte(&DOWN_POS_TMORPION[CaseX]);
return pgm_read_byte(&DOWN_TMORPION[(Sprite_*216)+(CaseX*72)+(xPASS-TMP_X_)+((yPASS-5)*36)]);
}

uint8_t RECUPE_POINTER_TMORPION(uint8_t xPASS,uint8_t yPASS){
switch (yPASS){
case 2 ... 3: return RECUPE_UP_TMORPION(xPASS,yPASS);break;
case 4:return RECUPE_MIDDLE_TMORPION(xPASS,yPASS);break;
case 5 ... 6:return RECUPE_DOWN_TMORPION(xPASS,yPASS);break;
default:return 0;break; 
}}

uint8_t Display_TMORLPION(uint8_t xPASS,uint8_t yPASS){
return SPEED_BLITZ_TMORPION(25,0,xPASS,yPASS,WinPLY,police_TMORPION)|SPEED_BLITZ_TMORPION(90,0,xPASS,yPASS,WinCPU,police_TMORPION);
}

uint8_t RECUPE_BACK_TMORPION(uint8_t xPASS,uint8_t yPASS){
switch(yPASS){
  case 0:
  case 1:return (pgm_read_byte(&PLATEAU_UP_TMORPION[xPASS+((yPASS)*128)]))&(0xff-Display_TMORLPION(xPASS,yPASS));break;
  default:break;
}
return pgm_read_byte(&PLATEAU_TMORPION[xPASS+((yPASS-2)*128)]);
}

uint8_t Recupe_TMORPION(uint8_t xPASS,uint8_t yPASS){
return (RECUPE_BACK_TMORPION(xPASS,yPASS)|RECUPE_POINTER_TMORPION(xPASS,yPASS));
}

void Tiny_Flip_TMORPION(uint8_t POINTER_,uint8_t START_,uint8_t END_){
switch(POINTER_) {
  case 1:DIVIDE_BY_2=0;break;
  default:DIVIDE_BY_2=!DIVIDE_BY_2;break;
}
DIVIDE_BY_2=(MyTurn==0)?0:DIVIDE_BY_2;
uint8_t y,x; 
for (y = START_; y < END_; y++){ 
    for (x = 0; x < 128; x++){ 
display.buffer[x+(y*128)] =(Recupe_TMORPION(x,y));
    }
}
display.display();
}

uint8_t Recupe_MENU_TMORPION(uint8_t xPASS,uint8_t yPASS){
switch(yPASS){
  case 0:
  case 1:return (pgm_read_byte(&PLATEAU_UP_TMORPION[xPASS+((yPASS)*128)]))&(0xff-Display_TMORLPION(xPASS,yPASS));break;
  case 3 ... 5 :return SPEED_BLITZ_TMORPION(54,3,xPASS,yPASS,0,menu_TMORPION);break;
  default:return 0;break;
}}

void Tiny_MENU_TMORPION(uint8_t POINTER_){
uint8_t y,x; 
for (y = 0; y < 8; y++){ 
    for (x = 0; x < 128; x++){ 
display.buffer[x+(y*128)] =(Recupe_MENU_TMORPION(x,y)|
(blitzSprite_TMORPION(52,POINTER_,x,y,0,CURSEUR_TMORPION))|
(blitzSprite_TMORPION(8,19,x,y,0,intro_TMORPION))|
(blitzSprite_TMORPION(80,19,x,y,0,intro_TMORPION)));
    }
}
display.display();}
