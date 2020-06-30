#include "../include/Diary.h"
#include <iostream>
#include <fstream>
#include "../include/Utils.h"
#include <sstream>

//Construtor
Diary::Diary(const std::string &file_name) : filename(file_name), messages(nullptr), messages_size(0), messages_capacity(10)
{
    messages = new Message[messages_capacity];
    read();
}

Diary::~Diary()
{
    delete[] messages;
}

void Diary::add(const std::string &message)
{

    if (messages_size == messages_capacity)
    {
        size_t new_messages_capacity = messages_capacity * 2;
        Message *newArray = new Message[new_messages_capacity];
        for (size_t i = 0; i < messages_size; i++)
            newArray[i] = messages[i];
        messages_capacity = new_messages_capacity;
        delete[] messages;
        messages = newArray;
    }

    // adicionar mensagem no array de mensagens
    Message msg;
    msg.content = message;
    msg.date.set_from_string(get_current_date());
    msg.time.set_from_string(get_current_time());
    messages[messages_size] = msg;
    messages_size++;
}

void Diary::add(const Message &message)
{
    if (messages_size == messages_capacity)
    {
        size_t new_messages_capacity = messages_capacity * 2;
        Message *newArray = new Message[new_messages_capacity];
        for (size_t i = 0; i < messages_size; i++)
            newArray[i] = messages[i];
        messages_capacity = new_messages_capacity;
        delete[] messages;
        messages = newArray;
    }
    messages[messages_size] = message;
    messages_size++;
}

void Diary::write()
{
    //Parte-se do presuposto que as datas sempre estão em ordem cronológica
    std::ofstream file_output(filename, std::ios::out);
    if (messages_size == 0)
    {
        std::cout << "First add messages!" << std::endl;
        exit(0);
    }
    std::string date_container = messages[0].date.toString();
    file_output << "# " << date_container << "\n\n";
    for (size_t i = 0; i < messages_size; i++)
    {
        if (messages[i].date.toString() == date_container)
        {
            // std::cout << "- " << messages[i].time.toString() << " " << messages[i].content << std::endl;
            file_output << "- " << messages[i].time.toString() << " " << messages[i].content << std::endl;
        }
        else
        {
            date_container = messages[i].date.toString();
            std::cout << date_container << std::endl;
            file_output << "\n# " << date_container << "\n\n";
            file_output << "- " << messages[i].time.toString() << " " << messages[i].content << std::endl;
        }
    }
    std::cout << "Mensagem adicionada!" << std::endl;
    file_output.close();
}

void Diary::list()
{
    for (size_t i = 0; i < messages_size; i++)
        std::cout << "- " << messages[i].content << std::endl;
}

void Diary::read()
{
    //Ler mensagens do arquivo e põe no array
    std::string line;
    std::ifstream file_input(filename);
    if (file_input.is_open())
    {
        Message msg;
        std::string date_container;
        while (getline(file_input, line))
        {
            if (line.size() == 0)
                continue;
            if (line[0] == '#')
            {
                std::stringstream stream(line);
                std::string date;
                char discard;
                stream >> discard;
                stream >> date;
                date_container = date;
                continue;
            }
            if (line[0] == '-')
            {
                std::stringstream stream(line);
                std::string time;
                std::string message;
                char discard;
                stream >> discard;
                stream >> time;
                stream >> message;
                msg.time.set_from_string(time);
                msg.date.set_from_string(date_container);
                msg.content = message;
                add(msg);
            }
        }
        file_input.close();
    }
}

Message *Diary::search(const std::string &what)
{
    for (size_t i = 0; i < messages_size; i++)
    {
        if (messages[i].content.find(what) != std::string::npos){
            return &messages[i];
        }
    }
    return nullptr;
}