/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:05:30 by botilia           #+#    #+#             */
/*   Updated: 2022/02/13 13:18:15 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	score_b(t_list **s_b)
{
	t_list	*tmp;
	int		i;
	int		j;

	tmp = (*s_b);
	i = find_len_list(s_b);
	j = 0;
	if (!tmp->next)
	{
		tmp->score_rr_b = 0;
		tmp->score_rev_b = 0;
	}
	else
	{
		while (tmp)
		{
			tmp->score_rr_b = i - j;
			tmp->score_rev_b = j;
			tmp = tmp->next;
			j++;
		}
	}
}

void	score_a_piece(t_list **s_b, t_list *tmp_a)
{
	if (ft_lstlast(tmp_a)->par > (*s_b)->par && (*s_b)->par < tmp_a->par)
	{
		while (tmp_a->par < tmp_a->next->par)
		{
			(*s_b)->score_rev_a++;
			tmp_a = tmp_a->next;
		}
		(*s_b)->score_rev_a++;
		tmp_a = tmp_a->next;
	}
	if ((*s_b)->par > tmp_a->par)
	{
		while (tmp_a->par < (*s_b)->par)
		{
			(*s_b)->score_rev_a++;
			tmp_a = tmp_a->next;
		}
	}
}

void	score_a(t_list **s_a, t_list **s_b)
{
	t_list	*tmp_b;
	t_list	*tmp_a;

	tmp_a = *s_a;
	tmp_b = *s_b;
	while ((*s_b))
	{
		(*s_b)->score_rev_a = 0;
		(*s_b)->score_rr_a = 0;
		score_a_piece(s_b, tmp_a);
		(*s_b)->score_rr_a = find_len_list(s_a) - (*s_b)->score_rev_a;
		(*s_b) = (*s_b)->next;
		tmp_a = (*s_a);
	}
	(*s_b) = tmp_b;
}

void	find_score(t_list **s_a, t_list **s_b)
{
	score_b(s_b);
	score_a(s_a, s_b);
}
