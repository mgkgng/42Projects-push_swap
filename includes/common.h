/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:59:22 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/19 17:00:01 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"

typedef struct s_stack {
	t_list	*a;
	t_list	*b;
}	t_stack;

int	error_exit(void);

#endif