#include "Header.h"


enum typeOfComponents{empty, block, well, wellBlocker, lamp, lampLocation, Roadblock, Exit, character};
enum ORDER{beforeOrAfter, afterMovement, movementOrFunctionality, simultaneous};
enum Direction{north, south, northEast, southEast, northWest, southWest};
struct Character
{
    char name[5];
    char nameForPrint[25];
    bool visible;
    int maximumOfMovement;
    short order;
    int horizontal;
    int vertical;
};

struct Character SergentGoodley = {"SG", "\033[0;34mS\033[0;31mG\033[0;38m", false, 4, beforeOrAfter};
struct Character SherlockHolmes = {"SH", "\033[0;31mSH\033[0;38m", false, 3, afterMovement};
struct Character JohnWatson = {"JW 0", "\033[0;33mJW\033[0;38m", false, 3, afterMovement};
struct Character JeremyBert = {"JB", "\033[0;36mJB\033[0;38m", false, 3, beforeOrAfter};
struct Character MissStealthy = {"MS", "\033[0;32mMS\033[0;38m", false, 3, simultaneous};
struct Character InspectorLestrade = {"IL", "\033[0;34mIN\033[0;38m", false, 3, beforeOrAfter};
struct Character SirWilliamGull = {"SG", "\033[0;35mSW\033[0;38m", false, 3, movementOrFunctionality};
struct Character JohnSmith = {"JW", "\033[0;33mJS\033[0;38m", false, 3, beforeOrAfter};


typedef struct PartMaP
{
    int type;
    char firstLine[25];
    char secondLine[25];
    char thirdLine[40];
    char fourthLine[25];
    char fifthLine[25];
    int vertical;
    int horizontal;
    struct Character *characters;
}part;


void board(int horizontal, int vertical);
int menu();
part** newGame();

