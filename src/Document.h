#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>
#include <vector>

class Document {

    private:
    std::vector<std::string> lines;
    int current_line;

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