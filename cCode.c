#include <stdio.h>
#include <stlib.h>

int i = 0; int j=0; int given = 88;
#define Size 7
#define screens 2
int mid = Size/2;
int *tens = calloc(sizeof(int), Size) ;
int *ones = calloc(sizeof(int), Size) ;
int **canvas = calloc( sizeof(int*), screens );

void drawL0( int *arr )
{
    for(j=0; j<Size; j++)
        arr[j] = 1;
}
void drawL1( int *arr )
{
    for(i=0; i<mid; i++)
        arr[ (i*Size) + Size-1] = 1;
}
void drawL2( int *arr )
{
     for(i=0; i<mid; i++)
        arr[ (Size*( mid+i)) + Size-1] = 1;   
}
void drawL3( int *arr )
{    
    for(j=0; j<Size; j++)
        arr[ ((Size-1)*Size) + j] = 1;
}
void drawL4( int *arr )
{
    for(i=0; i<mid; i++)
        arr[ (mid+i)*Size ] = 1;   }

void drawL5( int *arr )
{
    for(j=0; j<Size; j++)
        arr[ (mid*Size) + j] = 1;    
}
void drawL6( int *arr )
{
    for(i=0; i<mid; i++)
        arr[i*Size] = 1;    
}

void drawZero( int *arr )
{
    drawL0(arr); drawL1( arr ); drawL2( arr ); drawL3( arr ); drawL4( arr );
    drawL6( arr );
}
void drawOne( int *arr )
{
    drawL1( arr ); drawL2( arr );
}
void drawTwo( int *arr )
{
    drawL0( arr ); drawL1( arr );
    drawL3( arr ); drawL4( arr ); drawL5( arr ); 
}
void drawThree( int *arr )
{
    drawL0( arr ); drawL1( arr ); drawL2( arr ); drawL3( arr );
    drawL5( arr );
}
void drawFour( int *arr )
{
    drawL1( arr ); drawL2( arr );
    drawL5( arr ); drawL6( arr ); arr[ (i*(Size-1)) + Size-1] = 1;
}
void drawFive( int *arr )
{
    drawL0( arr );
    drawL2( arr ); drawL3( arr ); 
    drawL5( arr ); drawL6( arr );
}
void drawSix( int *arr )
{
    drawL0( arr ); drawL2( arr ); drawL3( arr ); drawL4( arr ); drawL5( arr ); drawL6( arr );
}
void drawSeven( int *arr )
{
    drawL0( arr ); drawL1( arr ); drawL2( arr ); arr[ (i*(Size-1)) + Size-1] = 1;
}
void drawEight( int *arr )
{
    drawL0( arr ); drawL1( arr ); drawL2( arr ); drawL3( arr );
    drawL4( arr ); drawL5( arr ); drawL6( arr );
}
void drawNine( int *arr )
{
    drawL0( arr ); drawL1( arr ); drawL2( arr ); drawL3( arr );
    drawL5( arr ); drawL6( arr );
}

void printMat( int **canvas )
{
    for( i=0; i<Size; i++ )
    { 
        for( int k=0; k<screens; k++ )
        {    printf("\t");
            for( j=0; j<Size; j++ )
            {
                if( canvas[ ((k*screen) + i)*Size + j] == 1 ) printf("*");
                else if( canvas[ ((k*screen) + i)*Size + j] == 0 ) printf(" ");
            }
        }
        printf("\n");
    }
}

void paintMat( int *arr )
{
    switch(given)
    {
        case 0 : drawZero( arr ); break;
        case 1 : drawOne( arr ); break;
        case 2 : drawTwo( arr ); break;
        case 3 : drawThree( arr ); break;
        case 4 : drawFour( arr ); break;
        case 5 : drawFive( arr ); break;
        case 6 : drawSix( arr ); break;
        case 7 : drawSeven( arr ); break;
        case 8 : drawEight( arr ); break;
        case 9 : drawNine( arr ); break;
        default : drawEight( arr );
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
    
    paintMat(tens, firstDigit );    paintMat(ones, secondDigit );
 
    printMat(canvas); 
    
}
