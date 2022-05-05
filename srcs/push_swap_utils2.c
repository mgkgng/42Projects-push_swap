/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:20:10 by min-kang          #+#    #+#             */
/*   Updated: 2022/05/05 14:26:12 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_index	get_chunk(t_list *l)
{
	int		size;
	int		begin;
	t_index	res;

	ft_bzero(&res, sizeof(t_index));
	while (l && l->next)
	{
		size = 1;
		begin = l->index;
		while (l->next && l->nb < l->next->nb)
		{	
			size++;
			l = l->next;
		}
		if (size > res.size)
		{
			res.size = size;
			res.begin = begin;
			res.end = begin + size - 1;
		}
		l = l->next;
	}
	return (res);
}

int	terminate(t_stack *stack)
{
	ft_lstclear(&stack->a);
	if (stack->b)
		ft_lstclear(&stack->b);
	return (0);
}

void	push_or_rotate(t_stack *stack, t_index chunk, int size)
{
	if ((stack->a->index < chunk.begin || stack->a->index > chunk.end)
		&& (!size || stack->a->pos < size))
		ops(stack, 11, "pb");
	else
		ops(stack, 3, "ra");
}
