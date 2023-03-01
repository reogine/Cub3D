/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:40:11 by midfath           #+#    #+#             */
/*   Updated: 2023/03/01 17:20:08 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>

void  ray_hit(t_window  *win, double rot_ang, int indx)
{
  t_ray      *ray;
  double      dis_ver;
  double      dis_hor;
  t_dou_xy    hor_hit;
  t_dou_xy    ver_hit;

  ray = &win->rays[indx];
  ray->angle = rot_ang;
  ray->face_up = ((ray->angle > P) && (ray->angle < 2 * P));
  ray->face_left = ((ray->angle > P / 2) && (ray->angle < 3 * P / 2));
  hor_hit = find_hit_point(win, ray, 1); 
  ver_hit = find_hit_point(win, ray, 0);
  dis_hor = fabs((hor_hit.x - win->ply.x) / cos(rot_ang));
  dis_ver = fabs((ver_hit.y - win->ply.y) / sin(rot_ang));
  if (dis_hor < dis_ver)
  {
    ray->hit_x = hor_hit.x;
    ray->hit_y = hor_hit.y;
    ray->distance = dis_hor;
    ray->is_horizontal = 1;
  }
  else 
  {
    ray->hit_x = ver_hit.x;
    ray->hit_y = ver_hit.y;
    ray->distance = dis_ver;
    ray->is_horizontal = 0;
  }
}

void  rays_calc(t_window *win)
{
  double ang;
  int    r;

  ang = win->ply.rot_ang - (FOV * ( P / 180)) / 2;
  r = 0;
  while (r < WIN_W)
  {
    if (ang < 0)
      ang += 2 * P;
    else if (ang >= 2 * P)
      ang -= 2 * P;
    // printf("%f degree\n",  ang);
    ray_hit(win, ang, r);
    ang += (FOV * (P / 180)) / WIN_W;
    r++;
  }
}

void  rays_display(t_window *win)
{
  t_xy  str;
  t_xy  end;
  int   i;

  i = 0;
  while (i < WIN_W)
  {
    str.x = win->ply.x * SCALE;
    str.y = win->ply.y * SCALE;
    if (win->rays[i].distance > 160)
    {
      end.x = (win->ply.x + cos(win->rays[i].angle) * 160) * SCALE;
      end.y = (win->ply.y + sin(win->rays[i].angle) * 160) * SCALE;
    }
    else
    {
      end.x = win->rays[i].hit_x * SCALE;  
      end.y = win->rays[i].hit_y * SCALE;
    }
  // printf("lol %d\n", str.x);
    ft_pxl_line(win, str, end, 0xf5f5dc); i++;
  }
}
