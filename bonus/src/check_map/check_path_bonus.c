/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:17:51 by jrossign          #+#    #+#             */
/*   Updated: 2023/01/19 08:28:07 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	check_extension(char *path, char *extension)
{
	int		length;
	char	*path_extension;

	length = ft_strlen(path);
	path_extension = ft_substr(path, length - ft_strlen(extension), length);
	if (ft_strncmp(extension, path_extension, ft_strlen(extension)) != 0)
	{
		free(path_extension);
		return (-1);
	}
	free(path_extension);
	return (0);
}

int	check_map_exist(char *map)
{
	int	fd;

	fd = open(map, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		error_and_exit(ERR_MAP_DIR);
	}
	fd = open(map, O_RDONLY);
	if (fd == -1)
		error_and_exit(ERR_MAP_NOT_EXIST);
	return (fd);
}
