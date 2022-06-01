/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:39:37 by botilia           #+#    #+#             */
/*   Updated: 2022/06/01 18:25:30 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		k;
	int		j;
	int		r;
	int		i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	k = 0;
	j = 0;
	r = ft_strlen(s2);
	i = ft_strlen(s1);
	str = (char *)malloc((i + r + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[k] && k < i)
	{
		str[k] = s1[k];
		k++;
	}
	while (s2[j] && k < (i + r))
		str[k++] = s2[j++];
	str[k] = '\0';
	return (str);
}

int	find_argc(char **argv)
{
	int	j;

	j = 0;
	while (argv[j])
		j++;
	return (j);
}

void	clearing(t_list *stack_a, t_list *stack_b)
{
	clear_stack(&stack_a);
	if (stack_b)
		clear_stack(&stack_b);
}

void	sorting(t_list **stack_a, t_list **stack_b, int argc, int *mass)
{
	if (argc == 3)
		sort_min(stack_a, 'a');
	else if (argc == 4)
		sort_three(stack_a);
	else if (argc > 4 && argc < 7)
		sort_five(stack_a, stack_b, argc, mass);
	else
		sort(stack_a, stack_b, (argc - 1), mass);
	check(*stack_a);
	free(mass);
	clearing(*stack_a, *stack_b);
}
