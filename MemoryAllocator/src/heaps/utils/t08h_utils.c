/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t08h_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:39:23 by tsignori          #+#    #+#             */
/*   Updated: 2025/12/06 16:43:30 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/heaps/fheaps.h"

void	*t08_alloc(void *heap, f_size size)
{
	void	*ptr;

	return (ptr);
}

void	t08_free(void *heap, void *ptr)
{

}

void	t08_free_heap(void *heap)
{

}

static const heap_vtbl g_t08_vtable = {
	.free_heap = t08_free_heap,
	.alloc = t08_alloc,
	.free = t08_free,
};

const heap_vtbl	*get_t08_vtable(void)
{
	return &g_t08_vtable;
}

