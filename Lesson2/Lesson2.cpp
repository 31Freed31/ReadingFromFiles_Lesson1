#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string path;

    cout << "Enter the path of the file: " << endl;
    cout << "For example: C:\\Users\\Freed31\\Desktop\\AdvancedCPP\\Lesson1\\Lesson2" << endl;

    cin >> path;
    cout << endl;

    ifstream fin;
    fin.open(path);


    if (!fin.is_open())
    {
        cout << "File opening error";
    }
    else
    {
        string str;

        while (!fin.eof())
        {
            str = " ";
            getline(fin, str);
            cout << str << endl;
        }
    }
    fin.close();
}