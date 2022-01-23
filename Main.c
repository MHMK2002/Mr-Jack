#include "Header.h"
#define firstPlayer 0
#define secondPlayer 1
#define enumPrint(E) (#E)



typedef struct Character
{
    char name[5];
    char nameForPrint[25];
    bool visible;
    int maximumOfMovement;
    short order;
    int horizontal;
    int vertical;
}Character;

typedef struct Node
{
    Character* character;
    
    struct Node* next;
}Node;


enum typeOfComponents{empty, block, well, wellBlocker, lamp, lampLocation, Roadblock, Exit};
enum ORDER{beforeOrAfter, afterMovement, movementOrFunctionality, simultaneous};
enum Direction{north, south, northEast, southEast, northWest, southWest};




Character SergentGoodley = {"SG", "\033[1;34mS\033[1;31mG\033[0;38m", false, 4, beforeOrAfter};
Character SherlockHolmes = {"SH", "\033[1;31mSH\033[0;38m", false, 3, afterMovement};
Character JohnWatson = {"JW 2", "\033[1;33mJW\033[0;38m", false, 3, afterMovement};
Character JeremyBert = {"JB", "\033[1;36mJB\033[0;38m", false, 3, beforeOrAfter};
Character MissStealthy = {"MS", "\033[1;32mMS\033[0;38m", false, 3, simultaneous};
Character InspectorLestrade = {"IN", "\033[1;34mIN\033[0;38m", false, 3, beforeOrAfter};
Character SirWilliamGull = {"WG", "\033[1;35mWG\033[0;38m", false, 3, movementOrFunctionality};
Character JohnSmith = {"JS", "\033[1;33mJS\033[0;38m", false, 3, beforeOrAfter};




