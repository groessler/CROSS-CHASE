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

#if defined(__CMOC__) && !defined(__WINCMOC__)
	#include <cmoc.h>
#else
	#include <stdlib.h>
	#include <string.h>
	#include <stdio.h>
#endif

#if !defined EXIT_SUCCESS
	#define EXIT_SUCCESS 0
#endif

#include "settings.h"
#include "character.h"
#include "item.h"
#include "strategy.h"
#include "text.h"
#include "level.h"
#include "enemy.h"

#if !defined(TINY_GAME)
	#include "missile.h"
	#include "invincible_enemy.h"
#endif
	
// Input input/output driver headers
#include "display_macros.h"
#include "input_macros.h"
#include "sleep_macros.h"

#if defined(FULL_GAME)
	#include "horizontal_missile.h"
	#include "rocket.h"
#endif
	
#include "sound_macros.h"
	

unsigned short ghostSlowDown;

unsigned short ghostLevel;
unsigned int points;
unsigned int highScore;
unsigned char lives;
unsigned char XSize;
unsigned char YSize;
unsigned short loop;
unsigned char level;


#if !defined(TINY_GAME)
	unsigned short invincibleSlowDown;
	unsigned char invincibleXCountDown;
	unsigned char invincibleYCountDown;
	unsigned char missileDirection;
#endif

// Level
// The level affects:
// 1. powerUpCoolDown (how long before a new powerUp is spawned)
// 2. ghostSlowDown (how much the power up slows the enemies down)
// 3. invincibleXCountDown (time needed to activate the invincible ghost)
// 4. invincibleYCountDown
// 5. invincibleSlowDown (how much the invincible ghost is slowed-down)
// 6. invincibleLoopTrigger (how long before the invincible ghost appears)

#if !defined(TINY_GAME)
	extern Image INVINCIBLE_GHOST_IMAGE;
	extern Image POWERUP_IMAGE;
	extern Image MISSILE_IMAGE;
	extern Image GUN_IMAGE;
	extern Image EXTRA_POINTS_IMAGE;	
	extern Image DEAD_GHOST_IMAGE;
#endif

#if defined(FULL_GAME)
	extern unsigned char playerBlink;	
#endif

#if defined(DEBUG) && defined(FULL_GAME)
	extern Image EXTRA_LIFE_IMAGE;
	extern Image INVINCIBILITY_IMAGE;
	extern Image BUBBLE_IMAGE;
	extern Image LEFT_ENEMY_MISSILE_IMAGE;
	extern Image RIGHT_ENEMY_MISSILE_IMAGE;	
#endif

Character player; 

#if !defined(TINY_GAME)
	Character invincibleGhost;
	Item powerUp;
	Item powerUp2;
	Item gun;
	Item extraPoints;	
	
	Character missile;
#endif

Character ghosts[GHOSTS_NUMBER];
Character bombs[BOMBS_NUMBER];

#if defined(FULL_GAME)
	unsigned short invincibleGhostCountTrigger = INVINCIBLE_GHOST_TRIGGER;

	unsigned char innerVerticalWallY; 
	unsigned char innerVerticalWallX; 
	unsigned char innerVerticalWallLength;

	Item freeze;
	Item invincibility;
	
	Item extraLife;
	Item super;
	Item confuse;
	Item zombie;
	Item chase;
	 
	unsigned char extraLife_present_on_level;
	unsigned char super_present_on_level;
	unsigned char confuse_present_on_level;
	unsigned char zombie_present_on_level;
	#define chase_present_on_level skullsKilled
	
	Character leftEnemyMissile;
	Character rightEnemyMissile;

	Character bubbles[BUBBLES_NUMBER];
	
	Character chasingBullet;

	Character * chasedEnemyPtr;

	unsigned char bubbles_x[BUBBLES_NUMBER];
	
	unsigned char dead_bubbles;
	
	unsigned char arrowRange;
	
	unsigned char skullsKilled;
	
	unsigned char missileBasesDestroyed;
	
	unsigned char horizontalWallsLength;
	
	unsigned char invincibilityActive;
	
	unsigned char confuseActive; 
	
	unsigned char zombieActive; 
		
	unsigned short invincibility_count_down;	
	
	unsigned short confuse_count_down;
	
	unsigned short zombie_count_down;
	
