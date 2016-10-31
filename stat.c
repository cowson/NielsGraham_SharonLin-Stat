#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

int main(){
  struct stat fileStat;
  stat("test.txt", &fileStat);

  printf("Information for %s\n", "test.txt");
  printf("---------------------------\n");
  if (fileStat.st_size < 1024)
    printf("File Size:\t\t%d bytes\n",fileStat.st_size);
  else if (fileStat.st_size < 1048576)
    printf("File Size: \t\t%d kilobytes %d bytes", fileStat.st_size/1024, fileStat.st_size%1024);
  else if (fileStat.st_size < 1073741824)
    printf("File Size: \t\t%d megabytes %d killobytes", fileStat.st_size/1048576, fileStat.st_size%1048576);
  else
    printf("File Size: \t\t%d gigabytes %d megabytes", fileStat.st_size/1073741824, fileStat.st_size%1073741824);
  printf("Time of last access:\t%d\n", fileStat.st_atime);

  printf("File Permissions: \t");
  printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
  printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
  printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
  printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
  printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
  printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
  printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
  printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
  printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
  printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
  printf("\n\n");
  return 0;
}
