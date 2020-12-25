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

void		heap_sort(void *array_, size_t nitems, size_t c_size, t_compar cmp)
{
	t_heap	h;
	char	*array;
	size_t	index;

	index = 0;
	array = array_;
	h = standard_heap_create(cmp, NULL);
	while (index < nitems)
	{
		heap_add(h, array + index * c_size);
		index++;
	}
	index = 0;
	while(index < nitems)
	{
		memory_copy((array + index * c_size), heap_get_head_value(h), c_size);
		//heap_delete_head_value(h);
		index++;
	}
}
