#include "seqlist.h"
int main()
{
    datatype_t s1 = {"zhangsan", 1, 21};
    datatype_t s2 = {"lisi", 2, 22};
    datatype_t s3 = {"wangwu", 3, 23};
    seqlist_t *l = create_empty_seqlist();
    insert_data_selist(l, s1);
    insert_data_selist(l, s2);
    insert_data_selist(l, s3);
    insert_data_selist(l, s1);
    printf_data_seqlist(l);
    delete_data_seqlist(l, s1);
    printf_data_seqlist(l);

    return 0;
}
