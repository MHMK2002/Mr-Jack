#include "Header.h"


enum typeOfComponents{empty, block, well, wellBlocker, lamp, lampLocation, Roadblock, Exit, SG, SH, JW, JB, MS, IL, WG, JS};
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
struct Character SirWilliamGull = {"WG", "\033[0;35mWG\033[0;38m", false, 3, movementOrFunctionality};
struct Character JohnSmith = {"JS", "\033[0;33mJS\033[0;38m", false, 3, beforeOrAfter};


typedef struct PartMaP
{
    int type;
    char firstLine[25];
    char secondLine[40];
    char thirdLine[25];
    int vertical;
    int horizontal;
}part;


void board(part** map, int horizontal, int vertical);
int menu();
part** newGame();
void reset(part** map, int horizontal, int vertical);




int main()
{

    part **map = newGame();
    reset(map, 9, 13);
    printf("Hello World!!\n");
    board(map,9, 13);
    // int k = 0;
    // for(int i = 0; i < 9; i++)
    // {
    //     for(int j = 0; j < 13; j++)
    //         if(map[i][j].type == 1)
    //             printf("%d %s %s %s\n", k++, map[i][j].firstLine, map[i][j].secondLine, map[i][j].thirdLine);
    // }

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
    // printf(" / \033[0;33m __\033[0;38m  \\\n");
    // printf("/  \033[0;33m/\033[0;38mJH\033[0;33m\\\033[0;38m  \\\n");
    // printf("\\  \033[0;33m\\__/\033[0;38m  /\n");
    // printf(" \\______/\n");
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
                strcpy(map[i][j].firstLine, "      ");
                map[i][j].firstLine[6] = '\0';

                strcpy(map[i][j].secondLine, "        ");
                map[i][j].secondLine[8] = '\0';

                strcpy(map[i][j].thirdLine, "        ");
                map[i][j].thirdLine[8] = '\0';
            }
            else if(map[i][j].type == 1) //محل های بسته
            {                
                strcpy(map[i][j].firstLine, "\033[0;47m      \033[0;38m");
                map[i][j].firstLine[20] = '\0';

                strcpy(map[i][j].secondLine, "\033[0;47m        \033[0;38m");
                map[i][j].secondLine[22] = '\0';

                strcpy(map[i][j].thirdLine, "\033[0;47m        \033[0;38m");
                map[i][j].thirdLine[22] = '\0';
            }
            else if(map[i][j].type == 2) //چاه
            {                
                strcpy(map[i][j].firstLine, "  __  ");
                strcpy(map[i][j].secondLine, "  /  \\  ");
                strcpy(map[i][j].thirdLine, "  \\__/  ");
            }
            else if(map[i][j].type == 3) // درپوش چاه
            {                
                strcpy(map[i][j].firstLine, "  __  ");
                strcpy(map[i][j].secondLine, "  /\033[0;47m  \\  \033[0;38m");
                strcpy(map[i][j].thirdLine, "  \\\033[0;47m__/  \033[0;38m");
            }
            else if(map[i][j].type == 4) // چراغ
            {                
                strcpy(map[i][j].firstLine, "      ");
                strcpy(map[i][j].secondLine, "  \033[0;33m****\033[0;38m  ");
                strcpy(map[i][j].thirdLine, "  \033[0;33m****\033[0;38m  ");
            }
            else if(map[i][j].type == 5) // محل قرار گیری چراغ
            {                
                strcpy(map[i][j].firstLine, "      ");
                strcpy(map[i][j].secondLine, "  ****  ");
                strcpy(map[i][j].thirdLine, "  ****  ");
            }
            else if(map[i][j].type == 6) // مسدود کننده محل خروج
            {
                strcpy(map[i][j].firstLine, "      ");
                strcpy(map[i][j].secondLine, "\033[0;41m        \033[0;38m");
                strcpy(map[i][j].thirdLine, "\033[0;41m        \033[0;38m/");
            }
            else if(map[i][j].type == 7) // خروجی
            {                
                strcpy(map[i][j].firstLine, "      ");
                strcpy(map[i][j].secondLine, "  EXIT  ");
                strcpy(map[i][j].thirdLine, "        ");
            }
            else if(map[i][j].type == 8) //SG 
            {
                char current[40] = "   ";
                strcat(current, SergentGoodley.nameForPrint);
                strcat(current, "   ");

                strcpy(map[i][j].firstLine, "      ");
                strcpy(map[i][j].secondLine, current);
                strcpy(map[i][j].thirdLine, "        ");
            }
            else if(map[i][j].type == 9) //SH 
            {
                char current[25] = "   ";
                strcat(current, SherlockHolmes.nameForPrint);
                strcat(current, "   ");

                strcpy(map[i][j].firstLine, "      ");
                strcpy(map[i][j].secondLine, current);
                strcpy(map[i][j].thirdLine, "        ");
            }
            else if(map[i][j].type == 10) //JW 
            {
                int direction = JohnWatson.name[3] - 48;

                if(direction == north)
                { 
                    strcpy(map[i][j].firstLine, "  \033[0;33m __\033[0;38m  ");
                    strcpy(map[i][j].secondLine, JohnWatson.nameForPrint);
                    strcpy(map[i][j].thirdLine, "        ");
                }
                else if(direction == south)
                {
                    strcpy(map[i][j].firstLine, "      ");
                    strcpy(map[i][j].secondLine, JohnWatson.nameForPrint);
                    strcpy(map[i][j].thirdLine, "  \033[0;33m __\033[0;38m  ");
                }
                else if(direction == northEast)
                {
                    strcpy(map[i][j].firstLine, "      ");
                    strcpy(map[i][j].secondLine, "   ");
                    strcat(map[i][j].secondLine, JohnWatson.nameForPrint);
                    strcat(map[i][j].secondLine, "\033[0;33m\\\033[0;38m  ");
                    strcpy(map[i][j].thirdLine, "        ");
                }
                else if(direction == southEast)
                {
                    strcpy(map[i][j].firstLine, "      ");
                    strcpy(map[i][j].secondLine, JohnWatson.nameForPrint);
                    strcpy(map[i][j].thirdLine, "     \033[0;33m/\033[0;38m  ");
                }
                else if(direction == northWest)
                {
                    strcpy(map[i][j].firstLine, "      ");
                    strcpy(map[i][j].secondLine, "  \033[0;33m/\033[0;38m");
                    strcat(map[i][j].secondLine, JohnWatson.nameForPrint);
                    strcat(map[i][j].secondLine, "   ");
                    strcpy(map[i][j].thirdLine, "        ");
                }
                else
                {
                    strcpy(map[i][j].firstLine, "      ");
                    strcpy(map[i][j].secondLine, JohnWatson.nameForPrint);
                    strcpy(map[i][j].thirdLine, "  \033[0;33m\\\033[0;38m     ");
                }
            }
            else if(map[i][j].type == 11) //JB 
            {
                char current[25] = "   ";
                strcat(current, JeremyBert.nameForPrint);
                strcat(current, "   ");

                strcpy(map[i][j].firstLine, "      ");
                strcpy(map[i][j].secondLine, current);
                strcpy(map[i][j].thirdLine, "        ");
            }
            else if(map[i][j].type == 12) //MS 
            {
                char current[25] = "   ";
                strcat(current, MissStealthy.nameForPrint);
                strcat(current, "   ");

                strcpy(map[i][j].firstLine, "      ");
                strcpy(map[i][j].secondLine, current);
                strcpy(map[i][j].thirdLine, "        ");
            }
            else if(map[i][j].type == 13) //IL 
            {
                char current[25] = "   ";
                strcat(current, InspectorLestrade.nameForPrint);
                strcat(current, "   ");

                strcpy(map[i][j].firstLine, "      ");
                strcpy(map[i][j].secondLine, current);
                strcpy(map[i][j].thirdLine, "        ");
            }        
            else if(map[i][j].type == 14) //WG
            {
                char current[25] = "   ";
                strcat(current, SirWilliamGull.nameForPrint);
                strcat(current, "   ");

                strcpy(map[i][j].firstLine, "      ");
                strcpy(map[i][j].secondLine, current);
                strcpy(map[i][j].thirdLine, "        ");
            }            
            else if(map[i][j].type == 15) //JS 
            {
                char current[25] = "   ";
                strcat(current, JohnSmith.nameForPrint);
                strcat(current, "   ");

                strcpy(map[i][j].firstLine, "      ");
                strcpy(map[i][j].secondLine, current);
                strcpy(map[i][j].thirdLine, "        ");
            }
            // else if(map[i][j].type == 8) // کاراکتر
            // {
            //     if(strncmp(map[i][j].characters->name, "JW", 2) != 0)
            //     {
            //         char current[25] = "   ";
            //         strcat(current, map[i][j].characters->nameForPrint);
            //         strcat(current, "   ");

            //         strcmp(map[i][j].firstLine, "      ");
            //         strcpy(map[i][j].secondLine, current);
            //         strcmp(map[i][j].thirdLine, "        ");

            //     }
            //     else if // کاراکتر جان واتسون به دلیل داشتن فانوس در برای روشنایی یک راستا،تفاوتی در چاپ کردن با دیگر کاراکتر ها دارد،به همین خاطر از این دو شرط استفاده شده است.
            //     {
            //         int direction = map[i][j].characters->name[3] - 48;

            //         if(direction == north)
            //         { 
            //             strcmp(map[i][j].firstLine, "  \033[0;33m __\033[0;38m  ");
            //             strcmp(map[i][j].secondLine, map[i][j].characters->nameForPrint);
            //             strcmp(map[i][j].thirdLine, "        ");
            //         }
            //         else if(direction == south)
            //         {
            //             strcmp(map[i][j].firstLine, "      ");
            //             strcmp(map[i][j].secondLine, map[i][j].characters->nameForPrint);
            //             strcmp(map[i][j].thirdLine, "  \033[0;33m __\033[0;38m  ");
            //         }
            //         else if(direction == northEast)
            //         {
            //             strcmp(map[i][j].firstLine, "      ");
            //             strcmp(map[i][j].secondLine, "   ");
            //             strcat(map[i][j].secondLine, map[i][j].characters->nameForPrint);
            //             strcat(map[i][j].secondLine, "\033[0;33m\\\033[0;38m  ");
            //             strcmp(map[i][j].thirdLine, "        ");
            //         }
            //         else if(direction == southEast)
            //         {
            //             strcmp(map[i][j].firstLine, "      ");
            //             strcmp(map[i][j].secondLine, map[i][j].characters->nameForPrint);
            //             strcmp(map[i][j].thirdLine, "     \033[0;33m/\033[0;38m  ");
            //         }
            //         else if(direction == northWest)
            //         {
            //             strcmp(map[i][j].firstLine, "      ");
            //             strcmp(map[i][j].secondLine, "  \033[0;33m/\033[0;38m");
            //             strcat(map[i][j].secondLine, map[i][j].characters->nameForPrint);
            //             strcat(map[i][j].secondLine, "   ");
            //             strcmp(map[i][j].thirdLine, "        ");
            //         }
            //         else
            //         {
            //             strcmp(map[i][j].firstLine, "      ");
            //             strcmp(map[i][j].secondLine, map[i][j].characters->nameForPrint);
            //             strcmp(map[i][j].thirdLine, "  \033[0;33m\\\033[0;38m     ");
            //         }
            //     }
            // }            
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


