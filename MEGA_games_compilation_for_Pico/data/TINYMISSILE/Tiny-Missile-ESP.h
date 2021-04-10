//     >>>>>  MEGA COMPILATION for ESP8266/ESP8285  GPL v3 <<<<
//                    >>>>>  MEGA Tiny Joypad  <<<<
//                    Programmer: Daniel C 2019-2020
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


#include"CLASS_TMISSILE.h"

uint8_t blitzSprite_TMISSILE(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES);
uint8_t SplitSpriteDecalageY_TMISSILE(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN);
int8_t RecupeLineY_TMISSILE(int8_t Valeur);
uint8_t RecupeDecalageY_TMISSILE(uint8_t Valeur);


void TinySound(uint8_t freq_,uint8_t dur);
void loop_TMISSILE();
uint8_t ALL_ANIM_END_TMISSILE(void);
void RESTORE_DOME_TMISSILE(void);
uint8_t Score_Dome_Munition_TMISSILE(void);
void ADJ_LEVEL_TMISSILE(uint8_t Level_);
void NEW_GAME_TMISSILE(void);
void NEXTLEVEL_TMISSILE(void);
void INC_SCORES_TMISSILE(void);
uint8_t UPDATE_ENGINE_TMISSILE(void);
void UPDATE_DOME_TMISSILE(void);
void UPDATE_Intercept_TMISSILE(void);
void Destroy_TMISSILE(uint8_t t_);
void Create_New_Intercept_TMISSILE(int8_t X_,int8_t Y_);
void NEW_POS_TMISSILE(int8_t *ST_,int8_t *END_);
void Start_RDLP_MIX(void);
void RDLP_MIX(void);
void UPDATE_DFENCE_TMISSILE(void);
void Renew_Shield_TMISSILE(int8_t x_END,int8_t y_END);
void REFRESH_TOPBAR_TMISSILE(void);
void RESET_ALL_MISSILE_TMISSILE(void);
void RENEW_MISSILE(void);
uint8_t RECUP_LINE_TMISSILE(uint8_t xPASS,uint8_t yPASS);
uint8_t RECUP_DOME_TMISSILE(uint8_t xPASS,uint8_t yPASS);
uint8_t RECUP_CROSS_TMISSILE(uint8_t xPASS,uint8_t yPASS);
uint8_t RECUP_SHIELD_TMISSILE(uint8_t xPASS,uint8_t yPASS);
uint8_t RECUPE_TOPBAR_TMISSILE(uint8_t xPASS,uint8_t yPASS);
uint8_t RECUP_INTERCEPT_TMISSILE(uint8_t xPASS,uint8_t yPASS);
uint8_t Recupe_TMISSILE(uint8_t xPASS,uint8_t yPASS);
uint8_t BACKGROUND_TMISSILE(uint8_t xPASS,uint8_t yPASS);
void Tiny_Flip_TMISSILE(void);
void INTRO_TMISSILE(uint8_t FL_);
uint8_t RECUPE_INTRO_TMISSILE(uint8_t xPASS,uint8_t yPASS,uint8_t Fl_);
uint8_t RECUP_PANEL_TMISSILE(uint8_t xPASS,uint8_t yPASS);
uint8_t INVENTORY_TMISSILE(uint8_t xPASS);
uint8_t MUNITION_TMISSILE(uint8_t xPASS);
uint8_t NUMERIC_TMISSILE(uint8_t xPASS);
uint8_t recupe_SCORES_TMISSILE(uint8_t xPASS);
void COMPIL_SCO_TMISSILE(void);
void SNDBOX_TMISSILE(uint8_t Snd_);
int8_t Mymap(int8_t x, int8_t in_min, int8_t in_max, int8_t out_min, int8_t out_max);
uint8_t Trace_LINE(uint8_t DESACTIVE_,int8_t x1,int8_t y1,int8_t x2,int8_t y2,uint8_t xPASS,uint8_t yPASS);
uint8_t DIRECTION_LINE(uint8_t DESACTIVE_,int8_t x1,int8_t y1,int8_t x2,int8_t y2,uint8_t xPASS,uint8_t yPASS);
uint8_t Return_Full_Byte(int8_t x1,int8_t y1,int8_t x2,int8_t y2,uint8_t xPASS,uint8_t yPASS);
void Universal_Swap(int8_t *A_,int8_t *B_);


