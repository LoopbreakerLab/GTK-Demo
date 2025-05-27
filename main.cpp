#include <gtkmm.h>
#include "MainWindow.h"

int main() {
    auto app = Gtk::Application::create();

    MainWindow mainWindow;
    return app->run(mainWindow);
}