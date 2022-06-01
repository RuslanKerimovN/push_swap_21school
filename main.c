/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:06:32 by botilia           #+#    #+#             */
/*   Updated: 2022/06/01 19:09:50 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* функция добавлена для выведения отсортированного списка,
	сама функция лежит в файле tools_2.c в функции sorting */
//////////////////////////////////////////////////////////////
void	check(t_list *stack_a)
{
	t_list	*p;
	
	p = (stack_a);
	while (p)
	{
		printf("%d ", p->par);
		p = p->next;
	}
	printf("\n");
}
/////////////////////////////////////////////////////////////

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*mass;
	char	*s;
	int		i;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		s = ft_strjoin("push_swap ", argv[1]);
		argv = ft_split(s, ' ');
		free(s);
		argc = find_argc(argv);
		i = 1;
	}
	check_sym(argv, argc);
	stack_a = make_stack_a(stack_a, argv);
	mass = sec_mass(argv, (argc - 1));
	mass = check_sorted(mass, argc - 1);
	if (i == 1)
		argv = ft_free(argv);
	sorting(&stack_a, &stack_b, argc, mass);
	return (0);
}
