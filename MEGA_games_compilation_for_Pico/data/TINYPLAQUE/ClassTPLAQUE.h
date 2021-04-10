//    >>>>>  MEGA COMPILATION 0006 for ESP8266/ESP8285  GPL v3 <<<<
//                    >>>>>  MEGA Tiny Joypad  <<<<
//                  Programmer: Daniel C 2019-2020
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

//for ESP8266/ESP8285 at 80Mhz


#include "PictureTPLAQUE.h"

#define MAX_LEVEL_TPLAQUE 16
#define MAIN_ACCEL_SPEED_TPLAQUE 32
#define FOOD_ACCEL_SPEED_TPLAQUE 60
#define RENEW_NUMBER_TPLAQUE 20

//PUBLIC:VAR
int8_t RD_TPLAQUE=0;
uint8_t RNDPOS_TPLAQUE=19;

//PUBLIC: STRUCT VAR
struct GAME_DATA_TPLAQUE {
uint16_t Scores_TPLAQUE;
uint8_t Level;
uint8_t EXTRA_TEETH;
uint8_t EXTRA_TEETH_COMP;
int8_t up_down;
int8_t sp;
uint8_t renew;
uint8_t REGEN_NO;
uint8_t NOT_MOVE;
uint8_t SCAN_CHANGE_DIRECTION;
uint8_t DELAY_DIRECTION_CHANGE;
uint8_t Delay_Direction_Change;
uint8_t END_OF_GAME;
uint8_t RENEW_FOOD;
uint8_t x_move_active;
uint8_t Food_Type;
uint8_t TIMER_TEETH;
uint8_t Skip_Frame;
uint8_t TEETH_COUNT_UP;
uint8_t TEETH_COUNT_DOWN;
uint8_t TUBE_FUEL;
uint16_t TUBE_FUEL_TIMER;
uint16_t TUBE_FUEL_TIMER_REF;
uint8_t Tube_Refresh;
};

uint8_t RND_POS_TPLAQUE(void){
RNDPOS_TPLAQUE=(RNDPOS_TPLAQUE!=85)?RNDPOS_TPLAQUE+11:19;
return RNDPOS_TPLAQUE;
}

int8_t RND_TPLAQUE(void){
RD_TPLAQUE=(RD_TPLAQUE<11)?RD_TPLAQUE+1:0;
return pgm_read_byte(&RnD_TPLAQUE[RD_TPLAQUE]);
}

