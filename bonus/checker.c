/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:14:37 by min-kang          #+#    #+#             */
/*   Updated: 2022/05/05 16:43:51 by min-kang         ###   ########.fr       */
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

void	execute_op(t_stack *stack, char *op)
{
	if (!ft_strcmp(op, "sa"))
		ops(stack, 0, NULL);
	else if (!ft_strcmp(op, "sb"))
		ops(stack, 1, NULL);
	else if (!ft_strcmp(op, "ss"))
		ops(stack, 2, NULL);
	else if (!ft_strcmp(op, "ra"))
		ops(stack, 3, NULL);
	else if (!ft_strcmp(op, "rb"))
		ops(stack, 4, NULL);
	else if (!ft_strcmp(op, "rr"))
		ops(stack, 5, NULL);
	else if (!ft_strcmp(op, "rra"))
		ops(stack, 6, NULL);
	else if (!ft_strcmp(op, "rrb"))
		ops(stack, 7, NULL);
	else if (!ft_strcmp(op, "rrr"))
		ops(stack, 8, NULL);
	else if (!ft_strcmp(op, "pa"))
		ops(stack, 9, NULL);
	else if (!ft_strcmp(op, "pb"))
		ops(stack, 10, NULL);
	else
		error_exit();
}

char	**get_ops(void)
{
	char	*res;
	char	*r_data;

	res = NULL;
	r_data = get_next_line(0);
	while (r_data)
	{
		res = ft_strcat(res, r_data);
		free(r_data);
		r_data = get_next_line(0);
	}
	return (ft_split(res, '\n'));
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

void	execute(t_stack *stack, char **ops)
{
	int		i;

	if (!ops)
		terminate(stack->a, stack->b);
	i = -1;
	while (ops[++i])
		execute_op(stack, ops[i]);
	terminate(stack->a, stack->b);
}
