/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:14:37 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/30 21:30:41 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	terminate(t_list *a, t_list *b)
{
	if (checker(a, b))
	{
		ft_lstclear(&a);
		ft_putendl("OK");
		exit(EXIT_SUCCESS);
	}
	ft_lstclear(&a);
	if (b)
		ft_lstclear(&b);
	ft_putendl("KO");
	exit(EXIT_FAILURE);
}

void	execute_op(t_stack *stack, char *to_do)
{
	if (!ft_strcmp(to_do, "sa"))
		ops(stack, 0, NULL);
	else if (!ft_strcmp(to_do, "sb"))
		ops(stack, 1, NULL);
	else if (!ft_strcmp(to_do, "ss"))
		ops(stack, 2, NULL);
	else if (!ft_strcmp(to_do, "ra"))
		ops(stack, 3, NULL);
	else if (!ft_strcmp(to_do, "rb"))
		ops(stack, 4, NULL);
	else if (!ft_strcmp(to_do, "rr"))
		ops(stack, 5, NULL);
	else if (!ft_strcmp(to_do, "rra"))
		ops(stack, 6, NULL);
	else if (!ft_strcmp(to_do, "rrb"))
		ops(stack, 7, NULL);
	else if (!ft_strcmp(to_do, "rrr"))
		ops(stack, 8, NULL);
	else if (!ft_strcmp(to_do, "pa"))
		ops(stack, 9, NULL);
	else if (!ft_strcmp(to_do, "pb"))
		ops(stack, 10, NULL);
	else
		error_exit();
}

void	execute(t_stack *stack, char **ops)
{
	//char	**to_do;
	int		i;

	/*if (!s)
		terminate(stack->a, stack->b);
	to_do = ft_split(s, '\n');
	i = -1;
	while (to_do[++i])
		execute_op(stack, to_do[i]);*/
	if (!ops[0])
		terminate(stack->a, stack->b);
	i = -1;
	while (ops[++i])
		execute_op(stack, ops[i]);
	terminate(stack->a, stack->b);
}

int	checker(t_list *a, t_list *b)
{
	if (b)
		return (0);
	while (a->next)
	{
		if (a->nb > a->next->nb)
			return (0);
		a = a->next;
	}
	return (1);
}
