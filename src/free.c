/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:42:16 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/22 16:12:24 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack **stack_a)
{
	t_stack	*head;

	head = *stack_a;
	while (head)
	{
		head = (*stack_a)->next;
		free(*stack_a);
		*stack_a = head;
	}
	free(*stack_a);
}
