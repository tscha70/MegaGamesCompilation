//     >>>>>  MEGA COMPILATION for ESP8266/ESP8285  GPL v3 <<<<
//                    >>>>>  MEGA Tiny Joypad  <<<<
//                      Programmer: Daniel C 2019
//           Contact EMAIL: electro_l.i.b@tinyjoypad.com
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


#include "spritebank_TSPACE.h"

#define Frame_Rate_TSPACE 0
#define MAXLEVELSHIELDED 3

// var public
uint8_t Live_TSPACE=0;
uint8_t ShieldRemoved_TSPACE=0;
uint8_t MONSTERrest_TSPACE=0;
uint8_t LEVELS_TSPACE=0;
uint8_t SpeedShootMonster_TSPACE=0;
uint8_t ShipDead_TSPACE=0;
uint8_t ShipPos_TSPACE=56;
// fin var public

void SnD(int8_t Sp_,uint8_t SN);
void LoadMonstersLevels_TSPACE(int8_t Levels,SPACE_TSPACE *space);
void SpeedControle_TSPACE(SPACE_TSPACE *space);
void GRIDMonsterFloorY_TSPACE(SPACE_TSPACE *space);
uint8_t LivePrint_TSPACE(uint8_t x,uint8_t y);
void Tiny_Flip_TSPACE(uint8_t render0_picture1,SPACE_TSPACE *space);
uint8_t UFOWrite_TSPACE(uint8_t x,uint8_t y,SPACE_TSPACE *space);
void UFOUpdate_TSPACE(SPACE_TSPACE *space);
void ShipDestroyByMonster_TSPACE(SPACE_TSPACE *space);
void MonsterShootupdate_TSPACE(SPACE_TSPACE *space);
void MonsterShootGenerate_TSPACE(SPACE_TSPACE *space);
uint8_t MonsterShoot_TSPACE(uint8_t x,uint8_t y,SPACE_TSPACE *space);
uint8_t ShieldDestroy_TSPACE(uint8_t Origine,uint8_t VarX,uint8_t VarY,SPACE_TSPACE *space);
void ShieldDestroyWrite_TSPACE(uint8_t BOOLWRITE,uint8_t line,SPACE_TSPACE *space,uint8_t Origine);
uint8_t MyShield_TSPACE(uint8_t x,uint8_t y,SPACE_TSPACE *space);
uint8_t ShieldBlitz_TSPACE(uint8_t Part,uint8_t LineSH );
uint8_t BOOLREAD_TSPACE(uint8_t SHnum,uint8_t LineSH,SPACE_TSPACE *space );
void RemoveExplodOnMonsterGrid_TSPACE(SPACE_TSPACE *space);
uint8_t background_TSPACE(uint8_t x,uint8_t y,SPACE_TSPACE *space);
uint8_t Vesso_TSPACE(uint8_t x,uint8_t y,SPACE_TSPACE *space);
void UFO_Attack_Check_TSPACE(uint8_t x,SPACE_TSPACE *space);
uint8_t MyShoot_TSPACE(uint8_t x,uint8_t y,SPACE_TSPACE *space);
void Monster_Attack_Check_TSPACE(SPACE_TSPACE *space);
int8_t OuDansLaGrilleMonster_TSPACE(uint8_t x,uint8_t y,SPACE_TSPACE *space);
uint8_t SplitSpriteDecalageY_TSPACE(uint8_t Input,uint8_t UPorDOWN,SPACE_TSPACE *space);
uint8_t Murge_Split_UP_DOWN_TSPACE(uint8_t x,SPACE_TSPACE *space);
uint8_t WriteMonster14_TSPACE(uint8_t x);
uint8_t Monster_TSPACE(uint8_t x,uint8_t y,SPACE_TSPACE *space);
uint8_t MonsterRefreshMove_TSPACE(SPACE_TSPACE *space);
void Sound_TSPACE(uint8_t freq,uint8_t dur);
void VarResetNewLevel_TSPACE(SPACE_TSPACE *space);







