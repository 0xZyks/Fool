/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:21:09 by tsignori          #+#    #+#             */
/*   Updated: 2025/12/05 18:36:11 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FL_TYPES_H
# define FL_TYPES_H

# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>

// scalaires “officiels” du langage
typedef uint8_t			f_uint8;
typedef uint16_t		f_uint16;
typedef uint32_t		f_uint32;
typedef uint64_t		f_uint64;

typedef int8_t			f_int8;
typedef int16_t			f_int16;
typedef int32_t			f_int32;
typedef int64_t			f_int64;

typedef size_t			f_size;
typedef ptrdiff_t		f_isize;

typedef int				fg_bool;

// alias “user facing” si tu veux
typedef unsigned char	fbyte;
typedef fg_bool			bool_t;   // si tu veux différencier

#endif // !FL_TYPES_H
