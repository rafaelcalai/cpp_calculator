#include <iostream>
#include "Include/MainWindow.h"

int main(int argc, char *argv[]) {
    std::cout << "C++ Calculator" << std::endl;
    Main main(argc, argv);
    MainWindow window;
    main.run(window);

    return 0;
}
