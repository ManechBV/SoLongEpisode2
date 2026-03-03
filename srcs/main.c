/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:39:28 by mabenois          #+#    #+#             */
/*   Updated: 2026/03/04 00:33:13 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	char	*ber;

	if (ac < 2)
		return (ft_error("Not enough args."));
	if (ft_strlen(av[1]) < 4)
		return (ft_error("need .ber"));
	ber = ft_strnstr(av[1] + ft_strlen(av[1]) - 4, ".ber", ft_strlen(av[1]));
	if (ber == NULL || ber[4] != 0)
		return (ft_error("need .ber"));
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
