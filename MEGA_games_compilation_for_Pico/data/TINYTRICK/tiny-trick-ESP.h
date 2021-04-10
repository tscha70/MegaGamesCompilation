//     >>>>>  MEGA COMPILATION for ESP8266/ESP8285  GPL v3 <<<<
//                    >>>>>  MEGA Tiny Joypad  <<<<
//                     Programmer: Daniel C 2019
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

#include "spritebank_TTRICK.h"
# define Frame_rate_TTRICK 0//50 original attiny85 speed
Sprite_TTRICK sprite_TTRICK[5];
uint8_t Player1_Rotate_TTRICK;
uint8_t Computer_Rotate_TTRICK;
uint8_t COM_MAX_SPEED_x_TTRICK;
uint8_t COM_MAX_SPEED_y_TTRICK;
uint8_t ORIx_TTRICK;
uint8_t ORIy_TTRICK;
uint8_t SKIP_FRAME_TTRICK;
uint8_t Puck_x_TTRICK;
uint8_t Puck_y_TTRICK;
uint8_t X_Drag_TTRICK;
uint8_t Y_drag_TTRICK;
uint8_t Drag_Puck_TTRICK;
uint8_t GOAL_TTRICK;
uint8_t Points_CPU_TTRICK;
uint8_t Points_Pl1_TTRICK;
//FIN VAR TTRICK

void Sound_TTRICK(uint8_t freq_,uint8_t dur);
void SCREEN_GOAL_TTRICK(void);
uint8_t Lost_win_TTRICK(uint8_t xPASS,uint8_t yPASS,const uint8_t *SPRITES);
void intro_TTRICK(uint8_t GOAL_TTRICKSCREEN,uint8_t SLIDE);
void Tiny_Flip_TTRICK(void);
uint8_t RecupeDecalageY_TTRICK(uint8_t Valeur);
uint8_t RecupeLineY_TTRICK(uint8_t Valeur);
uint8_t SplitSpriteDecalageY_TTRICK(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN);
uint8_t Patinoire1_2_TTRICK(uint8_t xPASS,uint8_t yPASS);
uint8_t Recupe_TTRICK(uint8_t xPASS,uint8_t yPASS);
uint8_t blitzSprite_TTRICK(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES);
void Speed_adj_V_N_TTRICK(uint8_t SPRITE_NO);
void Speed_adj_V_P_TTRICK(uint8_t SPRITE_NO);
void Speed_adj_H_N_TTRICK(uint8_t SPRITE_NO);
void Speed_adj_H_P_TTRICK(uint8_t SPRITE_NO);
void Adjust_Cumule_Speed_TTRICK(uint8_t SPRITE_NO);
uint8_t Adjust_Speed_Computer_TTRICK(uint8_t Puck,uint8_t Val_Computer_2);
void Speed_V_Decel_TTRICK(uint8_t SPR_TYPE);
void Speed_H_Decel_TTRICK(uint8_t SPR_TYPE);
uint8_t Update_Computer_Direction_TTRICK(void);
uint8_t Direction_Recupe_TTRICK(uint8_t Con);
uint8_t Computer_rotation_filter_update_TTRICK(void);
uint8_t collision_check_Sprite2Sprite_TTRICK(uint8_t Sp_1,uint8_t Sp_2);
void Reverse_x_pla_TTRICK(uint8_t SpriteTested);
void Reverse_y_pla_TTRICK(uint8_t SpriteTested);
void BOUNCE_SPRITE_TTRICK(void);
void Speed_Puck_Decel_TTRICK(uint8_t SPR_TYPE);
void Drag_Puck_TTRICK_test(void);
void Drag_Puck_Update_TTRICK(void);
void KICK_PUCK_TTRICK(uint8_t Player_Rotate);
uint8_t collision_check_LimiteScreen_TTRICK(uint8_t SpriteTested);
void Reverse_x_puck_2_neg_TTRICK(uint8_t SpriteTested);
void Reverse_x_puck_2_pos_TTRICK(uint8_t SpriteTested);
uint8_t GOAL_FUNCTION_TTRICK(uint8_t Goal_0,uint8_t Goal_1);
uint8_t check_Puck2Gard_TTRICK(uint8_t Gard);
void SND_TTRICK(uint8_t Snd);
void Goal_Adj_TTRICK(uint8_t Y_POS,uint8_t SPR_Type);

void Reset_new_game_TTRICK(void){
Drag_Puck_TTRICK=255;
GOAL_TTRICK=255;
Points_CPU_TTRICK=0;
Points_Pl1_TTRICK=0;
}

