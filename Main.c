#include "Header.h"


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

enum typeOfComponents{empty, block, well, wellBlocker, lamp, lampLocation, Roadblock, Exit, SG, SH, JW, JB, MS, IL, WG, JS};
enum ORDER{beforeOrAfter, afterMovement, movementOrFunctionality, simultaneous};
enum Direction{north, south, northEast, southEast, northWest, southWest};
struct Character SergentGoodley = {"SG", "\033[1;34mS\033[1;31mG\033[0;38m", false, 4, beforeOrAfter};
struct Character SherlockHolmes = {"SH", "\033[1;31mSH\033[0;38m", false, 3, afterMovement};
struct Character JohnWatson = {"JW 0", "\033[1;33mJW\033[0;38m", false, 3, afterMovement};
struct Character JeremyBert = {"JB", "\033[1;36mJB\033[0;38m", false, 3, beforeOrAfter};
struct Character MissStealthy = {"MS", "\033[1;32mMS\033[0;38m", false, 3, simultaneous};
struct Character InspectorLestrade = {"IL", "\033[1;34mIN\033[0;38m", false, 3, beforeOrAfter};
struct Character SirWilliamGull = {"WG", "\033[1;35mWG\033[0;38m", false, 3, movementOrFunctionality};
struct Character JohnSmith = {"JS", "\033[1;33mJS\033[0;38m", false, 3, beforeOrAfter};



typedef struct PartMaP
{
    int type;
    char firstLine[25];
    char secondLine[40];
    char thirdLine[25];
    char fourthLine[25];
    int vertical;
    int horizontal;
}part;


void board(part** map, int horizontal, int vertical);
int menu();
part** newGame();
void reset(part** map, int horizontal, int vertical);
void Description();
void DecelerationOfAimOfGame();
void DecelerationOfRulesOfGame();
void DecelerationOfWaysToEnd();
void DecelerationOfCharacters();
void DecelerationOfWell();
void DecelerationOfBlockedPlaces();
void DecelerationOfLamp();
void DecelerationOfExit();

char* toString(int numberOne, int numberTwo);
void help();

int main()
{
    Description();
    // help();
    // int choice = menu();
    // switch (choice)
    // {
    //     case 1:
    //     {

    //     }
    //     case 2:
    //     {

    //     }
    //     case 3:
    //     {

    //     }
    //     case 4:
    //     {

    //     }
    //     case 5:
    //         return 0;
    // }
}

