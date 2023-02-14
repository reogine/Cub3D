/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:51:53 by aomman            #+#    #+#             */
/*   Updated: 2023/02/05 18:51:54 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	ft_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (fd, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*_s1;
	unsigned char	*_s2;
	size_t			i;

	_s1 = (unsigned char *) s1;
	_s2 = (unsigned char *) s2;
	i = 0;
	while (_s1[i])
	{
		if (!(_s1[i] == _s2[i] && _s1[i] != '\0' && _s2[i] != '\0'))
			return (_s1[i] - _s2[i]);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*string;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		string = malloc(sizeof(char));
	else if (len > ft_strlen(s))
		string = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		string = malloc(sizeof (char) * (len + 1));
	if (!string)
		return (NULL);
	while (s[i] && i < len && i + start < ft_strlen(s))
	{
		string[i] = s[start + i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			++j;
		}
		++i;
	}
	return (NULL);
}
