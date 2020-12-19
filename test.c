#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generic_arrays/garray.h"

typedef struct
{
	char	*name;
	int		power_level;
} _weapon;

_weapon weapon(char *name, int power_level)
{
	_weapon w;

	w.name = malloc (strlen(name));
	strcpy(w.name, name);
	w.power_level = power_level;
	return (w);
}

void weapon_destroy(void *_w)
{
	_weapon *w = (_weapon*)_w;
	free(w->name);
}

void weapon_add(t_array arr, _weapon w)
{
	void *wp = (void*)&w;
	garr_add(arr, wp);
}

int main()
{
	_weapon *w;
	t_array arr;

	arr = empty_garr_64(weapon_destroy, sizeof(_weapon));
	weapon_add(arr,weapon("ice sword", 3));
	weapon_add(arr, weapon("magical wand", 20));
	weapon_add(arr, weapon("ak-47", 500));
	w = garr_get(arr, 0);
	printf("%s\n", w->name);
	
	w = garr_get(arr, 1);
	printf("%s\n", w->name);
	w = garr_get(arr, 2);
	printf("%s\n", w->name);
	
	garr_destroy(arr);	
	return (0);
}