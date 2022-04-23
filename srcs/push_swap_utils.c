/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:06:25 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/23 11:29:02 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list *l)
{
	int	max;

	max = l->nb;
	while (l)
	{
		if (l->nb > max)
			max = l->nb;
		l = l->next;
	}
	return (max);
}

int	find_min(t_list *l)
{
	int	min;

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

void	put_min_pos(t_list **l, int min, int min_pos)
{
	t_list	*begin;

	begin = *l;
	while (*l && (*l)->nb != min)
		*l = (*l)->next;
	(*l)->pos = min_pos;
	*l = begin;
}

void	put_pos(t_list **l)
{
	int	index;
	int	min;
	int	size;

	index = 0;
	size = ft_lstsize(*l);
	min = find_min(*l);
	put_min_pos(l, min, index++);
	while (index < size)
	{
		min = find_next_min(*l, min);
		put_min_pos(l, min, index++);
	}
}

void	put_index(t_list **l)
{
	t_list	*begin;
	int		i;

	i = 0;
	begin = *l;
	while (*l)
	{
		(*l)->index = i++;
		*l = (*l)->next;
	}
	*l = begin;
}
