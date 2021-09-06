#include "function.h"
#include <stdio.h>

t_list* merge(t_list* l1, t_list* l2)
{
    t_list head;
    t_list *p_head = &head;
    
    if (l1 == NULL && l2 == NULL)
        return NULL;
    
    while (l1 || l2) {
        if (*((int*)l1->content) < *((int*)l2->content)) {
            p_head->next = l1;
            l1 = l1->next;
            p_head = p_head->next;
        } else {
            p_head->next = l2;
            l2 = l2->next;
            p_head = p_head->next;
        }
    }

    if (l1) {
        p_head->next = l1;
    }
    if (l2) {
        p_head->next = l2;
    }
  
    return head.next;
}

void print(void *ptr)
{
	printf("%d\n", *((int*)ptr));
}

int main(void)
{
	t_list *l1 = ft_lstnew((int[]){1});
	ft_lstadd_back(&l1, ft_lstnew((int[]){3}));
	ft_lstadd_back(&l1, ft_lstnew((int[]){4}));

	t_list *l2 = ft_lstnew((int[]){1});
	ft_lstadd_back(&l2, ft_lstnew((int[]){2}));
	ft_lstadd_back(&l2, ft_lstnew((int[]){3}));
	ft_lstadd_back(&l2, ft_lstnew((int[]){4}));

	t_list *sorted = merge(l1, l2);
	ft_lstiter(sorted, print);
}
