//     >>>>>  MEGA COMPILATION for ESP8266/ESP8285  GPL v3 <<<<
//                    >>>>>  MEGA Tiny Joypad  <<<<
//                  Programmer: Daniel C 2019
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


#include "spritebank_TBERT.h"

#define Frame_Rate_TBERT 0

// var public
uint8_t INTERLACE_TBERT=0;
uint8_t ANIM_LIFT_TBERT;
uint8_t DESTROY_LIFT_R_TBERT;
uint8_t DESTROY_LIFT_L_TBERT;
uint8_t SEED_TBERT=0;
uint8_t INGAME_TBERT=0;
uint8_t MAIN_GHOST_TBERT=0;
uint8_t BYPASS_DEAD_TBERT;
uint8_t DIFICULT_PLATE_TBERT;
uint8_t Dificulty_TBERT=0;
uint8_t RENEW_SPRITE_TBERT;
int8_t Extra_Live_TBERT;
uint8_t CHANGE_LEVEL_TBERT=0;
uint8_t D4_TBERT=0,D3_TBERT=0,D2_TBERT=0,D1_TBERT=0,D0_TBERT=0;
uint8_t HD4_TBERT=0,HD3_TBERT=0,HD2_TBERT=0,HD1_TBERT=0,HD0_TBERT=0;
// fin var public


void DIFICULTY_CHANGE_TBERT(void);
void ResetDataVar_TBERT(Sprite_TBERT* DATA);
void RESET_GAME_TBERT(void);
void SEED_RND_TBERT(void);
uint8_t RANDOM_TBERT(uint8_t STEP);
void Recupe_HighScore_TBERT(void);
void Rst_Score_TBERT(void);
void recupe_Score_TBERT(void);
uint16_t HighScore_TBERT(uint8_t D_3,uint8_t D_2,uint8_t D_1,uint8_t D_0);
void DEAD_SOUND_TBERT(void);
void DEADIFY_TBERT(uint8_t SPr,Sprite_TBERT *DATA);
void RenewSprite_TBERT(uint8_t SPr,Sprite_TBERT *DATA);
uint8_t Renew_if_Posible_TBERT(Sprite_TBERT *DATA);
uint8_t Renew_Check_if_Posible_TBERT(uint8_t SPr,Sprite_TBERT *DATA);
uint8_t COLLISION_CHECK_TBERT(Sprite_TBERT *DATA);
void FLIP_PLATE_TBERT(void);
void GamePlayUpdate_TBERT(Sprite_TBERT *DATA);
void renew_if_possible_add_TBERT(uint8_t Sprite );
void ResetPlateGrid_TBERT(void);
void ScoreChange_TBERT(void);
void refreshJump_TBERT(uint8_t SpUSE,Sprite_TBERT *DATA);
void TELEPORT_MAIN_TBERT(Sprite_TBERT *DATA);
uint8_t UPDATE_LIFT_MAIN_TBERT(uint8_t SpUSE,Sprite_TBERT *DATA);
void UPDATE_MAIN_MOVE_TBERT(uint8_t SpUSE,Sprite_TBERT *DATA);
void UPDATE_MAIN_DEAD_TBERT(uint8_t SpUSE,Sprite_TBERT *DATA);
void LimitCheck_TBERT(uint8_t SpUSE,uint8_t JOYKEY,Sprite_TBERT *DATA);
uint8_t GridLimitTest_TBERT(uint8_t SpUSE,int8_t x,int8_t y,Sprite_TBERT *DATA);
uint8_t Level_Completed_TBERT(void);
void Ball_move_update_TBERT(uint8_t SpUSE,Sprite_TBERT *sprite);
uint8_t blitzSprite_TBERT(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES);
uint8_t GridPlate_TBERT(uint8_t xPASS,uint8_t yPASS);
uint8_t Recupe_TBERT(uint8_t xPASS,uint8_t yPASS,Sprite_TBERT *DATA);
uint8_t SplitSpriteDecalageY_TBERT(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN);
int8_t RecupeLineY_TBERT(int8_t Valeur);
uint8_t RecupeDecalageY_TBERT(uint8_t Valeur);
uint8_t Tiny_Bert_Live_Print(uint8_t xPASS,uint8_t yPASS);
uint8_t Police_Print_TBERT(uint8_t xPASS,uint8_t yPASS);
void Tiny_Flip_TBERT(Sprite_TBERT *DATA);
void Sound_TBERT(uint8_t freq,uint8_t dur);




