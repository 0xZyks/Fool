/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heaps_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:33:54 by tsignori          #+#    #+#             */
/*   Updated: 2025/12/07 05:03:34 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAPS_UTILS_PROTOTYPES_H
# define HEAPS_UTILS_PROTOTYPES_H

# include "../fheaps.h"


const heap_vtbl	*get_raw_vtable(void);
const heap_vtbl	*get_ptr_vtable(void);
const heap_vtbl	*get_t04_vtable(void);
const heap_vtbl	*get_t08_vtable(void);
const heap_vtbl	*get_t16_vtable(void);
const heap_vtbl	*get_t24_vtable(void);
const heap_vtbl	*get_t32_vtable(void);
const heap_vtbl	*get_t64_vtable(void);
const heap_vtbl	*get_t128_vtable(void);
const heap_vtbl	*get_t256_vtable(void);

#endif // !HEAPS_UTILS_PROTOTYPES_H