void LoadMonstersLevels_TSPACE(int8_t Levels,SPACE_TSPACE *space){
uint8_t x,y;
for (y=0;y<4;y++){
for (x=0;x<6;x++){
space->MonsterGrid[y][x]=pgm_read_byte(&MonstersLevels_TSPACE[(Levels*24)+((y)*6)+(x)]); 
}}}

void loop_TINVADERS() {
ESP.wdtDisable();
  #define SHOOTS 2
  uint8_t Decompte=0;
  uint8_t VarPot;
  uint8_t MyShootReady=SHOOTS;
SPACE_TSPACE space;
NEWGAME:;
Live_TSPACE=3;
LEVELS_TSPACE=0;
while(1){
ESP.wdtFeed();
Tiny_Flip_TSPACE(1,&space);
if (BUTTON_DOWN) {Sound_TSPACE(100,125);Sound_TSPACE(50,125);goto BYPASS2;}
}
NEWLEVEL:
My_delay_ms(1000);
BYPASS2:
VarResetNewLevel_TSPACE(&space);
SpeedControle_TSPACE(&space);
VarPot=54;
ShipPos_TSPACE=56;
space.ScrBackV=(ShipPos_TSPACE/14)+52;
goto Bypass;
RestartLevel:
if (Live_TSPACE>0) {Live_TSPACE--;}else{goto NEWGAME;}
Bypass:
ShipDead_TSPACE=0;
Decompte=0;
Tiny_Flip_TSPACE(0,&space);
My_delay_ms(1000);
while(1){
ESP.wdtFeed();
if (MONSTERrest_TSPACE==0) { 
#define ADD_TIME_TSPACE 20
Sound_TSPACE(110,255);My_delay_ms(40+ADD_TIME_TSPACE);Sound_TSPACE(130,255);My_delay_ms(40+ADD_TIME_TSPACE);Sound_TSPACE(100,255);
My_delay_ms(40+ADD_TIME_TSPACE);Sound_TSPACE(1,155);My_delay_ms(20+ADD_TIME_TSPACE);Sound_TSPACE(60,255);Sound_TSPACE(60,255);
if (LEVELS_TSPACE<9) {LEVELS_TSPACE++;}
goto NEWLEVEL;}
if ((((space.MonsterGroupeYpos)+(space.MonsterFloorMax+1))==7)&&(Decompte==0)) {ShipDead_TSPACE=1;}
if (SpeedShootMonster_TSPACE<=((9-LEVELS_TSPACE))) {SpeedShootMonster_TSPACE++;}else{SpeedShootMonster_TSPACE=0;MonsterShootGenerate_TSPACE(&space);}
 space.ScrBackV= (ShipPos_TSPACE/14)+52;
while((currentMillis-MemMillis)<Frame_Rate_TSPACE){
currentMillis=millis();
}
MemMillis=currentMillis;
Tiny_Flip_TSPACE(0,&space);
space.oneFrame=!space.oneFrame;
RemoveExplodOnMonsterGrid_TSPACE(&space);
MonsterShootupdate_TSPACE(&space);
UFOUpdate_TSPACE(&space);
if (((space.MonsterGroupeXpos>=26)&&(space.MonsterGroupeXpos<=28))&&(space.MonsterGroupeYpos==2)&&(space.DecalageY8==4)) {space.UFOxPos=127;}
if (VarPot>(ShipPos_TSPACE+2)) {ShipPos_TSPACE=ShipPos_TSPACE+((VarPot-ShipPos_TSPACE)/3);}
if (VarPot<(ShipPos_TSPACE-2)) {ShipPos_TSPACE=ShipPos_TSPACE-((ShipPos_TSPACE-VarPot)/3);}
if (ShipDead_TSPACE!=1) {
if (space.frame<space.frameMax) {space.frame++;}else{GRIDMonsterFloorY_TSPACE(&space);space.anim=!space.anim;if (space.anim==0){SnD(space.UFOxPos,200);}else{SnD(space.UFOxPos,100);}MonsterRefreshMove_TSPACE(&space);space.frame=0;}
//VarPot=map(analogRead(A3),0,1023,0,114);
if (TINYJOYPAD_LEFT==0) {if (VarPot>5) {VarPot=VarPot-6;}}
if (TINYJOYPAD_RIGHT==0) {if (VarPot<108) {VarPot=VarPot+6;}}
if ((BUTTON_DOWN)&&(MyShootReady==SHOOTS)) {Sound_TSPACE(200,4);MyShootReady=0;space.MyShootBall=6;space.MyShootBallxpos=ShipPos_TSPACE+6;}
}else{
Sound_TSPACE(80,1);Sound_TSPACE(100,1); 
Decompte++;
if (Decompte>=30) {My_delay_ms(600);if (((space.MonsterGroupeYpos)+(space.MonsterFloorMax+1))==7) {goto NEWGAME;}else{goto RestartLevel;}}}
if (space.MyShootBall==-1) {if (MyShootReady<SHOOTS) {MyShootReady++;}
}}}
////////////////////////////////// main end /////////////////////////////////

