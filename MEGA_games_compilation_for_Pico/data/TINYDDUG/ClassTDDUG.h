//     >>>>>  MEGA COMPILATION for ESP8266/ESP8285  GPL v3 <<<<
//                    >>>>>  MEGA Tiny Joypad  <<<<
//                      Programmer: Daniel C 2020
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

#include "PictureTDDUG.h"

#define MAIN_ACCEL_SPEED_TDDUG 50
#define SPRITE_ACCEL_SPEED_TDDUG 50
#define ENEMY_SPEED_STEP_TDDUG 25


//PROTOTYPE
void SND_DDUG(void);
void SCORES_ADD_TDDUG(void);
uint8_t READ_GRID_TDDUG(int8_t X_,int8_t Y_);
uint8_t WRITE_GRID_TDDUG(int8_t X_,int8_t Y_);
uint8_t RecupeDecalageY_TDDUG(uint8_t Valeur);
int8_t RND_TDDUG(void);
void ANIM_UPDATE_MAIN_TDDUG(uint8_t Direct_);
void Sound_TDDUG(uint8_t freq_,uint8_t dur);

//PUBLIC VAR
int8_t RD_TDDUG=0;
uint8_t EXT_COUNT_TDDUG=0;
uint8_t EXT_GRID_TDDUG=0;
uint8_t M10000_TDDUG=0;
uint8_t M1000_TDDUG=0;
uint8_t M100_TDDUG=0;
uint8_t M10_TDDUG=0;
uint8_t M1_TDDUG=0;
uint8_t Anim_Enemy_TDDUG=0;
uint8_t Anim_Enemy_Frame_TDDUG=0;
uint8_t MAIN_SPEED_STEP_TDDUG=25;

//PUBLIC: STRUCT VAR
struct GAME_DATA_TDDUG {
uint8_t TimeLaps;
uint8_t  FirsT_Time;
uint8_t One_Time_TDDUG;
uint8_t Counter; 
uint8_t Trigger_Counter;
uint8_t MAIN_FRAME;
uint8_t MAIN_ANIM_FRAME;
uint8_t MAIN_ANIM;
uint8_t DIRECTION_ANIM;
uint16_t Scores;
uint8_t Skip_Frame;
uint8_t LEVEL;
uint8_t GO_OUT;
uint8_t NOSPRITE_GO_OUT;
uint8_t DEAD;
uint8_t LIVE;
uint8_t LIVE_COMP;
};

GAME_DATA_TDDUG GD_DDUG;

uint8_t GRID_TDDUG[12][3];

//start Sprite
class Sprite_TDDUG {
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
void PUT_X(int8_t XX);
void PUT_Y(int8_t YY);
void PUT_ACTIVE(int8_t ACT);
int8_t DIRECTION_X(void);
int8_t DIRECTION_Y(void);
void PUT_DIRECTION_X(int8_t D_X);
void PUT_DIRECTION_Y(int8_t D_Y);
};

int8_t Sprite_TDDUG::X(void){return x;}
int8_t Sprite_TDDUG::Y(void){return y;}
int8_t Sprite_TDDUG::ACTIVE(void){return active;}
void Sprite_TDDUG::PUT_X(int8_t XX){x=XX;}
void Sprite_TDDUG::PUT_Y(int8_t YY){y=YY;}
void Sprite_TDDUG::PUT_ACTIVE(int8_t ACT){active=ACT;}
int8_t Sprite_TDDUG::DIRECTION_X(void){return direction_x;}
int8_t Sprite_TDDUG::DIRECTION_Y(void){return direction_y;}
void Sprite_TDDUG::PUT_DIRECTION_X(int8_t D_X){direction_x=D_X;}
void Sprite_TDDUG::PUT_DIRECTION_Y(int8_t D_Y){direction_y=D_Y;}
//end sprite

//start Moving sprite
class Moving_Sprite_TDDUG:public Sprite_TDDUG {
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
void Ou_suis_je(uint8_t &x_,uint8_t &y_);
};

