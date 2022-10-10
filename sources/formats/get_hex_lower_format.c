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

static char	*formatter(void *data, t_list **flags)
{
	t_hex_base_converter	*converter;
	unsigned int			*unsigned_data;
	char					*result;

	unsigned_data = data;
	converter = get_hex_base_converter();
	if (!converter)
		return (NULL);
	result = converter->convert(*unsigned_data,
			converter->hex_lower_digits);
	if (flags)
		result = ft_apply_flags(result, flags);
	free(converter);
	return (result);
}

static void	*get_arg(va_list ap)
{
	unsigned int	*result;

	result = malloc(sizeof(unsigned int));
	if (result)
		*result = va_arg(ap, unsigned int);
	return (result);
}

static size_t	print(t_data_format *data_format, va_list ap)
{
	char	*arg;
	char	*formatted;
	size_t	len;

	arg = data_format->get_arg(ap);
	formatted = data_format->formatter(arg, NULL);
	ft_putstr(formatted);
	len = ft_strlen(formatted);
	free(arg);
	free(formatted);
	return (len);
}

t_list	**flags_list(void)
{
	t_list	**head;

	head = malloc(sizeof(t_list **));
	if (head)
	{
		*head = ft_lstnew(get_sharp_flag());
		ft_lstadd_back(head, ft_lstnew(get_space_flag()));
		ft_lstadd_back(head, ft_lstnew(get_plus_flag()));
	}
	return (head);
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
		data_format->print = print;
		data_format->flags = flags_list();
	}
	return (data_format);
}
