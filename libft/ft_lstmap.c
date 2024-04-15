/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 04:02:41 by rafasant          #+#    #+#             */
/*   Updated: 2024/04/14 04:10:28 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	int	size;

	size = ft_lstsize(lst);
	new_lst = ft_lstnew(f(lst->content));
	while (size >= 0)
	{
		lst = lst->next;
		ft_lstadd_back(new_lst, ft_lstnew(f(lst->content)));
		size--;
	}
	return (new_lst);
}