void SnD(int8_t Sp_,uint8_t SN){
if (Sp_!=-120) {Sound_TSPACE(220,8);Sound_TSPACE(200,4);}else{Sound_TSPACE(SN,1);}
}

void SpeedControle_TSPACE(SPACE_TSPACE *space){
uint8_t xx=00,yy=0;
MONSTERrest_TSPACE=0;
for (yy=0;yy<=3;yy++){
for (xx=0;xx<=5;xx++){ 
if ((space->MonsterGrid[yy][xx]!=-1)&&((space->MonsterGrid[yy][xx]<=5)) ){MONSTERrest_TSPACE++;}
}}space->frameMax=(MONSTERrest_TSPACE/8 );}

/*Thanks to Sven Bruns for informing me of an error in this function!*/
void GRIDMonsterFloorY_TSPACE(SPACE_TSPACE *space){
uint8_t y,x; 
space->MonsterFloorMax=3;
for (y=0;y<4;y++){
for (x=0;x<6;x++){
if (space->MonsterGrid[3-y][x]!=-1) {goto FIN;}}
space->MonsterFloorMax=space->MonsterFloorMax-1;
}FIN:;}

uint8_t LivePrint_TSPACE(uint8_t x,uint8_t y){
#define XLIVEWIDE ((5*Live_TSPACE)-1)
if (((0>=(x-XLIVEWIDE)))&&(y==7)) {
  return pgm_read_byte(&LIVE_TSPACE[(x)]);
 }
return 0x00;}

void Tiny_Flip_TSPACE(uint8_t render0_picture1,SPACE_TSPACE *space){
uint8_t y,x; 
uint8_t MYSHIELD=0x00;
for (y = 0; y < 8; y++)
{
for (x = 0; x < 128; x++)
{
if (render0_picture1==0) {
if (ShieldRemoved_TSPACE==0) {MYSHIELD=MyShield_TSPACE(x,y,space);}else{MYSHIELD=0x00;}
display.buffer[x+(y*128)] =(background_TSPACE(x,y,space)|LivePrint_TSPACE(x,y)|Vesso_TSPACE(x,y,space)|UFOWrite_TSPACE(x,y,space)|Monster_TSPACE(x,y,space)|MyShoot_TSPACE(x,y,space)|MonsterShoot_TSPACE(x,y,space)|MYSHIELD);
}else{display.buffer[x+(y*128)] =(pgm_read_byte(&intro_TSPACE[x+(y*128)]));}
}
if (render0_picture1==0) {
if (ShieldRemoved_TSPACE==0) {ShieldDestroy_TSPACE(0,space->MyShootBallxpos,space->MyShootBall,space);}
}}
if (render0_picture1==0) {
if ((space->MonsterGroupeYpos<(2+(4-(space->MonsterFloorMax+1))))/*&&(LEVELS_TSPACE<=MAXLEVELSHIELDED)*/) {}else{
if (ShieldRemoved_TSPACE!=1) {
   space->Shield[0]=0x00;
   space->Shield[1]=0x00;
   space->Shield[2]=0x00;
   space->Shield[3]=0x00;
   space->Shield[4]=0x00;
   space->Shield[5]=0x00;
  ShieldRemoved_TSPACE=1;}}}
display.display();   
  }

