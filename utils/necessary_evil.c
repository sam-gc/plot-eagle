/*
 * This file is necessary as Eagle does not support passing
 * structs by value due to ABI issues; thus we must wrap such
 * functions in C and call in from Eagle.
 *
 * We also wrap functions here that are platform-dependent
 * (Eagle does not currently have a nice conditional-code
 * generation system).
 */

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <unistd.h>
#include <stdio.h>

typedef struct
{
    char r;
    char g;
    char b;
} Color;

void ne_binary_path(char *buffer, int len)
{
#ifdef __APPLE__
    _NSGetExecutablePath(buffer, len);
#else
    int read = readlink("/proc/self/exe", buffer, len);
    buffer[read] = '\0';
#endif
}

SDL_Surface *ne_render_text(TTF_Font *font, char *text, char r, char g, char b)
{
    SDL_Color col = {r, g, b, 0};
    return TTF_RenderText_Solid(font, text, col);
}

void print_yellow()
{
    printf("\033[1;36m");
}

void print_blue()
{
    printf("\033[1;34m");
}

void print_default()
{
    printf("\033[0m");
}

char *prompt()
{
    return "\033[1;34m> \033[0m";
}