//PROTOTYPE END


//Public VAR
uint8_t RDLP=40;
uint8_t START_RDLP=64;

uint8_t REVERSE_TMISSILE;
uint8_t M10000_TMISSILE;
uint8_t M1000_TMISSILE;
uint8_t M100_TMISSILE;
uint8_t M10_TMISSILE;
uint8_t M1_TMISSILE;
uint16_t Scores_TMISSILE;
uint8_t SHOT_ADJ_TMISSILE;
uint8_t LEVEL_TMISSILE;

//CLASS DECLARATION
CLK RENEW;
CLK SPEED_MISSILE;
STATIC_SPRITE_ANIM_TMISSILE INTERCEPT[3];
STATIC_SPRITE_ANIM_TMISSILE DOME[NUM_of_DOME_TMISSILE];
LINE_TMISSILE Missile[NUM_of_MISSILE_TMISSILE];
CROSS Cross;
DEFENCE Dfence[3];
ARMY_TMISSILE ARM_TMISSILE;

////////////////////////////////// main  ////////////////////////////////////

void loop_TMISSILE() {
ESP.wdtDisable();
ESP.wdtFeed();
CLK BLINK;
BLINK.INIT(0,10,1);
NEWGAME:;
while(1){
ESP.wdtDisable();
ESP.wdtFeed();
if (BUTTON_DOWN) {
while(1){if (BUTTON_UP) {SNDBOX_TMISSILE(0);goto START_;}}  
  }
INTRO_TMISSILE(BLINK.PROGRESS());
CONTROL_FRAMERATE(46);
}
START_:;
NEW_GAME_TMISSILE();
NEXTLEVEL:;
ADJ_LEVEL_TMISSILE(LEVEL_TMISSILE);
RESTORE_DOME_TMISSILE();
uint8_t OneDrop=0;
Tiny_Flip_TMISSILE();
while(1){
ESP.wdtFeed();
if (TINYJOYPAD_RIGHT==0) {Cross.RIGHT();RDLP_MIX();}
else if (TINYJOYPAD_LEFT==0) {Cross.LEFT();RDLP_MIX();}
if (TINYJOYPAD_UP==0) {Cross.UP();Start_RDLP_MIX();}
else if (TINYJOYPAD_DOWN==0) {Cross.DOWN();Start_RDLP_MIX();}
if (BUTTON_DOWN) {
 if (OneDrop==0) {
   Renew_Shield_TMISSILE(Cross.GET_X(),Cross.GET_Y());
   OneDrop=1;
  }
  }else{OneDrop=0;}
switch (UPDATE_ENGINE_TMISSILE()) {
case 1:
if (ALL_ANIM_END_TMISSILE()){
  if (Score_Dome_Munition_TMISSILE()) {
    SNDBOX_TMISSILE(2);
    goto NEWGAME;
    }else{
     SNDBOX_TMISSILE(1);
     NEXTLEVEL_TMISSILE();
     goto NEXTLEVEL;
      }
}break;
default:break;
  }
CONTROL_FRAMERATE(46);
Tiny_Flip_TMISSILE();
RDLP_MIX();
Start_RDLP_MIX(); 
}}
////////////////////////////////// main end /////////////////////////////////

uint8_t ALL_ANIM_END_TMISSILE(void){
for (uint8_t t=0;t<NUM_of_DOME_TMISSILE;t++){
if (DOME[t].GET_FRAME()!=0) {return 0;}
}return 1;}

void RESTORE_DOME_TMISSILE(void){
for (uint8_t t=0;t<NUM_of_DOME_TMISSILE;t++){
if (DOME[t].GET_ACTIVE()==2) {DOME[t].PUT_ACTIVE(1);}
}}

