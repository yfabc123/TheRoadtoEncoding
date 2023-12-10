#include "bitree.h"

 //            1:A
 //       2:B          3:C
 //   4:D   5:E      6:F
 //
 //前:  A B D E C F 
 //
 //中:  D B E A F C
 //
 //后:  D E B F C A
int main()
{
	bitree_t *root;

	root = create_binatry_tree(1);

	printf("create is successful!\n");


	printf("pre_order : ");
	pre_order(root);
	printf("\n");

	printf("in_order : ");
	in_order(root);
	printf("\n");

	printf("post_order : ");
	post_order(root);
	printf("\n");
	return 0;
}
