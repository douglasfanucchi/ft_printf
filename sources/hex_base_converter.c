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

static void	reverse_tab(char *tab)
{
	size_t	len;
	size_t	start;
	size_t	end;
	char	tmp;

	len = ft_strlen(tab);
	start = 0;
	end = len - 1;
	while (end > start)
	{
		tmp = tab[start];
		tab[start] = tab[end];
		tab[end] = tmp;
		start++;
		end--;
	}
}

static char	*convert_recursive(unsigned int n, char *digits, size_t index)
{
	char	*hex_nbr;
	char	tmp;

	if (n == 0 && index != 0)
		return (ft_calloc(index, sizeof(char)));
	if (n == 0 && index == 0)
	{
		hex_nbr = ft_calloc(2, sizeof(char));
		ft_strlcpy(hex_nbr, "0", 2);
		return (hex_nbr);
	}
	hex_nbr = convert_recursive(n / 16, digits, index + 1);
	if (!hex_nbr)
		return (NULL);
	hex_nbr[index] = digits[n % 16];
	return (hex_nbr);
}

static char	*convert(int n, char *digits)
{
	char	*result;

	result = convert_recursive((unsigned int) n, digits, 0);
	if (result)
		reverse_tab(result);
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
