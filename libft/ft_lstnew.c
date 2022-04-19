/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:04:19 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/19 16:02:56 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int nb)
{
	t_list	*res;

	res = ft_calloc(1, sizeof(t_list));
	res->nb = nb;
	return (res);
}
