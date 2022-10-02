/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:48:33 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/01 16:48:34 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <libft.h>

struct	s_data_format {
	char	*id;
	char	*(*formatter)(void *);
	void	*(*get_arg)(va_list);
};

typedef struct s_data_format	t_data_format;

t_data_format	*get_char_format();

#endif