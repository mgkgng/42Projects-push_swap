/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:33:35 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/20 23:50:16 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	index_count(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		i++;
	}
	return (count);
}

static char	*ft_strdup(char *s1)
{
	char	*res;
	int		i;

	res = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	return (res);
}

static char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*res;

	if (!s)
		return (NULL);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		res[i] = (char) s[start + i];
		i++;
	}
	return (res);
}

char	**ft_split(char *s, char c)
{
	char		**result;
	char		*start;
	int			i;
	int			len;

	if (!s)
		return (NULL);
	i = 0;
	result = malloc(sizeof(char *) * (index_count(s, c) + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		start = s;
		len = 0;
		while (*s && *s != c && len++ != -1)
			s++;
		if (*(s - 1) != c)
			result[i++] = ft_substr(start, 0, len);
	}
	result[i] = 0;
	return (result);
}
