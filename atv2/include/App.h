#ifndef __APP__H__
#define __APP__H__

#include <string>
#include "Diary.h"

struct App
{
    Diary diary;

    App(const std::string &filename);
    int run(int argc, char *argv[]);
    int show_usage(const std::string name_program);
    void add();
    void add(const std::string message);
    void list_messages();
    void write();
};

#endif //!__APP__H__