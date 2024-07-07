#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <chrono>
#include <iomanip>
#include <string>
#include <sstream>
#include "console-plus.h"

// 清屏函数
void ClearScreen() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft, &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}
char map[55][65]{
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','L','L','L','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','L','L','L','L','L','#','#','#','#','#','#','#','#','#','L','L','L','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','L','L','L','W','L','L','L','#','#','#','#','#','#','#','L','L','L','L','L','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','W','#','#','#','#','#','#','#','#','#','L','L','L','W','L','L','L','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','W','#','#','#','#','#','#','#','#','#','#','#','#','W','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#','#','#','#','#','G','G','G','G','#','#','#','#','#','#','#','#','#','#','G','G','G','G','G','#','#','#','#','#','#','#','G','G','G','G','G','G','G','#','#','#','#','#','#','#','#','#','#','#','#','#','G','G','G','G','G','G','G','G','G'},
{'G','G','G','G','G','M','M','M','M','G','G','G','G','G','G','G','G','G','G','M','M','M','M','M','G','G','G','G','G','G','G','M','M','M','M','M','M','M','G','G','G','G','G','G','G','G','G','G','G','G','G','M','M','M','M','M','M','M','M','M'},
{'M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M'},
{'M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','S','S','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M','M'},
{'M','M','M','S','S','S','S','M','M','M','M','S','S','S','S','S','M','M','S','S','S','M','M','S','S','S','S','M','M','M','M','S','S','S','S','M','M','M','M','M','M','S','S','S','S','S','S','S','M','M','M','S','S','S','S','M','M','M','M','M'},
{'S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S'},
{'S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S'},
{'S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S'}
};
int x=11, y=8;

int block = 1; // 1 = STONE , 2 = GRASS

void draw() {
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            if (i == x && j == y) {
                greenbg();
                white();
                std::cout << "P";
                reset();
            }
            else if (map[i][j]=='#') {
                blue();
                bluebg();
                std::cout << "A";
                reset();
            }
            else if (map[i][j] == 'S') {
                rgb(128, 128, 128);
                rgbbg(128, 128, 128);
                std::cout << "S";
                reset();
            }
            else if (map[i][j] == 'G') {
                rgb(27, 115, 26);
                rgbbg(27, 115, 26);
                std::cout << "G";
                reset();
            }
            else if (map[i][j] == 'M') {
                rgb(120, 67, 21);
                rgbbg(120, 67, 21);
                std::cout << "G";
                reset();
            }
            else if (map[i][j] == 'W') {
                rgb(116, 90, 54);
                rgbbg(116, 90, 54);
                std::cout << "W";
                reset();
            }
            else if (map[i][j] == 'L') {
                rgb(117, 250, 141);
                rgbbg(117, 250, 141);
                std::cout << "L";
                reset();
            }
            else if (map[i][j] == 'P') {
                rgb(194, 157, 98);
                rgbbg(194, 157, 98);
                std::cout << "P";
                reset();
            }
            else {
                blue();
                bluebg();
                std::cout << "N";
                reset();
            }
        }
        std::cout << std::endl;
    }
    rgbbg(54, 126, 127);
    std::cout << R"(
+-------+-------+-------+-------+-------+-------+
|   1   |   2   |   3   |   4   |   5   |   6   |
| STONE | GRASS |  MUD  | WOOD  | LEAF  | PLANK |
+-------+-------+-------+-------+-------+-------+
                                                 
w :   UP  d : RIGHT  j :  PLACE  q : exit        
s : DOWN  a :  LEFT  k : REMOVE                  )" << std::endl << std::endl;
    reset();
    redbg();
    std::cout << "x:" << x << "y:" << y;
}
auto now = std::chrono::system_clock::now();
auto in_time_t = std::chrono::system_clock::to_time_t(now);
std::stringstream ss;
std::string formatted_time;
bool logic(bool b,const char* fn) {
    char c = _getch();
    std::ofstream fout;
    if (b) fout.open(fn, std::ios::app);
    else fout.open("world/data-" + formatted_time + ".dat", std::ios::app);
    if(c!='q') fout << c;
    switch (c)
    {
    case 'a':
    case 'A':
        y--;
        break;
    case 'd':
    case 'D':
        y++;
        break;
    case 'w':
    case 'W':
        x--;
        break;
    case 's':
    case 'S':
        x++;
        break;
    case 'j':
    case 'J':
        if (block == 1) map[x][y + 1] = 'S';
        else if (block == 2) map[x][y + 1] = 'G';
        else if (block == 3) map[x][y + 1] = 'M';
        else if (block == 4) map[x][y + 1] = 'W';
        else if (block == 5) map[x][y + 1] = 'L';
        else if (block == 6) map[x][y + 1] = 'P';
        break;
    case 'k':
    case 'K':
        map[x][y + 1] = '#';
        break;
    case 'q':
    case 'Q':
        fout.close();
        return 1;
    case '1':
        block = 1;
        break;
    case '2':
        block = 2;
        break;
    case '3':
        block = 3;
        break;
    case '4':
        block = 4;
        break;
    case '5':
        block = 5;
        break;
    case '6':
        block = 6;
        break;
    default:
        std::cout << "\a";
        break;
    }
    if (x >= 20 || x < 0 || y>=60 || y < 0) {
        x = 11;y = 8;
        std::cout << "\a";
    }
    fout.close();
    ClearScreen();
    return 0;
}

// 主程序
int main() {
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d-%H-%M-%S");
    formatted_time = ss.str();
    hidecur();
    italic();
    std::cout << R"(2D minecraft
by github@neverforward
)" << std::endl;
    reset();
    redbg();
    std::cout << R"(
1. new world
2. open file(world/data-year-month-day-hour-min-sec.dat)
)";
    if (_getch() == '1') {
        ClearScreen();
        while (1)
        {
            draw();
            if (logic(false,"")) {
                reset();
                return 0;
            }
        }
    }
    else {
        reset();
        std::cout << "file name:";
        char ch[10010];
        std::cin >> ch;
        std::ifstream fin(ch, std::ios::in);
        if (!fin.is_open()) {
            redbg();
            std::cerr << "Error opening file." << std::endl;
            reset();
            _getch();
            return -1;
        }
        char c;
        while (fin.get(c)) {
            switch (c)
            {
            case 'a':
            case 'A':
                y--;
                break;
            case 'd':
            case 'D':
                y++;
                break;
            case 'w':
            case 'W':
                x--;
                break;
            case 's':
            case 'S':
                x++;
                break;
            case 'j':
            case 'J':
                if (block == 1) map[x][y + 1] = 'S';
                else if (block == 2) map[x][y + 1] = 'G';
                else if (block == 3) map[x][y + 1] = 'M';
                else if (block == 4) map[x][y + 1] = 'W';
                else if (block == 5) map[x][y + 1] = 'L';
                else if (block == 6) map[x][y + 1] = 'P';
                break;
            case 'k':
            case 'K':
                map[x][y + 1] = '#';
                break;
            case 'q':
            case 'Q':
                return 1;
            case '1':
                block = 1;
                break;
            case '2':
                block = 2;
                break;
            case '3':
                block = 3;
                break;
            case '4':
                block = 4;
                break;
            case '5':
                block = 5;
                break;
            case '6':
                block = 6;
                break;
            default:
                std::cout << "\a";
                break;
            }
        }
        fin.close(); 
        ClearScreen();
        while (1)
        {
            draw();
            if (logic(true,ch)) {
                reset();
                return 0;
            }
        }
    }
    return 0;
}