typedef struct PartMaP
{
    int type;
    char firstLine[25];
    char secondLine[40];
    char thirdLine[25];
    char fourthLine[25];
    int vertical;
    int horizontal;
    Character *character;
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
Node* TheSuspects();
void removeNodeByName(Node** head, char name[3]);
int checkIsCorrect(Node* head, char name[3]);
char* toString(int numberOne, int numberTwo);
void help();
int game(part** map, int horizontal, int vertical);
void setVisible(part** map ,int horizontal ,int vertical);
void exchangeCharacter(part** map, int firstHorizontal, int firstVertical, int secondHorizontal, int secondVertical);
Character* removeNode(Node** head, int length);
Node* newNode(Character* character);
void addNode(Node** head, Node* newNode);
Node** random();
void print(Node* head);
int checkIsCorrectForOperation(part** map, int horizontal, int vertical, int type);
void exchange(part** map, int firstHorizontal, int firstVertical, int secondHorizontal, int secondVertical, int firstType, int secondType);
int** copyMap(part** map ,int horizontal ,int vertical);


int game(part** map, int horizontal, int vertical) // این تابع اصلی بازی است.
{

    // اگر تابع یک را برگرداند جک برنده شده،در غیر اینصورت کارآگاه برنده شده است.

    system("cls");
    resetColor();
    int jack;
    int detective;
    int current;
    current = rand() % 2;
    if(current)
        printf("\t\tJack is first Player\tDetective is second Player");
    else
        printf("\t\tJack is second Player\tDetective is first Player");

    printf("\n\nPlease Press ENTER key to continue...");
    getchar();


    jack = current;
    detective = !current;
    int round = 1;


    Node* theSuspects = TheSuspects();
    int counterOfTheSuspects = 8;
    Node* jackCharacter = NULL;
    Node* innocents = NULL;
    addNode(&jackCharacter, newNode(removeNode(&theSuspects, rand() % counterOfTheSuspects--)));
    printf("\n>>>>>>%s is Jack",jackCharacter->character->nameForPrint);

    printf("\n\nPlease Press ENTER key to continue...");
    getchar();

    if(current)
    {
        while(round <= 8)
        {
            
            Node** head = random();

            { // راند های فرد
                char curr[5];


                // کارت اول
                while(1)
                {
                    board(map, horizontal, vertical);
                    printf("\n\n");
                    print(head[0]);

                    printf("\n\nPlease choice  your card...\n");
                    printf("The second player chooses a card : ");
                
                    scanf("%s" , &curr);
                    if(checkIsCorrect(head[0], curr))
                        break;
                    printf("\nPlease enter correctly -_-");
                    printf("\nPlease press ENTER to continue...");
                    getchar();
                    getchar();
                }
                
                removeNodeByName(&head[0] ,curr);
                // تا این قسمت اولین کارت راند های فرد انتخاب شده است.
                
                
                // کارت دوم
                while(1)
                {
                    board(map, horizontal, vertical);
                    printf("\n\n");
                    print(head[0]);

                    printf("\n\nPlease choice  your card...\n");
                    printf("The first player chooses a card : ");
                
                    scanf("%s" , &curr);
                    if(checkIsCorrect(head[0], curr))
                        break;
                    printf("\nPlease enter correctly -_-");
                    printf("\nPlease press ENTER to continue...");
                    getchar();
                    getchar();
                }
                
                removeNodeByName(&head[0] ,curr);
                // تا این قسمت دومین کارت راند های فرد انتخاب شده است.


                // کارت سوم
                while(1)
                {
                    board(map, horizontal, vertical);
                    printf("\n\n");
                    print(head[0]);

                    printf("\n\nPlease choice  your card...\n");
                    printf("The first player chooses a card : ");
                
                    scanf("%s" , &curr);
                    if(checkIsCorrect(head[0], curr))
                        break;
                    printf("\nPlease enter correctly -_-");
                    printf("\nPlease press ENTER to continue...");
                    getchar();
                    getchar();
                }
                
                removeNodeByName(&head[0] ,curr);
                // تا این قسمت سومین کارت راند های فرد انتخاب شده است.



                // کارت چهارم
                while(1)
                {
                    board(map, horizontal, vertical);
                    printf("\n\n");
                    print(head[0]);

                    printf("\n\nPlease choice  your card...\n");
                    printf("The second player chooses a card : ");
                
                    scanf("%s" , &curr);
                    if(checkIsCorrect(head[0], curr))
                        break;
                    printf("\nPlease enter correctly -_-");
                    printf("\nPlease press ENTER to continue...");
                    getchar();
                    getchar();
                }
                
                removeNodeByName(&head[0] ,curr);

                round++;
            }



            { // راند های زوج
                char curr[5];


                // کارت اول
                while(1)
                {
                    board(map, horizontal, vertical);
                    printf("\n\n");
                    print(head[1]);

                    printf("\n\nPlease choice  your card...\n");
                    printf("The first player chooses a card : ");
                
                    scanf("%s" , &curr);
                    if(checkIsCorrect(head[1], curr))
                        break;
                    printf("\nPlease enter correctly -_-");
                    printf("\nPlease press ENTER to continue...");
                    getchar();
                    getchar();
                }
                
                removeNodeByName(&head[1] ,curr);
                // تا این قسمت اولین کارت راند های فرد انتخاب شده است.
                
                
                // کارت دوم
                while(1)
                {
                    board(map, horizontal, vertical);
                    printf("\n\n");
                    print(head[1]);

                    printf("\n\nPlease choice  your card...\n");
                    printf("The second player chooses a card : ");
                
                    scanf("%s" , &curr);
                    if(checkIsCorrect(head[1], curr))
                        break;
                    printf("\nPlease enter correctly -_-");
                    printf("\nPlease press ENTER to continue...");
                    getchar();
                    getchar();
                }
                
                removeNodeByName(&head[1] ,curr);
                // تا این قسمت دومین کارت راند های فرد انتخاب شده است.


                // کارت سوم
                while(1)
                {
                    board(map, horizontal, vertical);
                    printf("\n\n");
                    print(head[1]);

                    printf("\n\nPlease choice  your card...\n");
                    printf("The second player chooses a card : ");
                
                    scanf("%s" , &curr);
                    if(checkIsCorrect(head[1], curr))
                        break;
                    printf("\nPlease enter correctly -_-");
                    printf("\nPlease press ENTER to continue...");
                    getchar();
                    getchar();
                }
                
                removeNodeByName(&head[1] ,curr);
                // تا این قسمت سومین کارت راند های فرد انتخاب شده است.



                // کارت چهارم
                while(1)
                {
                    board(map, horizontal, vertical);
                    printf("\n\n");
                    print(head[1]);

                    printf("\n\nPlease choice  your card...\n");
                    printf("The first player chooses a card : ");
                
                    scanf("%s" , &curr);
                    if(checkIsCorrect(head[1], curr))
                        break;
                    printf("\nPlease enter correctly -_-");
                    printf("\nPlease press ENTER to continue...");
                    getchar();
                    getchar();
                }
                
                removeNodeByName(&head[1] ,curr);

                round++;
            }   
        }
    }




    else
    {
        while(round <= 8)
        {
            
            Node** head = random();

            { // راند های فرد
                char curr[5];


                // کارت اول
                while(1)
                {
                    board(map, horizontal, vertical);
                    printf("\n\n");
                    print(head[0]);

                    printf("\n\nPlease choice  your card...\n");
                    printf("The first player chooses a card : ");
                
                    scanf("%s" , &curr);
                    if(checkIsCorrect(head[0], curr))
                        break;
                    printf("\nPlease enter correctly -_-");
                    printf("\nPlease press ENTER to continue...");
                    getchar();
                    getchar();
                }
                
                removeNodeByName(&head[0] ,curr);
                // تا این قسمت اولین کارت راند های فرد انتخاب شده است.
                
                
                // کارت دوم
                while(1)
                {
                    board(map, horizontal, vertical);
                    printf("\n\n");
                    print(head[0]);

                    printf("\n\nPlease choice  your card...\n");
                    printf("The second player chooses a card : ");
                
                    scanf("%s" , &curr);
                    if(checkIsCorrect(head[0], curr))
                        break;
                    printf("\nPlease enter correctly -_-");
                    printf("\nPlease press ENTER to continue...");
                    getchar();
                    getchar();
                }
                
                removeNodeByName(&head[0] ,curr);
                // تا این قسمت دومین کارت راند های فرد انتخاب شده است.


                // کارت سوم
                while(1)
                {
                    board(map, horizontal, vertical);
                    printf("\n\n");
                    print(head[0]);

                    printf("\n\nPlease choice  your card...\n");
                    printf("The second player chooses a card : ");
                
                    scanf("%s" , &curr);
                    if(checkIsCorrect(head[0], curr))
                        break;
                    printf("\nPlease enter correctly -_-");
                    printf("\nPlease press ENTER to continue...");
                    getchar();
                    getchar();
                }
                
                removeNodeByName(&head[0] ,curr);
                // تا این قسمت سومین کارت راند های فرد انتخاب شده است.



                // کارت چهارم
                while(1)
                {
                    board(map, horizontal, vertical);
                    printf("\n\n");
                    print(head[0]);

                    printf("\n\nPlease choice  your card...\n");
                    printf("The first player chooses a card : ");
                
                    scanf("%s" , &curr);
                    if(checkIsCorrect(head[0], curr))
                        break;
                    printf("\nPlease enter correctly -_-");
                    printf("\nPlease press ENTER to continue...");
                    getchar();
                    getchar();
                }
                
                removeNodeByName(&head[0] ,curr);

                round++;
            }



            { // راند های زوج
                char curr[5];


                // کارت اول
                while(1)
                {
                    board(map, horizontal, vertical);
                    printf("\n\n");
                    print(head[1]);

                    printf("\n\nPlease choice  your card...\n");
                    printf("The second player chooses a card : ");
                
                    scanf("%s" , &curr);
                    if(checkIsCorrect(head[1], curr))
                        break;
                    printf("\nPlease enter correctly -_-");
                    printf("\nPlease press ENTER to continue...");
                    getchar();
                    getchar();
                }
                
                removeNodeByName(&head[1] ,curr);
                // تا این قسمت اولین کارت راند های فرد انتخاب شده است.
                
                
                // کارت دوم
                while(1)
                {
                    board(map, horizontal, vertical);
                    printf("\n\n");
                    print(head[1]);

                    printf("\n\nPlease choice  your card...\n");
                    printf("The first player chooses a card : ");
                
                    scanf("%s" , &curr);
                    if(checkIsCorrect(head[1], curr))
                        break;
                    printf("\nPlease enter correctly -_-");
                    printf("\nPlease press ENTER to continue...");
                    getchar();
                    getchar();
                }
                
                removeNodeByName(&head[1] ,curr);
                // تا این قسمت دومین کارت راند های فرد انتخاب شده است.


                // کارت سوم
                while(1)
                {
                    board(map, horizontal, vertical);
                    printf("\n\n");
                    print(head[1]);

                    printf("\n\nPlease choice  your card...\n");
                    printf("The first player chooses a card : ");
                
                    scanf("%s" , &curr);
                    if(checkIsCorrect(head[1], curr))
                        break;
                    printf("\nPlease enter correctly -_-");
                    printf("\nPlease press ENTER to continue...");
                    getchar();
                    getchar();
                }
                
                removeNodeByName(&head[1] ,curr);
                // تا این قسمت سومین کارت راند های فرد انتخاب شده است.



                // کارت چهارم
                while(1)
                {
                    board(map, horizontal, vertical);
                    printf("\n\n");
                    print(head[1]);

                    printf("\n\nPlease choice  your card...\n");
                    printf("The second player chooses a card : ");
                
                    scanf("%s" , &curr);
                    if(checkIsCorrect(head[1], curr))
                        break;
                    printf("\nPlease enter correctly -_-");
                    printf("\nPlease press ENTER to continue...");
                    getchar();
                    getchar();
                }
                
                removeNodeByName(&head[1] ,curr);

                round++;
            }   
        }
    }


    return 1; 
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
                if(map[i][j].character == NULL)
                {
                    strcpy(map[i][j].firstLine, "      ");
                    map[i][j].firstLine[6] = '\0';

                    strcpy(map[i][j].secondLine, "        ");
                    map[i][j].secondLine[8] = '\0';

                    strcpy(map[i][j].thirdLine, "        ");
                    map[i][j].thirdLine[8] = '\0';
                }
                else
                {
                    map[i][j].character->horizontal = i;
                    map[i][j].character->vertical = j;
                    if(strncmp(map[i][j].character->name , "JW", 2) != 0)
                    {
                        char current[40] = "   ";
                        map[i][j].firstLine[6] = '\0';
                        strcat(current, map[i][j].character->nameForPrint);
                        strcat(current, "   ");

                        strcpy(map[i][j].firstLine, "      ");
                        strcpy(map[i][j].secondLine, current);
                        map[i][j].secondLine[33] = '\0';
                        strcpy(map[i][j].thirdLine, "        ");
                        map[i][j].thirdLine[8] = '\0';
                    }
                    else
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
                            strcpy(map[i][j].secondLine, "   ");
                            strcat(map[i][j].secondLine, JohnWatson.nameForPrint);
                            strcat(map[i][j].secondLine, "   ");
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
                }
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
                if(map[i][j].character == NULL)           
                {
                    strcpy(map[i][j].firstLine, " ____ ");
                    map[i][j].firstLine[6] = '\0';
                    strcpy(map[i][j].secondLine, " /    \\ ");
                    map[i][j].secondLine[8] = '\0';
                    strcpy(map[i][j].thirdLine, " \\____/ ");
                }
                else
                {
                    map[i][j].character->horizontal = i;
                    map[i][j].character->vertical = j;
                    if(strncmp(map[i][j].character->name , "JW", 2) != 0)
                    {
                        char current[40] = " / ";
                        map[i][j].firstLine[6] = '\0';
                        strcat(current, map[i][j].character->nameForPrint);
                        strcat(current, " \\ ");

                        strcpy(map[i][j].firstLine, " ____ ");
                        strcpy(map[i][j].secondLine, current);
                        map[i][j].secondLine[33] = '\0';
                        strcpy(map[i][j].thirdLine, " \\____/ ");
                        map[i][j].thirdLine[8] = '\0';
                    }
                    else
                    {
                        int direction = JohnWatson.name[3] - 48;

                        if(direction == north)
                        { 
                            char current[40] = " / ";
                            map[i][j].firstLine[6] = '\0';
                            strcat(current, map[i][j].character->nameForPrint);
                            strcat(current, " \\ ");
                            strcpy(map[i][j].firstLine, " _\033[0;33m__\033[0;38m_ ");
                            strcpy(map[i][j].secondLine, current);
                            strcpy(map[i][j].thirdLine, " \\____/ ");
                        }
                        else if(direction == south)
                        {
                            char current[40] = " / ";
                            map[i][j].firstLine[6] = '\0';
                            strcat(current, map[i][j].character->nameForPrint);
                            strcat(current, " \\ ");
                            strcpy(map[i][j].firstLine, " ____ ");
                            strcpy(map[i][j].secondLine, current);
                            strcpy(map[i][j].thirdLine, " \\_\033[0;33m__\033[0;38m_/ ");
                        }
                        else if(direction == northEast)
                        {
                            char current[40] = " / ";
                            map[i][j].firstLine[6] = '\0';
                            strcat(current, map[i][j].character->nameForPrint);
                            strcat(current, " \033[0;33m\\\033[0;38m ");
                            strcpy(map[i][j].firstLine, " ____ ");
                            strcpy(map[i][j].secondLine, current);
                            strcpy(map[i][j].thirdLine, " \\____/ ");
                        }
                        else if(direction == southEast)
                        {
                            char current[40] = " / ";
                            map[i][j].firstLine[6] = '\0';
                            strcat(current, map[i][j].character->nameForPrint);
                            strcat(current, " \\ ");
                            strcpy(map[i][j].firstLine, " ____ ");
                            strcpy(map[i][j].secondLine, current);
                            strcpy(map[i][j].thirdLine, " \\____\033[0;33m/\033[0;38m ");
                        }
                        else if(direction == northWest)
                        {
                            char current[40] = " \033[0;33m/\033[0;38m ";
                            map[i][j].firstLine[6] = '\0';
                            strcat(current, map[i][j].character->nameForPrint);
                            strcat(current, " \\ ");
                            strcpy(map[i][j].firstLine, " ____ ");
                            strcpy(map[i][j].secondLine, current);
                            strcpy(map[i][j].thirdLine, " \\____/ ");
                        }
                        else
                        {
                            char current[40] = " / ";
                            map[i][j].firstLine[6] = '\0';
                            strcat(current, map[i][j].character->nameForPrint);
                            strcat(current, " \\ ");
                            strcpy(map[i][j].firstLine, " ____ ");
                            strcpy(map[i][j].secondLine, current);
                            strcpy(map[i][j].thirdLine, " \033[0;33m\\\033[0;38m____/ ");
                        }
                    }
                }
            }
            else if(map[i][j].type == 3) // درپوش چاه
            {        


                if(map[i][j].character == NULL)           
                {
                    strcpy(map[i][j].firstLine, " ____ ");
                    map[i][j].firstLine[6] = '\0';
                    strcpy(map[i][j].secondLine, " /    \\ ");
                    map[i][j].secondLine[8] = '\0';
                    strcpy(map[i][j].thirdLine, " \\____/ ");
                }
                else
                {
                    map[i][j].character->horizontal = i;
                    map[i][j].character->vertical = j;  
                    if(strncmp(map[i][j].character->name , "JW", 2) != 0)
                    {

                        // strcpy(map[i][j].firstLine, " ____ ");
                        // map[i][j].firstLine[6] = '\0';
                        // strcpy(map[i][j].secondLine, " /    \\ ");
                        // map[i][j].secondLine[8] = '\0';
                        // strcpy(map[i][j].thirdLine, " \\____/ ");


                        char current[40] = " / ";
                        map[i][j].firstLine[6] = '\0';
                        strcat(current, map[i][j].character->nameForPrint);
                        strcat(current, " \\ ");

                        strcpy(map[i][j].firstLine, " ____ ");
                        strcpy(map[i][j].secondLine, current);
                        map[i][j].secondLine[33] = '\0';
                        strcpy(map[i][j].thirdLine, " \\____/ ");
                        map[i][j].thirdLine[8] = '\0';
                    }
                    else
                    {
                        int direction = JohnWatson.name[3] - 48;

                        if(direction == north)
                        { 
                            char current[40] = " / ";
                            map[i][j].firstLine[6] = '\0';
                            strcat(current, map[i][j].character->nameForPrint);
                            strcat(current, " \\ ");
                            strcpy(map[i][j].firstLine, " _\033[0;33m__\033[0;38m_ ");
                            strcpy(map[i][j].secondLine, current);
                            strcpy(map[i][j].thirdLine, " \\____/ ");
                        }
                        else if(direction == south)
                        {
                            char current[40] = " / ";
                            map[i][j].firstLine[6] = '\0';
                            strcat(current, map[i][j].character->nameForPrint);
                            strcat(current, " \\ ");
                            strcpy(map[i][j].firstLine, " ____ ");
                            strcpy(map[i][j].secondLine, current);
                            strcpy(map[i][j].thirdLine, " \\_\033[0;33m__\033[0;38m_/ ");
                        }
                        else if(direction == northEast)
                        {
                            char current[40] = " / ";
                            map[i][j].firstLine[6] = '\0';
                            strcat(current, map[i][j].character->nameForPrint);
                            strcat(current, " \033[0;33m\\\033[0;38m ");
                            strcpy(map[i][j].firstLine, " ____ ");
                            strcpy(map[i][j].secondLine, current);
                            strcpy(map[i][j].thirdLine, " \\____/ ");
                        }
                        else if(direction == southEast)
                        {
                            char current[40] = " / ";
                            map[i][j].firstLine[6] = '\0';
                            strcat(current, map[i][j].character->nameForPrint);
                            strcat(current, " \\ ");
                            strcpy(map[i][j].firstLine, " ____ ");
                            strcpy(map[i][j].secondLine, current);
                            strcpy(map[i][j].thirdLine, " \\____\033[0;33m/\033[0;38m ");
                        }
                        else if(direction == northWest)
                        {
                            char current[40] = " \033[0;33m/\033[0;38m ";
                            map[i][j].firstLine[6] = '\0';
                            strcat(current, map[i][j].character->nameForPrint);
                            strcat(current, " \\ ");
                            strcpy(map[i][j].firstLine, " ____ ");
                            strcpy(map[i][j].secondLine, current);
                            strcpy(map[i][j].thirdLine, " \\____/ ");
                        }
                        else
                        {
                            char current[40] = " / ";
                            map[i][j].firstLine[6] = '\0';
                            strcat(current, map[i][j].character->nameForPrint);
                            strcat(current, " \\ ");
                            strcpy(map[i][j].firstLine, " ____ ");
                            strcpy(map[i][j].secondLine, current);
                            strcpy(map[i][j].thirdLine, " \033[0;33m\\\033[0;38m____/ ");
                        }
                    }
                }
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
                if(map[i][j].character == NULL)
                { 
                    strcpy(map[i][j].firstLine, "      ");
                    map[i][j].firstLine[6] = '\0';
                    strcpy(map[i][j].secondLine, "  EXIT  ");
                    map[i][j].secondLine[8] = '\0';
                    strcpy(map[i][j].thirdLine, "        ");
                    map[i][j].thirdLine[8] = '\0';
                }
                else
                {
                    strcpy(map[i][j].firstLine, "      ");
                    map[i][j].firstLine[6] = '\0';
                    strcpy(map[i][j].secondLine, "  EXIT  ");
                    map[i][j].secondLine[8] = '\0';
                    strcpy(map[i][j].thirdLine, "   ");
                    strcat(map[i][j].thirdLine, map[i][j].character->nameForPrint);
                    strcat(map[i][j].thirdLine, "   ");
                    map[i][j].thirdLine[8] = '\0';
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
            map[i][j].character = NULL;
            map[i][j].horizontal = i;
            map[i][j].vertical = j;
        }
    }
    fgetc(NewGame);
    int i;
    int j;


    fscanf(NewGame, "%d %d\n", &i, &j);
    map[i][j].character = &JohnWatson;
    fscanf(NewGame, "%d %d\n", &i, &j);
    map[i][j].character = &SirWilliamGull;
    fscanf(NewGame, "%d %d\n", &i, &j);
    map[i][j].character = &InspectorLestrade;
    fscanf(NewGame, "%d %d\n", &i, &j);
    map[i][j].character = &JohnSmith;
    fscanf(NewGame, "%d %d\n", &i, &j);
    map[i][j].character = &SherlockHolmes;
    fscanf(NewGame, "%d %d\n", &i, &j);
    map[i][j].character = &JeremyBert;
    fscanf(NewGame, "%d %d\n", &i, &j);
    map[i][j].character = &MissStealthy;
    fscanf(NewGame, "%d %d\n", &i, &j);
    map[i][j].character = &SergentGoodley;
    
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
    while(1)
    {
        scanf("%d", &choice);
        getchar();
        if(choice > 0 && choice < 3)
            break;
        printf("\n\nPlease enter correctly...\n");
    }

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
    while(1)
    {
        scanf("%d", &choice);
        getchar();
        if(choice > 0 && choice < 3)
            break;
        printf("\n\nPlease enter correctly...\n");
    }


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
    while(1)
    {
        scanf("%d", &choice);
        getchar();
        if(choice > 0 && choice < 3)
            break;
        printf("\n\nPlease enter correctly...\n");
    }

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
    while(1)
    {
        scanf("%d", &choice);
        getchar();
        if(choice > 0 && choice < 3)
            break;
        printf("\n\nPlease enter correctly...\n");
    }

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
    while(1)
    {
        scanf("%d", &choice);
        getchar();
        if(choice > 0 && choice < 3)
            break;
        printf("\n\nPlease enter correctly...\n");
    }

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
    while(1)
    {
        scanf("%d", &choice);
        getchar();
        if(choice > 0 && choice < 3)
            break;
        printf("\n\nPlease enter correctly...\n");
    }

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
    while(1)
    {
        scanf("%d", &choice);
        getchar();
        if(choice > 0 && choice < 3)
            break;
        printf("\n\nPlease enter correctly...\n");
    }

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
    while(1)
    {
        scanf("%d", &choice);
        getchar();
        if(choice > 0 && choice < 4)
            break;
        printf("\n\nPlease enter correctly...\n");
    }

    if(choice == 1)
        DecelerationOfLamp();
    else if(choice == 2)
        return;
    else    
        Description();
}

