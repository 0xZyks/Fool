/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsystem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 06:11:38 by tsignori          #+#    #+#             */
/*   Updated: 2025/12/06 11:47:51 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sys/fsystem.h"

static long	get_linux_pagesize(void)
{
	static long	page_size;

	if (page_size == 0)
	{
		page_size = sysconf(_SC_PAGE_SIZE);
		if (page_size <= 0)
			page_size = 4096;
	}
	return page_size; 
}

static void	*linux_reserve(f_size size)
{
	long	ps;
	f_size	align;
	void	*ptr;

	if (size == 0)
		return ((void *)0);
	ps = get_linux_pagesize();
	align = (size + ps - 1) & ~(ps - 1);
	ptr = mmap((void *)0, align, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ptr == MAP_FAILED)
		return ((void *)0);
	return (ptr);
}

static void	linux_release(void *ptr, f_size size)
{
	long	ps;
	f_size	align;

	if (size <= 0)
		return;
	ps = get_linux_pagesize();
	align = (size + ps - 1) & ~(ps - 1);
	munmap(ptr, align);
}

fl_os_mem linux_os_mem(void)
{
	fl_os_mem	os_mem;

	os_mem.reserve = linux_reserve;
	os_mem.release = linux_release;
	os_mem.page_size = (f_size)get_linux_pagesize();
	return  os_mem;
}
