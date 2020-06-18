#include <iostream>
#include <fstream>
using namespace std;

void show_usage(const string &prog_name);

int main(int argc, char const *argv[])
{

    if (argc == 1 || (string(argv[1]) != "add" && string(argv[1]) != "list"))
    {
        show_usage(argv[0]);
        return 1;
    }

    string action = argv[1];

    if (action == "add")
    {
        string msg;
        ofstream arq_saida("arquivo.txt", ios::app);
        if (arq_saida.fail())
        {
            cerr << "Não foi possível acessar o arquivo!" << endl;
            return 1;
        }
        if (argc == 3)
            msg = argv[2];
        else
        {
            cout << "Informe uma mensagem: ";
            getline(cin, msg);
        }

        arq_saida << msg << endl;
        arq_saida.close();
        cout << "Mensagem '" << msg << "' adicionada!" << endl;
        return 0;
    }

    if (action == "list")
    {
        string line;
        int line_number = 0;
        ifstream arq_entrada("arquivo.txt");

        if (arq_entrada.fail())
        {
            cerr << "Não foi possível acessar o arquivo!" << endl;
            return 1;
        }
        cout << "Mensagens:\n\n";
        while (getline(arq_entrada, line))
        {
            ++line_number;
            if (line.size() == 0)
                continue;
            cout << line_number << ". " << line << endl;
        }
        arq_entrada.close();
    }

    return 0;
}

void show_usage(const string &prog_name)
{
    cout << "Uso add: " << prog_name << " add <mensagem>" << endl;
    cout << "Uso list: " << prog_name << " list" << endl;
}