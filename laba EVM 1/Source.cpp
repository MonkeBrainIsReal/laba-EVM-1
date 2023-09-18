#include <ostream>
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
HANDLE Output = GetStdHandle(STD_OUTPUT_HANDLE);


void DoubleToBits(double x)
{
    union 
    {
        double x;
        char buffer[sizeof(double)];
    } u;
    u.x = x;
    for (unsigned ofs = 0; ofs < sizeof(double); ofs++) {
        for (int i = 7; i >= 0; i--) {
            printf(((1 << i) & u.buffer[ofs]) ? "1" : "0");
        }
        printf(" ");
    }
}


void IntToBits(short int n)
{
    long i;
    for (i = 1 << 30; i > 0; i = i / 2)
    {
        if ((n & i) != 0)
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
}


int main()
{
    short int SIInput;
    double DInput;

    while (TRUE) 
    {
        SetConsoleTextAttribute(Output,14);
        printf("Select a mode:\n");
        printf("1 - for ");
        SetConsoleTextAttribute(Output, 12);
        printf("Short int");
        SetConsoleTextAttribute(Output, 14);
        printf(" representation\n");
        printf("2 - for ");
        SetConsoleTextAttribute(Output, 12);
        printf("Double");
        SetConsoleTextAttribute(Output, 14);
        printf(" representation\n");
        printf("ESC - to ");
        SetConsoleTextAttribute(Output, 12);
        printf("exit ");
        SetConsoleTextAttribute(Output, 14);
        printf("an application");
        int  selectmode = _getch();

        if (selectmode == 49) 
        {
            system("cls");
            printf("print in a integer decimal number\n");
            cin >> SIInput;
            printf("Binary mode representation: ");
            IntToBits(SIInput);
            printf("\n");
            printf("Press any button to continue");
            _getch();
            system("cls");
        }

        if (selectmode == 50) 
        {
            system("cls");
            printf("print in a real decimal number\n");
            cin >> DInput;
            printf("Binary mode representation: ");
            DoubleToBits(DInput);
            printf("\n");
            printf("Press any button to continue");
            _getch();
            system("cls");
        }

        if (selectmode == 27) 
        {
            system("cls");
            break;
        }
    }

}