void ResetAllSprites_TTRICK(void){
uint8_t t;
for (t=0;t<4;t++){  
sprite_TTRICK[t].Xpos=0;   
sprite_TTRICK[t].Ypos=0;  
sprite_TTRICK[t].CumuleX=0;
sprite_TTRICK[t].CumuleY=0;
sprite_TTRICK[t].SpeedXpositif=0;
sprite_TTRICK[t].SpeedXnegatif=0;
sprite_TTRICK[t].SpeedYpositif=0;
sprite_TTRICK[t].SpeedYnegatif=0;
}}

void INIT_ALL_VAR_TTRICK(void){
ORIx_TTRICK=0;
ORIy_TTRICK=0;
Player1_Rotate_TTRICK=0;
Computer_Rotate_TTRICK=4;
sprite_TTRICK[0].Xpos=37;   
sprite_TTRICK[0].Ypos=23;  
sprite_TTRICK[1].Xpos=74;   
sprite_TTRICK[1].Ypos=24;  
sprite_TTRICK[3].Xpos=4;
sprite_TTRICK[3].Ypos=28;   
sprite_TTRICK[4].Xpos=119; 
sprite_TTRICK[4].Ypos=28;  
sprite_TTRICK[2].Xpos=63;
if (SKIP_FRAME_TTRICK){
  sprite_TTRICK[2].SpeedYpositif=26;
  sprite_TTRICK[2].Ypos=6;
}else{
  sprite_TTRICK[2].SpeedYnegatif=26;
  sprite_TTRICK[2].Ypos=56;
}}

#define PUCK_X sprite_TTRICK[2].Xpos
#define PUCK_Y sprite_TTRICK[2].Ypos

void Goal_Adj_TTRICK(uint8_t Y_POS,uint8_t SPR_Type){
if (Y_POS==1) {
if (sprite_TTRICK[SPR_Type].Ypos<34) {sprite_TTRICK[SPR_Type].Ypos+=2;}
}else{
if (sprite_TTRICK[SPR_Type].Ypos>20) {sprite_TTRICK[SPR_Type].Ypos-=2;}
}}

void SND_TTRICK(uint8_t Snd){
uint8_t q; 
  switch(Snd){
    case 0:for(q=1;q<30;q++){Sound_TTRICK(140,30);Sound_TTRICK(220,30);}break;
    case 1:for(q=1;q<30;q++){Sound_TTRICK(20,35);Sound_TTRICK(200,45);}break;
    case 2:Sound_TTRICK(3,5);Sound_TTRICK(10,10);Sound_TTRICK(3,5);break;
    case 3:Sound_TTRICK(3,2);break;
    case 4:Sound_TTRICK(200,10);Sound_TTRICK(80,4);break;
    case 5:for(q=1;q<20;q++){Sound_TTRICK(4,80);Sound_TTRICK(100,80);}break;
    case 6:for(q=200;q>10;q--){Sound_TTRICK(200-q,3);Sound_TTRICK(q,12);}break;
    case 7:Sound_TTRICK(100,250);Sound_TTRICK(20,250);break;
    default:break;
 }}

