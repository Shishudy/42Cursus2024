/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 04:02:41 by rafasant          #+#    #+#             */
/*   Updated: 2024/04/15 17:22:46 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*f(void *content)
{
	return (content + 1);
}

void	del(void *content)
{
	(void)content;
	return ;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;
	t_list	*new_node;

	new_lst = ft_lstnew(lst->content);
	temp = lst->next;
	while (temp != NULL)
	{
		new_node = ft_lstnew(f(temp->content + 1));
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
	i = 0;
	while (temp != NULL)
	{
		printf("Before: %lu\n", (unsigned long int)temp->content);
		temp = temp->next;
		i++;
	}
	t_list	*new_lst;
	new_lst = ft_lstmap(lst, f, del);
	while (new_lst != NULL)
	{
		printf("After: %lu\n", (unsigned long int)new_lst->content);
			new_lst = new_lst->next;
		i++;
	}
} //porque e que o primeiro elemento da lista nova nao fica com 1? como e que posso passar o valor 0 para dentro da funcao f para que saia 1