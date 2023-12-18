// include/Menu.h

#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

class Menu {
public:
  Menu(const std::vector<std::string> &options);
  int displayMenu();

private:
  std::vector<std::string> menuOptions;
};

#endif // MENU_H