void board(part** map, int horizontal, int vertical)
{
    int z = 65;

    reset(map, horizontal, vertical);
    system("cls");
    if(vertical % 2 == 0)
    {
        for(int j = 0; j < vertical / 2; j++)
        {
            printf("          ");

            printf("______");
        }
        printf("\n ");
        
        for(int j = 0; j < vertical / 2; j++)
        {
            printf("        ");

            printf("/%s\\" ,map[0][2 * j + 1].firstLine); // سطر اول اندیس های فرد
        }
        printf("\n  ");
        for(int j = 0; j < vertical / 2; j++)
        {
            printf("______");

            printf("/%s\\" ,map[0][2 * j + 1].secondLine); // سطر دوم اندیس های فرد
        }
        printf("\n");

        for(int i = 0; i < horizontal; i++)
        {
            printf(" ");
            for(int j = 0; j < vertical / 2; j++)
            {
                printf("/%s\\"); // سطر اول اندیس های زوج
                printf("        "); // سطر سوم اندیس های فرد
            }
            printf("/\n");

            for(int j = 0; j < vertical / 2; j++)
            {
                printf("/        \\"); // سطر دوم اندیس های زوج
                printf("______");
            }
            printf("/\n");

            for(int j = 0; j < vertical / 2; j++)
            {
                printf("\\        /"); // سطر سوم اندیس های زوج

                printf("      ");

            }
            if(i != horizontal - 1)
                printf("\\");
            printf("\n ");


            for(int j = 0;j < vertical / 2; j++)
            {
                printf("\\______/");

                printf("        ");

            }
            if(i != horizontal - 1)
                printf("\\");
            printf("\n");
        }
    }
    
    else
    {
        for(int j = 0; j < vertical / 2; j++)
        {
            printf("          ");
            printf("______");
        }
        printf("\n ");

        for(int j = 0; j < vertical / 2; j++)
        {
            printf("        ");
            printf("/%s\\" ,map[j][0].firstLine); // سطر اول اندیس های فرد
        }
        printf("\n");

        printf("  ______");
        for(int j = 0; j < vertical / 2; j++)
        {
            printf("/%s\\" ,map[j][0].secondLine); // سطر دوم اندیس های فرد

            printf("______");
        }
        printf("\n");


        for(int i = 0; i < horizontal; i++)
        {
            printf(" /%s\\" ,map[i][0].firstLine); // سطر اول اندیس های زوج
            for(int j = 0; j < vertical / 2; j++)
            {
                printf("%s" ,map[i][2 * j + 1].thirdLine); // سطر سوم اندیس های فرد
                printf("/%s\\" ,map[i][2 * j].firstLine); // سطر اول اندیس های زوج
            }
            printf("\n");

            printf("/%s\\" , map[i][0].secondLine); // سطر دوم اندیس های زوج
            for(int j = 0; j < vertical / 2; j++)
            {
                printf("______");

                printf("/%s\\", map[i][2 * j].secondLine); // سطر دوم اندیس های زوج
            }
            printf("\n");

            printf("\\%s/", map[i][0].thirdLine); // سطر سوم اندیس های زوج
            for(int j = 0; j < vertical / 2; j++)
            {
                printf("      ");

                printf("\\%s/", map[i][j].thirdLine); // سطر سوم اندیس های زوج
            }
            printf("\n");

            printf(" \\______/");
            for(int j = 0;j < vertical / 2; j++)
            {
                printf("        ");

                printf("\\______/");
            }
            printf("\n");
        }
    }




}






















int menu()
{
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