/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_go.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:09:33 by botilia           #+#    #+#             */
/*   Updated: 2022/02/11 19:31:25 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_swap(t_list **stack_a, t_list **stack_b, char flag)
{
	if (flag == 'a')
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
	else if (flag == 'b')
	{
		swap(stack_b);
		write(1, "sb\n", 3);
	}
	else if (flag == 'd')
	{
		swap(stack_a);
		swap(stack_b);
		write(1, "ss\n", 3);
	}
	else
		return ;
}

void	go_rev(t_list **stack_a, t_list **stack_b, char flag)
{
	if (flag == 'a')
	{
		rev(stack_a);
		write(1, "ra\n", 3);
	}
	else if (flag == 'b')
	{
		rev(stack_b);
		write(1, "rb\n", 3);
	}
	else if (flag == 'd')
	{
		rev(stack_a);
		rev(stack_b);
		write(1, "rr\n", 3);
	}
	else
		return ;
}

void	go_rr(t_list **stack_a, t_list **stack_b, char flag)
{
	if (flag == 'a')
	{
		rr(stack_a);
		write(1, "rra\n", 4);
	}
	else if (flag == 'b')
	{
		rr(stack_b);
		write(1, "rrb\n", 4);
	}
	else if (flag == 'd')
	{
		rr(stack_a);
		rr(stack_b);
		write(1, "rrr\n", 4);
	}
	else
		return ;
}

void	go_push(t_list **stack_a, t_list **stack_b, char flag)
{
	if (flag == 'a')
	{
		push(stack_a, stack_b);
		write(1, "pb\n", 3);
	}
	else if (flag == 'b')
	{
		push(stack_b, stack_a);
		write(1, "pa\n", 3);
	}
	else
		return ;
}
