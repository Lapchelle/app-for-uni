// hack (c++).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "stdafx.h"
using namespace std;
int main()
{   

    int valueToWrite = 0;
    cin >> valueToWrite;
    HWND window = FindWindowA(0, "Form1");
    if (window == 0) {
        cout << "Window not found!" << endl;
    }
    else {
        DWORD processId;
        GetWindowThreadProcessId(window, &processId);
        HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, false, processId);

        if (!process) {
            cout << "Process could not be open!" << endl;

        }
        else {
            int memoryWriteStatus = WriteProcessMemory(process, (LPVOID) 0x026B5A78, &valueToWrite, (DWORD)sizeof(valueToWrite), NULL);
            if (memoryWriteStatus > 0) {
                cout << "Data has been succsessfuly written" << endl;
            }
            else {
                cout << "Error" << endl;
            }
        }
        CloseHandle(process);
        cin.get();
    }
    return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
