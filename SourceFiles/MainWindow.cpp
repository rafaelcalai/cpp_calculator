//
// Created by rcala on 22-07-2023.
//

#include "../Include/MainWindow.h"

MainWindow::MainWindow()
{
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
        digit[i].signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(this, &MainWindow::digits_pressed), i));
        grid.attach(digit[i], column[i%3] , 3-((i-1)/3), 1, 1);
    }
    digit[0].set_label("0");
    digit[0].signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(this, &MainWindow::digits_pressed), 0));
    grid.attach(digit[0], 0, 4, 3, 1);

    operation[0].set_label("/");
    operation[1].set_label("x");
    operation[2].set_label("-");
    operation[3].set_label("+");
    operation[0].signal_clicked().connect(sigc::bind<const char>(sigc::mem_fun(this, &MainWindow::operation_pressed), '/'));
    operation[1].signal_clicked().connect(sigc::bind<const char>(sigc::mem_fun(this, &MainWindow::operation_pressed), 'x'));
    operation[2].signal_clicked().connect(sigc::bind<const char>(sigc::mem_fun(this, &MainWindow::operation_pressed), '-'));
    operation[3].signal_clicked().connect(sigc::bind<const char>(sigc::mem_fun(this, &MainWindow::operation_pressed), '+'));
    grid.attach(operation[0], 3, 1, 1, 1);
    grid.attach(operation[1], 3, 2, 1, 1);
    grid.attach(operation[2], 3, 3, 1, 1);
    grid.attach(operation[3], 3, 4, 1, 1);

    clr.set_label("Clr");
    clr.signal_clicked().connect(sigc::mem_fun(this, &MainWindow::clear));
    equal.set_label("=");
    equal.signal_clicked().connect(sigc::mem_fun(this, &MainWindow::calculate));
    grid.attach(clr, 4, 1, 1, 1);
    grid.attach(equal, 4, 2, 1, 3);

    add(grid);
    show_all_children();
}

void MainWindow::digits_pressed(int digit_pressed)
{
    if(res)
    {
        MainWindow::clear();
    }

    std::cout << digit_pressed << std::endl;
    std::cout << result_display.get_text_length() << std::endl;
    if(result_display.get_text_length() < 45)
    {
        result_display.set_text(result_display.get_text() + std::to_string(digit_pressed));
    }
}

void MainWindow::operation_pressed(char operation_pressed)
{
    std::cout << operation_pressed << std::endl;
    if(res)
    {
        MainWindow::clear();
    }
    if(result_display.get_text_length()  == 0 && operation_pressed == '-')
    {
        result_display.set_text(result_display.get_text() + operation_pressed);
        num1_negative = true;
    }
    else if(result_display.get_text_length() == 1 && num1_negative)
    {
        return;
    }
    else if(result_display.get_text_length() > 0 && result_display.get_text_length() < 45 && !has_operator)
    {
        result_display.get_text_length() == 0 and operation_pressed == '-'? has_operator = false : has_operator = true ;
        result_display.set_text(result_display.get_text() + " " + operation_pressed + " ");
    }
}

void MainWindow::clear()
{
    std::cout << "Clear" << std::endl;
    result_display.set_text("");
    has_operator = false;
    num1_negative = false;
    res = false;
}

void MainWindow::calculate()
{
    std::cout << "Calc" << std::endl;

    if((result_display.get_text_length() == 1 && num1_negative) || result_display.get_text_length() == 0)
    {
        result_display.set_text("Error, no value added");
        res = true;
        return;
    }
    std::string expression = result_display.get_text();
    std::cout << expression<< std::endl;
    std::vector <std::string>values;


    if(!has_operator)
    {
        res = true;
        return;
    }
    else
    {
        // Used to split string around spaces.
        std::string word, display_result;
        char operation_type;
        std::istringstream ss(expression);
        ss >> word;
        num1 = stol(word);
        ss >> operation_type;
        ss >> word;
        num2 = stol(word);

        switch(operation_type)
        {
            case '+':
                display_result = std::to_string(num1 + num2);
                break;
            case '-':
                display_result = std::to_string(num1 - num2);
                break;
            case 'x':
                display_result = std::to_string(num1 * num2);
                break;
            case '/':
                display_result = std::to_string(num1 / num2);
                break;
            default:
                result_display.set_text("Error, operation_type");
                return;
        }
        result_display.set_text(display_result);
        res = true;
    }
}
