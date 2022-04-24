/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:05:57 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/23 22:23:32 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

typedef struct s_move {
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	sum;
}	t_move;

typedef struct s_value {
	int	value;
	int	index;
}	t_value;

typedef struct s_index {
	int	begin;
	int	end;
	int	size;
}	t_index;

int		push_swap(t_stack *stack);
void	ops(t_stack *stack, int op, char *s);
t_list	*parse(int argc, char **argv);
void	mini_swap(t_stack *stack);
void	algo_push_b(t_stack *stack, t_index chunk);
void	algo_push_a(t_stack *stack);
void	algo_rotate_a(t_stack *stack);
int		check_push(int first_a, int last_a, int first_b);

/* move */
void	make_move(t_stack *stack, t_move move);
t_move	get_move(t_list *a, t_list *b);


/* utils */
void	put_index(t_list **lst);
void	put_pos(t_list **lst);
t_index	get_chunk(t_list *lst);
int		find_max(t_list *l);
int		find_min(t_list *l);



#endif
