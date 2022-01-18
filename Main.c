#include "Header.h"


enum typeOfComponents{empty, block, well, wellBlocker, lamp, lampLocation, Roadblock, Exit, WG, JW, IL, SH, JS, JB, MS, SG};

typedef struct PartMaP
{
    int type;
    int vertical;
    int horizontal;
}part;

void board(int horizontal, int vertical);
int menu();
part** newGame();

char blc = 254;
int main()
{

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

    printf("  ______\n");
    printf(" /  __  \\\n");
    printf("/  /XX\\  \\\n");
    printf("\\  \\XX/  /\n");
    printf(" \\______/\n");
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
            else
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
            if(i > 0)
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