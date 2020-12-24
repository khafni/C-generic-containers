#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generic_parrays/garrptr.h"
#include "generic_arrays/garray.h"

typedef struct _weapon s_weapon;
typedef struct _weapon *t_weapon;

struct _weapon
{
	char	*name;
	int		power_level;
};

t_weapon weapon(char *name, int power_level)
{
	t_weapon w;

	w = (t_weapon) malloc(sizeof(struct _weapon));
	w->name = malloc (strlen(name));
	strcpy(w->name, name);
	w->power_level = power_level;
	return (w);
}

void weapon_destroy(void *_w)
{
	t_weapon w = (t_weapon)_w;
	w = NULL;
	//free(w->name);
	//free(w);
}

void weapon_add(t_arrptr arr, t_weapon w)
{
	void *wp = (void*)w;
	arrptr_add(arr, wp);
}

void weapons_print (t_arrptr arr)
{
	t_weapon w;

	for (int i = 0; i < arr->len; i++)
	{
		w = (t_weapon)arr->data[i];
		printf("\n___________________\n||weapon name : %s|| \n ||weapon power level : %d||\n_________________\n", w->name, w->power_level);
	}
}

int main()
{
	t_arrptr arr;

	
	arr = empty_arrptr_create(weapon_destroy);
	//for (int i = 0; i < 20000; i++)
		weapon_add(arr,weapon("ice sword", 3));
	/*
	weapon_add(arr, weapon("magical wand", 20));
	weapon_add(arr, weapon("ak-47", 500));
	weapon_add(arr, weapon("red sword", 5));
	weapon_add(arr, weapon("mlassa1", 12));
	weapon_add(arr, weapon("mlassa2", 19));
	weapon_add(arr, weapon("mlassa3", 431));
	weapon_add(arr, weapon("dragon dildo", 2000));
	weapon_add(arr, weapon("fleshlight", 1999));
	weapon_add(arr, weapon("god", 0));
	weapon_add(arr, weapon("catgirl", 1000000));
	*/
	//weapons_print(arr);
	arrptr_destroy(arr);
	return (0);
}