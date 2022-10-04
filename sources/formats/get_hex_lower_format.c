/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex_lower_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:12:02 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/03 18:12:03 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	char*	formatter(void *data)
{
	t_hex_base_converter	*converter;
	unsigned long			*unsigned_data;
	char					*result;

	unsigned_data = data;
	converter = get_hex_base_converter();
	if (converter)
		result = converter->convert(*unsigned_data, converter->hex_lower_digits);
	free(converter);
	return (result);
}

void	*get_arg(va_list ap)
{
	unsigned long	*result;

	result = malloc(sizeof(unsigned long));
	if (result)
		*result = va_arg(ap, unsigned long);
	return (result);
}

t_data_format	*get_hex_lower_format(void)
{
	t_data_format	*data_format;

	data_format = malloc(sizeof(t_data_format));
	if (data_format)
	{
		data_format->id = "%x";
		data_format->formatter = formatter;
		data_format->get_arg = get_arg;
	}
	return (data_format);
}
