#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "namelist.h"


int main(int argc, char **argv) {
  canalyze(argv[1]);
  return 0;
}
	
int canalyze(char* fileAdres) 
{
  
  static char* keywords[]={"auto","break","case","char","const","continue","default","do","double",
  "else","enum","extern","float","for","goto","if","long","register","return","short","signed","sizeof",
  "static","long","switch","typedef","union","unsigned","void","volatile","while", NULL};
  
  int iskeyword(char *name) {
    char **keyword = keywords;
    while(*keyword) {
        if(!strcmp(*keyword, name))
            return 1;
        ++keyword;
    }
    return 0;
  }

  int sort(const void *p1, const void *p2)
  {
    return strcmp(p1,p2);
  }
  
  FILE *file;
  char str1[50];
  char x;
  namelist nl = make_namelist();

  file = fopen(fileAdres,"r");
  if (!file){
    printf("error opening file %s\n", fileAdres);
    fclose(file);
    return -1;
  }
  
  x=fgetc(file);
  while(x!=EOF){
      int i=0;
      int flag = 0;
      int c;
      for(c=0; c<50; c++){
	    str1[c]=0;
      } 
      while(isalpha(x)!=0){
            str1[i]=x;
	    i++;
	    x=getc(file);
	    flag = 1;
      }
      if (flag = 1 && iskeyword(str1) == 0){
	add_name(nl, str1);
      }
      int j;
      for(j=0; j<50; j++){
	    str1[j]=0;
      } 
      x=getc(file);
  }
  
  int i;
  qsort(&(nl->names[1]), nl->size, sizeof(nl->names[1]), sort);
  for (i=0; i <= nl->size; ++i){
    if (i!=1)
      printf("%s %d\n", nl->names[i].name, nl->names[i].count);
  }
  fclose(file);
}