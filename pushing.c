/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:51:09 by botilia           #+#    #+#             */
/*   Updated: 2022/02/11 19:51:35 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb_ra_rr_function(t_list **s_a, t_list **s_b, t_list **s_bp)
{
	int	min;
	int	rr;
	int	r_step;

	if ((*s_b)->score_rev_b >= (*s_b)->score_rev_a)
	{
		min = (*s_b)->score_rev_b;
		rr = (*s_b)->score_rev_a;
		r_step = (min - rr);
		while (rr--)
			go_rev(s_a, s_bp, 'd');
		while (r_step--)
			go_rev(0, s_bp, 'b');
	}
	else if ((*s_b)->score_rev_b < (*s_b)->score_rev_a)
	{
		min = (*s_b)->score_rev_a;
		rr = (*s_b)->score_rev_b;
		r_step = (min - rr);
		while (rr--)
			go_rev(s_a, s_bp, 'd');
		while (r_step--)
			go_rev(s_a, 0, 'a');
	}
	go_push(s_a, s_bp, 'b');
}

void	rrb_rra_rrr_function(t_list **s_a, t_list **s_b, t_list **s_bp)
{
	int	min;
	int	rrr;
	int	rr_step;

	if ((*s_b)->score_rr_b >= (*s_b)->score_rr_a)
	{
		min = (*s_b)->score_rr_b;
		rrr = (*s_b)->score_rr_a;
		rr_step = (min - rrr);
		while (rrr--)
			go_rr(s_a, s_bp, 'd');
		while (rr_step--)
			go_rr(0, s_bp, 'b');
	}
	else if ((*s_b)->score_rr_b < (*s_b)->score_rr_a)
	{
		min = (*s_b)->score_rr_a;
		rrr = (*s_b)->score_rr_b;
		rr_step = (min - rrr);
		while (rrr--)
			go_rr(s_a, s_bp, 'd');
		while (rr_step--)
			go_rr(s_a, 0, 'a');
	}
	go_push(s_a, s_bp, 'b');
}

void	ra_rrb_function(t_list **s_a, t_list **s_b, t_list **s_bp)
{
	int	i;
	int	j;

	i = (*s_b)->score_rev_a;
	j = (*s_b)->score_rr_b;
	while (i--)
		go_rev(s_a, 0, 'a');
	while (j--)
		go_rr(0, s_bp, 'b');
	go_push(s_a, s_bp, 'b');
}

void	rra_rb_function(t_list **s_a, t_list **s_b, t_list **s_bp)
{
	int	i;
	int	j;

	i = (*s_b)->score_rev_b;
	j = (*s_b)->score_rr_a;
	while (i--)
		go_rev(0, s_bp, 'b');
	while (j--)
		go_rr(s_a, 0, 'a');
	go_push(s_a, s_bp, 'b');
}

void	pushing(t_list **s_a, t_list **s_b, int min)
{
	t_list	*tmp;

	tmp = (*s_b);
	while (tmp)
	{
		if (tmp->rb_rr == min || tmp->ra_rr == min || tmp->rrb_rrr == min
			|| tmp->rra_rrr == min || tmp->ra_rrb == min || tmp->rra_rb == min)
		{
			if (tmp->rb_rr == min || tmp->ra_rr == min)
				rb_ra_rr_function(s_a, &tmp, s_b);
			else if (tmp->rrb_rrr == min || tmp->rra_rrr == min)
				rrb_rra_rrr_function(s_a, &tmp, s_b);
			else if (tmp->ra_rrb == min)
				ra_rrb_function(s_a, &tmp, s_b);
			else if (tmp->rra_rb == min)
				rra_rb_function(s_a, &tmp, s_b);
			break ;
		}
		else
			tmp = tmp->next;
	}
}
