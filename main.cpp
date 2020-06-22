#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

//Formata a data e hora
std::string format_current_date(const std::string &format)
{
    std::time_t time = std::time(nullptr);
    char result[1024];

    std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

    return std::string(result);
}

//Retorna a data atual formatada
std::string get_current_date() { return format_current_date("%d/%m/%Y"); }

//Retorna a hora atual formatada
std::string get_current_time() { return format_current_date("%H:%M:%S"); }

//Imprime uma mensagem de uso dos comandos
void show_usage(const string &prog_name);

//Verifica se já existe algum registro no arquivo com a data de hoje;
bool verificar_data(const string &data_hoje);

//Lista as mensagem gravadas no arquivo
void list();

//Adiciona a mensagem ao arquivo
void add_message(string const &message, bool const &verificacao_current_data);

int main(int argc, char const *argv[])
{

    if (argc == 1 || (string(argv[1]) != "add" && string(argv[1]) != "list"))
        show_usage(argv[0]);

    string action = argv[1];

    if (action == "add")
    {
        string msg;
        bool registro_dia;
        if (argc == 3)
            msg = argv[2];
        else
        {
            cout << "Informe uma mensagem: ";
            getline(cin, msg);
        }
        registro_dia = verificar_data(get_current_date());
        add_message(msg, registro_dia);
        return 0;
    }
    if (action == "list")
        list();
    return 0;
}

void show_usage(const string &prog_name)
{
    cout << "Uso add: " << prog_name << " add <mensagem>" << endl;
    cout << "Uso list: " << prog_name << " list" << endl;
    exit(0);
}

void list()
{
    string line;
    int line_number = 0;
    ifstream arq_entrada("arquivo.txt");

    if (arq_entrada.fail())
    {
        cerr << "Não foi possível acessar o arquivo!" << endl;
        exit(0);
    }
    while (getline(arq_entrada, line))
    {
        if (line.size() == 0 || line[0] == '#')
            continue;
        cout << "- ";
        for (int i = 11; i < line.size(); i++)
            cout << line[i];
        cout << endl;
    }
    arq_entrada.close();
}

void add_message(string const &message, bool const &verificacao_current_data)
{
    ofstream arq_saida("arquivo.txt", ios::app);
    if (!verificacao_current_data)
    {
        arq_saida << "\n# " << get_current_date() << "\n\n";
    }

    arq_saida << "- " << get_current_time() << " " << message << endl;
    arq_saida.close();
    cout << "Mensagem '" << message << "' adicionada!" << endl;
}

bool verificar_data(const string &data_hoje)
{
    ifstream file("arquivo.txt");
    string line;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line.size() == 0 || line[0] == '-')
                continue;
            if (line == "# " + get_current_date())
                return true;
        }
    }

    return false;
}