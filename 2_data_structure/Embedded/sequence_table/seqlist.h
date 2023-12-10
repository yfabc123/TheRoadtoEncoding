#ifndef a
#define a
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

struct student
{
    char name[20];
    int id;
    int age;

} ;
typedef struct student datatype_t;

typedef struct
{
    datatype_t buf[MAX];
    int n;
} seqlist_t;

extern seqlist_t *create_empty_seqlist();
extern int isfull_seqlist(seqlist_t *l);
extern void insert_data_selist(seqlist_t *l, datatype_t date);
extern void printf_data_seqlist(seqlist_t *l);
extern int is_empty_seqlist(seqlist_t *l);
int delete_data_seqlist(seqlist_t *l, datatype_t data);
#endif
