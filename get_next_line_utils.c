/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 12:33:10 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/24 20:59:33 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int sl(char *buf);


char *stash(int fd, ssize_t len, char *buf)
{
	static int			i;
	int					j;
	static char			*content;
	static int			bytecount;
	
	j = 0;
	bytecount =+ sl(buf);
	content = malloc(bytecount);
	while (buf[j] != '\n' && buf[j] != '\0')
	{
		content[i] = buf[j];
		buf++;
		j++;
	}
	if (buf[j] == '\n')
	{
		free(buf); 
		return (content);
	}
	else
		return (get_next_line(fd));
}

/*char *buffering(int fd)
{
	
}*/

int sl(char *buf)
{
	int	len;
	
	len = 0;
	while (buf[len])
		len++;
	return (len);
}