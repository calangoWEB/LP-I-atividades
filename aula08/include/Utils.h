#ifndef __UTILS__H__
#define __UTILS__H__

#include <string>

//Formata a data ou hora
std::string format_current_date(const std::string &format);

//Retorna a data atual formatada
std::string get_current_date();

//Retorna a hora atual formatada
std::string get_current_time();

#endif //!__UTILS__H__