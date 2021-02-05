#include <iostream>
#include <string>

std::string maze[25] = {
    "####B######################",
    "# #       #   #      #    #",
    "# # # ###### #### ####### #",
    "# # # #       #   #       #",
    "#   # # ######### # ##### #",
    "# # # #   #       #     # #",
    "### ### ### ############# #",
    "# #   #     # #           #",
    "# # #   ####### ###########",
    "# # # #       # #         C",
    "# # ##### ### # # ####### #",
    "# # #     ### # #       # #",
    "#   ##### ### # ######### #",
    "######### ### #           #",
    "# ####### ### #############",
    "A           #   ###   #   #",
    "# ############# ### # # # #",
    "# ###       # # ### # # # #",
    "# ######### # # ### # # # F",
    "#       ### # #     # # # #",
    "# ######### # ##### # # # #",
    "# #######   #       #   # #",
    "# ####### ######### #######",
    "#         #########       #",
    "#######E############D######"
};

std::string salvation(int x, int y, int x1, int y1)
{
     std::string res("");

    if (maze[y - 1][x] != '#' && y + 1 != y1)
    {
        if (maze[y - 1][x] == ' ')
            res += salvation(y - 1, x, x, y).c_str();
        else
            return std::to_string(maze[y + 1][x]).c_str();

    }
    
    if (maze[y + 1][x] != '#' && y - 1 != y1)
    {
        if (maze[y + 1][x] == ' ')
            res += salvation(y + 1, x, x, y).c_str();
        else
            return std::to_string(maze[y + 1][x]).c_str();
    }

    if (maze[y][x - 1] != '#' && x + 1 != x1)
    {
        if (maze[y][x - 1] == ' ')
            res += salvation(y, x - 1, x, y).c_str();
        else
            return std::to_string(maze[y + 1][x]).c_str();

        return res;
    }

    if (maze[y][x + 1] != '#' && x - 1 != x1)
    {
        if (maze[y][x + 1] == ' ')
            res += salvation(y, x + 1, x, y).c_str();
        else
            return std::to_string(maze[y + 1][x]).c_str();
    }

    return res;
}

int main()
{
    setlocale(LC_ALL, "rus");

    int x, y;
    std::cin >> x >> y;

    if (x <= 0 || y <= 0 || x >= 25 || y >= 25)
    {
        std::cout << "Íåâåðíûå êîîðäèíàòû";
        return 0;
    }
    std::cout << salvation(x, y, 0, 0);

    return 0;
}
