//
// Created by blackprince on 18/08/23.
//
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>

std::list<std::string> split_by(std::string& text, char& s) {
    std::list<std::string> texts;
    std::string buffer;

    for (char ch : text) {
        if (ch == s) {
            texts.push_back(buffer);
            buffer = " ";
            continue;
        }
        buffer += ch;
    }
    if (buffer.length() > 0) texts.push_back(buffer);
    return texts;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "This is not the correct use for this application: \n";
        std::cerr << "Correct use: read_file_buffer <file>";

        return EXIT_FAILURE;
    }

    std::string contents;
    {
        std::fstream input(argv[1], std::ios::in);
        std::stringstream contents_stream;
        contents_stream << input.rdbuf();
        contents = contents_stream.str();
    }

    char character = ' ';
    auto _iter_contents = split_by(contents, character);

    int count_includes = 0;
    for (auto stream : _iter_contents) {
        if (stream.find("#include")) count_includes += 1;
    }

    std::cout << " Number of includes from CPP file: " << count_includes
              << std::endl;

    for (auto item : _iter_contents) std::cout << item;

    return EXIT_SUCCESS;
}
