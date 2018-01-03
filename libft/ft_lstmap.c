/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:16:14 by wsabates          #+#    #+#             */
/*   Updated: 2017/11/15 11:30:31 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;

	if (lst == NULL)
		return (NULL);
	if ((list = (t_list*)malloc(sizeof(f(lst)))) == NULL)
		return (NULL);
	list = f(lst);
	list->next = ft_lstmap(lst->next, f);
	return (list);
}
