	//+ - SA - 1/7 THIS ENTIRE CODE BLOCK IS NEW!
	//SA - s_playertag.c - Sayyid Ali's class for tag based off Brad Davis(GreyBear)'s tutorial
	//This code file consists of functions that relate to classes or tag jobs
	//of players in deathmatch mode

	//Include this for variable declarations we need
	#include "g_local.h"
	#include "m_player.h"
	#include "s_playertag.h"	//+ - SA - 1/7 Make our functions visible here\

	// CheckTAG -SA- This checks to see if an MOS has been chosen. If not, a message is printed.
	// This function is called in the Client_Think function to keep displaying it every frame.
	void CheckTAG(edict_t *ent)
	{
		
		edict_t	*other;
		int		i, j;
		pmove_t	pm;

		if(ent->client->resp.tagit < 1)   //Do we already have an role?
		{       //Noper...Message time	
			gi.centerprintf(ent, "Choose a role through Console\n Type 'runner' or 'chaser' in the console to choose your role.\n" );
		}
		if(ent->client->resp.tagit == 1)
		{
			gi.centerprintf(ent, "You Are It");
			
		}
		if(ent->client->resp.tagit == 2)
		{
			
			gi.centerprintf(ent, "You Are Not It");
		}

	}
	//+ - SA - END NEW CODE BLOCK

	//+ - SA - 1/5 - THE ENTIRE CODE BLOCK IS NEW!
	// Cmd_TAG_f This function sets the ent->client->resp.tagit value
	void Cmd_TAG_f(edict_t *ent, char *cmd)
	{
		//If the player already has a role, tell him what it is and return
		if(ent->client->resp.tagit > 0)
		{
			//Let the player know he can't change MOS, and tell him what he is...
			if(ent->client->resp.tagit == 1)
			{
				gi.centerprintf(ent,"Sorry Soldier.\nYou better go catch someone to change class\n");
			}
			else if(ent->client->resp.tagit == 2)
			{
				gi.centerprintf(ent,"Sorry Soldier.\nYou shoud run for your life...\n");
			}
			//Play a sound for the player.
			gi.sound(ent, CHAN_VOICE, gi.soundindex("items/damage2.wav"), 1, ATTN_NORM, 0);
			//Bail out now. We don't want to execute what's below
			return;
		}
		//Otherwise, assign an role now...
		gi.cprintf(ent,PRINT_HIGH,"Got: %s\n",cmd);
		
		//We MUST use Quake's string functions. The string isn't a normal one!
		if(Q_stricmp (cmd, "chaser") == 0)
		{
			ent->client->resp.tagit = 1;
			gi.bprintf (PRINT_HIGH, "%s Is Now It! RUN!\n", ent->client->pers.netname);
			gi.centerprintf(ent,"You Are It! RUN!.\n\nGood Luck!\n");
		}
		else if(Q_stricmp (cmd, "runner") == 0)
		{
			ent->client->resp.tagit = 2;
			gi.centerprintf(ent,"You Are NOT It! RUN!.\n\nGood Luck!\n");
		}
		else
		{
		//For completeness. We should NEVER get here.
			ent->client->resp.tagit = 0;
			gi.centerprintf(ent,"Invalid role selection!\n");
		}												

		//Play a sound just to be cool...
		gi.sound(ent, CHAN_VOICE, gi.soundindex("player/male/jump1.wav"), 1, ATTN_NORM, 0);
	}
	//+ - BD - END NEW CODE BLOCK