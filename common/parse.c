/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:06:14 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/21 00:29:48 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_error(char *s, char **argv)
{
	int	i;
	int	j;
	int	nb;

	if (!ft_strlen(s))
		return (0);
	i = -1;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]))
		{
			if (!i && (s[i] == '-' || s[i] == '+'))
			{
				if (!s[i + 1])
					return (0);
				continue ;
			}
			else
				return (0);
		}
		// should find a more elegant way to check this error
		j = i;
		nb = ft_atoi(s);
		while (argv[++j])
			if (ft_atoi(argv[j]) == nb)
				return (0);
	}
	return (1);
}

static t_list	*do_parse(char **argv, int start)
{
	t_list	*res;

	res = NULL;
	while (argv[start])
	{
		if (!check_error(argv[start], argv))
		{
			ft_lstclear(&res);
			error_exit();
		}
		ft_lstadd_back(&res, ft_lstnew(ft_atoi(argv[start++])));
	}
	return (res);
}

t_list	*parse(int argc, char **argv)
{
	if (argc == 2)
		return (do_parse(ft_split(argv[1], ' '), 0));
	return (do_parse(argv, 1));
}
