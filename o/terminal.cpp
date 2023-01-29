#include "terminal.h"

Terminal::Terminal() {
    initscr(); //Initializes ncurses
    start_color(); //Initializes color support;
    box(stdscr, 0, 0); // Adds some borders
    this->output(getmaxx(stdscr) / 2 - 17, 1, "Welcome to the equation calculator!\n", COLOR_BLUE);
}

int Terminal::start() { //auto* ptr
    int option;
    bool active = true;

    //this->core = ptr;
    this->clear();

    do {
        this->output(5, 2, "[1] New equation", COLOR_CYAN);
        this->output(5, 3, "[2] Show equation", COLOR_CYAN);
        this->output(5, 4, "[3] Delete equation", COLOR_CYAN);
        this->output(5, 5, "[4] Exit calculator", COLOR_CYAN);
        this->input(5, 6, "Option:", &option, COLOR_YELLOW);
        this->clear();

        switch (option) {
            case 1:
                this->option_add();
                break;
            case 2:
                this->option_show();
                break;
            case 3:
                this->option_remove();
                break;
            case 4:
                active = false;
        }
    } while (active);

    //delete this->core,
    delete &option, &active;
    endwin();
    return 0;
}

//Clears the terminal
inline void Terminal::clear() {erase();}

//Prints the specified title with a bar under it
inline void Terminal::title(std::string title) {
    this->output((getmaxx(stdscr) / 2) - (title.length() / 2), 1, title, COLOR_BLUE);
    move(2, 2);
    hline('-', getmaxx(stdscr) - 2);
}

//Prints the specified string in the specified coords with the specified color
inline void Terminal::output(int x, int y, std::string s, int c = COLOR_WHITE) {
    attron(c);
    mvprintw(x, y, s.c_str());
    attroff(c);
    refresh();
}

//Gets input with a prompt printed with the output method and stores it in a pointer
template <typename T> inline void Terminal::input(int x, int y, std::string s, T* v, int c = COLOR_WHITE) { 
    this->output(x, y, s, c);
    v* = getchar();
}

inline void Terminal::option_add() {
    this->title("Create a new equation");
    /*
    Equation eq;
    std::string count;
    this->input(5, 3, "Degree:", &eq.degree, COLOR_YELLOW);
    for (int i = 0; i < eq.degree; i++) {
        count = i+1;
        this->output(5, 3 + i, "Coefficient N" + count + ":", COLOR_YELLOW);
        eq.coefficients.push_back(getchar());
    }
    delete &count;

    this->core->add(&eq);
    
    delete &eq;
    */
};

inline void Terminal::option_remove() {
    /*this->core->remove();*/
};

inline void Terminal::option_show() {
    this->title("Show all equations");
    /*
    std::vector<Equation> eqs;
    this->core->get(&eqs);

    for (int i = 0; i < eqs.size(); i++) { //Watch out!
        this->output(5, 3 + i,  "Equation " + (i+1) + ":", COLOR_CYAN);
        //Add more details and multiply i for the number of lines of detail
    }

    delete &eqs;
    */
};

int main() {
    Terminal* terminal = new Terminal();
    terminal->start();
    return 0;
}