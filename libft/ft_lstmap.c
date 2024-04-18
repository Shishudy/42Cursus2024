/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 04:02:41 by rafasant          #+#    #+#             */
/*   Updated: 2024/04/18 23:12:45 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;
	t_list	*new_node;

	new_lst = NULL;
	temp = lst;
	while (temp != NULL)
	{
		new_node = ft_lstnew(f(temp->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		temp = temp->next;
	}
	return (new_lst);
}

// void	*f(unsigned long int content)
// {
// 	return ((void *)(content + 1));
// }

// void	del(void *content)
// {
// 	(void)content;
// 	return ;
// }

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*temp;
// 	int		i;

// 	lst = NULL;
// 	i = 0;
// 	while (i < 5)
// 	{
		
// 		ft_lstadd_back(&lst, ft_lstnew((void *)(int *)i));
// 		i++;
// 	}
// 	temp = lst;
// 	i = 0;
// 	while (temp != NULL)
// 	{
// 		printf("Before: %lu\n", (unsigned long int)temp->content);
// 		temp = temp->next;
// 		i++;
// 	}
// 	t_list	*new_lst;
// 	new_lst = ft_lstmap(lst, (void *) f, del);
// 	while (new_lst != NULL)
// 	{
// 		printf("After: %lu\n", (unsigned long int)new_lst->content);
// 			new_lst = new_lst->next;
// 		i++;
// 	}
// }