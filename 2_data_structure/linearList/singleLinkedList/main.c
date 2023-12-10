#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkList.h"
int main()
{
    linknode_t *head = create_empty_linklist();
    insert_order_linklist(head, 4);
    insert_order_linklist(head, 2);
    insert_order_linklist(head, 5);
    insert_order_linklist(head, 1);
    insert_order_linklist(head, 4);

   // printf_data_linklist(head);
    clean_up_linklist(head);
    printf_data_linklist(head);
    

    return 0;
}