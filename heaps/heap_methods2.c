/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_methods2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 07:46:01 by khafni            #+#    #+#             */
/*   Updated: 2020/12/24 15:47:42 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

void	*heap_get_head_value(t_heap h)
{
	return (h->data[0]);
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
		lc = h->data[heap_get_left_child_index(h, i)];
		rc = h->data[heap_get_right_child_index(h, i)];
		if (((*(h->obj_cmp)) (lc, rc)) <= 0)
			return (heap_get_left_child_index(h, i));
		else
			return (heap_get_right_child_index(h, i));
	}
}

void	heap_add(t_heap h, void *n)
{
	int		index;
	int		parent_index;	

	arrptr_add(h, n);
	if (h->len > 1)
	{
		index = h->len - 1;
		while (heap_has_parent(h, index))
		{
			parent_index = heap_get_parent_index(h, index);
			if ((*(h->obj_cmp))(h->data[index], h->data[parent_index]) < 0)
			{
				 void* tmp = h->data[index];
	     		h->data[index] = h->data[parent_index];
	      		h->data[parent_index] = tmp;
				//vp_swap(h->data[index], h->data[parent_index]);
				index = parent_index;
			}
			else
				break ;
		}
	}
}

void	heap_delete_head_value(t_heap h)
{
	int		index;
	int		last;
	int		s_ch_index;

	if (h->len == 0)
		return ;
	else if (h->len == 1)
		h->len = 0;
	else
	{
		last = h->len - 1;
		h->data[0] = h->data[last];
		index = 0;
		h->len--;
		while (heap_count_children(h, index) > 0)
		{
			s_ch_index = heap_get_smallest_child_index(h, index);
			if ((*(h->obj_cmp))(h->data[index], h->data[s_ch_index]) > 0)
			{
				//vp_swap(h->data[index], h->data[s_ch_index]);
				void* tmp = h->data[index];
	     		h->data[index] = h->data[s_ch_index];
	      		h->data[s_ch_index] = tmp;
				index = s_ch_index;
			}
			else
				break ;
		}
	}
}
