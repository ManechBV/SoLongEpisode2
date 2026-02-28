/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:54:35 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/28 04:08:48 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

# define P 2
# define C 3
# define E 4

# include <fcntl.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct	s_map
{
	int	**map;
	int	w;
	int	h;
}	t_map;

typedef struct	s_vars
{
	t_map	*map;
}	t_vars;

//	ft_error.c
int		ft_error(char *s);

//	parsing.c
int		read_and_parse(t_vars *vars, char *filename);

//	parsing2.c
void	free_vars(t_vars *vars);
int		ft_error_free_map(t_map *map, int y, char *tmp, int fd);
int		ft_check_line_w(char *tmp, size_t map_w);

//	parsing_flood.c
int		ft_check_map_flood(t_map *map);

#endif