Node* newNode(Character* character)
{
    Node* result = (Node*) malloc(sizeof(Node));
    result->character = character;
    result->next = NULL;
    return result;
}

void addNode(Node** head, Node* newNode)
{
    if(*head == NULL)
        *head = newNode;
    else
    {
        Node* current = *head;
        for(;current->next != NULL; current = current->next);
        current->next = newNode;
    }
}

Character* removeNode(Node** head, int length)
{
    Node* current = *head;
    if(length == 0)
    {
        *head = (*head)->next;
        
        current->next = NULL;
        return current->character;
    }
    else
    {
        for(int i = 0; i < length - 1; i++)
            current = current->next;
        
        Node* result = current->next;
        current->next = current->next->next;
        
        return result->character;
    }
}

void removeNodeByName(Node** head, char name[3])
{
    if(strncmp((*head)->character->name, name, 2) == 0)
    {
        *head = (*head)->next;
    }
    else
    {
        for(Node* current = *head; current->next != NULL; current = current->next)
            if(strncmp(current->next->character->name, name, 2) == 0)
            {
                current->next = current->next->next;
                return;
            }
    }
}

void print(Node* head)
{
    for(Node* current = head; current != NULL; current = current->next)
        printf("%s  " ,current->character->nameForPrint);
}

Node** random()
{
    int length = 8;
    int current;

    Node **head = (Node**) malloc(2 * sizeof(Node*));
    head[0] = NULL;
    head[1] = NULL;
    addNode(&head[0], newNode(&SergentGoodley));
    addNode(&head[0], newNode(&SherlockHolmes));
    addNode(&head[0], newNode(&JohnWatson));
    addNode(&head[0], newNode(&JeremyBert));
    addNode(&head[0], newNode(&MissStealthy));
    addNode(&head[0], newNode(&InspectorLestrade));
    addNode(&head[0], newNode(&SirWilliamGull));
    addNode(&head[0], newNode(&JohnSmith));

    int j = 0;
    while(j < 4)
    {
        addNode(&head[1] ,newNode(removeNode(&head[0], rand() % length)));
        length--;
        j++;
    }
    return head;
}