void loop_TTRICK() {
ESP.wdtDisable();
INTRO:;
Reset_new_game_TTRICK();
{ 
uint8_t TIMER=0;
while(1){
 ESP.wdtFeed();
if (TIMER<255) {TIMER++;}else{TIMER=0;}
My_delay_ms(4);
switch(TIMER){
case (0) : intro_TTRICK(0,0); break;
case (128) : intro_TTRICK(4,0);break;
default:break;}
if (BUTTON_DOWN) {SND_TTRICK(7);My_delay_ms(100);goto Start_Game;}
}}
Start_Game:;
RESTART:;
ResetAllSprites_TTRICK();
INIT_ALL_VAR_TTRICK();
Tiny_Flip_TTRICK();
My_delay_ms(600);
SND_TTRICK(0);
while(1){
ESP.wdtFeed();
COM_MAX_SPEED_x_TTRICK=28;
COM_MAX_SPEED_y_TTRICK=28;
if  (TINYJOYPAD_UP==0) {Goal_Adj_TTRICK(0,3);ORIx_TTRICK=2;Speed_adj_V_N_TTRICK(0);}
else if (TINYJOYPAD_DOWN==0) {Goal_Adj_TTRICK(1,3);ORIx_TTRICK=8;Speed_adj_V_P_TTRICK(0);}else{ORIx_TTRICK=0;Speed_V_Decel_TTRICK(0);}
if (TINYJOYPAD_RIGHT==0) {ORIy_TTRICK=4; Speed_adj_H_P_TTRICK(0);}
else if (TINYJOYPAD_LEFT==0) {ORIy_TTRICK=16;Speed_adj_H_N_TTRICK(0);}else{ORIy_TTRICK=0;Speed_H_Decel_TTRICK(0);}
Adjust_Cumule_Speed_TTRICK(0);
Player1_Rotate_TTRICK=Direction_Recupe_TTRICK(ORIy_TTRICK+ORIx_TTRICK);
if (BUTTON_DOWN) {if ((Drag_Puck_TTRICK==0)&&(sprite_TTRICK[2].Xpos<119)) {KICK_PUCK_TTRICK(Player1_Rotate_TTRICK);}}
collision_check_LimiteScreen_TTRICK(0);
COM_MAX_SPEED_x_TTRICK=Adjust_Speed_Computer_TTRICK(X_Drag_TTRICK,sprite_TTRICK[1].Xpos);
COM_MAX_SPEED_y_TTRICK=Adjust_Speed_Computer_TTRICK(Y_drag_TTRICK,sprite_TTRICK[1].Ypos);
Computer_Rotate_TTRICK=Update_Computer_Direction_TTRICK(); 
if ((sprite_TTRICK[2].Ypos+1)>(sprite_TTRICK[4].Ypos+5)) {Goal_Adj_TTRICK(1,4);}
if ((sprite_TTRICK[2].Ypos+1)<(sprite_TTRICK[4].Ypos+5)) {Goal_Adj_TTRICK(0,4);} 
Adjust_Cumule_Speed_TTRICK(1);
collision_check_LimiteScreen_TTRICK(1);
if (collision_check_Sprite2Sprite_TTRICK(0,1)) {BOUNCE_SPRITE_TTRICK();SND_TTRICK(2);}
Speed_Puck_Decel_TTRICK(2);
Adjust_Cumule_Speed_TTRICK(2);
Drag_Puck_TTRICK_test();
Drag_Puck_Update_TTRICK();

while((currentMillis-MemMillis)<Frame_rate_TTRICK){
currentMillis=millis();
}
MemMillis=currentMillis;

Tiny_Flip_TTRICK();
collision_check_LimiteScreen_TTRICK(2);
  if ((Drag_Puck_TTRICK==1)&&(sprite_TTRICK[1].Xpos<48)&&((Computer_Rotate_TTRICK>=3)&&(Computer_Rotate_TTRICK<=5))) {if ((sprite_TTRICK[2].Xpos>8)) {KICK_PUCK_TTRICK(Computer_Rotate_TTRICK);}}
  if (GOAL_TTRICK!=255) {
   GOAL_TTRICK=255;
   SND_TTRICK(1); 
   Drag_Puck_TTRICK=255;
   if (Points_CPU_TTRICK==10) {intro_TTRICK(3,0);SND_TTRICK(6);My_delay_ms(1000);My_delay_ms(1000);goto INTRO;}
   else if (Points_Pl1_TTRICK==10) {intro_TTRICK(2,0);SND_TTRICK(5);My_delay_ms(1000);My_delay_ms(1000);goto INTRO;}
   else{SCREEN_GOAL_TTRICK();} 
   goto RESTART;
    }
SKIP_FRAME_TTRICK=!SKIP_FRAME_TTRICK;
}}
////////////////////////////////// main end /////////////////////////////////

uint8_t check_Puck2Gard_TTRICK(uint8_t Gard){
#define X1 (sprite_TTRICK[2].Xpos)
#define Y1 (sprite_TTRICK[2].Ypos)
#define D1 2
#define X2 ((sprite_TTRICK[Gard].Xpos)+1)
#define Y2 ((sprite_TTRICK[Gard].Ypos)+1)
#define D2x 3 
#define D2y 7 
if ((X1>(X2+D2x))||((X1+D1)<X2)||(Y1>(Y2+D2y))||((Y1+D1)<Y2)) {return 0;}
return 1;
}

uint8_t GOAL_FUNCTION_TTRICK(uint8_t Goal_0,uint8_t Goal_1){
#define Xt1 (sprite_TTRICK[2].Xpos)
if (Drag_Puck_TTRICK==255){
if (Xt1<64) {
if ((Xt1+2)<=(sprite_TTRICK[3].Xpos+1)&&(Goal_0==0)) {GOAL_TTRICK=1;Points_CPU_TTRICK++;} }else{
if (((Xt1)>=((sprite_TTRICK[4].Xpos+5)-1))&&(Goal_1==0)) {GOAL_TTRICK=0;Points_Pl1_TTRICK++;} }
}
return 1;
}

void Reverse_x_puck_2_pos_TTRICK(uint8_t SpriteTested){
 
  if (sprite_TTRICK[SpriteTested].SpeedXpositif==0) {
    Reverse_x_pla_TTRICK(SpriteTested);
}
}

void Reverse_x_puck_2_neg_TTRICK(uint8_t SpriteTested){
 if (sprite_TTRICK[SpriteTested].SpeedXnegatif==0) {
 Reverse_x_pla_TTRICK(SpriteTested);
}}

