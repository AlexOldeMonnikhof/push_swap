/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:14:36 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/22 16:12:35 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_byte_amount(t_stack **stack_a)
{
	int	max;
	int	i;

	max = ft_find_minormax(stack_a, 'M');
	i = 0;
	while (max >> i)
		i++;
	return (i);
}

void	ft_radixsort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	byte_amount;
	int	lstsize;

	byte_amount = find_byte_amount(stack_a);
	lstsize = ft_lstsize(*stack_a);
	i = 0;
	while (i < byte_amount)
	{
		j = 0;
		while (j < lstsize)
		{
			if (((*stack_a)->index >> i) & 1)
				rotate(stack_a);
			else
				push_b(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			push_a(stack_a, stack_b);
		i++;
	}
}
