/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_steps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:15:58 by botilia           #+#    #+#             */
/*   Updated: 2022/02/13 10:52:38 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rb_ra_rr(int rev_b, int rev_a)
{
	int	min;

	min = 0;
	if (rev_b >= rev_a)
		min = rev_b;
	else if (rev_b < rev_a)
		min = rev_a;
	return (min);
}

int	rrb_rra_rrr(int rr_b, int rr_a)
{
	int	min;

	min = 0;
	if (rr_b >= rr_a)
		min = rr_b;
	else if (rr_b < rr_a)
		min = rr_a;
	return (min);
}

int	ra_rrb(int rev_a, int rr_b)
{
	int	min;

	min = 0;
	min = rev_a + rr_b;
	return (min);
}

int	rra_rb(int rev_b, int rr_a)
{
	int	min;

	min = 0;
	min = rev_b + rr_a;
	return (min);
}

void	steps(t_list **s_b)
{
	t_list	*tmp;

	tmp = (*s_b);
	while (tmp)
	{
		tmp->ra_rr = rb_ra_rr(tmp->score_rev_b, tmp->score_rev_a);
		tmp->rb_rr = rb_ra_rr(tmp->score_rev_b, tmp->score_rev_a);
		tmp->rra_rrr = rrb_rra_rrr(tmp->score_rr_b, tmp->score_rr_a);
		tmp->rrb_rrr = rrb_rra_rrr(tmp->score_rr_b, tmp->score_rr_a);
		tmp->ra_rrb = ra_rrb(tmp->score_rev_a, tmp->score_rr_b);
		tmp->rra_rb = rra_rb(tmp->score_rev_b, tmp->score_rr_a);
		tmp = tmp->next;
	}
}
