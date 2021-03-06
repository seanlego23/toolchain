/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

/* Standard headers - it's recommended to leave them included */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Shared libraries */
#include <lib/ce/graphx.h>
#include "gfx/logo_gfx.h"

/* Defines used below */

#define UBUNTU_SPRITE_WIDTH   32
#define UBUNTU_SPRITE_HEIGHT  32

/* Put function prototypes here */

/* Put all your code here */
void main(void) {
	/* Create a buffer the same size as the ubuntu sprite */
	gfx_UninitedSprite( sprite_buffer, UBUNTU_SPRITE_WIDTH, UBUNTU_SPRITE_HEIGHT );
	sprite_buffer->width = UBUNTU_SPRITE_WIDTH;
	sprite_buffer->height = UBUNTU_SPRITE_HEIGHT;
	
	gfx_Begin( gfx_8bpp );
	
	/* Setup the palette used by the sprites*/
	gfx_SetPalette(logo_gfx_pal, sizeof(logo_gfx_pal), 0);
	
	gfx_Sprite( ubuntu, 42, 42 );
	gfx_Sprite( gfx_FlipSpriteY(ubuntu, sprite_buffer), 74, 74);
	gfx_Sprite( gfx_RotateSpriteC(ubuntu, sprite_buffer), 106, 106);
	
	/* Draw these ones without any clipping. Clipping refers to wether or not when it hits the edge of the window if       */
	/* the sprite will be draw partially onscreen. These routines are usually faster, because edge detection doesn't occur */
	gfx_Sprite_NoClip( gfx_RotateSpriteCC(ubuntu, sprite_buffer), 138, 138);
	gfx_Sprite_NoClip( gfx_RotateSpriteHalf(ubuntu, sprite_buffer), 170, 170);
	
	/* Wait for a key to be pressed */
	while( !os_GetCSC() );
	
	/* Close the graphics and return to the OS */
	gfx_End();
	prgm_CleanUp();
}
