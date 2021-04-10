//     >>>>>  MEGA COMPILATION for ESP8266/ESP8285  GPL v3 <<<<
//                    >>>>>  MEGA Tiny Joypad  <<<<
//                      Programmer: Daniel C 2019
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

#include "spritebank_TBIKE.h"

#define Frame_Rate_TBIKE 0
#define NUMofSPRITE 2


uint8_t ReWind_TBIKE=0;
uint8_t End_game_TBIKE=0;
int8_t Live_TBIKE=3;
uint8_t Progress_bar_Interval_TBIKE;
uint8_t Progress_bar_Interval_TBIKE_timer;
uint8_t Progress_bar_value_TBIKE;
uint8_t Time_bar_Interval_TBIKE;
uint8_t Time_bar_Interval_TBIKE_timer;
uint8_t Time_bar_value_TBIKE;
uint8_t CLIMB_ACTIVATE_TBIKE=0;
float Higher_jump_TBIKE=0;
float ADD_PILL_TBIKE=0;
float Jump_dinamic_duration_TBIKE;
uint8_t PLANCHER_TBIKE;
uint8_t PLANCHER_TBIKE_add;
int8_t TRANSITION_TRACK_TBIKE=0;
uint8_t ENDMAP_TBIKE=0;
uint8_t LINE_Y_TBIKE;
uint8_t DECALAGE_TBIKE;
uint8_t DIV1_TBIKE=0;
float ACCEL_TBIKE=0;
uint8_t trackrun_TBIKE=2;
uint8_t Trackrun_progress_TBIKE=2;
float gravity_expo_TBIKE=0;
uint8_t BIKE_POSy_TBIKE=33;
uint8_t TRIG_OK_TBIKE=0;
uint16_t MAP_POS_TBIKE=0;
uint8_t animBike_TBIKE=1;
uint8_t RENEW_SPRITE_TBIKE=0;
uint8_t NoSprite_TBIKE=0;
uint8_t FOUL_BLITZ_TBIKE=0;
uint8_t VAR_SCROLL1_TBIKE=0;
uint8_t VAR_SCROLL2_TBIKE=0;
uint8_t VAR_SCROLL3_TBIKE=0;
uint8_t Not_Move_TBIKE=0;
uint8_t Not_Turn_TBIKE=0;
uint8_t Wheel_up_TBIKE=1;
uint8_t FREEAIR_TBIKE=0;
uint8_t BypassWheelupreset_TBIKE=0;
uint8_t Latch1_TBIKE=0;
uint8_t PLANTAGE_0_TBIKE=0;
uint8_t Pause_TBIKE=0;
Sprite_TBIKE sprite_TBIKE[NUMofSPRITE];
const uint8_t *INTROPIC_TBIKE;


void ResetSprite_TBIKE(void);
void intro_sound_TBIKE(void);
void End_Line_Win_sound_TBIKE(void);
void restore_start_line_TBIKE(void);
void Next_Level_TBIKE(void);
void RESET_FOR_NEW_GAME_TBIKE(void);
void Pause1_TBIKE(void);
uint8_t GAME_PLAY_TBIKE(void);
void TIME_TRACK_TBIKE(void);
void PLANTAGE_TBIKE(void);
void Higher_adj_TBIKE(uint8_t test);
void dinamic_adj_TBIKE(void);
void GRAVITY_ADJ_TBIKE(void);
void JUMP_ADJ_TBIKE(void);
void CheckCollision_TBIKE(void);
uint8_t  Trouver_Sprite_Collisionner_TBIKE(void);
void analise_minutieuse_TBIKE(void);
void ADD_LIVE_TBIKE(uint8_t SPR);
void CLIMB_ADJ3_TBIKE(void);
void Break_Gravity_TBIKE(void);
void CLIMB_ADJ0_TBIKE(void);
void CLIMB_ADJ1_TBIKE(void);
void CLIMB_ADJ2_TBIKE(void);
uint8_t RECUPE_X_SPRITE_TBIKE(uint8_t Type_Sprite);
uint8_t CHECK_SPEED_ADJ_TBIKE(float REC_INT);
void TRACK_RUN_ADJ_TBIKE(void);
uint8_t RECUPE_MAP_BYTE_TBIKE(const uint8_t *Level);
uint8_t SPLIT_MAP_BYTE_TBIKE(uint8_t BYTE,uint8_t L0_R1);
void RefreshPosSprite_TBIKE(void);
void INCREMENTE_SCROLL_TBIKE(void);
uint8_t CREATE_NEWSPRITE_TBIKE(void);
uint8_t  BACKGROUND_TBIKE(uint8_t xPASS,uint8_t yPASS);
uint8_t TOPBACK_TBIKE(uint8_t xPASS,uint8_t yPASS);
uint8_t FOUL1_TBIKE(void);
uint8_t GRADIN23_TBIKE(uint8_t yPASS);
uint8_t TIRE4_TBIKE(void);
uint8_t ROAD567_TBIKE(uint8_t yPASS);
uint8_t TABLEAU8_TBIKE(uint8_t xPASS);
uint8_t Return_live_TBIKE(uint8_t xPASS);
uint8_t Return_time_TBIKE(uint8_t xPASS);
uint8_t Return_Progress_TBIKE(uint8_t xPASS);
void AdjustVarScroll_TBIKE(void);
uint8_t Recupe_TBIKE(uint8_t xPASS,uint8_t yPASS);
uint8_t BLITZ_SPRITE_MAP_TBIKE(uint8_t xPASS,uint8_t yPASS);
uint8_t BIGSTEP_SPRITE_TBIKE(uint8_t numSprite,uint8_t xPASS,uint8_t yPASS);
uint8_t MINISTEP_SPRITE_TBIKE(uint8_t numSprite,uint8_t xPASS,uint8_t yPASS);
uint8_t Plantage_TBIKE(uint8_t numSprite,uint8_t xPASS,uint8_t yPASS);
uint8_t HUILE_SPRITE_TBIKE(uint8_t numSprite,uint8_t xPASS,uint8_t yPASS);
uint8_t LINE_SPRITE_TBIKE(uint8_t numSprite,uint8_t xPASS,uint8_t yPASS);
uint8_t START_SPRITE_TBIKE(uint8_t numSprite,uint8_t xPASS,uint8_t yPASS);
uint8_t SPEED_SPRITE_TBIKE(uint8_t numSprite,uint8_t xPASS,uint8_t yPASS);
uint8_t NEW_LIVE_TBIKE(uint8_t numSprite,uint8_t xPASS,uint8_t yPASS);
uint8_t BIKE_SPRITE_TBIKE(uint8_t xPASS,uint8_t yPASS);
uint8_t blitzSprite_TBIKE(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES);
void RecupeDecalageY_TBIKE(uint8_t Valeur);
void Tiny_Flip_TBIKE(uint8_t MODE);
uint8_t SplitSpriteDecalageY_TBIKE(uint8_t DECALAGE_TBIKE,uint8_t Input,uint8_t UPorDOWN);
void Sound_TBIKE(uint8_t freq,uint8_t dur);


