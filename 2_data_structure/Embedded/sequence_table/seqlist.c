#include "seqlist.h"

seqlist_t *create_empty_seqlist()
{
    seqlist_t *seq = (seqlist_t *)malloc(sizeof(seqlist_t));
    if (NULL == seq)
    {
        return NULL;
    }
    seq->n = 0;                        // 一定要置为0
    memset(seq, 0, sizeof(seqlist_t)); // 重置
    return seq;
}
int isfull_seqlist(seqlist_t *l)
{
    if (l->n < MAX)
    {
        return 0;
    }
    else
        return 1;
}
void insert_data_selist(seqlist_t *l, datatype_t date)
{
    if (!isfull_seqlist(l))
    {
        l->buf[l->n] = date;
        l->n++;
    }
    else
        printf("full!");
}

void printf_data_seqlist(seqlist_t *l)
{
    for (int i = 0; i < l->n; i++)
    {
        printf("%s-%d-%d\n", l->buf[i].name, l->buf[i].id, l->buf[i].age);
    }
}
int is_empty_seqlist(seqlist_t *l)
{
    return l->n != 0 ? 1 : 0; // 1说明不为空
}
int delete_data_seqlist(seqlist_t *l, datatype_t data)
{
    int j = 0;
    if (is_empty_seqlist(l))
    {
        for (int i = 0; i < l->n; i++)
        {
            if (l->buf[i].age != data.age || l->buf[i].id != data.id || strcmp(l->buf[i].name,data.name)==-1)
            {
                l->buf[j] = l->buf[i];
                j++;
            }
        }
        l->n = j;
        return 1;
    }
    else
        return 0;
}