uint8_t collision_check_LimiteScreen_TTRICK(uint8_t SpriteTested){
uint8_t Gar0=0,Gar1=0;
#define XX sprite_TTRICK[SpriteTested].Xpos
#define YY sprite_TTRICK[SpriteTested].Ypos
if (SpriteTested==2) {
if (check_Puck2Gard_TTRICK(3)) {Gar0=1;Reverse_x_puck_2_pos_TTRICK(2);}
if (check_Puck2Gard_TTRICK(4)) {Gar1=1;Reverse_x_puck_2_neg_TTRICK(2);}
if ((YY>=23)&&(YY<=38)) {if (GOAL_FUNCTION_TTRICK(Gar0,Gar1)) {return 0;}}
}
#define DIM (pgm_read_byte(&PLAYER_DIM_TTRICK[SpriteTested])*2)
if (XX<=4) {XX+=2;goto X_X;}
if ((XX+DIM)>=122) {XX-=2;goto X_X;}
if (YY<=4) {YY+=2;goto Y_Y;}
if ((YY+DIM)>=56) {YY-=2;goto Y_Y;}
return 0;
Y_Y:;
Reverse_y_pla_TTRICK(SpriteTested);
SND_TTRICK(3);
return 1;
X_X:;
Reverse_x_pla_TTRICK(SpriteTested);
SND_TTRICK(3);
return 1;
}

void KICK_PUCK_TTRICK(uint8_t Player_Rotate){
Drag_Puck_TTRICK=255;
uint8_t DXN=0;
uint8_t DYN=0;
uint8_t DXP=0;
uint8_t DYP=0;
#define SPD 46
switch(Player_Rotate){
  case(0):DXP=SPD;break;
  case(1):DXP=SPD;DYP=SPD;break;
  case(2):DYP=SPD;break;
  case(3):DYP=SPD;DXN=SPD;break;
  case(4):DXN=SPD;break;
  case(5):DXN=SPD;DYN=SPD;break;
  case(6):DYN=SPD;break;
  case(7):DXP=SPD;DYN=SPD;break;
  default:break;
}
sprite_TTRICK[2].SpeedXnegatif=DXN;
sprite_TTRICK[2].SpeedXpositif=DXP; 
sprite_TTRICK[2].SpeedYnegatif=DYN;
sprite_TTRICK[2].SpeedYpositif=DYP;
SND_TTRICK(4);
}

void Drag_Puck_Update_TTRICK(void){
uint8_t Rot;
if (Drag_Puck_TTRICK!=255) {  
Rot=(Drag_Puck_TTRICK==0)?Player1_Rotate_TTRICK:Computer_Rotate_TTRICK;
Puck_x_TTRICK=sprite_TTRICK[Drag_Puck_TTRICK].Xpos;
Puck_y_TTRICK=sprite_TTRICK[Drag_Puck_TTRICK].Ypos; 
sprite_TTRICK[2].Xpos=Puck_x_TTRICK+pgm_read_byte(&PLAYER_Puck_TTRICK[(Rot*2)]);
sprite_TTRICK[2].Ypos=Puck_y_TTRICK+pgm_read_byte(&PLAYER_Puck_TTRICK[(Rot*2)+1]);
}else{
Puck_x_TTRICK=sprite_TTRICK[2].Xpos;
Puck_y_TTRICK=sprite_TTRICK[2].Ypos;
}}

void Drag_Puck_TTRICK_test(void){
if (SKIP_FRAME_TTRICK==0) {
if (collision_check_Sprite2Sprite_TTRICK(2,0)) {
 Drag_Puck_TTRICK=0; 
  }}else{  
if (collision_check_Sprite2Sprite_TTRICK(2,1)) {
 Drag_Puck_TTRICK=1; 
  }} 
}

void Speed_Puck_Decel_TTRICK(uint8_t SPR_TYPE){
if (sprite_TTRICK[SPR_TYPE].SpeedXpositif>0) {sprite_TTRICK[SPR_TYPE].SpeedXpositif-=1;}
if (sprite_TTRICK[SPR_TYPE].SpeedXnegatif>0) {sprite_TTRICK[SPR_TYPE].SpeedXnegatif-=1;}
if (sprite_TTRICK[SPR_TYPE].SpeedYpositif>0) {sprite_TTRICK[SPR_TYPE].SpeedYpositif-=1;}
if (sprite_TTRICK[SPR_TYPE].SpeedYnegatif>0) {sprite_TTRICK[SPR_TYPE].SpeedYnegatif-=1;}
}

