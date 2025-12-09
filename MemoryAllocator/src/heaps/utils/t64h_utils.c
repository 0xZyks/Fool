/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t64h_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:44:46 by tsignori          #+#    #+#             */
/*   Updated: 2025/12/06 16:45:14 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/heaps/fheaps.h"

void	*t64_alloc(void *heap, f_size size)
{
	void	*ptr;

	return (ptr);
}

void	t64_free(void *heap, void *ptr)
{

}

void	t64_free_heap(void *heap)
{

}

static const heap_vtbl g_t64_vtable = {
	.free_heap = t64_free_heap,
	.alloc = t64_alloc,
	.free = t64_free,
};

const heap_vtbl	*get_t64_vtable(void)
{
	return &g_t64_vtable;
}

