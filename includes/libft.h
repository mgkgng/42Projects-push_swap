/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:41:02 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/28 16:20:41 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 99999

typedef struct s_list {
	int				nb;
	int				pos;
	int				index;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(char c);
void	ft_lstadd_back(t_list **alist, t_list *new);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int nb);
int		ft_lstsize(t_list *lst);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	*ft_realloc(void *ptr, size_t new_size);
char	**ft_split(char *s, char c);
char	*ft_strcat(char *dest, const char *src);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *s);
void	ft_putendl(char *s);
void	ft_putstr(char *s);

#endif