void ResetSprite_TBIKE(void){
for (uint8_t t=0;t<NUMofSPRITE;t++){
sprite_TBIKE[t].ACTIVE=0;
sprite_TBIKE[t].TypeofSprite=0;
sprite_TBIKE[t].xPOS=0;
sprite_TBIKE[t].yPOS=0;
sprite_TBIKE[t].Y_START=0;
sprite_TBIKE[t].Y_END=0;
}}


void intro_sound_TBIKE(void){
Sound_TBIKE(100,255); 
My_delay_ms(400); 
Sound_TBIKE(100,255); 
My_delay_ms(400); 
Sound_TBIKE(100,255); 
My_delay_ms(400); 
Sound_TBIKE(155,255); 
Sound_TBIKE(155,255);
Sound_TBIKE(155,255); 
Sound_TBIKE(155,255); 

}

void End_Line_Win_sound_TBIKE(void){
for(uint8_t t=0;t<5;t++){
  Sound_TBIKE (100,100);
  Sound_TBIKE (1,100);}
}

void restore_start_line_TBIKE(void){
sprite_TBIKE[0].ACTIVE=1;
sprite_TBIKE[0].TypeofSprite=5;  
sprite_TBIKE[0].xPOS=36;  
sprite_TBIKE[0].yPOS=32;
}

void Next_Level_TBIKE(void){
ENDMAP_TBIKE=0;
CLIMB_ACTIVATE_TBIKE=0;
Higher_jump_TBIKE=0;
ADD_PILL_TBIKE=0;
TRANSITION_TRACK_TBIKE=0;
DIV1_TBIKE=0;
ACCEL_TBIKE=0;
trackrun_TBIKE=2;
Trackrun_progress_TBIKE=2;
gravity_expo_TBIKE=0;
BIKE_POSy_TBIKE=33;
TRIG_OK_TBIKE=0;
animBike_TBIKE=1;
RENEW_SPRITE_TBIKE=0;
NoSprite_TBIKE=0;
FOUL_BLITZ_TBIKE=0;
VAR_SCROLL1_TBIKE=0;
VAR_SCROLL2_TBIKE=0;
VAR_SCROLL3_TBIKE=0;
Not_Move_TBIKE=0;
Not_Turn_TBIKE=0;
Wheel_up_TBIKE=1;
FREEAIR_TBIKE=0;
BypassWheelupreset_TBIKE=0;
Latch1_TBIKE=0;
PLANTAGE_0_TBIKE=0;
Pause_TBIKE=0;
if (ReWind_TBIKE==1) {ReWind_TBIKE=0;MAP_POS_TBIKE=0;}
if (MAP_POS_TBIKE!=0) {MAP_POS_TBIKE++;}
Progress_bar_Interval_TBIKE=pgm_read_byte(&Level0_TBIKE[MAP_POS_TBIKE]);
Progress_bar_Interval_TBIKE_timer=0;
Progress_bar_value_TBIKE=0;
MAP_POS_TBIKE++;
Time_bar_Interval_TBIKE=pgm_read_byte(&Level0_TBIKE[MAP_POS_TBIKE]);
Time_bar_Interval_TBIKE_timer=0;
Time_bar_value_TBIKE=0;
MAP_POS_TBIKE++;
INTROPIC_TBIKE=&NEXTRACE_TBIKE[0];
}

void RESET_FOR_NEW_GAME_TBIKE(void){
End_game_TBIKE=0;
Live_TBIKE=3;
Jump_dinamic_duration_TBIKE=0;
PLANCHER_TBIKE=0;
PLANCHER_TBIKE_add=0;
LINE_Y_TBIKE=0;
DECALAGE_TBIKE=0;
MAP_POS_TBIKE=0;
INTROPIC_TBIKE=&START_GAME_TBIKE[0];
}