uint8_t Score_Dome_Munition_TMISSILE(void){
My_delay_ms(500);
while(1){
if (ARM_TMISSILE.USE_WEAPON()) {Scores_TMISSILE++;COMPIL_SCO_TMISSILE();SNDBOX_TMISSILE(3);Tiny_Flip_TMISSILE();}else{break;}
}
My_delay_ms(500);
uint8_t Count_=0;
for (uint8_t t=0;t<NUM_of_DOME_TMISSILE;t++){
if (DOME[t].GET_ACTIVE()==1) {
if (DOME[t].GET_FRAME()==0) {
Scores_TMISSILE+=5; 
COMPIL_SCO_TMISSILE();
DOME[t].PUT_ACTIVE(2);
Count_++;
SNDBOX_TMISSILE(4);
}else{DOME[t].PUT_ACTIVE(0);}
}
Tiny_Flip_TMISSILE();
Tiny_Flip_TMISSILE();
}
My_delay_ms(500);
if (Count_==0) return 1;
return 0;
}

void ADJ_LEVEL_TMISSILE(uint8_t Level_){
uint8_t t;
RESET_ALL_MISSILE_TMISSILE();
for (t=0;t<3;t++){
Dfence[t].INIT();
INTERCEPT[t].INIT(0,0,0);
}
ARM_TMISSILE.RESET_WEAPON(Level_);
SHOT_ADJ_TMISSILE=Mymap(Level_,0,10,20,60);
SPEED_MISSILE.INIT(0,Mymap(Level_,0,10,2,0),0);
RENEW.INIT(0,Mymap(Level_,0,10,6,12),0);
Cross.INIT();
}

void NEW_GAME_TMISSILE(void){
REVERSE_TMISSILE=0;
M10000_TMISSILE=0;
M1000_TMISSILE=0;
M100_TMISSILE=0;
M10_TMISSILE=0;
M1_TMISSILE=0;
Scores_TMISSILE=0;
LEVEL_TMISSILE=0;
for (uint8_t t=0;t<NUM_of_DOME_TMISSILE;t++){
DOME[t].INIT_DOME(pgm_read_byte(&DOME_ORDER_TMISSILE[t]),7,1);
}}

void NEXTLEVEL_TMISSILE(void){
LEVEL_TMISSILE=(LEVEL_TMISSILE<10)?LEVEL_TMISSILE+1:10;
}

void INC_SCORES_TMISSILE(void){
Scores_TMISSILE+=13;  
COMPIL_SCO_TMISSILE();
REFRESH_TOPBAR_TMISSILE();
}

uint8_t UPDATE_ENGINE_TMISSILE(void){
uint8_t CHECK_IF_EXIST=255;
uint8_t t;
UPDATE_DOME_TMISSILE();
UPDATE_DFENCE_TMISSILE();
UPDATE_Intercept_TMISSILE();
if (SPEED_MISSILE.PROGRESS()) {
CHECK_IF_EXIST=0;
for (t=0;t<NUM_of_MISSILE_TMISSILE;t++){
if (Missile[t].GET_ACTIVE()) {
CHECK_IF_EXIST++;
Start_RDLP_MIX();
Missile[t].PROGRESS(&DOME[0],&ARM_TMISSILE);}  
}
if (RENEW.PROGRESS()) {
  if (SHOT_ADJ_TMISSILE){
  RENEW_MISSILE();
  SHOT_ADJ_TMISSILE=(SHOT_ADJ_TMISSILE>0)?SHOT_ADJ_TMISSILE-1:0;
  RENEW.RESET();
  }}
SPEED_MISSILE.RESET();
}
if (CHECK_IF_EXIST==0) {
if (SHOT_ADJ_TMISSILE==0) {
  for (t=0;t<3;t++){
Dfence[t].PUT_ACTIVE(0);
INTERCEPT[t].PUT_ACTIVE(0); 
}
Tiny_Flip_TMISSILE();   
return 1;}
}
return 0;
}

void UPDATE_DOME_TMISSILE(void){
uint8_t REFRESH=0;
uint8_t TOTAL_=0;
for (uint8_t t=0;t<NUM_of_DOME_TMISSILE;t++){
if (DOME[t].GET_ACTIVE()) {
if (DOME[t].GET_FRAME()>0) {
  SNDBOX_TMISSILE(5);
DOME[t].PROGRESS_ANIM();
  REFRESH=1;
  }
 TOTAL_++; 
  }}
if (TOTAL_==0) {
  SHOT_ADJ_TMISSILE=0;
}
 if (REFRESH) Tiny_Flip_TMISSILE();
}


