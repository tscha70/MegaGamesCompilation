//     >>>>>  MEGA COMPILATION for ESP8266/ESP8285  GPL v3 <<<<
//                    >>>>>  MEGA Tiny Joypad  <<<<
//                    Programmer: Daniel C 2019-2020
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


#include "PIC_TMISSILE.h"
//DEFINE CLASS CROSS
#define CROSS_ACCEL_SPEEDX_TMISSILE 6
#define CROSS_ACCEL_SPEEDY_TMISSILE 4 
#define CROSS_ACCEL_STEPX_TMISSILE 3
#define CROSS_ACCEL_STEPY_TMISSILE 2
#define SPEED_SHOOT_TMISSILE 3

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

uint8_t blitzSprite_TMISSILE(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES);
uint8_t SplitSpriteDecalageY_TMISSILE(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN);
int8_t RecupeLineY_TMISSILE(int8_t Valeur);
uint8_t RecupeDecalageY_TMISSILE(uint8_t Valeur);

uint8_t SPEED_BLITZ_TMISSILE(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES){
uint8_t WSPRITE=(pgm_read_byte(&SPRITES[0]));
uint8_t HSPRITE=(pgm_read_byte(&SPRITES[1]));
if ((xPASS>((xPos+(WSPRITE-1))))||(xPASS<xPos)||((yPASS<yPos)||(yPASS>(yPos+(HSPRITE-1))))) {return 0x00;}
return pgm_read_byte(&SPRITES[2+(((xPASS-xPos)+((yPASS-yPos)*(WSPRITE)))+(FRAME*(HSPRITE*WSPRITE)))]);
}

uint8_t blitzSprite_TMISSILE(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES){
uint8_t OUTBYTE;
uint8_t WSPRITE=(pgm_read_byte(&SPRITES[0]));
uint8_t HSPRITE=(pgm_read_byte(&SPRITES[1]));
uint16_t Wmax=((HSPRITE*WSPRITE)+1);
uint16_t PICBYTE=FRAME*(Wmax-1);
int8_t RECUPELINEY=RecupeLineY_TMISSILE(yPos);
if ((xPASS>((xPos+(WSPRITE-1))))||(xPASS<xPos)||((RECUPELINEY>yPASS)||((RECUPELINEY+(HSPRITE))<yPASS))) {return 0x00;}
int8_t SPRITEyLINE=(yPASS-(RECUPELINEY));
uint8_t SPRITEyDECALAGE=(RecupeDecalageY_TMISSILE(yPos));
uint16_t ScanA=(((xPASS-xPos)+(SPRITEyLINE*WSPRITE))+2);
uint16_t ScanB=(((xPASS-xPos)+((SPRITEyLINE-1)*WSPRITE))+2);
if (ScanA>Wmax) {OUTBYTE=0x00;}else{OUTBYTE=SplitSpriteDecalageY_TMISSILE(SPRITEyDECALAGE,pgm_read_byte(&SPRITES[ScanA+(PICBYTE)]),1);}
if ((SPRITEyLINE>0)) {
uint8_t OUTBYTE2=SplitSpriteDecalageY_TMISSILE(SPRITEyDECALAGE,pgm_read_byte(&SPRITES[ScanB+(PICBYTE)]),0);
if (ScanB>Wmax) {return OUTBYTE;}else{return OUTBYTE|OUTBYTE2;}
}else{return OUTBYTE;}
}

uint8_t SplitSpriteDecalageY_TMISSILE(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN){
if (UPorDOWN) {return Input<<decalage;}
return Input>>(8-decalage);
}

int8_t RecupeLineY_TMISSILE(int8_t Valeur){
return (Valeur>>3); 
}

uint8_t RecupeDecalageY_TMISSILE(uint8_t Valeur){
return (Valeur-((Valeur>>3)<<3));
}

//CLASS ARMY 
class ARMY_TMISSILE{
public:
void RESET_WEAPON(uint8_t LEVEL_);
uint8_t USE_WEAPON(void);
void ATTACK_WEAPON(void);
uint8_t GET_SPARE(void);
uint8_t GET_ROCKET(void);
private:
uint8_t SPARE;
uint8_t ROCKET; 
};

