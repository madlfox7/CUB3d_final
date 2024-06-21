/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parsing_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:27:46 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/23 14:27:50 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

void	ft_check_argc_and_name(int argc, char *argv[])
{
	size_t	i;
	char	*c;

	if (argc != 2)
	{
		ft_put_error("Error: Wrong argc quantity");
		exit(EXIT_FAILURE);
	}
	i = ft_strlen(argv[1]);
	c = &argv[1][i - 4];
	if (ft_strncmp(c, ".cub", 4))
	{
		ft_put_error("Error: Wrong filename");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	check_file_exists(char *argv, int *fd)
{
	*fd = open(argv, O_RDONLY);
	if (*fd == -1)
	{
		ft_put_error("Error: File not found");
		exit(EXIT_FAILURE);
	}
	return ;
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	simple_atoi(char *str)
{
	int	result;
	int	sign;
	int	digit;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		digit = str[i] - '0';
		result = result * 10 + digit;
		i++;
	}
	return (sign * result);
}

int	invalid_color(char *token)
{
	int	value;
	int	i;

	i = 0;
	while (token[i] != '\0')
	{
		if (!ft_isdigit(token[i]))
			return (1);
		i++;
	}
	value = simple_atoi(token);
	if (value < 0 || value > 255)
		return (1);
	return (0);
}