int8_t Moving_Sprite_TDDUG::SOMX(void){return Som_x;}
int8_t Moving_Sprite_TDDUG::SOMY(void){return Som_y;}
int8_t Moving_Sprite_TDDUG::SX(void){return sx;}
int8_t Moving_Sprite_TDDUG::SY(void){return sy;}
void Moving_Sprite_TDDUG::PUT_SX(int8_t SX_){sx=SX_;}
void Moving_Sprite_TDDUG::PUT_SY(int8_t SY_){sy=SY_;}
void Moving_Sprite_TDDUG::PUT_SOMX(int8_t PUT_SOMX_){Som_x=PUT_SOMX_;}
void Moving_Sprite_TDDUG::PUT_SOMY(int8_t PUT_SOMY_){Som_y=PUT_SOMY_;}
void Moving_Sprite_TDDUG::Ou_suis_je(uint8_t &x_,uint8_t &y_){uint8_t PX=x_-20;int8_t PY=y_-8;x_=PX>>2;y_=PY>>2;}
//end moving sprite

class Enemy_Sprite_TDDUG : public Moving_Sprite_TDDUG{
public:
uint8_t ANIM_DIRECT(void);
void PUT_ANIM_DIRECT(uint8_t H_Dir_);
void PUT_TYPE(uint8_t TY_);
uint8_t TYPE(void);
void PUT_TRACKING(int8_t TR_);
int8_t TRACKING(void);
void INIT(int8_t X_,int8_t Y_,int8_t Type_);
void HAUT(void);
void DROITE(void);
void BAS(void);
void GAUCHE(void);
void NEW_DIRECTION(int8_t dir_);
void NEW_LIMITE_DIRECTION(int8_t dir_);
void PUT_ANIM(uint8_t Ani_);
uint8_t ANIM(void);
uint8_t E_GRID_UPDATE_UP(void);
uint8_t E_GRID_UPDATE_DOWN(void);
uint8_t E_GRID_UPDATE_RIGHT(void);
uint8_t E_GRID_UPDATE_LEFT(void);
uint8_t FIRST(void);
void PUT_FIRST(uint8_t Fir_);
uint8_t BIG_ZIP(void);
void PUT_BIG_ZIP(uint8_t Fir_);
private:
uint8_t First;
uint8_t Type;
int8_t Tracking;
uint8_t Anim_Direct;
uint8_t Anim;
uint8_t Big_zip;
};

uint8_t Enemy_Sprite_TDDUG::BIG_ZIP(void){
return Big_zip;
}

void Enemy_Sprite_TDDUG::PUT_BIG_ZIP(uint8_t Fir_){
Big_zip=Fir_;
}

uint8_t Enemy_Sprite_TDDUG::FIRST(void){
return First;
}

void Enemy_Sprite_TDDUG::PUT_FIRST(uint8_t Fir_){
First=Fir_;
}

uint8_t Enemy_Sprite_TDDUG::ANIM_DIRECT(void){
return Anim_Direct;
}

void Enemy_Sprite_TDDUG::PUT_ANIM_DIRECT(uint8_t H_Dir_){
Anim_Direct=H_Dir_;
}

void Enemy_Sprite_TDDUG::PUT_TYPE(uint8_t TY_){
Type=TY_;
}

uint8_t Enemy_Sprite_TDDUG::TYPE(void){
return Type; 
}

void Enemy_Sprite_TDDUG::PUT_ANIM(uint8_t Ani_){
Anim=Ani_;
}

uint8_t Enemy_Sprite_TDDUG::ANIM(void){
return Anim; 
}

void Enemy_Sprite_TDDUG::PUT_TRACKING(int8_t TR_){
Tracking=TR_;
}

int8_t Enemy_Sprite_TDDUG::TRACKING(void){
return Tracking;
}

void Enemy_Sprite_TDDUG::INIT(int8_t X_,int8_t Y_,int8_t Type_){
PUT_TRACKING(1);
PUT_SOMX(0);
PUT_SOMY(0);
PUT_SX(0);
PUT_SY(0);
PUT_X(X_);
PUT_Y(Y_);
PUT_DIRECTION_X(RND_TDDUG());
PUT_DIRECTION_Y(RND_TDDUG());
PUT_ACTIVE(1);
First=0;
Type=Type_;
Big_zip=0;
}

