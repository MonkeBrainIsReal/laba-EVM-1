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
    printf("Print in highest bit posistion ");
    int member;
    cin >> member;
    printf("Print in amount of elemets for inverting:\n");
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
    char ch = 0;
    while (ch == 0) {
        ch = _getch();
    }

}

void vivod() 
{
    setlocale(LC_ALL, "Ru");

    SMALL_RECT WinS = { 0, 0, 80, 25 };//прямоугольник буфера
    SetConsoleWindowInfo(Output, true, &WinS);
    CHAR_INFO chars = { ' ' };
    SMALL_RECT scroll = { 0, 6, 80, 25 };//где скроллится(искл менюшку)
    int i = 0;// colour
    for (int j = 0; j < 20; j++) 
    {
        cout << endl;
    } 
        while (i < 3000) {
            //SetConsoleCursorPosition(Output, { 15, 5 });  // Устанавливаем начальную позицию в окне

            SetConsoleTextAttribute(Output, i);


            cout << "Stroka                                     h";
            i++;
            ScrollConsoleScreenBuffer(Output, &scroll, NULL, { 0, 5 }, &chars);
            cout << ("\r");
            Sleep(100);
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
        printf("3 - for ");
        SetConsoleTextAttribute(Output, 12);
        printf("Laba 2");
        SetConsoleTextAttribute(Output, 14);
        printf(" implementation\n");
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
            if (sel2 == 89||121)
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
            if (sel2 == 89||121)
            {
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
        if (selectmode == 51) 
        {
            system("cls");
            vivod();
        }

        if (selectmode == 27)
        {
            system("cls");
            break;
        }
    }

}