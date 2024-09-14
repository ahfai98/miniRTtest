/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:40:26 by jyap              #+#    #+#             */
/*   Updated: 2024/09/14 20:06:24 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

float	parse_ratio(char **str, int i, float ratio, t_mlxs *mlxs)
{
	if (is_float(str[i]) == false)
	{
		free_double_array(str);
		free_scene(mlxs->sc);
		print_err_exit("Ratio info is not valid.\n", mlxs, 1);
	}
	ratio = str_to_float(str[i]);
	if (ratio >= 0 && ratio <= 1)
		return (ratio);
	else
	{
		free_double_array(str);
		free_scene(mlxs->sc);
		print_err_exit("Ratio not within range.\n", mlxs, 1);
		return (0);
	}
}

t_color	parse_color(char **str, int i, t_color colors, t_mlxs *mlxs)
{
	char	**split;
	int		ret;

	ret = 0;
	split = ft_split(str[i], ',');
	if (split == NULL)
	{
		free_double_array(str);
		free_scene(mlxs->sc);
		print_err_exit("Malloc for ft_split failed.\n", mlxs, 1);
	}
	if (count_arr_elements(split) != 3)
	{
		free_double_array(str);
		free_double_array(split);
		free_scene(mlxs->sc);
		print_err_exit("Invalid info for colors.\n", mlxs, 1);
	}
	ret = is_color(split[0]) + is_color(split[1]) + is_color(split[2]);
	if (ret != 3)
	{
		free_double_array(str);
		free_double_array(split);
		free_scene(mlxs->sc);
		print_err_exit("Invalid info for colors.\n", mlxs, 1);
	}
	colors.r = ft_atoi(split[0]);		
	colors.g = ft_atoi(split[1]);
	colors.b = ft_atoi(split[2]);
	free_double_array(split);
	return (colors);
}

t_vect	parse_coord(char **str, int i, t_vect points, t_mlxs *mlxs)
{
	char	**split;
	int		ret;

	ret = 0;
	split = ft_split(str[i], ',');
	if (split == NULL)
	{
		free_double_array(str);
		free_scene(mlxs->sc);
		print_err_exit("Malloc for ft_split failed.\n", mlxs, 1);
	}
	if (count_arr_elements(split) != 3)
	{
		free_double_array(split);
		free_double_array(str);
		free_scene(mlxs->sc);
		print_err_exit("Invalid info for coordinates.\n", mlxs, 1);
	}
	ret = is_float(split[0]) + is_float(split[1]) + is_float(split[2]);
	if (ret != 3)
	{
		free_double_array(str);
		free_double_array(split);
		free_scene(mlxs->sc);
		print_err_exit("Invalid info for coordinates.\n", mlxs, 1);
	}
	points.x = str_to_float(split[0]);
	points.y = str_to_float(split[1]);
	points.z = str_to_float(split[2]);
	free_double_array(split);
	return (points);
}

t_vect	parse_vector(char **str, int i, t_vect points, t_mlxs *mlxs)
{
	char	**split;
	int		ret;
	float	tmp;

	ret = 0;
	split = ft_split(str[i], ',');
	if (split == NULL)
	{
		free_double_array(str);
		free_scene(mlxs->sc);
		print_err_exit("Malloc for ft_split failed.\n", mlxs, 1);
	}
	if (count_arr_elements(split) != 3)
	{
		free_double_array(split);
		free_double_array(str);
		free_scene(mlxs->sc);
		print_err_exit("Invalid info for normalized vector.\n", mlxs, 1);
	}
	ret = is_float(split[0]) + is_float(split[1]) + is_float(split[2]);
	if (ret == 3)
	{
		points.x = str_to_float(split[0]);
		points.y = str_to_float(split[1]);
		points.z = str_to_float(split[2]);
		ret += is_range(points.x) + is_range(points.y) + is_range(points.x);
	}
	free_double_array(split);
	if (ret != 6)
	{
		free_double_array(str);
		free_scene(mlxs->sc);
		print_err_exit("Invalid info for normalized vector.\n", mlxs, 1);
	}
	return (points);
}

int	parse_camera_fov(char **str, int i, int fov, t_mlxs *mlxs)
{
	char	**split;

	split = ft_split(str[i], ',');
	if (split == NULL)
	{
		free_double_array(str);
		free_scene(mlxs->sc);
		print_err_exit("Malloc for ft_split failed.\n", mlxs, 1);
	}
	if (count_arr_elements(split) != 1)
	{
		free_double_array(split);
		free_double_array(str);
		free_scene(mlxs->sc);
		print_err_exit("Invalid info for camera FOV.\n", mlxs, 1);
	}
	free_double_array(split);
	if (is_float(str[i]) == true)
	{
		free_double_array(str);
		free_scene(mlxs->sc);
		print_err_exit("Camera FOV cannot be a float.\n", mlxs, 1);
	}
	fov = ft_atoi(str[i]);
	if (!(fov >= 0 && fov <= 180))
	{
		free_double_array(str);
		free_scene(mlxs->sc);
		print_err_exit("Camera FOV must be between 0 and 180.\n", mlxs, 1);
	}
	return (fov);
}

float	parse_dia_height(char **str, int i, float element, t_mlxs *mlxs)
{
	char	**split;

	split = ft_split(str[i], ',');
	if (split == NULL)
	{
		free_double_array(str);
		free_scene(mlxs->sc);
		print_err_exit("Malloc for ft_split failed.\n", mlxs, 1);
	}
	if (count_arr_elements(split) != 1)
	{
		free_double_array(split);
		free_double_array(str);
		free_scene(mlxs->sc);
		print_err_exit("Invalid info for Diameter/Height.\n", mlxs, 1);
	}
	free_double_array(split);
	if (is_float(str[i]) == false)
	{
		free_double_array(str);
		free_scene(mlxs->sc);
		print_err_exit("Diameter/Height must be a float.\n", mlxs, 1);
	}
	element = str_to_float(str[i]);
	if (element <= 0)
	{
		free_double_array(str);
		free_scene(mlxs->sc);
		print_err_exit("Diameter/Height must be larger than 0.\n", mlxs, 1);
	}
	return (element);
}
