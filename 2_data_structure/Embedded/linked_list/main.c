#include "head.h"

int main()
{
  single_linked_list *list = create();
  insert(list, 5);
  insert(list, 4);

  prinf_list(list);
  fun(list);
  prinf_list(list);
  rm(list);
  list = NULL;
  printf("%p",list);
  prinf_list(list);

  return 0;
}
