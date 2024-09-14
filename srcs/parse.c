/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:24:59 by jyap              #+#    #+#             */
/*   Updated: 2024/09/14 18:01:29 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

bool	is_rt_file(char *name)
{
	int	len;

	len = ft_strlen(name) - 3;
	if (name[len] == '.' && name[len + 1] == 'r'
		&& name[len + 2] == 't')
		return (true);
	return (false);
}

char	*remove_spaces(char *line)
{
	int		i;
	char	*tmp;

	i = -1;
	if (line == NULL)
		return (line);
	tmp = line;
	while (tmp[++i])
	{
		if (tmp[i] == '\t' || tmp[i] == '\n')
			tmp[i] = ' ';
	}
	line = ft_strtrim(tmp, " ");
	free(tmp);
	return (line);
}

void	parse_elements(char *line, int fd, t_mlxs *mlxs)
{
	while (line)
	{
		if (!ft_strncmp(line, "A ", 2))
			parse_amb(line, mlxs);
		else if (!ft_strncmp(line, "C ", 2))
			parse_camera(line, mlxs);
		else if (!ft_strncmp(line, "L ", 2))
			parse_light(line, mlxs);
		else if (!ft_strncmp(line, "pl ", 3))
			parse_obj(line, mlxs, 1);
		else if (!ft_strncmp(line, "sp ", 3))
			parse_obj(line, mlxs, 2);
		else if (!ft_strncmp(line, "cy ", 3))
			parse_obj(line, mlxs, 3);
		else if (!(line[0] == '\0'))
		{
			free_scene(&mlxs->sc);
			free(line);
			print_err_exit("Element is not defined.\n", mlxs, 1);
		}
		free(line);
		line = get_next_line(fd);
		line = remove_spaces(line);
	}
	free (line);
}


void	parse(char *name, t_mlxs *mlxs)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		print_err_exit("Failed to open file.\n", mlxs, 1);
	if (is_rt_file(name) == false)
		print_err_exit("Not a rt file.\n", mlxs, 1);
	line = get_next_line(fd);
	if (line == NULL)
		print_err_exit("Empty file.\n", mlxs, 1);
	mlxs->sc = ft_calloc(sizeof(t_scene), 1);
	if (mlxs->sc == NULL)
		print_err_exit("Malloc scene failed.\n", mlxs, 1);
	line = remove_spaces(line);
	parse_elements(line, fd, mlxs);
	if (close(fd) == -1)
	{
		free(mlxs->sc);
		print_err_exit("Failed to close file.\n", mlxs, 1);
	}
}