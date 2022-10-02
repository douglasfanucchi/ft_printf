/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 01:52:07 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/02 01:52:08 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*char_formatter(void *s)
{
	return s;
}

static void	*char_get_arg(va_list ap)
{
	char	*result;

	result = malloc(sizeof(char));
	*result = (char) va_arg(ap, int);
	return (result);
}

t_data_format	*get_char_format()
{
	t_data_format	*data_format;

	data_format = (t_data_format *)malloc(sizeof(t_data_format));
	if (data_format)
	{
		data_format->id = "%c";
		data_format->formatter = char_formatter;
		data_format->get_arg = char_get_arg;
	}
	return (data_format);
}
