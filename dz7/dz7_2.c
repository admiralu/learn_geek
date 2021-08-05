#include <stdio.h>
 
void mu_ar(int sum, int *proizv, int *raz, int *delen)
   {
   	int a;
   	int b;
   	printf("enter two digits\n");
	   scanf("%d%d\n", &a, &b);
   	printf("%d  %d\n", a, b);
   	sum= a+b;
   	printf("%d\n", sum);
   	*proizv= a*b;
   	printf("%d\n", proizv);
   	*raz= a-b;
   	*delen= a/b;
   
   //return(sum, *proizv, *raz, *delen);
   }
   
int main(int argc, char **argv)
{
	 int sum;
	 int proizv;
	 int raz;
	 int delen;
	 int a;
	 int b;
	  
	  printf("%d%d\n", a, b);
	  mu_ar(sum, &proizv, &raz, &delen);
	  printf("summa=\n", sum);
		printf("proizvedenie=\n", proizv);
	  printf("raznost=\n", raz);
	  printf("chastnoe=\n", delen);
    
	return 0;
}
 
