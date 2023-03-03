/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:25:20 by aomman            #+#    #+#             */
/*   Updated: 2023/03/03 19:32:26 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"cub3d.h"
#include<window.h>

int	wall_text(t_var *var)
{
	var->fd_so = open(var->path_so, O_RDWR, 666);
	var->fd_no = open(var->path_no, O_RDWR, 666);
	var->fd_ea = open(var->path_ea, O_RDWR, 666);
	var->fd_we = open(var->path_we, O_RDWR, 666);
	if (!var->fd_so || !var->fd_no || !var->fd_ea || !var->fd_we)
	{
		ft_putstr_fd("Error\ntexturs file descriptor error\n", 2);
		return (1);
	}
	printf("%d\n", var->fd_so);
	return (0);
}