char blc = 254;
int main()
{
    board(5, 10);

    // part **map = newGame();
    // for(int i = 0; i < 9;i++)
    // {
    //     for(int j = 0; j < 13; j++)
    //     printf("%d " ,map[i][j].type);

    //     printf("\n");
    // }

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
    // printf(" /\033[0;33m//\033[0;38m    \\\n");
    // printf("/\033[0;33m//\033[0;38m      \\\n");
    // printf("\\        /\n");
    // printf(" \\______/\n");

    // for(int i = 0; i < 500; i++)
    //     printf("\n %d %c", i, i); 



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

// enum typeOfComponents{empty, block, well, wellBlocker, lamp, lampLocation, Roadblock, Exit, character};

void reset(part** map, int horizontal, int vertical) // این تابع هر بار کل نقشه را بررسی می کند و هربار نقشه را پس از تغییر چاپ می کند.
{
    for(int i = 0; i < horizontal; i++)
    {
        for(int j = 0; j < vertical; j++)
        {
            if(map[i][j].type == 0) //محل خالی 
            {
                strcmp(map[i][j].firstLine, "______");
                strcmp(map[i][j].secondLine, "      ");
                strcmp(map[i][j].thirdLine, "        ");
                strcmp(map[i][j].fourthLine, "        ");
                strcmp(map[i][j].fifthLine, "______");
            }
            else if(map[i][j].type == 1) //محل های بسته
            {
                strcmp(map[i][j].firstLine, "______");
                strcmp(map[i][j].secondLine, "\033[0;47m      \033[0;38m");
                strcmp(map[i][j].thirdLine, "\033[0;47m        \033[0;38m");
                strcmp(map[i][j].fourthLine, "\033[0;47m        \033[0;38m");
                strcmp(map[i][j].fifthLine, "\033[0;47m______\033[0;38m/");
            }
            else if(map[i][j].type == 2) //چاه
            {
                strcmp(map[i][j].firstLine, "______");
                strcmp(map[i][j].secondLine, "  __  ");
                strcmp(map[i][j].thirdLine, "  /  \\  ");
                strcmp(map[i][j].fourthLine, "  \\__/  ");
                strcmp(map[i][j].fifthLine, "______");
            }
            else if(map[i][j].type == 3) // درپوش چاه
            {
                strcmp(map[i][j].firstLine, "______");
                strcmp(map[i][j].secondLine, "  __  ");
                strcmp(map[i][j].thirdLine, "  /\033[0;47m  \\  \033[0;38m");
                strcmp(map[i][j].fourthLine, "  \\\033[0;47m__/  \033[0;38m");
                strcmp(map[i][j].fifthLine, "______");
            }
            else if(map[i][j].type == 4) // چراغ
            {
                strcmp(map[i][j].firstLine, "______");
                strcmp(map[i][j].secondLine, "      ");
                strcmp(map[i][j].thirdLine, "  \033[0;33m****\033[0;38m  ");
                strcmp(map[i][j].fourthLine, "  \033[0;33m****\033[0;38m  ");
                strcmp(map[i][j].fifthLine, "______");

            }
            else if(map[i][j].type == 5) // محل قرار گیری چراغ
            {
                strcmp(map[i][j].firstLine, "______");
                strcmp(map[i][j].secondLine, "      ");
                strcmp(map[i][j].thirdLine, "  ****  ");
                strcmp(map[i][j].fourthLine, "  ****  ");
                strcmp(map[i][j].fifthLine, "______");
            }
            else if(map[i][j].type == 6) // مسدود کننده محل خروج
            {
                strcmp(map[i][j].firstLine, "______");
                strcmp(map[i][j].secondLine, "      ");
                strcmp(map[i][j].thirdLine, "\033[0;41m        \033[0;38m");
                strcmp(map[i][j].fourthLine, "\033[0;41m        \033[0;38m/");
                strcmp(map[i][j].fifthLine, "______");
            }
            else if(map[i][j].type == 7) // خروجی
            {
                if(i == 0)
                {
                    strcmp(map[i][j].firstLine, "_|  |_");
                    strcmp(map[i][j].secondLine, " |  | ");
                    strcmp(map[i][j].thirdLine, "        ");
                    strcmp(map[i][j].fourthLine, "        ");
                    strcmp(map[i][j].fifthLine, "______");
                }
                else
                {
                    strcmp(map[i][j].firstLine, "______");
                    strcmp(map[i][j].secondLine, "      ");
                    strcmp(map[i][j].thirdLine, "        ");
                    strcmp(map[i][j].fourthLine, "  |  |  ");
                    strcmp(map[i][j].fifthLine, "_|  |_");
                }
            }
            else if(map[i][j].type == 8) // کاراکتر
            {
                if(strncmp(map[i][j].characters->name, "JW", 2) != 0)
                {
                    char current[25] = "   ";
                    strcat(current, map[i][j].characters->nameForPrint);
                    strcat(current, "   ");

                    strcmp(map[i][j].firstLine, "______");
                    strcmp(map[i][j].secondLine, "      ");
                    strcpy(map[i][j].thirdLine, current);
                    strcmp(map[i][j].fourthLine, "        ");
                    strcmp(map[i][j].fifthLine, "______");
                }
                else // کاراکتر جان واتسون به دلیل داشتن فانوس در برای روشنایی یک راستا،تفاوتی در چاپ کردن با دیگر کاراکتر ها دارد،به همین خاطر از این دو شرط استفاده شده است.
                {
                    int direction = map[i][j].characters->name[3];


                    if(direction == north)
                    {
                        char current[40] = "   ";
                        strcat(current, map[i][j].characters->nameForPrint);
                        strcat(current, "   ");

                        strcmp(map[i][j].firstLine, "\033[0;33m______\033[0;38m");
                        strcmp(map[i][j].secondLine, "\033[0;33m______\033[0;38m");
                        strcpy(map[i][j].thirdLine, current);
                        strcmp(map[i][j].fourthLine, "        ");
                        strcmp(map[i][j].fifthLine, "______");
                    }
                    else if(direction == south)
                    {
                        char current[25] = "   ";
                        strcat(current, map[i][j].characters->nameForPrint);
                        strcat(current, "   ");
                        strcmp(map[i][j].firstLine, "______");
                        strcmp(map[i][j].secondLine, "      ");
                        strcpy(map[i][j].thirdLine, current);
                        strcmp(map[i][j].fourthLine, " \033[0;33m______\033[0;38m ");
                        strcmp(map[i][j].fifthLine, "\033[0;33m______\033[0;38m");
                    }
                    else if(direction == northEast)
                    {
                        char current[25] = "   ";
                        strcat(current, map[i][j].characters->nameForPrint);
                        strcat(current, " \033[0;33m\\\\\033[0;38m");
                        strcmp(map[i][j].firstLine, "______");
                        strcmp(map[i][j].secondLine, "    \033[0;33m\\\\\033[0;38m");
                        strcpy(map[i][j].thirdLine, current);
                        strcmp(map[i][j].fourthLine, "        ");
                        strcmp(map[i][j].fifthLine, "______");
                    }
                    else if(direction == southEast)
                    {
                        char current[25] = "   ";
                        strcat(current, map[i][j].characters->nameForPrint);
                        strcat(current, "   ");
                        strcmp(map[i][j].firstLine, "______");
                        strcmp(map[i][j].secondLine, "      ");
                        strcpy(map[i][j].thirdLine, current);
                        strcmp(map[i][j].fourthLine, "       \033[0;33m//\033[0;38m");
                        strcmp(map[i][j].fifthLine, "____\033[0;33m//\033[0;38m");
                    }
                    else if(direction == northWest)
                    {
                        char current[25] = "\033[0;33m//\033[0;38m ";
                        strcat(current, map[i][j].characters->nameForPrint);
                        strcat(current, "   ");
                        strcmp(map[i][j].firstLine, "______");
                        strcmp(map[i][j].secondLine, "\033[0;33m//\033[0;38m    ");
                        strcpy(map[i][j].thirdLine, current);
                        strcmp(map[i][j].fourthLine, "        ");
                        strcmp(map[i][j].fifthLine, "______");
                    }
                    else
                    {
                        char current[25] = "   ";
                        strcat(current, map[i][j].characters->nameForPrint);
                        strcat(current, "   ");
                        strcmp(map[i][j].firstLine, "______");
                        strcmp(map[i][j].secondLine, "      ");
                        strcpy(map[i][j].thirdLine, current);
                        strcmp(map[i][j].fourthLine, "\033[0;33m\\\\\033[0;38m      ");
                        strcmp(map[i][j].fifthLine, "\033[0;33m\\\\\033[0;38m____");
                    }
                }
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
    int z = 65;

    system("cls");
    if(1)
    {
        for(int j = 0; j < vertical / 2; j++)
        {
            printf("          ");

            printf("______");
        }
        printf("\n");

        for(int i = 0; i < horizontal; i++)
        {
            for(int j = 0; j < vertical / 2; j++)
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

            for(int j = 0; j < vertical / 2; j++)
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

            for(int j = 0; j < vertical / 2; j++)
            {
                printf("/      \\");

                printf("        ");
            }
            printf("/\n");

            for(int j = 0; j < vertical / 2; j++)
            {

                printf("/        \\");

                printf("______");
            }
            printf("/\n");
        }
        for(int j = 0; j < vertical / 2; j++)
        {

            printf("\\        /");

            printf("      ");
        }
        printf("\n ");
        for(int j = 0; j < vertical / 2; j++)
        {
            
            printf("\\______/");

            printf("        ");
        }
    }
    
    // else
    // {
    //     for(int j = 0; j < vertical / 2; j++)
    //     {
    //         printf("          ");

    //         printf("______");
    //     }
    //     printf("\n");


    //     for(int i = 0; i < horizontal; i++)
    //     {
    //         for(int j = 0; j < vertical / 2; j++)
    //         {
    //             if(i == 0 && j == 0)
    //             {
    //                 printf("         /");
    //                 printf("   2  ");
    //                 continue;
    //             }
    //             printf("\\    %c   /", z++);

    //             printf("   2  ");
    //         }
    //         if(i > 0)
    //             printf("\\    %c   /\n ", z++);
    //         else if(vertical != 1)
    //             printf("\\\n ");



    //         for(int j = 0; j < vertical / 2; j++)
    //         {
    //             if(i == 0 && j == 0)
    //             {
    //                 printf(" ______/");
    //                 printf("    4   ");
    //                 continue;
    //             }
    //             printf("\\______/");

    //             printf("    4   ");
    //         }
            
    //         if(horizontal == 1)
    //             printf("  ______\n ");
    //         else if(i > 0)
    //             printf("\\______/\n ");
    //         else
    //             printf("\\______\n ");




    //         for(int j = 0; j < vertical / 2; j++)
    //         {
    //             printf("/   %c  \\" , z++);

    //             printf("    6   ");
    //         }
    //         printf("/   %c  \\\n" ,z);

    //         for(int j = 0; j < vertical / 2; j++)
    //         {

    //             printf("/    %c   \\" ,z++);

    //             printf("______");
    //         }
    //         printf("/    %c   \\\n" ,z++);
    //     }

        
    //     for(int j = 0; j < vertical / 2; j++)
    //     {

    //         printf("\\    %c   /", z++);

    //         printf("      ");
    //     }
    //     printf("\\    %c   /\n ", z++);
    //     for(int j = 0; j < vertical / 2; j++)
    //     {
            
    //         printf("\\______/");

    //         printf("        ");
    //     }
    //     printf("\\______/");
    // }
}