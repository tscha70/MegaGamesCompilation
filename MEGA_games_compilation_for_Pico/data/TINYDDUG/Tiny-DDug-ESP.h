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


#include "ClassTDDUG.h"

//define
#define MAX_ENEMY_TDDUG 4
#define GAME_FRAME_CONTROL_TDDUG while((currentMillis-MemMillis)<0){currentMillis=millis();}MemMillis=currentMillis

//  PUBLIC OBJ
Main_Sprite_TDDUG DUG_TDDUG;
WEAPON_TDDUG W_TDDUG[2];
Enemy_Sprite_TDDUG ENEMY_DDUG[MAX_ENEMY_TDDUG];

//prototype
void loop_TDDUG();
void RESET_ALL_GD_TDDUG(void);
void RESET_WEAPON_TDDUG(void);
void LOAD_ENEMY_POS_TDDUG(void);
void LOAD_LEVEL_TDDUG(uint8_t Lev_);
void NEWGAME_TDDUG(void);
void NEXTLEVEL_TDDUG(void);
void Trigger_adj_TDDUG(void);
void SND_TDDUG(uint8_t Val_);
void SND_DDUG(void);
void COMPILING_TDDUG(void);
void DLAY(void);
uint8_t GamePlay_TDDUG(void);
void HowManyEnemy_TDDUG(void);
uint8_t Universal_TDDUG(int8_t ax,int8_t ay,int8_t aw,int8_t ah,int8_t bx,int8_t by,int8_t bw,int8_t bh);
void Check_Collision_TDDUG(void);
void ADJUST_FRAME_MAIN_DDUG(void);
void TL_ENEMY_TDDUG(void);
uint8_t Check_Balistic_Colid_TDDUG(void);
int8_t TrackX_TDDUG(int8_t t_);
int8_t TrackY_TDDUG(int8_t t_);
void UPDATE_ENEMY_TDDOG(void);
void Colapse_Enemy_Anim_TDDUG(void);
uint8_t RECUPE_ENEMY_FRAME_TDDUG(uint8_t SPR_);
void Adjust_main_speed_TDDUG(uint8_t RT_);
void UPDATE_PANNEL_TDDUG(uint8_t t_);
void COMPIL_SCO_TDDUG(void);
uint8_t READ_GRID_TDDUG(int8_t X_,int8_t Y_);
uint8_t WRITE_GRID_TDDUG(int8_t X_,int8_t Y_);
int8_t RND_TDDUG(void);
void ANIM_UPDATE_MAIN_TDDUG(uint8_t Direct_);
uint8_t blitzSprite_TDDUG(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES);
uint8_t BACK_TDDUG(uint8_t xPASS,uint8_t yPASS);
void ADJUST_LIVE_COMP_TDDUG(void);
uint8_t RECUPE_LIVE_TDDUG(uint8_t xPASS,uint8_t yPASS);
uint8_t BACKGROUND_TDDUG(uint8_t xPASS,uint8_t yPASS);
uint8_t MAIN_TDDUG(uint8_t xPASS,uint8_t yPASS);
uint8_t RECUPE_ENEMY_TDDUG(uint8_t xPASS,uint8_t yPASS);
uint8_t RECUPE_WEAPON_TDDUG(uint8_t xPASS,uint8_t yPASS);
uint8_t Recupe_TDDUG(uint8_t xPASS,uint8_t yPASS);
uint8_t SplitSpriteDecalageY_TDDUG(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN);
int8_t RecupeLineY_TDDUG(int8_t Valeur);
uint8_t RecupeDecalageY_TDDUG(uint8_t Valeur);
void Tiny_Flip_TDDUG(uint8_t Select_,uint8_t Blink_);
uint8_t RECUPE_START_TDDUG(uint8_t xPASS,uint8_t yPASS,uint8_t Blink_);
uint8_t recupe_SCORES_TDDUG(uint8_t xPASS,uint8_t yPASS,int8_t Pos_);
uint8_t SPEED_BLITZ_TDDUG(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES);
void Sound_TDDUG(uint8_t freq_,uint8_t dur);







