/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:25:47 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/21 13:28:26 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

static size_t	word_count(char const *s, char c)
{
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			size++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (size);
}

static char	*get_next_word(size_t *i, char const *s, char c)
{
	size_t	index;
	size_t	size;
	size_t	tmp;
	char	*res;

	while (s[*i] && s[*i] == c)
		(*i)++;
	tmp = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	size = *i - tmp;
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	index = 0;
	while (tmp + index < *i)
	{
		res[index] = s[tmp + index];
		index++;
	}
	res[index] = '\0';
	return (res);
}

static char	**free2d(char **arr)
{
	size_t	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	index;
	size_t	wc;
	size_t	i;
	char	**res;

	if (!s)
		return (NULL);
	i = 0;
	index = 0;
	wc = word_count(s, c);
	res = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!res)
		return (NULL);
	while (index < wc)
	{
		res[index] = get_next_word(&i, s, c);
		if (!res[index])
			return (free2d(res));
		index++;
	}
	res[wc] = NULL;
	free((void *)s);
	return (res);
}
