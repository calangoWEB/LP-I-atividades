#include "../include/App.h"
#include "../include/Diary.h"

#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char *argv[])
{
    App p("arquivo.txt");
    p.add("message");
    p.add("message");
    p.list_messages();
    p.write();
    return 0;
}