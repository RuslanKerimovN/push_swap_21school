/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:36:16 by botilia           #+#    #+#             */
/*   Updated: 2022/02/12 20:14:24 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_new(int par)
{
	t_list	*newlst;

	newlst = malloc(sizeof(t_list));
	if (!newlst)
		return (NULL);
	newlst->par = par;
	newlst->score_rev_a = 0;
	newlst->score_rr_a = 0;
	newlst->score_rev_b = 0;
	newlst->score_rr_b = 0;
	newlst->rb_rr = 0;
	newlst->ra_rr = 0;
	newlst->rrb_rrr = 0;
	newlst->rra_rrr = 0;
	newlst->ra_rrb = 0;
	newlst->rra_rb = 0;
	newlst->next = NULL;
	newlst->prev = NULL;
	return (newlst);
}

void	ft_lst_add_front(t_list *lst, int par)
{
	t_list	*add_front;

	add_front = ft_lst_new(par);
	while (lst->next)
		lst = lst->next;
	lst->next = add_front;
	add_front->prev = lst;
}

void	ft_lst_add_back(t_list **lst, int par)
{
	t_list	*add_back;

	add_back = ft_lst_new(par);
	add_back->next = (*lst);
	(*lst)->prev = add_back;
	(*lst) = (*lst)->prev;
}

int	ft_atoi(const char *str)
{
	int		i;
	int		j;
	long	k;

	i = 0;
	j = 1;
	k = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		j = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k *= 10;
		k += ((long)str[i] - '0');
		i++;
	}
	k = k * j;
	if (k < -2147483648 || k > 2147483647)
		error(1);
	return (k);
}

t_list	*make_stack_a(t_list *stack_a, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[j])
	{
		if (i == 0)
			stack_a = ft_lst_new(ft_atoi(argv[j]));
		else
			ft_lst_add_front(stack_a, ft_atoi(argv[j]));
		i++;
		j++;
	}
	return (stack_a);
}
