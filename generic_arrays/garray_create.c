/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garray_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 01:55:05 by khafni            #+#    #+#             */
/*   Updated: 2020/12/19 16:25:10 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garray.h"

t_array			empty_garr(int size, t_destruct obj_des, int cell_size)
{
	t_array a;

	a = malloc(sizeof(struct s_array));
	a->len = 0;
	a->alloc = size;
	a->data = malloc(cell_size * a->alloc);
	a->cell_size = cell_size;
	a->obj_des = obj_des;
	return (a);
}

t_array			empty_garr_64(t_destruct obj_des, int cell_size)
{
	t_array a;

	a = empty_garr(GARRAY_DEFAULT_ALLOC, obj_des, cell_size);
	return (a);
}

void			garr_destroy(t_array a)
{
	free(a->data);
	free(a);
}

void			*garr_get(t_array a, int index)
{
	return (a->data + index * a->cell_size);
}
