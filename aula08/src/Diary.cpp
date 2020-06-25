#include "../include/Diary.h"
#include <iostream>
#include <fstream>
#include "../include/Utils.h"

//Construtor
Diary::Diary(const std::string &file_name) : filename(file_name), messages(nullptr), messages_size(0), messages_capacity(10)
{
    messages = new Message[messages_capacity];
}

Diary::~Diary()
{
    delete[] messages;
}

void Diary::add(const std::string &message)
{

    if (messages_size == messages_capacity)
        return;

    // adicionar mensagem no array de mensagens
    Message msg;
    msg.content = message;
    msg.date.set_from_string(get_current_date());
    msg.time.set_from_string(get_current_time());
    messages[messages_size] = msg;
    messages_size++;
}

void Diary::write()
{
    // gravar as mensagens no disco
    std::cout << "grava" << std::endl;
}

void Diary::read()
{
    //Ler mensagens do arquivo e põe no array
    std::string line;
    std::ifstream file_input(filename);

    if (file_input.is_open())
    {
        while (getline(file_input, line))
        {
            if (line.size() == 0 || line[0] == '#')
                continue;
            for (int i = 11; i < line.size(); i++)
                std::cout << line << std::endl;
        }
        file_input.close();
    }
}