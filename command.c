/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:25:32 by botilia           #+#    #+#             */
/*   Updated: 2022/02/12 20:14:24 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*lst2;

	tmp = (*stack_a)->next;
	lst2 = (*stack_a)->next;
	tmp->next = lst2->next;
	tmp->prev = (*stack_a)->prev;
	if (lst2->next)
		lst2->next->prev = (*stack_a);
	(*stack_a)->prev = lst2;
	(*stack_a)->next = tmp->next;
	lst2->next = (*stack_a);
	lst2->prev = tmp->prev;
	(*stack_a) = (*stack_a)->prev;
}

void	rev(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*lst;

	lst = (*stack_a)->next;
	tmp = *stack_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	lst->prev = (*stack_a)->prev;
	(*stack_a)->prev = tmp;
	(*stack_a)->next = tmp->next;
	tmp->next = (*stack_a);
	(*stack_a) = lst;
}

void	rr(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->prev->next = tmp->next;
	tmp->next = (*stack_a);
	tmp->prev = (*stack_a)->prev;
	(*stack_a)->prev = tmp;
	(*stack_a) = (*stack_a)->prev;
}

void	push(t_list **lst, t_list **tmp)
{
	t_list	*add_back;
	t_list	*p;

	add_back = ft_lst_new((*lst)->par);
	p = add_back;
	if (*tmp == NULL)
		(*tmp) = add_back;
	else
	{
		p->next = (*tmp);
		(*tmp)->prev = p;
		(*tmp) = (*tmp)->prev;
	}
	del_back(lst);
}

void	del_back(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp1 = (*lst);
	if (tmp1->next != NULL)
	{
		tmp = (*lst)->next;
		tmp->prev = (*lst)->prev;
		(*lst) = (*lst)->next;
		free(tmp1);
	}
}
