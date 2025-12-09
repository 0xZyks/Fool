/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t32h_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:44:18 by tsignori          #+#    #+#             */
/*   Updated: 2025/12/06 16:44:35 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/heaps/fheaps.h"

void	*t32_alloc(void *heap, f_size size)
{
	void	*ptr;

	return (ptr);
}

void	t32_free(void *heap, void *ptr)
{

}

void	t32_free_heap(void *heap)
{

}

static const heap_vtbl g_t32_vtable = {
	.free_heap = t32_free_heap,
	.alloc = t32_alloc,
	.free = t32_free,
};

const heap_vtbl	*get_t32_vtable(void)
{
	return &g_t32_vtable;
}