void UPDATE_Intercept_TMISSILE(void){
uint8_t t;
for (t=0;t<3;t++){
if (INTERCEPT[t].GET_ACTIVE()) {
switch(INTERCEPT[t].PROGRESS_ANIM()){
  case(4):Destroy_TMISSILE(t);break;
  default:break;
}}}}

void Destroy_TMISSILE(uint8_t t_){
uint8_t t;
uint8_t Sn_=255;
for (t=0;t<NUM_of_MISSILE_TMISSILE;t++){
if (Missile[t].GET_ACTIVE()) {
if ((INTERCEPT[t_].GET_Y()+15)<(Missile[t].GET_TRACK())) goto NexT;
if ((INTERCEPT[t_].GET_Y())>(Missile[t].GET_TRACK())) goto NexT;
int8_t XPOS_=Mymap((Missile[t].GET_TRACK()),11,55,Missile[t].GET_START_X(),Missile[t].GET_END_X());
if (XPOS_< INTERCEPT[t_].GET_X()) {goto NexT;}
if (XPOS_> (INTERCEPT[t_].GET_X()+9)) {goto NexT;}
Missile[t].PUT_ACTIVE(0);
INC_SCORES_TMISSILE();}
NexT:;
TinySound(Sn_=Sn_-45,4);
}}

void Create_New_Intercept_TMISSILE(int8_t X_,int8_t Y_){
uint8_t t;
for (t=0;t<3;t++){
if (INTERCEPT[t].GET_ACTIVE()==0) {
INTERCEPT[t].INIT(X_,Y_,1);
INTERCEPT[t].PUT_FRAME(0);
break;
}}}

void NEW_POS_TMISSILE(int8_t *ST_,int8_t *END_){
int8_t A_,B_=0;
A_=START_RDLP;
if (REVERSE_TMISSILE==1){
B_=((A_+RDLP)>126)?(A_-RDLP):(A_+RDLP);}else
{B_=((A_-RDLP)<3)?(A_+RDLP):(A_-RDLP);}
*ST_=A_;
*END_=B_;
}

void Start_RDLP_MIX(void){
START_RDLP=(START_RDLP>3)?START_RDLP-3:125-START_RDLP;
}

void RDLP_MIX(void){
RDLP=(RDLP<60)?RDLP+3:22;
}

void UPDATE_DFENCE_TMISSILE(void){
for (uint8_t t=0;t<3;t++){
if (Dfence[t].GET_ACTIVE()==1) {Dfence[t].UPDATE_DEFENCE();}
}}

void Renew_Shield_TMISSILE(int8_t x_END,int8_t y_END){
for (uint8_t t=0;t<3;t++){
if (Dfence[t].GET_ACTIVE()==0) {    
  if (ARM_TMISSILE.USE_WEAPON()) {REFRESH_TOPBAR_TMISSILE();Dfence[t].NEW(x_END,y_END); }
  break;
  }}
}

void REFRESH_TOPBAR_TMISSILE(void){
Tiny_Flip_TMISSILE();
}

void RESET_ALL_MISSILE_TMISSILE(void){
int8_t A_,B_;
for (uint8_t t=0;t<NUM_of_MISSILE_TMISSILE;t++){
RDLP_MIX();
Start_RDLP_MIX();
NEW_POS_TMISSILE(&A_,&B_); 
Missile[t].INIT(A_,B_,0);}
}

void RENEW_MISSILE(void){
int8_t A_,B_;
RDLP_MIX();
Start_RDLP_MIX();
 NEW_POS_TMISSILE(&A_,&B_);
for (uint8_t t=0;t<NUM_of_MISSILE_TMISSILE;t++){
if (Missile[t].GET_ACTIVE()==0) { REVERSE_TMISSILE=(REVERSE_TMISSILE==1)?0:1;Missile[t].INIT(A_,B_,1);goto Ending;}
}  
Ending:;
}

