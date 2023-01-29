#include <iostream>
#include <string>

#include <ncurses.h>

#include "math.h"

class Terminal {
    public:
        Terminal();
        //int start(auto* ptr);
        int start();

    private:
        class {}* core;

        inline void clear();
        inline void Terminal::title(std::string title);
        inline void output(int x, int y, std::string s, int c);
        template <typename T> inline void input(int x, int y, std::string s, T* v, int c = COLOR_WHITE);

        inline void option_add();
        inline void option_remove();
        inline void option_show();
};