/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:16:01 by khafni            #+#    #+#             */
/*   Updated: 2020/12/24 07:46:36 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

t_heap	heap_create(int alloc, t_compar cmp_fun, t_destructor des)
{
	t_arrptr h;

	h = empty_arrptr_create_size(alloc, des);
	h->obj_cmp = cmp_fun;
	return (h);
}

t_heap	standard_heap_create(t_compar cmp, t_destructor des)
{
	return (heap_create(HEAP_DEFAULT_ALLOC, cmp, des));
}

void	heap_destroy(t_heap h)
{
	arrptr_destroy(h);
}
