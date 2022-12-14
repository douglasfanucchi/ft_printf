/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:33:40 by dfanucch          #+#    #+#             */
/*   Updated: 2022/09/08 10:33:41 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (!ft_isalpha(c) || c < 97 || c > 122)
		return (c);
	return (c - 32);
}
