/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptrh_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:39:04 by tsignori          #+#    #+#             */
/*   Updated: 2025/12/10 15:34:04 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/heaps/fheaps.h"

void	*ptr_alloc(void *heap, f_size size)
{
	fheap			*tmp;
	f_size			size8;
	unsigned char	*ptr;

	tmp = (fheap *)heap;
	size8 = (size + 7) & ~((f_size)7);

    if (tmp->offset + size8 > tmp->capacity)
        return NULL;

    ptr = (unsigned char *)tmp->base + tmp->offset;
    tmp->offset += size8;

	// Update Bitset in live;
    return (ptr);
}

void	ptr_free(void *heap, void *ptr)
{
	(void)heap;
	(void)ptr;
}

void	ptr_free_heap(void *heap)
{
	fheap *tmp;
	fl_central *central;
	tmp = (fheap *)heap;
	central = get_central();

	if (tmp->base)
		central->os.release(tmp->base, tmp->capacity);
	if (tmp->bitset)
		central->os.release(tmp->bitset, tmp->bitset_size);
	tmp->base   = NULL;
	tmp->bitset = NULL;
	tmp->is_init = 0;
	tmp->offset  = 0;
}

void	ptr_init(void *heap)
{
	fheap		*tmp;
	f_size		nb_chunks;
	f_size		bitset_size;
	fl_central	*central;

	tmp = (fheap *)heap;
	if (tmp->is_init)
	{
		tmp = (void *)0;
		return;
	}
	central = get_central();
	tmp->id = PTR_HEAP;
	tmp->capacity = 1024ULL * 1024ULL * 4;
	tmp->bitset_chunks = 8;
	tmp->offset = 0;
	tmp->bitset_size = 1;
	nb_chunks = tmp->capacity / tmp->bitset_chunks;
	bitset_size = (nb_chunks + 7) / 8;
	tmp->bitset_size = bitset_size;
	tmp->base = central->os.reserve(tmp->capacity);
	tmp->bitset = central->os.reserve(bitset_size);

	tmp->is_init = 1;
}

static const heap_vtbl g_ptr_vtable = {
	.free_heap = ptr_free_heap,
	.alloc = ptr_alloc,
	.free = ptr_free,
	.init = ptr_init,
};

const heap_vtbl	*get_ptr_vtable(void)
{
	return &g_ptr_vtable;
}

