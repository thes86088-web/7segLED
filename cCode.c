
#include <stdio.h>

void triggerZero(int i, int j, int arr[][7] )
{
    if(i==0)
        arr[i][j] = 1 ; 
}

void triggerOne(int i, int j, int arr[][7] )
{
    if( i==6 && j<=3 )
        arr[i][j] = 1 ;
}

void triggerTwo(int i, int j, int arr[][7] )
{
    if( i==6 && j>=3 )
        arr[i][j] = 1 ;
}

void triggerThree(int i, int j, int arr[][7] )
{
    if(i==6)
        arr[i][j] = 1 ;
}

void triggerFour(int i, int j, int arr[][7] )
{
    if( i==0 && j>=3 )
        arr[i][j] = 1 ;
}

void triggerFive(int i, int j, int arr[][7] )
{
    if(i==3)
        arr[i][j] = 1 ;
}

void triggerSix(int i, int j, int arr[][7] )
{
    if( i==0 && j<=3 )
        arr[i][j] = 1 ;
}

void fillMat( int arr[][7] )
{
    int given = 0;
    do{
        if( given>9 || given<0 )
        {
            printf("\n");
            printf("please try again !"); printf("\n");
        }
        printf("Enter a number 0-9 : ");
        scanf( "%d", &given ); printf("\n");
    }
    while( given>9 || given<0 );
    
    for( int i=0; i<7; i++ )
    {
        for( int j=0; j<7; j++ )
        {
            if( given!=1 && given!=4 )
            {
                triggerZero(i, j, arr); }
            
            if( given!=5 && given!=6 )
            {
                triggerOne(i, j, arr); }
            
            if( given!=2 )
            {
                triggerTwo(i, j, arr); }
            
            if( given!=1 && given!=4 && given!=7 )
            {
                triggerThree(i, j, arr); }
            
            if( given!=1 && given!=3 && given!=4 && given!=5 && given!=7  )
            {
                triggerFour(i, j, arr); }
            
            if( given!=0 && given!=1 && given!=7  )
            {
                triggerFive(i, j, arr); }

            if( given!=1 && given!=2 && given!=3 && given!=7 )
            {
                triggerSix(i, j, arr); }
                    
        }
        
    }

}

void printMat( int arr[][7] )
{
    for( int i=0; i<7; i++ )
    {
        for( int j=0; j<7; j++ )
        {
            printf( "%c", arr[i][j]==1?'*':' ' );
        }
        printf("\n");
    }
}

int main()
{
    int arr[7][7] = {0};
    fillMat(arr);
    printMat(arr);
    
}
