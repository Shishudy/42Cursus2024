/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:40:56 by rafasant          #+#    #+#             */
/*   Updated: 2025/08/07 19:43:56 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/catch.h"

t_catch	*catch(void)
{
	static t_catch	catch;

	return (&catch);
}

char	*set_error(char *s, ...)
{
	va_list		args;
	t_error_var	*error_vars;
	char		*error_msg;

	if (!s)
		return ("Invalid string in set_error()!");
	error_msg = ft_calloc(1, sizeof(char));
	if (!error_msg)
		return ("Malloc failure in set_error()!");
	free(error_msg);
	error_msg = NULL;
	va_start(args, s);
	error_vars = convert_vars(s, args);
	if (error_vars == NULL)
		return ("Error converting variables to strings in set_error()!");
	alloc_error_msg(s, error_vars, &error_msg);
	if (error_msg == NULL)
		return ("Error allocating memory for error_msg in set_error()!");
	build_error_msg(s, error_vars, error_msg);
	free_vars(error_vars);
	va_end(args);
	return (error_msg);
}
