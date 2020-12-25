#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generic_parrays/garrptr.h"
#include "generic_arrays/garray.h"
#include "heaps/heap.h"

typedef struct _weapon s_weapon;
typedef struct _weapon *t_weapon;

struct _weapon
{
	char	*name;
	int		power_level;
};

s_weapon weapon2(char *name, int power_level)
{
	s_weapon w;
	
	w.name = strdup(name);	
	w.power_level = power_level;
	return (w);
}

t_weapon weapon(char *name, int power_level)
{
	t_weapon w;
	
	w = (t_weapon) malloc(sizeof(s_weapon));
	w->name = strdup(name);	
	w->power_level = power_level;
	return (w);
}

void weapon_destroy(void *_w)
{
	t_weapon w = (t_weapon)_w;
	free(w->name);
}

void weapon_add(t_arrptr arr, t_weapon w)
{
	void *wp = (void*)w;
	arrptr_add(arr, wp);
}

void weapon_add2(t_array arr, t_weapon w)
{
	void *wp = (void*)w;
	garr_add(arr, wp);
}

void weapons_print (t_array arr)
{
	t_weapon w;

	for (int i = 0; i < arr->len; i++)
	{
		w = (t_weapon)garr_get(arr, i);
		printf("\n___________________\n||weapon name : %s|| \n ||weapon power level : %d||\n_________________\n", w->name, w->power_level);
	}
}

void weapons_print2 (t_arrptr arr)
{
	t_weapon w;

	for (int i = 0; i < arr->len; i++)
	{
		w = (t_weapon)arrptr_get(arr, i);
		printf("\n___________________\n||weapon name : %s|| \n ||weapon power level : %d||\n_________________\n", w->name, w->power_level);
	}
}
int		weapons_compare(const void *_w1, const void *_w2)
{
	t_weapon w1 = (t_weapon)_w1;
	t_weapon w2 = (t_weapon)_w2;

	if (w1->power_level > w2->power_level)
		return (1);
	return (-1);
}

int main()
{
	t_arrptr arrp;


	arrp = empty_arrptr_create(weapon_destroy);
	arrp->obj_cmp = weapons_compare;
	weapon_add(arrp, weapon("magical wand", 1));
	
	weapon_add(arrp, weapon("ak-47", 3));
	weapon_add(arrp, weapon("red sword", 8));
	weapon_add(arrp, weapon("mlassa1", 5));
	
	weapon_add(arrp, weapon("mlassa2", -9));
	weapon_add(arrp, weapon("mlassa3", 6));
	weapon_add(arrp, weapon("dragon dildo", 2000));
	weapon_add(arrp, weapon("fleshlight", 1999));
	weapon_add(arrp, weapon("god", 0));
	weapon_add(arrp, weapon("catgirl", 1000000));
	heap_sort(arrp, weapons_compare);
/*
	t_heap h = standard_heap_create(weapons_compare, weapon_destroy);
	for (int i = 0; i < arrp->len; i++)
		heap_add(h, arrptr_get(arrp, i));	
	for (int i = 0; i < arrp->len; i++)
	{
		arrptr_set(arrp, i, heap_get_head_value(h));
		heap_delete_head_value(h);
	}
	*/
	weapons_print2(arrp);
	//printf("%s", ((t_weapon)garr_get(arr, 4))->name);
	//garr_destroy(arr);
	//weapon_destroy(w);
	return (0);
}