void DIFICULTY_CHANGE_TBERT(void){
if (Dificulty_TBERT<20) {Dificulty_TBERT++;}
MAX_SPEED=(DEFAULT_SPEED-(Dificulty_TBERT));
MAX_RENEW=MAX_SPEED;
if ((Dificulty_TBERT>4)) {DIFICULT_PLATE_TBERT=1;}
}

void ResetDataVar_TBERT(Sprite_TBERT* DATA){
uint8_t x;
for (x=0;x<3;x++){
DEADIFY_TBERT(x,DATA);
}}

void RESET_GAME_TBERT(void){
ANIM_LIFT_TBERT=0;
DESTROY_LIFT_R_TBERT=0;
DESTROY_LIFT_L_TBERT=0;
INGAME_TBERT=0;
BYPASS_DEAD_TBERT=1;
DIFICULT_PLATE_TBERT=0;
Dificulty_TBERT=0;
MAX_RENEW=DEFAULT_SPEED;
MAX_SPEED=DEFAULT_SPEED;
Extra_Live_TBERT=3;
CHANGE_LEVEL_TBERT=0;
D4_TBERT=0;
D3_TBERT=0;
D2_TBERT=0;
D1_TBERT=0;
D0_TBERT=0; 
}

void SEED_RND_TBERT(void){
if (SEED_TBERT<29) {SEED_TBERT++;}else{SEED_TBERT=0;}  
}

uint8_t RANDOM_TBERT(uint8_t STEP){
SEED_RND_TBERT();   
if (STEP==2) {
return pgm_read_byte(&RAND2_TBERT[SEED_TBERT]);  
}else{
return pgm_read_byte(&RAND4_TBERT[SEED_TBERT]);   
}}


void Recupe_HighScore_TBERT(void){
uint16_t Score1=HighScore_TBERT(D3_TBERT,D2_TBERT,D1_TBERT,D0_TBERT);
uint16_t Score2=HighScore_TBERT(HD3_TBERT,HD2_TBERT,HD1_TBERT,HD0_TBERT);
if (Score1>Score2){
HD0_TBERT=D0_TBERT;
HD1_TBERT=D1_TBERT;
HD2_TBERT=D2_TBERT;
HD3_TBERT=D3_TBERT;
HD4_TBERT=D4_TBERT;}
}

void Rst_Score_TBERT(void){
D0_TBERT=0;
D1_TBERT=0;
D2_TBERT=0;
D3_TBERT=0;
D4_TBERT=0;
}

void recupe_Score_TBERT(void){
D0_TBERT=HD0_TBERT;
D1_TBERT=HD1_TBERT;
D2_TBERT=HD2_TBERT;
D3_TBERT=HD3_TBERT;
D4_TBERT=HD4_TBERT;
}

uint16_t HighScore_TBERT(uint8_t D_3,uint8_t D_2,uint8_t D_1,uint8_t D_0){
return (D_0+(D_1*10)+(D_2*100)+(D_3*1000));
}

