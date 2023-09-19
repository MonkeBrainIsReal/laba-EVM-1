#include <ostream>
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
HANDLE Output = GetStdHandle(STD_OUTPUT_HANDLE);


void DoubleToBits(double x, char* binaryArray) 
{
    union 
    {
        double value;
        uint64_t bits;//любой тип данных который занимает 64 бита (если uint64_t смущает)
    } u;

    u.value = x;
    unsigned long long check = 1;//mask

    if (u.bits & (check << 63)) 
    {
        binaryArray[0] = '1';
    }
    else 
    {
        binaryArray[0] = '0';
    }
    binaryArray[1] = ' ';//for ebeyshiy output

    for (int i = 0; i < 11; i++) {
        if (u.bits & (check << (53 + i))) 
        {
            binaryArray[2+i] = '1';
        }
        else 
        {
            binaryArray[2+i] = '0';
        }
    }
    binaryArray[13] = ' ';//for ebeyshiy output

    for (int i = 0; i < 52; i++) 
    {
        if (u.bits & (check << (51 - i))) 
        {
            binaryArray[14 + i] = '1';
        }
        else 
        {
            binaryArray[14 + i] = '0';
        }


    }
}
   



void IntToBits(short int n, char* bitsArray)
{
    long i;
    int index = 0;
    for (i = 1 << 30; i >= 0 && index < 31; i = i / 2)
    {
        if ((n & i) != 0)
        {
            bitsArray[index] = '1';
        }
        else
        {
            bitsArray[index] = '0';
        }
        index++;
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
            char arr[32];
            system("cls");
            printf("print in a integer decimal number\n");
            cin >> SIInput;
            printf("Binary mode representation: ");
            IntToBits(SIInput,arr);
            for (int i = 0;i < 31;i++) 
            {
                cout << arr[i];
            }
            
            printf("\n");
            printf("Press any button to continue");
            _getch();
            system("cls");
        }

        if (selectmode == 50) 
        {
            char arr2[64];
            system("cls");
            printf("print in a real decimal number\n");
            cin >> DInput;
            printf("Binary mode representation: ");
            DoubleToBits(DInput,arr2);
            for (int i = 0;i < 63;i++)
            {
                cout << arr2[i];
            }
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