////////////////////////////////// main  ////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////  
void loop_TDDUG() {
RESTART:;
{uint8_t t_TDDUG=0;
ESP.wdtDisable();
ESP.wdtFeed();
while(1){
ESP.wdtDisable();
ESP.wdtFeed();
          UPDATE_PANNEL_TDDUG(t_TDDUG);
          My_delay_ms(36);
          t_TDDUG=(t_TDDUG<20)?t_TDDUG+1:0;
          if ((BUTTON_DOWN)) {
              while(1){
              ESP.wdtDisable();
              ESP.wdtFeed();
                     if ((BUTTON_UP)) {SND_TDDUG(2);goto StArT;}
              }
           }
}}
StArT:;
  NEWGAME_TDDUG();
  goto NexT;
NEXTLEVEL:;
  NEXTLEVEL_TDDUG();
NexT:;
  LOAD_LEVEL_TDDUG(GD_DDUG.LEVEL);
RELOAD_LEVEL:;
  COMPILING_TDDUG();
unsigned long currentMillis=0;
unsigned long MemMillis=0;
ESP.wdtDisable();
ESP.wdtFeed();
while(1){
ESP.wdtFeed();
uint8_t DIRECT_SP_TDDUG=0;
if (GD_DDUG.DEAD==0) {
switch(W_TDDUG[0].ACTIVE()){
    case (0):case (5):if (TINYJOYPAD_RIGHT==0) {RND_TDDUG();DUG_TDDUG.WALK_RIGHT();DIRECT_SP_TDDUG=DIRECT_SP_TDDUG+1;}
                      else if (TINYJOYPAD_LEFT==0) {RND_TDDUG();DUG_TDDUG.WALK_LEFT();DIRECT_SP_TDDUG=DIRECT_SP_TDDUG+4;}
                      if (TINYJOYPAD_UP==0) {RND_TDDUG();DUG_TDDUG.WALK_UP();DIRECT_SP_TDDUG=DIRECT_SP_TDDUG+8;}
                      else if (TINYJOYPAD_DOWN==0) {RND_TDDUG();DUG_TDDUG.WALK_DOWN();DIRECT_SP_TDDUG=DIRECT_SP_TDDUG+2;}
                      break;
    default:break;
}
Adjust_main_speed_TDDUG(DIRECT_SP_TDDUG);
UPDATE_ENEMY_TDDOG();
if ((BUTTON_DOWN)) {
  GD_DDUG.One_Time_TDDUG=1;
  if (W_TDDUG[0].ACTIVE()<5) {
  W_TDDUG[0].PUT_ACTIVE(W_TDDUG[0].ACTIVE()+1);
  W_TDDUG[0].ADJUST_WEAPON(DUG_TDDUG);
  if ((W_TDDUG[0].ACTIVE()>2)) {
  W_TDDUG[1].PUT_ACTIVE(1);
  W_TDDUG[1].ADJUST_WEAPON2(W_TDDUG[0],DUG_TDDUG);}
  Check_Balistic_Colid_TDDUG();
  }
}else{
if (GD_DDUG.One_Time_TDDUG==1) {
RESET_WEAPON_TDDUG();
GD_DDUG.One_Time_TDDUG=0;
{for (uint8_t t_TDDUG=0;t_TDDUG<MAX_ENEMY_TDDUG;t_TDDUG++){ENEMY_DDUG[t_TDDUG].PUT_FIRST(0);}}
}}}
TL_ENEMY_TDDUG();
switch(GD_DDUG.Skip_Frame){
      case (0):ADJUST_FRAME_MAIN_DDUG();Tiny_Flip_TDDUG(1,0);
                GAME_FRAME_CONTROL_TDDUG;
                if (GD_DDUG.FirsT_Time==1) {DLAY();GD_DDUG.FirsT_Time=0;}if (GD_DDUG.DEAD==6) {DLAY();
                if (GD_DDUG.LIVE>0){GD_DDUG.LIVE--;goto RELOAD_LEVEL;}else{goto RESTART;} }break;
      case (1):Trigger_adj_TDDUG();Check_Collision_TDDUG();break;
      default:break;
}
switch(GamePlay_TDDUG()) {
  case 0:break;
  case 1:Tiny_Flip_TDDUG(1,0);SND_TDDUG(0);DLAY();goto NEXTLEVEL;break;
  default:break;
}
GD_DDUG.Skip_Frame=!GD_DDUG.Skip_Frame;
RND_TDDUG();
}}
////////////////////////////////// main end /////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void RESET_ALL_GD_TDDUG(void){
GD_DDUG.TimeLaps=0;
GD_DDUG.One_Time_TDDUG=1;
GD_DDUG.FirsT_Time=1;
GD_DDUG.Counter=0;
GD_DDUG.GO_OUT=0;
GD_DDUG.MAIN_FRAME=0;
GD_DDUG.DEAD=0;
GD_DDUG.MAIN_ANIM_FRAME=0;
GD_DDUG.MAIN_ANIM=0;
GD_DDUG.DIRECTION_ANIM=0;
GD_DDUG.Skip_Frame=0;
}

