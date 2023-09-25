#include "libmx.h"

static void swap(void **s1, void **s2) 
{
    if (*s1 != *s2) {
        *s1 = (void *)((size_t)(*s1) + (size_t)(*s2));
        *s2 = (void *)((size_t)(*s1) - (size_t)(*s2));
        *s1 = (void *)((size_t)(*s1) - (size_t)(*s2));
    }
}

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)) {
    if (list)
    {
        for (t_list *temp1 = list; temp1; temp1 = temp1->next)
        {
            for (t_list *temp2 = list; temp2->next; temp2 = temp2->next)
            {
                if (cmp(temp2->data, temp2->next->data))
                {
                    swap(&temp2->data, &temp2->next->data);  
                }
            }
        }
    }
    return list;
}