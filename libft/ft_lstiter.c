/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 03:48:29 by rafasant          #+#    #+#             */
/*   Updated: 2024/04/14 03:52:46 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	f(void *)
{
	return ;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

int	main(void)
{
	t_list	*lst;
	t_list	*temp;
	int		i;

	lst = ft_lstnew((void*)0);
	i = 0;
	while (i < 5)
	{
		ft_lstadd_back(&lst, ft_lstnew((void*)1 + i));
		i++;
	}
	temp = lst;
	while (temp != NULL)
	{
		printf("Before: %lu\n", (unsigned long int)temp->content);
		temp = temp->next;
		i++;
	}
	ft_lstiter(lst, f);
	while (lst != NULL)
	{
		printf("After: %lu\n", (unsigned long int)lst->content);
		lst = lst->next;
		i++;
	}
}