void BOUNCE_SPRITE_TTRICK(void){
if (sprite_TTRICK[0].Xpos<sprite_TTRICK[1].Xpos) {
if (sprite_TTRICK[0].SpeedXnegatif==0) {
Reverse_x_pla_TTRICK(0);
}
if (sprite_TTRICK[1].SpeedXpositif==0) {
Reverse_x_pla_TTRICK(1);
}}else{
if (sprite_TTRICK[0].SpeedXpositif==0) {
Reverse_x_pla_TTRICK(0);
}
if (sprite_TTRICK[1].SpeedXnegatif==0) {
Reverse_x_pla_TTRICK(1);
}}
if (sprite_TTRICK[0].Ypos<sprite_TTRICK[1].Ypos) {
if (sprite_TTRICK[0].SpeedYnegatif==0) {
Reverse_y_pla_TTRICK(0);
}
if (sprite_TTRICK[1].SpeedYpositif==0) {
Reverse_y_pla_TTRICK(1);
}
}else{
  if (sprite_TTRICK[0].SpeedYpositif==0) {
Reverse_y_pla_TTRICK(0);
}
if (sprite_TTRICK[1].SpeedYnegatif==0) {
Reverse_y_pla_TTRICK(1);
}}
}

void Reverse_y_pla_TTRICK(uint8_t SpriteTested){
uint8_t temp=sprite_TTRICK[SpriteTested].SpeedYnegatif;
sprite_TTRICK[SpriteTested].SpeedYnegatif=sprite_TTRICK[SpriteTested].SpeedYpositif;
sprite_TTRICK[SpriteTested].SpeedYpositif=temp; 
}

void Reverse_x_pla_TTRICK(uint8_t SpriteTested){
uint8_t temp=sprite_TTRICK[SpriteTested].SpeedXnegatif;
sprite_TTRICK[SpriteTested].SpeedXnegatif=sprite_TTRICK[SpriteTested].SpeedXpositif;
sprite_TTRICK[SpriteTested].SpeedXpositif=temp; 
}

uint8_t collision_check_Sprite2Sprite_TTRICK(uint8_t Sp_1,uint8_t Sp_2){
uint8_t EXCEP=(Sp_1==2)?0:5;
uint8_t EXCEP2=(Sp_1==2)?2:1;
#define XX_ (sprite_TTRICK[Sp_1].Xpos+EXCEP)
#define YY_ (sprite_TTRICK[Sp_1].Ypos+EXCEP)
#define DIM_ (pgm_read_byte(&PLAYER_DIM_TTRICK[Sp_1])*EXCEP2)
#define XX2_ (sprite_TTRICK[Sp_2].Xpos+EXCEP)
#define YY2_ (sprite_TTRICK[Sp_2].Ypos+EXCEP)
#define DIM2_ (pgm_read_byte(&PLAYER_DIM_TTRICK[Sp_2])*EXCEP2)  
if (XX_>(XX2_+DIM2_)) {return 0;}
if ((XX_+DIM_)<XX2_) {return 0;}
if (YY_>(YY2_+DIM2_)) {return 0;}
if ((YY_+DIM_)<YY2_) {return 0;}
return 1;
}

uint8_t Computer_rotation_filter_update_TTRICK(void){
uint8_t Direct_x=0;
uint8_t Direct_y=0;
uint8_t Mem_X_HIGH=0;
uint8_t Mem_Y_HIGH=0;
#define XP sprite_TTRICK[1].SpeedXpositif
#define XN sprite_TTRICK[1].SpeedXnegatif
#define YP sprite_TTRICK[1].SpeedYpositif
#define YN sprite_TTRICK[1].SpeedYnegatif
if (XP>XN) {Mem_X_HIGH=XP;Direct_x=4;}else{Direct_x=16;Mem_X_HIGH=XN;}
if (YP>YN) {Mem_Y_HIGH=YP;Direct_y=8;}else{Direct_y=2;Mem_Y_HIGH=YN;}
if (Mem_X_HIGH>Mem_Y_HIGH) {
 if ((Mem_X_HIGH-Mem_Y_HIGH)<14) {return Direction_Recupe_TTRICK(Direct_x+Direct_y);}else{return Direction_Recupe_TTRICK(Direct_x);}
  }else{
 if ((Mem_Y_HIGH-Mem_X_HIGH)<14) {return Direction_Recupe_TTRICK(Direct_x+Direct_y);}else{return Direction_Recupe_TTRICK(Direct_y);}
  }
}

uint8_t Direction_Recupe_TTRICK(uint8_t Con){
switch(Con){
  case(4):return 0;break;
  case(12):return 1;break;
  case(8):return 2;break;
  case(24):return 3;break;
  case(16):return 4;break;
  case(18):return 5;break;
  case(2):return 6;break;
  case(6):return 7;break;
  default:return Player1_Rotate_TTRICK;break;
}
return 0;
}

