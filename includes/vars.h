/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:54:35 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/28 07:19:40 by mabenois         ###   ########.fr       */
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
# include "mlx.h"
# include "mlx_extended.h"

typedef struct	s_map
{
	int	**map;
	int	w;
	int	h;
}	t_map;

typedef struct	s_mlx_vars
{
	mlx_context				mlx;
	mlx_window_create_info	info;
	mlx_window				win;
}	t_mlx_vars;

typedef struct	s_imgs
{
	mlx_image	tileset;
}	t_imgs;

typedef struct	s_timers
{
	int	coin_timer;
	int	coin_reset;
	int	coin_frame;
}	t_timers;

typedef struct	s_vars
{
	t_map		*map;
	t_mlx_vars	*mlx_vars;
	t_imgs		*imgs;
	t_timers	*timers;
}	t_vars;

//	ft_error.c
int		ft_error(char *s);

//	parsing.c
int		read_and_parse(t_vars *vars, char *filename);

//	parsing2.c
void	free_vars(t_vars *vars);
int		ft_error_free_map(t_map *map, int y, char *tmp, int fd);
int		ft_check_line_w(char *tmp, size_t map_w);
int		ft_check_border(t_map *map);

//	parsing_flood.c
int		ft_check_map_flood(t_map *map);

//	ft_window.c
int		ft_load_mlx(t_vars *vars);
int		ft_destroy_mlx(t_vars *vars);
void	window_hook(int event, void *param);
void	update_loop(void *param);
void	ft_draw_map(t_vars *vars);

#endif
