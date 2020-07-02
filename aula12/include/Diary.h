#ifndef __DIARY__H__
#define __DIARY__H__

#include <string>
#include "Message.h"
#include "../include/Utils.h"
#include <vector>

struct Diary
{
    Diary(const std::string &filename);

    std::string filename;
    std::vector<Message> messages;

    void add(const std::string &message);
    void add(const Message &message);
    void write();
    void read();
    void list();
    std::vector<Message *> search(const std::string &what);
};

#endif //!__DIARY__H__