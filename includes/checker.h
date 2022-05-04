/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:17:23 by min-kang          #+#    #+#             */
/*   Updated: 2022/05/04 22:10:07 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"

void	execute(t_stack *stack, char **ops);
int		checker(t_list *a, t_list *b);
void	check_free_exit(t_list *lst_a, t_list *lst_b);
char	**get_ops(void);

#endif
