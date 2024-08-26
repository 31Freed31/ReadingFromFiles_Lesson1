#include <iostream>
#include <fstream>

using namespace std;

bool isPNG(const string& filePath)
{
    ifstream file(filePath, ios::binary);

    if (!file.is_open())
    {
        cout << "Ошибка открытия файла." << endl;
        return false;
    }

    if (file.get() == 0x89 &&
        file.get() == 'P' &&
        file.get() == 'N' &&
        file.get() == 'G')
    {
        return true;
    }

    return false;
}

int main()
{
    setlocale(LC_CTYPE, "rus");

    string filePath;
    cout << "Введите путь к файлу: ";
    cin >> filePath;

    if (isPNG(filePath))
    {
        cout << "Файл является PNG-изображением." << endl;
    }
    else
    {
        cout << "Файл НЕ является PNG-изображением." << endl;
    }
}