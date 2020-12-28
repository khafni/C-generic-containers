
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generic_arrays/array_heap/arr_heap.h"

typedef struct _weapon s_weapon;
typedef struct _weapon *t_weapon;

struct _weapon
{
	char	*name;
	int		power_level;
};

s_weapon weapon(char *name, int power_level)
{
	s_weapon w;
	
	w.name = strdup(name);	
	w.power_level = power_level;
	return (w);
}

void weapon_add(t_array arr, s_weapon w)
{
	void *wp = (void*)&w;
	garr_add(arr, wp);
}

int		weapons_compare(void *_w1, void *_w2)
{
	t_weapon w1 = (t_weapon)_w1;
	t_weapon w2 = (t_weapon)_w2;

	if (w1->power_level > w2->power_level)
		return (1);
	return (-1);
}

int num_compare(void *_n1, void *_n2)
{
	int* n1 = (int*)_n1;
	int* n2 = (int*)_n2;

	if ((*n1) > (*n2))
		return (1);
	return (-1);
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

int main()
{
	t_heap a = empty_garr_64(NULL, sizeof(s_weapon));
    weapon_add(a, weapon("god", 999999));
    weapon_add(a, weapon("cat girl", 1999999));
    weapon_add(a, weapon("sword of cosmos", 50000));
    heap_sort(a, weapons_compare);
    weapons_print(a);
    garr_destroy(a);
    return (0);
}