uint8_t UFOWrite_TSPACE(uint8_t x,uint8_t y,SPACE_TSPACE *space){
if ((space->UFOxPos!=-120)&&(y==0)&&((space->UFOxPos<=(x))&&(space->UFOxPos>=(x-14)))) {return pgm_read_byte(&Monsters_TSPACE[(x-space->UFOxPos)+(6*14)+(space->oneFrame*14)]); }
return 0x00;
}

void UFOUpdate_TSPACE(SPACE_TSPACE *space){
if (space->UFOxPos!=-120) {space->UFOxPos=space->UFOxPos-2;SnD(space->UFOxPos,0);if (space->UFOxPos<=-20) {space->UFOxPos=-120;} }
}

void ShipDestroyByMonster_TSPACE(SPACE_TSPACE *space){ 
if ((space->MonsterShoot[1][0]>=14)&&(space->MonsterShoot[1][0]<=15)&&(space->MonsterShoot[0][0]>=ShipPos_TSPACE)&&(space->MonsterShoot[0][0]<=ShipPos_TSPACE+14)) {
ShipDead_TSPACE=1;
}}

void MonsterShootupdate_TSPACE(SPACE_TSPACE *space){
if (space->MonsterShoot[1][0]!=16) {
ShipDestroyByMonster_TSPACE(space);
if (ShieldDestroy_TSPACE(1,space->MonsterShoot[0][0],space->MonsterShoot[1][0]/2,space)) {
space->MonsterShoot[1][0]=16;
}else{
space->MonsterShoot[1][0]=space->MonsterShoot[1][0]+1;
}}}

void MonsterShootGenerate_TSPACE(SPACE_TSPACE *space){ 
uint8_t a=random(3); 
uint8_t b=random(6); 
if (b>=5) {b=5;}
if (space->MonsterShoot[1][0]==16) {  
if (space->MonsterGrid[a][b]!=-1) {
space->MonsterShoot[0][0]=(space->MonsterGroupeXpos+7)+(b*14);
space->MonsterShoot[1][0]=(((space->MonsterGroupeYpos)+a)*2)+1;
}  
}
}

uint8_t MonsterShoot_TSPACE(uint8_t x,uint8_t y,SPACE_TSPACE *space){
if ((((space->MonsterShoot[1][0])/2)==y)&&(space->MonsterShoot[0][0]==x) ) {if (((space->MonsterShoot[1][0 ])%2)==0) {return 0b00001111;}else{return 0b11110000;}}
return 0x00;
}

