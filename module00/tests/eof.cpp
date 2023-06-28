#include <iostream>

using namespace std;

int main(void)
{
    string s;

    while (true)
    {
        cout << "Enter a input: ";
        cin >> s;
        if (cin.eof())
        {
            cout << "EOF detected" << endl;
            cout << "EOF: You entered: " << s << endl;
            cout << "Try enter again: " << endl;
            cin >> s;
            break;
        }
        cout << "You entered: " << s << endl;
    }
}