void RESET_WEAPON_TDDUG(void){
W_TDDUG[0].INIT_WEAPON();
W_TDDUG[1].INIT_WEAPON();
}

void LOAD_ENEMY_POS_TDDUG(void){
#define LevEl_ (GD_DDUG.LEVEL)
#define w1_ pgm_read_byte(&ENEMY_TDDUG[0+(t_*3)])
#define w2_ pgm_read_byte(&ENEMY_TDDUG[1+(t_*3)])
#define w5_ pgm_read_byte(&ENEMY_TDDUG[2+(t_*3)])
for (uint8_t t_=0;t_<MAX_ENEMY_TDDUG;t_++){
ENEMY_DDUG[t_].PUT_ACTIVE(0);
if (pgm_read_byte(&ENEMY_ENABLE_TDDUG[t_+(LevEl_*4)])) ENEMY_DDUG[t_].INIT(w1_,w2_,w5_);
}}

void LOAD_LEVEL_TDDUG(uint8_t Lev_){
for (uint8_t yc=0;yc<12;yc++){
for (uint8_t xc=0;xc<3;xc++){
GRID_TDDUG[yc][xc]=pgm_read_byte(&LEVEL_TDDUG[(xc+(yc*3))+(Lev_*36)]);
}}}

void NEWGAME_TDDUG(void){
GD_DDUG.Scores=0;
GD_DDUG.LEVEL=0;
GD_DDUG.LIVE_COMP=34;
GD_DDUG.LIVE=4;
GD_DDUG.Trigger_Counter=200;
}

void NEXTLEVEL_TDDUG(void){
 GD_DDUG.Trigger_Counter=(GD_DDUG.Trigger_Counter>12)?GD_DDUG.Trigger_Counter-10:10;
GD_DDUG.LEVEL=(GD_DDUG.LEVEL<6)?GD_DDUG.LEVEL+1:2;
}

void Trigger_adj_TDDUG(void){
GD_DDUG.Counter++;
if (GD_DDUG.Counter>GD_DDUG.Trigger_Counter) {
GD_DDUG.Counter=0;
for (uint8_t t_=0;t_<MAX_ENEMY_TDDUG;t_++){
if (ENEMY_DDUG[t_].ACTIVE()) {
if (ENEMY_DDUG[t_].TRACKING()==1)  {ENEMY_DDUG[t_].PUT_TRACKING(0);break;}
}}}}

void SND_TDDUG(uint8_t Val_){
switch (Val_){
 case (0):for(uint8_t t_=1;t_<250;t_=t_+10){Sound_TDDUG(t_,4);Sound_TDDUG(0,15);Sound_TDDUG(255-t_,2);}break;
 case (1):for(uint8_t t_=1;t_<100;t_=t_+5){Sound_TDDUG(t_,4);}break;
 case (2):Sound_TDDUG(20,150);Sound_TDDUG(100,150);break;
default:break;  
   }
}

void SND_DDUG(void){
 Sound_TDDUG(200,1); 
}

void SCORES_ADD_TDDUG(void){
GD_DDUG.Scores++; 
COMPIL_SCO_TDDUG();
}

void COMPILING_TDDUG(void){
  COMPIL_SCO_TDDUG();
  RESET_ALL_GD_TDDUG();
  RESET_WEAPON_TDDUG();
  DUG_TDDUG.INIT();
  LOAD_ENEMY_POS_TDDUG();
  W_TDDUG[0].PUT_ACTIVE(5);
  Tiny_Flip_TDDUG(1,0); 
}

void DLAY(void){
My_delay_ms(1000); 
}

uint8_t GamePlay_TDDUG(void){
switch(GD_DDUG.GO_OUT){
case 0:HowManyEnemy_TDDUG();break;
case 1:if (((ENEMY_DDUG[GD_DDUG.NOSPRITE_GO_OUT].X()==20)&&(ENEMY_DDUG[GD_DDUG.NOSPRITE_GO_OUT].Y()==0))||(ENEMY_DDUG[GD_DDUG.NOSPRITE_GO_OUT].ACTIVE()==0)) {ENEMY_DDUG[GD_DDUG.NOSPRITE_GO_OUT].PUT_ACTIVE(0);Tiny_Flip_TDDUG(1,0);return 1;}break;
default:break;
}
return 0;
}

