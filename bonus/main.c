/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:16:09 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/30 21:31:35 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**get_ops()
{
	char	*res;
	char	*r_data;

	res = NULL;
	while (1)
	{
		r_data = get_next_line(0);
		res = ft_strcat(res, r_data);
		free(r_data);
	}
	printf("coucou\n");
	return (ft_split(res, '\n'));
	/*r_data = NULL;
	ret = read(0, &buf, BUFFER_SIZE);
	if (ret < 0)
		execute(&stack, r_data);
	while (ret)
	{
		buf[ret] = '\0';
		r_data = ft_strcat(r_data, buf);
		ret = read(0, &buf, BUFFER_SIZE);
	}
	*/
}

int	main(int argc, char **argv)
{
	t_stack	stack;


	if (argc < 2)
		return (0);
	stack.a = parse(argc, argv);
	stack.b = NULL;
	execute(&stack, get_ops());
}
