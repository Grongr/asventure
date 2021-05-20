#include <ios>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

#include "dialogue.h"

//-----------------------------------------------------------------------------------------------------------//

Dialogue::Dialogue(std::string filepath) {
    std::ifstream dlg;
    dlg.open(filepath);

    if (!dlg.is_open()) {
        throw std::runtime_error("some shit with file");
    }

    std::string iter;

    std::getline(dlg, iter);
    while (iter != "###" && !dlg.eof()) {
        std::getline(dlg, iter);
    }

    std::string button;
    std::string phrase;
    while (!dlg.eof()) {
        button = "";
        phrase = "";

        std::getline(dlg, button);
        
        std::getline(dlg, iter);
        
        while (iter != "###" && !dlg.eof()) {
            phrase += iter + "\n";
            std::getline(dlg, iter);
        }

        this->variants[button] = phrase;
    }

    dlg.close();
}

void Dialogue::print_dialogues(std::ostream &out) const {
    for (auto it = variants.begin(); it != variants.end(); ++it) {
        out << it->first << std::endl;
        out << it->second << std::endl;
    }   
}

//-----------------------------------------------------------------------------------------------------------//
