//        >>>>>  T-I-N-Y  M-O-R-P-I-O-N for ATTINY85  GPL v3 <<<<<
//                    Programmer: Daniel C 2020
//             Contact EMAIL: electro_l.i.b@tinyjoypad.com
//                    https://WWW.TINYJOYPAD.COM
//          https://sites.google.com/view/arduino-collection

//  tiny-Morpion is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.

//  You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

//for TINY JOYPAD rev2 (attiny85)
//the code work at 16MHZ internal
//and use ssd1306xled Library for SSD1306 oled display 128x64
//Program chip with arduino uno as isp at 16 mhz internal!

//define
#define DEBOUNCE(ZELTADA)  My_delay_ms(30);if (ZELTADA) 

//prototype
uint8_t Mymap_TMORPION(uint8_t x, uint8_t in_min, uint8_t in_max, uint8_t out_min, uint8_t out_max);
uint8_t blitzSprite_TMORPION(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES);
uint8_t SPEED_BLITZ_TMORPION(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES);
uint8_t SplitSpriteDecalageY_TMORPION(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN);
int8_t RecupeLineY_TMORPION(int8_t Valeur);
uint8_t RecupeDecalageY_TMORPION(uint8_t Valeur);
uint8_t Trace_LINE_TMORPION(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t xPASS,uint8_t yPASS);
uint8_t DIRECTION_LINE_TMORPION(uint8_t DESACTIVE_,uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t xPASS,uint8_t yPASS);
uint8_t Return_Full_Byte_TMORPION(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t xPASS,uint8_t yPASS);
void Universal_Swap_TMORPION(uint8_t *A_,uint8_t *B_);
uint8_t RECONSTRUCT_BYTE_TMORPION(uint8_t Min_,uint8_t Max_);
void Sound_TMORPION(uint8_t freq_,uint8_t dur);
void TINYJOYPAD_INIT_TMORPION(void);

uint8_t blitzSprite_TMORPION(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES){
uint8_t OUTBYTE;
uint8_t WSPRITE=(pgm_read_byte(&SPRITES[0]));
uint8_t HSPRITE=(pgm_read_byte(&SPRITES[1]));
uint16_t Wmax=((HSPRITE*WSPRITE)+1);
uint16_t PICBYTE=FRAME*(Wmax-1);
int8_t RECUPELINEY=RecupeLineY_TMORPION(yPos);
if ((xPASS>((xPos+(WSPRITE-1))))||(xPASS<xPos)||((RECUPELINEY>yPASS)||((RECUPELINEY+(HSPRITE))<yPASS))) {return 0x00;}
int8_t SPRITEyLINE=(yPASS-(RECUPELINEY));
uint8_t SPRITEyDECALAGE=(RecupeDecalageY_TMORPION(yPos));
uint16_t ScanA=(((xPASS-xPos)+(SPRITEyLINE*WSPRITE))+2);
uint16_t ScanB=(((xPASS-xPos)+((SPRITEyLINE-1)*WSPRITE))+2);
if (ScanA>Wmax) {OUTBYTE=0x00;}else{OUTBYTE=SplitSpriteDecalageY_TMORPION(SPRITEyDECALAGE,pgm_read_byte(&SPRITES[ScanA+(PICBYTE)]),1);}
if ((SPRITEyLINE>0)) {
uint8_t OUTBYTE2=SplitSpriteDecalageY_TMORPION(SPRITEyDECALAGE,pgm_read_byte(&SPRITES[ScanB+(PICBYTE)]),0);
if (ScanB>Wmax) {return OUTBYTE;}else{return OUTBYTE|OUTBYTE2;}
}else{return OUTBYTE;}
}

