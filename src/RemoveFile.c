#include "../main.h"

void RemoveFile(struct Directory *dir) {
  char filename[FILENAME_LEN];

  chdir(dir->path);
  // если не пустое имя
  if (remove(dir->dir_list[dir->position]->d_name) != 0) {
    ShowMessage("No such file!", 3, 25, 10, 10, 5);
  }
}