class STATIC_SPRITE_TMISSILE {
  public:
  void INIT(int8_t X_,int8_t Y_,uint8_t ACTIVE_);
  void PUT_X(int8_t X_);
  void PUT_Y(int8_t Y_);
  void PUT_ACTIVE(uint8_t ACTIVE_);
  int8_t GET_X(void);
  int8_t GET_Y(void);
  uint8_t GET_ACTIVE(void);
  private:
  int8_t X;
  int8_t Y;
  uint8_t ACTIVE;
};

class STATIC_SPRITE_ANIM_TMISSILE:public STATIC_SPRITE_TMISSILE {
  public:
void INIT_DOME(int8_t X_,int8_t Y_,uint8_t ACTIVE_);
void PUT_FRAME(uint8_t FRAME_);
uint8_t PROGRESS_ANIM(void);
uint8_t GET_FRAME(void);
  private:
uint8_t FRAME;
};

class CROSS:public STATIC_SPRITE_TMISSILE{
public:
void INIT(void);
void RIGHT(void);
void LEFT(void);
void DOWN(void);
void UP(void);

void R(void);
void D(void);
void U(void);
void L(void);

void DECELX(void);
void DECELY(void);

void LIMITR(void);
void LIMITL(void);
void LIMITU(void);
void LIMITD(void);
private:
};

class LINE_TMISSILE {
public:
void RESET(void);
void INIT(int8_t START_X_,int8_t END_X_,uint8_t ACTIVE_);
void DOME_COLLISION(STATIC_SPRITE_ANIM_TMISSILE *DOME_,ARMY_TMISSILE *ARM_);
uint8_t PROGRESS(STATIC_SPRITE_ANIM_TMISSILE *DOME_,ARMY_TMISSILE *ARM_);
int8_t GET_START_X(void);
int8_t GET_POS_X(void);
int8_t GET_POS_Y(void);
int8_t GET_END_X(void);
uint8_t GET_yPass(void);
uint8_t GET_yDeca(void);
uint8_t GET_ACTIVE(void);  
uint8_t GET_TRACK(void);  
void PUT_START_X(int8_t START_X_);
void PUT_POS_X(int8_t POS_X_);
void PUT_POS_Y(int8_t POS_Y_);
void PUT_END_X(int8_t END_X_); 
void PUT_ACTIVE(uint8_t ACTIVE_);  
void PUT_TRACK(uint8_t TRACK_);  
  private:
int8_t START_X;
int8_t POS_X;
int8_t POS_Y;
uint8_t yPass;
uint8_t yDeca;
uint8_t Track;
int8_t END_X;
uint8_t ACTIVE;
};

class DEFENCE:public STATIC_SPRITE_TMISSILE{
public:
void UPDATE_DEFENCE(void);
void INIT(void);
void NEW(int8_t xEND_,int8_t yEND_);
private: 
float XF=63;
float YF=51;
float XCF;
float YCF;
uint8_t Count;
int8_t SWAP_XY;
};

class CLK {
public:
void INIT(uint8_t Start_,uint8_t End_,uint8_t Loop_);
uint8_t PROGRESS(void);
void RESET(void);
private:
uint8_t Start;
uint8_t End;
uint8_t Pos;
uint8_t Trig;
uint8_t Loop;
};
//PROTOTYPE
void Create_New_Intercept_TMISSILE(int8_t X_,int8_t Y_);
void SNDBOX_TMISSILE(uint8_t Snd_);
void Tiny_Flip_TMISSILE(void);

//class ARMY
void ARMY_TMISSILE::RESET_WEAPON(uint8_t LEVEL_){
 if (LEVEL_>4) {SPARE=4;}else{SPARE=3;}
ROCKET=10;
}

uint8_t ARMY_TMISSILE::USE_WEAPON(void){
if (ROCKET>0) {ROCKET--;}else{
if (SPARE>0) {SPARE--;ROCKET=9;}else{return 0;} 
}return 1;}

