/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:48:22 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/22 16:12:26 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_two_args(t_stack **head)
{
	t_stack	*ptr;

	ptr = *head;
	if (ptr->index == 1)
		swap(head);
}

void	ft_three_args(t_stack **head_a)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(head_a))
		return ;
	first = (*head_a)->index;
	second = (*head_a)->next->index;
	third = (*head_a)->next->next->index;
	if (first > second && first < third)
		swap(head_a);
	else if (first > second && second > third)
	{
		swap(head_a);
		reverse_rotate(head_a);
	}
	else if (first > third && second < third)
		rotate(head_a);
	else if (first < third && second > third)
	{
		swap(head_a);
		rotate(head_a);
	}
	else
		reverse_rotate(head_a);
}

void	ft_four_args(t_stack **head_a, t_stack **head_b)
{
	int	min_val;
	int	max_val;

	min_val = ft_find_minormax(head_a, 'm');
	max_val = ft_find_minormax(head_a, 'M');
	if (is_sorted(head_a))
		return ;
	while ((*head_a) && (*head_a)->index != max_val
		&& (*head_a)->index != min_val)
		rotate(head_a);
	if (is_sorted(head_a))
		return ;
	push_b(head_a, head_b);
	ft_three_args(head_a);
	push_a(head_a, head_b);
	if (!is_sorted(head_a))
		rotate(head_a);
}

void	ft_five_args(t_stack **head_a, t_stack **head_b)
{
	t_stack	*last;

	if (is_sorted(head_a))
		return ;
	last = ft_lstlast(*head_a);
	while (ft_lstsize(*head_a) != 4)
	{
		if (last->index == 4 || last->index == 0)
			reverse_rotate(head_a);
		if ((*head_a)->index == 4 || (*head_a)->index == 0)
		{
			push_b(head_a, head_b);
			break ;
		}
		rotate(head_a);
	}
	ft_four_args(head_a, head_b);
	push_a(head_a, head_b);
	if ((*head_a)->index == 4)
		rotate(head_a);
}
