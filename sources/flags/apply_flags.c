/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:07:36 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/10 17:07:36 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_apply_flags(char *str, t_list **flag_list)
{
	t_list	*flag_node;
	t_flag	*flag;
	void	*tmp;

	flag_node = *flag_list;
	while (flag_node)
	{
		flag = flag_node->content;
		tmp = str;
		str = flag->formatter(str);
		free(tmp);
		flag_node = flag_node->next;
	}
	return (str);
}
