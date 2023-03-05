/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_lenght.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:00:44 by aomman            #+#    #+#             */
/*   Updated: 2023/03/05 17:00:46 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	line_lenght(char **str)
{
	int		len;
	char	*s1;
	char	*s2;

	s1 = remove_spaces_in_begin(str[1]);
	s2 = remove_spaces_in_end(s1);
	len = ft_strlen(s2);
	free(s1);
	free(s2);
	return (len);
}