void Enemy_Sprite_TDDUG::HAUT(void){
int8_t Sy_=SY(),y_=Y(),Somy_=SOMY();
int8_t T_SOMY=SOMY();
if ((T_SOMY+(-ENEMY_SPEED_STEP_TDDUG))<=-SPRITE_ACCEL_SPEED_TDDUG) {
  PUT_SOMY((T_SOMY+(-ENEMY_SPEED_STEP_TDDUG))+SPRITE_ACCEL_SPEED_TDDUG);
  PUT_Y(Y()-1);
  }else{
    PUT_SOMY(T_SOMY+(-ENEMY_SPEED_STEP_TDDUG));
    }
if ((E_GRID_UPDATE_UP())||(Y()<0)) {
PUT_SY(Sy_);
PUT_Y(y_);
PUT_SOMY(Somy_);
NEW_LIMITE_DIRECTION(1);
}else{
  NEW_DIRECTION(1);
  PUT_DIRECTION_Y(-1);
}}

void Enemy_Sprite_TDDUG::DROITE(void){
int8_t Sx_=SX(),x_=X(),Somx_=SOMX();
int8_t T_SOMX=SOMX();
if ((T_SOMX+ENEMY_SPEED_STEP_TDDUG)>=SPRITE_ACCEL_SPEED_TDDUG) {
  PUT_SOMX((T_SOMX+ENEMY_SPEED_STEP_TDDUG)-SPRITE_ACCEL_SPEED_TDDUG);
  PUT_X(X()+1);
  }else{
    PUT_SOMX(T_SOMX+ENEMY_SPEED_STEP_TDDUG);
    }
if ((E_GRID_UPDATE_RIGHT())||(X()>100)) {
PUT_SX(Sx_);
PUT_X(x_);
PUT_SOMX(Somx_);
NEW_LIMITE_DIRECTION(0);
}else{
   NEW_DIRECTION(0);
   PUT_DIRECTION_X(1);
}
if (X()!=x_) {PUT_ANIM_DIRECT(1);}
}  

void Enemy_Sprite_TDDUG::BAS(void){
int8_t Sy_=SY(),y_=Y(),Somy_=SOMY();
int8_t T_SOMY=SOMY();
if ((T_SOMY+ENEMY_SPEED_STEP_TDDUG)>=SPRITE_ACCEL_SPEED_TDDUG) {
  PUT_SOMY((T_SOMY+ENEMY_SPEED_STEP_TDDUG)-SPRITE_ACCEL_SPEED_TDDUG);
  PUT_Y(Y()+1);
  }else{
    PUT_SOMY(T_SOMY+ENEMY_SPEED_STEP_TDDUG);
    }
if ((E_GRID_UPDATE_DOWN())||(Y()>48)) {
PUT_SY(Sy_);
PUT_Y(y_);
PUT_SOMY(Somy_);
NEW_LIMITE_DIRECTION(1);
}else{
  NEW_DIRECTION(1);
  PUT_DIRECTION_Y(1);
}}

void Enemy_Sprite_TDDUG::GAUCHE(void){
int8_t Sx_=SX(),x_=X(),Somx_=SOMX();
int8_t T_SOMX=SOMX();
if ((T_SOMX+(-ENEMY_SPEED_STEP_TDDUG))<=-SPRITE_ACCEL_SPEED_TDDUG) {
  PUT_SOMX((T_SOMX+(-ENEMY_SPEED_STEP_TDDUG))+SPRITE_ACCEL_SPEED_TDDUG);
  PUT_X(X()-1);
  }else{
    PUT_SOMX(T_SOMX+(-ENEMY_SPEED_STEP_TDDUG));
    }
if ((E_GRID_UPDATE_LEFT())||(X()<20)) {
PUT_SX(Sx_);
PUT_X(x_);
PUT_SOMX(Somx_);
NEW_LIMITE_DIRECTION(0);
}else{
NEW_DIRECTION(0);  
PUT_DIRECTION_X(-1);
}
if (X()!=x_) {PUT_ANIM_DIRECT(0);}
}

void Enemy_Sprite_TDDUG::NEW_LIMITE_DIRECTION(int8_t dir_){
switch(dir_){
  case(0):if (DIRECTION_X()==1) {PUT_DIRECTION_X(-1);}else{PUT_DIRECTION_X(1);}break;
  case(1):if (DIRECTION_Y()==1) {PUT_DIRECTION_Y(-1);}else{PUT_DIRECTION_Y(1);}break;  
default:break;
}}

void Enemy_Sprite_TDDUG::NEW_DIRECTION(int8_t dir_){
switch(dir_){
  case(0):if (RecupeDecalageY_TDDUG(X()-20)!=0) {PUT_DIRECTION_Y(RND_TDDUG());}break;  
  case(1):if (RecupeDecalageY_TDDUG(Y())!=0) {PUT_DIRECTION_X(RND_TDDUG());}break;  
}}

