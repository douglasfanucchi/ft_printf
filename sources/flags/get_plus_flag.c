/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plus_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 07:36:20 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/10 07:36:20 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*formatter(char *str)
{
	if (*str == '-')
		return (ft_strdup(str));
	if (*str == ' ')
		str++;
	return (ft_strjoin("+", str));
}

t_flag	*get_plus_flag(void)
{
	t_flag	*flag;

	flag = malloc(sizeof(t_flag));
	if (flag)
	{
		flag->type = "+";
		flag->formatter = formatter;
	}
	return (flag);
}
