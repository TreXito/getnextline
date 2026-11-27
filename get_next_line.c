/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:02:30 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/28 00:15:09 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	*buf;
	ssize_t	len;
	char	*content;

	buf = 0;
	len = 0;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	len = read(fd, buf, BUFFER_SIZE);
	if (len < 0)
		return (free(buf), NULL);
	buf[len] = '\0';
	content = stash(fd, buf);
	return (content);
}
/*int main (void)
{
	int fd = open("test.txt",O_RDONLY);
	int i = 0;

	while (i != 2)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
}
*/