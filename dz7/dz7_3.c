#include <stdio.h>
 
void mu_ar(int *sum, int *proizv, int *raz, int *delen)
   {
   	int a;
   	int b;
   	printf("enter two digits\n");
	   scanf("%d%d\n", &a, &b);
   	printf("%d  %d\n", a, b);
   	*sum= a+b;
   	*proizv= a*b;
     *raz= a-b;
   	*delen= a/b;
   }
   
int main()
{
	 int sum;
	 int proizv;
	 int raz;
	 int delen;
	 int a;
	 int b;
	 mu_ar(&sum, &proizv, &raz, &delen);
	  printf("summa=%d\n", sum);
		printf("proizvedenie=%d\n", proizv);
	  printf("raznost=%d\n", raz);
	  printf("chastnoe=%d\n", delen);
    
	return 0;
}
 
