/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:06:25 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/18 19:20:39 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *l)
{
	int		min;

	min = l->nb;
	while (l)
	{
		if (l->nb < min)
			min = l->nb;
		l = l->next;
	}
	return (min);
}

int	find_next_min(t_list *l, int before)
{
	int		min;

	while (l->nb <= before)
		l = l->next;
	min = l->nb;
	while (l)
	{
		if (l->nb < min && l->nb > before)
			min = l->nb;
		l = l->next;
	}
	return (min);
}

void	min_index_put(t_list **lst, int min, int min_index)
{
	t_list	*begin;

	begin = *lst;
	while ((*lst)->nb != min && *lst)
		*lst = (*lst)->next;
	(*lst)->pos = min_index;
	*lst = begin;
}

void	put_pos(t_list **lst)
{
	int	index;
	int	min;
	int	size;

	index = 0;
	size = ft_lstsize(*lst);
	min = find_min(*lst);
	min_index_put(lst, min, index++);
	while (index < size)
	{
		min = find_next_min(*lst, min);
		min_index_put(lst, min, index++);
	}
}

void	put_index(t_list **lst)
{
	t_list	*begin;
	int		i;

	i = 0;
	begin = *lst;
	while (*lst)
	{
		(*lst)->index = i++;
		(*lst) = (*lst)->next;
	}
	*lst = begin;
}

