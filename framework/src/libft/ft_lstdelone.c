/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:52:46 by melschmi          #+#    #+#             */
/*   Updated: 2025/11/10 12:56:30 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst == NULL)
		return ;
	tmp = lst;
	lst = lst->next;
	if (del)
		(*del)(tmp->content);
	tmp->next = NULL;
	free(tmp);
}

/*int	main()
{
	t_list *lst;

	lst = ft_lstnew(ft_strdup("test"));

	if (lst->next->next)
		ft_lstdelone(lst->next->next, free);
	ft_lstdelone(lst->next, NULL);
	return (0);
}*/