void loop_TBIKE() {
New_Games:;
RESET_FOR_NEW_GAME_TBIKE();
ESP.wdtDisable();
ESP.wdtFeed();
while(1){
ESP.wdtFeed();
Tiny_Flip_TBIKE(2);
if ((BUTTON_DOWN)) {INTROPIC_TBIKE=&START_RACE_TBIKE[0];Sound_TBIKE(200,20);Sound_TBIKE(60,20);goto NEXT_LEVEL;}
}
NEXT_LEVEL:;
Tiny_Flip_TBIKE(2);
ESP.wdtDisable();
ESP.wdtFeed();
My_delay_ms(1000);
ESP.wdtDisable();
ESP.wdtFeed();
My_delay_ms(1000);
ResetSprite_TBIKE();
Next_Level_TBIKE();
NEW_START:;
if ((BUTTON_DOWN)) {goto NEW_START;}
uint8_t t=0;
restore_start_line_TBIKE();
Tiny_Flip_TBIKE(3);
intro_sound_TBIKE();
if ((BUTTON_DOWN)) {goto NEW_START;}
animBike_TBIKE=6;
ESP.wdtDisable();
ESP.wdtFeed();
while(1){
ESP.wdtFeed();
if (PLANTAGE_0_TBIKE==0){
if (TRIG_OK_TBIKE==0) {
if ((TINYJOYPAD_LEFT==0)&&(ACCEL_TBIKE>1)) {BypassWheelupreset_TBIKE=1;if ((Wheel_up_TBIKE<5)&&(Latch1_TBIKE==0)){Wheel_up_TBIKE++;}}
else if ((TINYJOYPAD_RIGHT==0)&&(ACCEL_TBIKE>1)) {BypassWheelupreset_TBIKE=1;if ((Wheel_up_TBIKE>0)&&(Latch1_TBIKE==0)){Wheel_up_TBIKE--;if ((Wheel_up_TBIKE==0)&&(FREEAIR_TBIKE==0)) {Wheel_up_TBIKE=1;} }}

if ((Not_Move_TBIKE==0)&&(Not_Turn_TBIKE==0)){
if ((TINYJOYPAD_DOWN==0)) {if (Trackrun_progress_TBIKE<3){Trackrun_progress_TBIKE++;TRIG_OK_TBIKE=1;}}
else if ((TINYJOYPAD_UP==0)) {if (Trackrun_progress_TBIKE>0){Trackrun_progress_TBIKE--;TRIG_OK_TBIKE=2; }}
}
if ((TRIG_OK_TBIKE==0)&&(Wheel_up_TBIKE==1)&&(t>0)) {animBike_TBIKE = (animBike_TBIKE==1) ? 6 : 1;}
}
if (((BUTTON_DOWN)&&(ENDMAP_TBIKE!=1))&&((FREEAIR_TBIKE==0)||(Wheel_up_TBIKE<=2))&&(End_game_TBIKE==0) ) {
  if (ACCEL_TBIKE<8){ACCEL_TBIKE=ACCEL_TBIKE+0.10;}
  }else{
    if (ACCEL_TBIKE>1){ACCEL_TBIKE=ACCEL_TBIKE-0.10;}BypassWheelupreset_TBIKE=0;
   if ((Wheel_up_TBIKE>1)&&(Latch1_TBIKE==0)&&(FREEAIR_TBIKE==0)){Wheel_up_TBIKE--;}
    }
if (BypassWheelupreset_TBIKE==0){
if ((Wheel_up_TBIKE>1)&&(Latch1_TBIKE==0)&&(FREEAIR_TBIKE==0)){Wheel_up_TBIKE--;}
}else{BypassWheelupreset_TBIKE=0;}
}else{PLANTAGE_TBIKE();}
dinamic_adj_TBIKE();
for (t=0;t<CHECK_SPEED_ADJ_TBIKE(ACCEL_TBIKE);t++){
  INCREMENTE_SCROLL_TBIKE();if (DIV1_TBIKE==3) { Sound_TBIKE(1,1);TRACK_RUN_ADJ_TBIKE();
  if (Wheel_up_TBIKE!=1) {animBike_TBIKE=Wheel_up_TBIKE;}
  DIV1_TBIKE=0;}else{DIV1_TBIKE++;}}
  if (Pause_TBIKE==1) {if (Live_TBIKE>-1) {Live_TBIKE--;}Pause_TBIKE=0;}
Latch1_TBIKE++;
if (Latch1_TBIKE==4){ Latch1_TBIKE=0;}
if (((FREEAIR_TBIKE==0)&&((Wheel_up_TBIKE==0)||(Wheel_up_TBIKE==5)))&&(PLANTAGE_0_TBIKE!=1)) {PLANTAGE_0_TBIKE=1;}
while((currentMillis-MemMillis)<Frame_Rate_TBIKE){
ESP.wdtFeed();
currentMillis=millis();
}
MemMillis=currentMillis;
Tiny_Flip_TBIKE(1);
TIME_TRACK_TBIKE();
if (ENDMAP_TBIKE==1) {if (ACCEL_TBIKE<=1) {End_Line_Win_sound_TBIKE();Pause1_TBIKE();End_game_TBIKE=0;ESP.wdtFeed();goto NEXT_LEVEL;}}
if (End_game_TBIKE==1) {if (ACCEL_TBIKE<=1) {Pause1_TBIKE();ESP.wdtFeed();goto New_Games;}}
GAME_PLAY_TBIKE();
}}
void Pause1_TBIKE(void){
ESP.wdtFeed();My_delay_ms(2000);
}


