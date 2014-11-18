#include <stdio.h> //Mengakses file library stdio.h untuk fungsi input/output
#include <stdlib.h> //Mengakses file library stdlib.h untuk fungsi system()
#include <string.h> //Mengakses file library string.h untuk fungsi gets(), strcmp
#include<windows.h> //Mengakses file library windows.h untuk fungsi system color

void password();
void cover();
void Board();
void PlayerX();
void PlayerO();
void Player_win();
void check();
int win=0,wrong_X=0,wrong_O=0,chk=0;
char name_X[30];
char name_O[30];
int pos_for_X[3][3];
int pos_for_O[3][3];
int pos_marked[3][3];

void main()
{
int i,ch,j;
char ans;

system("color f0");
password();
cover();

do
{
system("cls");
printf("____________________________________________________________________\n");
printf("\n\t\t\t\tTIC TAC TOE\n");
printf("____________________________________________________________________\n");

    for(i=1;i<=11;i++)
    {
    printf("*");
    }

printf("\n1.START GAME");
printf("\n2.EXIT");
printf("\n(1-2) : ");
scanf("%d",&ch);

switch(ch)
{
case 1: chk=0; win=0;

    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)

    {
        pos_for_X[i][j]=0;
        pos_for_O[i][j]=0;
        pos_marked[i][j]=0;
    }
}
printf("\n\n");
system("cls");

printf("\nPlayer 1 name\'X\': ");
fflush(stdin);
gets(name_X);

printf("\nPlayer 2 name\'O\': ");
fflush(stdin);
gets(name_O);

Board();

    for(;;)
    {
    if(win==1)
    break;

    check();

        if(chk==9)
    {
    printf("\n\t\t\tMATCH DRAWS!!");
    printf("\nPress any key..");
    break;
    }

        else
        chk=0;

printf("\nTURN FOR %s:",name_X);
PlayerX();

do
{
    if(wrong_X!=1)
    break;

wrong_X=0;
printf("\nTURN FOR %s:",name_X);
PlayerX();
} while(wrong_X==1);

check();
    if(chk==9)
    {
    printf("\n\t\t\tMATCH DRAWS");
    printf("\nPress any key..");
    break;
    }

    else
    chk=0;

printf("\nTURN FOR %s:",name_O);
PlayerO();

do
{
    if(wrong_O!=1)
    break;

wrong_O=0;
printf("\nTURN FOR %s:",name_O);
PlayerO();
} while(wrong_O==1);

}

Board();
    if(win!=1)
    {
    printf("\n\t\t\tMATCH DRAWS!!");
    printf("\nPress any key..");
    }

getch();
break;

case 2:
printf("\n\n\n\t\t\t-THANK YOU FOR PLAYING-");
printf("\n\t\t\t______________________________");
getch();
break;

}

printf("\nONCE AGAIN? (Y/N) ");
fflush(stdin);
scanf("%c",&ans);
}   while(ans=='y' || ans=='Y');

}

void password()
{
char word1[20], word2[20], pass1[20], pass2[20];
int cek1, cek2, a=0;

ulang:

strcpy(word1,"mytictactoe");
printf("The number %d password try\n", a+1);
printf("Enter Password\t\t: ",word1);
gets(pass1);
strcpy(word2,"mytictactoe");
printf("Corfirm Password\t: ");
gets(pass2);

cek1=strcmp(word1,pass1);
cek2=strcmp(word2,pass2);

    if (cek1 == 0 && cek2 == 0)
    {
    printf("\n Correct Password!\n");
    }

    else
    {
    a=a+1;
        if(a<3)
        {
        printf("\nIncorrect Password\n");
        goto ulang;
        }

        else
        {
        printf("\nAcces Denied!\n");
        exit(EXIT_SUCCESS);
        }
    }
}

void cover()                              // prosedur opening
{

    int i, j = 1;
    system("color f0");
    char o[]   = "\n\n\n\n\n\t\t\tL o a d i n g";
    char dt[]  = " . . . . .";
    char clear[]= "          ";
    char cap[]  = "\' T I C T A C T O E \'";

    for (i=0; o[i] != 0; i++)
    {
        printf("%c", o[i]);
    }

    while (j <= 3)
    {
        for (i=0; dt[i] != 0; i++)
        {
            Sleep(130);
            printf("%c", dt[i]);
        }
        Sleep(220);
        for (i=10; i>0; i--)
        {
            printf("\b");
            printf("%c", clear[i]);
            printf("\b");
        }
        j++;
    }

    for (i=13; i>0; i--)
    {
        Sleep(20);
        printf("\b");
    }

    for (i=0; cap[i] != 0; i++)
    {
        Sleep(50);
        printf("%c", cap[i]);
    }
    printf("\n");
    printf("\n\t\t\tby\n\t\t\tMIFTA APRILYA SURYANI\n\n");
    Sleep(3000);
}


