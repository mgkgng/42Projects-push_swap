/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:05:22 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/25 10:53:08 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_swap(t_stack *stack)
{
	while (ft_lstsize(stack->a) > 3)
		ops(stack, 11, "pb");
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
	printf("---%d---%d---%d===\n", first_a, last_a, first_b);
	if (first_a > first_b && first_a < last_a)
	{
		printf("11111111\n");
		return (1);
	}
	else if (first_a > first_b && first_b > last_a)
	{
		printf("222222222\n");
		return (1);
	}
	else if (first_a < last_a && first_b > last_a)
	{
		printf("33333333\n");
		return (1);
	}
	printf("000000000\n");
	return (0);
}

void	algo_push_b(t_stack *stack, t_index chunk)
{
	int	i;
	int	size_a;
	int	size_chunk;

	size_a = ft_lstsize(stack->a);
	size_chunk = 3;
	if (size_a > 99)
	{
		i = 0;
		while (++i < size_chunk)
		{
			if ((stack->a->index < chunk.begin || stack->a->index > chunk.end)
				&& stack->a->pos < size_a * i / size_chunk)
				ops(stack, 11, "pb");
			else
				ops(stack, 3, "ra");
		}
	}
	while (ft_lstsize(stack->a) != chunk.size)
	{
		if (stack->a->index < chunk.begin || stack->a->index > chunk.end)
			ops(stack, 11, "pb");
		else
			ops(stack, 3, "ra");
	}
}

void	algo_push_a(t_stack *stack)
{
	while (stack->b)
	{
		printf("b = %d ... a = %d \n", stack->b->nb, stack->a->nb);
		t_list *save_a;
		save_a = stack->a;
		while (stack->a)
		{
			printf("...%d", stack->a->nb);
			stack->a = stack->a->next;
		}
		printf("\n");
		stack->a = save_a;
		if (check_push(stack->a->pos, ft_lstlast(stack->a)->pos, stack->b->pos))
			ops(stack, 10, "pa");
		else
		{
			put_index(&stack->a);
			put_index(&stack->b);
			make_move(stack, get_move(stack->a, stack->b));
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