uint8_t GAME_PLAY_TBIKE(void){
if (Live_TBIKE==-1) {End_game_TBIKE=1;}
return 0;
}

void TIME_TRACK_TBIKE(void){
if (Time_bar_Interval_TBIKE_timer<Time_bar_Interval_TBIKE) {Time_bar_Interval_TBIKE_timer++;
}else{
  Time_bar_Interval_TBIKE_timer=0;
  if (Time_bar_value_TBIKE<34) {Time_bar_value_TBIKE++;}else{End_game_TBIKE=1;}
  }
}

void PLANTAGE_TBIKE(void){
if (ACCEL_TBIKE>1.4){ACCEL_TBIKE=ACCEL_TBIKE-0.10;}else{PLANTAGE_0_TBIKE=0;Wheel_up_TBIKE=1;Pause_TBIKE=1;goto EED;}
if (Wheel_up_TBIKE>0) {Wheel_up_TBIKE--;}else{Wheel_up_TBIKE=5;}
EED:;
}

void Higher_adj_TBIKE(uint8_t test){
switch(test){

  case(0):
  case(1):
  case(2):Higher_jump_TBIKE=0.24;break;
  case(3):
  case(4):
  case(5):Higher_jump_TBIKE=0.18;break;
  case(6):
  case(7):
  case(8):Higher_jump_TBIKE=0.046;break;
  default:  break;
}}

void dinamic_adj_TBIKE(void){
if (Jump_dinamic_duration_TBIKE!=0){
Not_Move_TBIKE=1;JUMP_ADJ_TBIKE();
}else{GRAVITY_ADJ_TBIKE();
CLIMB_ACTIVATE_TBIKE=0;
Not_Move_TBIKE=0;
}}

void GRAVITY_ADJ_TBIKE(void){
PLANCHER_TBIKE=pgm_read_byte(&STEP_BIKE_TRACKRUN_TBIKE[trackrun_TBIKE]);
if (trackrun_TBIKE==Trackrun_progress_TBIKE) {
if (BIKE_POSy_TBIKE<(PLANCHER_TBIKE-PLANCHER_TBIKE_add)) {BIKE_POSy_TBIKE=BIKE_POSy_TBIKE+gravity_expo_TBIKE;gravity_expo_TBIKE=gravity_expo_TBIKE+0.2;FREEAIR_TBIKE=1;}else{FREEAIR_TBIKE=0;Not_Turn_TBIKE=0;BIKE_POSy_TBIKE=PLANCHER_TBIKE-PLANCHER_TBIKE_add;gravity_expo_TBIKE=0;}
}
}

void JUMP_ADJ_TBIKE(void){
 if (Jump_dinamic_duration_TBIKE>=.24){ADD_PILL_TBIKE=ADD_PILL_TBIKE+Jump_dinamic_duration_TBIKE; Jump_dinamic_duration_TBIKE=Jump_dinamic_duration_TBIKE-Higher_jump_TBIKE;}else{ADD_PILL_TBIKE=0;Jump_dinamic_duration_TBIKE=0;}
 if (ADD_PILL_TBIKE>=1) {ADD_PILL_TBIKE=ADD_PILL_TBIKE-1;if (BIKE_POSy_TBIKE>0) {BIKE_POSy_TBIKE=BIKE_POSy_TBIKE-1;}}
}

void CheckCollision_TBIKE(void){
if (Trouver_Sprite_Collisionner_TBIKE()!=0) {
analise_minutieuse_TBIKE();Not_Move_TBIKE=1;}
}

uint8_t  Trouver_Sprite_Collisionner_TBIKE(void){
#define xBike 30
#define yBike BIKE_POSy_TBIKE+12
for(uint8_t t=0;t<NUMofSPRITE;t++){
if (sprite_TBIKE[t].ACTIVE!=0) {
if ((sprite_TBIKE[t].xPOS>xBike)||((sprite_TBIKE[t].xPOS+RECUPE_X_SPRITE_TBIKE(sprite_TBIKE[NoSprite_TBIKE].TypeofSprite))<xBike)||(trackrun_TBIKE>sprite_TBIKE[t].Y_END)||(trackrun_TBIKE<sprite_TBIKE[t].Y_START)) {goto TIEND;}
NoSprite_TBIKE=t;
goto Fin; 
TIEND:;
}}
return 0;
Fin:;
return 1;
}

void analise_minutieuse_TBIKE(void){
switch(sprite_TBIKE[NoSprite_TBIKE].TypeofSprite){
   case(1):CLIMB_ADJ0_TBIKE();break;
   case(2):CLIMB_ADJ1_TBIKE();break;
   case(3):if ((ACCEL_TBIKE>2)&&(FREEAIR_TBIKE==0)){ACCEL_TBIKE=ACCEL_TBIKE-0.20;}break;
   case(4):ENDMAP_TBIKE=1;Sound_TBIKE(200,4);break;
   case(5):break;
   case(6):CLIMB_ADJ2_TBIKE();break;
   case(7):CLIMB_ADJ3_TBIKE();break;
   case(8):if (FREEAIR_TBIKE==0) {ADD_LIVE_TBIKE(NoSprite_TBIKE);}break;
   default:break;
}}