void loop_TBERT() {
ESP.wdtDisable();
ESP.wdtFeed();
uint8_t Time_Management;
Sprite_TBERT sprite_TBERT[3];
NEW_GAME:;
Recupe_HighScore_TBERT();
RESET_GAME_TBERT();
NEW_LEVEL:;
DESTROY_LIFT_R_TBERT=0;
DESTROY_LIFT_L_TBERT=0;
DIFICULTY_CHANGE_TBERT();
RENEW_SPRITE_TBERT=0b00000111;
Time_Management=0;
ResetPlateGrid_TBERT();
ResetDataVar_TBERT(&sprite_TBERT[0]);
MENU_LOOP:;
SEED_RND_TBERT();
if (BUTTON_DOWN) {Rst_Score_TBERT();INGAME_TBERT=1;Sound_TBERT(150,200);Sound_TBERT(100,200);}else{if (INGAME_TBERT==0){recupe_Score_TBERT();}goto FLIP;}
START:;
ESP.wdtDisable();
ESP.wdtFeed();
while(1){
ESP.wdtFeed();
if (CHANGE_LEVEL_TBERT!=0) {
FLIP_PLATE_TBERT();
CHANGE_LEVEL_TBERT--; 
if (CHANGE_LEVEL_TBERT==0) {goto NEW_LEVEL;}else{Sound_TBERT(200,40);BYPASS_DEAD_TBERT=1;goto FLIP;}
}
Ball_move_update_TBERT(1,&sprite_TBERT[0]);
Ball_move_update_TBERT(2,&sprite_TBERT[0]);
if ((sprite_TBERT[0].Joypad_Key==255)&&(sprite_TBERT[0].DEAD==0)) {
if (sprite_TBERT[0].moveTimer1==6) {sprite_TBERT[0].Joypad_Key=0;sprite_TBERT[0].moveTimer1=0;}else{sprite_TBERT[0].moveTimer1++;}
}
if ((TINYJOYPAD_LEFT==0)&&(sprite_TBERT[0].Joypad_Key==0)) {SEED_RND_TBERT();LimitCheck_TBERT(0,4,&sprite_TBERT[0]);}
if ((TINYJOYPAD_RIGHT==0)&&(sprite_TBERT[0].Joypad_Key==0)) {LimitCheck_TBERT(0,2,&sprite_TBERT[0]);}
if ((TINYJOYPAD_DOWN==0)&&(sprite_TBERT[0].Joypad_Key==0)) {LimitCheck_TBERT(0,3,&sprite_TBERT[0]);}
if ((TINYJOYPAD_UP==0)&&(sprite_TBERT[0].Joypad_Key==0)) {SEED_RND_TBERT();LimitCheck_TBERT(0,1,&sprite_TBERT[0]);}
if (Time_Management==1) {Renew_if_Posible_TBERT(&sprite_TBERT[0]);if (Extra_Live_TBERT<0) {INGAME_TBERT=0;goto NEW_GAME;}}
if (Time_Management<2) {
Time_Management++;
GamePlayUpdate_TBERT(&sprite_TBERT[0]);
for (uint8_t Count=0;Count<3;Count++){
 switch (sprite_TBERT[Count].DEAD){
  case(0):
  case(1):UPDATE_MAIN_MOVE_TBERT(Count,&sprite_TBERT[0]);break;
  case(2):UPDATE_MAIN_DEAD_TBERT(Count,&sprite_TBERT[0]);break;
  case(3):UPDATE_LIFT_MAIN_TBERT(Count,&sprite_TBERT[0]);break;
  default:break;}}
  }else{Time_Management=0;goto FLIP;}
}
FLIP:;
if (ANIM_LIFT_TBERT<2) {ANIM_LIFT_TBERT++;}else{ANIM_LIFT_TBERT=0;}
while((currentMillis-MemMillis)<Frame_Rate_TBERT){  
currentMillis=millis();
}
MemMillis=currentMillis;
Tiny_Flip_TBERT(&sprite_TBERT[0]);
COLLISION_CHECK_TBERT(&sprite_TBERT[0]);
if (INTERLACE_TBERT<3) {INTERLACE_TBERT++;}else{INTERLACE_TBERT=0;}
if (INGAME_TBERT==0) {ESP.wdtDisable();ESP.wdtFeed();goto MENU_LOOP;}
goto START;
}
////////////////////////////////// main end /////////////////////////////////

void DEAD_SOUND_TBERT(void){
for(uint8_t s=200;s>100;s--){Sound_TBERT(s,10);} 
}

void DEADIFY_TBERT(uint8_t SPr,Sprite_TBERT *DATA){
DATA[SPr].DEAD=254;
DATA[SPr].moveTimer1=0;
DATA[SPr].xPOS=200+(SPr*10);
DATA[SPr].yPOS=200+(SPr*10);
DATA[SPr].JumpFrame=0;
DATA[SPr].Joypad_Key=254;
DATA[SPr].GridXpos=4+SPr;
DATA[SPr].GridYpos=4+SPr;
}

void RenewSprite_TBERT(uint8_t SPr,Sprite_TBERT *DATA){
if ((SPr==0)&&(BYPASS_DEAD_TBERT==0)) {Extra_Live_TBERT--;}
BYPASS_DEAD_TBERT=0;
DATA[SPr].DEAD=0;
DATA[SPr].moveTimer1=0;
DATA[SPr].xPOS=58;
DATA[SPr].yPOS=2;
DATA[SPr].JumpFrame=0;
DATA[SPr].Joypad_Key=0;
DATA[SPr].GridXpos=0;
DATA[SPr].GridYpos=0;
}

uint8_t Renew_if_Posible_TBERT(Sprite_TBERT *DATA){
if (RENEW_SPRITE_TBERT==0) {return 0;}
if ((RENEW_SPRITE_TBERT&0b00000001)!=0) {return Renew_Check_if_Posible_TBERT(0,DATA);} 
if ((RENEW_SPRITE_TBERT&0b00000010)!=0) {Renew_Check_if_Posible_TBERT(1,DATA);return 0;} 
if ((RENEW_SPRITE_TBERT&0b00000100)!=0) {Renew_Check_if_Posible_TBERT(2,DATA);return 0;} 
return 0;}

