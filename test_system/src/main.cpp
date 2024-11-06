#include <SDKDDKVer.h>

#include <boost/process.hpp>
#include <iostream>
#include <print>

namespace bp = boost::process;

int main(int argc, char* argv[]) {
    bp::ipstream pipe_stream;

    bp::child c{bp::search_path("winver"), bp::std_out > pipe_stream};

    std::string line;
    while (pipe_stream && std::getline(pipe_stream, line) && !line.empty()) {
        std::println("output: {}", line);
    }
    c.wait();

    return EXIT_SUCCESS;
}
