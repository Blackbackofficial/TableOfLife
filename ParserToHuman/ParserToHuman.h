#ifndef TABLEOFLIFE_PARSERGATOHUMAN_H
#define TABLEOFLIFE_PARSERGATOHUMAN_H

class json;

class ParserToHuman {
public:
    ParserToHuman();
    ~ParserToHuman();

    std::string GetReadable(int **);
private:

    ParserToHuman() = delete;
    ParserToHuman(const ParserToHuman &a) = delete;
    ParserToHuman& operator=(const ParserToHuman &a) = delete;

};


#endif //TABLEOFLIFE_PARSERGATOHUMAN_H