/*****************************************************************************
 
 Program for writing to Newhaven Display's NHD - 192x32 LCD
 This code is written for the Arduino Uno.
 Copyright (c) 2021 - Newhaven Display International, Inc.
 Newhaven Display invests time and resources providing this open source code,
 please support Newhaven Display by purchasing products from Newhaven Display!
 Author: Zachary Palrang - Applications Engineer
 
 *****************************************************************************/
 
#define CS      8  //Chip Select signal
#define SDIN    9  //Serial In/Out signal
#define SCK     10  //Serial Clock signal


unsigned char NHD_W [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xF7, 0x60, 0xF9, 0xC6,
0x71, 0x98, 0x38, 0x70, 0xC7, 0xE3, 0x98, 0x03, 0xF0, 0x61, 0xFC, 0x7E, 0x18, 0x07, 0x0C, 0x30,
0x00, 0x00, 0x7F, 0xFF, 0xF7, 0x61, 0xF8, 0xCF, 0x61, 0x98, 0x3C, 0x30, 0xCF, 0xE3, 0xD8, 0x03,
0xF8, 0x63, 0xFC, 0x7F, 0x18, 0x0F, 0x0E, 0x70, 0x00, 0x00, 0x7F, 0x00, 0x07, 0x63, 0x80, 0xCF,
0x61, 0x98, 0x2C, 0x31, 0x8C, 0x03, 0xD8, 0x03, 0x1C, 0x63, 0x00, 0x63, 0x18, 0x0D, 0x86, 0x60,
0x00, 0x00, 0x3E, 0x1F, 0xF7, 0x63, 0xF8, 0xED, 0x61, 0xF8, 0x66, 0x19, 0x8F, 0xE3, 0x58, 0x03,
0x0C, 0x63, 0xF8, 0x63, 0x18, 0x1D, 0x83, 0xC0, 0x00, 0x00, 0x1E, 0x3F, 0xF7, 0xE3, 0xF8, 0x69,
0xE1, 0xF8, 0x66, 0x19, 0x8F, 0xE3, 0x78, 0x03, 0x0C, 0x63, 0xF8, 0x7F, 0x18, 0x18, 0xC1, 0x80,
0x00, 0x1E, 0x00, 0xF0, 0x06, 0xE1, 0x80, 0x79, 0xC1, 0x98, 0xFF, 0x0F, 0x0C, 0x03, 0x38, 0x03,
0x0C, 0x60, 0x1C, 0x7E, 0x18, 0x1F, 0xE1, 0x80, 0x00, 0x3F, 0x01, 0xE0, 0x06, 0xE1, 0xF8, 0x79,
0xC1, 0x98, 0xC3, 0x0F, 0x0F, 0xE3, 0x38, 0x03, 0xFC, 0x63, 0xFC, 0x60, 0x18, 0x3F, 0xE1, 0x80,
0x00, 0x3F, 0xFF, 0x1F, 0xF6, 0x60, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
0xF0, 0x63, 0xF0, 0x60, 0x1F, 0xB0, 0x61, 0x80, 0x00, 0x3F, 0xFE, 0x3F, 0xF0, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x3F, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1E, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x0F, 0xC0, 0x01, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xC0, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x1F, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x0F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};