void HowManyEnemy_TDDUG(void){
uint8_t t_,VAL_=0,VAL2_=0;
for (t_=0;t_<MAX_ENEMY_TDDUG;t_++){
if (ENEMY_DDUG[t_].ACTIVE()==1) {VAL2_=t_;VAL_++;}
}
if (VAL_==1) {ENEMY_DDUG[VAL2_].PUT_TRACKING(0);GD_DDUG.GO_OUT=1;GD_DDUG.NOSPRITE_GO_OUT=VAL2_;}
}

uint8_t Universal_TDDUG(int8_t ax,int8_t ay,int8_t aw,int8_t ah,int8_t bx,int8_t by,int8_t bw,int8_t bh){
if (ax>(bx+(bw))) {return 0;}
if ((ax+(aw))<bx) {return 0;}
if (ay>(by+(bh))) {return 0;}
if ((ay+(ah))<by) {return 0;}
return 1;
}

void Check_Collision_TDDUG(void){
uint8_t t;
#define Dx_ (DUG_TDDUG.X()+1)
#define Dy_ (DUG_TDDUG.Y()+1)
#define Dw_ (5)
#define Dh_ (5)
#define Enx_ (ENEMY_DDUG[t].X())
#define Eny_ (ENEMY_DDUG[t].Y())
#define Enw_ (7)
#define Enh_ (7)
for (t=0;t<MAX_ENEMY_TDDUG;t++){
if ((ENEMY_DDUG[t].ACTIVE()==1)&&(ENEMY_DDUG[t].BIG_ZIP()==0)) {
if (Universal_TDDUG(Dx_,Dy_,Dw_,Dh_,Enx_,Eny_,Enh_,Enw_)) {for (uint8_t t4=200;t4>2;t4-=4){Sound_TDDUG(t4,1);}RESET_WEAPON_TDDUG();GD_DDUG.DEAD++;}
}}}

void ADJUST_FRAME_MAIN_DDUG(void){
switch(GD_DDUG.DEAD){
  case 0 : GD_DDUG.MAIN_FRAME=GD_DDUG.MAIN_ANIM_FRAME+(GD_DDUG.DIRECTION_ANIM*3);break;
  case 1 ... 5 :GD_DDUG.MAIN_FRAME=(GD_DDUG.DEAD+11);break;
  case 6 :GD_DDUG.MAIN_FRAME=(GD_DDUG.DEAD+10);break;
  default : break;
}}

void TL_ENEMY_TDDUG(void){
uint8_t t;
if (GD_DDUG.TimeLaps<2) {GD_DDUG.TimeLaps+=1;}else{
 GD_DDUG.TimeLaps=0;
for (t=0;t<MAX_ENEMY_TDDUG;t++){
ENEMY_DDUG[t].PUT_BIG_ZIP((ENEMY_DDUG[t].BIG_ZIP()>0)?ENEMY_DDUG[t].BIG_ZIP()-1:0);
}}}

uint8_t Check_Balistic_Colid_TDDUG(void){
uint8_t ONE_ADD=0;
uint8_t t1,t2,t3;
#define ex_ (ENEMY_DDUG[t3].X())
#define ey_ (ENEMY_DDUG[t3].Y())
#define ew_ (7)
#define eh_ (7)
#define bx_ (W_TDDUG[t2].X()+1)
#define by_ (W_TDDUG[t2].Y()+1)
#define bw_ (1)
#define bh_ (1)
uint8_t PAss_=0;
for (t1=0;t1<MAX_ENEMY_TDDUG;t1++){
if (ENEMY_DDUG[t1].FIRST()==1) {
PAss_=1;
}}
for (t3=0;t3<MAX_ENEMY_TDDUG;t3++){
for (t2=0;t2<2;t2++){
 if (W_TDDUG[t2].ACTIVE()&&(ENEMY_DDUG[t3].ACTIVE())) {
if (Universal_TDDUG(ex_,ey_,ew_,eh_,bx_,by_,bh_,bw_)) {
if (PAss_==0) {ENEMY_DDUG[t3].PUT_FIRST(1);}
if (ENEMY_DDUG[t3].FIRST()) {
  W_TDDUG[0].PUT_ACTIVE(4);
 if (ONE_ADD==0) {
  ENEMY_DDUG[t3].PUT_BIG_ZIP((ENEMY_DDUG[t3].BIG_ZIP()<30)?ENEMY_DDUG[t3].BIG_ZIP()+1:ENEMY_DDUG[t3].BIG_ZIP());
  ONE_ADD++;}
 }
}}}}return 0;}

