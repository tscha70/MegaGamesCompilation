//     >>>>>  MEGA COMPILATION for ESP8266/ESP8285  GPL v3 <<<<
//                    >>>>>  MEGA Tiny Joypad  <<<<
//                      Programmer: Daniel C 2020
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


#include "PIC_JOY_TESTER.h"

uint8_t blitzSprite_JOYTESTER(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES);
uint8_t SplitSpriteDecalageY_JOYTESTER(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN);
int8_t RecupeLineY_JOYTESTER(int8_t Valeur);
uint8_t RecupeDecalageY_JOYTESTER(uint8_t Valeur);
void Tiny_Flip_JOYTESTER(void);
void Sound_JOYTESTER(uint8_t freq_,uint8_t dur);

//public var
uint8_t X_JOY,Y_JOY;
////////////////////////////////// main  ////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////  
void loop_JOYTESTER() {
ESP.wdtDisable();
ESP.wdtFeed();
X_JOY=29;
Y_JOY=30;
while(1){
if (TINYJOYPAD_RIGHT==0) {X_JOY=(X_JOY<47)?X_JOY+1:47;}else 
if (TINYJOYPAD_LEFT==0) {X_JOY=(X_JOY>11)?X_JOY-1:11;}else{
if (X_JOY<29) {X_JOY+=1;}
if (X_JOY>29) {X_JOY-=1;}
}
if (TINYJOYPAD_DOWN==0) {Y_JOY=(Y_JOY<48)?Y_JOY+1:48;}else 
if (TINYJOYPAD_UP==0) {Y_JOY=(Y_JOY>12)?Y_JOY-1:12;}else{
if (Y_JOY<30) {Y_JOY+=1;}
if (Y_JOY>30) {Y_JOY-=1;}
}
ESP.wdtFeed();
Tiny_Flip_JOYTESTER();
}
}
////////////////////////////////// main end /////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

uint8_t blitzSprite_JOYTESTER(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES){
uint8_t OUTBYTE;
uint8_t WSPRITE=(pgm_read_byte(&SPRITES[0]));
uint8_t HSPRITE=(pgm_read_byte(&SPRITES[1]));
uint16_t Wmax=((HSPRITE*WSPRITE)+1);
uint16_t PICBYTE=FRAME*(Wmax-1);
int8_t RECUPELINEY=RecupeLineY_JOYTESTER(yPos);
if ((xPASS>((xPos+(WSPRITE-1))))||(xPASS<xPos)||((RECUPELINEY>yPASS)||((RECUPELINEY+(HSPRITE))<yPASS))) {return 0x00;}
int8_t SPRITEyLINE=(yPASS-(RECUPELINEY));
uint8_t SPRITEyDECALAGE=(RecupeDecalageY_JOYTESTER(yPos));
uint16_t ScanA=(((xPASS-xPos)+(SPRITEyLINE*WSPRITE))+2);
uint16_t ScanB=(((xPASS-xPos)+((SPRITEyLINE-1)*WSPRITE))+2);
if (ScanA>Wmax) {OUTBYTE=0x00;}else{OUTBYTE=SplitSpriteDecalageY_JOYTESTER(SPRITEyDECALAGE,pgm_read_byte(&SPRITES[ScanA+(PICBYTE)]),1);}
if ((SPRITEyLINE>0)) {
uint8_t OUTBYTE2=SplitSpriteDecalageY_JOYTESTER(SPRITEyDECALAGE,pgm_read_byte(&SPRITES[ScanB+(PICBYTE)]),0);
if (ScanB>Wmax) {return OUTBYTE;}else{return OUTBYTE|OUTBYTE2;}
}else{return OUTBYTE;}
}

uint8_t SplitSpriteDecalageY_JOYTESTER(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN){
if (UPorDOWN) {return Input<<decalage;}
return Input>>(8-decalage);
}

int8_t RecupeLineY_JOYTESTER(int8_t Valeur){
return (Valeur>>3); 
}

uint8_t RecupeDecalageY_JOYTESTER(uint8_t Valeur){
return (Valeur-((Valeur>>3)<<3));
}

uint8_t JOYTEST_JOYTESTER(uint8_t xPASS,uint8_t yPASS){
return pgm_read_byte(&JOYTEST[xPASS+(yPASS*128)]);
}

uint8_t boutton_JOYTESTER(uint8_t xPASS,uint8_t yPASS){
if (BUTTON_DOWN) {
return (0xff-blitzSprite_JOYTESTER(97,20,xPASS,yPASS,0,boutton));
}else{
return 0xff;}
}

uint8_t Joy_JOYTESTER(uint8_t xPASS,uint8_t yPASS){
return (blitzSprite_JOYTESTER(X_JOY,Y_JOY,xPASS,yPASS,0,Joy));
}

void Tiny_Flip_JOYTESTER(void){
uint8_t y,x;
for (y = 0; y < 8; y++){
    for (x = 0; x < 128; x++){ 
    display.buffer[x+(y*128)] =Joy_JOYTESTER(x,y)|(JOYTEST_JOYTESTER(x,y)&boutton_JOYTESTER(x,y));
    }
}

display.display();
}


void Sound_JOYTESTER(uint8_t freq_,uint8_t dur){
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

