 #include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(int argc, char **argv)
{
        DIR *dip;
        struct dirent *dit;
        struct stat fileStat;
        int i = 0;
        int help = 0;
        int l = 0;
        int c;
        
        
        opterr = 0;
        while ((c = getopt (argc, argv, "hl::")) != -1)
         switch (c)
           {
           case 'h':
	    help=1;
            break;
           case 'l':
            l = 1;
            break;
           }

        if(help==1){
            printf("\nNAME\n dir - print list of files in the directory\n\nSYNOPSIS\n dir [OPTIONS] [directory]\n\nDESCRIPTION\n dir prints a list of files in the directory specified as the argument,\n on file per line.\n If the directory name is not specified,\n the list of files in the current directory is printed.\n\nOPTIONS\n -h print summary of options and exit.\n -l print file size in bytes before the file name.\n\n");
	}
        
        
        
        /* check to see if user entered a directory name */
        if (argc < 2){
                printf("Usage: %s <directory>\n", argv[0]);
                return 0;
        }
        

        if ((dip = opendir(argv[optind])) == NULL){
                perror("opendir");
                return 0;
        }


        while ((dit = readdir(dip)) != NULL){
	  printf("File: '%s', Size of this file: %d bytes\n" ,dit->d_name, dit->d_reclen);
        }

        if (closedir(dip) == -1)
        {
                perror("closedir");
                return 0;
        }
 
      
        return 1;
}