/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light_and_camera.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:03:12 by jyap              #+#    #+#             */
/*   Updated: 2024/09/14 20:38:25 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	count_arr_elements(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	parse_amb(char *line, t_mlxs *mlxs)
{
	char		**split;
	t_amb		amb;

	if (mlxs->sc->amb.i != 0)
	{
		free(line);
		free_scene(mlxs->sc);
		print_err_exit("Maximum of 1 Ambient Lighting accepted.\n", mlxs, 1);
	}
	split = ft_split(line, ' ');
	if (split == NULL)
	{
		free(line);
		free_scene(mlxs->sc);
		print_err_exit("Malloc ft_split failed.\n", mlxs, 1);
	}
	ft_bzero(&amb, sizeof(t_amb));
	amb.i = 1;
	if (count_arr_elements(split) != 3)
	{
		free(line);
		free_double_array(split);
		free_scene(mlxs->sc);
		print_err_exit("Wrong number of info for Ambient Lighting.\n", mlxs, 1);
	}
	amb.ratio = parse_ratio(split, 1, amb.ratio, mlxs);
	amb.color = parse_color(split, 2, amb.color, mlxs);
	mlxs->sc->amb = amb;
	free_double_array(split);
}

void	parse_light(char *line, t_mlxs *mlxs)
{
	t_light	light;
	char	**split;

	if (mlxs->sc->light.i != 0)
	{
		free(line);
		free_scene(mlxs->sc);
		print_err_exit("Maximum of 1 Light accepted.\n", mlxs, 1);
	}
	split = ft_split(line, ' ');
	if (split == NULL)
	{
		free(line);
		free_scene(mlxs->sc);
		print_err_exit("Malloc ft_split failed.\n", mlxs, 1);
	}
	ft_bzero(&light, sizeof(t_light));
	light.i = 1;
	if (count_arr_elements(split) != 3)
	{
		free(line);
		free_double_array(split);
		free_scene(mlxs->sc);
		print_err_exit("Wrong number of info for Light.\n", mlxs, 1);
	}
	light.pos = parse_coord(split, 1, light.pos, mlxs);
	light.ratio = parse_ratio(split, 2, light.ratio, mlxs);
	mlxs->sc->light = light;
	free_double_array(split);
}

void	parse_camera(char *line, t_mlxs *mlxs)
{
	t_camera	cam;
	char		**split;

	if (mlxs->sc->cam.i != 0)
	{
		free_scene(mlxs->sc);
		print_err_exit("Only 1 Camera accepted.\n", mlxs, 1);
	}
	split = ft_split(line, ' ');
	if (split == NULL)
	{
		free_scene(mlxs->sc);
		print_err_exit("Malloc ft_split failed.\n", mlxs, 1);
	}
	ft_bzero(&cam, sizeof(t_camera));
	cam.i = 1;
	if (count_arr_elements(split) != 4)
	{
		free_double_array(split);
		free_scene(mlxs->sc);
		print_err_exit("Wrong number of info for Camera.\n", mlxs, 1);
	}
	cam.pos = parse_coord(split, 1, cam.pos, mlxs);	
	cam.norm = parse_vector(split, 2, cam.norm, mlxs);
	cam.fov_deg = (unsigned char)parse_camera_fov(split, 3, cam.fov_deg, mlxs);
	mlxs->sc->cam = cam;
	free_double_array(split);
}