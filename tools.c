/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:11:58 by botilia           #+#    #+#             */
/*   Updated: 2022/02/12 20:14:24 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_len_list(t_list **s_a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = (*s_a);
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	find_min(t_list **s_b, int min)
{
	t_list	*tmp;

	tmp = (*s_b);
	while (tmp)
	{
		if (min > tmp->rb_rr)
			min = tmp->rb_rr;
		if (min > tmp->ra_rr)
			min = tmp->ra_rr;
		if (min > tmp->rrb_rrr)
			min = tmp->rrb_rrr;
		if (min > tmp->rra_rrr)
			min = tmp->rra_rrr;
		if (min > tmp->ra_rrb)
			min = tmp->ra_rrb;
		if (min > tmp->rra_rb)
			min = tmp->rra_rb;
		tmp = tmp->next;
	}
	return (min);
}

void	final_step(t_list **s_a, int max)
{
	t_list	*front;
	int		len_list;
	int		st_bef_max;
	int		i;

	len_list = find_len_list(s_a);
	front = (*s_a);
	st_bef_max = 1;
	while (front->par != max)
	{
		front = front->next;
		st_bef_max++;
	}
	i = len_list - st_bef_max;
	if (i < st_bef_max)
	{
		while (i--)
			go_rr(s_a, 0, 'a');
	}
	else
	{
		while (st_bef_max--)
			go_rev(s_a, 0, 'a');
	}
}

void	clear_stack(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*p;

	tmp = (*stack_a);
	while (tmp->next)
		tmp = tmp->next;
	while (tmp->prev)
	{
		p = tmp;
		tmp->prev->next = NULL;
		tmp = tmp->prev;
		free(p);
	}
	free(tmp);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
