#ifndef GTK_DEMO_MAINWINDOW_H
#define GTK_DEMO_MAINWINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/menubar.h>
#include <gtkmm/menu.h>
#include <gtkmm/menuitem.h>

class MainWindow : public Gtk::Window {
public:
    MainWindow();
    ~MainWindow() override;

protected:
    // Signal Handler
    void on_quit();
    void on_file_open();
    void on_about();

private:
    // Window constants
    static constexpr int DEFAULT_WINDOW_WIDTH = 800;
    static constexpr int DEFAULT_WINDOW_HEIGHT = 600;
    static constexpr int DEFAULT_BORDER_WIDTH = 0;

    // Main Layout
    Gtk::Box mainBox;
    Gtk::MenuBar menuBar;

    // File Menu
    Gtk::Menu fileMenu;
    Gtk::MenuItem itemFileMenu;
    Gtk::MenuItem itemOpenFile;
    Gtk::MenuItem itemQuit;

    // Help Menu
    Gtk::Menu helpMenu;
    Gtk::MenuItem itemHelpMenu;
    Gtk::MenuItem itemAbout;
};

#endif // GTK_DEMO_MAINWINDOW_H