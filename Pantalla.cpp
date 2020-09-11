#include <curses.h>

int main()
{
    int MaxX, MaxY;
    initscr();
    getmaxyx(stdscr, MaxY, MaxX);
    if (!has_colors())
    {
        endwin();
        return 1;
    }
    WINDOW *ventana = newwin(MaxY, MaxX, 0, 0);
    refresh();
    cbreak();
    noecho();
    nonl();
    intrflush(ventana, FALSE);
    keypad(ventana, TRUE);
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLUE);
    wbkgd(ventana, COLOR_PAIR(1));
    mvwprintw(ventana, 0, 1, "YaST @ g185");
    mvwprintw(ventana, 0, MaxX - 18, "Press F1 for Help");
    int encabeadoTitulo = ((MaxX - 2) / 2) - 10;
    WINDOW *encabezado = subwin(ventana, 3, MaxX - 2, 1, 1);
    mvwprintw(encabezado, 1, encabeadoTitulo, "YaST2 Control Center");
    box(encabezado, ACS_VLINE, ACS_HLINE);
    int longitud = (MaxX - 2) / 3;
    int distanciaEnY = MaxY - 4;
    WINDOW *segundaVentana = subwin(ventana, MaxY - 4, longitud, 6, 1);
    box(segundaVentana, ACS_VLINE, ACS_HLINE);
    WINDOW *terceraVentana = subwin(ventana, MaxY - 4, longitud * 2, 6, longitud + 1);
    box(terceraVentana, ACS_VLINE, ACS_HLINE);
    touchwin(ventana);
    wrefresh(ventana);
    //getchar();
    endwin();
    return 0;
}