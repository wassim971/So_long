/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:58:52 by wbaali            #+#    #+#             */
/*   Updated: 2025/04/29 13:22:11 by wbaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoins(char const *s1, char const *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlens(s1) + ft_strlens(s2);
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[sizetotal] = 0;
	return (res);
}

char	*ft_strchrs(const char *string, int search)
{
	char	*str;

	str = (char *)string;
	while (*str != search && *str != 0)
		str++;
	if (*str == search)
		return (str);
	else
		return (NULL);
}

void	ft_bzeros(void *s, unsigned int n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = '\0';
}

void	*ft_callocs(unsigned int count, unsigned int size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzeros(ptr, size * count);
	return (ptr);
}

size_t	ft_strlens(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
