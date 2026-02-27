/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:09:52 by mabenois          #+#    #+#             */
/*   Updated: 2025/12/20 18:43:02 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 32

# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*read_buffer(int fd, char *stash, size_t buffer_size_safe);
char	*fetch_line(char *stash);
char	*remove_line_from_stash(char *stash);
int		ft_contains_nl(char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strlcpy_gnl(char *dst, const char *src, size_t size);
void	*ft_calloc_gnl(size_t nmemb, size_t size);

#endif
