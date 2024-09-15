/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:09:38 by jyap              #+#    #+#             */
/*   Updated: 2024/09/15 20:38:55 by jyap             ###   ########.fr       */
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

# define WIN_W 500
# define WIN_H 500

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
double	parse_dia_height(char **str, int i, char *line, t_mlxs *mlxs);

bool	is_float(char *str);
bool	is_range(double number);
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

double	solve_quadratic(double a, double b, double c);

double	dot_product(t_vect v1, t_vect v2);
double	distance(t_vect v1, t_vect v2);
t_vect	mult(t_vect v, double scale);
t_vect	sub(t_vect v1, t_vect v2);
t_vect	add(t_vect v1, t_vect v2);
t_vect	normalize(t_vect v);

void	set_pixel_color(t_image img, int x, int y, int color);
t_color	get_pixel_color(t_inter *inter);

void	launch_rays_from_camera(t_mlxs *mlxs);

bool	is_closest(t_inter *closest, t_inter *temp);
void	closest_inter(t_mlxs *mlxs, t_ray *ray);

t_inter	*intersect_plane(t_ray *ray, t_plane *plane);
t_inter	*intersect_sphere(t_ray *ray, t_sphere *sphere);
t_inter	*intersect_cylinder(t_ray *ray, t_cylinder *cylinder);

bool	is_intersection_valid(t_ray *ray, t_cylinder *cy, double t, double h);
t_vect	cylinder_normal(t_vect P, t_cylinder *cylinder);
int		quad_cylinder(t_ray *ray, t_inter *inter, t_cylinder *cylinder, t_vect X);


#endif