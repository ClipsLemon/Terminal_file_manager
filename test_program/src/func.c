#include "../main.h"

void func() {
  initscr();
  start_color();
  noecho();
  cbreak();
  curs_set(FALSE);

  int row = getmaxy(stdscr);
  int col = getmaxx(stdscr);
  char ch = ' ';

  WINDOW *win = newwin(row, col, 0, 0);
  WINDOW *swin;
  keypad(win, TRUE);

  while (1) {
    mvwprintw(win, 0, 0, "Hello world!");
    ch = wgetch(win);
    if (ch == 'c') {
      swin = subwin(win, 3, 25, 0, 3);
      box(swin, 0, 0);
      mvwprintw(swin, 1, 1, "KEY      WAS PRESSED");
      wrefresh(swin);
      sleep(5);
      delwin(swin);
    }
    wrefresh(win);
  }

  endwin(); // завершение работы с ncurses
}