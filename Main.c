#include "Header.h"


void board(int horizontal, int vertical);


int main()
{
    printf("");

}

void board(int horizontal, int vertical)
{
    printf("  ");
    for(int i = 0; i < horizontal;i++)
        printf("______\t  ");
    printf("\n");
    for(int i = 0; i < vertical; i++)
    {
        printf(" ");
        for(int i =0;; i++)
        {
            printf("/      \\");
            if(i == horizontal - 1)
                break;
            printf("        ");
        }
        printf("\n");

        for(int i = 0;; i++)
        {
            printf("/        \\");
            if(i == horizontal - 1)
                break;
            printf("______");
        }
        printf("\n");

        for(int i = 0;; i++)
        {
            printf("\\        /");
            if(i == horizontal - 1)
                break;
            printf("      ");
        }

        printf("\n ");

        for(int i = 0;; i++)
        {
            printf("\\______/");
            if(i == horizontal - 1)
                break;
            printf("        ");
        }
        printf("\n");
    }
}

