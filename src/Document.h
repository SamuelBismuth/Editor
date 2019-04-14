/* Samuel Bismuth 342533064 */
/* Matan Zilka 307949438 */

#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>

/**
 Class Documennt.
 */
class Document {

    private:
    std::vector<std::string> lines;  // The lines.
    int current_line;  // The current line.

    public:
    Document();

    void print();
    void num();
    void print_all();
    void make_current(int num);
    void append();
    void insert();
    void change();
    void del();
    void search(std::string substring);
    void replace(std::string old_string, std::string new_string);

};

#endif
