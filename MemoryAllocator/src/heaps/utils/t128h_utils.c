/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t128h_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:43:56 by tsignori          #+#    #+#             */
/*   Updated: 2025/12/07 05:07:01 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/heaps/fheaps.h"

void	*t128_alloc(void *heap, f_size size)
{
	void	*ptr;

	return (ptr);
}

void	t128_free(void *heap, void *ptr)
{

}

void	t128_free_heap(void *heap)
{

}

static const heap_vtbl g_t128_vtable = {
	.free_heap = t128_free_heap,
	.alloc = t128_alloc,
	.free = t128_free,
};

const heap_vtbl	*get_t128_vtable(void)
{
	return &g_t128_vtable;
}

