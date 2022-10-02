/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 02:10:54 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/02 02:10:54 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*formatter(void *str)
{
	return (str);
}

static void	*get_arg(va_list ap)
{
	return (va_arg(ap, char *));
}

t_data_format	*get_str_format(void)
{
	t_data_format	*data_format;

	data_format = (t_data_format *)malloc(sizeof(t_data_format));
	if (data_format)
	{
		data_format->id = "%s";
		data_format->formatter = formatter;
		data_format->get_arg = get_arg;
	}
	return (data_format);
}
