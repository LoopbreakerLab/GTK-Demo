#include <iostream>
#include <gtkmm.h>
#include <gtkmm/separatormenuitem.h>
#include <gtkmm/filechooserdialog.h>
#include <gtkmm/aboutdialog.h>

#include "MainWindow.h"

MainWindow::MainWindow() {
    set_border_width(DEFAULT_BORDER_WIDTH);
    set_default_size(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);

    mainBox = Gtk::Box(Gtk::ORIENTATION_VERTICAL);
    add(mainBox);

    // Create menu items
    fileMenu = Gtk::Menu();
    itemFileMenu = Gtk::MenuItem("_File", true);
    itemOpenFile = Gtk::MenuItem("_Open", true);
    itemOpenFile.signal_activate().connect(sigc::mem_fun(*this, &MainWindow::on_file_open));
    itemQuit = Gtk::MenuItem("_Quit", true);
    itemQuit.signal_activate().connect(sigc::mem_fun(*this, &MainWindow::on_quit));
    auto separator = Gtk::SeparatorMenuItem();

    helpMenu = Gtk::Menu();
    itemHelpMenu = Gtk::MenuItem("_Help", true);
    itemAbout = Gtk::MenuItem("_About", true);
    itemAbout.signal_activate().connect(sigc::mem_fun(*this, &MainWindow::on_about));

    // Build menu bar
    menuBar = Gtk::MenuBar();
    menuBar.append(itemFileMenu);
    menuBar.append(itemHelpMenu);

    // Assign submenus
    itemFileMenu.set_submenu(fileMenu);
    fileMenu.append(itemOpenFile);
    fileMenu.append(separator);
    fileMenu.append(itemQuit);

    itemHelpMenu.set_submenu(helpMenu);
    helpMenu.append(itemAbout);

    // Build layout
    auto topBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
    topBox->pack_start(menuBar, Gtk::PACK_SHRINK);
    mainBox.pack_start(*topBox, Gtk::PACK_SHRINK);

    show_all_children();
}

MainWindow::~MainWindow() = default;

void MainWindow::on_quit() {
    get_application()->quit();
}

void MainWindow::on_file_open() {
    Gtk::FileChooserDialog dialog("Choose files",
                                Gtk::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_select_multiple(true);
    dialog.set_transient_for(*this);
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Open", Gtk::RESPONSE_OK);

    int result = dialog.run();
    if (result == Gtk::RESPONSE_OK) {
        std::vector<std::string> filenames = dialog.get_filenames();
        for(const auto& filename : filenames) {
            std::cout << "Selected file: " << filename << std::endl;
        }
    }
}

void MainWindow::on_about() {
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this);
    dialog.set_program_name("GTK-Demo");
    dialog.set_version("0.0.1");
    dialog.set_copyright("Copyright 2025");
    dialog.set_comments("Demo with GTK");
    dialog.set_license("License text");
    dialog.set_website("https://www.gtk.org/");

    dialog.run();
    dialog.hide();
}