/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t16h_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:43:37 by tsignori          #+#    #+#             */
/*   Updated: 2025/12/06 16:43:53 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/heaps/fheaps.h"

void	*t16_alloc(void *heap, f_size size)
{
	void	*ptr;

	return (ptr);
}

void	t16_free(void *heap, void *ptr)
{

}

void	t16_free_heap(void *heap)
{

}

static const heap_vtbl g_t16_vtable = {
	.free_heap = t16_free_heap,
	.alloc = t16_alloc,
	.free = t16_free,
};

const heap_vtbl	*get_t16_vtable(void)
{
	return &g_t16_vtable;
}

