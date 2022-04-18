/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:20:10 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/18 19:22:42 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_index	get_chunk(t_list *lst)
{
	t_index	res;
	t_index	tmp;
	int		dist;

	dist = 0;
	tmp.begin = lst->index;
	res.begin = 0;
	res.end = 0;
	while (lst->next)
	{
		if (lst->nb < lst->next->nb)
		{
			tmp.end = lst->next->index;
			if (dist < tmp.end - tmp.begin)
			{
				dist = tmp.end - tmp.begin;
				res.begin = tmp.begin;
				res.end = tmp.end;
			}
		}
		else
			tmp.begin = lst->next->index;
		lst = lst->next;
	}
	return (res);
}
