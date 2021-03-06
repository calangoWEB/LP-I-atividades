#include "../include/Diary.h"
#include <iostream>
#include "../include/Message.h"

Diary::Diary(const std::string &filename) : messages_capacity(10), messages(nullptr), messages_size(0)
{
    messages = new Message[messages_capacity];
}

void Diary::add(const std::string &message)
{
    // adicionar mensagem no array de mensagens
    Message msg;
    msg.content = message;
    messages[messages_size] = msg;
    messages_size++;

    // Teste
    std::cout << messages[0].content << std::endl;
    // std::cout << "add mensagem" << std::endl;
}

void Diary::write()
{
    // gravar as mensagens no disco
    std::cout << "grava" << std::endl;
}