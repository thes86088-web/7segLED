#include <stdio.h>

int i = 0; int j=0; int given = 88;
#define size 7
int mid = size/2;
int tens[size][size] = {0};
int ones[size][size] = {0};

void drawL0( int arr[] )
{
    for(j=0; j<size; j++)
        arr[0][j] = 1;
}
void drawL1( int arr[] )
{
    for(i=0; i<mid; i++)
        arr[i][size-1] = 1;
}
void drawL2( int arr[] )
{
     for(i=0; i<mid; i++)
        arr[mid+i][size-1] = 1;   
}
void drawL3( int arr[] )
{    
    for(j=0; j<size; j++)
        arr[size-1][j] = 1;
}
void drawL4( int arr[] )
{
    for(i=0; i<mid; i++)
        arr[mid+i][0] = 1;   }

void drawL5( int arr[] )
{
    for(j=0; j<size; j++)
        arr[mid][j] = 1;    
}
void drawL6( int arr[] )
{
    for(i=0; i<mid; i++)
        arr[i][0] = 1;    
}

void drawZero( int arr[] )
{
    drawL0( int arr[] ); drawL1( int arr[] ); drawL2( int arr[] ); drawL3( int arr[] ); drawL4( int arr[] );
    drawL6( int arr[] );
}
void drawOne( int arr[] )
{
    drawL1( int arr[] ); drawL2( int arr[] );
}
void drawTwo( int arr[] )
{
    drawL0( int arr[] ); drawL1( int arr[] );
    drawL3( int arr[] ); drawL4( int arr[] ); drawL5( int arr[] ); 
}
void drawThree( int arr[] )
{
    drawL0( int arr[] ); drawL1( int arr[] ); drawL2( int arr[] ); drawL3( int arr[] );
    drawL5( int arr[] );
}
void drawFour( int arr[] )
{
    drawL1( int arr[] ); drawL2( int arr[] );
    drawL5( int arr[] ); drawL6( int arr[] ); arr[size-1][size-1] = 1;
}
void drawFive( int arr[] )
{
    drawL0( int arr[] );
    drawL2( int arr[] ); drawL3( int arr[] ); 
    drawL5( int arr[] ); drawL6( int arr[] );
}
void drawSix( int arr[] )
{
    drawL0( int arr[] ); drawL2( int arr[] ); drawL3( int arr[] ); drawL4( int arr[] ); drawL5( int arr[] ); drawL6( int arr[] );
}
void drawSeven( int arr[] )
{
    drawL0( int arr[] ); drawL1( int arr[] ); drawL2( int arr[] ); arr[size-1][size-1] = 1;
}
void drawEight( int arr[] )
{
    drawL0( int arr[] ); drawL1( int arr[] ); drawL2( int arr[] ); drawL3( int arr[] );
    drawL4( int arr[] ); drawL5( int arr[] ); drawL6( int arr[] );
}
void drawNine( int arr[] )
{
    drawL0( int arr[] ); drawL1( int arr[] ); drawL2( int arr[] ); drawL3( int arr[] );
    drawL5( int arr[] ); drawL6( int arr[] );
}

void printMat( int arr[] )
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

void initMat( int arr[] )
{
    for( i=0; i<size; i++ )
    {
        for( j=0; j<size; j++ )
        {
            arr[i][j] = 0;
        }
    }
}


void paintMat( int arr[], int given )
{
    switch(given)
    {
        case 0 : drawZero( int arr[] ); break;
        case 1 : drawOne( int arr[] ); break;
        case 2 : drawTwo( int arr[] ); break;
        case 3 : drawThree( int arr[] ); break;
        case 4 : drawFour( int arr[] ); break;
        case 5 : drawFive( int arr[] ); break;
        case 6 : drawSix( int arr[] ); break;
        case 7 : drawSeven( int arr[] ); break;
        case 8 : drawEight( int arr[] ); break;
        case 9 : drawNine( int arr[] ); break;
        default : drawEight( int arr[] );
    }
}

int main()
{
    do{
        if( given>99 || given<0 )
        {
            printf("\n");
            printf("invalid input! please try again !"); printf("\n");
        }
        printf("Enter a number 0-99 : ");
        scanf( "%d", &given ); printf("\n");
    }
    while( given>99 || given<0 );

    firstDigit = given/10;
    secondDigit = given%10 ;
    
    initMat();
    paintMat();
    printMat(); 
    
}
