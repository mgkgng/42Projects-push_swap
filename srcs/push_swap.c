/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:51 by min-kang          #+#    #+#             */
/*   Updated: 2022/05/02 15:36:05 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_stack *stack)
{
	t_index	chunk;

	if (ft_lstsize(stack->a) == 1)
		return (0);
	put_index(&stack->a);
	put_pos(&stack->a);
	chunk = get_chunk(stack->a);
	if (chunk.size == ft_lstsize(stack->a))
		return (terminate(stack));
	else if (chunk.size < 3)
		mini_swap(stack);
	else
		algo_push_b(stack, chunk);
	algo_push_a(stack);
	algo_rotate_a(stack);
	return (terminate(stack));
}