void ADD_LIVE_TBIKE(uint8_t SPR){
sprite_TBIKE[SPR].ACTIVE=0;
if (Live_TBIKE<3) {Live_TBIKE++;}
Sound_TBIKE(60,4);
Sound_TBIKE(200,4);
Sound_TBIKE(120,4);
}

void CLIMB_ADJ3_TBIKE(void){
#define POS_JUMP (30-sprite_TBIKE[NoSprite_TBIKE].xPOS)
if ((POS_JUMP==0)&&(FREEAIR_TBIKE==0)) {PLANTAGE_0_TBIKE=1;}
}

void Break_Gravity_TBIKE(void){
if (POS_JUMP==0) {
gravity_expo_TBIKE=0;
if ((FREEAIR_TBIKE==0)&&(Wheel_up_TBIKE==1)) {if (ACCEL_TBIKE>5) {ACCEL_TBIKE=ACCEL_TBIKE-2;}}} 
}

void CLIMB_ADJ0_TBIKE(void){
#define POS_JUMP (30-sprite_TBIKE[NoSprite_TBIKE].xPOS)
Break_Gravity_TBIKE();
Wheel_up_TBIKE=3;
  if ((POS_JUMP)<11) {Not_Turn_TBIKE=1;CLIMB_ACTIVATE_TBIKE=1;PLANCHER_TBIKE_add++;}
  else if((POS_JUMP)>15) {PLANCHER_TBIKE_add--;}
}

void CLIMB_ADJ1_TBIKE(void){
#define POS_JUMP (30-sprite_TBIKE[NoSprite_TBIKE].xPOS)
Break_Gravity_TBIKE();
Wheel_up_TBIKE=3;
  if ((POS_JUMP)<5) {Not_Turn_TBIKE=1;CLIMB_ACTIVATE_TBIKE=1;PLANCHER_TBIKE_add++;}
  else if((POS_JUMP)>9) {PLANCHER_TBIKE_add--;}
}

void CLIMB_ADJ2_TBIKE(void){
#define POS_JUMP (30-sprite_TBIKE[NoSprite_TBIKE].xPOS)
Break_Gravity_TBIKE();
Wheel_up_TBIKE=3;
  if ((POS_JUMP)<9) {Not_Turn_TBIKE=1;CLIMB_ACTIVATE_TBIKE=1;PLANCHER_TBIKE_add++;}
  else{PLANCHER_TBIKE_add=0;}
}

uint8_t RECUPE_X_SPRITE_TBIKE(uint8_t Type_Sprite){
return pgm_read_byte(&DIM_SPRITE_TBIKE[((Type_Sprite-1)*2)]);
}

uint8_t CHECK_SPEED_ADJ_TBIKE(float REC_INT){
uint8_t ret=0;
while(1){
ESP.wdtFeed();
if (REC_INT>1) {ret++;REC_INT=REC_INT-1;}else{ Higher_adj_TBIKE(ret);return ret;}
}}

void TRACK_RUN_ADJ_TBIKE(void){
if (trackrun_TBIKE!=Trackrun_progress_TBIKE) {
 if ((trackrun_TBIKE<Trackrun_progress_TBIKE)&&(TRANSITION_TRACK_TBIKE==0)){TRANSITION_TRACK_TBIKE=5;}
 if ((trackrun_TBIKE>Trackrun_progress_TBIKE)&&(TRANSITION_TRACK_TBIKE==0)){TRANSITION_TRACK_TBIKE=-5;}
  
 if (TRANSITION_TRACK_TBIKE>0){TRANSITION_TRACK_TBIKE--;animBike_TBIKE=8;BIKE_POSy_TBIKE++;}
 else if (TRANSITION_TRACK_TBIKE<0){TRANSITION_TRACK_TBIKE++;animBike_TBIKE=7;BIKE_POSy_TBIKE--;}
if (TRANSITION_TRACK_TBIKE==0) {TRIG_OK_TBIKE=0;trackrun_TBIKE=Trackrun_progress_TBIKE;}}
}

uint8_t RECUPE_MAP_BYTE_TBIKE(const uint8_t *Level){
return pgm_read_byte(&Level[MAP_POS_TBIKE]);
}

uint8_t SPLIT_MAP_BYTE_TBIKE(uint8_t BYTE,uint8_t L0_R1){
  switch(L0_R1){
    case(0):return (BYTE>>6);break;
    case(1):return (BYTE>>4)&0b00000011;break;
    case(2):return BYTE&0b00001111;break;
    default:break;
  }
  return 0;
}

void RefreshPosSprite_TBIKE(void){
for(uint8_t t=0;t<NUMofSPRITE;t++){
if (sprite_TBIKE[t].ACTIVE!=0) {
if (sprite_TBIKE[t].xPOS<=-26) {sprite_TBIKE[t].ACTIVE=0;}else{sprite_TBIKE[t].xPOS--;}
}}
CheckCollision_TBIKE();
}