void ARMY_TMISSILE::ATTACK_WEAPON(void){
if (ROCKET>0) {
while(1){
if (ROCKET>0) {USE_WEAPON();SNDBOX_TMISSILE(5);}else{goto Exit_;} 
}
Exit_:;
}else{
if (SPARE>0) {SPARE--;SNDBOX_TMISSILE(3);} 
}
Tiny_Flip_TMISSILE();
}

uint8_t ARMY_TMISSILE::GET_SPARE(void){
return SPARE; 
}

uint8_t ARMY_TMISSILE::GET_ROCKET(void){
return ROCKET; 
}
//class ARMY END

//CLASS STATIC SPRITE 
  void STATIC_SPRITE_TMISSILE::INIT(int8_t X_,int8_t Y_,uint8_t ACTIVE_){X=X_;Y=Y_;ACTIVE=ACTIVE_;}
  void STATIC_SPRITE_TMISSILE::PUT_X(int8_t X_){X=X_;}
  void STATIC_SPRITE_TMISSILE::PUT_Y(int8_t Y_){Y=Y_;}
  void STATIC_SPRITE_TMISSILE::PUT_ACTIVE(uint8_t ACTIVE_){ACTIVE=ACTIVE_;} 
  int8_t STATIC_SPRITE_TMISSILE::GET_X(void){return X;}
  int8_t STATIC_SPRITE_TMISSILE::GET_Y(void){return Y;} 
  uint8_t STATIC_SPRITE_TMISSILE::GET_ACTIVE(void){return ACTIVE;}
//CLASS STATIC SPRITE END

//CLASS STATIC ANIM SPRITE 
void STATIC_SPRITE_ANIM_TMISSILE::INIT_DOME(int8_t X_,int8_t Y_,uint8_t ACTIVE_){INIT(X_,Y_,ACTIVE_);FRAME=0;}

uint8_t STATIC_SPRITE_ANIM_TMISSILE::PROGRESS_ANIM(void){
if (FRAME<6) {FRAME++;}else{
FRAME=0;
PUT_ACTIVE(0);
}
return FRAME;
}

void STATIC_SPRITE_ANIM_TMISSILE::PUT_FRAME(uint8_t FRAME_){
FRAME=FRAME_;
}

uint8_t STATIC_SPRITE_ANIM_TMISSILE::GET_FRAME(void){
return FRAME;
}
//CLASS STATIC ANIM SPRITE END

//CLASS LINE TMISSILE
void LINE_TMISSILE::RESET(void){
ACTIVE=0;
}

void LINE_TMISSILE::INIT(int8_t START_X_,int8_t END_X_,uint8_t ACTIVE_){
  START_X=START_X_;
  POS_X=START_X;
  POS_Y=11;
  END_X=END_X_;
  ACTIVE=ACTIVE_;
  Track=POS_Y;
  yPass=0;
  yDeca=0;
  }

void LINE_TMISSILE::DOME_COLLISION(STATIC_SPRITE_ANIM_TMISSILE *DOME_,ARMY_TMISSILE *ARM_){
if ((END_X>54)&&(END_X<73)) {ARM_->ATTACK_WEAPON();}
for(uint8_t t=0;t<NUM_of_DOME_TMISSILE;t++){
  if  (DOME_[t].GET_ACTIVE()) { 
    if (((END_X)>(DOME_[t].GET_X()))&&((END_X)<(DOME_[t].GET_X()+14))) {
    DOME_[t].PUT_FRAME(1);
    goto Out_;
    }
  }
}
Out_:;
}

uint8_t LINE_TMISSILE::PROGRESS(STATIC_SPRITE_ANIM_TMISSILE *DOME_,ARMY_TMISSILE *ARM_){ 
if (Track<55) {Track++;}else{DOME_COLLISION(DOME_,ARM_);ACTIVE=0;return 0;}
yPass=RecupeLineY_TMISSILE(Track);
yDeca=(0xff>>(7-RecupeDecalageY_TMISSILE(Track)));
return 0;
}

