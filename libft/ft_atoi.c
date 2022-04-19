/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:15:01 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/19 17:15:04 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

int	ft_atoi(const char *str)
{
	long int	result;
	int			i;
	int			minus;

	i = 0;
	minus = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		minus *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i++] - '0');
		if (result * minus > INT32_MAX || result * minus < INT32_MIN)
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
	}
	return (result * minus);
}
