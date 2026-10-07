#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

    // ============================================================
    // CONSOLE SETTINGS
    // ============================================================

    const int WIDTH = 80;
    const int HEIGHT = 30;

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    // ============================================================
    // COLORS
    // ============================================================

    const int WHITE = 7;
    const int GRAY = 8;
    const int RED = 12;
    const int GREEN = 10;
    const int YELLOW = 14;
    const int BLUE = 9;
    const int MAGENTA = 13;
    const int CYAN = 11;

    // Extra colors used by the sign
    const int DARK_GREEN = 2;
    const int PURPLE = 5;
    const int ORANGE = 6;       // dark yellow, reads as orange
    const int BRIGHT_WHITE = 15;

    // ============================================================
    // CONSOLE FUNCTIONS
    // ============================================================

    void setColor(int color)
    {
        SetConsoleTextAttribute(consoleHandle, color);
    }

    void moveCursor(int x, int y)
    {
        COORD pos;
        pos.X = (SHORT)x;
        pos.Y = (SHORT)y;

        SetConsoleCursorPosition(consoleHandle, pos);
    }

    void clearScreen()
    {
        CONSOLE_SCREEN_BUFFER_INFO info;

        GetConsoleScreenBufferInfo(consoleHandle, &info);

        DWORD cells =
            info.dwSize.X * info.dwSize.Y;

        COORD home = { 0, 0 };

        DWORD written;

        FillConsoleOutputCharacter(
            consoleHandle,
            ' ',
            cells,
            home,
            &written
        );

        FillConsoleOutputAttribute(
            consoleHandle,
            WHITE,
            cells,
            home,
            &written
        );

        moveCursor(0, 0);
    }

    void put(int x, int y, char c, int color)
    {
        if (x < 0 || x >= WIDTH ||
            y < 0 || y >= HEIGHT)
            return;

        moveCursor(x, y);

        setColor(color);

        cout << c;
    }

    // ============================================================
    // MENU SIGN
    // ============================================================

    /*
       Block letters, 5 wide by 5 tall.
       '#' = filled, '.' = empty.
       Order: B O W L I N G S M
    */
    const char* GLYPHS[9][5] =
    {
        { "####.", "#...#", "####.", "#...#", "####." },   // B
        { ".###.", "#...#", "#...#", "#...#", ".###." },   // O
        { "#...#", "#...#", "#.#.#", "##.##", "#...#" },   // W
        { "#....", "#....", "#....", "#....", "#####" },   // L
        { "#####", "..#..", "..#..", "..#..", "#####" },   // I
        { "#...#", "##..#", "#.#.#", "#..##", "#...#" },   // N
        { ".####", "#....", "#..##", "#...#", ".###." },   // G
        { ".####", "#....", ".###.", "....#", "####." },   // S
        { "#...#", "##.##", "#.#.#", "#...#", "#...#" }    // M
    };

    void drawGlyph(int glyph, int x, int y, int color)
    {
        for (int row = 0; row < 5; row++)
        {
            for (int col = 0; col < 5; col++)
            {
                if (GLYPHS[glyph][row][col] == '#')
                    put(x + col, y + row, '#', color);
            }
        }
    }

    void drawMenuSign()
    {
        const int boxLeft = 5;
        const int boxRight = 73;
        const int boxTop = 2;
        const int boxBottom = 10;

        // Hanging chains
        put(20, 1, '|', GRAY);
        put(59, 1, '|', GRAY);

        // Sign frame
        for (int x = boxLeft + 1; x < boxRight; x++)
        {
            put(x, boxTop, '=', YELLOW);
            put(x, boxBottom, '=', YELLOW);
        }

        for (int y = boxTop + 1; y < boxBottom; y++)
        {
            put(boxLeft, y, '|', YELLOW);
            put(boxRight, y, '|', YELLOW);
        }

        put(boxLeft, boxTop, '+', YELLOW);
        put(boxRight, boxTop, '+', YELLOW);
        put(boxLeft, boxBottom, '+', YELLOW);
        put(boxRight, boxBottom, '+', YELLOW);

        // Letters: B O W L I N G (space) S I M
        const int glyphs[] = { 0, 1, 2, 3, 4, 5, 6, -1, 7, 4, 8 };

        // One color per letter, no repeats
        const int colors[] =
        {
            RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, MAGENTA,
            WHITE,
            BRIGHT_WHITE, PURPLE, DARK_GREEN
        };

        int x = 8;
        const int y = 4;

        for (int i = 0; i < 11; i++)
        {
            if (glyphs[i] >= 0)
            {
                drawGlyph(glyphs[i], x, y, colors[i]);
                x += 6;
            }
            else
            {
                // Gap between the two words
                x += 5;
            }
        }

        setColor(WHITE);
    }