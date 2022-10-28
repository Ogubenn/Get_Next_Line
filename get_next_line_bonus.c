/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogdurkan <ogdurkan@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:41:59 by ogdurkan          #+#    #+#             */
/*   Updated: 2022/10/28 09:42:00 by ogdurkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str[fd] = ft_read_to_left_str(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = ft_get_line(left_str[fd]);
	left_str[fd] = ft_new_left_str(left_str[fd]);
	return (line);
}
#include <stdio.h>
 int		main()
 {
     char *line;

     int fd1 = open("b.txt",O_RDONLY);
	 int fd2 = open("a.txt",O_RDONLY);
      line = get_next_line(fd1);
 	 printf("%s\n",line);
	 char *line2 = get_next_line(fd2);
 	 printf("%s\n",line2);
	    line = get_next_line(fd1);
 	 printf("%s\n",line);
	 	line2 = get_next_line(fd2);
 	 printf("%s\n",line2);
	// printf("%d\n",fd2);
	// printf("%d\n",fd1);
	

 	close(fd1);

 }
