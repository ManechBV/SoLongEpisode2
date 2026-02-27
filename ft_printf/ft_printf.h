/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:13:02 by mabenois          #+#    #+#             */
/*   Updated: 2025/12/20 18:41:40 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *format, ...);
int	ft_printstr(char *s);
int	ft_printint(int a);
int	ft_printuint(unsigned int a);
int	ft_printhex(unsigned int a, int is_upper);
int	ft_printptr(void *ptr);

#endif
