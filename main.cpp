#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    string msg;
    if (argc == 1 || string(argv[1]) != "add")
    {
        cout << "Uso: " << argv[0] << " add <mensagem>" << endl;
        return 1;
    }

    ofstream arq_saida("arquivo.txt", ios::app);

    if (argc == 2)
    {
        cout << "Informe uma mensagem: ";
        getline(cin, msg);
    }

    if (argc == 3)
        msg = argv[2];

    arq_saida << msg << endl;
    arq_saida.close();
    cout << "Mensagem ''" << msg << "'' adicionada!" << endl;
    return 0;
}
