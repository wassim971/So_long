/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:47:21 by wbaali            #+#    #+#             */
/*   Updated: 2025/04/29 13:20:30 by wbaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strjoins(char const *s1, char const *s2);
char	*ft_strchrs(const char *str, int search);

void	ft_bzeros(void *s, unsigned int n);
void	*ft_callocs(unsigned int count, unsigned int size);

size_t	ft_strlens(const char *str);

#endif
