/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:15:59 by khafni            #+#    #+#             */
/*   Updated: 2020/12/24 16:07:51 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAP_H
# define HEAP_H
# include "../generic_parrays/garrptr.h"

/*
** A Heap is a special Tree-based data structure in
** which the tree is a complete binary tree.
** here i implement the heap data structure based on
** my generic dynamic void pointers arrays module
** and i also implement a polymorphic heap sort function
** that works similary to the C library function qsort
** but using the heap sort algorithm instead of the quick sort
** one O(nlog(n))
*/

typedef t_arrptr	t_heap;

# define HEAP_DEFAULT_ALLOC 128

t_heap		heap_create(int alloc, t_compar cmp, t_destructor des);

t_heap		standard_heap_create(t_compar cmp, t_destructor des);

void		heap_destroy(t_heap h);

int			is_empty_heap(t_heap h);

int			heap_has_parent(t_heap h, int i);

int			heap_get_parent_index(t_heap h, int i);

int			heap_get_left_child_index(t_heap h, int i);

int			heap_count_children(t_heap h, int i);

void		*heap_get_head_value(t_heap h);

int			heap_get_smallest_child_index(t_heap h, int i);

/*
** add element to the end of the heap
*/

void		heap_add(t_heap h, void *n);

void		heap_delete_head_value(t_heap h);
#endif
