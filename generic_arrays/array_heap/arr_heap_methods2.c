/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_heap_methods2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 07:46:01 by khafni            #+#    #+#             */
/*   Updated: 2020/12/28 19:35:06 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr_heap.h"

void	*heap_get_head_value(t_heap h)
{
	return (garr_get(h, 0));
}

int		heap_count_children(t_heap h, int i)
{
	int fg;

	fg = 2 * i + 1;
	if (fg >= h->len)
		return (0);
	else if (fg + 1 >= h->len)
		return (1);
	else
		return (2);
}

int		heap_get_smallest_child_index(t_heap h, int i)
{
	void	*rc;
	void	*lc;

	if (i < 0 || (i >= h->len) || (heap_count_children(h, i) < 1))
		return (-1);
	if ((heap_count_children(h, i) == 1))
		return (heap_get_left_child_index(h, i));
	else
	{
		lc = garr_get(h, heap_get_left_child_index(h, i));
		rc = garr_get(h, heap_get_right_child_index(h, i));
		if (((*(h->obj_cmp)) (lc, rc)) <= 0)
			return (heap_get_left_child_index(h, i));
		else
			return (heap_get_right_child_index(h, i));
	}
}

/* 
void	head_compare_aux(t_heap)
{

} */
void	heap_add(t_heap h, void *n)
{
	int		index;
	int		parent_index;
	void	*v1;
	void	*v2;

	garr_add(h, n);
	if (h->len > 1)
	{
		index = h->len - 1;
		while (heap_has_parent(h, index))
		{
			parent_index = heap_get_parent_index(h, index);
			v1 = garr_get(h, index);
			v2 = garr_get(h, parent_index);
			if ((*(h->obj_cmp))(v1, v2) < 0)
			{
				memory_swap(v1, v2, h->cell_size);
				index = parent_index;
			}
			else
				break ;
		}
	}
}

/*
**	GENERAL ALGORITHM :
**	if heap got no element we return 0
**	else if got 1 element we decrease the heap length by 1
**	else :
**	set the first element as the last one in the tree
**	decrease the length to remove the head element
**	and keep going down the tree from the new head of the tree (to sort it)
**	and swipe parent, smallest child pairs whenever it is needed
*/

void	heap_delete_head_value(t_heap h)
{
	int		index;
	int		last;
	int		s_ch_index;

	if (h->len == 1)
		h->len = 0;
	else if (h->len > 0)
	{
		last = h->len - 1;
		garr_set(h, 0, garr_get(h, last));
		index = 0;
		h->len--;
		while (heap_count_children(h, index) > 0)
		{
			s_ch_index = heap_get_smallest_child_index(h, index);
			if ((*(h->obj_cmp))(garr_get(h, index), garr_get(h, s_ch_index)) > 0)
			{
				memory_swap(garr_get(h, index), garr_get(h, s_ch_index), h->cell_size);
				index = s_ch_index;
			}
			else
				break ;
		}
	}
}
