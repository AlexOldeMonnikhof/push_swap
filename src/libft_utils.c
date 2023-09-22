/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:08:36 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/22 16:12:28 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit (0);
}

long long	ft_atoi2(const char *str, int i, long long pol)
{
	long long	output;

	output = 0;
	if (!ft_isdigit(str[i]))
		ft_error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		output = output * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != 0)
		ft_error();
	output *= pol;
	if (output < INT_MIN || output > INT_MAX)
		ft_error();
	return (output);
}

long long	ft_atoi(const char *str)
{
	int			i;
	long long	pol;

	i = 0;
	pol = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			pol = -pol;
		i++;
	}
	return (ft_atoi2(str, i, pol));
}

int	ft_find_minormax(t_stack **stack_a, char c)
{
	t_stack	*head;
	int		i;

	head = *stack_a;
	i = head->index;
	while (head)
	{
		if (c == 'm')
		{
			if (head->index < i)
				i = head->index;
		}
		else
		{
			if (head->index > i)
				i = head->index;
		}
		head = head->next;
	}
	return (i);
}
