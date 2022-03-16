/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:01:08 by seunghye          #+#    #+#             */
/*   Updated: 2022/03/17 00:41:29 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*lst;
	t_list			*fd_lst;
	char			*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	fd_lst = lst;
	buf = ft_read(&lst, fd, buf, &fd_lst);
	if (buf)
		return (buf);
	if (fd_lst)
	{
		buf = fd_lst->str;
		ft_lstdelone(&lst, fd);
		if (!*buf)
		{
			free(buf);
			return (0);
		}
		return (buf);
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	n;

	if (!str)
		return (0);
	n = 0;
	while (str[n])
		n++;
	return (n);
}

char	*ft_strchr(char *str, char c)
{
	while (*str != c && *str)
		str++;
	if (*str == c)
		return (str);
	return (0);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	src_size;
	size_t	i;

	if (!src || !dst)
		return (0);
	src_size = ft_strlen(src);
	if (!size)
		return (src_size);
	i = 0;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (src_size);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	size_1;
	size_t	size_2;

	if (!s1 || !s2)
		return (0);
	size_1 = ft_strlen(s1);
	size_2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (size_1 + size_2 + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, size_1 + 1);
	ft_strlcpy(str + size_1, s2, size_2 + 1);
	return (str);
}
