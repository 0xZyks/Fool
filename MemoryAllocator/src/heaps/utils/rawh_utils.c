/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rawh_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:08:51 by tsignori          #+#    #+#             */
/*   Updated: 2025/12/09 20:51:46 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/heaps/fheaps.h"

void	*raw_alloc(void *heap, f_size size)
{
	fheap			*tmp;
	f_size			size8;
	unsigned char	*ptr;

	tmp = (fheap *)heap;
	size8 = (size + 7) & ~((f_size)7);

    if (tmp->offset + size8 > tmp->capacity)
        return NULL;
	
	// ADD SoA
    ptr = (unsigned char *)tmp->base + tmp->offset;
    tmp->offset += size8;

	// Update Bitset in live;
    return (ptr);
}

void	raw_free(void *heap, void *ptr)
{
	(void)heap;
	(void)ptr;
}

void	raw_free_heap(void *heap)
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

void	raw_init(void *heap)
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
	tmp->id = RAW_HEAP;
	tmp->capacity = 124ULL * 1024ULL * 64;
	tmp->bitset_chunks = 8;
	tmp->offset = 0;
	tmp->bitset_size = 1;
	nb_chunks = tmp->capacity / tmp->bitset_chunks;
	bitset_size = (nb_chunks + 7) / 8;
	tmp->bitset_size = bitset_size;
	tmp->base = (unsigned char *)central->os.reserve(tmp->capacity);
	// \\User:id:x:y:z
	// \\0x47:17:x:y:z
	tmp->bitset = central->os.reserve(bitset_size);

	tmp->is_init = 1;
}

static const heap_vtbl g_raw_vtable = {
	.free_heap = raw_free_heap,
	.alloc = raw_alloc,
	.free = raw_free,
	.init = raw_init,
};

const heap_vtbl	*get_raw_vtable(void)
{
	return &g_raw_vtable;
}
