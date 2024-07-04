#include "../main.h"

void GetInput(struct Directory *dir, int *ch, int *dir_changed,
              int *current_window) {

  *ch = wgetch(dir->win);

  if (*ch == KEY_DOWN) {
    // возвращаемся в начало директории, если дошли до последнего элемента
    if (dir->position == dir->dir_len - 1) {
      dir->position = 0;
      // опускаем указатель ниже если иначе
    } else {
      dir->position++;
    }
  } else if (*ch == KEY_UP) {
    // переходим в конец директории, если нажали вверх в начале
    if (dir->position == 0) {
      dir->position = dir->dir_len - 1;
      // опускаем указатель выше если иначе
    } else {
      dir->position--;
    }
    // если пользователь решил перейти в папку, то меняем дриекторию
  } else if (*ch == '\n') {
    ChangeDir(dir, dir_changed);
  } else if (*ch == '\t') {
    *dir_changed = 1;
    *current_window = *current_window == LEFT_WINDOW ? RIGHT_WINDOW : LEFT_WINDOW;
  }
}