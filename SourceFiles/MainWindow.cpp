//
// Created by rcala on 22-07-2023.
//

#include "../Include/MainWindow.h"

MainWindow::MainWindow() {
    set_size_request(500,700);
    set_position(WIN_POS_CENTER);
    set_resizable(false);
    set_border_width(10);
    set_title("Calculator");

    grid.set_row_homogeneous(true);
    grid.set_column_homogeneous(true);
    grid.set_row_spacing(10);
    grid.set_column_spacing(10);

    result_display.set_editable(true);
    result_display.set_can_focus(false);
    grid.attach(result_display, 0, 0, 5, 1);

    const int column[] = {2, 0, 1 };
    for(int i = 9; i > 0; i--)
    {
        digit[i].set_label(std::to_string(i));
        grid.attach(digit[i], column[i%3] , 3-((i-1)/3), 1, 1);
    }
    digit[0].set_label("0");
    grid.attach(digit[0], 0, 4, 3, 1);

    operation[0].set_label("/");
    operation[1].set_label("x");
    operation[2].set_label("-");
    operation[3].set_label("+");
    grid.attach(operation[0], 3, 1, 1, 1);
    grid.attach(operation[1], 3, 2, 1, 1);
    grid.attach(operation[2], 3, 3, 1, 1);
    grid.attach(operation[3], 3, 4, 1, 1);

    clr.set_label("Clr");
    equal.set_label("=");
    grid.attach(clr, 4, 1, 1, 1);
    grid.attach(equal, 4, 2, 1, 3);

    add(grid);
    show_all_children();
}

void MainWindow::digits_pressed(int digit) {

}

void MainWindow::operation_pressed(int operation) {

}

void MainWindow::clear() {

}