uint8_t Enemy_Sprite_TDDUG::E_GRID_UPDATE_RIGHT(void){
 uint8_t XX_=X()+7,YY_=Y();
 Ou_suis_je(XX_,YY_); 
 if (READ_GRID_TDDUG(XX_,YY_)==1) {return Tracking;}
 if (READ_GRID_TDDUG(XX_,YY_+1)==1) {return Tracking;}
 return 0;
  }

uint8_t Enemy_Sprite_TDDUG::E_GRID_UPDATE_LEFT(void){
  uint8_t XX_=X(),YY_=Y();
 Ou_suis_je(XX_,YY_); 
 if (READ_GRID_TDDUG(XX_,YY_)==1) {return Tracking;}
 if (READ_GRID_TDDUG(XX_,YY_+1)==1) {return Tracking;}
 return 0;
  }

uint8_t Enemy_Sprite_TDDUG::E_GRID_UPDATE_UP(void){
  uint8_t XX_=X(),YY_=Y();
 Ou_suis_je(XX_,YY_); 
 if (READ_GRID_TDDUG(XX_,YY_)==1) {return Tracking;}
 if (READ_GRID_TDDUG(XX_+1,YY_)==1) {return Tracking;} 
 return 0;
  }

uint8_t Enemy_Sprite_TDDUG::E_GRID_UPDATE_DOWN(void){
  uint8_t XX_=X(),YY_=Y()+7;
 Ou_suis_je(XX_,YY_); 
 if (READ_GRID_TDDUG(XX_,YY_)==1) {return Tracking;}
 if (READ_GRID_TDDUG(XX_+1,YY_)==1) {return Tracking;} 
 return 0;
  }
  
//start Main sprite
class Main_Sprite_TDDUG : public Moving_Sprite_TDDUG{
public:
void MHAUT(void);
void MDROITE(void);
void MBAS(void);
void MGAUCHE(void);
void INIT(void);
void WALK_RIGHT(void);
void WALK_LEFT(void);
void WALK_UP(void);
void WALK_DOWN(void);
void GRID_UPDATE_RIGHT(void);
void GRID_UPDATE_LEFT(void);
void GRID_UPDATE_UP(void);
void GRID_UPDATE_DOWN(void);
private:
};

void Main_Sprite_TDDUG::INIT(void){
PUT_X(60);
PUT_Y(32);
PUT_ACTIVE(1);
PUT_DIRECTION_Y(0);
PUT_DIRECTION_X(1);
PUT_SOMX(0);
PUT_SOMY(0);
PUT_SX(0);
PUT_SY(0);
}

void Main_Sprite_TDDUG::MHAUT(void){
int8_t T_SOMY=SOMY();
if ((T_SOMY+(-MAIN_SPEED_STEP_TDDUG))<=-MAIN_ACCEL_SPEED_TDDUG) {
  PUT_SOMY((T_SOMY+(-MAIN_SPEED_STEP_TDDUG))+MAIN_ACCEL_SPEED_TDDUG);
  PUT_Y(Y()-1);
  }else{
    PUT_SOMY(T_SOMY+(-MAIN_SPEED_STEP_TDDUG));
    }
ANIM_UPDATE_MAIN_TDDUG(3);
if(Y()<0) {PUT_Y(0);PUT_SY(0);PUT_SOMY(0);}
PUT_DIRECTION_Y(-1);
GRID_UPDATE_UP();
}

void Main_Sprite_TDDUG::MDROITE(void){
int8_t T_SOMX=SOMX();
if ((T_SOMX+MAIN_SPEED_STEP_TDDUG)>=MAIN_ACCEL_SPEED_TDDUG) {
  PUT_SOMX((T_SOMX+MAIN_SPEED_STEP_TDDUG)-MAIN_ACCEL_SPEED_TDDUG);
  PUT_X(X()+1);
  }else{
    PUT_SOMX(T_SOMX+MAIN_SPEED_STEP_TDDUG);
    }
ANIM_UPDATE_MAIN_TDDUG(0);
if(X()>100){PUT_X(100);PUT_SX(0);PUT_SOMX(0);}
PUT_DIRECTION_X(1);
GRID_UPDATE_RIGHT();
}  

