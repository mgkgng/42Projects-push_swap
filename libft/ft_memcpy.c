/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:52:10 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/30 18:52:22 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*p_dst;
	char	*p_src;

	if (!n)
		return (dst);
	if (!dst && !src)
		return (NULL);
	p_dst = (char *) dst;
	p_src = (char *) src;
	i = 0;
	while (i++ < n)
		*p_dst++ = *p_src++;
	return (dst);
}