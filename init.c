#include <stdio.h>
#define FILENAME "student.dat"

int main(int argc, char const *argv[]) {

  FILE* fd = fopen(FILENAME, "w");
  int id = 1;
  fwrite(&id, sizeof(id), 1, fd);
  fclose(fd);

  return 0;
}
