/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:38:44 by botilia           #+#    #+#             */
/*   Updated: 2022/02/12 19:36:15 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	check_sym(char **argv, int argc)
{
	int	i;
	int	j;
	int	z;

	i = 1;
	while (i < argc)
	{
		j = 0;
		z = ft_strlen(argv[i]);
		if (argv[i][0] == '-')
			j++;
		while (j < z)
		{
			if (argv[i][j] <= 47 || argv[i][j] >= 58)
				error(2);
			j++;
		}
		i++;
	}
}

void	check_repeat(int *mass, int argc)
{
	int	*ch_mass;
	int	m_first;
	int	second;
	int	i;

	m_first = 0;
	i = 0;
	ch_mass = ft_strdup(mass, argc);
	while (m_first < argc)
	{
		second = 0;
		while (second < argc)
		{
			if (mass[m_first] == ch_mass[second])
				i++;
			second++;
		}
		m_first++;
	}
	if (i > argc)
		error(3);
	else
		free(ch_mass);
}

int	*check_sorted(int *mass, int argc)
{
	int	*ch_mass;
	int	i;

	i = 0;
	check_repeat(mass, argc);
	ch_mass = ft_strdup(mass, argc);
	sort_bubble(mass, (argc));
	i = 0;
	while (i < argc)
	{
		if (mass[i] == ch_mass[i])
			i++;
		else
			break ;
	}
	if (i == argc)
		exit(0);
	else
		free(ch_mass);
	return (mass);
}

void	error(int i)
{
	if (i == 1)
		write(1, "Error of int\n", 13);
	if (i == 2)
		write(1, "Error of symbol\n", 16);
	if (i == 3)
		write(1, "Error of repeat\n", 16);
	exit(0);
}
