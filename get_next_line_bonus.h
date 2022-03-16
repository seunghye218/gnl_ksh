/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:01:16 by seunghye          #+#    #+#             */
/*   Updated: 2022/03/17 00:42:27 by kimseungh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			*str;
	struct s_list	*next;
}	t_list;

size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, char c);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
t_list	*ft_lstnew(int fd, char *buf);
t_list	*ft_lstadd(t_list **lst, int fd, char *buf);
void	ft_lstdelone(t_list **lst, int fd);
char	*ft_read(t_list **lst, int fd, char *buf, t_list **fd_lst);
char	*find_n(char **str, char *buf);
char	*get_next_line(int fd);
#endif
