/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 12:33:10 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/22 20:14:46 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int sl(char *buf);


char *stash(int fd, ssize_t len, char *buf)
{
	static int			i;
	static char			*content;
	static int			bytecount;
	
	bytecount += sl(buf);
	content = malloc(bytecount);
	while (*buf != '\n' && *buf != '\0')
	{
		content[i] = *buf;
		buf++;
		i++;
	}
	if (*buf == '\n')
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
	while (*buf)
		len++;
	return (len);
}