/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:05:02 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/06 13:05:02 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	ft_print_formatted_data(t_list **formats,
	t_data_format *data_format, va_list ap)
{
	char			*arg;
	char			*formatted;

	arg = NULL;
	if (data_format->get_arg)
		arg = data_format->get_arg(ap);
	formatted = data_format->formatter(arg);
	ft_pustr(formatted);
	free(formatted);
	free(arg);
}

void	ft_printf(char *str, ...)
{
	t_list			**formats;
	t_data_format	*data_format;
	va_list			ap;

	va_start(ap, str);
	formats = get_formats_list();
	if (!formats)
		return ;
	while (*str)
	{
		data_format = find_format_from_str_start(formats, str);
		if (data_format)
		{
			ft_print_formatted_data(formats, data_format, ap);
			str += ft_strlen(data_format->id);
			continue ;
		}
		write(1, str++, 1);
	}
	ft_lstclear(formats, del_data_formats);
	free(formats);
	va_end(ap);
}
