#include <stdio.h>
 

int main()
{
int max;
char max2;
int i;
int cnt[256]={0};
char str=0;

while ((str = getchar()) != '.')
   {
    if (str >= '0' && str <= '9')
     {
     cnt[str]++;
     }
   }
   for(i=1; i<256; i++)
    {
      if (cnt[i]>max)
    	{
    		max=cnt[i];
    		max2=i;
    	  //printf("%d\n", max);  
       }
    }
  printf("quantity printed=%d simv=%c\n", max, max2);  
  return 0;
}