uint8_t RECUP_LINE_TMISSILE(uint8_t xPASS,uint8_t yPASS){
uint8_t Byte_=0x00;
uint8_t TByte_=0x00;
for (uint8_t t=0;t<NUM_of_MISSILE_TMISSILE;t++){
if (Missile[t].GET_ACTIVE()==1) {
if (yPASS<=Missile[t].GET_yPass()){
TByte_=Trace_LINE(0,Missile[t].GET_START_X(),11,Missile[t].GET_END_X(),55,xPASS,yPASS);
if (Missile[t].GET_yPass()==yPASS) {
Byte_|=(Missile[t].GET_yDeca()&TByte_);
}else{
Byte_|=TByte_;
}}}}
return Byte_;
}

uint8_t RECUP_DOME_TMISSILE(uint8_t xPASS,uint8_t yPASS){
if (yPASS!=7) {return 0x00;}
uint8_t BYTE_OUT;
for (uint8_t t=0;t<NUM_of_DOME_TMISSILE;t++){
if (DOME[t].GET_ACTIVE()==1) {
BYTE_OUT=SPEED_BLITZ_TMISSILE(DOME[t].GET_X(),DOME[t].GET_Y(),xPASS,yPASS,DOME[t].GET_FRAME(),DOME_SPRITE_TMISSILE);
if (BYTE_OUT!=0) return BYTE_OUT;
}}
return 0x00;
}

uint8_t RECUP_CROSS_TMISSILE(uint8_t xPASS,uint8_t yPASS){
return blitzSprite_TMISSILE(Cross.GET_X(),Cross.GET_Y(),xPASS,yPASS,0,CROSS_TMISSILE);
}

uint8_t RECUP_SHIELD_TMISSILE(uint8_t xPASS,uint8_t yPASS){
uint8_t Byte_=0;
uint8_t t;
for (t=0;t<3;t++){
if (Dfence[t].GET_ACTIVE()) Byte_|=blitzSprite_TMISSILE(Dfence[t].GET_X(),Dfence[t].GET_Y(),xPASS,yPASS,0,ROCKET_TMISSILE);
}
return Byte_;
}

uint8_t RECUPE_TOPBAR_TMISSILE(uint8_t xPASS,uint8_t yPASS){
return pgm_read_byte(&TOP_PANEL_TMISSILE[xPASS+(yPASS*128)]); 
}

uint8_t RECUP_INTERCEPT_TMISSILE(uint8_t xPASS,uint8_t yPASS){
uint8_t t,BYTE_=0;
for (t=0;t<3;t++){
if (INTERCEPT[t].GET_ACTIVE()){
if (xPASS<INTERCEPT[t].GET_X()) goto NexT_;
if (xPASS>INTERCEPT[t].GET_X()+10) goto NexT_;
BYTE_|=blitzSprite_TMISSILE(INTERCEPT[t].GET_X(),INTERCEPT[t].GET_Y(),xPASS,yPASS,INTERCEPT[t].GET_FRAME() ,INTERCEPT_TMISSILE);
NexT_:;
}}
return BYTE_;
}

uint8_t Recupe_TMISSILE(uint8_t xPASS,uint8_t yPASS){
return (
RECUP_LINE_TMISSILE(xPASS,yPASS)|
BACKGROUND_TMISSILE(xPASS,yPASS)|
RECUP_DOME_TMISSILE(xPASS,yPASS)|
RECUP_CROSS_TMISSILE(xPASS,yPASS)|
RECUP_SHIELD_TMISSILE(xPASS,yPASS)|
RECUP_INTERCEPT_TMISSILE(xPASS,yPASS)|
RECUP_PANEL_TMISSILE(xPASS,yPASS)
);}

uint8_t BACKGROUND_TMISSILE(uint8_t xPASS,uint8_t yPASS){
switch(yPASS){
  case 0:return 0;break;
  case 1:return pgm_read_byte(&Y1_TMISSILE[xPASS]);break; 
  case 2 ... 5 :return pgm_read_byte(&CENTER_TMISSILE[xPASS]);break; 
  case 6:return pgm_read_byte(&Y6_TMISSILE[xPASS]);break; 
  case 7:return pgm_read_byte(&Y7_TMISSILE[xPASS]);break; 
  default:return 0;break;
}}