void INCREMENTE_SCROLL_TBIKE(void){
if (VAR_SCROLL3_TBIKE==0) {VAR_SCROLL3_TBIKE=1;
if (VAR_SCROLL2_TBIKE==0) {VAR_SCROLL2_TBIKE=1;
if (VAR_SCROLL1_TBIKE==0) {VAR_SCROLL1_TBIKE=1;}else{VAR_SCROLL1_TBIKE=0;}}else{VAR_SCROLL2_TBIKE=0;}}else{VAR_SCROLL3_TBIKE=0;}
if (VAR_SCROLL3_TBIKE==1) {VAR_SCROLL3_TBIKE=2;if (Progress_bar_Interval_TBIKE_timer<Progress_bar_Interval_TBIKE) {Progress_bar_Interval_TBIKE_timer++;}else{Progress_bar_Interval_TBIKE_timer=0;if (Progress_bar_value_TBIKE<32) {Progress_bar_value_TBIKE++;}}
if (RENEW_SPRITE_TBIKE<64) {RENEW_SPRITE_TBIKE++;}else{CREATE_NEWSPRITE_TBIKE();}
  if (Jump_dinamic_duration_TBIKE!=0){Not_Move_TBIKE=1;JUMP_ADJ_TBIKE();}  if (CLIMB_ACTIVATE_TBIKE) {CLIMB_ACTIVATE_TBIKE=0;Jump_dinamic_duration_TBIKE=1;}
RefreshPosSprite_TBIKE();if (DScroll3<9) {DScroll3++;}else{DScroll3=0;}}
if (VAR_SCROLL2_TBIKE==1) {VAR_SCROLL2_TBIKE=2;if (DScroll2<14) {DScroll2++;}else{DScroll2=0;}}
if (VAR_SCROLL1_TBIKE==1) {VAR_SCROLL1_TBIKE=2;if (DScroll1<7) {DScroll1++;}else{DScroll1=0;}}
}

uint8_t CREATE_NEWSPRITE_TBIKE(void){
uint8_t type=SPLIT_MAP_BYTE_TBIKE(RECUPE_MAP_BYTE_TBIKE(Level0_TBIKE),2);
uint8_t recupe_y_pos0=SPLIT_MAP_BYTE_TBIKE(RECUPE_MAP_BYTE_TBIKE(Level0_TBIKE),0);
uint8_t recupe_y_pos=(recupe_y_pos0*5);
for(uint8_t t=0;t<NUMofSPRITE;t++){
if (sprite_TBIKE[t].ACTIVE==0) {
sprite_TBIKE[t].xPOS=127;
sprite_TBIKE[t].ACTIVE=1;
sprite_TBIKE[t].Y_START=recupe_y_pos0;
sprite_TBIKE[t].Y_END=SPLIT_MAP_BYTE_TBIKE(RECUPE_MAP_BYTE_TBIKE(Level0_TBIKE),1);
 switch(type){
case(0):sprite_TBIKE[t].TypeofSprite=1;sprite_TBIKE[t].yPOS=20;break;
case(1):sprite_TBIKE[t].TypeofSprite=2;sprite_TBIKE[t].yPOS=26;break;
case(2):sprite_TBIKE[t].TypeofSprite=3;sprite_TBIKE[t].yPOS=recupe_y_pos+32;break;
case(3):sprite_TBIKE[t].TypeofSprite=4;sprite_TBIKE[t].yPOS=32;break; 
case(4):sprite_TBIKE[t].TypeofSprite=5;sprite_TBIKE[t].yPOS=32;break; 
case(5):sprite_TBIKE[t].TypeofSprite=6;sprite_TBIKE[t].yPOS=recupe_y_pos+22;break;
case(6):sprite_TBIKE[t].TypeofSprite=7;sprite_TBIKE[t].yPOS=recupe_y_pos+34;break;
case(7):sprite_TBIKE[t].TypeofSprite=8;sprite_TBIKE[t].yPOS=recupe_y_pos+30;break;
  default:sprite_TBIKE[t].TypeofSprite=16;break;
 }
RENEW_SPRITE_TBIKE=0;
if (type==14) {ReWind_TBIKE=1;}
if ((type!=15)&&(ReWind_TBIKE!=1)) {MAP_POS_TBIKE++;}
return 0;
}} 
return 0;
}

uint8_t  BACKGROUND_TBIKE(uint8_t xPASS,uint8_t yPASS){
switch(yPASS){
  case(0):return FOUL1_TBIKE();break;
  case(1):return GRADIN23_TBIKE(yPASS);break;
  case(2):return GRADIN23_TBIKE(yPASS);break;
  case(3):return TIRE4_TBIKE();break;
  case(4):return ROAD567_TBIKE(yPASS);break;
  case(5):return ROAD567_TBIKE(yPASS);break;
  case(6):return ROAD567_TBIKE(yPASS);break;
  case(7):return (0xff-TABLEAU8_TBIKE(xPASS));break;
  default:return 0x00;break;
}}

uint8_t TOPBACK_TBIKE(uint8_t xPASS,uint8_t yPASS){
return pgm_read_byte(&TOP_BACK_TBIKE[xPASS+(yPASS*128)]);
}

uint8_t FOUL1_TBIKE(void){
if (BScroll1<7) {BScroll1++;}else{BScroll1=0;}
return pgm_read_byte(&FOUL_TBIKE[BScroll1]);  
}
uint8_t GRADIN23_TBIKE(uint8_t yPASS){
uint8_t MUL=0;
if (yPASS==2) {return 0;MUL=8;}
if (BScroll1<7) {BScroll1++;}else{BScroll1=0;}
return pgm_read_byte(&GRADIN_TBIKE[BScroll1+MUL]);  
}

