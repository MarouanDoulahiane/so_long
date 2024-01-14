/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 02:17:38 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/26 09:36:46 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s1, char *old_remainder)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = ft_strlen(s1);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = s1[i];
		i++;
	}
	if (old_remainder)
		free(old_remainder);
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char const *s2, bool to_free)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	free(s1);
	if (to_free)
		free((void *)s2);
	return (res[i + j] = '\0', res);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
