/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:51 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/18 19:12:16 by min-kang         ###   ########.fr       */
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
	if (chunk.end - chunk.begin + 1 < 3)
		mini_swap(stack);
	else
		algo_pushB(stack, chunk);
	algo_pushA(stack);
	algo_rotateA(stack);
	free_list(stack);
	return (0);
}