const unsigned char Picture [] = {
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

/****************************************************
*                 Function Commands                  *
*****************************************************/

void command(unsigned char c)
{
  unsigned char i, temp;
  
              digitalWrite(CS, HIGH);
              temp = 0xF8;
              //-=-=-=-=-=-=-=-=-=-=
              //  Start Byte      -=
              //-=-=-=-=-=-=-=-=-=-=
              for (i=0;i<8;i++)
              {
              digitalWrite(SCK, LOW);
              if ((temp&0x80)>>7==1)
                {
                  digitalWrite(SDIN, HIGH);
                }
                else
                {
                  digitalWrite(SDIN, LOW);
                }
                digitalWrite(SCK, HIGH);
                temp = temp << 1;
              }
              //-=-=-=-=-=-=-=-=-=-=
              //  1st Byte        -=
              //-=-=-=-=-=-=-=-=-=-=
              for (i=0;i<4;i++)
              {
                digitalWrite(SCK, LOW);
                if ((c&0x80)>>7==1)
                {
                  digitalWrite(SDIN, HIGH);
                }
                else
                {
                  digitalWrite(SDIN, LOW);
                }
                digitalWrite(SCK, HIGH);
                c = c<<1;
              }
        
              for (i=0;i<4;i++)
              {
                digitalWrite(SCK, LOW);
                digitalWrite(SDIN, LOW);
                digitalWrite(SCK, HIGH);
              }
              //-=-=-=-=-=-=-=-=-=-=
              //  2nd Byte        -=
              //-=-=-=-=-=-=-=-=-=-=
              for (i=0;i<4;i++)
              {
                digitalWrite(SCK, LOW);
                if ((c&0x80)>>7==1)
                {
                  digitalWrite(SDIN, HIGH);
                }
                else
                {
                  digitalWrite(SDIN, LOW);
                }
                digitalWrite(SCK, HIGH);
                c = c<<1;
              }
        
              for (i=0;i<4;i++)
              {
                digitalWrite(SCK, LOW);
                digitalWrite(SDIN, LOW);
                digitalWrite(SCK, HIGH);
              }
                           
  }



//--------------------------------------------------------------------------

void data(unsigned char d)
{
  unsigned char i, temp;
 digitalWrite(CS, HIGH);
              temp = 0xFA;
              //-=-=-=-=-=-=-=-=-=-=
              //  Start Byte      -=
              //-=-=-=-=-=-=-=-=-=-=
              for (i=0;i<8;i++)
              {
              digitalWrite(SCK, LOW);
              if ((temp&0x80)>>7==1)
                {
                  digitalWrite(SDIN, HIGH);
                }
                else
                {
                  digitalWrite(SDIN, LOW);
                }
                digitalWrite(SCK, HIGH);
                temp = temp << 1;
              }
              //-=-=-=-=-=-=-=-=-=-=
              //  1st Byte        -=
              //-=-=-=-=-=-=-=-=-=-=
              for (i = 0; i < 4; i++)
              {
                digitalWrite(SCK, LOW);
                if((d&0x80)>>7==1)
                {
                  digitalWrite(SDIN, HIGH);
                }
                else
                {
                  digitalWrite(SDIN, LOW);
                }
                digitalWrite(SCK, HIGH);
                d = d<<1;
              }
        
              for (i=0;i<4;i++)
              {
                digitalWrite(SCK, LOW);
                digitalWrite(SDIN, LOW);
                digitalWrite(SCK, HIGH);
              }
              //-=-=-=-=-=-=-=-=-=-=
              //  2nd Byte        -=
              //-=-=-=-=-=-=-=-=-=-=
              for(i=0;i<4;i++)
              {
                digitalWrite(SCK, LOW);
                if((d&0x80)>>7==1)
                {
                  digitalWrite(SDIN, HIGH);
                }
                else
                {
                  digitalWrite(SDIN, LOW);
                }
                digitalWrite(SCK, HIGH);
                d = d<<1;
              }
        
              for(i=0;i<4;i++)
              {
                digitalWrite(SCK, LOW);
                digitalWrite(SDIN, LOW);
                digitalWrite(SCK, HIGH);
              }
                        
  }


/****************************************************
*                 Display Commands                   *
*****************************************************/

void disp(unsigned char *LCD_String)
{
  unsigned int x, y, page;
  page = 0x80;
  for(page=0x80;page<0xA0;page++)
  {
    command(0x3E);
    command(page);
    command(0x80);
    for(x=0;x<24;x++)
    {
      data(*LCD_String);
      LCD_String++;
      delay(1);
    }
  } 
}

void Fill()
{
  unsigned int x, y, page;
  page = 0x80;
  for(page=0x80;page<0xA1;page++)
  {
    command(0x3E);
    command(page);
    command(0x80);
    for(x=0;x<25;x++)
    {
      data(0xFF);
      delay(1);
    }
  } 
}

void Text_String()
{command(0x20);  
command(0x83); //Set DDRAM Address
data(0x47);
data(0x72);
data(0x61);
data(0x70);
data(0x68);
data(0x69);
data(0x63);
data(0x20);
data(0x4C);
data(0x43);
data(0x44);
command(0x92);
data(0x20);
data(0x44);
data(0x65);
data(0x6D);
data(0x6F);
data(0x6E);
data(0x73);
data(0x74);
data(0x72);
data(0x61);
data(0x74);
data(0x69);
data(0x6F);
data(0x6E); 
delay(5000);
command(0x01);
}

void icons(){
  command(0x01);
  command(0x20);
  command(0x80);
  data(0x20);
  data(0x20);
  data(0x01);
  data(0x20);
  data(0x02);
  data(0x20);
  data(0x03);
  data(0x20);
  data(0x04);
  data(0x20);
  data(0x05);
  data(0x20);
  data(0x06);
  data(0x20);
  data(0x07);
  data(0x20);
  data(0x09);
  data(0x20);
  data(0x0B);
  data(0x20);
  data(0x0C);
  data(0x20);
  data(0x0D);
  data(0x20);
  command(0x90);
  data(0x20);
  data(0x20);
  data(0x0E);
  data(0x20);
  data(0x0F);
  data(0x20);
  data(0x11);
  data(0x20);
  data(0x12);
  data(0x20);
  data(0x13);
  data(0x20);
  data(0x14);
  data(0x20);
  data(0x15);
  data(0x20);
  data(0x16);
  data(0x20);
  data(0x17);
  data(0x20);
  data(0x18);
  data(0x20);
  data(0x19);
  delay(5000);
}

void blank(){
  command(0x01);
  command(0x20);
  command(0x80);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  command(0x90);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
  data(0x20);
}



void Clear()
{
  unsigned int x, y, page;
  page = 0x80;
  for(page=0x80;page<0xA1;page++)
  {
    command(0x3E);
    command(page);
    command(0x80);
    for(x=0;x<24;x++)
    {
      data(0x00);
     delayMicroseconds(50);
    }
  }
}

/****************************************************
*           Initialization For controller           *
*****************************************************/

void Initialization_Sequence()
{
  command(0x38);
  delay(2);
  command(0x38);
  delay(2);
  command(0x0C);
  delay(2);
  command(0x01);
  delay(2);
  command(0x06);
  delay(2);
  command(0x02);
  delay(10);
  command(0x01);
}

/*****************************************************
*           Setup Function, to run once              *
*****************************************************/

void setup() {
  // put your setup code here, to run once:
  pinMode(CS,8);
  pinMode(SDIN,9);
  pinMode(SCK,10);
  Initialization_Sequence();
  delay(10);
  Clear();
  delay(500);
  Text_String();
  delay(500);
}

/*****************************************************
*           Loop Function, to run repeatedly         *
*****************************************************/

void loop() {
  Fill();
  delay(500);
  Clear();
  delay(500);
  command(0x01);
  disp(NHD_W);
  delay(5000);
  Fill();
  delay(500);
  Clear();
  delay(500);
  command(0x01);
  disp(Picture);
  icons();
  blank();
 
         
}
