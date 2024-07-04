#include "../main.h"

void PrintManager(struct Directory *window_list, char *home_path) {
  // ввод пользователя
  int ch = ' ';
  int current_window = LEFT_WINDOW;
  int dir_changed = 0;

  while (ch != 'q') {
    // если мы сменили директорию, то путь надо отрисовать заново и обновить
    // список объектов директории
    if (dir_changed) {
      // чистим окно (что бы избежать наложения длинных имен файлов на короткие)
      wclear(window_list[current_window].win);
      // выводим пути
      PrintPath(&window_list[current_window], home_path);
      // чистим память
      FreeDirList(&window_list[current_window]);
      // заново сканируем директорию
      window_list[current_window].dir_len =
          scandir(window_list[current_window].path,
                  &(window_list[current_window].dir_list), 0, alphasort);
      dir_changed = 0;
    }

    PrintDir(&(window_list[current_window]), home_path);
    // берем пользовательский ввод
    GetInput(&window_list[current_window], &ch, &dir_changed, &current_window);
  }
}