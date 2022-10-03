/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:30:26 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/02 12:30:27 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*convert(int n, char *digits)
{
	char			*result;
	unsigned int	unsigned_n;
	size_t			result_len;
	size_t			i;

	result_len = 1;
	i = 0;
	unsigned_n = (unsigned int) n;
	while (unsigned_n / 16)
	{
		unsigned_n /= 16;
		result_len++;
	}
	result = ft_calloc(result_len + 1, sizeof(char));
	if (result)
	{
		unsigned_n = (unsigned int) n;
		while (unsigned_n / 16)
		{
			result[result_len - 1 - i++] = digits[unsigned_n % 16];
			unsigned_n /= 16;
		}
		result[result_len - 1 - i] = digits[unsigned_n % 16];
	}
	return (result);
}

t_hex_base_converter	*get_hex_base_converter(void)
{
	t_hex_base_converter	*converter;

	converter = malloc(sizeof(t_hex_base_converter));
	if (converter)
	{
		converter->hex_lower_digits = "0123456789abcdef";
		converter->hex_upper_digits = "0123456789ABCDEF";
		converter->convert = convert;
	}
	return (converter);
}
