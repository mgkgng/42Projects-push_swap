/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:05:22 by min-kang          #+#    #+#             */
/*   Updated: 2022/05/05 16:42:39 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_swap(t_stack *stack)
{
	while (ft_lstsize(stack->a) > 3)
		ops(stack, 10, "pb");
	if (stack->a->nb > stack->a->next->nb
		&& stack->a->next->nb < ft_lstlast(stack->a)->nb
		&& find_max(stack->a) == stack->a->nb)
		ops(stack, 3, "ra");
	else if ((stack->a->nb > stack->a->next->nb)
		|| (find_max(stack->a) == stack->a->next->nb
			&& find_min(stack->a) == stack->a->nb))
		ops(stack, 0, "sa");
	if (find_min(stack->a) == stack->a->next->nb)
		ops(stack, 3, "ra");
	else if (find_min(stack->a) == ft_lstlast(stack->a)->nb)
		ops(stack, 6, "rra");
}

int	check_push(int first_a, int last_a, int first_b)
{
	if (first_a > first_b && first_a < last_a)
		return (1);
	else if (first_a > first_b && first_b > last_a)
		return (1);
	else if (first_a < last_a && first_b > last_a)
		return (1);
	return (0);
}

void	algo_push_b(t_stack *stack, t_index chunk)
{
	int	i;
	int	size_a;
	int	size_chunk;

	size_a = ft_lstsize(stack->a);
	if (size_a > 99)
	{
		i = 0;
		while (++i < 3)
		{
			size_chunk = size_a * i / 3 ;
			while (ft_lstsize(stack->b) < size_chunk - chunk.size)
				push_or_rotate(stack, chunk, size_chunk);
		}
	}
	while (ft_lstsize(stack->a) != chunk.size)
		push_or_rotate(stack, chunk, 0);
}

void	algo_push_a(t_stack *stack)
{
	while (stack->b)
	{
		if (check_push(stack->a->pos, ft_lstlast(stack->a)->pos, stack->b->pos))
			ops(stack, 9, "pa");
		else
		{
			put_index(&stack->a);
			put_index(&stack->b);
			make_move(stack, get_move(stack->a, stack->b,
					ft_lstsize(stack->a), ft_lstsize(stack->b)));
		}
	}
}

void	algo_rotate_a(t_stack *stack)
{
	int	size;

	if (!stack->a->pos)
		return ;
	size = ft_lstsize(stack->a);
	if (stack->a->pos < size / 2)
		while (stack->a->pos)
			ops(stack, 6, "rra");
	else
		while (stack->a->pos)
			ops(stack, 3, "ra");
}
