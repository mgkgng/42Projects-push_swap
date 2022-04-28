/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:17:23 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/28 16:21:59 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"

void	execute(t_stack *stack, char *s);
int		checker(t_list *a, t_list *b);
void	check_free_exit(t_list *lst_a, t_list *lst_b);

#endif
