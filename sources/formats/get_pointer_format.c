/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pointer_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:15:23 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/04 13:15:23 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*formatter(void *data)
{
	t_hex_base_converter	*converter;
	char					*prefix;
	char					*hex;
	char					*result;

	result = NULL;
	converter = get_hex_base_converter();
	if (converter)
	{
		prefix = ft_strdup("0x");
		hex = converter->convert(
				(unsigned long) data,
				converter->hex_lower_digits);
		result = ft_strjoin(prefix, hex);
		free(prefix);
		free(hex);
		free(converter);
	}
	return (result);
}

static void	*get_arg(va_list ap)
{
	return (va_arg(ap, void *));
}

t_data_format	*get_pointer_format(void)
{
	t_data_format	*data_format;

	data_format = malloc(sizeof(t_data_format));
	if (data_format)
	{
		data_format->id = "%p";
		data_format->formatter = formatter;
		data_format->get_arg = get_arg;
	}
	return (data_format);
}