#endif

#if !defined(TINY_GAME)
	unsigned char strategyArray[GHOSTS_NUMBER];

	unsigned char playerDirection; // 0: right, 1: down, 2: left, 3: up
	
	unsigned char freezeActive; // freezeActive	

	unsigned short freeze_count_down;
		
#endif

unsigned int extraLifeThroughPointsCounter;

unsigned char ghostCount = GHOSTS_NUMBER;

#if !defined(TINY_GAME)
	unsigned char playerFire;
	unsigned char guns = GUNS_NUMBER;

	unsigned char invincibleGhostHits;
	unsigned char invincibleGhostAlive;
#endif


#if !defined(TINY_GAME)
	void resetItems()
	{
		gun._coolDown = GUN_INITIAL_COOLDOWN;
		powerUp._coolDown = POWER_UP_INITIAL_COOLDOWN;
		powerUp2._coolDown = POWER_UP2_INITIAL_COOLDOWN;
		extraPoints._coolDown = EXTRA_POINTS_COOL_DOWN;		
		
		#if defined(FULL_GAME)
			freeze._coolDown = FREEZE_INITIAL_COOLDOWN;				
			extraLife._coolDown = EXTRA_LIFE_COOL_DOWN;
			invincibility._coolDown = INVINCIBILITY_COOL_DOWN;
			
			super._coolDown = SUPER_COOL_DOWN;
			confuse._coolDown = CONFUSE_COOL_DOWN;
			zombie._coolDown = ZOMBIE_COOL_DOWN;		
			chase._coolDown = CHASE_COOL_DOWN;
		#endif
	}

	// Constructor for all items
	void constructItems()
	{
		powerUp._effect = &powerUpEffect;
		powerUp2._effect = &powerUp2Effect;
		gun._effect = &gunEffect;
		extraPoints._effect = &extraPointsEffect;
		#if defined(FULL_GAME)
			freeze._effect = &freezeEffect;
			extraLife._effect = &extraLifeEffect;
			invincibility._effect = &invincibilityEffect;
			super._effect = &superEffect;
			confuse._effect = &confuseEffect;
			zombie._effect = &zombieEffect;
			chase._effect = &chaseEffect;
		#endif	
	}	

#endif

#if !defined(NO_INITIAL_SCREEN)			
void initialScreen(void)
{	
	CLEAR_SCREEN();					
	printStartMessage();
	
	#if defined(FULL_GAME)
		WAIT_PRESS();
		CLEAR_SCREEN();
		printHints();	
	#endif
}
#endif


#if defined(FULL_GAME)
	
	void handle_special_triggers(void)
	{

		confuse_present_on_level = missileBasesDestroyed>=2;
		zombie_present_on_level = missileBasesDestroyed>=3;
		super_present_on_level = skullsKilled>=2;
		// chase_present_on_level is defined as skullsKilled;
		extraLife_present_on_level = super_present_on_level && confuse_present_on_level;
		
	}
	
#endif

