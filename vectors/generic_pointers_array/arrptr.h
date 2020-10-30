#ifndef GARRPTR_H
#define GARRPTR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define ARRAY_DEFAULT_SIZE 64
typedef void (*t_destructor)(void *obj);
typedef struct s_arrptr *t_arrptr;

struct s_arrptr
{
    void **data;
    int len;
    int alloc;
    t_destructor obj_des;
};

t_arrptr empty_arrptr_create(t_destructor obj_des);
t_arrptr empty_arrptr_create_size(int size, t_destructor obj_des);
void arrptr_destroy(t_arrptr *a);

void *arrptr_get(t_arrptr a, int index);
void arrptr_set(t_arrptr a, int index, void *obj);
void arrptr_add(t_arrptr a, void *obj);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif