/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_u_decimal_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:33:07 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/04 15:33:07 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*formatter(void *data, t_list **flags)
{
	unsigned int	*int_data;

	int_data = data;
	if (!flags)
		return (ft_litoa(*int_data));
	return (ft_apply_flags(ft_litoa(*int_data), flags));
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

static t_list	**flags_list(void)
{
	t_list	**head;

	head = malloc(sizeof(t_list **));
	if (head)
	{
		*head = ft_lstnew(get_space_flag());
		ft_lstadd_back(head, ft_lstnew(get_plus_flag()));
	}
	return (head);
}

t_data_format	*get_u_decimal_format(void)
{
	t_data_format	*data_format;

	data_format = malloc(sizeof(t_data_format));
	if (data_format)
	{
		data_format->id = "%u";
		data_format->formatter = formatter;
		data_format->get_arg = get_arg;
		data_format->print = print;
		data_format->flags = flags_list();
	}
	return (data_format);
}
