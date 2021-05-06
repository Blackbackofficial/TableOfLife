#ifndef TABLEOFLIFE_REPORTER_H
#define TABLEOFLIFE_REPORTER_H

#include <memory>


class GABuilder;
class Database;
class ParserGAtoHuman;
template<class T> class Queue;
struct Solution;

class Reporter {
public:

    Reporter();
    ~Reporter();

    void SetUp(std::shared_ptr<Queue<Result*>> &results, std::unique_ptr<Database> db);

    void WorkCycle(int);

private:

    Reporter(const Reporter & a) = delete;
    Reporter& operator=(const Reporter & a) = delete;

    std::shared_ptr<Queue<Result*>> rque;
    std::shared_ptr<IDatabase> db;
};


#endif //TABLEOFLIFE_REPORTER_H