/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:32:12 by rvandepu          #+#    #+#             */
/*   Updated: 2023/07/17 18:23:34 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = ft_strlen(src);
	dest = malloc(i + 1);
	if (dest == NULL)
		return (dest);
	dest[i] = '\0';
	while (i--)
		dest[i] = src[i];
	return (dest);
}

void	*ft_free(struct s_stock_str *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(s[i++].copy);
	free(s);
	return (NULL);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*s;
	int					i;

	s = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (s == NULL)
		return (s);
	i = 0;
	while (i < ac)
	{
		s[i].size = ft_strlen(av[i]);
		s[i].str = av[i];
		s[i].copy = ft_strdup(av[i]);
		if (s[i].copy == NULL)
			return (ft_free(s, i));
		i++;
	}
	s[i].str = 0;
	return (s);
}
