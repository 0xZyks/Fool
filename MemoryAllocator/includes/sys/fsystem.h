/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsystem.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 05:59:55 by tsignori          #+#    #+#             */
/*   Updated: 2025/12/06 15:49:41 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FSYSTEM_H
# define FSYSTEM_H

# include "../types/fl_types.h"
# include <unistd.h>
# include <sys/mman.h>

typedef struct s_fl_os_mem {
	void	*(*reserve)(f_size size);
	void	(*release)(void *ptr, f_size size);
	f_size	page_size;
} fl_os_mem;

fl_os_mem linux_os_mem(void);

#endif // !SYSTEM_H
