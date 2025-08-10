/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rida-cos <rida-cos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:03:42 by rida-cos          #+#    #+#             */
/*   Updated: 2025/08/10 18:55:34 by rida-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	size;
	int	i;

	size = 0;
	while (s[size] != '\0')
		size++;
	size++;
	i = 0;
	while (i < size)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	size_t	sub_len;
	char	*substr;

	s_len = ft_strlen(s);
	if ((size_t)start >= s_len)
		return (ft_strdup(""));
	sub_len = s_len - start;
	if (sub_len > len)
		sub_len = len;
	substr = (char *)malloc(sizeof(char) * (sub_len + 1));
	if (!substr)
		return (0);
	i = 0;
	while (i < sub_len && (s[(size_t)start + i] != '\0'))
	{
		substr[i] = s[(size_t)start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*copy;

	len = 0;
	while (s[len] != '\0')
		len++;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*joined;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	joined = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!joined)
		return (NULL);
	ft_memcpy(joined, s1, s1_len);
	ft_memcpy(joined + s1_len, s2, s2_len);
	joined[s1_len + s2_len] = '\0';
	return (joined);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*str;
	size_t			i;

	if (!dest && !src && n > 0)
		return (0);
	destination = (unsigned char *)dest;
	str = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		destination[i] = (unsigned char)str[i];
		i++;
	}
	return (dest);
}
