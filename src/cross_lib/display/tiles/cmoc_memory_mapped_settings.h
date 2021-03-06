/* --------------------------------------------------------------------------------------- */ 
// 
// CROSS CHASE by Fabrizio Caruso
//
// Fabrizio_Caruso@hotmail.com
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from
// the use of this software.

// Permission is granted to anyone to use this software for non-commercial applications, 
// subject to the following restrictions:

// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software. If you use this software in
// a product, an acknowledgment in the product documentation would be
// appreciated but is not required.

// 2. Altered source versions must be plainly marked as such, and must not
// be misrepresented as being the original software.

// 3. This notice may not be removed or altered from any source distribution.
/* --------------------------------------------------------------------------------------- */ 
#ifndef _CMOC_GRAPHICS_SETTINGS
#define _CMOC_GRAPHICS_SETTINGS

#include "cross_lib.h"

	
// BLUE
#if !defined(_TILE_0)
#define _TILE_0 ('*'+NOT_INVERTED)
#endif

#if !defined(_TILE_1)
#define _TILE_1 ('*'+NOT_INVERTED)
#endif

#if !defined(_TILE_2)
#define _TILE_2 ('*'+NOT_INVERTED)
#endif

#if !defined(_TILE_3)
#define _TILE_3 ('*'+NOT_INVERTED)
#endif


#define _TILE_9 '!'

// YELLOW
#define _TILE_7 ('+'+NOT_INVERTED)

#define _TILE_0_B '*'
#define _DOLLAR_TILE '$'

// GREEN
#define _TILE_8  ('S'+INVERTED)
#define _TILE_17 ('F'+INVERTED)
#define _TILE_18 ('H'+INVERTED)

// RED
#define _TILE_5 ('X'+INVERTED)
#define _TILE_6 '#'

#define _TILE_10 'I'
#define _TILE_11 ('.'+NOT_INVERTED)

#define _TILE_4 'O'

#define _TILE_14 ('>'+NOT_INVERTED)
#define _TILE_15 ('<'+NOT_INVERTED)
#define _TILE_16 ('^'+NOT_INVERTED)

#define _TILE_18 ('H'+INVERTED)
#define _TILE_7_B ('C'+INVERTED)
#define _TILE_4_B ('Z'+INVERTED)	

#define _TILE_12 ('#'+NOT_INVERTED)
#define _TILE_13 ('-'+NOT_INVERTED)
#define _TILE_5_B 'X'


#endif // _CMOC_GRAPHICS_SETTINGS