uint8_t Renew_Check_if_Posible_TBERT(uint8_t SPr,Sprite_TBERT *DATA){
  if ((SPr==2) &&(Dificulty_TBERT<=5)) return 0;
for (uint8_t t=0;t<3;t++){
if (DATA[t].DEAD!=254) {
if (DATA[t].yPOS<12) {return 1;}
}}
  switch(SPr){
    case(0):RENEW_SPRITE_TBERT=(RENEW_SPRITE_TBERT&0b11111110);break;
    case(1):RENEW_SPRITE_TBERT=(RENEW_SPRITE_TBERT&0b11111101);break;
    case(2):RENEW_SPRITE_TBERT=(RENEW_SPRITE_TBERT&0b11111011);break;    
    default:break;
  }
  RenewSprite_TBERT(SPr,DATA);
  return 0;
}

uint8_t COLLISION_CHECK_TBERT(Sprite_TBERT *DATA){
#define MargXMax 3
#define MargYMax 3
if ((MAIN_GHOST_TBERT==1)||((DATA[0].DEAD!=0))) {return 0;}
for (uint8_t x=1;x<3;x++){
if (((DATA[0].xPOS-MargXMax)>(DATA[x].xPOS+MargXMax))||((DATA[0].xPOS+MargXMax)<(DATA[x].xPOS-MargXMax))||((DATA[0].yPOS-MargYMax)>(DATA[x].yPOS+MargYMax))||((DATA[0].yPOS+MargYMax)<(DATA[x].yPOS-MargYMax))) {}else{DEADIFY_TBERT(0,DATA);RENEW_SPRITE_TBERT=(RENEW_SPRITE_TBERT|0b00000001);DEAD_SOUND_TBERT();}
}
return 0;
}

void FLIP_PLATE_TBERT(void){
uint8_t x,y,S=4,Q;
if (PlateGrid_TBERT[0][0]==1) {Q=0;}else{Q=1;}
for (y=0;y<4;y++){
for (x=0;x<S;x++){
PlateGrid_TBERT[y][x]=Q;
}S--;} 
}

void GamePlayUpdate_TBERT(Sprite_TBERT *DATA){
for (uint8_t Q=0;Q<3;Q++){
if (DATA[Q].DEAD==255) {
if (DATA[Q].Timer_new_Live>0) {DATA[Q].Timer_new_Live--;}else{ 
DATA[Q].Timer_new_Live=MAX_RENEW;
DEADIFY_TBERT(Q,DATA);
renew_if_possible_add_TBERT(Q);
}}}}

void renew_if_possible_add_TBERT(uint8_t Sprite ){
switch (Sprite){
  case(0):RENEW_SPRITE_TBERT=(RENEW_SPRITE_TBERT|0b00000001);break;
  case(1):RENEW_SPRITE_TBERT=(RENEW_SPRITE_TBERT|0b00000010);break;
  case(2):RENEW_SPRITE_TBERT=(RENEW_SPRITE_TBERT|0b00000100);break;
  default:break;
}}

void ResetPlateGrid_TBERT(void){
uint8_t x,y,S=4;
for (y=0;y<4;y++){
for (x=0;x<4;x++){
PlateGrid_TBERT[y][x]=255;
}}
for (y=0;y<4;y++){
for (x=0;x<S;x++){
PlateGrid_TBERT[y][x]=0;
}S--;}
}

void ScoreChange_TBERT(void){
for (uint8_t r=0;r<13;r++){
if (D0_TBERT<9) {D0_TBERT++;}else{
D0_TBERT=0;
if (D1_TBERT<9) {D1_TBERT++;}else{
 D1_TBERT=0;
if (D2_TBERT<9) {D2_TBERT++;}else{
if (Extra_Live_TBERT<3) {Extra_Live_TBERT++;Sound_TBERT(200,20);}
 D2_TBERT=0;
 if (D3_TBERT<9) {D3_TBERT++;}else{D3_TBERT=0;
 if (D4_TBERT<9) {D4_TBERT++;}}
}}}}}

