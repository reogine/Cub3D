/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:37:11 by aomman            #+#    #+#             */
/*   Updated: 2023/02/24 14:37:14 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

char	*skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 32)
			i++;
		else
			break ;
	}
	str = ft_substr(str, i, ft_strlen(str));
	return (str);
}

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	unsigned char	*_s1;
// 	unsigned char	*_s2;
// 	size_t			i;

// 	_s1 = (unsigned char *) s1;
// 	_s2 = (unsigned char *) s2;
// 	i = 0;
// 	while (i < n)
// 	{
// 		if (!(_s1[i] == _s2[i] && _s1[i] != '\0' && _s2[i] != '\0'))
// 		{
// 			return (_s1[i] - _s2[i]);
// 		}
// 		i++;
// 	}
// 	return (0);
// }
