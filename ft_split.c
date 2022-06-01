/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:29:14 by botilia           #+#    #+#             */
/*   Updated: 2022/02/12 18:16:01 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_numstr(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j++;
		i++;
		if (s[i] == c && s[i - 1] == c)
			j--;
	}
	if (s[0] == c && s[i - 1] == c)
		return (j - 1);
	else if (s[0] != c && s[i - 1] != c)
		return (j + 1);
	else
		return (j);
}

char	*ft_cpy(char *s1, char *s2, int size)
{
	int	i;

	i = 0;
	while (s2[i] != 0 && i < size)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}

char	**ft_free(char **mass)
{
	int	sizemass;

	sizemass = 0;
	while (mass[sizemass])
	{
		free(mass[sizemass]);
		sizemass++;
	}
	free(mass);
	return (NULL);
}

char	**ft_podstr(char *str, char **mass, char c)
{
	int		x;
	int		y;
	char	*z;

	x = 0;
	while (*str)
	{
		y = 0;
		while (*str && *str == c)
			str++;
		while (*(str + y) && *(str + y) != c)
			y++;
		if (*str && *str != c)
		{
			z = (char *)malloc(sizeof(char) * (y + 1));
			if (!z)
				return (ft_free(mass));
			ft_cpy(z, str, y);
			mass[x++] = z;
			while (*str && *str != c)
				str++;
		}
	}
	mass[x] = NULL;
	return (mass);
}

char	**ft_split(char const *s, char c)
{
	char	**masstr;
	int		n;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	n = ft_numstr((char *)s, c);
	masstr = (char **)malloc(sizeof(char *) * (n + 1));
	if (!masstr)
		return (NULL);
	while (i < (n + 1))
	{
		masstr[i] = NULL;
		i++;
	}
	masstr = ft_podstr((char *)s, masstr, c);
	return (masstr);
}
