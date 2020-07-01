#include "../include/App.h"
#include <iostream>
#include <string>

App::App(const std::string &filename) : diary(filename)
{
}

int App::run(int argc, char *argv[])
{
    if (argc == 1)
        return show_usage(argv[0]);
    std::string action = argv[1];
    if (action == "add")
    {
        if (argc == 2)
            add();
        else
            add(argv[2]);
    }
    else if (action == "list")
        list_messages();
    else if (action == "search")
    {
        if (argc == 2)
            show_usage(argv[0]);
        else
        {
            search(argv[2]);
        }
    }
    else
        return show_usage(argv[0]);
    return 0;
}

void App::search(const std::string word)
{
    std::vector<Message *> response = diary.search(word);
    if (response.size() != 0)
    {
        for (size_t i = 0; i < response.size(); i++)
        {
            std::cout << "- " << response[i]->content << std::endl;
        }
    }
    else
        std::cout << "Message not found!" << std::endl;
}

void App::add()
{
    std::string message;
    std::cout << "Enter your message:" << std::endl;
    std::getline(std::cin, message);

    add(message);
}

void App::add(const std::string message)
{
    diary.add(message);
    diary.write();
}

void App::list_messages()
{
    diary.list();
}

int App::show_usage(const std::string name_program)
{
    std::cout << "Uso add: " << name_program << " add <mensagem>" << std::endl;
    std::cout << "Uso list: " << name_program << " list" << std::endl;
    return 1;
}