void Main_Sprite_TDDUG::MBAS(void){
int8_t T_SOMY=SOMY();
if ((T_SOMY+MAIN_SPEED_STEP_TDDUG)>=MAIN_ACCEL_SPEED_TDDUG) {
  PUT_SOMY((T_SOMY+MAIN_SPEED_STEP_TDDUG)-MAIN_ACCEL_SPEED_TDDUG);
  PUT_Y(Y()+1);
  }else{
    PUT_SOMY(T_SOMY+MAIN_SPEED_STEP_TDDUG);
    }
ANIM_UPDATE_MAIN_TDDUG(1);
if(Y()>48) {PUT_Y(48);PUT_SY(0);PUT_SOMY(0);}  
PUT_DIRECTION_Y(1);
GRID_UPDATE_DOWN();
}

void Main_Sprite_TDDUG::MGAUCHE(void){
int8_t T_SOMX=SOMX();
if ((T_SOMX+(-MAIN_SPEED_STEP_TDDUG))<=-MAIN_ACCEL_SPEED_TDDUG) {
  PUT_SOMX((T_SOMX+(-MAIN_SPEED_STEP_TDDUG))+MAIN_ACCEL_SPEED_TDDUG);
  PUT_X(X()-1);
  }else{
    PUT_SOMX(T_SOMX+(-MAIN_SPEED_STEP_TDDUG));
    }
ANIM_UPDATE_MAIN_TDDUG(2);
if(X()<20) {PUT_X(20);PUT_SX(0);PUT_SOMX(0);}
PUT_DIRECTION_X(-1);
GRID_UPDATE_LEFT();
}

void Main_Sprite_TDDUG::WALK_RIGHT(void){
if (RecupeDecalageY_TDDUG(Y())==0) {MDROITE();
}else{
switch(DIRECTION_Y()){
  case  (1):MBAS(); break;
  case (-1):MHAUT();break;
  default:break;
  }}}

void Main_Sprite_TDDUG::WALK_LEFT(void){
if (RecupeDecalageY_TDDUG(Y())==0) {MGAUCHE();
}else{
switch(DIRECTION_Y()){
  case  (1):MBAS(); break;
  case (-1):MHAUT();break;
  default:break;
  }}}

void Main_Sprite_TDDUG::WALK_UP(void){
if (RecupeDecalageY_TDDUG(X()-20)==0) {MHAUT();
}else{
switch(DIRECTION_X()){
  case  (1):MDROITE(); break;
  case (-1):MGAUCHE();break;
  default:break;
  }}}

void Main_Sprite_TDDUG::WALK_DOWN(void){
if (RecupeDecalageY_TDDUG(X()-20)==0) {MBAS(); 
}else{
switch(DIRECTION_X()){
  case  (1):MDROITE(); break;
  case (-1):MGAUCHE();break;
  default:break;
  }}}

void Main_Sprite_TDDUG::GRID_UPDATE_RIGHT(void){
  uint8_t Snd=0;
  uint8_t XX_=X()+7,YY_=Y();
 Ou_suis_je(XX_,YY_); 
 if (READ_GRID_TDDUG(XX_,YY_)==1) {Snd=1;SCORES_ADD_TDDUG();WRITE_GRID_TDDUG(XX_,YY_);}
 if (READ_GRID_TDDUG(XX_,YY_+1)==1) {Snd=1;SCORES_ADD_TDDUG();WRITE_GRID_TDDUG(XX_,YY_+1);}
 if (Snd) SND_DDUG();
  }
  
void Main_Sprite_TDDUG::GRID_UPDATE_LEFT(void){
    uint8_t Snd=0;
  uint8_t XX_=X(),YY_=Y();
 Ou_suis_je(XX_,YY_); 
 if (READ_GRID_TDDUG(XX_,YY_)==1) {Snd=1;SCORES_ADD_TDDUG();WRITE_GRID_TDDUG(XX_,YY_);}
 if (READ_GRID_TDDUG(XX_,YY_+1)==1) {Snd=1;SCORES_ADD_TDDUG();WRITE_GRID_TDDUG(XX_,YY_+1);}
   if (Snd) SND_DDUG();
  }
  
void Main_Sprite_TDDUG::GRID_UPDATE_UP(void){
    uint8_t Snd=0;
  uint8_t XX_=X(),YY_=Y();
 Ou_suis_je(XX_,YY_); 
 if (READ_GRID_TDDUG(XX_,YY_)==1) {Snd=1;SCORES_ADD_TDDUG();WRITE_GRID_TDDUG(XX_,YY_);}
 if (READ_GRID_TDDUG(XX_+1,YY_)==1) {Snd=1;SCORES_ADD_TDDUG();WRITE_GRID_TDDUG(XX_+1,YY_);} 
  if (Snd) SND_DDUG();
  }
  