int8_t TrackX_TDDUG(int8_t t_){
if (ENEMY_DDUG[t_].TRACKING()==1){
return ENEMY_DDUG[t_].DIRECTION_X();}else{
  if (RecupeDecalageY_TDDUG(ENEMY_DDUG[t_].X()-20)==0) {
if ((ENEMY_DDUG[t_].X())<((GD_DDUG.GO_OUT==0)?DUG_TDDUG.X():20)) {return 1;}
if ((ENEMY_DDUG[t_].X())>((GD_DDUG.GO_OUT==0)?DUG_TDDUG.X():20)) {return -1;}
return 0;}else{return ENEMY_DDUG[t_].DIRECTION_X();}
}}

int8_t TrackY_TDDUG(int8_t t_){
if (ENEMY_DDUG[t_].TRACKING()==1){
return ENEMY_DDUG[t_].DIRECTION_Y();}else{
    if (RecupeDecalageY_TDDUG(ENEMY_DDUG[t_].Y())==0) {
if ((ENEMY_DDUG[t_].Y())<((GD_DDUG.GO_OUT==0)?DUG_TDDUG.Y():0)) {return 1;}
if ((ENEMY_DDUG[t_].Y())>((GD_DDUG.GO_OUT==0)?DUG_TDDUG.Y():0)) {return -1;}
return 0;
    }else{return ENEMY_DDUG[t_].DIRECTION_Y();}
}}

void UPDATE_ENEMY_TDDOG(void){
 for (uint8_t t_=0;t_<MAX_ENEMY_TDDUG;t_++){
if ((ENEMY_DDUG[t_].ACTIVE()!=0)&&(ENEMY_DDUG[t_].BIG_ZIP()==0)) {
if (RecupeDecalageY_TDDUG(ENEMY_DDUG[t_].Y())==0) {
  switch (TrackX_TDDUG(t_)) {
    case(0):break;
    case(1):ENEMY_DDUG[t_].DROITE();break;
    case(-1):ENEMY_DDUG[t_].GAUCHE();break;   
        default:break; 
  }}
if (RecupeDecalageY_TDDUG(ENEMY_DDUG[t_].X()-20)==0) {
  switch (TrackY_TDDUG(t_)) {
    case(0):break;
    case(1):ENEMY_DDUG[t_].BAS();break;
    case(-1):ENEMY_DDUG[t_].HAUT();break;    
    default:break;
  }}}
}
  if (Anim_Enemy_TDDUG<3){Anim_Enemy_TDDUG++;}else{
 Anim_Enemy_Frame_TDDUG=(Anim_Enemy_Frame_TDDUG==0)?1:0;
  Anim_Enemy_TDDUG=0;
  }
Colapse_Enemy_Anim_TDDUG();
}

void Colapse_Enemy_Anim_TDDUG(void){
for (uint8_t t_=0;t_<MAX_ENEMY_TDDUG;t_++){
ENEMY_DDUG[t_].PUT_ANIM(RECUPE_ENEMY_FRAME_TDDUG(t_));    
}}

uint8_t RECUPE_ENEMY_BIG_TDDUG(uint8_t SPR_){
uint8_t ADD_;
 if ((ENEMY_DDUG[SPR_].TRACKING()==0)&&(ENEMY_DDUG[SPR_].BIG_ZIP()==0)){ADD_=2;}else{ADD_=0;}
switch (ENEMY_DDUG[SPR_].BIG_ZIP()){
case(0):return (Anim_Enemy_Frame_TDDUG+ADD_);break;
case 1 ... 9 :return 0;break;
case 10 ... 19 :return 1;break;
case 20 ... 29 :return 4;break;
case(30):ENEMY_DDUG[SPR_].PUT_BIG_ZIP(0);ENEMY_DDUG[SPR_].PUT_ACTIVE(0);Tiny_Flip_TDDUG(1,0);SND_TDDUG(1);W_TDDUG[0].PUT_ACTIVE(5);GD_DDUG.Scores+=5;COMPIL_SCO_TDDUG();Tiny_Flip_TDDUG(1,0);break;
default:return ENEMY_DDUG[SPR_].ANIM();break; 
}
return 0;}

