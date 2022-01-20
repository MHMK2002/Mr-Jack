#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <string.h>





void printBlack() { printf("\033[0;30m"); }
void printRed(){ printf("\033[0;31m"); }
void printGreen() { printf("\033[0;32m"); }
void printYellow() { printf("\033[0;33m"); }
void printBlue() { printf("\033[0;34m"); }
void printPurple() { printf("\033[0;35m"); }
void printCyan() { printf("\033[0;36m"); }
void printWhite() { printf("\033[0;37m"); }
void resetColor() { printf("\033[0;38m"); }


void printBlackHighLight() { printf("\033[0;40m"); }
void printRedHighLight() { printf("\033[0;41m"); }
void printGreenHighLight() { printf("\033[0;42m"); }
void printYellowHighLight() { printf("\033[0;43m"); }
void printBlueHighLight() { printf("\033[0;44m"); }
void printPurpleHighLight() { printf("\033[0;45m"); }
void printCyanHighLight() { printf("\033[0;46m"); }
void printWhiteHighLight() { printf("\033[0;47m"); }


void printBlock(int num)
{
    for(int i = 0; i < num; i++)
        printf("%c" ,254);
}