Node* TheSuspects()
{
    Node* result = NULL;
    addNode(&result, newNode(&SergentGoodley));
    addNode(&result, newNode(&SherlockHolmes));
    addNode(&result, newNode(&JohnWatson));
    addNode(&result, newNode(&JeremyBert));
    addNode(&result, newNode(&MissStealthy));
    addNode(&result, newNode(&InspectorLestrade));
    addNode(&result, newNode(&SirWilliamGull));
    addNode(&result, newNode(&JohnSmith));

    return result;
}

int checkIsCorrect(Node* head, char name[3])
{
    for(Node* current = head; current != NULL; current = current->next)
        if(strncmp(current->character->name, name, 2) == 0)
            return 1;
    return 0;
}

void setVisible(part** map ,int horizontal ,int vertical) // این تابع هر سری چک می کند کدام کاراکتر های مرئی و کدام نامرئی هستند
{
    SergentGoodley.visible = false;
    SherlockHolmes.visible = false;
    JohnWatson.visible = false;
    JeremyBert.visible = false;
    MissStealthy.visible = false;
    InspectorLestrade.visible = false;
    SirWilliamGull.visible = false;
    JohnSmith.visible = false;


    // این قسمت کاراکتر های دور لامپ و کاراکتر هایی که در مجاورت هم هستند،مرئی می شوند.
    for(int i = 0; i < horizontal; i++)
        for(int j = 0; j < vertical; j++)
        {
            if(j % 2) // برای خانه های با مقدار افقی فرد
            {
                if(map[i][j].type == lamp) // خانه های اطراف لامپ
                {
                    if(j - 1 >= 0)
                        if(map[i][j - 1].character != NULL)
                            map[i][j].character->visible = true;


                    if(i - 1 >= 0 && j - 1 >= 0)
                        if(map[i - 1][j - 1].character != NULL)
                            map[i - 1][j - 1].character->visible = true;


                    if(i - 1 >= 0)
                        if(map[i - 1][j].character != NULL)
                            map[i - 1][j].character->visible = true;

                    if(i + 1 < horizontal)
                        if(map[i + 1][j].character != NULL)
                            map[i + 1][j].character->visible = true;

                    if(j + 1 < vertical)
                        if(map[i][j + 1].character != NULL)
                            map[i][j + 1].character->visible = true;
    
                    if(i - 1 >= 0 && j + 1 < vertical)
                        if(map[i - 1][j + 1].character != NULL)
                            map[i - 1][j + 1].character->visible = true;
                }
                if(map[i][j].character != NULL) // کاراکتر های مجاور
                {
                    if(j - 1 >= 0)
                        if(map[i][j - 1].character != NULL)
                        {
                            map[i][j].character->visible = true;
                            map[i][j - 1].character->visible = true;
                        }

                    if(i - 1 >= 0 && j - 1 >= 0)
                        if(map[i - 1][j - 1].character != NULL)
                        {
                            map[i][j].character->visible = true;
                            map[i - 1][j - 1].character->visible = true;
                        }

                    if(i - 1 >= 0)
                        if(map[i - 1][j].character != NULL)
                        {
                            map[i][j].character->visible = true;
                            map[i - 1][j].character->visible = true;
                        }

                    if(i + 1 < horizontal)
                        if(map[i + 1][j].character != NULL)
                        {
                            map[i][j].character->visible = true;
                            map[i + 1][j].character->visible = true;
                        }

                    if(j + 1 < vertical)
                        if(map[i][j + 1].character != NULL)
                        {
                            map[i][j].character->visible = true;
                            map[i][j + 1].character->visible = true;
                        }

                    if(i - 1 >= 0 && j + 1 < vertical)
                        if(map[i - 1][j + 1].character != NULL)
                        {
                            map[i][j].character->visible = true;
                            map[i - 1][j + 1].character->visible = true;
                        }   
                }
            
            }
            else // برای خانه های با مولفه افقی زوج
            {
                if(map[i][j].type == lamp) // خانه های اطراف لامپ
                {
                    if(j - 1 >= 0)
                        if(map[i][j - 1].character != NULL)
                            map[i][j].character->visible = true;



                    if(i + 1 < horizontal && j - 1 >= 0)
                        if(map[i + 1][j - 1].character != NULL)
                            map[i + 1][j - 1].character->visible = true;


                    if(i - 1 >= 0)
                        if(map[i - 1][j].character != NULL)
                            map[i - 1][j].character->visible = true;

                    if(i + 1 < horizontal)
                        if(map[i + 1][j].character != NULL)
                            map[i + 1][j].character->visible = true;

                    if(j + 1 < vertical)
                        if(map[i][j + 1].character != NULL)
                            map[i][j + 1].character->visible = true;
    
                    if(i + 1 < horizontal && j + 1 < vertical)
                        if(map[i + 1][j + 1].character != NULL)
                            map[i + 1][j + 1].character->visible = true;
                }
                if(map[i][j].character != NULL) // کاراکتر های مجاور
                {
                    if(j - 1 >= 0)
                        if(map[i][j - 1].character != NULL)
                        {
                            map[i][j].character->visible = true;
                            map[i][j - 1].character->visible = true;
                        }

                    if(i + 1 < horizontal && j - 1 >= 0)
                        if(map[i + 1][j - 1].character != NULL)
                        {
                            map[i][j].character->visible = true;
                            map[i + 1][j - 1].character->visible = true;
                        }

                    if(i - 1 >= 0)
                        if(map[i - 1][j].character != NULL)
                        {
                            map[i][j].character->visible = true;
                            map[i - 1][j].character->visible = true;
                        }

                    if(i + 1 < horizontal)
                        if(map[i + 1][j].character != NULL)
                        {
                            map[i][j].character->visible = true;
                            map[i + 1][j].character->visible = true;
                        }

                    if(j + 1 < vertical)
                        if(map[i][j + 1].character != NULL)
                        {
                            map[i][j].character->visible = true;
                            map[i][j + 1].character->visible = true;
                        }

                    if(i + 1 < horizontal && j + 1 < vertical)
                        if(map[i + 1][j + 1].character != NULL)
                        {
                            map[i][j].character->visible = true;
                            map[i + 1][j + 1].character->visible = true;
                        }   
                }
            }
            
        }
    
    // این قسمت کاراکتر های در امتداد نور جان واتسون مرئی می شوند
    int i = JohnWatson.horizontal;
    int j = JohnWatson.vertical;  
    int direction = JohnWatson.name[3];  
    if(direction == north)
    {
        for(int k = i - 1; k >= 0; k--)
            if(map[k][j].character != NULL)
                map[k][j].character->visible = true;
    }
    else if(direction == south)
    {
        for(int k = i + 1; k < horizontal; k++)
            if(map[k][j].character != NULL)
                map[k][j].character->visible = true;
    }
    else if(direction == northEast)
    {
        if(j % 2 == 0)
            if(map[i][++j].character != NULL)
                map[i][j].character->visible = true;

        i++;
        for(int k = i; k < horizontal; k++)
        {
            if(map[i][++j].character != NULL)
                map[i][j].character->visible = true;
            if(j < 0 || map[i][j + 1].type == 1)
                break;
            
            if(map[i][++j].character != NULL)
                map[i][j].character->visible = true;
            if(j < 0 || map[i + 1][j + 1].type == 1)
                break;
        }
    }
    else if(direction == southEast)
    {
        if(j % 2 == 0)
            if(map[i][++j].character != NULL)
                map[i][j].character->visible = true;

        i--;

        for(int k = i; k >= 0; k--)
        {
            if(map[i][++j].character != NULL)
                map[i][j].character->visible = true;
            if(j < 0 || map[i][j + 1].type == 1)
                break;
            
            if(map[i][++j].character != NULL)
                map[i][j].character->visible = true;
            if(j < 0 || map[i - 1][j + 1].type == 1)
                break;
        }
    }
    else if(direction == northWest)
    {
        if(j % 2 == 0)
            if(map[i][--j].character != NULL)
                map[i][j].character->visible = true;

        i++;
        for(int k = i; k < horizontal; k++)
        {
            if(map[i][--j].character != NULL)
                map[i][j].character->visible = true;
            if(j < 0 || map[i][j - 1].type == 1)
                break;
            
            if(map[i][--j].character != NULL)
                map[i][j].character->visible = true;
            if(j < 0 || map[i + 1][j - 1].type == 1)
                break;
        }
    }
    else if(direction == southWest)
    {
        if(j % 2 == 0)
            if(map[i][--j].character != NULL)
                map[i][j].character->visible = true;

        i--;

        for(int k = i; k >= 0; k--)
        {
            if(map[i][--j].character != NULL)
                map[i][j].character->visible = true;
            if(j < 0 || map[i][j - 1].type == 1)
                break;
            
            if(map[i][--j].character != NULL)
                map[i][j].character->visible = true;
            if(j < 0 || map[i - 1][j - 1].type == 1)
                break;
        }
    }

}

