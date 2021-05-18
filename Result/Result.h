#ifndef TABLEOFLIFE_RESULT_H
#define TABLEOFLIFE_RESULT_H

#include <vector>
#include "../Request/Request.h"
#include <boost/uuid/uuid.hpp>            // uuid class

namespace u = boost::uuids;

struct Result {
    u::uuid id;
    std::vector<size_t> result;
    std::vector<Classes> classes; // все занятия, а вних id группы
    std::vector<std::vector<int>> students; // все ученики и их параметры
};


#endif //TABLEOFLIFE_RESULT_H