int main(void)
{		
	INIT_INPUT();

	INIT_GRAPHICS();

	// Ask for the screen size 
	GET_SCREEN_SIZE(&XSize, &YSize);
	
	highScore = 0;
	
	while(1)
	{

		INIT_IMAGES();
		
		#if !defined(NO_SET_SCREEN_COLORS)
			// Set Screen Colors
			setScreenColors();				
		#endif
		
		#if !defined(NO_INITIAL_SCREEN)
			initialScreen();
			
			#if !defined(TINY_GAME)
				WAIT_PRESS();
				CLEAR_SCREEN();	
			#endif
		#else
			CLEAR_SCREEN();	
			
			printPressKeyToStart();				
		#endif

		#if defined(TINY_GAME) || defined(FULL_GAME)
			highScoreScreen();	
			WAIT_PRESS();	
		#endif
		#if !defined(TINY_GAME)

			CLEAR_SCREEN();
		#endif
		
		extraLifeThroughPointsCounter = 1;
		points = 0;
		level = INITIAL_LEVEL; 	
		lives = LIVES_NUMBER;
		ghostCount = GHOSTS_NUMBER;
		#if defined(FULL_GAME)
			skullsKilled = 0;
			missileBasesDestroyed = 0;
		#endif
		do // Level (Re-)Start
		{ 	
			loop = 0;
			ghostLevel = 0;
		
			#if defined(FULL_GAME)
			
				dead_bubbles = 0;
				
				invincibilityActive = 0;				
				confuseActive = 0;
				zombieActive = 0; 
				
				handle_special_triggers();
			
				// freeze_count_down = 0;									
			#endif			
			
			#if !defined(TINY_GAME)
				freezeActive = 0;
				
				invincibleGhostAlive = 1;
				invincibleGhostHits = 0;						
				guns = 0;

				resetItems();
								
				computeStrategy();

				computeInvincibleGhostParameters();				
			#endif

			ghostSlowDown = computeGhostSlowDown();
			
			CLEAR_SCREEN();
			#if !defined(NO_TEXT)
				// Clear the screen, put cursor in upper left corner

				printLevel();
				sleep(1);
				CLEAR_SCREEN();
			#endif
			
			#if defined(FULL_GAME)
						
				arrowRange = computeArrowRange();
			
				if(bossLevel())
				{
					printKillTheSkull();
					sleep(1);
				}
				CLEAR_SCREEN();
				
				updateInnerWallVerticalData();	
			#endif
			
			printPressKeyToStart();
			WAIT_PRESS();
			CLEAR_SCREEN();
			
			
			#if !defined(TINY_GAME)
				DRAW_BORDERS();
			#endif
			
			fillLevelWithCharacters(ghostCount);	
			
			#if !defined(TINY_GAME)
				constructItems();	
				
				displayStatsTitles();
			#endif
			displayStats();			
			printLevelStats();
			printLivesStats();				
			
			//
			#if !defined(TINY_GAME)
				printGunsStats();
				printGhostCountStats();
			#endif

			#if defined(FULL_GAME)
			while(player._status && ((ghostCount>0 && !bossLevel()) || (invincibleGhostAlive && bossLevel()))) // while alive && there are still ghosts
			#else
			while(player._status && (ghostCount>0) )
			#endif
			{
				#if defined(SLOW_DOWN)
				{
					unsigned short i;
					for(i=0;i<GAME_SLOW_DOWN;++i)
					{
					}
				}
				#endif
							
				#if defined(FULL_GAME)
					handle_invincibility_count_down();
					handle_rockets();
					handle_enemy_missiles();
				#endif
				
				++loop;
				
				if(points>(extraLifeThroughPointsCounter*EXTRA_LIFE_THROUGH_POINTS))
				{
					++extraLifeThroughPointsCounter;
					PING_SOUND();
					++lives;
					printLivesStats();
				}
				
				ghostSlowDown = computeGhostSlowDown();

				MOVE_PLAYER();
				
				_DRAW_PLAYER();	
	
				#if !defined(TINY_GAME)
					handle_missile();
				#endif
				
				#if !defined(TINY_GAME)						
					handle_freeze_count_down();
					
					if(!freezeActive)
					{
						#if defined(FULL_GAME)
							if(confuseActive && invincibleGhostAlive && invincibleGhost._status)
							{
								chaseCharacter(&invincibleGhost, ghostSlowDown);
							}
							else
							{
								chaseCharacter(&player, ghostSlowDown);
							}
						#else
							chaseCharacter(ghostSlowDown);
						#endif
						++ghostLevel;				
					}
				
					handle_invincible_ghost();

					// This detects collisions of ghosts that have just moved
					if(missile._status)
					{
						//checkMissileVsGhosts(&missile);
						checkMissile(&missile);
					}
				#else
					chaseCharacter(ghostSlowDown);
					++ghostLevel;						
				#endif
				
				// Check collisions bombs vs ghosts
				checkBombsVsGhosts();
				
				#if !defined(TINY_GAME)
					handle_extraPoints_item();
					handle_gun_item();
					handle_powerup_item();
					handle_powerup2_item();		
				#endif
				
				#if defined(FULL_GAME)
					handle_freeze_item();	
					handle_invincibility_item();

					if(chase_present_on_level)
					{
						handle_chase_item();
						handle_chasing_bullet();						
						if(super_present_on_level)
						{
							handle_super_item();
							if(extraLife_present_on_level)
							{
								handle_extraLife_item();
							}
						}
					}
										
					if(confuse_present_on_level)
					{
						handle_confuse_item();
						handle_confuse_count_down();
						if(zombie_present_on_level)
						{
							handle_zombie_item();
							handle_zombie_count_down();	
							if(zombieActive && ((loop&15)==1))
							{
								points+=ZOMBIE_BONUS;
								PING_SOUND();
							}
						}
					}
					
				#endif
				
				#if defined(FULL_GAME)
					if(wallReached(&player) || 
					   (!invincibilityActive && (playerReached(&player) || playerReachedBombs(&player) || innerWallReached(&player) || (horizontalWallsLevel() && horizontalWallsReached(&player))))
					  )
				#else
					if(wallReached(&player) || playerReached(&player) || playerReachedBombs(&player))
				#endif
					{
						playerDies();
					}

				
				#if defined(FULL_GAME)
					SKIP_MORE_DRAW
					{
						SET_TEXT_COLOR(WALL_COLOR);
						DRAW_VERTICAL_LINE(XSize/2, YSize/2-(innerVerticalWallLength/2), innerVerticalWallLength);			
						DRAW_BOMBS();	
				
						if(horizontalWallsLevel())
						{				
							horizontalWallsLength = HORIZONTAL_WALLS_INITIAL_LENGTH + (level>>4) + (loop/HORIZONTAL_WALLS_INCREASE_LOOP);		
							DRAW_HORIZONTAL_WALLS(horizontalWallsLength);	
						}						
					}
										
				#else
					#if !defined(TINY_GAME)
					SKIP_MORE_DRAW
						DRAW_BOMBS();
					#endif
				#endif
				
				// Display ghosts
				SKIP_DRAW
					displayGhosts();
				
			}; // end inner while [while (player._alive && ghostCount>0), i.e., exit on death or end of level]

			if(player._status) // if level finished
			{
				#if !defined(TINY_GAME)
					#if !defined(NO_TEXT)
						sleep(1);
						printVictoryMessage();
						sleep(2);

						CLEAR_SCREEN();
					#endif

					if(level<=10)
					{
						points+= LEVEL_BONUS*level;
						printLevelBonus(LEVEL_BONUS*level);
					}
					else
					{				
						points+= LEVEL_BONUS*10;
						printLevelBonus(LEVEL_BONUS*10);
					}
					sleep(1);
					CLEAR_SCREEN();						
				#else
					points+= LEVEL_BONUS*4;
				#endif			

				ghostCount = GHOSTS_NUMBER;
				
				#if defined(FULL_GAME)			
					if(bossLevel())
					{	
						CLEAR_SCREEN();
						sleep(1);
						PING_SOUND();
						#if !defined(NO_TEXT)
							printExtraLife();
						#endif
						sleep(2);
						++lives;
						skullsKilled = 1;
						missileBasesDestroyed/=2;
					}
					else
					{
						if(!invincibleGhostAlive)
						{
							++skullsKilled;
						}
						missileBasesDestroyed+=dead_bubbles;
					}
				#endif
				++level;

			}
			else // if dead
			{
				#if !defined(TINY_GAME)
					CLEAR_SCREEN();
				#endif
				--lives;
				if(lives>0)
				{
					player._status = 1;
				}
			}
		} while (player._status && (level<(FINAL_LEVEL+1))); // lives left and not completed game game 
			
	if(level==FINAL_LEVEL+1) // if completed game
	{
		gameCompleted();
		#if !defined(NO_SLEEP)
			sleep(2);
		#else
			WAIT_PRESS();
		#endif
	}

	// GAME OVER	
	printGameOver();

	sleep(2);
	
	#if !defined(TINY_GAME)
		CLEAR_SCREEN();
	
		finalScore();
	#endif
	
	#if defined(NO_SLEEP)
		WAIT_PRESS();
	#endif
	
	sleep(2);
	if(points>highScore)
	{
		highScore = points;
	}
	CLEAR_SCREEN();
	} // while(1) -> restart from the beginning

	return EXIT_SUCCESS;
}
