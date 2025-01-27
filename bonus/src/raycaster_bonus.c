/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:22:38 by jrossign          #+#    #+#             */
/*   Updated: 2023/02/08 09:21:09 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	texture_picker(t_data *data, int i)
{
	if (data->ray->side == 0)
	{
		find_hit(data, data->tex->east_tex);
		draw_line(data, data->tex->east_tex, data->tex->east, i);
	}
	else if (data->ray->side == 1)
	{
		find_hit(data, data->tex->west_tex);
		draw_line(data, data->tex->west_tex, data->tex->west, i);
	}
	else if (data->ray->side == 2)
	{
		find_hit(data, data->tex->south_tex);
		draw_line(data, data->tex->south_tex, data->tex->south, i);
	}
	else
	{
		find_hit(data, data->tex->north_tex);
		draw_line(data, data->tex->north_tex, data->tex->north, i);
	}
}

void	raycaster(t_data *data)
{
	int		i;

	i = -1;
	clear_image(data);
	while (++i < WIDTH)
	{
		init_var(data, i);
		init_dist(data);
		dda(data);
		calc_line(data);
		texture_picker(data, i);
	}
	draw_map(data);
}

void	init_mlx(t_data *data)
{
	data->ray = ft_calloc(1, sizeof(t_ray));
	start_var(data);
	create_texture(data);
	data->tex->overlay = mlx_load_xpm42("./asset/weapon.xpm42");
	data->tex->overlay_img = mlx_texture_to_image(data->ray->mlx,
			&data->tex->overlay->texture);
	raycaster(data);
	mlx_image_to_window(data->ray->mlx, data->ray->img, 0, 0);
	mlx_image_to_window(data->ray->mlx, data->tex->overlay_img, 730, 674);
	mlx_image_to_window(data->ray->mlx, data->minimap, 0, 0);
	cursor(data);
	data->tex->overlay_img->instances->enabled = true;
	data->tex->player = data->tex->overlay_img;
	set_spell_asset(data);
	mlx_key_hook(data->ray->mlx, &hook, (void *) data);
	mlx_cursor_hook(data->ray->mlx, &mouse_move, (void *)data);
	mlx_loop_hook(data->ray->mlx, &loop_hook, data);
	mlx_loop(data->ray->mlx);
	mlx_delete_image(data->ray->mlx, data->ray->img);
	mlx_delete_image(data->ray->mlx, data->tex->overlay_img);
	mlx_delete_image(data->ray->mlx, data->minimap);
	mlx_delete_image(data->ray->mlx, data->cursor);
	mlx_terminate(data->ray->mlx);
}