void Board()
{
int i,j;
system("cls");
puts("----------------------------------------------------------------");
printf("\t\t\t\tTIC TAC TOE BOARD");
puts("\n----------------------------------------------------------------");
printf("\n\n\n");
printf("\n\t\t\t    1\t      2\t        3");

    for(i=1;i<=3;i++)
    {
    printf("\n \t\t\t _____________________________");
    printf("\n \t\t\tº\t  º\t   º\t     º");
    printf("\n\t\t%d\t",i);

        for(j=1;j<=3;j++)
        {
            if(pos_for_X[i][j]==1)
            {
            printf("    X");
            printf("     ");
            }

            else if(pos_for_O[i][j]==1)
            {
            printf("    O");
            printf("     ");
            }

            else
            {
            printf("          ");
            continue;
            }

        }

printf("\n\t\t\tº\t  º\t   º\t     º");
}

printf("\n\t\t\t _____________________________");
Player_win();
}

void PlayerX()
{
int row,col;

    if(win==1)
    return;

printf("\nNumber of row\t: ");
fflush(stdin);
scanf("%d",&row);

printf("Number of column\t: ");
fflush(stdin);
scanf("%d",&col);

    if(pos_marked[row][col]==1 || row<1 || row>3 || col<1 || col>3)
    {
    printf("\nWRONG POSITION!! Press any key..");
    wrong_X=1;
    getch();
    Board();
    }

    else
    {
    pos_for_X[row][col]=1;
    pos_marked[row][col]=1;
    Board();
    }

}

void PlayerO()
{
int row,col;

    if(win==1)
    return;

printf("\nNumber of row\t: ");
scanf("%d",&row);
printf("Number of column\t: ");
scanf("%d",&col);
    if(pos_marked[row][col]==1 || row<1 || row>3 || col<1 || col>3)
    {
    printf("\nWRONG POSITION!! Press any key.");
    wrong_O=1;
    getch();
    Board();
    }

    else
    {
    pos_for_O[row][col]=1;
    pos_marked[row][col]=1;
    Board();
    }
}

void Player_win()
{
int i;
    for(i=1;i<=3;i++)
    {
        if(pos_for_X[i][1]==1 && pos_for_X[i][2]==1 && pos_for_X[i][3]==1)
        {
        win=1;
        printf("\n\nRESULT: %s wins!!",name_X);
        printf("\nPress any key..");
        return;
        }
    }

    for(i=1;i<=3;i++)
    {
        if(pos_for_X[1][i]==1 && pos_for_X[2][i]==1 && pos_for_X[3][i]==1)
        {
        win=1;
        printf("\n\nRESULT: %s wins!!",name_X);
        printf("\nPress any key..");
        return;
        }
    }

        if(pos_for_X[1][1]==1 && pos_for_X[2][2]==1 && pos_for_X[3][3]==1)
        {
        win=1;
        printf("\n\nRESULTL: %s wins!!",name_X);
        printf("\nPress any key..");
        return;
        }

        else if(pos_for_X[1][3]==1 && pos_for_X[2][2]==1 && pos_for_X[3][1]==1)
        {
        win=1;
        printf("\n\nRESULT: %s wins!!",name_X);
        printf("\nPress any key..");
        return;
        }

    for(i=1;i<=3;i++)
    {
        if(pos_for_O[i][1]==1 && pos_for_O[i][2]==1 && pos_for_O[i][3]==1)
        {
        win=1;
        printf("\n\nRESULT: %s wins!!",name_O);
        printf("\nPress any key..");
        return;
        }
    }

    for(i=1;i<=3;i++)
    {
        if(pos_for_O[1][i]==1 && pos_for_O[2][i]==1 && pos_for_O[3][i]==1)
        {
        win=1;
        printf("\n\nRESULT: %s wins!!",name_O);
        printf("\nPress any key");
        return;
        }
    }

        if(pos_for_O[1][1]==1 && pos_for_O[2][2]==1 && pos_for_O[3][3]==1)
        {
        win=1;
        printf("\n\nRESULT: %s wins!!",name_O);
        printf("\nPress any key..");
        return;
        }

        else if(pos_for_O[1][3]==1 && pos_for_O[2][2]==1 && pos_for_O[3][1]==1)
        {
        win=1;
        printf("\n\nRESULT: %s wins!!",name_O);
        printf("\nPress any key..");
        return;
        }
    }

void check()
{
int i,j;

    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
        if(pos_marked[i][j]==1)
        chk++;

        else
        continue;
        }
    }
}

