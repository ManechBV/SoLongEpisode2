/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:39:28 by mabenois          #+#    #+#             */
/*   Updated: 2026/03/03 21:50:08 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac < 2)
		return (ft_error("Not enough args."));
	if (read_and_parse(&vars, av[1]) != 0)
		return (-1);
	if (ft_load_mlx(&vars) == 0)
	{
		mlx_loop(vars.mlx_vars->mlx);
		ft_destroy_mlx(&vars);
	}
	free_vars(&vars);
	return (0);
}
