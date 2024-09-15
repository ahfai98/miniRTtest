/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:09:38 by jyap              #+#    #+#             */
/*   Updated: 2024/09/15 13:54:59 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include "mlx_structs.h"
#include "camera.h"
#include "color.h"
#include "cylinder.h"
#include "sphere.h"
#include "plane.h"
#include "light.h"
#include "ray.h"
#include "scene.h"
#include "vect.h"
#include "obj.h"
#include "intersect.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>

void	print_err_exit(char *msg, t_mlxs **mlxs, char *ptr);
void	print_err(char *msg, void *ptr);

void	parse(char *name, t_mlxs *mlxs);

void 	free_scene(t_scene *sc);
void	free_str_arr(char **arr);

void	parse_amb(char *line, t_mlxs *mlxs);
void	parse_light(char *line, t_mlxs *mlxs);
void	parse_camera(char *line, t_mlxs *mlxs);

int		count_arr_elements(char **arr);

float	parse_ratio(char **str, int i, char *line, t_mlxs *mlxs);
t_color	parse_color(char **str, int i, char *line, t_mlxs *mlxs);
t_vect	parse_coord(char **str, int i, char *line, t_mlxs *mlxs);
t_vect	parse_vector(char **str, int i, char *line, t_mlxs *mlxs);
unsigned char		parse_camera_fov(char **str, int i, char *line, t_mlxs *mlxs);
float	parse_dia_height(char **str, int i, char *line, t_mlxs *mlxs);

bool	is_float(char *str);
bool	is_range(float number);
bool	is_color(char *str);
float	str_to_float(char *str);

void	parse_light(char *line, t_mlxs *mlxs);
void	parse_camera(char *line, t_mlxs *mlxs);
void	parse_amb(char *line, t_mlxs *mlxs);
void	parse_obj(char *line, t_mlxs *mlxs, t_obj_type type);

void	free_two_str_arr(char **arr1, char **arr2);

void	free_all(t_mlxs *mlxs);

void	parse_plane(char *line, t_mlxs *mlxs, t_obj *new_obj);
void	parse_sphere(char *line, t_mlxs *mlxs, t_obj *new_obj);
void	parse_cylinder(char *line, t_mlxs *mlxs, t_obj *new_obj);

#endif