uint8_t RECUPE_ENEMY_FRAME_TDDUG(uint8_t SPR_){
uint8_t ADD_TYPE=(ENEMY_DDUG[SPR_].TYPE()==0)?0:10;
uint8_t OUT_=RECUPE_ENEMY_BIG_TDDUG(SPR_)+ADD_TYPE;
OUT_+=(ENEMY_DDUG[SPR_].ANIM_DIRECT()==1)?0:5;
return OUT_;
}

void Adjust_main_speed_TDDUG(uint8_t RT_){
switch (RT_) {
  case(9):case(3):case(6):case(12):MAIN_SPEED_STEP_TDDUG=13;break;
  default:MAIN_SPEED_STEP_TDDUG=25;break;
}}

void UPDATE_PANNEL_TDDUG(uint8_t t_){
COMPIL_SCO_TDDUG();
Tiny_Flip_TDDUG(0,t_);
}

void COMPIL_SCO_TDDUG(void){
ADJUST_LIVE_COMP_TDDUG();
M10000_TDDUG=(GD_DDUG.Scores/10000);
M1000_TDDUG=(((GD_DDUG.Scores)-(M10000_TDDUG*10000))/1000);
M100_TDDUG=(((GD_DDUG.Scores)-(M1000_TDDUG*1000)-(M10000_TDDUG*10000))/100);
M10_TDDUG=(((GD_DDUG.Scores)-(M100_TDDUG*100)-(M1000_TDDUG*1000)-(M10000_TDDUG*10000))/10);
M1_TDDUG=((GD_DDUG.Scores)-(M10_TDDUG*10)-(M100_TDDUG*100)-(M1000_TDDUG*1000)-(M10000_TDDUG*10000));
}

uint8_t READ_GRID_TDDUG(int8_t X_,int8_t Y_){
if (X_>21) return 1;
if (X_<0) return 1;
if (Y_>11) return 1;
if (Y_<0) return 0;
if (((0b10000000>>RecupeDecalageY_TDDUG(X_))&GRID_TDDUG[Y_][X_>>3])!=0) {return 1;} else{return 0;}
}

uint8_t WRITE_GRID_TDDUG(int8_t X_,int8_t Y_){
if (X_>21) return 1;
if (X_<0) return 1;
if (Y_>11) return 1;
if (Y_<0) return 1;

GRID_TDDUG[Y_][X_>>3]=GRID_TDDUG[Y_][X_>>3]&(0xff-(0b10000000>>RecupeDecalageY_TDDUG(X_)));
return 0;
}


int8_t RND_TDDUG(void){
RD_TDDUG=(RD_TDDUG<15)?RD_TDDUG+1:0;
return pgm_read_byte(&RnD_TDDUG[RD_TDDUG]);
}


void ANIM_UPDATE_MAIN_TDDUG(uint8_t Direct_){
if (GD_DDUG.MAIN_ANIM<4) {GD_DDUG.MAIN_ANIM++;}else{GD_DDUG.MAIN_ANIM=0;GD_DDUG.MAIN_ANIM_FRAME=(GD_DDUG.MAIN_ANIM_FRAME<2)?GD_DDUG.MAIN_ANIM_FRAME+1:0;}
GD_DDUG.DIRECTION_ANIM=Direct_;
}


uint8_t blitzSprite_TDDUG(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES){
uint8_t OUTBYTE;
uint8_t WSPRITE=(pgm_read_byte(&SPRITES[0]));
uint8_t HSPRITE=(pgm_read_byte(&SPRITES[1]));
uint16_t Wmax=((HSPRITE*WSPRITE)+1);
uint16_t PICBYTE=FRAME*(Wmax-1);
int8_t RECUPELINEY=RecupeLineY_TDDUG(yPos);
if ((xPASS>((xPos+(WSPRITE-1))))||(xPASS<xPos)||((RECUPELINEY>yPASS)||((RECUPELINEY+(HSPRITE))<yPASS))) {return 0x00;}
int8_t SPRITEyLINE=(yPASS-(RECUPELINEY));
uint8_t SPRITEyDECALAGE=(RecupeDecalageY_TDDUG(yPos));
uint16_t ScanA=(((xPASS-xPos)+(SPRITEyLINE*WSPRITE))+2);
uint16_t ScanB=(((xPASS-xPos)+((SPRITEyLINE-1)*WSPRITE))+2);
if (ScanA>Wmax) {OUTBYTE=0x00;}else{OUTBYTE=SplitSpriteDecalageY_TDDUG(SPRITEyDECALAGE,pgm_read_byte(&SPRITES[ScanA+(PICBYTE)]),1);}
if ((SPRITEyLINE>0)) {
uint8_t OUTBYTE2=SplitSpriteDecalageY_TDDUG(SPRITEyDECALAGE,pgm_read_byte(&SPRITES[ScanB+(PICBYTE)]),0);
if (ScanB>Wmax) {return OUTBYTE;}else{return OUTBYTE|OUTBYTE2;}
}else{return OUTBYTE;}
}

