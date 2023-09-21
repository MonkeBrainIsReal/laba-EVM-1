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
    if ((u.bits & (1LL << 63)) != 0)
    {
        binaryArray[0] = '1';
    }
    else
    {
        binaryArray[0] = '0';

    }
    //binaryArray[1] = ' ';
    // Èçâëåêàåì áèòû ýêñïîíåíòû c ïîìîùüþ ìàñêè èç 11 áèòîâ (áèòû ñ 52 ïî 62)
    long long exponentBits = (u.bits >> 52) & ((1LL << 11) - 1);
    for (int i = 0; i < 13; i++)
    {
        if (exponentBits & (1LL << (10 - i)))
        {
            binaryArray[1 + i] = '1';
        }
        else {
            binaryArray[1 + i] = '0';
        }
    }
    //binaryArray[13] = ' ';
    // Èçâëåêàåì áèòû ìàíòèññû  ñ ïîìîùüþ ìàñêè èç 52 áèòîâ (áèòû ñ 0 ïî 51)
    long long mantissaBits = u.bits & ((1LL << 52) - 1);

    for (int i = 0; i < 52; i++)
    {
        if (mantissaBits & (1LL << (51 - i)))
        {
            binaryArray[14 + i] = '1';
        }
        else {
            binaryArray[14 + i] = '0';
        }

    }
    binaryArray[66] = '\0';
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
    for (int i = highestBitPos; i > highestBitPos - numBits - 1; i--)
    {
        if (i >= 0)
        {
            binaryArray[i] = toggleBit(binaryArray, i);
        }
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
                for (int i = 0; i < 32; i++) {
                    if (arr[31 - i] == '1') {
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
            for (int i = 0;i < 63;i++)
            {
                cout << arr2[i];
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
                toggleArray(arr2, NumEl, HighestBitpos);
                for (int i = 0;i < 64;i++)
                {
                    cout << arr2[i];
                }
                printf("\n");

                union craft_d
                {
                    double db;
                    long long int dat;
                }craft;
                craft.dat = 0;
                long long int b = 1;
                for (int i = 0; i < 64; i++)
                {
                    if (arr2[63 - i] == '1')
                    {
                        craft.dat = craft.dat | (b << i);
                    }
                }
                cout << "Decimal representation after inverting: " << craft.db;

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