#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int CountSim(const string s, const string cs)
{
    size_t pos = 0;
    int k = 0;
    while ((pos = s.find_first_of(cs, pos)) != -1)
    {
        k++;
        pos++;
    }
    return k;
}

string ChangeSim(string& s)
{
    size_t pos = 0;
    while ((s.find("+") != -1 || s.find("-") != -1 || s.find("=") != -1))
    {
        if (s.find("+") != -1)
        {
            s = s.replace(s.find("+"), 1, "**");
        }
        if (s.find("-") != -1)
        {
            s = s.replace(s.find("-"), 1, "**");
        }
        if (s.find("=") != -1)
        {
            s = s.replace(s.find("="), 1, "**");
        }
    }

    return s;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    string cs;

    cout << "Ввод: ";

    getline(cin, cs);; cout << endl;
    char s[] = "+-=";

    cout << "Кол-во: " << CountSim(cs, s) << endl;

    string dest = ChangeSim(cs);

    cout << "Вывод: " << dest << endl;

    return 0;
}