uint8_t ShieldDestroy_TSPACE(uint8_t Origine,uint8_t VarX,uint8_t VarY,SPACE_TSPACE *space){
#define OFFSETXSHIELD -1
if (VarY==6) {
if (((VarX>=(20+OFFSETXSHIELD))&&(VarX<=(27+OFFSETXSHIELD)))) {
if ((BOOLREAD_TSPACE(0,(VarX-(20+OFFSETXSHIELD)),space))) {ShieldDestroyWrite_TSPACE(0,(VarX-(20+OFFSETXSHIELD)),space,Origine);return 1;}
}
if (((VarX>=(28+OFFSETXSHIELD))&&(VarX<=(35+OFFSETXSHIELD)))) {
if ((BOOLREAD_TSPACE(1,(VarX-(28+OFFSETXSHIELD)),space))) {ShieldDestroyWrite_TSPACE(1,(VarX-(28+OFFSETXSHIELD)),space,Origine);return 1;}
}
if (((VarX>=(55+OFFSETXSHIELD))&&(VarX<=(62+OFFSETXSHIELD)))) {
if ((BOOLREAD_TSPACE(2,(VarX-(55+OFFSETXSHIELD)),space))) {ShieldDestroyWrite_TSPACE(2,(VarX-(55+OFFSETXSHIELD)),space,Origine);return 1;}
}
if (((VarX>=(63+OFFSETXSHIELD))&&(VarX<=(70+OFFSETXSHIELD)))) {
if ((BOOLREAD_TSPACE(3,(VarX-(63+OFFSETXSHIELD)),space))) {ShieldDestroyWrite_TSPACE(3,(VarX-(63+OFFSETXSHIELD)),space,Origine);return 1;}
}
if (((VarX>=(90+OFFSETXSHIELD))&&(VarX<=(97+OFFSETXSHIELD)))) {
if ((BOOLREAD_TSPACE(4,(VarX-(90+OFFSETXSHIELD)),space))) {ShieldDestroyWrite_TSPACE(4,(VarX-(90+OFFSETXSHIELD)),space,Origine);return 1;}
}
if (((VarX>=(98+OFFSETXSHIELD))&&(VarX<=(105+OFFSETXSHIELD)))) {
if ((BOOLREAD_TSPACE(5,(VarX-(98+OFFSETXSHIELD)),space))) {ShieldDestroyWrite_TSPACE(5,(VarX-(98+OFFSETXSHIELD)),space,Origine);return 1;}
}
}
return 0;
}

  
void ShieldDestroyWrite_TSPACE(uint8_t BOOLWRITE,uint8_t line,SPACE_TSPACE *space,uint8_t Origine){
switch (line){
  case 0:space->Shield[BOOLWRITE]=space->Shield[BOOLWRITE]-128;if (Origine==0) {space->MyShootBall=-1;}break;
  case 1:space->Shield[BOOLWRITE]=space->Shield[BOOLWRITE]-64;if (Origine==0) {space->MyShootBall=-1;}break;
  case 2:space->Shield[BOOLWRITE]=space->Shield[BOOLWRITE]-32;if (Origine==0) {space->MyShootBall=-1;}break;
  case 3:space->Shield[BOOLWRITE]=space->Shield[BOOLWRITE]-16;if (Origine==0) {space->MyShootBall=-1;}break;
  case 4:space->Shield[BOOLWRITE]=space->Shield[BOOLWRITE]-8;if (Origine==0) {space->MyShootBall=-1;}break;
  case 5:space->Shield[BOOLWRITE]=space->Shield[BOOLWRITE]-4;if (Origine==0) {space->MyShootBall=-1;}break;
  case 6:space->Shield[BOOLWRITE]=space->Shield[BOOLWRITE]-2;if (Origine==0) {space->MyShootBall=-1;}break;
  case 7:space->Shield[BOOLWRITE]=space->Shield[BOOLWRITE]-1;if (Origine==0) {space->MyShootBall=-1;}break;
default:break;
}}


uint8_t MyShield_TSPACE(uint8_t x,uint8_t y,SPACE_TSPACE *space){
#define OFFSETXSHIELD -1
if (((x>=(20+OFFSETXSHIELD))&&(x<=(27+OFFSETXSHIELD)))&&(y==6)) {
if ((BOOLREAD_TSPACE(0,(x-(20+OFFSETXSHIELD)),space))) {return ShieldBlitz_TSPACE(0,(x-(20+OFFSETXSHIELD)));}else{return 0x00;}
}
if (((x>=(28+OFFSETXSHIELD))&&(x<=(35+OFFSETXSHIELD)))&&(y==6)) {
if ((BOOLREAD_TSPACE(1,(x-(28+OFFSETXSHIELD)),space))) {return ShieldBlitz_TSPACE(1,(x-(28+OFFSETXSHIELD)));}else{return 0x00;}
}
if (((x>=(55+OFFSETXSHIELD))&&(x<=(62+OFFSETXSHIELD)))&&(y==6)) {
if ((BOOLREAD_TSPACE(2,(x-(55+OFFSETXSHIELD)),space))) {return ShieldBlitz_TSPACE(0,(x-(55+OFFSETXSHIELD)));}else{return 0x00;}
}
if (((x>=(63+OFFSETXSHIELD))&&(x<=(70+OFFSETXSHIELD)))&&(y==6)) {
if ((BOOLREAD_TSPACE(3,(x-(63+OFFSETXSHIELD)),space))) {return ShieldBlitz_TSPACE(1,(x-(63+OFFSETXSHIELD)));}else{return 0x00;}
}
if (((x>=(90+OFFSETXSHIELD))&&(x<=(97+OFFSETXSHIELD)))&&(y==6)) {
if ((BOOLREAD_TSPACE(4,(x-(90+OFFSETXSHIELD)),space))) {return ShieldBlitz_TSPACE(0,(x-(90+OFFSETXSHIELD)));}else{return 0x00;}
}
if (((x>=(98+OFFSETXSHIELD))&&(x<=(105+OFFSETXSHIELD)))&&(y==6)) {
if ((BOOLREAD_TSPACE(5,(x-(98+OFFSETXSHIELD)),space))) {return ShieldBlitz_TSPACE(1,(x-(98+OFFSETXSHIELD)));}else{return 0x00;}
}
return 0x00;
}

