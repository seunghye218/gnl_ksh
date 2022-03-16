/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:01:08 by seunghye          #+#    #+#             */
/*   Updated: 2022/03/16 19:10:10 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	*lst;
	t_list			*fd_lst;
	char			*buf;
	ssize_t			n;

	if (fd < 0 || BUFFER_SIZE <= 0) //오류 체크
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); //버퍼를 동적할당으로 할당 (정적할당은 제한된 스택사이즈 내에서 공간을 할당 받기 떄문)
	if (!buf)
		return (0);
	if (ft_lstfd(lst, fd) && ft_strchr(ft_lstfd(lst, fd)->str, '\n'))
		return (find_n(&ft_lstfd(lst, fd)->str, buf));
	n = read(fd, buf, BUFFER_SIZE);
	while (n > 0)
	{
		buf[n] = 0;
		fd_lst = ft_lstadd(&lst, fd, buf); //fd값의 노드가 없으면 lst에 노드 추가, 있다면 기존 문자열과 buf를 join
		if (fd_lst && ft_strchr(fd_lst->str, '\n')) //개행이 있다면 개행 뒷부분을 백업하고 개행까지 문자열을 리턴
			return (find_n(&fd_lst->str, buf));
		n = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (ft_lstfd(lst, fd))
	{
		buf = ft_lstfd(lst, fd)->str;
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