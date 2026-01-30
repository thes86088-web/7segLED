#include <stdio.h>
#include <stlib.h>

int i = 0; int j=0; int given = 88;
#define Size 7
#define screens 2
int mid = Size/2;
int *tens = calloc(sizeof(int), Size) ;
int *ones = calloc(sizeof(int), Size) ;
int **canvas = calloc( sizeof(int*), screens );

int canvas[screens][Size][Size] = { tens, ones };

void drawL0( int arr[][Size] )
{
    for(j=0; j<Size; j++)
        arr[0][j] = 1;
}
void drawL1( int arr[][Size] )
{
    for(i=0; i<mid; i++)
        arr[i][Size-1] = 1;
}
void drawL2( int arr[][Size] )
{
     for(i=0; i<mid; i++)
        arr[mid+i][Size-1] = 1;   
}
void drawL3( int arr[][Size] )
{    
    for(j=0; j<Size; j++)
        arr[Size-1][j] = 1;
}
void drawL4( int arr[][Size] )
{
    for(i=0; i<mid; i++)
        arr[mid+i][0] = 1;   }

void drawL5( int arr[][Size] )
{
    for(j=0; j<Size; j++)
        arr[mid][j] = 1;    
}
void drawL6( int arr[][Size] )
{
    for(i=0; i<mid; i++)
        arr[i][0] = 1;    
}

void drawZero( int arr[][Size] )
{
    drawL0(arr); drawL1( arr ); drawL2( arr ); drawL3( arr ); drawL4( arr );
    drawL6( arr );
}
void drawOne( int arr[][Size] )
{
    drawL1( arr ); drawL2( arr );
}
void drawTwo( int arr[][Size] )
{
    drawL0( arr ); drawL1( arr );
    drawL3( arr ); drawL4( arr ); drawL5( arr ); 
}
void drawThree( int arr[][Size] )
{
    drawL0( arr ); drawL1( arr ); drawL2( arr ); drawL3( arr );
    drawL5( arr );
}
void drawFour( int arr[][Size] )
{
    drawL1( arr ); drawL2( arr );
    drawL5( arr ); drawL6( arr ); arr[Size-1][Size-1] = 1;
}
void drawFive( int arr[][Size] )
{
    drawL0( arr );
    drawL2( arr ); drawL3( arr ); 
    drawL5( arr ); drawL6( arr );
}
void drawSix( int arr[][Size] )
{
    drawL0( arr ); drawL2( arr ); drawL3( arr ); drawL4( arr ); drawL5( arr ); drawL6( arr );
}
void drawSeven( int arr[][Size] )
{
    drawL0( arr ); drawL1( arr ); drawL2( arr ); arr[Size-1][Size-1] = 1;
}
void drawEight( int arr[][Size] )
{
    drawL0( arr ); drawL1( arr ); drawL2( arr ); drawL3( arr );
    drawL4( arr ); drawL5( arr ); drawL6( arr );
}
void drawNine( int arr[][Size] )
{
    drawL0( arr ); drawL1( arr ); drawL2( arr ); drawL3( arr );
    drawL5( arr ); drawL6( arr );
}

void printMat( int canvas[][Size][Size] )
{
    for( i=0; i<Size; i++ )
    { 
        for( int k=0; k<screens; k++ )
        {    printf("\t");
            for( j=0; j<Size; j++ )
            {
                if( arr[k][i][j] == 1 ) printf("*");
                else if( arr[k][i][j] == 0 ) printf(" ");
            }
        }
        printf("\n");
    }
}

void initMat( int arr[][Size] )
{
    for( i=0; i<Size; i++ )
    {
        for( j=0; j<Size; j++ )
        {
            arr[i][j] = 0;
        }
    }
}


void paintMat( int arr[][Size] )
{
    switch(given)
    {
        case 0 : drawZero( int arr[][Size] ); break;
        case 1 : drawOne( int arr[][Size] ); break;
        case 2 : drawTwo( int arr[][Size] ); break;
        case 3 : drawThree( int arr[][Size] ); break;
        case 4 : drawFour( int arr[][Size] ); break;
        case 5 : drawFive( int arr[][Size] ); break;
        case 6 : drawSix( int arr[][Size] ); break;
        case 7 : drawSeven( int arr[][Size] ); break;
        case 8 : drawEight( int arr[][Size] ); break;
        case 9 : drawNine( int arr[][Size] ); break;
        default : drawEight( int arr[][Size] );
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
    
    initMat(tens);     initMat(ones);
    paintMat(tens);    paintMat(ones);
 
    printMat(canvas); 
    
}