uint8_t ShieldBlitz_TSPACE(uint8_t Part,uint8_t LineSH ){
uint8_t Var0=0;
switch (LineSH){
  case 0:if (Part==0) {Var0=0b11110000;}else{Var0=0b00001111;}break;
  case 1:if (Part==0) {Var0=0b11111100;}else{Var0=0b00001111;}break;
  case 2:
  case 3:
  case 4:
  case 5:Var0=0b00001111;break;
  case 6:if (Part==1) {Var0=0b11111100;}else{Var0=0b00001111;}break;
  case 7:if (Part==1) {Var0=0b11110000;}else{Var0=0b00001111;}break;
  default:Var0=0b00000000;break;
}
return Var0;
}

uint8_t BOOLREAD_TSPACE(uint8_t SHnum,uint8_t LineSH,SPACE_TSPACE *space ){
uint8_t Var0=(0b10000000>>LineSH);
if ((space->Shield[SHnum]&Var0)!=0) {return 1;}else{return 0;}
}

void RemoveExplodOnMonsterGrid_TSPACE(SPACE_TSPACE *space){
uint8_t x=0,y=0;
for (y=0;y<=3;y++){ //était a 5
for (x=0;x<=5;x++){
if (space->MonsterGrid[y][x]>=11) {space->MonsterGrid[y][x]=-1;} 
if (space->MonsterGrid[y][x]>=8) {space->MonsterGrid[y][x]=space->MonsterGrid[y][x]+1;}
}}}
  
uint8_t background_TSPACE(uint8_t x,uint8_t y,SPACE_TSPACE *space){
uint8_t scr=(space->ScrBackV+x);
if ((scr)>127) {scr=(space->ScrBackV+x)-128;}
return 0xff-pgm_read_byte(&back_TSPACE[((y)*128)+((scr))]);
}
 
uint8_t Vesso_TSPACE(uint8_t x,uint8_t y,SPACE_TSPACE *space){
if (((x-ShipPos_TSPACE)>=0)&&((x-ShipPos_TSPACE)<13)&&(y==7)) {
if (ShipDead_TSPACE==0) {return pgm_read_byte(&vesso_TSPACE[(x-ShipPos_TSPACE)]);}else{return pgm_read_byte(&vesso_TSPACE[(x-ShipPos_TSPACE)+(12*space->oneFrame)]);}
}
return 0;}

void UFO_Attack_Check_TSPACE(uint8_t x,SPACE_TSPACE *space){
if (space->MyShootBall==0) {
if ((space->MyShootBallxpos>=space->UFOxPos)&&(space->MyShootBallxpos<=(space->UFOxPos+14))) {
for (x=1;x<100;x++){
Sound_TSPACE(x,1);
}
if (Live_TSPACE<3) Live_TSPACE++;
space->UFOxPos=-120;}
}
}

 uint8_t MyShoot_TSPACE(uint8_t x,uint8_t y,SPACE_TSPACE *space){
if ((space->MyShootBallxpos==x)&&(y==((space->MyShootBall)))) {
if (space->MyShootBall>-1) {space->MyShootBallFrame=!space->MyShootBallFrame;}else{return 0x00;}
if (space->MyShootBallFrame==1) {space->MyShootBall--;} 
Monster_Attack_Check_TSPACE(space);
UFO_Attack_Check_TSPACE(x,space);
return pgm_read_byte(&SHOOT_TSPACE[(space->MyShootBallFrame)]);
}
return 0x00;
}

