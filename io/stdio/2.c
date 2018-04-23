#include <stdio.h>
#include <stdlib.h>

void main()
{
  int a=123456789; 

  FILE* fp;
  fp=fopen("a.txt","wb+");

 if(fp==0){puts("error");exit(0);}

  fwrite(&a,sizeof(int),1,fp);
  fwrite(&a,sizeof(int),1,stdout);

  fclose(fp);
}