void refreshJump_TBERT(uint8_t SpUSE,Sprite_TBERT *DATA){
uint8_t backup=DATA[SpUSE].Joypad_Key;
if (DATA[SpUSE].Joypad_Key==2) {
DATA[SpUSE].xPOS=DATA[SpUSE].xPOS+pgm_read_byte(&Jump_TBERT[DATA[SpUSE].JumpFrame*2]);
DATA[SpUSE].yPOS=DATA[SpUSE].yPOS+pgm_read_byte(&Jump_TBERT[(DATA[SpUSE].JumpFrame*2)+1]);
}
if (DATA[SpUSE].Joypad_Key==3) {
DATA[SpUSE].xPOS=DATA[SpUSE].xPOS+(-pgm_read_byte(&Jump_TBERT[DATA[SpUSE].JumpFrame*2]));
DATA[SpUSE].yPOS=DATA[SpUSE].yPOS+pgm_read_byte(&Jump_TBERT[(DATA[SpUSE].JumpFrame*2)+1]);
}
if (DATA[SpUSE].Joypad_Key==1) {
DATA[SpUSE].xPOS=DATA[SpUSE].xPOS+pgm_read_byte(&Jump_TBERT[32-(DATA[SpUSE].JumpFrame*2)]);
DATA[SpUSE].yPOS=DATA[SpUSE].yPOS+(-pgm_read_byte(&Jump_TBERT[(32-(DATA[SpUSE].JumpFrame*2))+1]));
}
if (DATA[SpUSE].Joypad_Key==4) {
DATA[SpUSE].xPOS=DATA[SpUSE].xPOS+(-pgm_read_byte(&Jump_TBERT[32-(DATA[SpUSE].JumpFrame*2)]));
DATA[SpUSE].yPOS=DATA[SpUSE].yPOS+(-pgm_read_byte(&Jump_TBERT[(32-(DATA[SpUSE].JumpFrame*2))+1]));
}
DATA[SpUSE].JumpFrame=DATA[SpUSE].JumpFrame+1;
if (DATA[SpUSE].JumpFrame>15) {
Sound_TBERT(160,10);
if (DIFICULT_PLATE_TBERT==0) {
if ((PlateGrid_TBERT[DATA[SpUSE].GridYpos][DATA[SpUSE].GridXpos]==0)&&(SpUSE==0)&&(DATA[SpUSE].DEAD==0)) {ScoreChange_TBERT();PlateGrid_TBERT[DATA[SpUSE].GridYpos][DATA[SpUSE].GridXpos]=1;if (Level_Completed_TBERT()) {BYPASS_DEAD_TBERT=1;CHANGE_LEVEL_TBERT=18;}}  
}else{
if ((SpUSE==0)&&(DATA[SpUSE].DEAD==0)) {PlateGrid_TBERT[DATA[SpUSE].GridYpos][DATA[SpUSE].GridXpos]=!PlateGrid_TBERT[DATA[SpUSE].GridYpos][DATA[SpUSE].GridXpos];if (PlateGrid_TBERT[DATA[SpUSE].GridYpos][DATA[SpUSE].GridXpos]==1) {ScoreChange_TBERT();}if (Level_Completed_TBERT()) {BYPASS_DEAD_TBERT=1;CHANGE_LEVEL_TBERT=18;}} 
} 
DATA[SpUSE].JumpFrame=0;
DATA[SpUSE].Joypad_Key=255;
if (DATA[SpUSE].sw==2) {DATA[SpUSE].sw=3;}
if (DATA[SpUSE].sw==0) {DATA[SpUSE].sw=1;}
if (DATA[SpUSE].DEAD==1) {
if ((DATA[SpUSE].GridXpos==3)&&(backup==1)&&(DESTROY_LIFT_R_TBERT==0)) {DESTROY_LIFT_R_TBERT=1;TELEPORT_MAIN_TBERT(DATA);DATA[SpUSE].DEAD=3;}
else if ((DATA[SpUSE].GridYpos==3)&&(backup==4)&&(DESTROY_LIFT_L_TBERT==0)) {DESTROY_LIFT_L_TBERT=1;TELEPORT_MAIN_TBERT(DATA);DATA[SpUSE].DEAD=3;}
else{DATA[SpUSE].DEAD=2;if (SpUSE==0) {DEAD_SOUND_TBERT();}}
}}}

void TELEPORT_MAIN_TBERT(Sprite_TBERT *DATA){
BYPASS_DEAD_TBERT=1; 
DATA[0].GridXpos=0;
DATA[0].GridYpos=0;
}

