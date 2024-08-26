#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string path = "words.txt";
    ifstream fin(path);

    if (!fin.is_open())
    {
        cout << "File opening error" << endl;
    }

    string firstName, lastName, maxName, maxSurname, date;
    int payment, totalSum = 0, maxPayment = 0;

    while (fin >> firstName >> lastName >> payment >> date)
    {
        totalSum += payment;

        if (payment > maxPayment)
        {
            maxPayment = payment;
            maxName = firstName;
            maxSurname = lastName;
        }
    }

    cout << "Total amount of payments: " << totalSum << endl;
    cout << "Maximum payout: " << maxPayment << " received " << maxName << " " << maxSurname << endl;

    fin.close();
}