#pragma once
#include <windows.h>

// ============================================================
// CONSOLE SETTINGS
// ============================================================

constexpr int WIDTH = 80;
constexpr int HEIGHT = 30;

// ============================================================
// COLORS
// ============================================================

constexpr int WHITE = 7;
constexpr int GRAY = 8;
constexpr int RED = 12;
constexpr int GREEN = 10;
constexpr int YELLOW = 14;
constexpr int BLUE = 9;
constexpr int MAGENTA = 13;
constexpr int CYAN = 11;

constexpr int DARK_GREEN = 2;
constexpr int PURPLE = 5;
constexpr int ORANGE = 6;
constexpr int BRIGHT_WHITE = 15;

// ============================================================
// CONSOLE FUNCTIONS
// ============================================================

void setColor(int color);
void moveCursor(int x, int y);
void clearScreen();
void put(int x, int y, char c, int color);

// ============================================================
// MENU SIGN
// ============================================================

void drawGlyph(int glyph, int x, int y, int color);
void drawMenuSign();

// ============================================================
// GAME ASCII ART
// ============================================================

void DrawStrike();
void DrawSpare();
void DrawGutterBall();