uint8_t UPDATE_LIFT_MAIN_TBERT(uint8_t SpUSE,Sprite_TBERT *DATA){
uint8_t x=0;
Sound_TBERT(100-DATA[SpUSE].yPOS,10);
while(x<2) {
if ((DATA[SpUSE].xPOS==58)&&(DATA[SpUSE].yPOS==2)) {DATA[SpUSE].DEAD=0;BYPASS_DEAD_TBERT=0; }
if (SpUSE!=0) {return 0;} 
if (DATA[SpUSE].yPOS>2) {DATA[SpUSE].yPOS--;}else{
if (DATA[SpUSE].xPOS>58) {DATA[SpUSE].xPOS--;}
if (DATA[SpUSE].xPOS<58) {DATA[SpUSE].xPOS++;}
}
x++;}
return 0;
}

void UPDATE_MAIN_MOVE_TBERT(uint8_t SpUSE,Sprite_TBERT *DATA){
uint8_t x=0;
if ((DATA[SpUSE].Joypad_Key!=0)&&(DATA[SpUSE].Joypad_Key!=255)&&(DATA[SpUSE].JumpFrame==0)) {
DATA[SpUSE].JumpFrame=1;}
while(x<2){
if (DATA[SpUSE].JumpFrame!=0) {refreshJump_TBERT(SpUSE,DATA);
}x++;
}}

void UPDATE_MAIN_DEAD_TBERT(uint8_t SpUSE,Sprite_TBERT *DATA){
uint8_t x=0;
while(x<2){
DATA[SpUSE].yPOS=DATA[SpUSE].yPOS+2;
x++;}
if (DATA[SpUSE].yPOS>120) {DATA[SpUSE].DEAD=255;}
}

void LimitCheck_TBERT(uint8_t SpUSE,uint8_t JOYKEY,Sprite_TBERT *DATA){
DATA[SpUSE].Joypad_Key=JOYKEY;
 switch(JOYKEY){
  case(4):DATA[SpUSE].sw=2;GridLimitTest_TBERT(SpUSE,-1,0,DATA);break;
  case(2):DATA[SpUSE].sw=0;GridLimitTest_TBERT(SpUSE,1,0,DATA);break;
  case(3):DATA[SpUSE].sw=2;GridLimitTest_TBERT(SpUSE,0,1,DATA);break;
  case(1):DATA[SpUSE].sw=0;GridLimitTest_TBERT(SpUSE,0,-1,DATA);break;
  default:break;
 }
 }

uint8_t GridLimitTest_TBERT(uint8_t SpUSE,int8_t x,int8_t y,Sprite_TBERT *DATA){
  if  ((x==-1)&&(DATA[SpUSE].GridXpos+x)>=0) {DATA[SpUSE].GridXpos--;return 0;}
  if  (((x==1)&&(DATA[SpUSE].GridXpos+x)<=3)&&(PlateGrid_TBERT[DATA[SpUSE].GridYpos][DATA[SpUSE].GridXpos+1]!=255)) {DATA[SpUSE].GridXpos++;return 0;}
  if  ((y==-1)&&(DATA[SpUSE].GridYpos+y)>=0) {DATA[SpUSE].GridYpos--;return 0;}
  if  (((y==1)&&(DATA[SpUSE].GridYpos+y)<=3)&&(PlateGrid_TBERT[DATA[SpUSE].GridYpos+1][DATA[SpUSE].GridXpos]!=255)) {DATA[SpUSE].GridYpos++;return 0;} 
DATA[SpUSE].DEAD=1;
return 0;
}

uint8_t Level_Completed_TBERT(void){
uint8_t x,y,S=4;
for (y=0;y<4;y++){
for (x=0;x<S;x++){
if (PlateGrid_TBERT[y][x]==0) {return 0;} 
}S--;}
return 1;
}

void Ball_move_update_TBERT(uint8_t SpUSE,Sprite_TBERT *sprite){
uint8_t SPEED=MAX_SPEED;
if (SpUSE==0) {SPEED=30;}
if ((sprite[SpUSE].Joypad_Key==255)&&(sprite[SpUSE].DEAD==0)) {sprite[SpUSE].Joypad_Key=0;}
if (sprite[SpUSE].Joypad_Key==0) {
sprite[SpUSE].moveTimer1++;
if (sprite[SpUSE].moveTimer1==SPEED){
sprite[SpUSE].moveTimer1=0;
uint8_t Q;
if ((SpUSE==1)||(sprite[SpUSE].GridXpos==0)||(sprite[SpUSE].GridYpos==0)) {Q=RANDOM_TBERT(2);}else{Q=RANDOM_TBERT(4);}
switch(Q){
case (0):LimitCheck_TBERT(SpUSE,2,&sprite[0]);break;
case (1):LimitCheck_TBERT(SpUSE,3,&sprite[0]);break;
case (2):LimitCheck_TBERT(SpUSE,1,&sprite[0]);break;
case (3):LimitCheck_TBERT(SpUSE,4,&sprite[0]);break;
default:break;
}}}}


