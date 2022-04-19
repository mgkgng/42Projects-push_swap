/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:17:23 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/19 17:00:38 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"

void	execute(t_list **lst_a, t_list **lst_b, char *s);
int		checker(t_list *lst_a, t_list *lst_b);
void	check_free_exit(t_list *lst_a, t_list *lst_b);

#endif
