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
	free(w);
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

int num_compare(const void *_n1, const void *_n2)
{
	int* n1 = (int*)_n1;
	int* n2 = (int*)_n2;

	if ((*n1) > (*n2))
		return (1);
	return (-1);
}
int main()
{
	/*
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

	//weapons_print2(arrp);
	arrptr_destroy(arrp);
	*/
	t_arrptr intarr = standard_heap_create(num_compare, NULL);

	int *ia = malloc(sizeof(int)* 4);
	
	ia[0] = 4;
	ia[1] = 8;
	ia[2] = 1;
	ia[3] = -4;
	//hsort(ia, 4, sizeof(int), num_compare);
	for (int i = 0; i < 4; i++)
		arrptr_add(intarr, ia + i);

	heap_sort(intarr, num_compare);

	/* for (int i = 0; i < 4; i++)
		printf("%d\n", *((int*)arrptr_get(intarr, i))); */

	printf("%d\n", *((int*)arrptr_get(intarr, 0)));

	
	ia[0] = *((int*)arrptr_get(intarr, 0));
	ia[1] = *((int*)arrptr_get(intarr, 1));
	ia[2] = *((int*)arrptr_get(intarr, 2));
	ia[3] = *((int*)arrptr_get(intarr, 3));
	

	printf("%d\n", *((int*)arrptr_get(intarr, 0)));
	/* printf("%d\n", *((int*)arrptr_get(intarr, 1)));
	printf("%d\n", *((int*)arrptr_get(intarr, 2)));
	printf("%d\n", *((int*)arrptr_get(intarr, 3))); */

	/* printf("%d\n", *((int*)arrptr_get(intarr, 0)));
	printf("%d\n", *((int*)arrptr_get(intarr, 1)));
	printf("%d\n", *((int*)arrptr_get(intarr, 2)));
	printf("%d\n", *((int*)arrptr_get(intarr, 3)));
	printf("%d\n", *((int*)arrptr_get(intarr, 0)));
	printf("%d\n", *((int*)arrptr_get(intarr, 1)));
	printf("%d\n", *((int*)arrptr_get(intarr, 2)));
	printf("%d\n", *((int*)arrptr_get(intarr, 3))); */
	printf("\n\n");
	/* printf("%d\n", ia[0]);
	printf("%d\n", ia[1]);
	printf("%d\n", ia[2]);
	printf("%d\n", ia[3]); */
	//for (int i = 0; i < 4; i++)
		//a[i] = *((int*)arrptr_get(intarr, i));

	//printf ("%d", ia[2] = *((int*)arrptr_get(intarr, 2)));
	//printf("%d\n", *((int*)arrptr_get(intarr, 2)));
	//printf("%d", *((int*)arrptr_get(h, 0)));
	//heap_delete_head_value(h);
	//hsort(ia, 4, sizeof(int), num_compare);
	//printf("%s", ((t_weapon)garr_get(arr, 4))->name);
	//garr_destroy(arr);
	//weapon_destroy(w);
	return (0);
}