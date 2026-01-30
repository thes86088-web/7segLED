#include <stdio.h>

int i = 0; int j=0; int given = 88;
#define size 7
#define screens 2
int mid = size/2;
int tens[size][size] = {0};
int ones[size][size] = {0};

void drawL0( int arr[][size] )
{
    for(j=0; j<size; j++)
        arr[0][j] = 1;
}
void drawL1( int arr[][size] )
{
    for(i=0; i<mid; i++)
        arr[i][size-1] = 1;
}
void drawL2( int arr[][size] )
{
     for(i=0; i<mid; i++)
        arr[mid+i][size-1] = 1;   
}
void drawL3( int arr[][size] )
{    
    for(j=0; j<size; j++)
        arr[size-1][j] = 1;
}
void drawL4( int arr[][size] )
{
    for(i=0; i<mid; i++)
        arr[mid+i][0] = 1;   }

void drawL5( int arr[][size] )
{
    for(j=0; j<size; j++)
        arr[mid][j] = 1;    
}
void drawL6( int arr[][size] )
{
    for(i=0; i<mid; i++)
        arr[i][0] = 1;    
}

void drawZero( int arr[][size] )
{
    drawL0(arr); drawL1( arr ); drawL2( arr ); drawL3( arr ); drawL4( arr );
    drawL6( arr );
}
void drawOne( int arr[][size] )
{
    drawL1( arr ); drawL2( arr );
}
void drawTwo( int arr[][size] )
{
    drawL0( arr ); drawL1( arr );
    drawL3( arr ); drawL4( arr ); drawL5( arr ); 
}
void drawThree( int arr[][size] )
{
    drawL0( arr ); drawL1( arr ); drawL2( arr ); drawL3( arr );
    drawL5( arr );
}
void drawFour( int arr[][size] )
{
    drawL1( arr ); drawL2( arr );
    drawL5( arr ); drawL6( arr ); arr[size-1][size-1] = 1;
}
void drawFive( int arr[][size] )
{
    drawL0( arr );
    drawL2( arr ); drawL3( arr ); 
    drawL5( arr ); drawL6( arr );
}
void drawSix( int arr[][size] )
{
    drawL0( arr ); drawL2( arr ); drawL3( arr ); drawL4( arr ); drawL5( arr ); drawL6( arr );
}
void drawSeven( int arr[][size] )
{
    drawL0( arr ); drawL1( arr ); drawL2( arr ); arr[size-1][size-1] = 1;
}
void drawEight( int arr[][size] )
{
    drawL0( arr ); drawL1( arr ); drawL2( arr ); drawL3( arr );
    drawL4( arr ); drawL5( arr ); drawL6( arr );
}
void drawNine( int arr[][size] )
{
    drawL0( arr ); drawL1( arr ); drawL2( arr ); drawL3( arr );
    drawL5( arr ); drawL6( arr );
}

void printMat( int canvas[][size][size] )
{
    for( i=0; i<size; i++ )
    { 
        for( int k=0; k<screens; k++ )
        {    printf("\t");
            for( j=0; j<size; j++ )
            {
                if( arr[k][i][j] == 1 ) printf("*");
                else if( arr[k][i][j] == 0 ) printf(" ");
            }
        }
        printf("\n");
    }
}

void initMat( int arr[][size] )
{
    for( i=0; i<size; i++ )
    {
        for( j=0; j<size; j++ )
        {
            arr[i][j] = 0;
        }
    }
}


void paintMat( int arr[][size] )
{
    switch(given)
    {
        case 0 : drawZero( int arr[][size] ); break;
        case 1 : drawOne( int arr[][size] ); break;
        case 2 : drawTwo( int arr[][size] ); break;
        case 3 : drawThree( int arr[][size] ); break;
        case 4 : drawFour( int arr[][size] ); break;
        case 5 : drawFive( int arr[][size] ); break;
        case 6 : drawSix( int arr[][size] ); break;
        case 7 : drawSeven( int arr[][size] ); break;
        case 8 : drawEight( int arr[][size] ); break;
        case 9 : drawNine( int arr[][size] ); break;
        default : drawEight( int arr[][size] );
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
    
    initMat();
    paintMat();
    
    printMat(); 
    
}