uint8_t BACK_TDDUG(uint8_t xPASS,uint8_t yPASS){
if (xPASS<20) return BACKGROUND_TDDUG(xPASS,yPASS);
if (xPASS>107) return BACKGROUND_TDDUG(xPASS,yPASS);
if (yPASS<1) return BACKGROUND_TDDUG(xPASS,yPASS);
if (yPASS>6) return BACKGROUND_TDDUG(xPASS,yPASS);
uint8_t RY=(yPASS-1)*2;
uint8_t OUT_COMP=0;
if (READ_GRID_TDDUG(EXT_GRID_TDDUG,RY)==1)  {OUT_COMP=15;}
if (READ_GRID_TDDUG(EXT_GRID_TDDUG,RY+1)==1)  {OUT_COMP=OUT_COMP|240;}
return (OUT_COMP&BACKGROUND_TDDUG(xPASS,yPASS));
}

void ADJUST_LIVE_COMP_TDDUG(void){
switch (GD_DDUG.LIVE) {
  case 0:GD_DDUG.LIVE_COMP=19;break;
  case 1:GD_DDUG.LIVE_COMP=23;break;
  case 2:GD_DDUG.LIVE_COMP=27;break;
  case 3:GD_DDUG.LIVE_COMP=31;break;
  case 4:GD_DDUG.LIVE_COMP=34;break;
  default:break;
}}

uint8_t RECUPE_LIVE_TDDUG(uint8_t xPASS,uint8_t yPASS){
if (yPASS<7) return 0;
if (xPASS<20) return 0;
if (xPASS>GD_DDUG.LIVE_COMP) return 0;
return pgm_read_byte(&LIVE_TDDUG[(xPASS-20)]);
}

uint8_t BACKGROUND_TDDUG(uint8_t xPASS,uint8_t yPASS){
  if (xPASS<19) return 0;
  if (xPASS>108) return 0;
return pgm_read_byte(&TDDUG[(xPASS-19)+(yPASS*90)]); 
}

uint8_t MAIN_TDDUG(uint8_t xPASS,uint8_t yPASS){
return blitzSprite_TDDUG(DUG_TDDUG.X(),DUG_TDDUG.Y(),xPASS,yPASS,GD_DDUG.MAIN_FRAME,Dig_TDDUG);
}

uint8_t RECUPE_ENEMY_TDDUG(uint8_t xPASS,uint8_t yPASS){
uint8_t Byte_=0x00,t_;
for (t_=0;t_<MAX_ENEMY_TDDUG;t_++){
if (ENEMY_DDUG[t_].ACTIVE()!=0) {Byte_=Byte_|blitzSprite_TDDUG(ENEMY_DDUG[t_].X(),ENEMY_DDUG[t_].Y(),xPASS,yPASS,ENEMY_DDUG[t_].ANIM(),Sprite_ENEMY_TDDUG);}
}
return (Byte_);
}

uint8_t RECUPE_WEAPON_TDDUG(uint8_t xPASS,uint8_t yPASS){
uint8_t RESULT=0;
if ((W_TDDUG[0].ACTIVE()!=0)&&(W_TDDUG[0].ACTIVE()!=5)) {
  RESULT=blitzSprite_TDDUG(W_TDDUG[0].X(),W_TDDUG[0].Y(),xPASS,yPASS,W_TDDUG[0].ANIM_OR(),LAZER_TDDUG);
  if (W_TDDUG[1].ACTIVE()!=0) {RESULT|=blitzSprite_TDDUG(W_TDDUG[1].X(),W_TDDUG[1].Y(),xPASS,yPASS,W_TDDUG[0].ANIM_OR(),LAZER_TDDUG);}
 }else{
    RESULT=0;
}
return RESULT;
}

