#include "SinglyLinkedCircularList.h"
int main()
{
    loopnode_t *head = create_empty_looplist();
    insert_head_looplist(head, 1);
    insert_head_looplist(head, 2);
    insert_head_looplist(head, 3);
    printf_data_looplist(head);

    return 0;
}