/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_tools.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:34:00 by khafni            #+#    #+#             */
/*   Updated: 2020/12/19 17:07:53 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_TOOLS_H
# define MEMORY_TOOLS_H
# include <string.h>
# include <stdlib.h>

/*
** copy n bytes of memory from src memory address to
** dst memory address
*/

void	*memory_copy(void *dst, const void *src, size_t n);

/*
**	grow allocated memory from old_size bytes size to new_size
**	bytes size
*/
void	memory_grow(void *address, size_t old_size, size_t new_size);
#endif
