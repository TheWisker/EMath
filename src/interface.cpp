/**
* @file interface.cpp
* @brief This file contains the text user interface for the emath library
* @details It contains an efc namespace with all the implementations inside\n
* It comes with the capability to do arithmetic operations with polynomials, parse polynomials,\n
* solve polynomials, evaluate polynomials and graphically represent polynomials.
**/
#ifndef INTERFACE_H
#define INTERFACE_H
#include <curses.h> 
#include <fstream>
#include <string>
#include <vector>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <SFML/Graphics.hpp>
#include <thread>
#include "emath.h"
#include "eparser.h"
#include "font.h"
#ifdef WINDOWS
    #include <windows.h>
#else
    #include <signal.h>
#endif
/**
 * @namespace efc
 * @brief Englobes all the classes and functions of the emath text user interface
 * @details The emth namespace contains the following classes: Window, IWindow, OWindow, Terminal, Plane, Storage, Lexer, Parser and Application.
**/
namespace efc {
    #define HPADD 1
    #define WPADD 2
    #define CPOSY 1
    #define CPOSX 2
    #define PSIZE 3
    #define TOFST 2
    #define COLOR_ID 1
    #define KEY_ESC 27
    #define KEY_TAB 9
    #define KEY_SPC 32
    #define KEY_E 101
    #define KEY_Q 113
    #define KEY_1 49
    #define KEY_2 50
    #define KEY_3 51
    #define KEY_4 52
    #define KEY_5 53
    #define LWIN 0
    #define RWIN 1
    #define BWIN 2
    #define SG_FILE "polynomials.json"
    /**
     * @class Window
     * @brief Generic class for wrapping a curses WINDOW
     * @details It wraps a curses WINDOW in a way that lets it manage some centralized structure.
    **/
    class Window {
        protected:
            /**
            * @brief Two booleans: c for knowing if contents changed, and a for knowing if window is active
            **/
            bool c, a;
            /**
            * @brief String t: window title
            **/
            ::std::string t;
            /**
            * @brief Four unsigned ints: x and y for the coordinates relative to the console window, w and h for the size of the window
            **/
            unsigned int y, x, h, w;
        public:
            /**
            * @brief Pointer to the curses WINDOW object
            **/
            WINDOW* o;
            /**
            * @brief Generic constructor with default values
            **/
            Window() noexcept : c(true), a(false), y(0), x(0), h(0), w(0), o(newwin(0, 0, 0, 0)) {keypad(this->o, TRUE); return;}
            /**
            * @brief Returns the c_str() const char pointer of the title std::string
            * @return (const char*) The title as a char array
            **/
            const char* get_title() const noexcept {return this->t.c_str();}
            /**
            * @brief Returns the y coordinate
            * @return (const unsigned int&) The y coordinate as a const unsigned int&
            **/
            const unsigned int& get_y() const noexcept {return this->y;}
            /**
            * @brief Returns the x coordinate
            * @return (const unsigned int&) The x coordinate as a const unsigned int&
            **/
            const unsigned int& get_x() const noexcept {return this->x;}
            /**
            * @brief Returns the height value
            * @return (const unsigned int&) The height value as a const unsigned int&
            **/
            const unsigned int& get_height() const noexcept {return this->h;}
            /**
            * @brief Returns the width value
            * @return (const unsigned int&) The width value as a const unsigned int&
            **/
            const unsigned int& get_width() const noexcept {return this->w;}
            /**
            * @brief Returns the title size
            * @return (const unsigned int) The title size as a const unsigned int
            **/
            const unsigned int get_title_size() const noexcept {return this->t.size();}
            /**
            * @brief Sets the title
            * @param title The title as a cons std::string&&
            **/
            void set_title(const ::std::string&& title) noexcept {this->t = title; this->c = true; return;}
            /**
            * @brief Sets the y and x coordinates
            * @param y The y coordinate as a const unsigned int y
            * @param x The x coordinate as a const unsigned int x
            **/
            void set_coords(const unsigned int y, const unsigned int x) noexcept {this->y = y; this->x = x; this->c = true; return;}
            /**
            * @brief Sets the size
            * @param h The height as a const unsigned int y
            * @param w The width as a const unsigned int x
            **/
            void set_size(const unsigned int h, const unsigned int w) noexcept {this->h = h; this->w = w; this->c = true; return;}
            /**
            * @brief Sets the active boolean to the provided value
            * @param active If it is a active as a const boolean
            **/
            void set_active(const bool active) noexcept {if (this-> a != active) {this->a = active; this->c = true;} return;}
            /**
            * @brief Gets the title y coordinate
            * @return (const unsigned int) The title y coordinate as a const unsigned int
            **/
            virtual const unsigned int get_title_y() const noexcept {return 0;}
            /**
            * @brief Gets the title x coordinate
            * @return (const unsigned int) The title x coordinate as a const unsigned int
            **/
            virtual const unsigned int get_title_x() const noexcept {return 0;}
            /**
            * @brief Gets if the window needs a redraw
            * @return (const bool) True if the window should be redrawed, false otherwise
            **/
            const bool needs_update() noexcept {if (this->c) {this->c = false; return true;} return false;}
            /**
            * @brief Gets if the window is active/focused
            * @return (const bool) True if the window is active, false otherwise
            **/
            const bool is_active() const noexcept {return this->a;}
            /**
            * @brief Deletes the WINDOW pointer and creates a new WINDOW at the class coordinates
            **/
            void place() {wclear(this->o); wrefresh(this->o); delwin(this->o); this->o = newwin(this->h, this->w, this->y, this->x); keypad(this->o, TRUE); return;}
            /**
            * @brief Calls curses delwin() function on the curses WINDOW object and returns
            **/
            virtual ~Window() noexcept {delwin(this->o); return;}
    };
    /**
     * @class OWindow
     * @extends Window
     * @brief Window class extension for output
     * @details Window class implementation that focuses on showin data. Comes with the ability to scroll through an std::vector of std::string
    **/
    class OWindow : public Window {
        private:
            /**
            * @brief The scroll index as the first visible element index
            **/
            unsigned int s; //Scroll index
            /**
            * @brief The data vector, a std::vector of std::string
            **/
            ::std::vector<::std::string> d; // Data vector
        public:
            /**
            * @brief Default constructor
            **/
            OWindow() noexcept : Window(), s(0) {return;}
            /**
            * @brief Gets if the scroll index
            * @return (const unsigned int&) The scroll index as a const unsigned int&
            **/
            const unsigned int& get_scroll_index() const noexcept {return this->s;}
            /**
            * @brief Gets the data vector
            * @return (const ::std::vector<::std::string>&) The data vector as a const ::std::vector<::std::string>&
            **/
            const ::std::vector<::std::string>& get_data() const noexcept {return this->d;}
            /**
            * @brief Gets the data vector size
            * @return (const unsigned int) The data vector size as a const unsigned int
            **/
            const unsigned int get_data_size() const noexcept {return this->d.size();}
            /**
            * @brief Gets the title y coordinate
            * @return (const unsigned int) The title y coordinate as a const unsigned int
            **/
            const unsigned int get_title_y() const noexcept override {return 1;}
            /**
            * @brief Gets the title x coordinate
            * @return (const unsigned int) The title x coordinate as a const unsigned int
            **/
            const unsigned int get_title_x() const noexcept override {return (((this->w / 2) - (this->t.size() / 2)) > 2) ? ((this->w / 2) - (this->t.size() / 2)) : 3;}
            /**
            * @brief Sets the data vector
            * @param data The data vector to replace with
            **/
            void set_data(::std::vector<::std::string>&& data) noexcept {this->d = data; this->c = true; return;}
            /**
            * @brief Scrolls up, internally substracts from the scroll index within certain bounds
            **/
            void scroll_up() noexcept {if (this->s > 0) {this->s--;} this->c = true; return;}
            /**
            * @brief Scrolls down, internally adds to the scroll index within certain bounds
            **/
            void scroll_down() noexcept {if (this->s < (this->d.size() - this->h + (HPADD * 2) + 1)) {this->s++;} this->c = true; return;}
            /**
            * @brief Default destructor
            **/
            ~OWindow() noexcept = default;
    };
    /**
     * @class IWindow
     * @extends Window
     * @brief Window class extension for input
     * @details Window class implementation that focuses on showin data.
    **/
    class IWindow : public Window {
        public:
            /**
            * @brief Default constructor
            **/
            IWindow() noexcept : Window() {return;}
            /**
            * @brief Gets the title y coordinate
            * @return (const unsigned int) The title y coordinate as a const unsigned int
            **/
            const unsigned int get_title_y() const noexcept override {return 1;}
            /**
            * @brief Gets the title x coordinate
            * @return (const unsigned int) The title x coordinate as a const unsigned int
            **/
            const unsigned int get_title_x() const noexcept override {return 4;}
            /**
            * @brief Default destructor
            **/
            ~IWindow() noexcept = default;
    };
    /**
     * @class Terminal
     * @brief Terminal class to manage the terminal through curses
     * @details It works as a singleton. Not generic in any way.
    **/
    class Terminal {
        private:
            /**
            * @brief Singleton Terminal instance pointer
            **/
            static Terminal* instance;
            /**
            * @brief Pointers to all the Windows as the parent class
            **/
            Window *lwin, *rwin, *bwin;
            /**
            * @brief Single constructor wich initializes curses, creates the Windows, adds the resize signal and computes the bounds
            **/
            Terminal() {
                this->launch(); //Launch curses
                this->lwin = new OWindow; this->rwin = new OWindow; this->bwin = new IWindow;
                #ifndef WINDOWS
                    signal(SIGWINCH, Terminal::resize);
                #endif
                this->bwin->set_active(true);
                this->cbounds();
                return;
            }
            /**
            * @brief Function with the single task of computing the Terminal bounds and the bounds of the Windows
            **/
            void cbounds() {
                unsigned int height, width;
                getmaxyx(stdscr, height, width);
                this->bwin->set_size(PSIZE, width - (WPADD * 2));
                this->lwin->set_size(height - (HPADD * 3) - this->bwin->get_height(), (width / 2) - (WPADD * 1.5));
                this->rwin->set_size(this->lwin->get_height(), this->lwin->get_width());
                this->bwin->set_coords(height - (HPADD + this->bwin->get_height()), WPADD);
                this->lwin->set_coords(HPADD, WPADD);
                this->rwin->set_coords(HPADD, (WPADD * 2) + this->lwin->get_width());
                this->lwin->place(); this->rwin->place(); this->bwin->place();
                bkgd(COLOR_PAIR(COLOR_ID)); refresh();
                this->flush();
                return;
            }
            /**
            * @brief Private function that flushes one Window to the Terminal
            * @param win The Window reference to flush
            **/
            static void wflush(Window*& win) {
                if (win->needs_update()) {
                    wclear(win->o);
                    box(win->o, 0, 0);
                    wbkgd(win->o, COLOR_PAIR(COLOR_ID));
                    wmove(win->o, win->get_title_y(), win->get_title_x()); 
                    wattron(win->o, A_BOLD); waddnstr(win->o, win->get_title(), win->get_width() - (WPADD * 2) - 2); wattroff(win->o, A_BOLD);
                    if (const OWindow *owin = dynamic_cast<OWindow *>(win)) {//Checks if instance of OWindow
                        for (unsigned int i = owin->get_scroll_index(); i < ((owin->get_height() - 3 >= owin->get_data_size()) ? owin->get_data_size() : owin->get_height() - 3 - HPADD * 2) + owin->get_scroll_index(); i++) {
                            wmove(owin->o, i+2 - owin->get_scroll_index() + HPADD, 1 + TOFST); waddnstr(owin->o, owin->get_data()[i].c_str(), owin->get_width() - 2 - TOFST);
                        }
                    }
                    if (win->is_active()) {wmove(win->o, CPOSY, CPOSX); wattron(win->o, A_BOLD | A_BLINK); waddch(win->o, '>'); wattroff(win->o, A_BOLD | A_BLINK);}
                    wrefresh(win->o);
                } return;
            }
            /**
            * @brief Resize handler called on Terminal resize
            * @param signal The id of the calling signal
            **/
            static inline void resize(int signal) {endwin(); refresh(); Terminal::instance->cbounds(); return;}
            #ifdef WINDOWS
            /**
            * @brief WindowProc function for Windows Terminal resizing (Windows_Exclusive)
            **/
            static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
                switch (uMsg) {
                    case WM_SIZE: Terminal::resize(0); break;
                    case WM_CLOSE: PostQuitMessage(0); break;
                    default: return DefWindowProc(hwnd, uMsg, wParam, lParam);
                } return 0;
            }
            #endif         
            /**
            * @brief Static function that groups all the curses procedure for launching the Terminal
            **/
            static inline void launch() {
                initscr(); curs_set(2); start_color(); cbreak(); keypad(stdscr, TRUE); noecho();
                init_pair(COLOR_ID, COLOR_YELLOW, COLOR_BLACK); 
                #ifdef WINDOWS 
                    HWND hwnd = GetConsoleWindow();
                    SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR)WindowProc);
                #else
                    set_escdelay(0);
                #endif
                return;
            }
        public:
            /**
            * @brief Static function for building the singleton static instance
            * @return (Terminal*) The singleton instance pointer also stored at Terminal::instance
            **/
            static Terminal* init() noexcept {
                if (Terminal::instance != nullptr) {delete Terminal::instance;}
                return Terminal::instance = new Terminal();
            }
            /**
            * @brief Function for flushin all the Terminal's Windows
            **/
            inline void flush() {Terminal::wflush(this->lwin); Terminal::wflush(this->rwin); Terminal::wflush(this->bwin); wmove(this->bwin->o, this->bwin->get_title_y(), this->bwin->get_title_x() + this->bwin->get_title_size()); return;}
            /**
            * @brief Function for setting the title of the left Window
            * @param title The title as a std::string
            **/
            void set_ltitle(const ::std::string title) noexcept {this->lwin->set_title(::std::move(title)); return;}
            /**
            * @brief Function for setting the title of the right Window
            * @param title The title as a std::string
            **/
            void set_rtitle(const ::std::string title) noexcept {this->rwin->set_title(::std::move(title)); return;}
            /**
            * @brief Function for setting the prompt of the bottom Window
            * @param prompt The prompt as a std::string
            **/
            void set_prompt(const ::std::string prompt) noexcept {this->bwin->set_title(::std::move(prompt)); return;}
            /**
            * @brief Function for setting data vector of the left Window
            * @param data The data as a std::vector of std::string
            **/
            void set_ldata(::std::vector<::std::string> data) noexcept {dynamic_cast<OWindow *>(this->lwin)->set_data(::std::move(data)); return;}
            /**
            * @brief Function for setting data vector of the right Window
            * @param data The data as a std::vector of std::string
            **/
            void set_rdata(::std::vector<::std::string> data) noexcept {dynamic_cast<OWindow *>(this->rwin)->set_data(::std::move(data)); return;}
            /**
            * @brief Function for getting short single char input from the Terminal
            * @return (const int) Int representing the pressed key
            **/
            const int get_short_input() const {wmove(this->bwin->o, this->bwin->get_title_y(), this->bwin->get_title_x() + this->bwin->get_title_size()); return wgetch(this->bwin->o);}
            /**
            * @brief Function for getting long single string input from the Terminal
            * @return (::std::string) The input as a std::string
            **/
            const ::std::string get_long_input() const {char* buffer = new char(); echo(); wmove(this->bwin->o, this->bwin->get_title_y(), this->bwin->get_title_x() + this->bwin->get_title_size()); wgetnstr(this->bwin->o, buffer, this->bwin->get_width() - (this->bwin->get_title_x() + this->bwin->get_title_size()) - WPADD - 1); noecho(); return ::std::move(buffer);}
            /**
            * @brief Function for scrolling down the left or right window depending on the provided id
            * @param id The id of the window as a const unsigned int
            **/
            void scroll_down(const unsigned int id) noexcept {
                switch (id) {
                    case LWIN: dynamic_cast<OWindow *>(this->lwin)->scroll_down(); break;
                    case RWIN: dynamic_cast<OWindow *>(this->rwin)->scroll_down(); break;
                } return;
            }
            /**
            * @brief Function for scrolling up the left or right window depending on the provided id
            * @param id The id of the window as a const unsigned int
            **/
            void scroll_up(const unsigned int id) noexcept {
                switch (id) {
                    case LWIN: dynamic_cast<OWindow *>(this->lwin)->scroll_up(); break;
                    case RWIN: dynamic_cast<OWindow *>(this->rwin)->scroll_up(); break;
                } return;
            }
            /**
            * @brief Echoes the provided result to the prompt and waits for a key press
            * @param result The result to echo as a const ::std::string&
            **/
            void echo_result(const ::std::string& result) {
                const ::std::string old_title = this->bwin->get_title(); this->set_prompt("Result:"); this->flush();
                wmove(this->bwin->o, this->bwin->get_title_y(), this->bwin->get_title_x() + this->bwin->get_title_size());
                waddnstr(bwin->o, result.c_str(), this->bwin->get_width() - (this->bwin->get_title_x() + this->bwin->get_title_size()) - WPADD - 1);
                wgetch(bwin->o); this->set_prompt(old_title);
                return;
            }
            /**
            * @brief Swaps the active window to the one matching the provide id
            * @param id The id of the window as a const unsigned int
            **/
            void swap_active(const unsigned int id) noexcept {
                #define swp(l, r, b) this->lwin->set_active(l); this->rwin->set_active(r); this->bwin->set_active(b);
                switch(id) {
                    case LWIN: swp(true, false, false); break;
                    case RWIN: swp(false, true, false); break;
                    case BWIN: swp(false, false, true); break;
                } return;
            }
            /**
            * @brief Default destructor, it deletes the Window pointers, sets the singleton instance to nullptr, stops the signal listener and stops curses
            **/
            ~Terminal() noexcept {
                delete this->lwin; delete this->rwin; delete this->bwin;
                Terminal::instance = nullptr;
                #ifndef WINDOWS 
                    signal(SIGWINCH, SIG_DFL);
                #endif
                endwin(); return;
            }
    }; Terminal* Terminal::instance = nullptr;
    /**
     * @class Plane
     * @brief Plane class to draw a function in the Cartesian plane
     * @details Provides the capability to run multiple Planes in different threads in paralell
    **/
    class Plane {
        private:
            /**
            * @brief The x and y offsets where the drawing starts
            **/
            int xogn, yogn;
            /**
            * @brief The original x and y offsets first provided on instantiation
            **/
            const int _xogn, _yogn;
            /**
            * @brief The domain and image of the Cartesian plane visible
            **/
            unsigned int domain, image;
            /**
            * @brief The function to draw
            **/
            ::emth::Polynomial function;
            /**
            * @brief The sf::Font for the coordinate tooltip
            **/
            ::sf::Font font;
            /**
            * @brief The sf::Text coordinate tooltip
            **/
            ::sf::Text tooltip;
            /**
            * @brief The sf::VertexArray that contains the Cartesian plane axes
            **/
            ::sf::VertexArray axes;
            /**
            * @brief The sf::RenderWindow where everything gets drawed
            **/
            ::sf::RenderWindow window;
            /**
            * @brief The sf::RectangleShape vertical line that follows the mouse
            **/
            ::sf::RectangleShape line;
            /**
            * @brief The sf::CircleShape that gets drawed on the intersection between the line and the function
            **/
            ::sf::CircleShape intersection;
            /**
            * @brief The sf::VertexArray that contains the points of the function for drawing
            **/
            ::sf::VertexArray representation;
            /**
            * @brief This function draws one frame per call of the Plane
            **/
            void draw() {
                this->window.clear(::sf::Color::Black);
                this->window.draw(this->axes);
                this->window.draw(this->line);
                this->window.draw(this->representation);
                this->window.draw(this->intersection);
                this->window.draw(this->tooltip);
                this->window.display(); return;
            }
            /**
            * @brief This function populates the representation with the function image in the current domain
            **/
            void populate() {
                const int end = (this->xogn + this->domain);
                this->axes[0].position = ::sf::Vector2f(0, -this->yogn);
                this->axes[1].position = ::sf::Vector2f(this->domain, -this->yogn);
                this->axes[2].position = ::sf::Vector2f(-this->xogn, 0);
                this->axes[3].position = ::sf::Vector2f(-this->xogn, this->image);
                for (int x = this->xogn; x < end; x++) {
                    this->representation[(x - this->xogn)].position = ::sf::Vector2f((x - this->xogn), (-this->yogn - this->function.get_value(x)));
                    this->representation[(x - this->xogn)].color = ::sf::Color::Red;
                } return;
            }
            /**
            * @brief This function resizes the Plane window and all the primitives that need to also be resized
            * @param event The sf::Event object that represents the resizing event
            **/
            void resize(const ::sf::Event& event) {
                this->domain = ::std::min(event.size.width, ::sf::VideoMode::getDesktopMode().width); this->image = ::std::min(event.size.height, ::sf::VideoMode::getDesktopMode().height);
                this->window.setSize(::sf::Vector2u(this->domain, this->image)); this->representation = ::sf::VertexArray(::sf::LineStrip, this->domain); this->line.setSize(::sf::Vector2f(1, this->image));
                this->window.setView(::sf::View(::sf::FloatRect(0, 0, this->domain, this->image)));
                this->populate(); return;
            }
            /**
            * @brief This function inverts a int
            * @param n The int to be inverted
            * @return (int) The inverted int
            **/
            static constexpr inline int inverse(const int& n) noexcept {return ((n != 0) ? -n : n);}
        public:
            /**
            * @brief The main constructor
            * @param ox The x offset
            * @param oy The y offset
            * @param func The function to be drawed
            **/
            Plane(int ox, int oy, const ::emth::Polynomial& func) : xogn(ox), yogn(oy), _xogn(ox), _yogn(oy), domain(::sf::VideoMode::getDesktopMode().width/2), image(::sf::VideoMode::getDesktopMode().height/2), function(func), window(::sf::VideoMode(::sf::VideoMode::getDesktopMode().width/2, ::sf::VideoMode::getDesktopMode().height/2), "Polynomial: " + func.get_expression(), ::sf::Style::Titlebar | ::sf::Style::Close, ::sf::ContextSettings(0, 0, 16, 1, 1, 0, false)), axes(::sf::Lines, 4), representation(::sf::LineStrip, ::sf::VideoMode::getDesktopMode().width/2), line(::sf::Vector2f(1, ::sf::VideoMode::getDesktopMode().height/2)), intersection(5/2) {
                this->window.setVerticalSyncEnabled(true);
                this->font.loadFromMemory(ROBOTO_BOLD, sizeof(ROBOTO_BOLD));
                tooltip.setFont(this->font); this->tooltip.setCharacterSize(16); this->tooltip.setFillColor(::sf::Color::White);
                this->axes[0].color = this->axes[1].color = this->axes[2].color = this->axes[3].color = ::sf::Color::White;
                this->line.setFillColor(::sf::Color::Yellow); this->intersection.setFillColor(::sf::Color::Blue); this->intersection.setPointCount(25);
                return;
            }
            /**
            * @brief Runs the main application loop, processing events
            **/
            void run() {
                while(this->window.isOpen()) {
                    ::sf::Event event; ::std::stringstream ts;
                    while (window.pollEvent(event)) {
                        switch(event.type) {
                            case ::sf::Event::Closed: this->window.close(); break;
                            case ::sf::Event::MouseMoved: 
                                this->line.setPosition(event.mouseMove.x, 0); 
                                this->intersection.setPosition(event.mouseMove.x - this->intersection.getRadius(), this->representation[event.mouseMove.x].position.y - this->intersection.getRadius());
                                ts = ::std::stringstream(); ts << "(" << event.mouseMove.x + this->xogn << "," << inverse(this->representation[event.mouseMove.x].position.y + this->yogn) << ")"; tooltip.setString(ts.str());
                                tooltip.setPosition(event.mouseMove.x + 10, this->representation[event.mouseMove.x].position.y);
                                break;
                            case ::sf::Event::KeyPressed: 
                                switch(event.key.code) {
                                    case ::sf::Keyboard::Up: this->yogn -= this->window.getSize().y/100; break;
                                    case ::sf::Keyboard::Down: this->yogn += this->window.getSize().y/100; break;
                                    case ::sf::Keyboard::Right: this->xogn += this->window.getSize().x/100; break;
                                    case ::sf::Keyboard::Left: this->xogn -= this->window.getSize().x/100; break;
                                    case ::sf::Keyboard::Space: this->xogn = this->_xogn; this->yogn = this->_yogn; break;
                                } this->populate(); break;
                            case ::sf::Event::Resized: this->resize(event); break;
                        }
                    } this->draw();
                } return;
            }
    };
    /**
     * @class Storage
     * @brief Storage class to read and write to a file
     * @details Provides some functions to read and write to a filename saved in a class variable
    **/
    class Storage {
        private:
            /**
            * @brief The filename to write to as a  std::string
            **/
            const ::std::string filename;
        public:
            /**
            * @brief The main constructor
            * @param file The filename to write to as a std::string
            **/
            Storage(const ::std::string file) noexcept : filename(::std::move(file)) {return;}
            /**
            * @brief The read function that returns the whole file as a std:.string
            * @return (const ::std::string) The whole file as a std:.string
            **/
            const ::std::string read() const noexcept {
                try {
                    ::std::ifstream file(this->filename);
                    if (!file.is_open()) {throw ::std::runtime_error("Input file does not exist");}
                    ::std::string contents((::std::istreambuf_iterator<char>(file)), ::std::istreambuf_iterator<char>());
                    file.close(); return contents;
                } catch(const ::std::exception& e) {return "";}
            }
            /**
            * @brief The write function that overwrites the whole file with a std::string
            * @param contents The contents to write as a std::string
            * @return (int) 0 If successful, 1 otherwise
            **/
            const int write(const ::std::string contents) const noexcept {
                try {
                    ::std::ofstream file(this->filename, ::std::ios::out | ::std::ios::trunc);
                    file << contents; file.close(); return 0;
                } catch (const ::std::exception& e) {return 1;}
            }
            /**
            * @brief This function check if the filename exists
            * @return (bool) True if the file exists, false otherwise
            **/
            bool exists() const noexcept {
                try {
                    ::std::ifstream file(this->filename);
                    if (!file.is_open()) {return false;}
                    file.close(); return true;
                } catch(const ::std::exception& e) {return false;}
            }
            /**
            * @brief Default destructor
            **/
            ~Storage() noexcept = default;
    };
    /**
     * @enum TokenType
     * @brief Enum with all the possible Token types
    **/
    enum TokenType {
        /**
         * @brief Number type
        **/
        T_NUMBER,
        /**
         * @brief Plus sign type
        **/
        T_PLUS,
        /**
         * @brief Minus sign type
        **/
        T_MINUS,
        /**
         * @brief Multiplication sign type
        **/
        T_MULTIPLICATION,
        /**
         * @brief Division sign type
        **/
        T_DIVISION,
        /**
         * @brief End of file type
        **/
        T_EOF
    };
    /**
     * @struct Token
     * @brief Struct for representing a token as a type and a value
    **/
    struct Token {
        /**
         * @brief The token's type as a TokenType
        **/
        const TokenType type;
        /**
         * @union value
         * @brief A union representing the value of the Token as a char or as a int
        **/
        union {char c; int n;} value;
    };
    /**
     * @class Lexer
     * @brief Class that works as a token supplier for the Parser class
     * @details The class consists of a public function for getting the next Token
    **/ 
    class Lexer {
        private:
            /**
            * @brief The provided input as a private std::string
            **/
            const ::std::string _input;
            /**
            * @brief Private long unsigned int that represents the cursor's position
            **/
            short unsigned int _pos;
            /**
            * @brief Private static function that cleans the input string of the unexpected characters
            * @param input The string to clean.
            * @return (std::string) The clean output
            **/
            static const ::std::string clean(const std::string& input) noexcept {
                short unsigned int pos = 0; ::std::string result;
                while (pos < input.size()) {
                    switch (input[pos]) {
                        case '+': result += '+'; break;
                        case '-': result += '-'; break;
                        case '*': result += '*'; break;
                        case '/': result += '/'; break;
                        default: if (Lexer::is_integer(input[pos])) {result += input[pos];} break;
                    } pos++;
                } return result;
            }
            /**
            * @brief Miscellaneous private function that checks if a char is an integer
            * @param c The char to check if it is an integer.
            * @return (true) If the char is an integer
            * @return (false) If the char is not an integer
            **/
            static constexpr inline bool is_integer(const char& c) noexcept {return (c >= '0' && c <= '9');}
        public:
            /**
            * @brief Standalone constructor for the Lexer class
            * @param input A const reference to the std::string to tokenize.
            **/
            Lexer(const std::string& input) noexcept : _input(Lexer::clean(input)), _pos(0) {}
            /**
            * @brief Function that returns the next Token in the input provided in the constructor
            * @return (Token) The next Token in the input
            **/
            const Token next() noexcept {
                if (this->_pos >= this->_input.size()) {return {TokenType::T_EOF, {0}};}
                switch (this->_input[this->_pos]) {
                    case '+': this->_pos++; return {TokenType::T_PLUS, {0}};
                    case '-': this->_pos++; return {TokenType::T_MINUS, {0}};
                    case '*': this->_pos++; return {TokenType::T_MULTIPLICATION, {0}};
                    case '/': this->_pos++; return {TokenType::T_DIVISION, {0}};
                    default: this->_pos++; return {TokenType::T_NUMBER, {(char) this->_input[this->_pos - 1]}};
                }
            }
            /**
            * @brief Default destructor
            **/
            ~Lexer() noexcept = default;
    };
    /**
     * @class Parser
     * @brief Class that wraps a std::string and parses it as a number or as a operation
     * @details The class consists of two public functions, one for parsing the entire input as a number and the other for it as a operation.
    **/
    class Parser {
        private:
            /**
            * @brief Private Lexer instance for supplying tokens
            **/
            Lexer _lexer;
        public:
            /**
            * @brief Standalone constructor for the Parser class
            * @param input A const reference to the std::string to parse when needed.
            **/
            Parser(const std::string& input) noexcept : _lexer(input) {}
            /**
            * @brief Function for parsing a plus, minus and number Tokens as a positive or negative int
            * @return (int) The parsed number
            **/
            const int parse_number() noexcept {
                bool positive = true;
                ::std::string buffer = "0";
                while (true) {
                    const Token token = this->_lexer.next();
                    switch (token.type) {
                        case TokenType::T_MINUS: positive = !positive; break;
                        case TokenType::T_NUMBER: buffer += token.value.c; break;
                        case TokenType::T_EOF: return positive ? std::stoi(buffer) : -1 * std::stoi(buffer);
                    }
                }
            }
            /**
            * @brief Function for parsing std::string as a mathematical operation consisting of Polynomials represented as integers
            * @param ps A std::vector of Polynomials, the integers representing the Polynomials map to this std::vector indexes
            * @return (emth::Polynomial) The parsed polynomial resulting of the operation
            **/
            const emth::Polynomial parse_operation(const ::std::vector<emth::Polynomial>& ps) {
                bool hook = false;
                std::vector<emth::Polynomial> data; std::vector<TokenType> operations;
                while (true) {
                    const Token token = this->_lexer.next();
                    if (token.type == TokenType::T_EOF) {break;}
                    switch (token.type) {
                        case TokenType::T_NUMBER: if (!hook && (unsigned int) std::stoi(std::string(1, token.value.c)) < ps.size()) {data.push_back(ps[std::stoi(std::string(1, token.value.c))]); hook = true;} break;
                        default: if (hook) {operations.push_back(token.type); hook = false;} break;
                    }
                }
                for (unsigned int i = 0; i < operations.size(); i++) {
                    if (operations[i] == TokenType::T_MULTIPLICATION || operations[i] == TokenType::T_DIVISION) {
                        switch (operations[i]) {
                            case TokenType::T_MULTIPLICATION: data[i] *= data[i + 1]; break;
                            case TokenType::T_DIVISION: data[i] /= data[i + 1]; break;
                        } data.erase(data.begin() + i + 1); operations.erase(operations.begin() + i); i--;
                    }
                }
                for (unsigned int i = 0; i < operations.size(); i++) {
                    switch (operations[i]) {
                        case TokenType::T_PLUS: data[i] += data[i + 1]; break;
                        case TokenType::T_MINUS: data[i] -= data[i + 1]; break;
                    } data.erase(data.begin() + i + 1); operations.erase(operations.begin() + i); i--;
                } return data[0];
            }
            /**
            * @brief Default destructor
            **/
            ~Parser() noexcept = default;
    };
    /**
     * @class Application
     * @brief Class that contains the application inner logic
     * @details The class consist of some menus as loops and all the logic of the Application
    **/
    class Application {
        private:
            #define V_MENU {::std::string("[ESC] Exit program"), ::std::string("[TAB] Cycle focus"), ::std::string("[E] Add polynomial"), ::std::string("[Q] Remove polynomial"), ::std::string("[SPACE] New operation")}
            #define V_OPERATION {::std::string("[ESC] Back"), ::std::string("[TAB] Cycle focus"), ::std::string("[1] Evaluate operation"), ::std::string("[2] Derivative operation"), ::std::string("[3] Integral operation"), ::std::string("[4] Root finding operation"), ::std::string("[5] Drawing operation"), ::std::string("[SPACE] Arithmetic operations")}
            #define V_SCROLL {::std::string("[ESC] Exit program"), ::std::string("[UP ARROW] Scroll up"), ::std::string("[DOWN ARROW] Scroll down")}
            /**
            * @brief Singleton Application instance pointer
            **/
            static Application* instance;
            /**
            * @brief Singleton Terminal instance pointer
            **/
            Terminal* terminal;
            /**
            * @brief The Storage object for writing the JSON file containing the saved Polynomials
            **/
            const Storage storage;
            /**
            * @brief The rapidjson::Document representing the JSON array of Polynomials
            **/
            rapidjson::Document json;
            /**
            * @brief The std::vector of the currently saved Polynomials
            **/
            ::std::vector<emth::Polynomial> polynomials;
            /**
            * @brief The id of the active Window
            **/
            unsigned int active;
            /**
            * @brief Default constructor with default values
            **/
            Application() noexcept : terminal(Terminal::init()), storage(Storage(SG_FILE)), active(BWIN) {
                if (!this->storage.exists()) {this->json.SetArray();} else {this->json.Parse(this->storage.read().c_str()); this->read_json();}
                this->terminal->set_ltitle("<Main menu>");
                this->terminal->set_rtitle("<Polynomials>");
                this->terminal->set_prompt("Option:");
                this->terminal->set_rdata(this->stringify_polynomials());
                return;
            }
            /**
            * @brief Function for saving JSON to the Storage object
            * @return (const int) 0 If susccessful, 1 otherwise
            **/
            const int save_json() const noexcept {
                try {
                    rapidjson::StringBuffer buffer;
                    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
                    this->json.Accept(writer);
                    this->storage.write(buffer.GetString());
                } catch (::std::exception& e) {return 1;} return 0;
            }
            /**
            * @brief Function for retrieving JSON from the Storage object
            * @return (const int) 0 If susccessful, 1 otherwise
            **/
            const int read_json() noexcept {
                try {
                    if (this->json.IsArray()) {
                        for (const auto& o : this->json.GetArray()) {
                            if (o.IsString()) {this->polynomials.push_back(emthp::Parser(o.GetString()).parse_polynomial());}
                        }
                    }
                } catch (::std::exception& e) {return 1;} return 0;
            }
            /**
            * @brief Function for cycling the Window focus
            * @return (const int) 0 If bottom window active, 1 otherwise
            **/
            const int cycle_focus() noexcept {
                #define swpa(o) this->active = o; this->terminal->swap_active(o);
                switch(this->active) {
                    case LWIN: swpa(RWIN); return 1;
                    case RWIN: swpa(BWIN); break;
                    case BWIN: swpa(LWIN); return 1;
                } return 0;
            }
            /**
            * @brief Scroll menu as a loop
            * @return (const int) 0 If exit triggered, 1 otherwise
            **/
            const int scroll_loop() noexcept {
                this->terminal->set_ldata(V_SCROLL);
                this->terminal->flush();
                while(true) {
                    switch(this->terminal->get_short_input()) {
                        case KEY_ESC: return 0;
                        case KEY_TAB: return 1;
                        case KEY_UP: this->terminal->scroll_up(this->active); break;
                        case KEY_DOWN: this->terminal->scroll_up(this->active); break;
                    } this->terminal->flush();
                } return 0;
            }
            /**
            * @brief Function for retrieving a Polynomial from Terminal input
            * @return (const int) 0 If susccessful, 1 otherwise
            **/
            const int get_polynomial() noexcept {
                try {
                    this->terminal->set_prompt("Polynomial:"); this->terminal->flush();
                    const emth::Polynomial polynomial(emthp::Parser(this->terminal->get_long_input()).parse_polynomial());
                    this->add_polynomial(polynomial);
                } catch (::std::exception& e) {return 1;} 
                this->terminal->set_prompt("Option:"); return 0;
            }
            /**
            * @brief Function for adding a Polynomial to the Application instance
            * @return (const int) 0 If susccessful, 1 otherwise
            **/
            const int add_polynomial(const emth::Polynomial& polynomial) noexcept {
                try {
                    this->json.PushBack(rapidjson::Value(polynomial.get_expression().c_str(), this->json.GetAllocator()).Move(), this->json.GetAllocator());
                    this->polynomials.push_back(::std::move(polynomial));
                    this->terminal->set_rdata(this->stringify_polynomials());
                    this->save_json();
                } catch (::std::exception& e) {return 1;} 
                return 0;
            }
            /**
            * @brief Function for removing a Polynomial from the Application instance
            * @return (const int) 0 If susccessful, 1 otherwise
            **/
            const int remove_polynomial(const unsigned int id) noexcept {
                try {
                    if (id < this->polynomials.size()) {
                        this->polynomials.erase(this->polynomials.begin() + id);
                        this->json.Erase(this->json.Begin() + id);
                        this->terminal->set_rdata(this->stringify_polynomials());
                        this->save_json();
                    } else {this->terminal->echo_result("No polynomial with index:" + std::to_string(id));}
                } catch (::std::exception& e) {return 1;} return 0;
            }
            /**
            * @brief Function for stringifying Polynomials to a :std::vector<std::string> for Terminal echoing
            * @return (std::vector<std::string>) The stringification results
            **/
            const ::std::vector<::std::string> stringify_polynomials() const noexcept {::std::vector<::std::string> buffer; for (unsigned int i = 0; i < this->polynomials.size(); i++) {buffer.push_back("[" + std::to_string(i) + "] " + ::std::move(this->polynomials[i].get_expression()));} return buffer;}
            /**
            * @brief The main application menu as a loop
            * @return (const int) 0 If exit triggered, 1 if operation triggered and 2 if active window cycling triggered
            **/
            const int main_loop() {
                this->terminal->set_ldata(V_MENU);
                this->terminal->flush();
                while(true) {
                    switch(this->terminal->get_short_input()) {
                        case KEY_ESC: return 0; case KEY_SPC: return 1; 
                        case KEY_TAB: return 2;
                        case KEY_E: this->get_polynomial(); break;
                        case KEY_Q: this->terminal->set_prompt("Id:"); this->terminal->flush(); this->remove_polynomial(Application::to_int(this->terminal->get_long_input())); this->terminal->set_prompt("Option:"); break;
                    } this->terminal->flush();
                } return 0;
            }
            /**
            * @brief The operation menu as a loop
            * @return (const int) 0 If exit triggered, 1 if operation triggered and 2 if active window cycling triggered
            **/
            const int operation_loop() {
                if (!this->polynomials.empty()) {
                    this->terminal->set_ldata(V_OPERATION);
                    this->terminal->flush();
                    while(true) {
                        switch(this->terminal->get_short_input()) {
                            case KEY_ESC: return 0; case KEY_TAB: return 2;
                            case KEY_SPC: this->calculate(0); return 1;
                            case KEY_1: this->calculate(1); return 1;
                            case KEY_2: this->calculate(2); return 1;
                            case KEY_3: this->calculate(3); return 1;
                            case KEY_4: this->calculate(4); return 1;
                            case KEY_5: this->calculate(5); return 1;
                        } this->terminal->flush();
                    }
                } this->terminal->echo_result("No polynomials registered!"); return 0;
            }
            /**
            * @brief Subcaller for efectuating a operation
            * @param t The operation type
            **/
            void calculate(const int t) noexcept {
                this->terminal->set_prompt("Input:"); this->terminal->flush();
                if (t == 0) {
                    try {
                        std::string in = this->terminal->get_long_input();
                        const emth::Polynomial r = Parser(in).parse_operation(this->polynomials);
                        this->terminal->echo_result(r.is_empty() ? "0" : r.get_expression());
                        if (in[0] == '_') {this->add_polynomial(r);}
                    } catch (int e) {this->terminal->echo_result("No polynomial with index:" + std::to_string(e));}
                } else {
                    const unsigned int sinput = Application::to_int(this->terminal->get_long_input());
                    if (sinput < this->polynomials.size()) {
                        switch(t) {
                            case 1:
                                this->terminal->set_prompt("Value:"); this->terminal->flush();
                                this->terminal->echo_result((::std::stringstream() << this->polynomials[sinput].get_value(Application::to_int(this->terminal->get_long_input()))).str());
                                break;
                            case 2: this->terminal->echo_result(this->polynomials[sinput].get_derivative().get_expression()); break;
                            case 3: this->terminal->echo_result(this->polynomials[sinput].get_integral().get_expression()); break;
                            case 4: this->terminal->echo_result(vtoss(this->polynomials[sinput].get_roots())); break;
                            case 5: launch_plane(this->polynomials[sinput]); break;
                        }
                    } else {this->terminal->echo_result("No polynomial with index:" + std::to_string(sinput));}
                } this->terminal->set_prompt("Option:"); return;
            }
            /**
            * @brief Function for launching a Plane object in a different thread and detaching it
            * @param function The function that the Plane object will represent
            **/
            void launch_plane(const emth::Polynomial& function) const noexcept {
                this->terminal->set_prompt("X Offset:"); this->terminal->flush();
                int x = Application::to_int(this->terminal->get_long_input());
                this->terminal->set_prompt("Y Offset:"); this->terminal->flush();
                int y = Application::to_int(this->terminal->get_long_input());
                std::thread plane_thread([function, x, y](){Plane p(-x, -y, function); p.run(); return;});
                plane_thread.detach(); return;
            }
            /**
            * @brief Function for parsing a std::string as an int
            * @param number The number to parse as a std:.string
            * @return (const int) The parsed int
            **/
            static const int to_int(const ::std::string& number) noexcept {return Parser(number).parse_number();}
            /**
            * @brief Function for transforming a std::vector<std::complex<double>> to a std::string representing it
            * @param v The std::vector<std::complex<double>> to transform
            * @return (std::string) The std::string representing it
            **/
            static const std::string vtoss(const std::vector<std::complex<double>>& v) noexcept {std::stringstream ss; ss << "["; ctoss(ss, v[0]); for(unsigned int i = 1; i < v.size(); i++) {ss << ", "; ctoss(ss, v[i]);} ss << "]"; return ss.str();}
            /**
            * @brief Function for inserting <std::complex<double> to a std::stringstream
            * @param ss The std::stringstream to insert the representation to
            * @param c The std::complex<double> to transform
            **/
            static const void ctoss(std::stringstream& ss, const std::complex<double>& c) noexcept {ss << "("; if (std::abs(c.real()) > 1e-9 && std::abs(c.imag()) > 1e-9) {ss << c.real() << " " << ((c.imag() > 0) ? "+ " : "- ") << std::abs(c.imag()) << "i";} else if (std::abs(c.real()) > 1e-9) {ss << c.real();} else if (std::abs(c.imag()) > 1e-9) {ss << c.imag() << "i";} else {ss << "0";} ss << ")"; return;}
        public:
            /**
            * @brief Static function for building the singleton static instance
            * @return (Application*) The singleton instance pointer also stored at Application::instance
            **/
            static Application* init() noexcept {
                if (Application::instance != nullptr) {delete Application::instance;}
                return Application::instance = new Application();
            }
            /**
            * @brief Main loop fallback, basically it starts the application event loop
            **/
            void run() {
                bool hook = false;
                while(true) {
                    switch(this->main_loop()) {
                        case 0: return;
                        case 1: if (this->operation_loop() == 2 && this->cycle_focus() == 1) {hook = true;} break;
                        case 2: if (this->cycle_focus() == 1) {hook = true;} break;
                    }
                    while (hook) {
                        switch (this->scroll_loop()) {
                            case 0: return;
                            case 1: if (this->cycle_focus() != 1) {hook = false;}; break;
                        }
                    }
                } return;
            }
            /**
            * @brief Default destructor, it deletes the Terminal pointer, sets the singleton instance to nullptr, and saves the Json data to the Storage object
            **/
            ~Application() noexcept {
                Application::instance = nullptr;
                delete this->terminal;
                this->save_json(); return;
            }
    }; Application* Application::instance = nullptr;
}
/**
* @brief The main function that creates the efc::Application instance, runs it and when it finishes it deletes it
* @return Int 0 If the efc::Application did not end abrubtly
**/
int main() {efc::Application* app = efc::Application::init(); app->run(); delete app; return 0;}
#endif