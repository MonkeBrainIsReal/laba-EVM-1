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
    if ((u.bits & (1LL << 63)) != 0) // Бит знака (бит 63) 
    {
        binaryArray[0] = '1';
    }
    else 
    {
        binaryArray[0] = '0';

    }
    binaryArray[1] = ' ';
    // Извлекаем биты экспоненты c помощью маски из 11 битов (биты с 52 по 62)
    long long exponentBits = (u.bits >> 52) & ((1LL << 11) - 1); 
    for (int i = 0; i < 11; i++) 
    {
        if (exponentBits & (1LL << (10 - i))) 
        {
            binaryArray[2 + i] = '1';
        }
        else {
            binaryArray[2 + i] = '0';
        } 
    }
    binaryArray[13] = ' ';
    // Извлекаем биты мантиссы  с помощью маски из 52 битов (биты с 0 по 51)
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

void toggleBit(char* binaryStr, int pos)
{
    if (binaryStr[pos] == '0') 
    {
        binaryStr[pos] = '1';
    }
    else if (binaryStr[pos] == '1') 
    {
        binaryStr[pos] = '0';
    }
}

void toggleArray(char** numbers, int numElements, int numBits, int highestBitpos)//эл масива; колво инвертируемых бит; старший разряд
{
    for (int i = 0; i < numElements; i++) 
    {
        for (int j = highestBitpos; j > highestBitpos - numBits; j--) 
        {
            toggleBit(numbers[i], j);
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
            char* arr= new char[sizeof(SIInput*8-1)];
            system("cls");
            printf("print in a integer decimal number\n");
            cin >> SIInput;
            printf("Binary mode representation: ");
            
            IntToBits(SIInput,arr);
            for (int i = 0;i < 16;i++) 
            {
                cout << arr[i];
            }
            printf("\n");
            printf("Press Y for inverting bytes and N to enter main menu\n");
            int sel2 =_getch();
            if (sel2 == 89) 
            {
                int HighestBitpos,NumEl;
                cin >> HighestBitpos;
                cin >> NumEl;
                toggleArray(&arr,sizeof(arr),NumEl,HighestBitpos);
                for (int i = 0;i < 16;i++)
                {
                    cout << arr[i];
                }
                printf("UOugh");

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