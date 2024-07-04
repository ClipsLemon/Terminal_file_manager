#include "../main.h"

void CreateFile(char *path) {
  char filename[FILENAME_LEN];

  chdir(path);
  // если не пустое имя
  GetString(filename, "Enter filename: ");
  if (strlen(filename)) {
    // если файла не существует
    if (access(filename, R_OK) != 0) {
      FILE *f = fopen(filename, "w");
      fclose(f);
    }
  }
}