int checkIsCorrectForOperation(part** map, int horizontal, int vertical, int type)
{
    if(map[horizontal][vertical].type == type)
        return 1;
    return 0;
}

void exchange(part** map, int firstHorizontal, int firstVertical, int secondHorizontal, int secondVertical, int firstType, int secondType)
{
    map[firstHorizontal][firstVertical].type = secondType;
    map[secondHorizontal][secondVertical].type = firstType;
}

void exchangeCharacter(part** map, int firstHorizontal, int firstVertical, int secondHorizontal, int secondVertical)
{
    Character* current = map[firstHorizontal][firstVertical].character;
    map[firstHorizontal][firstVertical].character = map[secondHorizontal][secondVertical].character;
    map[secondHorizontal][secondVertical].character = current;
}

int checkDestination(part** map, int horizontal, int vertical, bool visible)
{
    if(map[horizontal][vertical].type == block)
        return 0;
    if(map[horizontal][vertical].type == lamp)
        return 0;
    if(map[horizontal][vertical].type == lampLocation)
        return 0;
    if(map[horizontal][vertical].type == Roadblock)
        return 0;
    if(map[horizontal][vertical].character != NULL)
        return 0;
    if(map[horizontal][vertical].type == Exit && visible)
        return 0;

    return 1;    
}


