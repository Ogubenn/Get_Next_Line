/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogdurkan <ogdurkan@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:06:31 by ogdurkan          #+#    #+#             */
/*   Updated: 2022/10/27 14:06:33 by ogdurkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>



char	*move_line(char *s)
{
	char	*dest;

	dest = ft_strchr(s, '\n');
	if (!dest)
	{
		free(s);
		return (NULL);
	}
	if (*(dest + 1))
		dest = ft_strdup(dest + 1);
	else
		dest = NULL;
	free(s);
	return (dest);
}
//Normal olarak, içinde lokal değişken tanımlanan
 //bir fonksiyonu her çağırdığımızda, lokal değişken değeri yenilenir. 
 //Ancak, bu lokal değişkeni static olarak tanımlarsak, fonksiyonu her çağırmamızda, 
 //lokal değişken bir önceki fonksiyon çağrısındaki en son değerini korur.
char	*get_next_line(int fd)
{
	static char	*s;
	char		*dest;
	char		*buffer;
	int			size;

	buffer = malloc(BUFFER_SIZE + 1);
	size = read(fd, buffer, BUFFER_SIZE);
	buffer[size] = 0;
	while (size > 0)
	{
		if (!s)
			s = ft_strdup(buffer);
		else
			s = ft_strjoin(s, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		size = read(fd, buffer, BUFFER_SIZE);
		buffer[size] = 0;
	}
	dest = ft_substr(s, 0, ft_strchr(s, '\n') - s + 1);
	s = move_line(s);
	free(buffer);
	return (dest);
}
#include <stdio.h>
int main()
{
    char a[] = "aasd\nssssss\nasdasd";
    printf("%s\n",move_line(a));
}