uint8_t SPEED_BLITZ_TMORPION(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES){
uint8_t WSPRITE=(pgm_read_byte(&SPRITES[0]));
uint8_t HSPRITE=(pgm_read_byte(&SPRITES[1]));
if ((xPASS>((xPos+(WSPRITE-1))))||(xPASS<xPos)||((yPASS<yPos)||(yPASS>(yPos+(HSPRITE-1))))) {return 0x00;}
return pgm_read_byte(&SPRITES[2+(((xPASS-xPos)+((yPASS-yPos)*(WSPRITE)))+(FRAME*(HSPRITE*WSPRITE)))]);
}

uint8_t SplitSpriteDecalageY_TMORPION(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN){
if (UPorDOWN) {return Input<<decalage;}
return Input>>(8-decalage);
}

int8_t RecupeLineY_TMORPION(int8_t Valeur){
return (Valeur>>3); 
}

uint8_t RecupeDecalageY_TMORPION(uint8_t Valeur){
return (Valeur-((Valeur>>3)<<3));
}

uint8_t Mymap_TMORPION(uint8_t x, uint8_t in_min, uint8_t in_max, uint8_t out_min, uint8_t out_max){
 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

uint8_t Trace_LINE_TMORPION(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t xPASS,uint8_t yPASS){
uint8_t Y1_=RecupeLineY_TMORPION(y1);
uint8_t Y2_=RecupeLineY_TMORPION(y2);
if ((xPASS<x1)&&(xPASS<x2)) return 0;
if ((xPASS>x1)&&(xPASS>x2)) return 0;
if (Y1_<Y2_) {
if (yPASS<Y1_){return 0;}
if (yPASS>Y2_){return 0;}
}else{
if (yPASS>Y1_){return 0;}
if (yPASS<Y2_){return 0;} 
}
return DIRECTION_LINE_TMORPION(0,x1,y1,x2,y2,xPASS,yPASS);
}

uint8_t DIRECTION_LINE_TMORPION(uint8_t DESACTIVE_,uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t xPASS,uint8_t yPASS){
 uint8_t XL_=0;
 uint8_t YL_=0;
 uint8_t RESULTANT=0;
 uint8_t Yref_=0;
XL_=abs(x1-x2);
YL_=abs(y1-y2);
RESULTANT=Mymap_TMORPION(xPASS,x1,x2,y1,y2);
Yref_=RecupeLineY_TMORPION(RESULTANT);
if ((XL_<YL_)&&(DESACTIVE_==0)) {
return Return_Full_Byte_TMORPION(x1,y1,x2,y2,xPASS,yPASS);
 }else{
if (Yref_==yPASS) {return (1<<(RecupeDecalageY_TMORPION(RESULTANT)));}else{return 0;}
  }
}

uint8_t Return_Full_Byte_TMORPION(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t xPASS,uint8_t yPASS){
uint8_t Byte_add_=0;
uint8_t t=0,tout=0;
uint8_t A_=0,B_=0;
A_=(yPASS<<3);
B_=(A_+7);
if (y1>y2){
Universal_Swap_TMORPION(&y1,&y2);
Universal_Swap_TMORPION(&x1,&x2);}
A_=(A_<y1)?y1:A_;
B_=(B_>y2)?y2:B_;
for (t=A_;t<B_+1;t++){
if (yPASS==RecupeLineY_TMORPION(t)) {
tout=Mymap_TMORPION(t,y1,y2,x1,x2);
Byte_add_|=(tout==xPASS)?(0b00000001<<(RecupeDecalageY_TMORPION(t))):0x00;
}}
return Byte_add_;
}

void Universal_Swap_TMORPION(uint8_t *A_,uint8_t *B_){
uint8_t T_=*A_;
*A_=*B_;
*B_=T_;
}

uint8_t RECONSTRUCT_BYTE_TMORPION(uint8_t Min_,uint8_t Max_){
uint8_t A_=(0xff<<Min_);
uint8_t B_=0xff-(0xff<<Max_);
return (A_&B_);
}

void Sound_TMORPION(uint8_t freq_,uint8_t dur){
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

void TINYJOYPAD_INIT_TMORPION(void){
}