uint8_t blitzSprite_TBERT(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES){
uint8_t OUTBYTE;
uint8_t WSPRITE=(pgm_read_byte(&SPRITES[0]));
uint8_t HSPRITE=(pgm_read_byte(&SPRITES[1]));
uint8_t Wmax=((HSPRITE*WSPRITE)+1);
uint8_t PICBYTE=FRAME*(Wmax-1);
int8_t RECUPELINEY=RecupeLineY_TBERT(yPos);
if ((xPASS>((xPos+(WSPRITE-1))))||(xPASS<xPos)||((RECUPELINEY>yPASS)||((RECUPELINEY+(HSPRITE))<yPASS))) {return 0x00;}
int8_t SPRITEyLINE=(yPASS-(RECUPELINEY));
uint8_t SPRITEyDECALAGE=(RecupeDecalageY_TBERT(yPos));
uint8_t ScanA=(((xPASS-xPos)+(SPRITEyLINE*WSPRITE))+2);
uint8_t ScanB=(((xPASS-xPos)+((SPRITEyLINE-1)*WSPRITE))+2);
if (ScanA>Wmax) {OUTBYTE=0x00;}else{OUTBYTE=SplitSpriteDecalageY_TBERT(SPRITEyDECALAGE,pgm_read_byte(&SPRITES[ScanA+(PICBYTE)]),1);}
if ((SPRITEyLINE>0)) {
uint8_t OUTBYTE2=SplitSpriteDecalageY_TBERT(SPRITEyDECALAGE,pgm_read_byte(&SPRITES[ScanB+(PICBYTE)]),0);
if (ScanB>Wmax) {return OUTBYTE;}else{return OUTBYTE|OUTBYTE2;}
}else{return OUTBYTE;}
}

uint8_t GridPlate_TBERT(uint8_t xPASS,uint8_t yPASS){
uint8_t Byte=0x00;
if ((yPASS==0)||(yPASS==1)) {
if (PlateGrid_TBERT[0][0]==1) {Byte|=blitzSprite_TBERT(54,6,xPASS,yPASS,0,Plate_TBERT); }
}else if ((yPASS==2)||(yPASS==3)) {
if (PlateGrid_TBERT[0][1]==1) {Byte|=blitzSprite_TBERT(64,20,xPASS,yPASS,0,Plate_TBERT); }
if (PlateGrid_TBERT[1][0]==1) {Byte|=blitzSprite_TBERT(44,20,xPASS,yPASS,0,Plate_TBERT); }
}else if ((yPASS==4)||(yPASS==5)) {
if (PlateGrid_TBERT[0][2]==1) {Byte|=blitzSprite_TBERT(74,34,xPASS,yPASS,0,Plate_TBERT); }
if (PlateGrid_TBERT[1][1]==1) {Byte|=blitzSprite_TBERT(54,34,xPASS,yPASS,0,Plate_TBERT); }
if (PlateGrid_TBERT[2][0]==1) {Byte|=blitzSprite_TBERT(34,34,xPASS,yPASS,0,Plate_TBERT); }
}else if ((yPASS==6)) {
if (PlateGrid_TBERT[0][3]==1) {Byte|=blitzSprite_TBERT(84,48,xPASS,yPASS,0,Plate_TBERT); } 
if (PlateGrid_TBERT[1][2]==1) {Byte|=blitzSprite_TBERT(64,48,xPASS,yPASS,0,Plate_TBERT); }
if (PlateGrid_TBERT[2][1]==1) {Byte|=blitzSprite_TBERT(44,48,xPASS,yPASS,0,Plate_TBERT); }
if (PlateGrid_TBERT[3][0]==1) {Byte|=blitzSprite_TBERT(24,48,xPASS,yPASS,0,Plate_TBERT); }
}
return Byte;
}

