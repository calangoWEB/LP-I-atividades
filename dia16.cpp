#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string msg;

    if (argc == 1)
    {
        cout << "Uso: " << argv[0] << " add <mensagem>" << endl;
    }
    else if (argc == 2)
    {
        cout << "Informe uma mensagem: ";
        getline(cin, msg);
        cout << msg << endl;
    }
    else if (argc == 3)
    {
        cout << argv[2] << endl;
    }
    else
    {
        cout << "Entradas inválidas.";
    }
}
