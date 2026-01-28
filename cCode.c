int i = 0; int j=0; 
#define size 7;
int arr[size][size] = {0};

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
    drawL5(); drawL6();
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
    drawL0(); drawL1(); drawL2();
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

int main()
{
    
}
