#ifndef __DIARY__H__
#define __DIARY__H__

#include <string>
#include "Message.h"
#include "../include/Utils.h"

struct Diary
{
    Diary(const std::string &filename);
    ~Diary();

    std::string filename;
    Message *messages;
    size_t messages_size;
    size_t messages_capacity;

    void add(const std::string &message);
    void add(const Message &message);
    void write();
    void read();
    void list();
};

#endif //!__DIARY__H__