#ifndef EDITOR_H
#define EDITOR_H

#include "Document.h"
#include <sstream>

enum class string_code {
    print,
    num,
    print_all,
    make_current,
    append,
    insert,
    change,
    del,
    search,
    replace,
    quit,
    def
};

class Editor {

    private:
    Document doc;
    string_code hashit(std::string const& inString);

    public:
    Editor();
    void loop();


};

#endif