#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int bcm(char* frame1, char* frame2)
{
  FILE *f1, *f2;
  char *buffer1;
  char *buffer2;
  unsigned long fileLen1, fileLen2;
  int n1, n2;
  
  
  f1=fopen(frame1, "rb"); 
  f2=fopen(frame2, "rb");
  
  if(!f1)
  {
    printf("Error opening file %s\n", frame1);
    fclose(f1);
    return -1;
  }
    
  if(!f2)
  {
    printf("Error opening file %s\n", frame2);
    fclose(f2);
    return -1;
  }

 n1 = (int)fgetc(f1);
 n2 = (int)fgetc(f2);
 int i = 0;
 while (n1!=EOF || n2!=EOF){
   if (n1 != n2){
      printf("byte %d ",i);
      printf("%d %d\n",n1, n2);
      break;
    }
    else{
    n1 = (int)fgetc(f1);
    n2 = (int)fgetc(f2);
    i++;
    }
 }    
    
  fclose(f1);
  fclose(f2);

  return 0;
}

void main(int argc, char **argv)
{
	bcm(argv[1],argv[2]);

}