uint8_t Update_Computer_Direction_TTRICK(void){
#define W_PL2 pgm_read_byte(&PLAYER_DIM_TTRICK[1])
if (Drag_Puck_TTRICK==1) {
X_Drag_TTRICK=0;
Y_drag_TTRICK=30;
}else{
X_Drag_TTRICK=Puck_x_TTRICK;
Y_drag_TTRICK=Puck_y_TTRICK;}
if ((sprite_TTRICK[1].Xpos+W_PL2)<X_Drag_TTRICK) {Speed_adj_H_P_TTRICK(1);}else{Speed_adj_H_N_TTRICK(1);}
if ((sprite_TTRICK[1].Ypos+W_PL2)<Y_drag_TTRICK) {Speed_adj_V_P_TTRICK(1);}else{Speed_adj_V_N_TTRICK(1);}
return Computer_rotation_filter_update_TTRICK();
}

void Speed_H_Decel_TTRICK(uint8_t SPR_TYPE){
if (sprite_TTRICK[SPR_TYPE].SpeedXpositif>0) {sprite_TTRICK[SPR_TYPE].SpeedXpositif-=2;}
if (sprite_TTRICK[SPR_TYPE].SpeedXnegatif>0) {sprite_TTRICK[SPR_TYPE].SpeedXnegatif-=2;}
}

void Speed_V_Decel_TTRICK(uint8_t SPR_TYPE){
if (sprite_TTRICK[SPR_TYPE].SpeedYpositif>0) {sprite_TTRICK[SPR_TYPE].SpeedYpositif-=2;}
if (sprite_TTRICK[SPR_TYPE].SpeedYnegatif>0) {sprite_TTRICK[SPR_TYPE].SpeedYnegatif-=2;}
}

uint8_t Adjust_Speed_Computer_TTRICK(uint8_t Puck,uint8_t Val_Computer_2){
if (Val_Computer_2>Puck)  {
return ((Val_Computer_2-Puck)>10)?28:16;   
}else{return ((Puck-Val_Computer_2)>10)?28:16;     
}}

void Adjust_Cumule_Speed_TTRICK(uint8_t SPRITE_NO){
uint8_t MAX_SPEED=3;
if (SPRITE_NO==2) {MAX_SPEED=5;}
for(uint8_t t=0;t<MAX_SPEED;t++){
if (sprite_TTRICK[SPRITE_NO].SpeedXpositif>0) {
  if (t==0) {sprite_TTRICK[SPRITE_NO].CumuleX=sprite_TTRICK[SPRITE_NO].CumuleX+sprite_TTRICK[SPRITE_NO].SpeedXpositif;}
  if (sprite_TTRICK[SPRITE_NO].CumuleX>=10) {sprite_TTRICK[SPRITE_NO].CumuleX=sprite_TTRICK[SPRITE_NO].CumuleX-10;if (sprite_TTRICK[SPRITE_NO].Xpos<126) {sprite_TTRICK[SPRITE_NO].Xpos++;}}
}else if (sprite_TTRICK[SPRITE_NO].SpeedXnegatif>0) {
    if (t==0) {sprite_TTRICK[SPRITE_NO].CumuleX=sprite_TTRICK[SPRITE_NO].CumuleX+sprite_TTRICK[SPRITE_NO].SpeedXnegatif;}
  if (sprite_TTRICK[SPRITE_NO].CumuleX>=10) {sprite_TTRICK[SPRITE_NO].CumuleX=sprite_TTRICK[SPRITE_NO].CumuleX-10;if (sprite_TTRICK[SPRITE_NO].Xpos>0) {sprite_TTRICK[SPRITE_NO].Xpos--;}}
}else{sprite_TTRICK[SPRITE_NO].CumuleX=0;}
if (sprite_TTRICK[SPRITE_NO].SpeedYpositif>0) {
  if (t==0) {sprite_TTRICK[SPRITE_NO].CumuleY=sprite_TTRICK[SPRITE_NO].CumuleY+sprite_TTRICK[SPRITE_NO].SpeedYpositif;}
  if (sprite_TTRICK[SPRITE_NO].CumuleY>=10) {sprite_TTRICK[SPRITE_NO].CumuleY=sprite_TTRICK[SPRITE_NO].CumuleY-10;if (sprite_TTRICK[SPRITE_NO].Ypos<61) {sprite_TTRICK[SPRITE_NO].Ypos++;}}
}else if (sprite_TTRICK[SPRITE_NO].SpeedYnegatif>0) {
if (t==0) {sprite_TTRICK[SPRITE_NO].CumuleY=sprite_TTRICK[SPRITE_NO].CumuleY+sprite_TTRICK[SPRITE_NO].SpeedYnegatif;}
  if (sprite_TTRICK[SPRITE_NO].CumuleY>=10) {sprite_TTRICK[SPRITE_NO].CumuleY=sprite_TTRICK[SPRITE_NO].CumuleY-10;if (sprite_TTRICK[SPRITE_NO].Ypos>0) {sprite_TTRICK[SPRITE_NO].Ypos--;}}
}else{sprite_TTRICK[SPRITE_NO].CumuleY=0;}
}}

