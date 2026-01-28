#include <stdio.h>

int i = 0; int j=0; int given = 8;
#define size 7
int mid = size/2;
int arr[size][size] = {0};

void drawL0()
{
    for(j=0; j<size; j++)
        arr[0][j] = 1;
}
void drawL1()
{
    for(i=0; i<mid; i++)
        arr[i][size-1] = 1;
}
void drawL2()
{
     for(i=0; i<mid; i++)
        arr[mid+i][size-1] = 1;   
}
void drawL3()
{    
    for(j=0; j<size; j++)
        arr[size-1][j] = 1;
}
void drawL4()
{
    for(i=0; i<mid; i++)
        arr[mid+i][0] = 1;   }
void drawL5()
{
    for(j=0; j<size; j++)
        arr[mid][j] = 1;    
}
void drawL6()
{
    for(i=0; i<mid; i++)
        arr[i][0] = 1;    
}

void drawZero( )
{
    drawL0(); drawL1(); drawL2(); drawL3(); drawL4();
    drawL6();
}
void drawOne( )
{
    drawL1(); drawL2();
}
void drawTwo( )
{
    drawL0(); drawL1();
    drawL3(); drawL4(); drawL5(); 
}
void drawThree( )
{
    drawL0(); drawL1(); drawL2(); drawL3();
    drawL5();
}
void drawFour( )
{
    drawL1(); drawL2();
    drawL5(); drawL6(); arr[size-1][size-1] = 1;
}
void drawFive()
{
    drawL0();
    drawL2(); drawL3(); 
    drawL5(); drawL6();
}
void drawSix( )
{
    drawL0(); drawL2(); drawL3(); drawL4(); drawL5(); drawL6();
}
void drawSeven( )
{
    drawL0(); drawL1(); drawL2(); arr[size-1][size-1] = 1;
}
void drawEight( )
{
    drawL0(); drawL1(); drawL2(); drawL3(); drawL4(); drawL5(); drawL6();
}
void drawNine( )
{
    drawL0(); drawL1(); drawL2(); drawL3();
    drawL5(); drawL6();
}

void printMat()
{
    for( i=0; i<size; i++ )
    {
        for( j=0; j<size; j++ )
        {
            if( arr[i][j] == 1 ) printf("*");
            else if( arr[i][j] == 0 ) printf(" ");
        }
        printf("\n");
    }
}

void initMat()
{
    for( i=0; i<size; i++ )
    {
        for( j=0; j<size; j++ )
        {
            arr[i][j] = 0;
        }
    }
}


void paintMat()
{
    switch(given)
    {
        case 0 : drawZero(); break;
        case 1 : drawOne(); break;
        case 2 : drawTwo(); break;
        case 3 : drawThree(); break;
        case 4 : drawFour(); break;
        case 5 : drawFive(); break;
        case 6 : drawSix(); break;
        case 7 : drawSeven(); break;
        case 8 : drawEight(); break;
        case 9 : drawNine(); break;
        default : drawEight();
    }
}

int main()
{
    do{
        if( given>9 || given<0 )
        {
            printf("\n");
            printf("invalid input! please try again !"); printf("\n");
        }
        printf("Enter a number 0-9 : ");
        scanf( "%d", &given ); printf("\n");
    }
    while( given>9 || given<0 );
    
    initMat();
    paintMat();
    printMat(); 
    
}
