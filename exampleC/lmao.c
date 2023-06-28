#include <stdio.h>

int main(void){
	int b[3] = {9, 12, 13};
	int *p = &b[0];
	int *o = b;

	printf("%d\n", *p);
	printf("%d\n", *o);


	printf("%d\n", *(p+1));
	printf("%d\n", *(o+2));


	printf("%d\n", *(p+3));

	return 0;
}
