/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sharp_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 05:45:23 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/10 05:45:23 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*formatter(char *str, ...)
{
	if (*str == '0')
		return (ft_strdup(str));
	return (ft_strjoin("0x", str));
}

t_flag	*get_sharp_flag(void)
{
	t_flag	*flag;

	flag = malloc(sizeof(t_flag));
	if (flag)
	{
		flag->type = "#";
		flag->formatter = formatter;
	}
	return (flag);
}
