/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_spell_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:03:02 by jrossign          #+#    #+#             */
/*   Updated: 2023/02/02 11:46:47 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_anim_coor(t_data *data)
{
	data->anim->spell_anim[data->anim->frame]->instances->x = 730;
	if (data->anim->frame < 7)
		data->anim->spell_anim[data->anim->frame]->instances->y = 674;
	else
		data->anim->spell_anim[data->anim->frame]->instances->y = 580;
}

void	animation_spell(t_data *data)
{
	if (data->anim->frame == 12)
	{
		data->anim->spell_anim[11]->instances->enabled = false;
		data->anim->frame = 0;
		data->anim->spell = 0;
	}
	if (data->anim->spell == 1)
	{
		if (data->anim->frame > 0)
			data->anim->spell_anim
			[data->anim->frame - 1]->instances->enabled = false;
		set_anim_coor(data);
		data->anim->spell_anim[data->anim->frame]->instances->enabled = true;
		usleep(90000);
		data->anim->frame++;
	}
}

void	set_spell_asset(t_data *data)
{
	int		i;
	t_anim	*anim;

	i = 0;
	anim = ft_calloc(1, sizeof(t_anim));
	while (i < 12)
	{
		create_spell_img(data, anim, i);
		i++;
	}
	anim->frame = 0;
	anim->spell = 0;
	data->anim = anim;
}

void	create_spell_img(t_data *data, t_anim *anim, int i)
{
	char	*asset;
	char	*asset_ext;
	xpm_t	*animation;

	asset = ft_strjoinfree(ft_strdup("asset/animation_attack/spec"),
			ft_itoa(i));
	asset_ext = ft_strjoin(asset, EXTENSION_TEXTURE);
	animation = mlx_load_xpm42(asset_ext);
	anim->spell_anim[i] = mlx_texture_to_image(data->ray->mlx,
			&animation->texture);
	mlx_image_to_window(data->ray->mlx, anim->spell_anim[i], 0, 0);
	mlx_delete_xpm42(animation);
	anim->spell_anim[i]->instances->enabled = false;
	free(asset);
	free(asset_ext);
}
