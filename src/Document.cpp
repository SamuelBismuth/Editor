#include "Document.h"

Document::Document() : current_line(-1) {}

void Document::print() {
    if (this->current_line == -1) {
        std:: cout << "?" << std::endl;
        return;
    }
    std::cout << this->lines[this->current_line] << std::endl;
}

void Document::num() {
    if (this->current_line == -1) {
        std:: cout << "?" << std::endl;
        return;
    }
    std::cout << this->current_line << "  "; 
    this->print();
}

void Document::make_current(int num) {
    num--;
    if (this->lines.size() <= num) {
        std:: cout << "?" << std::endl;
        return;
    }
    this->current_line = num;
}

void Document::print_all() {
    if (this->current_line == -1) {
        std:: cout << "?" << std::endl;
        return;
    }
    for (int i = 0; i < this->lines.size(); i++) {
        std::cout << this->lines[i] << std::endl;
    }
}

void Document::append() {
    std::string line;
    std::cin >> line;
    while (line != ".") {
        std::vector<std::string>::iterator it;
        it = lines.begin();
        this->current_line++;
        this->lines.insert(it + this->current_line, line);
        std::cin >> line;
    }
}

void Document::insert() {
    std::string line;
    std::cin >> line;
    if (this->current_line != -1) {
        this->current_line--;
    }
    while (line != ".") {
        std::vector<std::string>::iterator it;
        it = lines.begin();
        this->current_line++;
        this->lines.insert(it + this->current_line, line);
        std::cin >> line;
    }
}

void Document::change() {
    if (this->current_line == -1) {
        std:: cout << "?" << std::endl;
        return;
    }
    this->del();
    this->append();
}

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

void Document::search(std::string substring) {
    if (this->current_line == -1) {
        std:: cout << "?" << std::endl;
        return;
    }
    for (int i = 0; i < this->lines.size(); i++) {
        if (this->lines[i].find(substring) != std::string::npos) {
            std::cout << this->lines[i] << std::endl;
            this->current_line = i;
            return;
        }
    }
}   

void Document::replace(std::string old_string, std::string new_string) {
    if (this->current_line == -1) {
        std:: cout << "?" << std::endl;
        return;
    }
    if (this->lines[this->current_line].find(old_string) != std::string::npos) {
        int index = this->lines[this->current_line].find(old_string);
        this->lines[this->current_line].replace(index, new_string.size() - 1, new_string);
    }
    else {
        std:: cout << "?" << std::endl;
    }
}