int8_t LINE_TMISSILE::GET_START_X(void){return START_X;}
int8_t LINE_TMISSILE::GET_POS_X(void){return POS_X;}
int8_t LINE_TMISSILE::GET_POS_Y(void){return POS_Y;}
uint8_t LINE_TMISSILE::GET_yPass(void){return yPass;}
uint8_t LINE_TMISSILE::GET_yDeca(void){return yDeca;}
int8_t LINE_TMISSILE::GET_END_X(void){return END_X;}
uint8_t LINE_TMISSILE::GET_ACTIVE(void){return ACTIVE;} 
uint8_t LINE_TMISSILE::GET_TRACK(void){return Track;}
void LINE_TMISSILE::PUT_START_X(int8_t START_X_){START_X=START_X_;}
void LINE_TMISSILE::PUT_POS_X(int8_t POS_X_){POS_X=POS_X_;}
void LINE_TMISSILE::PUT_POS_Y(int8_t POS_Y_){POS_Y=POS_Y_;}
void LINE_TMISSILE::PUT_END_X(int8_t END_X_){END_X=END_X_;}
void LINE_TMISSILE::PUT_ACTIVE(uint8_t ACTIVE_){ACTIVE=ACTIVE_;} 
void LINE_TMISSILE::PUT_TRACK(uint8_t TRACK_){Track=TRACK_;} 
//CLASS LINE TMISSILE END

//CLASS SHIELD:LINE_TMISSILE
void DEFENCE::UPDATE_DEFENCE(void){
if (Count>0) {
  XCF=XCF+(XF);
  YCF=YCF+(YF);
  PUT_X((XCF));
  PUT_Y((YCF));
 Count--; 
  }else{
    PUT_ACTIVE(0);
    Create_New_Intercept_TMISSILE(GET_X()-3,GET_Y()-6);
}}

void DEFENCE::INIT(void){
PUT_X(0);
PUT_Y(0); 
Count=0;
PUT_ACTIVE(0); 
XCF=0;
YCF=0;
}

void DEFENCE::NEW(int8_t xEND_,int8_t yEND_){
XCF=63.00;
YCF=51.00;
float tXF,tYF;
XF=(xEND_-XCF);
YF=(yEND_-YCF);
tXF=abs(XF);
tYF=abs(YF);
Count=(tXF>=tYF)?(tXF/SPEED_SHOOT_TMISSILE):(tYF/SPEED_SHOOT_TMISSILE);
XF=((XF)/Count);
YF=((YF)/Count);  
PUT_ACTIVE(1); 
}
//CLASS SHIELD:LINE_TMISSILE END

//CLASS Clk
void CLK::INIT(uint8_t Start_,uint8_t End_,uint8_t Loop_){Start=Start_;End=End_;Pos=Start;Trig=0;Loop=Loop_;}

uint8_t CLK::PROGRESS(void){
  if ((Loop==0)&&(Trig==1)) {return Trig;}
  if (Pos<End) {
    Pos++;
    }else{
      Trig=!Trig;
      Pos=(Loop==1)?Start:End;
      }
      return Trig;
      }
      
void CLK::RESET(void){Pos=Start;Trig=0;}
//CLASS Clk END

//Class CROSS
void CROSS::INIT(void){
PUT_X(62);
PUT_Y(30); 
PUT_ACTIVE(1);
}

void CROSS::RIGHT(void){
PUT_X(GET_X()+3);
LIMITR();
}

void CROSS::LEFT(void){
PUT_X(GET_X()-3);
LIMITL();
}

void CROSS::DOWN(void){
PUT_Y(GET_Y()+2);
LIMITD();
}

void CROSS::UP(void){
PUT_Y(GET_Y()-2);
LIMITU();
}

void CROSS::LIMITR(void){
if (GET_X()>123) {PUT_X(123);}
}
void CROSS::LIMITL(void){
if (GET_X()<2) {PUT_X(2);} 
}
void CROSS::LIMITU(void){
if (GET_Y()<14) {PUT_Y(14);}
}
void CROSS::LIMITD(void){
if (GET_Y()>48) {PUT_Y(48);} 
}
//Class CROSS END

void TinySound(uint8_t freq_,uint8_t dur){
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

