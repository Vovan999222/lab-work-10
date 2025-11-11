#include "pch.h"
using namespace System;

int main(array<System::String^>^ args)
{
    Console::OutputEncoding = System::Text::Encoding::UTF8;

    int N = 0;

    while (true)
    {
        try
        {
            Console::Write(L"Введіть кількість пар речовин (A1, A2, ..., A2n): ");
            N = Int32::Parse(Console::ReadLine());

            if (N <= 0)
            {
                Console::WriteLine(L"Кількість пар речовин повинна бути більшою за 0!!!");
                continue;
            }
            break;
        }
        catch (FormatException^)
        {
            Console::WriteLine(L"Потрібно ввести ціле число!");
        }
        catch (OverflowException^)
        {
            Console::WriteLine(L"Введене число занадто велике або мале!");
        }
    }

    array<double>^ A = gcnew array<double>(2 * N);
    array<double>^ B = gcnew array<double>(N);

    Console::WriteLine(L"\n*** Введення даних ***");
    Console::WriteLine(L"Введіть дані для {0} пар речовин:", N);

    for (int i = 0; i < 2 * N; i++)
    {
        Console::WriteLine(L"\nРечовина A{0}:", i + 1);

        while (true)
        {
            try
            {
                Console::Write(L"Введіть кількість: ");
                A[i] = Double::Parse(Console::ReadLine());
                if (A[i] < 0) throw gcnew ArgumentOutOfRangeException();
                break;
            }
            catch (FormatException^)
            {
                Console::WriteLine(L"Введіть число (наприклад: 100)! ");
            }
            catch (ArgumentOutOfRangeException^)
            {
                Console::WriteLine(L"Кількість повинна бути не менше 0!");
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        B[i] = (A[2 * i] + A[2 * i + 1]) / 2.0 / 4.0;
    }

    Console::WriteLine(L"\nРезультати розрахунків:");
    Console::WriteLine(L"№\tA1\tA2\tB");
    Console::WriteLine(L"──────────────────────");

    for (int i = 0; i < N; i++)
    {
        Console::WriteLine(L"{0}\t{1:F2}\t{2:F2}\t{3:F3}",
            i + 1, A[2 * i], A[2 * i + 1], B[i]);
    }

    Console::WriteLine(L"\nякщо програма не працює зверніться на пошту 1488pozvoniimypodbrosim@gmail.com");
    Console::ReadKey();
    return 0;
}