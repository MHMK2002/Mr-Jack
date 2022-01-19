#include "Header.h"


enum typeOfComponents{empty, block, well, wellBlocker, lamp
, lampLocation, Roadblock, Exit, WG, JW, IL, SH, JS, JB, MS, SG};

typedef struct PartMaP
{
    int type;
    char firstLine[7];
    char secondLine[9];
    char thirdLine[9];
    char fourthLine[7];
    int vertical;
    int horizontal;
}part;


void board(int horizontal, int vertical);
int menu();
part** newGame();

char blc = 254;
int main()
{
    // board(1, 4);

    // part **map = newGame();
    // for(int i = 0; i < 9;i++)
    // {
    //     for(int j = 0; j < 13; j++)
    //     printf("%d " ,map[i][j].type);

    //     printf("\n");
    // }

    // printf("  ______\n");
    // printf(" /      \\\n");
    // printf("/ ");
    // printYellowHighLight();
    // printf("      ");
    // resetColor();
    // printf(" \\\n");
    // printf("\\ ");
    // printYellowHighLight();
    // printf("      ");
    // resetColor();
    // printf(" /\n");
    // printf(" \\______/");


    // printf("  ______\n");
    // printf(" /  __  \\\n");
    // printf("/  /XX\\  \\\n");
    // printf("\\  \\XX/  /\n");
    // printf(" \\______/\n");
    // int choice = menu();

    // switch (choice)
    // {
    //     case 1:
        
            
    //     break;
    //     case 2:

    //     break;
    //     case 3:

    //     break;
    //     case 4:

    //     break;
    //     case 5:

    //     break;
    // }

    // printf("  ______\n");
    // printf(" /      \\\n");
    // printf("/\033[0;31m   S\033[0;34mG   \033[0;38m\\\n");
    // printf("\\        /\n");
    // printf(" \\______/\n");

    // for(int i = 0; i < 500; i++)
    //     printf("\n %d %c", i, i); 
//         176 ░
//  177 ▒
//  178 ▓

}


int menu()
{
    // for(int i = 0; i < 5; i++)
    //     printf("\n\n");

    system("cls");
    printRed();
    printf("\t\t\t\t\t\t\t\t\t              Mr Jack Board Game         \n\n");
    printGreen();
    printf("\t\t\t\t\t\t\t\t\t  * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t\t\t\t\t\t  *                                     *\n");
    printf("\t\t\t\t\t\t\t\t\t  *                                     *\n");

    printf("\t\t\t\t\t\t\t\t\t  *            ");
    printBlue();
    printf("1 - New game");
    printGreen();
    printf("             *\n");

    printf("\t\t\t\t\t\t\t\t\t  *                                     *\n");

    printf("\t\t\t\t\t\t\t\t\t  *            ");
    printBlue();
    printf("2 - Load Game");
    printGreen();
    printf("            *\n");

    printf("\t\t\t\t\t\t\t\t\t  *                                     *\n");

    printf("\t\t\t\t\t\t\t\t\t  *            ");
    printBlue();
    printf("3 - Create Map");
    printGreen();
    printf("           *\n");

    printf("\t\t\t\t\t\t\t\t\t  *                                     *\n");
    
    printf("\t\t\t\t\t\t\t\t\t  *            ");
    printBlue();
    printf("4 - Help game");
    printGreen();
    printf("            *\n");

    printf("\t\t\t\t\t\t\t\t\t  *                                     *\n");
    
    printf("\t\t\t\t\t\t\t\t\t  *            ");
    printBlue();
    printf("5 - Exit");
    printGreen();
    printf("                 *\n");


    printf("\t\t\t\t\t\t\t\t\t  *                                     *\n");
    printf("\t\t\t\t\t\t\t\t\t  *                                     *\n");
    printf("\t\t\t\t\t\t\t\t\t  * * * * * * * * * * * * * * * * * * * *\n");
    printBlue();
    printf("\n\t\t\t\t\t\t\t\t\t        Please enter your choice : ");

    int choice;
    
    scanf("%d", &choice);
    if(0 < choice && choice < 5)
        return choice;
    printf("\n\t\t\t\t\t\t\t\t\t        Please enter correctly!!!");
    printf("\n\t\t\t\t\t\t\t\t\t   Plesse Press ENTER key to continue...");
    getchar();
    getchar();
    

    menu();
}