void Main_Sprite_TDDUG::GRID_UPDATE_DOWN(void){
    uint8_t Snd=0;
  uint8_t XX_=X(),YY_=Y()+7;
 Ou_suis_je(XX_,YY_); 
 if (READ_GRID_TDDUG(XX_,YY_)==1) {Snd=1;SCORES_ADD_TDDUG();WRITE_GRID_TDDUG(XX_,YY_);}
 if (READ_GRID_TDDUG(XX_+1,YY_)==1) {Snd=1;SCORES_ADD_TDDUG();WRITE_GRID_TDDUG(XX_+1,YY_);} 
  if (Snd) SND_DDUG();
  }
//end main sprite

//CLASS WEAPON
class WEAPON_TDDUG : public Sprite_TDDUG {
public:
void INIT_WEAPON(void);
void ADJUST_WEAPON(Main_Sprite_TDDUG &MS_);
void ADJUST_WEAPON2(WEAPON_TDDUG &W_,Main_Sprite_TDDUG &MS_);
void WEAPON_COLISION_TDDUG(WEAPON_TDDUG W_,uint8_t Nu_);
uint8_t ANIM_OR(void);
void PUT_ANIM_OR(uint8_t WA_);
void Ou_suis_je(uint8_t &x_,uint8_t &y_);
private:
uint8_t anim_or;
};

void WEAPON_TDDUG::INIT_WEAPON(void){
PUT_ACTIVE(0); 
}

void WEAPON_TDDUG::ADJUST_WEAPON(Main_Sprite_TDDUG &MS_){
Sound_TDDUG(100,1);
Sound_TDDUG(200,12);
switch(GD_DDUG.DIRECTION_ANIM){
 case(0):PUT_ANIM_OR(0);PUT_X(MS_.X()+8);PUT_Y(MS_.Y()+2);break; 
 case(1):PUT_ANIM_OR(1);PUT_X(MS_.X()+2);PUT_Y(MS_.Y()+8);break; 
 case(2):PUT_ANIM_OR(0);PUT_X(MS_.X()-4);PUT_Y(MS_.Y()+2);break; 
 case(3):PUT_ANIM_OR(1);PUT_X(MS_.X()+2);PUT_Y(MS_.Y()-4);break; 
 default:break;
}
WEAPON_TDDUG NUl;
WEAPON_COLISION_TDDUG(NUl,0);
}

void WEAPON_TDDUG::ADJUST_WEAPON2(WEAPON_TDDUG &W_,Main_Sprite_TDDUG &MS_){
uint8_t A_,B_,C_;
switch(GD_DDUG.DIRECTION_ANIM){
 case(0):A_=0;B_=(MS_.X()+12);C_=(MS_.Y()+2);break; 
 case(1):A_=(1);B_=(MS_.X()+2);C_=(MS_.Y()+12);break; 
 case(2):A_=(0);B_=(MS_.X()-8);C_=(MS_.Y()+2);break; 
 case(3):A_=(1);B_=(MS_.X()+2);C_=(MS_.Y()-8);break; 
 default:A_=0;B_=0;C_=0;break;
}
PUT_ANIM_OR(A_);PUT_X(B_);PUT_Y(C_);
WEAPON_COLISION_TDDUG(W_,1);
}

void WEAPON_TDDUG::WEAPON_COLISION_TDDUG(WEAPON_TDDUG W_,uint8_t Nu_){
uint8_t XX_=X()+2,YY_=Y()+2;
Ou_suis_je(XX_,YY_); 
if (READ_GRID_TDDUG(XX_,YY_)==1) {
 if (Nu_==0) {
  W_.PUT_ACTIVE(5);
  }else{PUT_ACTIVE(0);}
}}

uint8_t WEAPON_TDDUG::ANIM_OR(void){
return anim_or;
}

void WEAPON_TDDUG::PUT_ANIM_OR(uint8_t WA_){
anim_or=WA_;
}

void WEAPON_TDDUG::Ou_suis_je(uint8_t &x_,uint8_t &y_){
uint8_t PX=x_-20;
int8_t PY=y_-8;
x_=PX>>2;
y_=PY>>2;
}