void Tiny_Flip_TMISSILE(void){
uint8_t y,x; 
for (y = 0; y < 8; y++){ 
    for (x = 0; x < 128; x++){ 
display.buffer[x+(y*128)] =(Recupe_TMISSILE(x,y));
    }
}
display.display();
}

void INTRO_TMISSILE(uint8_t FL_){
uint8_t y,x; 
for (y = 0; y < 8; y++){ 

    for (x = 0; x < 128; x++){ 
display.buffer[x+(y*128)] =(RECUPE_INTRO_TMISSILE(x,y,FL_)|((y==7)?NUMERIC_TMISSILE(x):0x00));
    }
}
display.display();
}

uint8_t RECUPE_INTRO_TMISSILE(uint8_t xPASS,uint8_t yPASS,uint8_t Fl_){
if (Fl_==1){
if ((xPASS<68)&&(xPASS>60)){
switch (yPASS) {
  case 4:return 0;break;
  case 5:return 0;break;
  }}}
return SPEED_BLITZ_TMISSILE(21,0,xPASS,yPASS,0,intro_TMISSILE);
}

uint8_t RECUP_PANEL_TMISSILE(uint8_t xPASS,uint8_t yPASS){
if (yPASS>0) return 0;
uint8_t Byte1_=RECUPE_TOPBAR_TMISSILE(xPASS,yPASS);
uint8_t Byte2_=0;
switch (xPASS){
  case 2 ... 33:Byte2_=Byte1_&INVENTORY_TMISSILE(xPASS);break;
  case 40 ... 99:Byte2_=Byte1_&MUNITION_TMISSILE(xPASS);break;
  case 106 ... 124:Byte2_=Byte1_|NUMERIC_TMISSILE(xPASS);break;
  default:return Byte1_;break;
}return Byte2_;}

uint8_t INVENTORY_TMISSILE(uint8_t xPASS){
uint8_t X_=(ARM_TMISSILE.GET_SPARE()*8)+2;
if (xPASS<X_) return 0xff;
return 0x03;}

uint8_t MUNITION_TMISSILE(uint8_t xPASS){
uint8_t X_=(ARM_TMISSILE.GET_ROCKET()*6)+40;
if (xPASS<X_) return 0xff;
return 0x01;}

uint8_t NUMERIC_TMISSILE(uint8_t xPASS){
return recupe_SCORES_TMISSILE(xPASS);}

uint8_t recupe_SCORES_TMISSILE(uint8_t xPASS){
if (xPASS<(105)) {return 0;}
if (xPASS>(125)){return 0;}
return 
(SPEED_BLITZ_TMISSILE(106,0,xPASS,0,M10000_TMISSILE,police_TMISSILE)|
 SPEED_BLITZ_TMISSILE(110,0,xPASS,0,M1000_TMISSILE,police_TMISSILE)|
 SPEED_BLITZ_TMISSILE(114,0,xPASS,0,M100_TMISSILE,police_TMISSILE)|
 SPEED_BLITZ_TMISSILE(118,0,xPASS,0,M10_TMISSILE,police_TMISSILE)|
 SPEED_BLITZ_TMISSILE(122,0,xPASS,0,M1_TMISSILE,police_TMISSILE));
}

void COMPIL_SCO_TMISSILE(void){
M10000_TMISSILE=(Scores_TMISSILE/10000);
M1000_TMISSILE=(((Scores_TMISSILE)-(M10000_TMISSILE*10000))/1000);
M100_TMISSILE=(((Scores_TMISSILE)-(M1000_TMISSILE*1000)-(M10000_TMISSILE*10000))/100);
M10_TMISSILE=(((Scores_TMISSILE)-(M100_TMISSILE*100)-(M1000_TMISSILE*1000)-(M10000_TMISSILE*10000))/10);
M1_TMISSILE=((Scores_TMISSILE)-(M10_TMISSILE*10)-(M100_TMISSILE*100)-(M1000_TMISSILE*1000)-(M10000_TMISSILE*10000));
}

void SNDBOX_TMISSILE(uint8_t Snd_){
uint8_t t;
switch(Snd_){
  case(0):TinySound(100,250);TinySound(20,250);break;
  case(1):for(t=1;t<255;t++){TinySound(50,2);TinySound(t,2);}break;
  case(2):for(t=200;t>10;t--){TinySound(200-t,3);TinySound(t,12);}break;
  case(3):TinySound(200,140);TinySound(100,140);break;
  case(4):TinySound(2,140);TinySound(200,14);break;
  case(5):TinySound(200,6);TinySound(150,6);break;
  default:break; 
}}