void reset(part** map, int horizontal, int vertical) // این تابع هر بار کل نقشه را بررسی می کند و هربار نقشه را پس از تغییر چاپ می کند.
{
    for(int i = 0; i < horizontal; i++)
    {
        for(int j = 0; j < vertical; j++)
        {
            if(map[i][j].type == 0) //محل خالی 
            {
                strcmp(map[i][j].firstLine, "      ");
                strcmp(map[i][j].secondLine, "        ");
                strcmp(map[i][j].thirdLine, "        ");
                strcmp(map[i][j].fourthLine, "______");
            }
            else if(map[i][j].type == 1) //محل های بسته
            {
                strcmp(map[i][j].firstLine, "\033[0;47m      \033[0;38m");
                strcmp(map[i][j].secondLine, "\033[0;47m        \033[0;38m");
                strcmp(map[i][j].thirdLine, "\033[0;47m        \033[0;38m");
                strcmp(map[i][j].fourthLine, "\033[0;47m______\033[0;38m/");
            }
            else if(map[i][j].type == 2) //چاه
            {
                strcmp(map[i][j].firstLine, "  __  ");
                strcmp(map[i][j].secondLine, "  /  \\  ");
                strcmp(map[i][j].thirdLine, "  \\__/  ");
                strcmp(map[i][j].fourthLine, "______");
            }
            else if(map[i][j].type == 3) // درپوش چاه
            {
                strcmp(map[i][j].firstLine, "  __  ");
                strcmp(map[i][j].secondLine, "  /\033[0;47m  \\  \033[0;38m");
                strcmp(map[i][j].thirdLine, "  \\\033[0;47m__/  \033[0;38m");
                strcmp(map[i][j].fourthLine, "______");
            }
            else if(map[i][j].type == 4) // چراغ
            {
                strcmp(map[i][j].firstLine, "      ");
                strcmp(map[i][j].secondLine, "\033[0;43m        \033[0;38m");
                strcmp(map[i][j].thirdLine, "\033[0;43m        \033[0;38m");
                strcmp(map[i][j].fourthLine, "______");

            }
            else if(map[i][j].type == 5) // محل قرار گیری چراغ
            {
                strcmp(map[i][j].firstLine, "");
                strcmp(map[i][j].secondLine, "");
                strcmp(map[i][j].thirdLine, "");
                strcmp(map[i][j].fourthLine, "");
            }
            else if(map[i][j].type == 6) // مسدود کننده محل خروج
            {
                strcmp(map[i][j].firstLine, "      ");
                strcmp(map[i][j].secondLine, "\033[0;41m        \033[0;38m");
                strcmp(map[i][j].thirdLine, "\033[0;41m        \033[0;38m/");
                strcmp(map[i][j].fourthLine, "______");
            }
            else if(map[i][j].type == 7) // 
            {
                strcmp(map[i][j].firstLine, "");
                strcmp(map[i][j].secondLine, "");
                strcmp(map[i][j].thirdLine, "");
                strcmp(map[i][j].fourthLine, "");
            }
            else if(map[i][j].type == 8) //
            {

                strcmp(map[i][j].firstLine, "      ");
                strcmp(map[i][j].secondLine, "\033[0;35m   WG   \033[0;38m");
                strcmp(map[i][j].thirdLine, "        ");
                strcmp(map[i][j].fourthLine, "______");
            }
            else if(map[i][j].type == 9) //
            {

                strcmp(map[i][j].firstLine, "      ");
                strcmp(map[i][j].secondLine, "\033[0;36m   JW   \033[0;38m");
                strcmp(map[i][j].thirdLine, "        ");
                strcmp(map[i][j].fourthLine, "______");
            }
            else if(map[i][j].type == 10) //
            {

                strcmp(map[i][j].firstLine, "      ");
                strcmp(map[i][j].secondLine, "\033[0;34m   IL   \033[0;38m");
                strcmp(map[i][j].thirdLine, "        ");
                strcmp(map[i][j].fourthLine, "______");
            }
            else if(map[i][j].type == 11) //
            {
                strcmp(map[i][j].firstLine, "      ");
                strcmp(map[i][j].secondLine, "\033[0;31m   SH   \033[0;38m");
                strcmp(map[i][j].thirdLine, "        ");
                strcmp(map[i][j].fourthLine, "______");
            }
            else if(map[i][j].type == 12) //
            {

            }
            else if(map[i][j].type == 13) //
            {

                strcmp(map[i][j].firstLine, "      ");
                strcmp(map[i][j].secondLine, "\033[93m   JB   \033[0;38m");
                strcmp(map[i][j].thirdLine, "        ");
                strcmp(map[i][j].fourthLine, "______");
            }
            else if(map[i][j].type == 14) //
            {
                strcmp(map[i][j].firstLine, "      ");
                strcmp(map[i][j].secondLine, "\033[0;32m   MS   \033[0;38m");
                strcmp(map[i][j].thirdLine, "        ");
                strcmp(map[i][j].fourthLine, "______");
            }
            else if(map[i][j].type == 15) //
            {

                strcmp(map[i][j].firstLine, "      ");
                strcmp(map[i][j].secondLine, "\033[0;31m   S\033[0;34mG   \033[0;38m");
                strcmp(map[i][j].thirdLine, "        ");
                strcmp(map[i][j].fourthLine, "______");
            }
            
        }
    }
}

