/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:03:31 by khafni            #+#    #+#             */
/*   Updated: 2020/12/25 16:24:36 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

void		heap_sort(t_arrptr arr, t_compar cmp)
{
	t_heap	h;


	h = standard_heap_create(cmp, arr->obj_des);
	/*
	while (index < arr->len)
	{
		heap_add(h, arrptr_get(arr, index));
		index++;
	}
	index = 0;
	while(index < h->len)
	{
		arrptr_set(arr, index, heap_get_head_value(h));
		//memory_copy((array + index * c_size), heap_get_head_value(h), c_size);
		heap_delete_head_value(h);
		index++;
	}
	*/

	for (int i = 0; i < arr->len; i++)
		heap_add(h, arrptr_get(arr, i));	
	for (int i = 0; i < arr->len; i++)
	{
		arrptr_set(arr, i, heap_get_head_value(h));
		heap_delete_head_value(h);
	}
	//heap_destroy(h);
}