void Monster_Attack_Check_TSPACE(SPACE_TSPACE *space){
int8_t Varx=0,Vary=0;
#define Xmouin (space->MonsterGroupeXpos) 
#define Ymouin ((space->MonsterGroupeYpos)*8)//-space->DecalageY8
#define XPlus (Xmouin+84)
#define YPlus (Ymouin+(4*8))
#define MYSHOOTX (space->MyShootBallxpos)
#define MYSHOOTY ((space->MyShootBall*8)+(((space->MyShootBallFrame)+1)*4))
if ((MYSHOOTX>=Xmouin)&&(MYSHOOTX<=XPlus)&&(MYSHOOTY>=(Ymouin))&&(MYSHOOTY<=YPlus)){
//enter in the monster zone
Vary= (round((MYSHOOTY-Ymouin)/8));
Varx= (round((MYSHOOTX-Xmouin)/14));
if (Varx<0) {Varx=0;}
if (Vary<0) {Vary=0;}
if (Varx>5) {goto End;}
if (Vary>3) {goto End;}
if ((space->MonsterGrid[Vary][Varx]>-1) && (space->MonsterGrid[Vary][Varx]<6)) {
Sound_TSPACE(50,10);
space->MonsterGrid[Vary][Varx]=8;
space->MyShootBall=-1;
SpeedControle_TSPACE(space);
}
//fin monster zone
}
End:;
}

int8_t OuDansLaGrilleMonster_TSPACE(uint8_t x,uint8_t y,SPACE_TSPACE *space){
if (x<space->MonsterGroupeXpos) {return -1;}
if (y<space->MonsterGroupeYpos) {return -1;}
space->PositionDansGrilleMonsterX=(x-space->MonsterGroupeXpos)/14; 
space->PositionDansGrilleMonsterY=(y-space->MonsterGroupeYpos);
if ((space->PositionDansGrilleMonsterX)>5)  {return -1;}
if ((space->PositionDansGrilleMonsterY)>4)  {return -1;}
return 0;
}

uint8_t SplitSpriteDecalageY_TSPACE(uint8_t Input,uint8_t UPorDOWN,SPACE_TSPACE *space){
if (UPorDOWN) {
return Input<<space->DecalageY8;
}else{
return Input>>(8-space->DecalageY8); 
}}

uint8_t Murge_Split_UP_DOWN_TSPACE(uint8_t x,SPACE_TSPACE *space){
int8_t SpriteType=-1;
int8_t ANIMs=-1;
uint8_t Murge1=0;
uint8_t Murge2=0;
if (space->DecalageY8==0) {
SpriteType=space->MonsterGrid[space->PositionDansGrilleMonsterY][space->PositionDansGrilleMonsterX];
if (SpriteType<8) {ANIMs=(space->anim*14);}else{ANIMs=0;}
if (SpriteType==-1) {return 0x00;}
return pgm_read_byte(&Monsters_TSPACE[(WriteMonster14_TSPACE(x-space->MonsterGroupeXpos)+SpriteType*14)+ANIMs]);
}else{ //debut
if (space->PositionDansGrilleMonsterY==0) {
SpriteType=space->MonsterGrid[space->PositionDansGrilleMonsterY][space->PositionDansGrilleMonsterX];
if (SpriteType<8) {ANIMs=(space->anim*14);}else{ANIMs=0;}
if (SpriteType!=-1) { Murge2=SplitSpriteDecalageY_TSPACE(pgm_read_byte(&Monsters_TSPACE[(WriteMonster14_TSPACE(x-space->MonsterGroupeXpos)+SpriteType*14)+ANIMs]),1,space);}else{
Murge2=0x00;
}
return Murge2;    
}else{
SpriteType=space->MonsterGrid[space->PositionDansGrilleMonsterY-1][space->PositionDansGrilleMonsterX];
if (SpriteType<8) {ANIMs=(space->anim*14);}else{ANIMs=0;}
if (SpriteType!=-1) {Murge1=SplitSpriteDecalageY_TSPACE(pgm_read_byte(&Monsters_TSPACE[(WriteMonster14_TSPACE(x-space->MonsterGroupeXpos)+SpriteType*14)+ANIMs]),0,space);
}else{Murge1=0x00;}
SpriteType=space->MonsterGrid[space->PositionDansGrilleMonsterY][space->PositionDansGrilleMonsterX];
if (SpriteType<8) {ANIMs=(space->anim*14);}else{ANIMs=0;}
if (SpriteType!=-1) { Murge2=SplitSpriteDecalageY_TSPACE(pgm_read_byte(&Monsters_TSPACE[(WriteMonster14_TSPACE(x-space->MonsterGroupeXpos)+SpriteType*14)+ANIMs]),1,space);
}else{Murge2=0x00;}
return Murge1|Murge2;    
}  
} //fin
}

