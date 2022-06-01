/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_final.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:08:50 by botilia           #+#    #+#             */
/*   Updated: 2022/02/13 15:14:33 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_min(t_list **s_a, char flag)
{
	if ((*s_a)->par > (*s_a)->next->par && flag == 'a')
		go_swap(s_a, 0, 'a');
	else if ((*s_a)->par > (*s_a)->next->par && flag == 'b')
		go_swap(0, s_a, 'b');
}

void	sort_three(t_list **s_a)
{
	t_list	*tmp;

	tmp = (*s_a)->next;
	if ((*s_a)->par > tmp->par && (*s_a)->par < tmp->next->par)
		go_swap(s_a, 0, 'a');
	else if ((*s_a)->par > tmp->next->par
		&& tmp->next->par > tmp->par)
		go_rev(s_a, 0, 'a');
	else if ((*s_a)->par < tmp->next->par
		&& tmp->par > tmp->next->par)
	{
		go_swap(s_a, 0, 'a');
		go_rev(s_a, 0, 'a');
	}
	else if ((*s_a)->par > tmp->next->par
		&& tmp->par > (*s_a)->par)
		go_rr(s_a, 0, 'a');
	else if ((*s_a)->par > tmp->par
		&& tmp->par > tmp->next->par)
	{
		go_swap(s_a, 0, 'a');
		go_rr(s_a, 0, 'a');
	}
}

void	sort_five(t_list **s_a, t_list **s_b, int count, int *mass)
{
	int	j;
	int	max;

	j = count - 1;
	max = mass[count - 2];
	while (count > (j - 1))
	{
		if ((*s_a)->par == mass[0] || (*s_a)->par == max)
		{
			go_push(s_a, s_b, 'a');
			count--;
		}
		else
			go_rev(s_a, 0, 'a');
	}
	sort_min(s_b, 'b');
	if (j == 4)
		sort_min(s_a, 'a');
	else
		sort_three(s_a);
	go_push(s_a, s_b, 'b');
	go_push(s_a, s_b, 'b');
	go_rev(s_a, 0, 'a');
}

void	big_sorting(t_list **s_a, t_list **s_b)
{
	int	min;

	find_score(s_a, s_b);
	steps(s_b);
	min = 2147483647;
	min = find_min(s_b, min);
	pushing(s_a, s_b, min);
}

void	sort(t_list **s_a, t_list **s_b, int count, int *mass)
{
	int		max;
	int		med;
	int		len;

	max = mass[count - 1];
	med = mass[count / 2];
	while (count > 3)
	{
		if ((*s_a)->par == mass[0] || (*s_a)->par == max || (*s_a)->par == med)
			go_rev(s_a, 0, 'a');
		else
		{
			go_push(s_a, s_b, 'a');
			count--;
		}
	}
	sort_three(s_a);
	len = find_len_list(s_b);
	while (len > 0)
	{
		big_sorting(s_a, s_b);
		len--;
	}
	final_step(s_a, max);
}