uint8_t TIRE4_TBIKE(void){
if (BScroll2<14) {BScroll2++;}else{BScroll2=0;}
return pgm_read_byte(&TIRE_TBIKE[BScroll2]);  
}

uint8_t ROAD567_TBIKE(uint8_t yPASS){
uint8_t MUL=0;
MUL=(yPASS==5)?10:MUL;
MUL=(yPASS==6)?20:MUL;
if (BScroll3<9) {BScroll3++;}else{BScroll3=0;}
return pgm_read_byte(&ROAD_TBIKE[BScroll3+MUL]);  
}

uint8_t TABLEAU8_TBIKE(uint8_t xPASS){
return ((0xff-pgm_read_byte(&DISPLAY8_TBIKE[xPASS]))|Return_live_TBIKE(xPASS)|Return_time_TBIKE(xPASS)|(Return_Progress_TBIKE(xPASS)));  
}

uint8_t Return_live_TBIKE(uint8_t xPASS){
 uint8_t Start_black=26;
 switch(Live_TBIKE){
 case -1:
 case 0:Start_black=4;break;
 case 1:Start_black=11;break;
 case 2:Start_black=19;break;
 case 3:Start_black=26;break;
 default:break;
 }
 if (xPASS<Start_black) {return 0x00;}
 if (xPASS>26) {return 0x00;}
 return 0b01111110;
}

uint8_t Return_time_TBIKE(uint8_t xPASS){
if ((xPASS>=(40+(35-Time_bar_value_TBIKE)))&&(xPASS<=75)) {return 0b00111100;}
return 0x00;   
}

uint8_t Return_Progress_TBIKE(uint8_t xPASS){
if (xPASS==(Progress_bar_value_TBIKE+90)) {return 0b00011000;}
return 0x00;   
}

void AdjustVarScroll_TBIKE(void){
BScroll1=(DScroll1);
BScroll2=(DScroll2);
BScroll3=(DScroll3);
}

uint8_t Sprite2PAINTinBLACK;

uint8_t Recupe_TBIKE(uint8_t xPASS,uint8_t yPASS){
Sprite2PAINTinBLACK=254;
return (BACKGROUND_TBIKE(xPASS,yPASS)
|BIKE_SPRITE_TBIKE(xPASS,yPASS)
|BLITZ_SPRITE_MAP_TBIKE(xPASS,yPASS));
}

uint8_t BLITZ_SPRITE_MAP_TBIKE(uint8_t xPASS,uint8_t yPASS){
uint8_t SPRITERECUPE=0;
if ((yPASS<2)||(yPASS>6)) {goto Fin;}
for(uint8_t t=0;t<NUMofSPRITE;t++){
if (sprite_TBIKE[t].ACTIVE!=0) {
switch(sprite_TBIKE[t].TypeofSprite){
case(1):SPRITERECUPE=BIGSTEP_SPRITE_TBIKE(t,xPASS,yPASS);break;
case(2):SPRITERECUPE=MINISTEP_SPRITE_TBIKE(t,xPASS,yPASS);break;
case(3):SPRITERECUPE=HUILE_SPRITE_TBIKE(t,xPASS,yPASS);break;
case(4):SPRITERECUPE=LINE_SPRITE_TBIKE(t,xPASS,yPASS);break;
case(5):SPRITERECUPE=START_SPRITE_TBIKE(t,xPASS,yPASS);break;
case(6):SPRITERECUPE=SPEED_SPRITE_TBIKE(t,xPASS,yPASS);break;
case(7):SPRITERECUPE=Plantage_TBIKE(t,xPASS,yPASS);break;
case(8):SPRITERECUPE=NEW_LIVE_TBIKE(t,xPASS,yPASS);break;
default:SPRITERECUPE=0x00;break;
}
if ((SPRITERECUPE!=0)||(Sprite2PAINTinBLACK!=254)) {Sprite2PAINTinBLACK=t;goto Fin;}
}} 
Fin:;
return SPRITERECUPE;
}

uint8_t BIGSTEP_SPRITE_TBIKE(uint8_t numSprite,uint8_t xPASS,uint8_t yPASS){
return blitzSprite_TBIKE(sprite_TBIKE[numSprite].xPOS,sprite_TBIKE[numSprite].yPOS,xPASS,yPASS,0,BigStepA_TBIKE);
}

uint8_t MINISTEP_SPRITE_TBIKE(uint8_t numSprite,uint8_t xPASS,uint8_t yPASS){
return blitzSprite_TBIKE(sprite_TBIKE[numSprite].xPOS,sprite_TBIKE[numSprite].yPOS,xPASS,yPASS,0,MinijumpA_TBIKE);
}

uint8_t Plantage_TBIKE(uint8_t numSprite,uint8_t xPASS,uint8_t yPASS){
return blitzSprite_TBIKE(sprite_TBIKE[numSprite].xPOS,sprite_TBIKE[numSprite].yPOS,xPASS,yPASS,0,plantage_TBIKE);
}

uint8_t HUILE_SPRITE_TBIKE(uint8_t numSprite,uint8_t xPASS,uint8_t yPASS){
return blitzSprite_TBIKE(sprite_TBIKE[numSprite].xPOS,sprite_TBIKE[numSprite].yPOS,xPASS,yPASS,0,huile_TBIKE);
}

