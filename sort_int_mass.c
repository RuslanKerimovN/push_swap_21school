/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_mass.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:54:38 by botilia           #+#    #+#             */
/*   Updated: 2022/02/12 18:38:38 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_bubble(int *mass, int j)
{
	int	i;
	int	k;
	int	tmp;

	i = 0;
	while (i < (j - 1))
	{
		k = 0;
		while (k < (j - i - 1))
		{
			if (mass[k] > mass[k + 1])
			{
				tmp = mass[k];
				mass[k] = mass[k + 1];
				mass[k + 1] = tmp;
			}
			k++;
		}
		i++;
	}
}

int	*ft_strdup(int *s1, int argc)
{
	int	*s2;
	int	j;

	j = 0;
	s2 = malloc(argc * sizeof(int));
	if (!s2)
		return (NULL);
	while (argc > 0)
	{
		s2[j] = s1[j];
		argc--;
		j++;
	}
	return (s2);
}

int	*sec_mass(char **argv, int argc)
{
	int	*mass;
	int	i;
	int	j;

	j = 0;
	mass = malloc(sizeof(int) * (argc));
	if (!mass)
		return (NULL);
	i = 1;
	while (argv[i])
	{
		mass[j] = ft_atoi(argv[i]);
		j++;
		i++;
	}
	return (mass);
}
