/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 12:33:10 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/27 21:41:46 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int sl(char *buf);


char *stash(int fd, char *buf)
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
		i++;
		j++;
	}
	if (buf[j] == '\n' || buf[0] == '\n' || buf[0] == '\0')
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