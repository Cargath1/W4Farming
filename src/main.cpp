#include "wasm4.h"
#include <cmath>
#include <iostream>
using namespace std;

// -------------------------------- //

// can
#define canWidth 8
#define canHeight 8
#define canFlags BLIT_2BPP
const uint8_t can[16] = { 0xaa,0xaa,0xaa,0xaa,0xaa,0x56,0xa9,0xa9,0x65,0x55,0x95,0x01,0xa9,0x55,0xaa,0xaa };

// carrot
#define carrotWidth 8
#define carrotHeight 8
#define carrotFlags BLIT_2BPP
const uint8_t carrot[16] = { 0x77,0xff,0xd7,0x7f,0x51,0x9f,0xf6,0x1f,0xd8,0x27,0xf5,0x07,0xff,0x51,0xff,0xf5 };

// crop0
#define crop0Width 8
#define crop0Height 8
#define crop0Flags BLIT_1BPP
const uint8_t crop0[8] = { 0xff,0xff,0xff,0xff,0xff,0xc3,0xbd,0xff };

// crop1
#define crop1Width 8
#define crop1Height 8
#define crop1Flags BLIT_2BPP
const uint8_t crop1[16] = { 0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x56,0x95,0x50,0x05,0x45,0x51,0x55,0x55 };

// crop2
#define crop2Width 8
#define crop2Height 8
#define crop2Flags BLIT_2BPP
const uint8_t crop2[16] = { 0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x95,0x56,0x95,0x50,0x05,0x45,0x51,0x55,0x55 };

// crop3
#define crop3Width 8
#define crop3Height 8
#define crop3Flags BLIT_2BPP
const uint8_t crop3[16] = { 0x55,0x55,0x55,0x55,0x59,0x95,0x5a,0xe5,0x56,0x95,0x50,0x05,0x45,0x51,0x55,0x55 };

// crop4
#define crop4Width 8
#define crop4Height 8
#define crop4Flags BLIT_2BPP
const uint8_t crop4[16] = { 0x55,0x55,0x55,0x95,0x69,0xe5,0x5d,0x95,0x56,0x95,0x50,0x05,0x45,0x51,0x55,0x55 };

// dirt
#define dirtWidth 8
#define dirtHeight 8
#define dirtFlags BLIT_1BPP
const uint8_t dirt[8] = { 0xff,0x3f,0xf8,0xff,0x8f,0xff,0xff,0xf0 };

// grass
#define grassWidth 8
#define grassHeight 8
#define grassFlags BLIT_1BPP
const uint8_t grass[8] = { 0x08,0x81,0x00,0x10,0x02,0x00,0xa0,0x09 };

// hoe
#define hoeWidth 8
#define hoeHeight 8
#define hoeFlags BLIT_2BPP
const uint8_t hoe[16] = { 0xff,0xff,0xf1,0xff,0xf6,0x7f,0xd8,0x1f,0xd8,0x47,0xd5,0xd1,0xff,0xf7,0xff,0xff };

// player
#define playerWidth 8
#define playerHeight 8
#define playerFlags BLIT_2BPP
const uint8_t player[16] = { 0x75,0x5d,0x55,0x55,0xda,0xa7,0xd6,0x67,0xf5,0x5f,0xf4,0x1f,0xf5,0x5f,0xf7,0xdf };

// potato
#define potatoWidth 8
#define potatoHeight 8
#define potatoFlags BLIT_2BPP
const uint8_t potato[16] = { 0xff,0xff,0xfd,0x5f,0xf6,0x87,0xd9,0x91,0x66,0xa1,0x6a,0x41,0xd0,0x17,0xf5,0x7f };

// seeds
#define seedsWidth 8
#define seedsHeight 8
#define seedsFlags BLIT_2BPP
const uint8_t seeds[16] = { 0xf5,0x7f,0xd0,0x5f,0xd5,0x07,0x48,0x57,0x66,0x47,0x49,0x07,0x41,0x07,0xd5,0x5f };

// -------------------------------- //



int x = 0;
int y = 0;
int speed = 4;
int z = 0;
int frame = 0;

uint8_t gamepad = *GAMEPAD1;

void playermove () {
	uint8_t gamepad = *GAMEPAD1;
	if (gamepad & BUTTON_UP) {
        y = y - speed;
    }
    if (gamepad & BUTTON_DOWN) {
        y = y + speed;
    }
    if (gamepad & BUTTON_LEFT) {
        x = x - speed;
    }
    if (gamepad & BUTTON_RIGHT) {
        x = x + speed;
    }
}

void update () {

	uint8_t gamepad = *GAMEPAD1;
	frame++;
    *DRAW_COLORS = 0x0243;
    text("Hello from C!", 8, 8);
    
    if (frame % 2 == 0)
    	{
    	frame == 0;
    	playermove();
    	}
    	
   
   	
    blit(player, x, y, 8, 8, BLIT_2BPP);
}






