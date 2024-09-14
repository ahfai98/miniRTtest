/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:07:00 by jyap              #+#    #+#             */
/*   Updated: 2024/09/14 17:35:09 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	main(int ac, char **av)
{
	t_mlxs	*mlxs;

	(void) av;
	if (ac != 2)
	{
		print_err("Invalid Arguments.\n", NULL);
		print_err_exit("./miniRT <file.rt>\n", NULL, 1);
	}
	mlxs = ft_calloc(sizeof(t_mlxs), 1);
	if (mlxs == NULL)
		print_err_exit("Malloc mlxs failed.\n", NULL, 1);
	parse(av[1], mlxs);
	make_window(mlxs);
}