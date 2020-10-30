#include "arrptr.h"

t_arrptr empty_arrptr_create_size(int size, t_destructor obj_des)
{
    t_arrptr a;

    a = malloc(sizeof(t_arrptr));
    a->len = 0;
    a->alloc = size;
    a->data = malloc(sizeof(void *) * a->alloc);
    a->obj_des = obj_des;
    return (a);
}

t_arrptr empty_arrptr_create(t_destructor obj_des)
{
    t_arrptr a;

    a = empty_arrptr_create_size (ARRAY_DEFAULT_SIZE, obj_des);
    return (a);
}

void arrptr_destroy (t_arrptr* aa)
{
    t_arrptr a;
    int i;

    i = 0;
    a = *aa;
    if (a->obj_des != NULL)
    {
        while (i < a->len)
        {
            (*(a->obj_des)) (a->data + i);
            i++;
        }
    }
}


void *arrptr_get(t_arrptr a, int index)
{
    return (a->data[index]);
}

/*
** private function that i use instead of realloc
*/
void arrptr_grow_size(t_arrptr a, int newalloc)
{
    void *tmp;

    if ((tmp = malloc(newalloc * sizeof(void*))) == NULL)
        return;
    ft_memcpy(tmp, a->data, a->alloc * sizeof(void*));
    free(a->data);
    a->data = tmp;
    a->alloc = newalloc;
}

void arrptr_set(t_arrptr a, int index, void *obj)
{
    if (index >= a->alloc)
        arrptr_grow_size (a, 1 + 2 * index);
    if (index >= a->len)
        a->len = index + 1;

    a->data[index] = obj; 
}

void arrptr_add(t_arrptr a, void *obj)
{
    arrptr_set (a, a->len, obj);
}


void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	const char		*s;
	char			*d;

	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	i = 0;
	s = (const char *)src;
	d = (char *)dst;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}