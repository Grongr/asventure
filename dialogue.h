#ifndef DIALOGU_EHEADER_INCLUDED
#define DIALOGU_EHEADER_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class Dialogue {
public:

    /*!
     * Default constructor. It takes information from file
     * and converts it into map, so you can start a dialogue
     * @param filepath  -  path to the file, where dialogues are saved
     */
    Dialogue(std::string filepath);

    /*!
     * Prints in out stream all possible
     * Dialogs, so that you can check them
     * @param out stream
     */
    void print_dialogues(std::ostream& out) const;

    /*!
     * Search for file named "type" + str(num) + ".dlg"
     * in ../dialogues folder
     * @param type  -  pirate if pirateship, police if policeship, planet if planet
     * @param num   -  number of dude. 0 if it is a standart one
     * @return path to the file or "" if file wasn't found
     */
    static std::string find_file(std::string type, int num=0) {
        std::string filepath = "../dialogues/" + type + std::to_string(num) + ".dlg";

        std::fstream dlg(filepath, std::ios::in);

        if (dlg.is_open())
            return std::move(filepath);
        else
            return "";
    }

    // Params made public not to copy them every time
    std::map<std::string, std::string> variants;
};

#endif // DIALOGU_EHEADER_INCLUDED
