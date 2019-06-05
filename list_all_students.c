#include <stdio.h>
#define FILENAME "student.dat"
#define MAX_SIZE 64

int main(int argc, char const *argv[]) {

  char first_name[MAX_SIZE];
  char last_name[MAX_SIZE];
  int age;
  int id;


  FILE* fd = fopen(FILENAME, "r");

  fseek(fd,0,SEEK_SET);
  fseek(fd,sizeof(int),SEEK_SET);

  printf("%10s %-32s %-32s %-3s\n", "Id","First Name","Last Name","Age");

  int count = fread(&id,sizeof(int),1,fd);

  while (count > 0)
  {
    fread(first_name,sizeof(first_name),1,fd);
    fread(last_name,sizeof(last_name),1,fd);
    fread(&age,sizeof(int),1,fd);
    printf("%010d %-32s %-32s %-3d\n", id,first_name,last_name,age);
    count = fread(&id,sizeof(int),1,fd);
  }
  fclose(fd);
  return 0;
}
