#include <stdio.h>
#define FILENAME "student.dat"
#define MAX_SIZE 64

int main(int argc, char const *argv[]) {

  char first_name[MAX_SIZE];
  char last_name[MAX_SIZE];
  int age;
  int id;

  printf("First Name: ");
  scanf("%s", first_name);
  printf("Last Name: ");
  scanf("%s", last_name);
  printf("Age: ");
  scanf("%d", &age);


  FILE* fd = fopen(FILENAME, "r+");
  fseek(fd, 0, SEEK_SET);
  fread(&id, sizeof(id), 1, fd);

  fseek(fd, 0, SEEK_END);
  fwrite(&id, sizeof(id), 1, fd);
  fwrite(&first_name, sizeof(first_name), 1, fd);
  fwrite(&last_name, sizeof(last_name), 1, fd);
  fwrite(&age, sizeof(age), 1, fd);

  fseek(fd, 0, SEEK_SET);
  id++;
  fwrite(&id, sizeof(id), 1, fd);
  fclose(fd);

  printf("Stored succesfully\n");


  return 0;
}
