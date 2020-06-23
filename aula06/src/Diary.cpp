#include "../include/Diary.h"
#include <iostream>

Diary::Diary(const std::string &filename)
{
}

void Diary::add(const std::string &message)
{
    // adicionar mensagem no array de mensagens
    std::cout << "add mensagem" << std::endl;
}

void Diary::write()
{
    // gravar as mensagens no disco
    std::cout << "grava" << std::endl;
}