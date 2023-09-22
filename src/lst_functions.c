/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:19:26 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/22 16:12:30 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstnew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		exit(EXIT_FAILURE);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_lstsecondlast(t_stack *lst)
{
	int	size;

	if (!lst)
		return (NULL);
	size = ft_lstsize(lst);
	while (size > 2)
	{
		lst = lst->next;
		size--;
	}
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
