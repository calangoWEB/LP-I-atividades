#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    string msg;

    if (argc == 1)
    {
        cout << "Uso: " << argv[0] << " add <mensagem>" << endl;
        return -1;
    }

    if (argc == 2 && string(argv[1]) == "add")
    {
        cout << "Informe uma mensagem: ";
        getline(cin, msg);
        cout << msg << endl;
    }

    if (argc == 3)
    {
        cout << argv[2] << endl;
    }
}