uint8_t WriteMonster14_TSPACE(uint8_t x){
while(1){
if ((x-14)>=0) {x=x-14;}else{break;}
}return x;}

uint8_t Monster_TSPACE(uint8_t x,uint8_t y,SPACE_TSPACE *space){
if (OuDansLaGrilleMonster_TSPACE(x,y,space)!=-1) {
}else{return 0x00;} //quiter la fonction si pas dans la grille
return  Murge_Split_UP_DOWN_TSPACE(x,space);
return 0x00;
}//end Monster();

uint8_t MonsterRefreshMove_TSPACE(SPACE_TSPACE *space){
if (space->Direction==1) {
if ((space->MonsterGroupeXpos<space->MonsterOffsetDroite)) {space->MonsterGroupeXpos=space->MonsterGroupeXpos+2;return 0;}else{
if (space->DecalageY8<7) {space->DecalageY8=space->DecalageY8+4;if (space->DecalageY8>7) {space->DecalageY8=7;} }else{space->MonsterGroupeYpos++;space->DecalageY8=0;}
space->Direction=0;return 0;
}}else{
if ((space->MonsterGroupeXpos>space->MonsterOffsetGauche)) {space->MonsterGroupeXpos=space->MonsterGroupeXpos-2;return 0;}else{
if (space->DecalageY8<7) {space->DecalageY8=space->DecalageY8+4;if (space->DecalageY8>7) {space->DecalageY8=7;} }else{space->MonsterGroupeYpos++;space->DecalageY8=0;}
space->Direction=1;return 0;
}}}


void Sound_TSPACE(uint8_t freq,uint8_t dur){
ESP.wdtFeed();
for (uint8_t t=0;t<dur;t++){
if (freq!=0)digitalWrite(PIN_,SOUND_ON_OFF); 
for (uint8_t t=0;t<(255-freq);t++){
My_delay_us(1);}
digitalWrite(PIN_,LOW);
for (uint8_t t=0;t<(255-freq);t++){
My_delay_us(1); }}}

void VarResetNewLevel_TSPACE(SPACE_TSPACE *space){
//space->ScrBackV=0;
ShieldRemoved_TSPACE=0;
SpeedShootMonster_TSPACE=0;
MONSTERrest_TSPACE=24;
LoadMonstersLevels_TSPACE(LEVELS_TSPACE,space);
space->Shield[0]=255;  
space->Shield[1]=255;  
space->Shield[2]=255;  
space->Shield[3]=255;  
space->Shield[4]=255;  
space->Shield[5]=255;  
space->MonsterShoot[0][0]=16;
space->MonsterShoot[1][0]=16;
space->UFOxPos=-120;

space->MyShootBall=-1;
space->MyShootBallxpos=0;
space->MyShootBallFrame=0;
space->anim=0;
 space->frame=0;
space->PositionDansGrilleMonsterX=0;
space->PositionDansGrilleMonsterY=0;
space->MonsterFloorMax=3;
space->MonsterOffsetGauche=0;
space->MonsterOffsetDroite=44;
space->MonsterGroupeXpos=20;
if (LEVELS_TSPACE>3) {space->MonsterGroupeYpos=1;}else{space->MonsterGroupeYpos=0;}
space->DecalageY8=0;
space->frameMax=8;
space->Direction=1; //1 right 0 gauche  
space->oneFrame=0;}



