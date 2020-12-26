/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:03:31 by khafni            #+#    #+#             */
/*   Updated: 2020/12/26 11:03:37 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

void		heap_sort(t_arrptr arr, t_compar cmp)
{
	t_heap	h;
	int i;


	h = standard_heap_create(cmp, arr->obj_des);
	i = 0;
	while (i < arr->len)
	{
		heap_add(h, arrptr_get(arr, i));	
		i++;
	}
	i = 0;
	while (i < arr->len)
	{
		arrptr_set(arr, i, heap_get_head_value(h));
		heap_delete_head_value(h);
		i++;
	}
	heap_destroy(h);
}

void        hsort(void *array, size_t nitems, size_t size, t_compar cmp)
{
	t_arrptr tmp;
	size_t index;
	char *ptr;

	index = 0;
	cmp += 1 - 1;
	tmp = empty_arrptr_create(NULL);
	while (index < nitems)
	{
		ptr = (char*)array + index * size;
		arrptr_add(tmp, ptr);
		index++;	
	}
	heap_sort(tmp, cmp);
	index = 0;
	while (index < nitems)
	{
		ptr = (char*)array + index * size;
		memory_copy(ptr, arrptr_get(tmp, index), size);
		index++;	
	}
}