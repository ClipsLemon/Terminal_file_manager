#include "../main.h"

void GetInput(struct Directory *dir, int *ch, int *dir_changed,
              int *current_window) {

  *ch = wgetch(dir->win);

  switch (*ch) {
  case KEY_DOWN:
    if (dir->position == dir->dir_len - 1) {
      dir->position = 0;
      // опускаем указатель ниже если иначе
    } else {
      dir->position++;
    }
    break;
  case KEY_UP:
    // переходим в конец директории, если нажали вверх в начале
    if (dir->position == 0) {
      dir->position = dir->dir_len - 1;
      // опускаем указатель выше если иначе
    } else {
      dir->position--;
    }
    break;
  case '\n':
    ChangeDir(dir, dir_changed);
    break;
  case '\t':
    *dir_changed = 1;
    *current_window =
        *current_window == LEFT_WINDOW ? RIGHT_WINDOW : LEFT_WINDOW;
    break;
  case KEY_F(1):
    *dir_changed = 1;
    *current_window =
        *current_window == LEFT_WINDOW ? RIGHT_WINDOW : LEFT_WINDOW;
    break;
  case KEY_F(2):
    *dir_changed = 1;
    *current_window =
        *current_window == LEFT_WINDOW ? RIGHT_WINDOW : LEFT_WINDOW;
    break;
  case KEY_F(3):
    *dir_changed = 1;
    *current_window =
        *current_window == LEFT_WINDOW ? RIGHT_WINDOW : LEFT_WINDOW;
    break;
  case KEY_F(4):
    *dir_changed = 1;
    CreateFile(dir->path);
    break;
  case KEY_F(5):
    *dir_changed = 1;
    CreateDir(dir->path);
    break;
  case KEY_F(6):
    *dir_changed = 1;
    RemoveFile(dir);
    break;
  }
}