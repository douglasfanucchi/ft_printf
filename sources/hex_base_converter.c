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

t_hex_base_converter	*get_hex_base_converter(void)
{
	t_hex_base_converter	*converter;

	converter = malloc(sizeof(t_hex_base_converter));
	return (converter);
}
