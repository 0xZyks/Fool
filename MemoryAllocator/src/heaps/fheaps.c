/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fheaps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:54:15 by tsignori          #+#    #+#             */
/*   Updated: 2025/12/09 19:51:36 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sys/fsystem.h"
#include "../../includes/heaps/fheaps.h"
#include "../../includes/heaps/utils/heaps_utils.h"

static void	set_vtable(fheap *heap)
{
	switch (heap->id)
	{
		case RAW_HEAP:
			heap->vptr =  get_raw_vtable();
			break;
		case PTR_HEAP:
			heap->vptr =  get_ptr_vtable();
			break;
		case T04_HEAP:
			heap->vptr =  get_t04_vtable();
			break;
		case T08_HEAP:
			heap->vptr =  get_t08_vtable();
			break;
		case T16_HEAP:
			heap->vptr =  get_t16_vtable();
			break;
		case T32_HEAP:
			heap->vptr =  get_t32_vtable();
			break;
		case T64_HEAP:
			heap->vptr =  get_t64_vtable();
			break;
		case T128_HEAP:
			heap->vptr =  get_t128_vtable();
			break;
		case T256_HEAP:
			heap->vptr =  get_t256_vtable();
			break;
	}
}

fl_central	*get_central(void)
{
	static fl_central	central;
	if (!central.init[0])
		central.os = linux_os_mem(); 
	return (&central);
}

fheap	*get_heap(int id)
{
	fl_central	*central = get_central();
	fheap		*heap = &central->heaps[id];

	if (!central->init[id])
	{
		central->init[id] = 1;
		heap->id = id;
		set_vtable(heap);
		heap->is_init = 0;
		heap->vptr->init(heap);
	}
	return (heap);
}

