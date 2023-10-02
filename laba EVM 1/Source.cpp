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
        long long bits;
    } u;

    u.value = x;
    for (int i = 0;i < 64;i++)
    {

        if ((u.bits & (1LL << 63-i)) != 0)
        {
            binaryArray[i] = '1';
        }
        else
        {
            binaryArray[i] = '0';
        }
    }
}
void IntToBits(short int n, char* binaryArray)
{
    int index = 0;
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--)
    {
        if ((n >> i) & 1)
        {
            binaryArray[index] = '1';
        }
        else
        {
            binaryArray[index] = '0';
        }
        index++;
    }
}

char toggleBit(char* binaryStr, int pos)
{
    if (binaryStr[pos] == '0')
    {
        binaryStr[pos] = '1';
    }
    else if (binaryStr[pos] == '1')
    {
        binaryStr[pos] = '0';
    }
    return binaryStr[pos];
}

void toggleArray(char* binaryArray, int numBits, int highestBitPos)
{
    for (int i = highestBitPos; i > highestBitPos - numBits -1 ; i--)
    {
        if (i >= 0)
        {
            binaryArray[i] = toggleBit(binaryArray, i);
        }
    }
}

void transform_dbl(char* arr2)
{
    printf("hIGHEST BIT POS (от 0 до 64): ");
    int member;
    cin >> member;
    printf("NUM OF ELEMENTS FOR INVERTING: ");
    int amount;
    cin >> amount;
    for (int i = member; amount > 0; i--) {
        if (arr2[i] == '1') {
            arr2[i] = '0';
        }
        else if (arr2[ i] == '0') {
            arr2[i] = '1';
        }
        amount--;
    }
    for (int i = 0; i < 64; i++) {
        cout << arr2[i];
    }
    union craft_d
    {
        double db;
        long long int dat;
    }craft;
    craft.dat = 0;
    long long int b = 1;
    for (int i = 0; i <= 63; i++)
    {
        if (arr2[63 - i] == '1')
        {
            craft.dat = (craft.dat | (b << i));
        }
    }
    cout << "Decimal representation after inverting: " << craft.db;
    printf("\nPOhui");
    char ch = 0;
    while (ch == 0) {
        ch = _getch();
    }

}

int main()
{
    short int SIInput;
    double DInput;

    while (TRUE)
    {
        SetConsoleTextAttribute(Output, 14);
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
            char* arr = new char[sizeof(SIInput * 8) - 1];
            system("cls");
            printf("print in a integer decimal number\n");
            cin >> SIInput;
            printf("Binary mode representation: ");
            IntToBits(SIInput, arr);
            for (int i = 0;i < 16;i++)
            {
                cout << arr[i];
            }
            printf("\n");
            printf("Press Y for inverting bytes and N to enter main menu\n");
            int sel2 = _getch();
            if (sel2 == 89)
            {
                int HighestBitpos, NumEl;
                printf("Print in a highest bit position\n");
                cin >> HighestBitpos;
                printf("Print in number of elemets for inverting\n");
                cin >> NumEl;
                toggleArray(arr, NumEl, HighestBitpos);
                for (int i = 0;i < 16;i++)
                {
                    cout << arr[i];
                }
                printf("\n");
                unsigned long int a = 0;
                unsigned long int b = 1;
                for (int i = 0; i < 16; i++) {
                    if (arr[15 - i] == '1') {
                        a = a | (b << i);
                    }
                }
                cout << "Decimal representation after inverting: " << a;

            }
            if (sel2 == 78)
            {

            }
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
            DoubleToBits(DInput, arr2);
            for (int i = 0;i < 64;i++)
            {
                cout << arr2[i];
            }
            printf("\n");
            printf("Press Y for inverting bytes and N to enter main menu\n");
            int sel2 = _getch();
            if (sel2 == 89)
            {
                int HighestBitpos, NumEl;
               /* printf("Print in a highest bit position\n");
                cin >> HighestBitpos;
                printf("Print in number of elemets for inverting\n");
                cin >> NumEl;
                toggleArray(arr2, NumEl, HighestBitpos);*/
                for (int i = 0;i < 64;i++)
                {
                    cout << arr2[i];
                }
                printf("\n");
                transform_dbl(arr2);
                
              

            }
            if (sel2 == 78)//SNAP BACK TO MAIN MENU
            {

            }
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