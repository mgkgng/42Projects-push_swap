/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:59:22 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/28 16:27:57 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"

typedef struct s_stack {
	t_list	*a;
	t_list	*b;
}	t_stack;

t_list	*parse(int argc, char **argv);
void	ops(t_stack *stack, int op, char *s);
int		error_exit(void);

#endif