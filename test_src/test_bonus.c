#include "../libft.h"
#include <stdio.h>

static void ft_del(char *str)
{
	str = 0;
}

int	main()
{
	t_list	**init;
	t_list	*elem;

	*init = ft_lstnew ("Test0");
	printf("%s\n%p -> %p\n\nModifs :\n\n", (*init)->content ,(*init), (*init)->next);

	elem = ft_lstnew ("Test-1");
	ft_lstadd_front(init, elem);
	elem = ft_lstnew ("Test1");
	ft_lstadd_back(init, elem);

	elem = (*init);
	while (elem->next != NULL)
	{
		printf("\n%p :\nContent : %s\nNext : %p\n", elem, elem->content, elem->next);
		elem = elem->next;
	}
	printf("\n%p :\nContent : %s\nNext : %p\n", elem, elem->content, elem->next);
	return (0);
}