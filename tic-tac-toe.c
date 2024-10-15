#include <stdio.h>
#include <stdlib.h>
int i,j,k;
int ValCoordinate(char arr[3][3],int cx,int cy)
{

    if(cx>2||cy>2||arr[cx][cy]=='X'||arr[cx][cy]=='O') 
    return 0;
    else 
    return 1;
}
void Display(char arr[3][3])
{
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(arr[i][j]!='1'&&j==2)
            printf("%c ",arr[i][j]);
            else if(arr[i][j]!='1'&&(j==0||j==1))
            printf("%c|",arr[i][j]);
            else if(arr[i][j]=='1'&&j==2)
            printf(" ");
            else if(arr[i][j]=='1'&&(j==0||j==1))
            printf(" |",arr[i][j]);
        }
        printf("\n");
        
            if(i==0||i==1)
            printf("_");
            printf("\n");
    }
}
int LeftDiagonal(char arr[3][3],char p)
{
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(i==j&&arr[i][j]!=p)
            return 0;
        }
    }
    return 1;
}
int RightDiagonal(char arr[3][3],char p)
{
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(i+j==2&&arr[i][j]!=p)
            return 0;
        }
    }
    return 1;
}
int Row(char arr[3][3],char p)
{
    int c=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
           if(arr[i][j]==p)
           ++c;
        }
     if(c==3)
     return 1;
     c=0;
    }
    return 0;
}
int Column(char arr[3][3],char p)
{
    int c=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
           if(arr[j][i]==p)
           ++c;
        }
     if(c==3)
     return 1;
     c=0;
    }
    return 0;
}
int GameContinue(char arr[3][3])
{
    int c=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(arr[i][j]=='O'||arr[i][j]=='X')
            ++c;
        }
    }
    if(c==9)
    return 1;
    else
    return 0;
}

void main()
{
    printf("Welcome to the TicTacToe Gaming Console\n");
    printf("RULES AND REGULATIONS!!!!\n");
    printf("1.Player 1 begins the game with X and player 2 begins the game with O\n");
    printf("2.If an player inserts X/O in an already pre-occupied square that move is invalid\n");
    printf("3.If such happens the player is giving another chance and if he/she does it again it would be declared a loss for that player\n");
    printf("4.Please beware of the coordinate system...Starting coordinate (0,0) Ending coordinate(2,2)\n");
    printf("5.For an Invalid coordinate,player is given another chance if he fails this time the game is declared loss for that player\n");
    printf("6.Rest all the rules for winning the game remains the same\n");
    printf("ALL THE BEST!!!!!\n");
    char arr[3][3];
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        arr[i][j]='1';
    }
    //Display(arr);
    int c=0,gamestop=1,start=0;
    int cx,cy;
    char p;
    while(gamestop)
    {
        printf("Enter the coordinates\n");
        scanf("%d%d",&cx,&cy);
        if(ValCoordinate(arr,cx,cy)==0)
        {
            if(c==0)
            printf("Invalid Coordinates..Please enter correctly and this is your last chance\n");
            c++;
        }
            else
            {
            if(start%2==0)
            arr[cx][cy]='X';
            else
            arr[cx][cy]='O';
            p=start%2==0?'X':'O';
            ++start;
            Display(arr);
            c=0;
            }
            if(LeftDiagonal(arr,p)||RightDiagonal(arr,p)||Row(arr,p)||Column(arr,p))
            {
                if(p=='X')
                printf("Congratulations to Player 1 for winning Tic-Tac-Toe World Championship....\n!!!!");
                else
                printf("Congratulations to Player 2 for winning Tic-Tac-Toe World Championship....\n!!!!");
                break;
            }
        if(c==2)
        {
        if(start%2==0)
        printf("Player 1 lost the game for trying to play an invalid move two times....\n");
        else
        printf("Player 2 lost the game for trying to play an invalid move two times....\n");   
        break;
        }
        if(GameContinue(arr))
        {
            printf("Game has ended in a Draw...\n");
            gamestop=0;
        }
    }
}