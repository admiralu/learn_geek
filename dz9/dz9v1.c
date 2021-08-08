#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void str_sum_digits(const char *cs);

int main()
{
	const char cs[100] = { 0 };
	printf("enter string with digits\n");
	scanf("%[0-9]", &cs);
	printf("cs %s\n", cs);
	str_sum_digits(cs);
	//*cs=getchar();
	//printf("Hello World!");
	return 0;
}
 
void str_sum_digits(const char *cs)
  {
    int a;
    int b;
    int i;
    int sum = 0;
   // const char cs[100] = { 0 };
	 // printf("enter string with digits\n");
	//  scanf("%[0-9]", &cs);
	  b = strlen(cs);
	  printf("len %d\n", b);
    a = atoi(cs);
    printf("a=%d\n", a);
    for(i=0; i<=b; i++)
      {
      	sum = sum+=(a % 10);
      	a = a / 10;
      }
      printf("sum digits=%d\n", sum);
  }