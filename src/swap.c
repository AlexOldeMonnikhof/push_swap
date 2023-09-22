/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:35:00 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/22 16:12:37 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **head)
{
	int	tmp;

	tmp = (*head)->index;
	(*head)->index = (*head)->next->index;
	(*head)->next->index = tmp;
	tmp = (*head)->value;
	(*head)->value = (*head)->next->value;
	(*head)->next->value = tmp;
	write(1, "sa\n", 3);
}

void	reverse_rotate(t_stack **head)
{
	t_stack	*second_last;
	t_stack	*last;

	second_last = ft_lstsecondlast(*head);
	last = ft_lstlast(*head);
	last->next = *head;
	second_last->next = NULL;
	*head = last;
	write(1, "rra\n", 4);
}

void	rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	first = *head;
	last = ft_lstlast(*head);
	*head = first->next;
	last->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}

int	is_sorted(t_stack **stack_a)
{
	t_stack	*ptr;
	int		i;

	ptr = *stack_a;
	i = ptr->index;
	while (ptr)
	{
		if (ptr->index != i)
			return (0);
		ptr = ptr->next;
		i++;
	}
	return (1);
}
