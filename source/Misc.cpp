//
// Created by Timothée Couble on 17/10/2019.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string readShader(const std::string &name) {
    std::string vs_text;
    std::ifstream vs_file(name);

    std::string vs_line;
    if (vs_file.is_open()) {

        while (std::getline(vs_file, vs_line)) {
            vs_text += vs_line;
            vs_text += '\n';
        }
        vs_file.close();
    }
    return vs_text;
}