/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:05:18 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/23 12:10:37 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compare_move(t_move move, t_move *opt)
{
	if (move.sum < opt->sum)
	{
		opt->sum = move.sum;
		opt->ra = move.ra;
		opt->rra = move.rra;
		opt->rb = move.rb;
		opt->rrb = move.rrb;
	}
}

static void	rotate_both(t_stack *stack, t_move *move)
{
	while (move->ra > 0 && move->rb > 0)
	{
		ops(stack, 5, "rr");
		move->ra--;
		move->rb--;
	}
	while (move->rra > 0 && move->rrb > 0)
	{
		ops(stack, 8, "rrr");
		move->rra--;
		move->rrb--;
	}
}

void	make_move(t_stack *stack, t_move move)
{
	rotate_both(stack, &move);
	while (move.ra > 0)
	{
		ops(stack, 3, "ra");
		move.ra--;
	}
	while (move.rb > 0)
	{
		ops(stack, 4, "rb");
		move.rb--;
	}
	while (move.rra > 0)
	{
		ops(stack, 6, "rra");
		move.rra--;
	}
	while (move.rrb > 0)
	{
		ops(stack, 7, "rrb");
		move.rrb--;
	}
	ops(stack, 10, "pa");
}

t_move	define_move(t_list *a, t_list *b, int sizeA, int sizeB)
{
	t_move	res;

	ft_bzero(&res, sizeof(t_move));
	if (a->index <= sizeA / 2)
		res.ra = a->index;
	else
		res.rra = sizeA - a->index;
	if (b->index <= sizeB / 2)
		res.rb = b->index;
	else
		res.rra = sizeB - b->index;
	res.sum = res.ra + res.rra + res.rb + res.rrb;
	return (res);
}

t_move	get_shortest(t_list *a, t_list *b)
{
	t_move	res;
	t_list	*begin_a;
	int		last_a;

	begin_a = a;
	ft_bzero(&res, sizeof(t_move));
	res.sum = INT32_MAX;
	while (b)
	{
		a = begin_a;
		last_a = ft_lstlast(a)->nb;
		while (a)
		{
			if (check_push(a->nb, last_a, b->nb))
			{
				compare_move(define_move(a, b, ft_lstsize(a), ft_lstsize(b)), &res);
				break ;
			}
			last_a = a->nb;
			a = a->next;
		}
		b = b->next;
	}
	printf(" ra=%d, rra=%d, rb=%d, rrb=%d\n", res.ra, res.rra, res.rb, res.rrb);
	return (res);
}
