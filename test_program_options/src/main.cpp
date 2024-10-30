#include <boost/program_options.hpp>
#include <iostream>
#include <print>
#include <string>
#include <vector>

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
    po::options_description desc{std::format(
        "Usage: {} [--help] [--input-file <input-file>] <output-file>",
        argv[0])};
    desc.add_options()("help", "produce help message")(
        "input-file,i", po::value<std::string>(), "input file to parse")(
        "output-file", po::value<std::string>()->required(),
        "file to write to");

    po::positional_options_description p;
    p.add("output-file", 1);

    po::variables_map vm;
    try {
        po::store(po::command_line_parser(argc, argv)
                      .options(desc)
                      .positional(p)
                      .run(),
                  vm);
        po::notify(vm);
    } catch (po::error& e) {
        std::println(std::cerr, "error: {}", e.what());
        desc.print(std::cerr);
        return 1;
    }

    if (vm.count("help")) {
        desc.print(std::cerr);
        return 1;
    }
    if (vm.count("input-file")) {
        std::println("file: {}", vm["input-file"].as<std::string>());
    }
    if (vm.count("output-file")) {
        std::println("out file: {}", vm["output-file"].as<std::string>());
    }
}