void Sound_TPLAQUE(uint8_t freq_,uint8_t dur){
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

GAME_DATA_TPLAQUE GD;

//start Sprite
class Sprite_TPLAQUE {
private:
int8_t x;
int8_t y;
int8_t direction_x;
int8_t direction_y;
int8_t active;
public:
int8_t X(void);
int8_t Y(void);
int8_t ACTIVE(void);
void PUT_X(int8_t XX_);
void PUT_Y(int8_t YY_);
void PUT_ACTIVE(int8_t ACT);
int8_t DIRECTION_X(void);
int8_t DIRECTION_Y(void);
void PUT_DIRECTION_X(int8_t D_X);
void PUT_DIRECTION_Y(int8_t D_Y);
};
int8_t Sprite_TPLAQUE::X(void){return x;}
int8_t Sprite_TPLAQUE::Y(void){return y;}
int8_t Sprite_TPLAQUE::ACTIVE(void){return active;}
void Sprite_TPLAQUE::PUT_X(int8_t XX_){x=XX_;}
void Sprite_TPLAQUE::PUT_Y(int8_t YY_){y=YY_;}
void Sprite_TPLAQUE::PUT_ACTIVE(int8_t ACT){active=ACT;}
int8_t Sprite_TPLAQUE::DIRECTION_X(void){return direction_x;}
int8_t Sprite_TPLAQUE::DIRECTION_Y(void){return direction_y;}
void Sprite_TPLAQUE::PUT_DIRECTION_X(int8_t D_X){direction_x=D_X;}
void Sprite_TPLAQUE::PUT_DIRECTION_Y(int8_t D_Y){direction_y=D_Y;}
//end sprite

//start Moving sprite
class Moving_Sprite_TPLAQUE:public Sprite_TPLAQUE {
private:
int8_t Som_x;
int8_t Som_y;
int8_t sx;
int8_t sy;
public:
int8_t SOMX(void);
int8_t SOMY(void);
int8_t SX(void);
int8_t SY(void);
void PUT_SX(int8_t SX_);
void PUT_SY(int8_t SY_);
void PUT_SOMX(int8_t PUT_SOMX_);
void PUT_SOMY(int8_t PUT_SOMX_);
void HAUT(void);
void DROITE(void);
void BAS(void);
void GAUCHE(void);
};
int8_t Moving_Sprite_TPLAQUE::SOMX(void){return Som_x;}
int8_t Moving_Sprite_TPLAQUE::SOMY(void){return Som_y;}
int8_t Moving_Sprite_TPLAQUE::SX(void){return sx;}
int8_t Moving_Sprite_TPLAQUE::SY(void){return sy;}
void Moving_Sprite_TPLAQUE::PUT_SX(int8_t SX_){sx=SX_;}
void Moving_Sprite_TPLAQUE::PUT_SY(int8_t SY_){sy=SY_;}
void Moving_Sprite_TPLAQUE::PUT_SOMX(int8_t PUT_SOMX_){Som_x=PUT_SOMX_;}
void Moving_Sprite_TPLAQUE::PUT_SOMY(int8_t PUT_SOMY_){Som_y=PUT_SOMY_;}
void Moving_Sprite_TPLAQUE::HAUT(void){
int8_t T_SOMY=SOMY();
if ((T_SOMY+(-GD.sp))<=-FOOD_ACCEL_SPEED_TPLAQUE) {PUT_SOMY((T_SOMY+(-GD.sp))+FOOD_ACCEL_SPEED_TPLAQUE);PUT_Y(Y()-1);}else{PUT_SOMY(T_SOMY+(-GD.sp));}
}
void Moving_Sprite_TPLAQUE::DROITE(void){
int8_t T_SOMX=SOMX();
if ((T_SOMX+GD.sp)>=FOOD_ACCEL_SPEED_TPLAQUE) {PUT_SOMX((T_SOMX+GD.sp)-FOOD_ACCEL_SPEED_TPLAQUE);PUT_X(X()+1);}else{PUT_SOMX(T_SOMX+GD.sp);}
}  
void Moving_Sprite_TPLAQUE::BAS(void){
int8_t T_SOMY=SOMY();
if ((T_SOMY+GD.sp)>=FOOD_ACCEL_SPEED_TPLAQUE) {PUT_SOMY((T_SOMY+GD.sp)-FOOD_ACCEL_SPEED_TPLAQUE);PUT_Y(Y()+1);}else{PUT_SOMY(T_SOMY+GD.sp);}
}
void Moving_Sprite_TPLAQUE::GAUCHE(void){
int8_t T_SOMX=SOMX();
if ((T_SOMX+(-GD.sp))<=-FOOD_ACCEL_SPEED_TPLAQUE) {PUT_SOMX((T_SOMX+(-GD.sp))+FOOD_ACCEL_SPEED_TPLAQUE);PUT_X(X()-1);}else{PUT_SOMX(T_SOMX+(-GD.sp));}
}
//end moving sprite

//start Food_sprite
class Food_Sprite_TPLAQUE:public Moving_Sprite_TPLAQUE {
private:
uint8_t colapsed;
uint8_t Start_Pos;
public:
uint8_t COLAPSED();
uint8_t START_POS();
void COPY_OBJ(Food_Sprite_TPLAQUE &T_OBJ);
void PUT_COLAPSED(uint8_t COL_);
void PUT_START_POS(uint8_t x_t);
void CREAT_FOOD();
void MOVE_UPDATE();
void ADJUST_X();
void RESET_OBJ();
void DISABLE_RESET(void);
};
void Food_Sprite_TPLAQUE::PUT_COLAPSED(uint8_t COL_){colapsed=COL_;}
uint8_t Food_Sprite_TPLAQUE::COLAPSED(void){return colapsed;}
void Food_Sprite_TPLAQUE::COPY_OBJ(Food_Sprite_TPLAQUE &T_OBJ){
PUT_COLAPSED(1);
PUT_START_POS(T_OBJ.START_POS()+11);
PUT_X(T_OBJ.X()+11);
PUT_Y(T_OBJ.Y());
PUT_DIRECTION_X(T_OBJ.DIRECTION_X());
PUT_DIRECTION_Y(T_OBJ.DIRECTION_Y());
PUT_SOMX(T_OBJ.SOMX());
PUT_SOMY(T_OBJ.SOMY());
}

void Food_Sprite_TPLAQUE::ADJUST_X(void){
if (X()>(START_POS())) {GAUCHE();}
else if (X()<(START_POS())) {DROITE();}
else{
if (START_POS()!=0) {
PUT_START_POS(0);
PUT_SOMX(0);
PUT_SOMY(0);
PUT_DIRECTION_X(0);
switch(GD.up_down){
case(0):PUT_DIRECTION_Y(-1);PUT_SY(0);break;
case(1):PUT_DIRECTION_Y(1);PUT_SY(0);break;
default:break;
}}}
}

uint8_t Food_Sprite_TPLAQUE::START_POS(void){
return Start_Pos;
}

void Food_Sprite_TPLAQUE::PUT_START_POS(uint8_t x_t){
Start_Pos=x_t;
}

void Food_Sprite_TPLAQUE::CREAT_FOOD(void){
RESET_OBJ();
if (START_POS()>55) {
PUT_X(116);
}else{
PUT_X(-4);
}
switch(GD.up_down){
case(0):PUT_Y(46);break;
case(1):PUT_Y(17);break;
default:break;
}}

void Food_Sprite_TPLAQUE::RESET_OBJ(void){
PUT_START_POS(RND_POS_TPLAQUE());
PUT_COLAPSED(0);
PUT_ACTIVE(1);
PUT_DIRECTION_X(0);
PUT_DIRECTION_Y(0);
PUT_SOMX(0);
PUT_SOMY(0);
}

void Food_Sprite_TPLAQUE::DISABLE_RESET(void){
PUT_ACTIVE(0);
}

void Food_Sprite_TPLAQUE::MOVE_UPDATE(){
if (ACTIVE()==1) {
if (START_POS()!=0) {
ADJUST_X();
ADJUST_X();
ADJUST_X();
 }else{
switch(DIRECTION_X()){
  case 0:break;
  case 1:DROITE();if (X()>116) {PUT_X(6);}break;
  case -1:GAUCHE();if (X()<6) {PUT_X(116);}break;
  default:break;
}
switch(DIRECTION_Y()){
  case 0:break;
  case 1:BAS();if (Y()>60) {PUT_ACTIVE(0);}break;
  case -1:HAUT();if (Y()<1) {PUT_ACTIVE(0);}break;
  default:break;
}}}}

//start Main sprite
class Main_Sprite_TPLAQUE : public Moving_Sprite_TPLAQUE{
public:
void MHAUT(void);
void MDROITE(void);
void MBAS(void);
void MGAUCHE(void);
void DECEL_X(void);
void DECEL_Y(void);
void LIMIT_CHECK(void);
void INIT(void);
private:
};

void Main_Sprite_TPLAQUE::INIT(void){
PUT_X(60);
PUT_Y(38);
PUT_ACTIVE(1);
PUT_DIRECTION_Y(-1);
PUT_DIRECTION_X(0);
PUT_SOMX(0);
PUT_SOMY(0);
PUT_SX(0);
PUT_SY(0);
}

void Main_Sprite_TPLAQUE::MHAUT(void){
int8_t T_SOMY=SOMY();
int8_t T_SY=SY();
if (T_SY>-MAIN_ACCEL_SPEED_TPLAQUE) {PUT_SY(T_SY-1);}
if ((T_SOMY+T_SY)<=0) {
if ((T_SOMY+T_SY)<=-MAIN_ACCEL_SPEED_TPLAQUE) {PUT_SOMY((T_SOMY+T_SY)+MAIN_ACCEL_SPEED_TPLAQUE);PUT_Y(Y()-1);}else{PUT_SOMY(T_SOMY+T_SY);}
}else{DECEL_Y();}
PUT_DIRECTION_Y(-1);
LIMIT_CHECK();
}

void Main_Sprite_TPLAQUE::MDROITE(void){
int8_t T_SOMX=SOMX();
int8_t T_SX=SX();
if (T_SX<MAIN_ACCEL_SPEED_TPLAQUE) {PUT_SX(T_SX+1);}
if ((T_SOMX+T_SX)>=0) {
if ((T_SOMX+T_SX)>=MAIN_ACCEL_SPEED_TPLAQUE) {PUT_SOMX((T_SOMX+T_SX)-MAIN_ACCEL_SPEED_TPLAQUE);PUT_X(X()+1);}else{PUT_SOMX(T_SOMX+T_SX);}
}else{DECEL_X();}
LIMIT_CHECK();}
    
void Main_Sprite_TPLAQUE::MBAS(void){
int8_t T_SOMY=SOMY();
int8_t T_SY=SY();
if (T_SY<MAIN_ACCEL_SPEED_TPLAQUE) {PUT_SY(T_SY+1);}
if ((T_SOMY+T_SY)>=0) {
if ((T_SOMY+T_SY)>=MAIN_ACCEL_SPEED_TPLAQUE) {PUT_SOMY((T_SOMY+T_SY)-MAIN_ACCEL_SPEED_TPLAQUE);PUT_Y(Y()+1);}else{PUT_SOMY(T_SOMY+T_SY);}
}else{DECEL_Y();}
PUT_DIRECTION_Y(1);
LIMIT_CHECK();}
    
void Main_Sprite_TPLAQUE::MGAUCHE(void){
int8_t T_SOMX=SOMX();
int8_t T_SX=SX();
if (T_SX>-MAIN_ACCEL_SPEED_TPLAQUE) {PUT_SX(T_SX-1);}
if ((T_SOMX+T_SX)<=0) {
if ((T_SOMX+T_SX)<=-MAIN_ACCEL_SPEED_TPLAQUE) {PUT_SOMX((T_SOMX+T_SX)+MAIN_ACCEL_SPEED_TPLAQUE);PUT_X(X()-1);}else{PUT_SOMX(T_SOMX+T_SX);}
}else{DECEL_X();}LIMIT_CHECK();}
    
void Main_Sprite_TPLAQUE::DECEL_Y(void){
int8_t T_SOMY=SOMY();
int8_t T_SY=SY();
if ((T_SOMY+T_SY)>=0) {
if (T_SY>0) {PUT_SY(T_SY-1);}
if ((T_SOMY+T_SY)>=MAIN_ACCEL_SPEED_TPLAQUE) {PUT_SOMY((T_SOMY+T_SY)-MAIN_ACCEL_SPEED_TPLAQUE);PUT_Y(Y()+1);}else{PUT_SOMY(T_SOMY+T_SY);}
}else{
if (T_SY<0) {PUT_SY(T_SY+1);}
if ((T_SOMY+T_SY)<=-MAIN_ACCEL_SPEED_TPLAQUE) {PUT_SOMY((T_SOMY+T_SY)+MAIN_ACCEL_SPEED_TPLAQUE);PUT_Y(Y()-1);}else{PUT_SOMY(T_SOMY+T_SY);}
}LIMIT_CHECK();}

void Main_Sprite_TPLAQUE::DECEL_X(void){
int8_t T_SOMX=SOMX();
int8_t T_SX=SX();
if ((T_SOMX+T_SX)>=0) {
if (T_SX>0) {PUT_SX(T_SX-1);}
if ((T_SOMX+T_SX)>=MAIN_ACCEL_SPEED_TPLAQUE) {PUT_SOMX((T_SOMX+T_SX)-MAIN_ACCEL_SPEED_TPLAQUE);PUT_X(X()+1);}else{PUT_SOMX(T_SOMX+T_SX);}
}else{
if (T_SX<0) {PUT_SX(T_SX+1);}
if ((T_SOMX+T_SX)<=-MAIN_ACCEL_SPEED_TPLAQUE) {PUT_SOMX((T_SOMX+T_SX)+MAIN_ACCEL_SPEED_TPLAQUE);PUT_X(X()-1);}else{PUT_SOMX(T_SOMX+T_SX);}
}LIMIT_CHECK();}

void Main_Sprite_TPLAQUE::LIMIT_CHECK(void){
if(X()<11) {PUT_X(11);PUT_SX(0);PUT_SOMX(0);}
if(X()>108){PUT_X(108);PUT_SX(0);PUT_SOMX(0);}
if(Y()<17) {PUT_Y(17);PUT_SY(0);PUT_SOMY(0);}
if(Y()>41) {PUT_Y(41);PUT_SY(0);PUT_SOMY(0);}  
if (Y()<18) {PUT_DIRECTION_Y(1);}
if (Y()>40) {PUT_DIRECTION_Y(-1);}
} 
//end main sprite

//START WAPON_SPRITE
class Weapon_Sprite_TPLAQUE:public Sprite_TPLAQUE {
private:
public:
void Start(Main_Sprite_TPLAQUE Main_S_);
void Update(void);
uint8_t COLLISION_DETECT(void);
};

void Weapon_Sprite_TPLAQUE::Start(Main_Sprite_TPLAQUE Main_S_){
if (ACTIVE()==0) {
Sound_TPLAQUE(200,4);
PUT_ACTIVE(1);
PUT_Y(Main_S_.Y()+2);
PUT_DIRECTION_Y(Main_S_.DIRECTION_Y());
}}

void Weapon_Sprite_TPLAQUE::Update(void){
if (ACTIVE()>0) {
switch(DIRECTION_Y()){
 case -1:PUT_Y(Y()-2);break;
 case 1:PUT_Y(Y()+2);break;
}}
if (COLLISION_DETECT()) {PUT_ACTIVE(0);}
}

uint8_t Weapon_Sprite_TPLAQUE::COLLISION_DETECT(void){if ((Y()<9)||(Y()>56)) {return 1;}return 0;}
//END WAPON SPRITE




