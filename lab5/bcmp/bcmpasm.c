unsigned int open(char*);
int readChar(unsigned int, char[]);
void close(unsigned int);
void puts();

int main(int argc, char *argv[]) {
  unsigned int fp1, fp2;
  int ch1 = 1;
  int ch2 = 1;
  int same;

  /* open first file */
  fp1 = open(argv[1]);
  /* open second file */
  fp2 = open(argv[2]);
  /* open second file */

  char buf1[1];
  char buf2[1];
  
  /* compare the files */
  while ((ch1 == 1) & (ch2 == 1)) {
    ch1 = readChar(fp1, buf1);
    ch2 = readChar(fp2, buf2);
    if ((ch1 == 0) || (ch2 == 0)) break;
    if((char)*buf1 != (char)*buf2) {
      char* msg = "byte ";
      puts(msg);
      puts(buf1);
      msg = " ";
      puts(msg);
      puts(buf2);
      msg = "\n";
      puts(msg);   
      same = 0;
    }
  }
  if(same){
    char* msg = "Files are the same.\n";
      puts(msg);
  }
  
  close(fp1);
  close(fp2);

  return 0;
}