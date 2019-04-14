#include "Editor.h"

Editor::Editor() {
}

string_code Editor::hashit(std::string const& inString) {
    if (inString == "p") return string_code::print;
    if (inString == "n") return string_code::num;
    if (inString == "%p") return string_code::print_all;
    int number;
    std::istringstream iss (inString);
    iss >> number;
    if (number > 0) {
        doc.make_current(number);
        return string_code::make_current;
    }
    if (inString == "a") return string_code::append;
    if (inString == "i") return string_code::insert;
    if (inString == "c") return string_code::change;
    if (inString == "d") return string_code::del;
    if (inString.at(0) == '/') return string_code::search;
    if (inString.at(0) == 's') return string_code::replace;
    if (inString == "Q") return string_code::quit;
    else return string_code::def;
}

void Editor::loop() {
    while (1) {
        std::string line;
        std::cin >> line;
        switch (hashit(line)) {
            case string_code::print:
                doc.print();
                break;
            case string_code::num:
                doc.num();
                break;
            case string_code::print_all:
                doc.print_all();
                break;
            case string_code::make_current:
                // Done in the hashit function.
                break;
            case string_code::append:
                doc.append();
                break;
            case string_code::insert:
                doc.insert();
                break;
            case string_code::change:
                doc.change();
                break;
            case string_code::del:
                doc.del();
                break;
            case string_code::search:
                doc.search(line.substr(1,line.size()));
                break;
            case string_code::replace:
                if (line.substr(2, line.size()).find('/') != std::string::npos) {
                    int index = line.substr(2, line.size()).find('/');
                    doc.replace(line.substr(2, index), line.substr(index + 3, line.size()));
                }
                else {
                    std:: cout << "?" << std::endl;
                }
                break;
            case string_code::quit:
                exit(0);
                break;
            case string_code::def:
                std:: cout << "?" << std::endl;
                break;
            default:
                std:: cout << "?" << std::endl;
        }
    }
}