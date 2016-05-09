	//+SA-THIS ENTIRE CODE BLOCK IS NEW!
	//SA - 1/3 - b_playertag.h - Sayyid Ali header file based off Brad Davis's tutorial

	//This file forward declares our function prototypes for inclusion into Q2 source
	//+ BD - 1/15 This file forward declares our function prototypes for inclusion into Q2 source
	//+ BD - 1/15 Defines to make our code easier to read
	#define TAGGER 1		//+ SA
	#define NOTIT 2		//+ SA

//Functions we use
	void CheckTAG(edict_t *ent);
	void Cmd_TAG_f(edict_t *ent, char *cmd); 
	//+ - SA - END NEW CODE BLOCK
