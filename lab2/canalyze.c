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
  
  /*
  int check(char* word){
    switch (word){
      case "auto":return 0;
      case "break":return 0;
      case "case":return 0;
      case "char":return 0;
      case "const":return 0;
      case "continue":return 0;
      case "default":return 0;
      case "do":return 0;
      case "double":return 0;
      case "else":return 0;
      case "enum":return 0;
      case "extern":return 0;
      case "float":return 0;
      case "for":return 0;
      case "goto":return 0;
      case "if":return 0;
      case "long": return 0;
      case "register": return 0;
      case "return": return 0;
      case "short": return 0;
      case "signed": return 0;
      case "sizeof": return 0;
      case "static": return 0;
      case "long": return 0;
      case "switch": return 0;
      case "typedef": return 0;
      case "union": return 0;
      case "unsigned": return 0;
      case "void": return 0;
      case "volatile": return 0;
      case "while": return 0;
      default: return 1;
    }
      return 1;
  }
  */

  int sort(const void *p1, const void *p2)
  {
    return strcmp(p1,p2);
  }
  
  FILE *file;
  char str1[50];
  namelist nl = make_namelist();

  file = fopen(fileAdres,"r");
  if (!file){
    printf("error opening file %s\n", fileAdres);
    fclose(file);
    return -1;
  }
  
  while (fscanf(file,"%s",str1) != EOF){
//    if (check(str1) == 1)
      add_name(nl, str1);
  }
  int i;
//  for (i=0; i < nl->size; ++i){
//    printf("%s\n", nl->names[i].name);
//  }
  qsort(&(nl->names[1]), nl->size, sizeof(nl->names[1]), sort);
  for (i=0; i < nl->size; ++i){
    printf("%s\n", nl->names[i].name);
  }
  fclose(file);
}