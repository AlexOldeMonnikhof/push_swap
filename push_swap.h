/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:00:15 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/03/14 17:29:52 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct push_swap
{
	int					value;
	int					index;
	struct push_swap	*next;
}					t_stack;

//MAIN FUNCTIONS
int			main(int argc, char **argv);
t_stack		*ft_make_stack_a(t_stack **stack_a, int argc, char **argv);
int			ft_sort_index(t_stack **head);
void		push_swap(int argc, t_stack **stack_a, t_stack **stack_b);

//LST FUNCTIONS
int			ft_lstsize(t_stack *lst);
t_stack		*ft_lstnew(int value);
t_stack		*ft_lstlast(t_stack *lst);
t_stack		*ft_lstsecondlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);

//PUSH
void		push(t_stack **src, t_stack **dst);
void		push_a(t_stack **stack_a, t_stack **stack_b);
void		push_b(t_stack **stack_a, t_stack **stack_b);

//LIBFT UTILS AND RANDOM UTILS
long long	ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_find_minormax(t_stack **stack_a, char c);
int			is_sorted(t_stack **stack_a);
void		ft_error(void);

//HARDCODE
void		ft_two_args(t_stack **head);
void		ft_three_args(t_stack **head_a);
void		ft_four_args(t_stack **head_a, t_stack **head_b);
void		ft_five_args(t_stack **head_a, t_stack **head_b);

//SWAP
void		swap(t_stack **head);
void		reverse_rotate(t_stack **head);
void		rotate(t_stack **head);

//RADIX
void		ft_radixsort(t_stack **stack_a, t_stack **stack_b);
int			find_byte_amount(t_stack **stack_a);

//FREE
void		free_stack(t_stack **stack_a);

#endif