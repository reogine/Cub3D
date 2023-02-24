/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:15:41 by aomman            #+#    #+#             */
/*   Updated: 2023/02/06 20:15:53 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 32)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0' && c != str[i])
		i++;
	if (str[i] == c)
		return (str + i);
	return (0);
}

static int	check(int sin)
{
	if (sin == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t				k;
	size_t				i;
	int					sin;
	unsigned long long	n;

	i = 0;
	n = 0;
	sin = 1;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-')
	{
		sin = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	k = i;
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i++] - 48);
	k = i - k;
	if (k > 19 || n > 9223372036854775807)
		return (check(sin));
	n = n * sin;
	return ((int)n);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*_s1;
	unsigned char	*_s2;
	size_t			i;

	_s1 = (unsigned char *) s1;
	_s2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (!(_s1[i] == _s2[i] && _s1[i] != '\0' && _s2[i] != '\0'))
		{
			return (_s1[i] - _s2[i]);
		}
		i++;
	}
	return (0);
}
