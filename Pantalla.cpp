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
    init_pair(2, COLOR_BLACK, COLOR_CYAN);
    init_pair(3, COLOR_YELLOW, COLOR_BLUE);
    WINDOW *parteSuperior = subwin(ventana, 1, MaxX, 0, 0);
    wbkgd(parteSuperior, COLOR_PAIR(2));
    mvwprintw(parteSuperior, 0, 1, "YaST @ g185");
    mvwprintw(parteSuperior, 0, MaxX - 18, "Press F1 for Help");
    int encabeadoTitulo = ((MaxX - 2) / 2) - 10;
    WINDOW *encabezado = subwin(ventana, 3, MaxX - 2, 1, 1);
    wbkgd(encabezado, COLOR_PAIR(3));
    mvwprintw(encabezado, 1, encabeadoTitulo, "YaST2 Control Center");
    box(encabezado, ACS_VLINE, ACS_HLINE);
    int longitud = (MaxX - 2) / 3;
    int distanciaEnY = MaxY / 2;
    WINDOW *segundaVentana = subwin(ventana, distanciaEnY, longitud, 6, 1);
    box(segundaVentana, ACS_VLINE, ACS_HLINE);
    mvwprintw(segundaVentana, 1, 1, "Software");
    mvwprintw(segundaVentana, 2, 1, "Hardware");
    mvwprintw(segundaVentana, 3, 1, "System");
    mvwprintw(segundaVentana, 4, 1, "Network Devices");
    mvwprintw(segundaVentana, 5, 1, "Network services");
    mvwprintw(segundaVentana, 6, 1, "Security And Users");
    mvwprintw(segundaVentana, 7, 1, "Misc");
    WINDOW *terceraVentana = subwin(ventana, distanciaEnY, MaxX - longitud - 2, 6, longitud + 1);
    box(terceraVentana, ACS_VLINE, ACS_HLINE);
    mvwprintw(terceraVentana, 1, 1, "Patch CD Update");
    mvwprintw(terceraVentana, 2, 1, "Installation into Directory");
    mvwprintw(terceraVentana, 3, 1, "Online Update");
    mvwprintw(terceraVentana, 4, 1, "Install and Remove Software");
    mvwprintw(terceraVentana, 5, 1, "Chaange source of installation");
    mvwprintw(terceraVentana, 6, 1, "System update");

    mvwprintw(ventana, MaxY - 2, 1, "[Help]");
    mvwprintw(ventana, MaxY - 2, MaxX - 8, "[Quit]");
    touchwin(ventana);
    wrefresh(ventana);
    getchar();
    endwin();
    return 0;
}