uint8_t Recupe_TDDUG(uint8_t xPASS,uint8_t yPASS){
return (
  BACK_TDDUG(xPASS,yPASS)|
  MAIN_TDDUG(xPASS,yPASS)|
  RECUPE_ENEMY_TDDUG(xPASS,yPASS)|
  RECUPE_WEAPON_TDDUG(xPASS,yPASS)|
  RECUPE_LIVE_TDDUG(xPASS,yPASS)
  );
}

uint8_t SplitSpriteDecalageY_TDDUG(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN){
if (UPorDOWN) {return Input<<decalage;}
return Input>>(8-decalage);
}

int8_t RecupeLineY_TDDUG(int8_t Valeur){
return (Valeur>>3); 
}

uint8_t RecupeDecalageY_TDDUG(uint8_t Valeur){
return (Valeur-((Valeur>>3)<<3));
}


void Tiny_Flip_TDDUG(uint8_t Select_,uint8_t Blink_){
uint8_t y,x;
uint8_t Byte1_=0x00;;
EXT_COUNT_TDDUG=0;
EXT_GRID_TDDUG=0;
for (y = 0; y < 8; y++){
EXT_COUNT_TDDUG=0;
EXT_GRID_TDDUG=0;
    for (x = 0; x < 128; x++){ 
    if (x<19) {display.buffer[x+(y*128)] =0x00;goto eend;}
switch(Select_){
 case 0:Byte1_=recupe_SCORES_TDDUG(x,y,-33)|SPEED_BLITZ_TDDUG(46,2,x,y,0,DDUG_INTRO_TDDUG)|RECUPE_START_TDDUG(x,y,Blink_);break;
 case 1:Byte1_=recupe_SCORES_TDDUG(x,y,0)|Recupe_TDDUG(x,y);break;
 default:break;
}
display.buffer[x+(y*128)] =Byte1_;
eend:;
if (x>19) {if (EXT_COUNT_TDDUG<3) {EXT_COUNT_TDDUG++;}else{EXT_COUNT_TDDUG=0;EXT_GRID_TDDUG++;}}
}
}
display.display();
}

uint8_t RECUPE_START_TDDUG(uint8_t xPASS,uint8_t yPASS,uint8_t Blink_){
if (Blink_>10) return 0;
return SPEED_BLITZ_TDDUG(51,6,xPASS,yPASS,0,START_TDDUG);
}

uint8_t recupe_SCORES_TDDUG(uint8_t xPASS,uint8_t yPASS,int8_t Pos_){
if (xPASS<(85+Pos_)) {return 0;}
if (xPASS>(108+Pos_)){return 0;}
if (yPASS<7) {return 0;}
return 
(SPEED_BLITZ_TDDUG(85+Pos_,7,xPASS,yPASS,M10000_TDDUG,police_TDDUG)|
 SPEED_BLITZ_TDDUG(89+Pos_,7,xPASS,yPASS,M1000_TDDUG,police_TDDUG)|
 SPEED_BLITZ_TDDUG(93+Pos_,7,xPASS,yPASS,M100_TDDUG,police_TDDUG)|
 SPEED_BLITZ_TDDUG(97+Pos_,7,xPASS,yPASS,M10_TDDUG,police_TDDUG)|
 SPEED_BLITZ_TDDUG(101+Pos_,7,xPASS,yPASS,M1_TDDUG,police_TDDUG)|
 SPEED_BLITZ_TDDUG(105+Pos_,7,xPASS,yPASS,0,police_TDDUG));
}

uint8_t SPEED_BLITZ_TDDUG(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES){
uint8_t WSPRITE=(pgm_read_byte(&SPRITES[0]));
uint8_t HSPRITE=(pgm_read_byte(&SPRITES[1]));
if ((xPASS>((xPos+(WSPRITE-1))))||(xPASS<xPos)||((yPASS<yPos)||(yPASS>(yPos+(HSPRITE-1))))) {return 0x00;}
return pgm_read_byte(&SPRITES[2+(((xPASS-xPos)+((yPASS-yPos)*(WSPRITE)))+(FRAME*(HSPRITE*WSPRITE)))]);
}

void Sound_TDDUG(uint8_t freq_,uint8_t dur){
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