uint8_t BACKGROUND(uint8_t xPASS,uint8_t yPASS,const uint8_t *BITMAP){
return pgm_read_byte(&BITMAP[xPASS+(yPASS*128)]);
}

uint8_t SPEED_BLITZ(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES){
uint8_t WSPRITE=(pgm_read_byte(&SPRITES[0]));
uint8_t HSPRITE=(pgm_read_byte(&SPRITES[1]));
if ((xPASS>((xPos+(WSPRITE-1))))||(xPASS<xPos)||((yPASS<yPos)||(yPASS>(yPos+(HSPRITE-1))))) {return 0x00;}
return pgm_read_byte(&SPRITES[2+(((xPASS-xPos)+((yPASS-yPos)*(WSPRITE)))+(FRAME*(HSPRITE*WSPRITE)))]);
}



int8_t Mymap(int8_t x, int8_t in_min, int8_t in_max, int8_t out_min, int8_t out_max){
return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

uint8_t Trace_LINE(uint8_t DESACTIVE_,int8_t x1,int8_t y1,int8_t x2,int8_t y2,uint8_t xPASS,uint8_t yPASS){
uint8_t Y1_=RecupeLineY_TMISSILE(y1);
uint8_t Y2_=RecupeLineY_TMISSILE(y2);
if ((xPASS<x1)&&(xPASS<x2)) return 0;
if ((xPASS>x1)&&(xPASS>x2)) return 0;
if (Y1_<Y2_) {
if (yPASS<Y1_){return 0;}
if (yPASS>Y2_){return 0;}
}else{
if (yPASS>Y1_){return 0;}
if (yPASS<Y2_){return 0;} 
}
return DIRECTION_LINE(DESACTIVE_,x1,y1,x2,y2,xPASS,yPASS);
}

uint8_t DIRECTION_LINE(uint8_t DESACTIVE_,int8_t x1,int8_t y1,int8_t x2,int8_t y2,uint8_t xPASS,uint8_t yPASS){
 uint8_t XL_=0;
 uint8_t YL_=0;
 uint8_t RESULTANT=0;
 uint8_t Yref_=0;
XL_=abs(x1-x2);
YL_=abs(y1-y2);
if ((XL_<YL_)&&(DESACTIVE_==0)) {
return Return_Full_Byte(x1,y1,x2,y2,xPASS,yPASS);
 }else{
RESULTANT=Mymap(xPASS,x1,x2,y1,y2);
Yref_=RecupeLineY_TMISSILE(RESULTANT);
if (Yref_==yPASS) {return (1<<(RecupeDecalageY_TMISSILE(RESULTANT)));}else{return 0;}
  }
}

uint8_t Return_Full_Byte(int8_t x1,int8_t y1,int8_t x2,int8_t y2,uint8_t xPASS,uint8_t yPASS){
uint8_t Byte_add_=0;
uint8_t t=0,tout=0;
uint8_t A_=0,B_=0;
A_=(yPASS<<3);
B_=(A_+7);
if (y1>y2){
Universal_Swap(&y1,&y2);
Universal_Swap(&x1,&x2);}
A_=(A_<y1)?y1:A_;
B_=(B_>y2)?y2:B_;
for (t=A_;t<B_+1;t++){
if (yPASS==RecupeLineY_TMISSILE(t)) {
tout=Mymap(t,y1,y2,x1,x2);
Byte_add_|=(tout==xPASS)?(0b00000001<<(RecupeDecalageY_TMISSILE(t))):0x00;
}}
return Byte_add_;
}

void Universal_Swap(int8_t *A_,int8_t *B_){ //for int8_t only
int8_t T_=*A_;
*A_=*B_;
*B_=T_;
}

uint8_t RECONSTRUCT_BYTE(uint8_t Min_,uint8_t Max_){
uint8_t A_=(0xff<<Min_);
uint8_t B_=0xff-(0xff<<Max_);
return (A_&B_);
}





