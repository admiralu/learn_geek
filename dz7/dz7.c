#include <stdio.h>
 
int mu_ar(int *sum, int *proizv, int *raz, int *delen, int a, int b)
   {
   	*sum= a+b;
   	*proizv= a*b;
   	*raz= a-b;
   	*delen= a/b;
   return(*sum, *proizv, *raz, *delen);
   
int main()
{
	 int sum;
	 int proizv;
	 int raz;
	 int delen;
	 int a;
	 int b;
	  printf("enter two digits\n");
	  scanf("%d%d\n", &a, &b);
	  mu_ar( int sum, int proizv, int raz, int delen)
	  printf("summa=\n", mu_ar(sum));
	  printf("proizvedenie=\n", mu_ar(proizv));
	  printf("raznost=\n", mu_ar(raz));
	  printf("chastnoe=\n", mu_ar(delen));
    
	return 0;
}
 