void Speed_adj_H_P_TTRICK(uint8_t SPRITE_NO){
if (sprite_TTRICK[SPRITE_NO].SpeedXnegatif==0) {if (sprite_TTRICK[SPRITE_NO].SpeedXpositif<COM_MAX_SPEED_x_TTRICK) {sprite_TTRICK[SPRITE_NO].SpeedXpositif=sprite_TTRICK[SPRITE_NO].SpeedXpositif+2;}}else{
sprite_TTRICK[SPRITE_NO].SpeedXnegatif=sprite_TTRICK[SPRITE_NO].SpeedXnegatif-2;  
}}

void Speed_adj_H_N_TTRICK(uint8_t SPRITE_NO){
if (sprite_TTRICK[SPRITE_NO].SpeedXpositif==0) {if (sprite_TTRICK[SPRITE_NO].SpeedXnegatif<COM_MAX_SPEED_x_TTRICK) {sprite_TTRICK[SPRITE_NO].SpeedXnegatif=sprite_TTRICK[SPRITE_NO].SpeedXnegatif+2;}}else{
sprite_TTRICK[SPRITE_NO].SpeedXpositif=sprite_TTRICK[SPRITE_NO].SpeedXpositif-2;  
}}

void Speed_adj_V_P_TTRICK(uint8_t SPRITE_NO){
if (sprite_TTRICK[SPRITE_NO].SpeedYnegatif==0) {if (sprite_TTRICK[SPRITE_NO].SpeedYpositif<COM_MAX_SPEED_y_TTRICK) {sprite_TTRICK[SPRITE_NO].SpeedYpositif=sprite_TTRICK[SPRITE_NO].SpeedYpositif+2;}}else{
sprite_TTRICK[SPRITE_NO].SpeedYnegatif=sprite_TTRICK[SPRITE_NO].SpeedYnegatif-2;  
}}

void Speed_adj_V_N_TTRICK(uint8_t SPRITE_NO){
if (sprite_TTRICK[SPRITE_NO].SpeedYpositif==0) {if (sprite_TTRICK[SPRITE_NO].SpeedYnegatif<COM_MAX_SPEED_y_TTRICK) {sprite_TTRICK[SPRITE_NO].SpeedYnegatif=sprite_TTRICK[SPRITE_NO].SpeedYnegatif+2;}}else{
sprite_TTRICK[SPRITE_NO].SpeedYpositif=sprite_TTRICK[SPRITE_NO].SpeedYpositif-2;  
}}

uint8_t blitzSprite_TTRICK(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES){
uint8_t OUTBYTE;
uint8_t WSPRITE=(pgm_read_byte(&SPRITES[0]));
uint8_t HSPRITE=(pgm_read_byte(&SPRITES[1]));
uint8_t Wmax ((HSPRITE*WSPRITE)+1);
uint16_t PICBYTE=FRAME*(Wmax-1);
uint8_t RECUPELINEY=RecupeLineY_TTRICK(yPos);
if ((xPASS>((xPos+(WSPRITE-1))))||(xPASS<xPos)||((RECUPELINEY>yPASS)||((RECUPELINEY+(HSPRITE))<yPASS))) {return 0x00;}
uint8_t SPRITEyLINE=(yPASS-(RECUPELINEY));
uint8_t SPRITEyDECALAGE=(RecupeDecalageY_TTRICK(yPos));
uint8_t ScanA=(((xPASS-xPos)+(SPRITEyLINE*WSPRITE))+2);
uint8_t ScanB=(((xPASS-xPos)+((SPRITEyLINE-1)*WSPRITE))+2);
if (ScanA>Wmax) {OUTBYTE=0x00;}else{OUTBYTE=SplitSpriteDecalageY_TTRICK(SPRITEyDECALAGE,pgm_read_byte(&SPRITES[ScanA+(PICBYTE)]),1);}
if ((SPRITEyLINE>0)) {
uint8_t OUTBYTE2=SplitSpriteDecalageY_TTRICK(SPRITEyDECALAGE,pgm_read_byte(&SPRITES[ScanB+(PICBYTE)]),0);
if (ScanB>Wmax) {return OUTBYTE;}else{return OUTBYTE|OUTBYTE2;}
}else{return OUTBYTE;}
}

