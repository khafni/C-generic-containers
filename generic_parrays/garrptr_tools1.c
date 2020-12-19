/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garrptr_tools1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 01:06:56 by khafni            #+#    #+#             */
/*   Updated: 2020/12/19 17:28:56 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garrptr.h"

void		arrptr_set(t_arrptr a, int index, void *obj)
{
	size_t newalc;

	newalc = 1 + 2 * index;
	if (index >= a->alloc)
		memory_grow(a->data, a->alloc * sizeof(void*), newalc * sizeof(void*));
	if (index >= a->len)
		a->len = index + 1;
	a->data[index] = obj;
}

void		arrptr_add(t_arrptr a, void *obj)
{
	arrptr_set(a, a->len, obj);
}
