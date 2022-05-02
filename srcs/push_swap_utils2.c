/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:20:10 by min-kang          #+#    #+#             */
/*   Updated: 2022/05/02 15:35:27 by min-kang         ###   ########.fr       */
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

// i could do it better again
t_index	get_chunk(t_list *lst)
{
	t_index	res;
	t_index	tmp;

	tmp.size = 0;
	tmp.begin = lst->index;
	ft_bzero(&res, sizeof(t_index));
	while (lst->next)
	{
		if (lst->nb < lst->next->nb)
		{
			tmp.end = lst->next->index;
			tmp.size = tmp.end - tmp.begin + 1;
			if (res.size < tmp.size)
			{
				res.size = tmp.size;
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
