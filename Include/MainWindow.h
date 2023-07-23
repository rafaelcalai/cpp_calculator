//
// Created by rcala on 22-07-2023.
//

#ifndef CPP_CALCULATOR_MAINWINDOW_H
#define CPP_CALCULATOR_MAINWINDOW_H
#include <iostream>
#include<gtkmm-3.0/gtkmm.h>

using namespace Gtk;
class MainWindow : public Gtk::Window{
private:
    Gtk::Grid grid;
    long num1 = -1,  num2 = -1;
    std::string op = "";
    bool res = false;
    bool has_operator = false;

    Gtk::Entry result_display;
    Gtk::Button digit[10];
    Gtk::Button operation[4];
    Gtk::Button equal;
    Gtk::Button clr;

    void digits_pressed(int digit);
    void operation_pressed(char operation);
    void calculate();
    void clear();

public:
    MainWindow();
};


#endif //CPP_CALCULATOR_MAINWINDOW_H
