
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
   
    char fname1[20];
    char fname2[20];
    printf("Enter source and destination files:\n");
    scanf("%19s %19s", &fname1, &fname2);
    
    char slovo[20];
    FILE *input;
    FILE *output= NULL;
    unsigned int len;
    unsigned int len1;
    
    
    input = fopen(fname1, "rb");
    
    fread(&slovo, sizeof(char), 19, input);
    printf("slovo %s\n", slovo);
    fclose(input);
    output = fopen(fname2, "wb");
    len = strlen(slovo);
    len1 = sizeof(output);
    fwrite(slovo, len1, 2, output);
    printf("Сopy done. Transfered simv%d, bait%lu\n", len, len1);
    fclose(output);
    return 0;
 }
       
