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
#include <strings.h>

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