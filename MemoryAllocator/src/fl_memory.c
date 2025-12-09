/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:15:30 by tsignori          #+#    #+#             */
/*   Updated: 2025/12/06 05:52:05 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fl_memory.h"
#include "../includes/types/fl_types.h"
#include <stdio.h>

void	*fl_malloc(f_size len)
{
	void	*ptr;

	return (ptr);
}

int	main(int ac, char **av)
{
	if (ac <= 1)
		return (printf("Bad use, try passing parameters !"));
	char	*str = *(++av);
	printf("Str: %s\n", str);

	return (0);
}