uint8_t LINE_SPRITE_TBIKE(uint8_t numSprite,uint8_t xPASS,uint8_t yPASS){
return blitzSprite_TBIKE(sprite_TBIKE[numSprite].xPOS,sprite_TBIKE[numSprite].yPOS,xPASS,yPASS,0,Line_TBIKE);
}

uint8_t START_SPRITE_TBIKE(uint8_t numSprite,uint8_t xPASS,uint8_t yPASS){
return blitzSprite_TBIKE(sprite_TBIKE[numSprite].xPOS,sprite_TBIKE[numSprite].yPOS,xPASS,yPASS,0,Start_TBIKE);
}

uint8_t SPEED_SPRITE_TBIKE(uint8_t numSprite,uint8_t xPASS,uint8_t yPASS){
return blitzSprite_TBIKE(sprite_TBIKE[numSprite].xPOS,sprite_TBIKE[numSprite].yPOS,xPASS,yPASS,0,Speed_TBIKE);
}

uint8_t NEW_LIVE_TBIKE(uint8_t numSprite,uint8_t xPASS,uint8_t yPASS){
return blitzSprite_TBIKE(sprite_TBIKE[numSprite].xPOS,sprite_TBIKE[numSprite].yPOS,xPASS,yPASS,0,New_Live_TBIKE);
}

uint8_t BIKE_SPRITE_TBIKE(uint8_t xPASS,uint8_t yPASS){
return blitzSprite_TBIKE(24,BIKE_POSy_TBIKE,xPASS,yPASS,animBike_TBIKE,bike1_TBIKE);
}

uint8_t blitzSprite_TBIKE(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES){
RecupeDecalageY_TBIKE(yPos);

uint8_t OUTBYTE=0;
uint8_t WSPRITE=(pgm_read_byte(&SPRITES[0]));
uint8_t HSPRITE=(pgm_read_byte(&SPRITES[1]));
if ((xPASS>((xPos+(WSPRITE-1))))||(xPASS<xPos)||((LINE_Y_TBIKE>yPASS)||((LINE_Y_TBIKE+(HSPRITE))<yPASS))) {return 0x00;} 
uint8_t Wmax ((HSPRITE*WSPRITE)+1);
uint8_t PICBYTE=FRAME*(Wmax-1);
uint8_t SPRITEyLINE=(yPASS-(LINE_Y_TBIKE));
uint8_t ScanA=(((xPASS-xPos)+(SPRITEyLINE*WSPRITE))+2);
uint8_t ScanB=(((xPASS-xPos)+((SPRITEyLINE-1)*WSPRITE))+2);
OUTBYTE=(ScanA>Wmax)?0x00:SplitSpriteDecalageY_TBIKE(DECALAGE_TBIKE,pgm_read_byte(&SPRITES[ScanA+(PICBYTE)]),1);
if ((SPRITEyLINE>0)) {
uint8_t OUTBYTE2=SplitSpriteDecalageY_TBIKE(DECALAGE_TBIKE,pgm_read_byte(&SPRITES[ScanB+(PICBYTE)]),0);
if (ScanB>Wmax) {return OUTBYTE;}else{return OUTBYTE|OUTBYTE2;}
}else{
return OUTBYTE;}
}

void RecupeDecalageY_TBIKE(uint8_t Valeur){
LINE_Y_TBIKE=0;
DECALAGE_TBIKE=Valeur;
while(DECALAGE_TBIKE>7){
ESP.wdtFeed();
	DECALAGE_TBIKE=DECALAGE_TBIKE-8;LINE_Y_TBIKE++;}
}

uint8_t SplitSpriteDecalageY_TBIKE(uint8_t DECALAGE_TBIKE,uint8_t Input,uint8_t UPorDOWN){
if (UPorDOWN) {
return Input<<DECALAGE_TBIKE;
}else{
return Input>>(8-DECALAGE_TBIKE); 
}}
#define VAR_16 (x+(y*128))
void Tiny_Flip_TBIKE(uint8_t MODE){
uint8_t y,x; 
for (y = 0; y < 8; y++){ 
AdjustVarScroll_TBIKE();   
for (x = 0; x < 128; x++){
  switch(MODE){
   case 0:display.buffer[VAR_16] =Recupe_TBIKE(x,y);break;
   case 1:display.buffer[VAR_16] =Recupe_TBIKE(x,y);break;
   case 2:display.buffer[VAR_16] =blitzSprite_TBIKE(38,30,x,y,0,INTROPIC_TBIKE);break;
   case 3:display.buffer[VAR_16] =Recupe_TBIKE(x,y);break;
   default:break;
}}}
display.display();  
}

void Sound_TBIKE(uint8_t freq,uint8_t dur){
ESP.wdtFeed();
if (freq==0) {My_delay_ms(dur);goto END;}
for (uint8_t t=0;t<dur;t++){
if (freq!=0){
digitalWrite(PIN_,SOUND_ON_OFF);
}
for (uint8_t t=0;t<(255-freq);t++){
My_delay_us(1); }
digitalWrite(PIN_,LOW);
for (uint8_t t=0;t<(255-freq);t++){
My_delay_us(1); }}
END:;
digitalWrite(PIN_,LOW);
}
