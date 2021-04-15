#ifndef TABLEOFLIFE_TESTDATABASE_H
#define TABLEOFLIFE_TESTDATABASE_H
#include <vector>
#include "../IDatabase.h"
#include <../../Result/Result.h>

class TestDatabase: public IDatabase {
public:
    Database();
    Database(sql *connect);
    ~Database();

    int ** Select(int id);
    void Insert(int id, int **);

private:
    vector<Result*> connection;
};


#endif //TABLEOFLIFE_TESTDATABASE_H
