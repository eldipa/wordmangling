
#include <iostream>
#include <fstream>
#include <ostream>
#include <istream>

#include "rules.h"
#include <list>

#include <stdexcept>

class Mangle;

class BadFile : public std::exception {
private:
    std::string msg;
public:
    BadFile(const char *arg) : msg(arg) {}
    virtual ~BadFile() throw() {}
};

class Main {
private:
    std::ostream *out;
    bool is_stdout;

    std::istream *in;
    bool is_stdin;

    std::ifstream rules_file;

public:
    Main() : out(0), is_stdout(false), in(0), is_stdin(false) {}

    void process(char *rules_path, char *input_path, char *out_path) {
        open_output(out_path);
        Rules r(*out);

        open_rules(rules_path);
        rules_file >> r;

        open_input(input_path);
        r.mangle_words(*in);
    }

    void open_rules(char *arg) {
        rules_file.open(arg);
        if(not rules_file.is_open())
            throw BadFile(arg);
    }

    void open_output(char* arg) {
        if(std::string(arg) != "-") {
            std::ofstream *out = new std::ofstream(arg);
            this->out = out;
            is_stdout = false;
            if(not out->is_open())
                throw BadFile(arg);
        }
        else {
            out = &std::cout;
            is_stdout = true;
        }
    }

    void open_input(char* arg) {
        if(std::string(arg) != "-") {
            std::ifstream *in = new std::ifstream(arg);
            this->in = in;
            is_stdin = false;
            if(not in->is_open())
                throw BadFile(arg);
        }
        else {
            in = &std::cin;
            is_stdin = true;
        }
    }

    ~Main() {
        if(not is_stdout and out) {
            static_cast<std::ofstream*>(out)->close();
            delete out;
        }

        if(not is_stdin and in) {
            static_cast<std::ifstream*>(in)->close();
            delete in;
        }
    }
};

int main(int argc, char *argv[]) {
    if(argc != 4) {
        std::cout << "Usage: ./wm <rules> <dictionary> <output>\n"
                  << "  <rules>       file with the rules to apply.\n"
                  << "  <dictionary>  input file with the words to be mangled;\n"
                  << "                if it is '-', read it from stdin.\n"
                  << "  <output>      output file to save the mangled words;\n"
                  << "                if it is '-', write them to stdout.\n";
        return 1;
    }

    try {
        Main().process(argv[1], argv[2], argv[3]);
    }
    catch(const BadFile& b) {
        std::cerr << "Bad file. Aborting." << std::endl;
        return 2;
    }
    catch(...) {
        std::cerr << "Unknown error. Aborting." << std::endl;
        return 2;
    }
    return 0;
}
