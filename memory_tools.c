/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:52:19 by khafni            #+#    #+#             */
/*   Updated: 2020/12/19 17:11:15 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_tools.h"

void	*memory_copy(void *dst, const void *src, size_t n)
{
	size_t			i;
	const char		*s;
	char			*d;

	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	i = 0;
	s = (const char *)src;
	d = (char *)dst;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

void	memory_grow(void *address, size_t old_size, size_t new_size)
{
	void *tmp;

	if ((tmp = malloc(new_size)) == NULL)
		return ;
	memory_copy(tmp, address, old_size);
	free(address);
	address = tmp;
}