part** newGame()
{
    int horizontal,vertical;
    int type;
    FILE* NewGame = fopen("NewGame.txt", "r");
    
    fscanf(NewGame, "%d %d", &horizontal, &vertical);
    fgetc(NewGame);
    part **map = (part**)malloc(horizontal * sizeof(part*));
    for(int i = 0; i < horizontal; i++)
    {
        map[i] = (part*)malloc(vertical * sizeof(part));
        for(int j = 0; j < vertical; j++)
        {
            fscanf(NewGame, "%d", &map[i][j].type);
            map[i][j].horizontal = i;
            map[i][j].vertical = j;
        }
    }

    return map;
}


void board(int horizontal, int vertical)
{

    system("cls");
    if(horizontal % 2 == 0)
    {
        for(int j = 0; j < horizontal / 2; j++)
        {
            printf("          ");

            printf("______");
        }
        printf("\n");

        for(int i = 0; i < vertical; i++)
        {
            for(int j = 0; j < horizontal / 2; j++)
            {
                if(i == 0 && j == 0)
                {
                    printf("         /");
                    printf("      ");
                    continue;
                }
                printf("\\        /");

                printf("      ");
            }
            printf("\\\n ");

            for(int j = 0; j < horizontal / 2; j++)
            {
                if(i == 0 && j == 0)
                {
                    printf(" ______/");
                    printf("        ");
                    continue;
                }
                printf("\\______/");

                printf("        ");
            }
            printf("\\\n ");

            for(int j = 0; j < horizontal / 2; j++)
            {
                printf("/      \\");

                printf("        ");
            }
            printf("/\n");

            for(int j = 0; j < horizontal / 2; j++)
            {

                printf("/        \\");

                printf("______");
            }
            printf("/\n");
        }
        for(int j = 0; j < horizontal / 2; j++)
        {

            printf("\\        /");

            printf("      ");
        }
        printf("\n ");
        for(int j = 0; j < horizontal / 2; j++)
        {
            
            printf("\\______/");

            printf("        ");
        }
    }
    
    else
    {
        for(int j = 0; j < horizontal / 2; j++)
        {
            printf("          ");

            printf("______");
        }
        printf("\n");


        for(int i = 0; i < vertical; i++)
        {
            for(int j = 0; j < horizontal / 2; j++)
            {
                if(i == 0 && j == 0)
                {
                    printf("         /");
                    printf("   2  ");
                    continue;
                }
                printf("\\    5   /");

                printf("   2  ");
            }
            if(i > 0)
                printf("\\    5   /\n ");
            else if(horizontal != 1)
                printf("\\\n ");



            for(int j = 0; j < horizontal / 2; j++)
            {
                if(i == 0 && j == 0)
                {
                    printf(" ______/");
                    printf("    4   ");
                    continue;
                }
                printf("\\______/");

                printf("    4   ");
            }
            
            if(vertical == 1)
                printf("  ______\n ");
            else if(i > 0)
                printf("\\______/\n ");
            else
                printf("\\______\n ");




            for(int j = 0; j < horizontal / 2; j++)
            {
                printf("/   1  \\");

                printf("    6   ");
            }
            printf("/   1  \\\n");

            for(int j = 0; j < horizontal / 2; j++)
            {

                printf("/    3   \\");

                printf("______");
            }
            printf("/    3   \\\n");
        }

        
        for(int j = 0; j < horizontal / 2; j++)
        {

            printf("\\    5   /");

            printf("      ");
        }
        printf("\\    5   /\n ");
        for(int j = 0; j < horizontal / 2; j++)
        {
            
            printf("\\______/");

            printf("        ");
        }
        printf("\\______/");
    }
}