uint8_t Recupe_TBERT(uint8_t xPASS,uint8_t yPASS,Sprite_TBERT *DATA){
uint8_t R,L;
if (INGAME_TBERT==0) {
return (pgm_read_byte(&INTRO_TBERT[xPASS+(yPASS*128)])|Police_Print_TBERT(xPASS,yPASS)); 
}
if (DESTROY_LIFT_R_TBERT==0) {R=blitzSprite_TBERT(96,40,xPASS,yPASS,ANIM_LIFT_TBERT,LIFT_PLATE_TBERT);}else{R=0;}
if (DESTROY_LIFT_L_TBERT==0) {L=blitzSprite_TBERT(16,40,xPASS,yPASS,ANIM_LIFT_TBERT,LIFT_PLATE_TBERT);}else{L=0;}
uint8_t black=(0xff-Tiny_Bert_Live_Print(xPASS,yPASS));
if (DATA[0].DEAD!=2) {black&=(0xff-(blitzSprite_TBERT(DATA[0].xPOS,DATA[0].yPOS,xPASS,yPASS,DATA[0].sw,TINYBERT_BLACK_TBERT)));}
if (DATA[1].DEAD!=2) {black&=(0xff-(blitzSprite_TBERT(DATA[1].xPOS,DATA[1].yPOS,xPASS,yPASS,DATA[1].sw,BALL_BLACK_TBERT)));}
if (DATA[2].DEAD!=2) {black&=(0xff-(blitzSprite_TBERT(DATA[2].xPOS,DATA[2].yPOS,xPASS,yPASS,DATA[2].sw,SNACK_BLACK_TBERT)));}
return 
(blitzSprite_TBERT(DATA[0].xPOS,DATA[0].yPOS,xPASS,yPASS,DATA[0].sw,TINYBERT_TBERT)
|blitzSprite_TBERT(DATA[1].xPOS,DATA[1].yPOS,xPASS,yPASS,DATA[1].sw,BALL_TBERT)
|blitzSprite_TBERT(DATA[2].xPOS,DATA[2].yPOS,xPASS,yPASS,DATA[2].sw,SNACK_TBERT)
|Police_Print_TBERT(xPASS,yPASS)
|GridPlate_TBERT(xPASS,yPASS)
|R
|L
|pgm_read_byte(&BACK_TBERT[xPASS+(yPASS*128)]))&(black);
;}

uint8_t SplitSpriteDecalageY_TBERT(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN){
if (UPorDOWN) {return Input<<decalage;}
return Input>>(8-decalage);
}

int8_t RecupeLineY_TBERT(int8_t Valeur){
return (Valeur>>3); 
}

uint8_t RecupeDecalageY_TBERT(uint8_t Valeur){
return (Valeur-((Valeur>>3)<<3));
}

uint8_t Tiny_Bert_Live_Print(uint8_t xPASS,uint8_t yPASS){
if (yPASS>1) {return 0x00;}
if (xPASS>34) {return 0x00;}
uint8_t ret=0x00;
#define A_TBERT blitzSprite_TBERT(5,1,xPASS,yPASS,0,Live_TBERT)
#define B_TBERT blitzSprite_TBERT(14,1,xPASS,yPASS,0,Live_TBERT)
#define C_TBERT blitzSprite_TBERT(23,1,xPASS,yPASS,0,Live_TBERT)

switch(Extra_Live_TBERT){
  case(1):ret|=A_TBERT;break;
  case(2):ret|=A_TBERT;ret|=B_TBERT;break;
  case(3):ret|=A_TBERT;ret|=B_TBERT;ret|=C_TBERT;break;
  default:break;
}return ret;
};

uint8_t Police_Print_TBERT(uint8_t xPASS,uint8_t yPASS){
if (xPASS<94) return 0x00;
if (yPASS>0) return 0x00;
if ((xPASS>=99)&&(xPASS<=102)) {return pgm_read_byte(&police_TBERT[(xPASS-99)+(D4_TBERT*4)]);} //digit 0 
if ((xPASS>=103)&&(xPASS<=106)) {return pgm_read_byte(&police_TBERT[(xPASS-103)+(D3_TBERT*4)]);} //digit 0 
if ((xPASS>=107)&&(xPASS<=110)) {return pgm_read_byte(&police_TBERT[(xPASS-107)+(D2_TBERT*4)]);} //digit 0 
if ((xPASS>=111)&&(xPASS<=114)) {return pgm_read_byte(&police_TBERT[(xPASS-111)+(D1_TBERT*4)]);} //digit 0 
if ((xPASS>=115)&&(xPASS<=118)) {return pgm_read_byte(&police_TBERT[(xPASS-115)+(D0_TBERT*4)]);} //digit 0 
return 0x00;
};

void Tiny_Flip_TBERT(Sprite_TBERT *DATA){
uint8_t y,x; 
for (y = 0; y < 8; y++){ 
for (x = 0; x < 128; x++){
display.buffer[x+(y*128)] =(Recupe_TBERT(x,y,DATA));
}}
display.display();
}

void Sound_TBERT(uint8_t freq,uint8_t dur){
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



