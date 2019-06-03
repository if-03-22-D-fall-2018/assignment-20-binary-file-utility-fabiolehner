#include <stdio.h>
#define FILE_NAME "students.dat"


int main(int argc, char const *argv[]) {
  FILE* fd = fopen(FILE_NAME, "a");
  fclose(fd);
  return 0;
}
