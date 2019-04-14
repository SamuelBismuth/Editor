/* Samuel Bismuth 342533064 */
/* Matan Zilka 307949438 */

#include "Document.h"

/**
 Constructor.
 */
Document::Document() : current_line(-1) {}

/**
 Print the current line.
 */
void Document::print() {
    if (this->current_line == -1) {
        std:: cout << "?" << std::endl;
        return;
    }
    std::cout << this->lines[this->current_line] << std::endl;
}

/**
 Tab and then print the current line.
 */
void Document::num() {
    if (this->current_line == -1) {
        std:: cout << "?" << std::endl;
        return;
    }
    std::cout << this->current_line+1 << "         "; 
    this->print();
}

/**
 Make the num current line.
 */
void Document::make_current(int num) {
    num--;
    if (this->lines.size() <= num) {
        std:: cout << "?" << std::endl;
        return;
    }
    this->current_line = num;
    this->print();
}

/**
 Print all the lines.
 */
void Document::print_all() {
    if (this->current_line == -1) {
        std:: cout << "?" << std::endl;
        return;
    }
    for (int i = 0; i < this->lines.size(); i++) {
        std::cout << this->lines[i] << std::endl;
    }
}

/**
 Append line to the doc.
 */
void Document::append() {
    std::string line;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    getline(std::cin, line);
    while (line != ".") {
        std::vector<std::string>::iterator it;
        it = lines.begin();
        this->current_line++;
        this->lines.insert(it + this->current_line, line);
        getline(std::cin, line);
    }
}

/**
 Insert line to the doc before the current line.
 */
void Document::insert() {
    std::string line;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    getline(std::cin, line);
    if (this->current_line == -1) {
        this->current_line++;
    }
    while (line != ".") {
        std::vector<std::string>::iterator it;
        it = lines.begin();
        this->lines.insert(it + this->current_line, line);
        this->current_line++;
        getline(std::cin, line);
    }
}

/**
 Change the line with new data.
 */
void Document::change() {
    if (this->current_line == -1) {
        std:: cout << "?" << std::endl;
        return;
    }
    this->del();
    this->append();
}

/**
 Delete the current line.
 */
void Document::del() {
    if (this->current_line == -1) {
        std:: cout << "?" << std::endl;
        return;
    }
    std::vector<std::string>::iterator it;
    it = lines.begin();
    this->lines.erase(it + this->current_line);
    this->current_line--;
}

/**
 Search for the substring in the doc.
 */
void Document::search(std::string substring) {
    if (this->current_line == -1) {
        std:: cout << "?" << std::endl;
        return;
    }
    for (int i = this->current_line; i < this->lines.size(); i++) {
        if (this->lines[i].find(substring) != std::string::npos) {
            std::cout << this->lines[i] << std::endl;
            this->current_line = i;
            return;
        }
    }
    for (int i = 0; i < this->current_line; i++) {
        if (this->lines[i].find(substring) != std::string::npos) {
            std::cout << this->lines[i] << std::endl;
            this->current_line = i;
            return;
        }
    }
    std:: cout << "?" << std::endl;
}   

/**
 Replace the current line if exist.
 */
void Document::replace(std::string old_string, std::string new_string) {
    if (this->current_line == -1) {
        std:: cout << "?" << std::endl;
        return;
    }
    if (this->lines[this->current_line].find(old_string) != std::string::npos) {
        int index = this->lines[this->current_line].find(old_string);
        this->lines[this->current_line].replace(index, old_string.size(), new_string);
    }
    else {
        std:: cout << "?" << std::endl;
    }
}