void reset(part** map, int horizontal, int vertical) // این تابع هر بار کل نقشه را بررسی می کند و هربار نقشه را پس از تغییر چاپ می کند.
{
    for(int i = 0; i < horizontal; i++)
    {
        for(int j = 0; j < vertical; j++)
        {
            strcpy(map[i][j].fourthLine ,"\033[4;37m");
            strcat(map[i][j].fourthLine ,toString(i ,j));
            strcat(map[i][j].fourthLine ,"\033[0;38m");

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
                int random = rand() % 3;                
                strcpy(map[i][j].firstLine, "      ");
                map[i][j].firstLine[6] = '\0';
                if(random == 0) // white
                {
                    strcpy(map[i][j].secondLine, "\033[0;37m########\033[0;38m");
                    map[i][j].secondLine[22] = '\0';

                    strcpy(map[i][j].thirdLine, "\033[0;37m########\033[0;38m");
                    map[i][j].thirdLine[22] = '\0';
                }
                else if(random == 1) // Green
                {
                    strcpy(map[i][j].secondLine, "\033[0;32m########\033[0;38m");
                    map[i][j].secondLine[22] = '\0';

                    strcpy(map[i][j].thirdLine, "\033[0;32m########\033[0;38m");
                    map[i][j].thirdLine[22] = '\0';
                }
                else // Cyan
                {
                    strcpy(map[i][j].secondLine, "\033[0;36m########\033[0;38m");
                    map[i][j].secondLine[22] = '\0';

                    strcpy(map[i][j].thirdLine, "\033[0;36m########\033[0;38m");
                    map[i][j].thirdLine[22] = '\0';
                }

            }
            else if(map[i][j].type == 2) //چاه
            {                
                strcpy(map[i][j].firstLine, " ____ ");
                map[i][j].firstLine[6] = '\0';
                strcpy(map[i][j].secondLine, " /    \\ ");
                map[i][j].secondLine[8] = '\0';
                strcpy(map[i][j].thirdLine, " \\____/ ");
            }
            else if(map[i][j].type == 3) // درپوش چاه
            {                
                strcpy(map[i][j].firstLine, " ____ ");
                map[i][j].firstLine[6] = '\0';
                strcpy(map[i][j].secondLine, " /\033[0;41m    \033[0;38m\\ ");
                strcpy(map[i][j].thirdLine, " \\\033[0;41m____\033[0;38m/ ");
            }
            else if(map[i][j].type == 4) // چراغ
            {                
                strcpy(map[i][j].firstLine, "      ");
                map[i][j].firstLine[6] = '\0';
                strcpy(map[i][j].secondLine, "  \033[0;33m****\033[0;38m  ");
                strcpy(map[i][j].thirdLine, "  \033[0;33m****\033[0;38m  ");
            }
            else if(map[i][j].type == 5) // محل قرار گیری چراغ
            {                
                strcpy(map[i][j].firstLine, "      ");
                map[i][j].firstLine[6] = '\0';
                strcpy(map[i][j].secondLine, "  ****  ");
                map[i][j].secondLine[8] = '\0';
                strcpy(map[i][j].thirdLine, "  ****  ");
                map[i][j].thirdLine[8] = '\0';
            }
            else if(map[i][j].type == 6) // مسدود کننده محل خروج
            {
                strcpy(map[i][j].firstLine, "      ");
                map[i][j].firstLine[6] = '\0';
                strcpy(map[i][j].secondLine, "\033[0;41m        \033[0;38m");
                map[i][j].secondLine[22] = '\0';
                strcpy(map[i][j].thirdLine, "\033[0;41m        \033[0;38m/");
                map[i][j].thirdLine[22] = '\0';
            }
            else if(map[i][j].type == 7) // خروجی
            {                
                strcpy(map[i][j].firstLine, "      ");
                map[i][j].firstLine[6] = '\0';
                strcpy(map[i][j].secondLine, "  EXIT  ");
                map[i][j].secondLine[8] = '\0';
                strcpy(map[i][j].thirdLine, "        ");
                map[i][j].thirdLine[8] = '\0';
            }
            else if(map[i][j].type == 8) //SG 
            {
                char current[40] = "   ";
                map[i][j].firstLine[6] = '\0';
                strcat(current, SergentGoodley.nameForPrint);
                strcat(current, "   ");

                strcpy(map[i][j].firstLine, "      ");
                strcpy(map[i][j].secondLine, current);
                map[i][j].secondLine[33] = '\0';
                strcpy(map[i][j].thirdLine, "        ");
                map[i][j].thirdLine[8] = '\0';

            }
            else if(map[i][j].type == 9) //SH 
            {
                char current[25] = "   ";
                strcat(current, SherlockHolmes.nameForPrint);
                strcat(current, "   ");

                strcpy(map[i][j].firstLine, "      ");
                map[i][j].firstLine[6] = '\0';
                strcpy(map[i][j].secondLine, current);
                strcpy(map[i][j].thirdLine, "        ");
                map[i][j].thirdLine[8] = '\0';
            }
            else if(map[i][j].type == 10) //JW 
            {
                int direction = JohnWatson.name[3] - 48;

                if(direction == north)
                { 
                    strcpy(map[i][j].firstLine, "  \033[0;33m__\033[0;38m  ");
                    strcpy(map[i][j].secondLine, "   ");
                    strcat(map[i][j].secondLine, JohnWatson.nameForPrint);
                    strcat(map[i][j].secondLine, "   ");
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
                map[i][j].firstLine[6] = '\0';
                strcpy(map[i][j].secondLine, current);
                strcpy(map[i][j].thirdLine, "        ");
                map[i][j].thirdLine[8] = '\0';
            }
            else if(map[i][j].type == 12) //MS 
            {
                char current[25] = "   ";
                strcat(current, MissStealthy.nameForPrint);
                strcat(current, "   ");

                strcpy(map[i][j].firstLine, "      ");
                map[i][j].firstLine[6] = '\0';
                strcpy(map[i][j].secondLine, current);
                strcpy(map[i][j].thirdLine, "        ");
                map[i][j].thirdLine[8] = '\0';
            }
            else if(map[i][j].type == 13) //IL 
            {
                char current[25] = "   ";
                strcat(current, InspectorLestrade.nameForPrint);
                strcat(current, "   ");

                strcpy(map[i][j].firstLine, "      ");
                map[i][j].firstLine[6] = '\0';
                strcpy(map[i][j].secondLine, current);
                strcpy(map[i][j].thirdLine, "        ");
                map[i][j].thirdLine[8] = '\0';
            }        
            else if(map[i][j].type == 14) //WG
            {
                char current[25] = "   ";
                strcat(current, SirWilliamGull.nameForPrint);
                strcat(current, "   ");

                strcpy(map[i][j].firstLine, "      ");
                map[i][j].firstLine[6] = '\0';
                strcpy(map[i][j].secondLine, current);
                strcpy(map[i][j].thirdLine, "        ");
                map[i][j].thirdLine[8] = '\0';
            }            
            else if(map[i][j].type == 15) //JS 
            {
                char current[25] = "   ";
                strcat(current, JohnSmith.nameForPrint);
                strcat(current, "   ");

                strcpy(map[i][j].firstLine, "      ");
                map[i][j].firstLine[6] = '\0';
                strcpy(map[i][j].secondLine, current);
                strcpy(map[i][j].thirdLine, "        ");
                map[i][j].thirdLine[8] = '\0';
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

void board(part** map, int horizontal, int vertical)
{
    int z = 65;

    reset(map, horizontal, vertical);
    system("cls");
    if(vertical % 2 == 0)
    {
        for(int j = 1; j <= vertical / 2; j++)
        {
            printf("          ");

            printf("______");
        }
        printf("\n ");
        
        for(int j = 1; j <= vertical / 2; j++)
        {
            printf("        ");

            printf("/%s\\" ,map[0][2 * j - 1].firstLine); // سطر اول اندیس های فرد
        }
        printf("\n  ");
        for(int j = 1; j <= vertical / 2; j++)
        {
            printf("______");

            printf("/%s\\" ,map[0][2 * j - 1].secondLine); // سطر دوم اندیس های فرد
        }
        printf("\n");

        for(int i = 0; i < horizontal; i++)
        {
            printf(" ");
            for(int j = 0; j < vertical / 2; j++)
            {
                printf("/%s\\" ,map[i][2 * j].firstLine); // سطر اول اندیس های زوج
                printf("%s" ,map[i][2 * j + 1].thirdLine); // سطر سوم اندیس های فرد
            }
            printf("/\n");

            for(int j = 0; j < vertical / 2; j++)
            {
                printf("/%s\\" ,map[i][2 * j].secondLine); // سطر دوم اندیس های زوج

                printf("%s" ,map[i][2 * j + 1].fourthLine); // سطر چهارم اندیس های فرد
            }
            printf("/\n");

            for(int j = 0; j < vertical / 2; j++)
            {
                printf("\\%s/" ,map[i][2 * j].thirdLine); // سطر سوم اندیس های زوج

                if(i == horizontal - 1)
                    printf("      ");// سطر اول اندیس های فرد
                else
                    printf("%s" ,map[i + 1][2 * j + 1].firstLine);// سطر اول اندیس های فرد


            }
            if(i != horizontal - 1)
                printf("\\");
            printf("\n ");


            for(int j = 1 ; j <= vertical / 2; j++)
            {
                printf("\\%s/" , map[i][2 * j - 2].fourthLine); // سطر چهارم اندیس های زوج

                if(i == horizontal - 1)
                    printf("        "); // سطر دوم اندیس های فرد
                else
                    printf("%s" ,map[i + 1][2 * j - 1].secondLine); // سطر دوم اندیس های فرد

            }
            if(i != horizontal - 1)
                printf("\\");
            printf("\n");
        }
    }
    
    else
    {
        for(int j = 1; j <= vertical / 2; j++)
        {
            printf("          ");
            printf("______");
        }
        printf("\n ");

        for(int j = 1; j <= vertical / 2; j++)
        {
            printf("        ");
            printf("/%s\\" ,map[0][2 * j - 1].firstLine); // سطر اول اندیس های فرد
        }
        printf("\n");

        printf("  ______");
        for(int j = 1; j <= vertical / 2; j++)
        {
            printf("/%s\\" ,map[0][2 * j - 1].secondLine); // سطر دوم اندیس های فرد

            printf("______");
        }
        printf("\n");


        for(int i = 0; i < horizontal; i++)
        {
            printf(" /%s\\" ,map[i][0].firstLine); // سطر اول اندیس های زوج
            for(int j = 1; j <= vertical / 2; j++)
            {
                printf("%s" ,map[i][2 * j - 1].thirdLine); // سطر سوم اندیس های فرد
                printf("/%s\\" ,map[i][2 * j].firstLine); // سطر اول اندیس های زوج
            }
            printf("\n");

            printf("/%s\\" , map[i][0].secondLine); // سطر دوم اندیس های زوج
            for(int j = 1; j <= vertical / 2; j++)
            {
                printf("%s" ,map[i][2 * j - 1].fourthLine); // سطر چهارم اندیس های فرد

                printf("/%s\\", map[i][2 * j].secondLine); // سطر دوم اندیس های زوج
            }
            printf("\n");

            printf("\\%s/", map[i][0].thirdLine); // سطر سوم اندیس های زوج
            for(int j = 1; j <= vertical / 2; j++)
            {
                if(i == horizontal - 1)
                    printf("      ");
                else
                    printf("%s", map[i + 1][2 * j - 1].firstLine); // سطر اول اندیس های فرد

                printf("\\%s/", map[i][2 * j].thirdLine); // سطر سوم اندیس های زوج
            }
            printf("\n");

            printf(" \\%s/" ,map[i][0].fourthLine); // سطر چهارم اندیس های زوج
            for(int j = 1; j <= vertical / 2; j++)
            {
                if(i == horizontal - 1)
                    printf("        ");
                else
                    printf("%s", map[i  + 1][2 * j - 1].secondLine); // سطر دوم اندیس های فرد

                printf("\\%s/" ,map[i][2 * j].fourthLine); // سطر چهارم اندیس های زوج
            }
            printf("\n");
        }
    }




}

char* toString(int numberOne, int numberTwo)
{
    char* output = (char*)malloc(7 * sizeof(char));

    if(numberOne < 10)
    {
        output[0] = ' ';
        output[1] = numberOne + 48;
    }
    else
    {
        output[0] = numberOne / 10 + 48;
        output[1] = numberOne % 10 + 48;
    }
    output[2] = ' ';
    output[3] = ' ';

    if(numberTwo < 10)
    {
        output[4] = numberTwo + 48;
        output[5] = ' ';
    }
    else
    {
        output[4] = numberTwo / 10 + 48;
        output[5] = numberTwo % 10 + 48;
    }

    output[6] = '\0';

    return output;
}

int menu()
{
    system("cls");

    printRed();
    printf("\t\t\t\t\t\t\t\t\t             \033[3;33mMr Jack Board Game         \n\n");
    printGreen();
    printf("\t\t\t\t\t\t\t\t\t  * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t\t\t\t\t\t  *                                     *\n");
    printf("\t\t\t\t\t\t\t\t\t  *                                     *\n");

    printf("\t\t\t\t\t\t\t\t\t  *            ");
    printf("\033[3;34m1 - New game");
    printGreen();
    printf("             *\n");

    printf("\t\t\t\t\t\t\t\t\t  *                                     *\n");

    printf("\t\t\t\t\t\t\t\t\t  *            ");
    printf("\033[3;34m2 - Load Game");
    printGreen();
    printf("            *\n");

    printf("\t\t\t\t\t\t\t\t\t  *                                     *\n");

    printf("\t\t\t\t\t\t\t\t\t  *            ");
    printf("\033[3;34m3 - Create Map");
    printGreen();
    printf("           *\n");

    printf("\t\t\t\t\t\t\t\t\t  *                                     *\n");
    
    printf("\t\t\t\t\t\t\t\t\t  *            ");
    printf("\033[3;34m4 - Help game");
    printGreen();
    printf("            *\n");

    printf("\t\t\t\t\t\t\t\t\t  *                                     *\n");
    
    printf("\t\t\t\t\t\t\t\t\t  *            ");
    printf("\033[3;34m5 - Exit");
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

void Description()
{
    system("cls");

    printf("\033[1;31mDescription\033[0m\n\n");
    printf("\t1888 - London - Whitechapel district.\n\tThe night covers the gloomy alleys with a veil of darkness.\n\tJack is moving in the shadows...\n\tThe finest investigators of the gaslight age have gathered\n");

    printf("\n\nPlease press ENTER key to continue...");
    getchar();

    DecelerationOfAimOfGame();
}

void DecelerationOfAimOfGame()
{
    system("cls");

    printf("\033[1;31mAim of the game\033[0m\n\n");
    printf("\tThe goal of the player who plays \"Jack\" is to \n\tescape the investigator before dawn or to leave\n\tthe district by taking advantage of the darkness.\n\tFor the player who is \"the detective\", his \n\tgoal is to uncover which investigator Jack is\n\timpersonating and to catch him before dawn\n");

    int choice;

    printf("\n\n1 - Undo");
    printf("\n2 - Continue\n");
    scanf("%d", &choice);
    getchar();

    if(choice == 1)
        Description();
    else
        DecelerationOfRulesOfGame();
}

void DecelerationOfRulesOfGame()
{
    system("cls");

    printf("\033[1;31mRules of the game\033[0m\n\n");
    printf("\tEight investigators have gathered to catch the cunning\n\tJack. But Jack is in fact cleverly impersonating one \n\tof them. By moving each character into light or shadow,\n\tthe detective player makes successive deductions to \n\tuncover which investigator is in fact Jack, then \n\the/she must try to catch the infamous Jack.\n\tThe opponent, playing Jack, must do his best to delay\n\tthe investigation. He can even try to use the darkness\n\tto secretly flee the district!\n");


    int choice;

    printf("\n\n1 - Undo");
    printf("\n2 - Continue\n");
    scanf("%d", &choice);
    getchar();

    if(choice == 1)
        DecelerationOfAimOfGame();
    else
        DecelerationOfWaysToEnd();
}

void DecelerationOfWaysToEnd()
{
    system("cls");

    printf("\033[1;31mWays to end the game\033[0m\n\n");

    printf("Ways to Win Jack Ways                                     Ways to Win a Detective\n");
    printf("1 - Escape the map invisibly                              1 - Catch Jack\n");
    printf("2 - Detective arrest someone else\n");
    printf("3 - The game lasts 8 rounds and Jack is not caught\n");

    int choice;

    printf("\n\n1 - Undo");
    printf("\n2 - Continue\n");
    scanf("%d", &choice);
    getchar();

    if(choice == 1)
        DecelerationOfRulesOfGame();
    else
        DecelerationOfCharacters();
}

void DecelerationOfCharacters()
{    
    system("cls");

    printf("\033[1;31mContent of the game\033[0m\n\n");

    printf("1 - Characters: \n");
    printf(" *Sherlock Holmes %s\n" ,SherlockHolmes.nameForPrint);
    printf(" *John H. Watson %s\n" ,JohnWatson.nameForPrint);
    printf(" *John Smith %s\n" ,JohnSmith.nameForPrint);
    printf(" *Inspector Lestrade %s\n" ,InspectorLestrade.nameForPrint);
    printf(" *Miss Stealthy %s\n" ,MissStealthy.nameForPrint);
    printf(" *Sergeant Goodley %s\n" ,SergentGoodley.nameForPrint);
    printf(" *Sir William Gull %s\n" ,SirWilliamGull.nameForPrint);
    printf(" *Jeremy Bert %s\n" ,JeremyBert.nameForPrint);


    int choice;

    printf("\n\n1 - Undo");
    printf("\n2 - Continue\n");
    scanf("%d", &choice);
    getchar();

    if(choice == 1)
        DecelerationOfWaysToEnd();
    else
        DecelerationOfWell();
}

void DecelerationOfWell()
{
    system("cls");

    printf("\033[1;31mWell\033[0m\n");
    printf("    ____ \n");
    printf("   /    \\\n");
    printf("   \\____/\n\n");


    printf("\033[1;31mWell Blocker\033[0m\n");
    printf("    ____ \n");
    printf("   /\033[0;41m    \033[0;38m\\\n");
    printf("   \\\033[0;41m    \033[0;38m/\n");


    int choice;

    printf("\n\n1 - Undo");
    printf("\n2 - Continue\n");
    scanf("%d", &choice);
    getchar();

    if(choice == 1)
        DecelerationOfCharacters();
    else
        DecelerationOfBlockedPlaces();
}

void DecelerationOfBlockedPlaces()
{
    system("cls");

    printf("\033[1;31mBlocked places\033[0m\n");

    printf("  ______      \t  ______      \t  ______  \n");
    printf(" /      \\     \t /      \\    \t /      \\\n");
    printf("/########\\ OR \t/\033[0;36m########\033[0;38m\\ OR \t/\033[0;32m########\033[0;38m\\\n");
    printf("\\########/    \t\\\033[0;36m########\033[0;38m/    \t\\\033[0;32m########\033[0;38m/\n");
    printf(" \\______/     \t \\______/     \t \\______/");


    int choice;

    printf("\n\n1 - Undo");
    printf("\n2 - Continue\n");
    scanf("%d", &choice);
    getchar();

    if(choice == 1)
        DecelerationOfWell();
    else
        DecelerationOfLamp();
}

void DecelerationOfLamp()
{
    system("cls");

    printf("\033[1;31mLamp\033[0m\n");

    printf(" \033[0;33m****\n ****\033[0;38m\n");


    printf("\n\033[1;31mLamp location\033[0m\n");

    printf(" ****\n ****\n");

    int choice;

    printf("\n\n1 - Undo");
    printf("\n2 - Continue\n");
    scanf("%d", &choice);
    getchar();

    if(choice == 1)
        DecelerationOfBlockedPlaces();
    else
        DecelerationOfExit();

}

void DecelerationOfExit()
{
    system("cls");


    printf("\033[1;31mExit map location\033[0m\n");


    printf("\t   ______\n");
    printf("\t  /      \\\n");
    printf("\t /  EXIT  \\\n");
    printf("\t \\        /\n");
    printf("\t  \\______/\n\n");


    printf("\033[1;31mExit map blocker\033[0m\n\n");

    printf("\t   ______\n");
    printf("\t  /      \\\n");
    printf("\t /\033[0;41m        \033[0;38m\\\n");
    printf("\t \\\033[0;41m        \033[0;38m/\n");
    printf("\t  \\______/");


    int choice;

    printf("\n\n1 - Undo");
    printf("\n2 - Exit");
    printf("3 - See again\n");
    scanf("%d", &choice);
    getchar();

    if(choice == 1)
        DecelerationOfLamp();
    else if(choice == 2)
        return;
    else    
        Description();
}











