#include <iostream>
#include <fstream>
#include <string>;

using namespace std;

int main()
{
    string path = "words.txt";
    ifstream fin;
    fin.open(path);

    string word;
    cout << "Enter a word: ";
    cin >> word;
    cout << endl;

    if (!fin.is_open())
    {
        cout << "File opening error";
    }
    else
    {
        int res = 0;
        string str;

        while (!fin.eof())
        {
            fin >> str;
            if (str == word)
            {
                res += 1;
            }
        }
        cout << "The word: " << "\"" << word << "\"" << " is written " << res << " times";
    }
    fin.close(); 
}
