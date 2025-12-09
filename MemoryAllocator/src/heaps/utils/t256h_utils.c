/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t256h_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:43:56 by tsignori          #+#    #+#             */
/*   Updated: 2025/12/07 05:07:20 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/heaps/fheaps.h"

void	*t256_alloc(void *heap, f_size size)
{
	void	*ptr;

	return (ptr);
}

void	t256_free(void *heap, void *ptr)
{

}

void	t256_free_heap(void *heap)
{

}

static const heap_vtbl g_t256_vtable = {
	.free_heap = t256_free_heap,
	.alloc = t256_alloc,
	.free = t256_free,
};

const heap_vtbl	*get_t256_vtable(void)
{
	return &g_t256_vtable;
}

