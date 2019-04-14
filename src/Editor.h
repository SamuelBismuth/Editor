/* Samuel Bismuth 342533064 */
/* Matan Zilka 307949438 */

#ifndef EDITOR_H
#define EDITOR_H

#include "Document.h"
#include <sstream>

/**
 Enum with all the possibility.
 */
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

/**
 Class Editor.
 */
class Editor {

    private:
    Document doc;  // The doc.
    string_code hashit(std::string const& inString);

    public:
    Editor();
    void loop();


};

#endif
