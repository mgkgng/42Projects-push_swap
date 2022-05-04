/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:06:14 by min-kang          #+#    #+#             */
/*   Updated: 2022/05/04 22:08:34 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	terminate_parse(t_list *l)
{
	ft_lstclear(&l);
	error_exit();
}

static void	check_isdigit(char *s, t_list *l)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]))
		{
			if (!i && (s[i] == '-' || s[i] == '+') && s[i + 1])
				continue ;
			else
				terminate_parse(l);
		}
	}
}

static void	check_double(t_list *l, int new_nb)
{
	t_list	*begin;

	begin = l;
	while (l)
	{
		if (l->nb == new_nb)
			terminate_parse(begin);
		l = l->next;
	}
}

static t_list	*do_parse(char **argv, int start)
{
	t_list		*res;
	long int	nb;

	res = NULL;
	while (argv[start])
	{
		if (!ft_strlen(argv[start]))
			return (0);
		check_isdigit(argv[start], res);
		nb = ft_atol(argv[start++]);
		if (nb > INT32_MAX || nb < INT32_MIN)
			terminate_parse(res);
		check_double(res, nb);
		ft_lstadd_back(&res, ft_lstnew((int) nb));
	}
	return (res);
}

t_list	*parse(int argc, char **argv)
{
	if (argc == 2)
		return (do_parse(ft_split(argv[1], ' '), 0));
	return (do_parse(argv, 1));
}
