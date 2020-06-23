#ifndef __DIARY__H__
#define __DIARY__H__

#include <string>
#include "Message.h"

struct Diary
{
    Diary(const std::string &filename);
    std::string filename;
    Message *messages;
    size_t messages_size;
    size_t messages_capacity;

    void add(const std::string &message);
    void write();
};

#endif //!__DIARY__H__