uint8_t Recupe_TTRICK(uint8_t xPASS,uint8_t yPASS){
 #define XP1 sprite_TTRICK[0].Xpos   
 #define YP1 sprite_TTRICK[0].Ypos 
 #define XP2 sprite_TTRICK[1].Xpos 
 #define YP2 sprite_TTRICK[1].Ypos
 #define XP3 sprite_TTRICK[2].Xpos   
 #define YP3 sprite_TTRICK[2].Ypos 
 #define XP4 sprite_TTRICK[3].Xpos 
 #define YP4 sprite_TTRICK[3].Ypos
 #define XP5 sprite_TTRICK[4].Xpos 
 #define YP5 sprite_TTRICK[4].Ypos
return (Patinoire1_2_TTRICK(xPASS,yPASS))
  &((0xff-blitzSprite_TTRICK(XP1,YP1,xPASS,yPASS,Player1_Rotate_TTRICK,PLAYER_WHITE_B_TTRICK)))
  &((0xff-blitzSprite_TTRICK(XP4,YP4,xPASS,yPASS,0,GOALER_WHITE_TTRICK)))
  &((0xff-blitzSprite_TTRICK(XP3,YP3,xPASS,yPASS,0,puck_TTRICK)))
  &((0xff-blitzSprite_TTRICK(XP5,YP5,xPASS,yPASS,0,GOALER_BLACK_TTRICK)))
  &(0xff-blitzSprite_TTRICK(XP2,YP2,xPASS,yPASS,Computer_Rotate_TTRICK,PLAYER_BLACK_B_TTRICK));
}

uint8_t Patinoire1_2_TTRICK(uint8_t xPASS,uint8_t yPASS){
if (xPASS>63) {return pgm_read_byte(&patinoire1_2_TTRICK[(127-xPASS)+(yPASS*64)]);}
return pgm_read_byte(&patinoire1_2_TTRICK[(xPASS)+(yPASS*64)]); 
}

uint8_t SplitSpriteDecalageY_TTRICK(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN){
if (UPorDOWN) {return Input<<decalage;}
return Input>>(8-decalage);
}

uint8_t RecupeLineY_TTRICK(uint8_t Valeur){
return (Valeur>>3); 
}

uint8_t RecupeDecalageY_TTRICK(uint8_t Valeur){
return (Valeur-((Valeur>>3)*8));
}
#define VAR_16 (x+(y*128))
void Tiny_Flip_TTRICK(void){
uint8_t y,x; 
for (y = 0; y < 8; y++){ 

for (x = 0; x < 128; x++){

 display.buffer[VAR_16] =(Recupe_TTRICK(x,y));}

}
display.display();  
}

void intro_TTRICK(uint8_t GOAL_TTRICKSCREEN,uint8_t SLIDE){
uint8_t y,x;

for (y = 0; y < 8; y++){ 
for (x = 0; x < 128; x++){
  
switch(GOAL_TTRICKSCREEN){
  case 0:display.buffer[VAR_16] =((pgm_read_byte(&Intro_TTRICK[(x)+(y*128)])|blitzSprite_TTRICK(40,39,x,y,0,cadre40_37_TTRICK)));break;
  case 1:display.buffer[VAR_16] =(((Recupe_TTRICK(x,y)|(blitzSprite_TTRICK(40,39+SLIDE,x,y,0,screen_TTRICK)))&(0xff-blitzSprite_TTRICK(40,39+SLIDE,x,y,1,screen_TTRICK)))|(blitzSprite_TTRICK(40+(13),39+SLIDE+(13),x,y,Points_Pl1_TTRICK,NUM_TTRICK)|blitzSprite_TTRICK(40+(33),39+SLIDE+(13),x,y,Points_CPU_TTRICK,NUM_TTRICK)));break;
  case 2:display.buffer[VAR_16] =(Lost_win_TTRICK(x,y,win_TTRICK));break;
  case 3:display.buffer[VAR_16] =(Lost_win_TTRICK(x,y,lost_TTRICK));break;
  case 4:display.buffer[VAR_16] =(pgm_read_byte(&Intro_TTRICK[(x)+(y*128)]));break;
  default:break;
}}

}
display.display();  

}

uint8_t Lost_win_TTRICK(uint8_t xPASS,uint8_t yPASS,const uint8_t *SPRITES ){
return (((Recupe_TTRICK(xPASS,yPASS)|(blitzSprite_TTRICK(48,27,xPASS,yPASS,0,SPRITES))))&(0xff-blitzSprite_TTRICK(48,27,xPASS,yPASS,1,SPRITES)));
}

void SCREEN_GOAL_TTRICK(void){
uint8_t t;
for (t=6;t>0;t--){
My_delay_ms(33);
intro_TTRICK(1,t*4);}
My_delay_ms(900);
for (t=1;t<8;t++){
My_delay_ms(33);
intro_TTRICK(1,t*4);}
My_delay_ms(400);
}


void Sound_TTRICK(uint8_t freq_,uint8_t dur){
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