int main()
{
    // srand(time(NULL));

    part** map = newGame();

    // board(map, 9, 13);

    // getchar();
    // exchangeCharacter(map, 4, 0, 0, 4);

    // board(map, 9, 13);

    // getchar();

    int **result = copyMap(map ,9 ,13);
    for(int i = 0; i < 11; i++)
    {
        for(int j = 0; j < 15; j++)
            printf("%d " ,result[i][j]);
        printf("\n");
    }
    // setVisible(map, 9, 13);

    // printf("\n%s %s" ,SergentGoodley.nameForPrint, SergentGoodley.visible ? "true" : "false");
    // printf("\n%s %s" ,SherlockHolmes.nameForPrint, SherlockHolmes.visible ? "true" : "false");
    // printf("\n%s %s" ,JohnWatson.nameForPrint, JohnWatson.visible ? "true" : "false");
    // printf("\n%s %s" ,JeremyBert.nameForPrint, JeremyBert.visible ? "true" : "false");
    // printf("\n%s %s" ,MissStealthy.nameForPrint, MissStealthy.visible ? "true" : "false");
    // printf("\n%s %s" ,InspectorLestrade.nameForPrint, InspectorLestrade.visible ? "true" : "false");
    // printf("\n%s %s" ,SirWilliamGull.nameForPrint, SirWilliamGull.visible ? "true" : "false");
    // printf("\n%s %s" ,JohnSmith.nameForPrint, JohnSmith.visible ? "true" : "false");


    // game(map ,9 ,13);


//     Character SergentGoodley = {"SG", "\033[1;34mS\033[1;31mG\033[0;38m", false, 4, beforeOrAfter};
// Character SherlockHolmes = {"SH", "\033[1;31mSH\033[0;38m", false, 3, afterMovement};
// Character JohnWatson = {"JW 3", "\033[1;33mJW\033[0;38m", false, 3, afterMovement};
// Character JeremyBert = {"JB", "\033[1;36mJB\033[0;38m", false, 3, beforeOrAfter};
// Character MissStealthy = {"MS", "\033[1;32mMS\033[0;38m", false, 3, simultaneous};
// Character InspectorLestrade = {"IN", "\033[1;34mIN\033[0;38m", false, 3, beforeOrAfter};
// Character SirWilliamGull = {"WG", "\033[1;35mWG\033[0;38m", false, 3, movementOrFunctionality};
// Character JohnSmith = {"JS", "\033[1;33mJS\033[0;38m", false, 3, beforeOrAfter};



    // s %s\n" ,(*head)->character->nameForPrint ,(*head)->next->character->nameForPrint ,(*head)->next->next->character->nameForPrint ,(*head)->next->next->next->character->nameForPrint);
    // int choice = menu();
    // switch (choice)
    // {
    //     case 1: // New Game
    //     {
    //         game();
    //         break;
    //     }
    //     case 2: // Load Game
    //     {

    //         break;
    //     }
    //     case 3: // Create Map
    //     {

    //         break;
    //     }
    //     case 4: // Help
    //     {
    //         Description();
    //         break;
    //     }
    //     case 5:
    //         return 0;
    // }
}

