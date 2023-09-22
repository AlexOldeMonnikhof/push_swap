/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:02:05 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/22 16:12:31 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(int argc, t_stack **stack_a, t_stack **stack_b)
{
	if (argc == 3)
		ft_two_args(stack_a);
	else if (argc == 4)
		ft_three_args(stack_a);
	else if (argc == 5)
		ft_four_args(stack_a, stack_b);
	else if (argc == 6)
		ft_five_args(stack_a, stack_b);
	else
		ft_radixsort(stack_a, stack_b);
}

int	ft_sort_index(t_stack **head)
{
	t_stack	*ptr;
	t_stack	*compare;
	int		dup_check;

	ptr = *head;
	compare = ptr->next;
	dup_check = 1;
	while (ptr)
	{
		while (compare)
		{
			if (ptr->value > compare->value)
				ptr->index++;
			if (compare && ptr->value == compare->value)
				dup_check++;
			if (dup_check > 1)
				return (1);
			compare = compare->next;
		}
		dup_check = 0;
		ptr = ptr->next;
		compare = *head;
	}
	return (0);
}

t_stack	*ft_make_stack_a(t_stack **stack_a, int argc, char **argv)
{
	int		i;
	t_stack	*new;

	i = 1;
	while (i < argc)
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		if (!new)
			exit(EXIT_FAILURE);
		new->index = 0;
		ft_lstadd_back(stack_a, new);
		i++;
	}
	if (ft_sort_index(stack_a))
		return (write(1, "Error\n", 6), NULL);
	return (*stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = ft_make_stack_a(&stack_a, argc, argv);
	if (!stack_a)
		return (0);
	if (is_sorted(&stack_a))
		return (0);
	push_swap(argc, &stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
