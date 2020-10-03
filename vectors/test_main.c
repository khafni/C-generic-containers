#include <stdio.h>
#include "vector.h"

typedef struct
{
    char *name;
    char *type;
    int number;
} weapon;

weapon weapon_create(char *name, char *type, int number)
{
    weapon w;

    w.name = malloc(sizeof(char) * (strlen(name)));
    w.type = malloc(sizeof(char) * (strlen(type)));
    strcpy(w.name, name);
    strcpy(w.type, type);
    w.number = number;
    return (w);
}

void weapon_destroy(void *w_ptr)
{
    weapon *w = (weapon *)w_ptr;
    free(w->name);
    free(w->type);
}

void weapon_print(void *weapon_ptr)
{
    weapon *w = (weapon *)weapon_ptr;
    printf("name : %s type : %s number : %d", w->name, w->type, w->number);
}

void fun_weapon_copy(void *src, void *dst)
{
    weapon *w_src = (weapon *)src;
    weapon *w_dst = (weapon *)dst;

    w_dst->name = w_src->name;
    w_dst->type = w_src->type;
    w_dst->number = w_src->number;
}

weapon *get_weapon_data (t_vector *v, int index)
{
    weapon *w = (weapon *)v->data + index;
    return (w);
}

int main(void)
{
    weapon swords = weapon_create("ice swords", "sword", 90);
    weapon axes = weapon_create("fire axes", "axe", 90);
    t_obj_funs *objs_funs = zero_obj_funs_create();
    objs_funs->free = weapon_destroy;
    objs_funs->print = weapon_print;
    objs_funs->copy = fun_weapon_copy;
    t_vector *v = empty_vector(sizeof(weapon), *objs_funs);
    vector_push_back (v, &swords);
    vector_push_back (v, &axes);
    //vector_set (v, 100 , &swords);
    //printf ("%d", v->len);
    printf ("%s", (((weapon *)(v->data + (v->len - 1) * v->cell_size))->name));
    //vector_print (v, "\n");

    vector_destroy(&v);
    obj_funs_destroy(&objs_funs);
    return (0);
}