int** copyMap(part** map ,int horizontal ,int vertical)
{
    int** result = (int**)malloc((horizontal + 2) * (sizeof(int*)));
    for(int i = 0; i <= horizontal + 1; i++)
        result[i] = (int*)malloc((vertical + 2) * (sizeof(int)));
    
    for (int i = 0; i <= horizontal + 1; i++) 
    {
        result[i][0] = 1;
        result[i][vertical + 1] = 1;
    }
    for (int i = 0; i <= vertical + 1; i++) 
    {
        result[0][i] = 1;
        result[horizontal + 1][i] = 1;
    }
    for(int i = 1; i <= horizontal; i++)
        for(int j = 1; j <= vertical; j++)
        {
            int type = map[i - 1][j - 1].type;
            if(type == empty || type == well || type == wellBlocker)
                result[i][j] = 0;
            else 
                result[i][j] = 1;
        }

    return result;
}

int maze(part** map, int firstHorizontal, int firstVertical, int secondHorizontal, int secondVertical, int length)
{
    if(length > 0)
    {
        if(firstVertical == secondVertical)
            if(firstHorizontal -1 == secondHorizontal || firstHorizontal + 1 == secondHorizontal)
                return 1;

        if(firstHorizontal == secondHorizontal)
            if(firstVertical - 1 == secondVertical || firstVertical + 1 == secondVertical)
                return 1;

        if(firstVertical % 2)
        {
            if(firstHorizontal - 1 == secondHorizontal && firstVertical - 1 == secondHorizontal)
                return 1;
            if(firstHorizontal - 1 == secondHorizontal && firstVertical + 1 == secondVertical)
                return 1;
        }   

        else
        {
            if(firstHorizontal + 1 == secondHorizontal && firstVertical + 1 == secondVertical)
                return 1;
            if(firstHorizontal + 1 == secondHorizontal && firstVertical - 1 == secondVertical)
                return 1;
        }

        return 0;
    }
    if(length > 1)
    {
        if(firstVertical == secondVertical)
        {
            if(firstHorizontal - secondHorizontal == 2)
            {
                int type = map[firstHorizontal + 1][firstVertical].type;
                if(type != block && type != lamp && type != lampLocation)
                    return 1;
                else
                    return 0;
            }
            else if(secondHorizontal - firstHorizontal == 2)
            {
                int type = map[firstHorizontal - 1][firstVertical].type;
                if(type != block && type != lamp && type != lampLocation)
                    return 1;
                else
                    return 0;
            }
        }
        if(firstHorizontal == secondHorizontal)
        {
            if(firstVertical - secondVertical == 2)
            {
                int type = map[firstHorizontal][firstVertical + 1].type;
                if(type != block && type != lamp && type != lampLocation)
                    return 1;
                else
                    return 0;
            }
            else if(secondVertical - firstVertical == 2)
            {
                int type = map[firstHorizontal][firstVertical - 1].type;
                if(type != block && type != lamp && type != lampLocation)
                    return 1;
                else
                    return 0;
            }
        }

        if(firstVertical % 2)
        {
            
        }
        else
        {
            if(firstHorizontal - secondHorizontal == 1)
            {

            }
            else if(secondHorizontal - firstHorizontal == 1)
            {

            }
        }
    }

}

// زوج

//  i+1 j+1
//  i+1 j-1



// فرد
// i-1 j-1
// i-1 j+1



