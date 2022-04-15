#include <exception>
#include <iostream>
#include <stdexcept>

#include <hpx/local/init.hpp>
#include <hpx/modules/format.hpp>

#include "matrix.h"

int hpx_main(hpx::program_options::variables_map& vm) {
    try {
        std::size_t r1 = vm["r1"].as<std::size_t>();
        std::size_t c1 = vm["c1"].as<std::size_t>();
        std::size_t r2 = vm["r2"].as<std::size_t>();
        std::size_t c2 = vm["c2"].as<std::size_t>();

        if (r1 == 0 || c1 == 0 || r2 == 0 || c2 == 0 || c1 != r2) { throw std::runtime_error("invalid input"); }

        hpx::util::format_to(std::cout, "generating matrix 1 ({1}x{2})..\n", r1, c1);
        matrix matrix1(r1, c1);
        std::cout << "genrated matrix 1:\n";
        matrix1.print();
        hpx::util::format_to(std::cout, "generating matrix 2 ({1}x{2})..\n", r2, c2);
        matrix matrix2(r2, c2);
        std::cout << "genrated matrix 2:\n";
        matrix2.print();
        std::cout << "multiplying the matrices..\n";
        matrix multiplication = matrix1 * matrix2;
        std::cout << "result:\n";
        multiplication.print();
        std::cout << "exiting..";

        // clang-format off
    }catch (const std::exception& err) { 
        hpx::util::format_to(std::cerr, "error: {1}\n", err.what());
    }
    catch (...) {
        std::cerr<<"an unknown error occured..";
    }
    // clang-format on

    return hpx::local::finalize();
}

int main(int argc, char** argv) {
    hpx::program_options::options_description cli("usage: " HPX_APPLICATION_STRING " [options]");
    // clang-format off
    cli.add_options()
    ("r1", hpx::program_options::value<std::size_t>()->default_value(3), "matrix 1: number of rows")
    ("c1", hpx::program_options::value<std::size_t>()->default_value(3), "matrix 1: number of columns")
    ("r2", hpx::program_options::value<std::size_t>()->default_value(3), "matrix 2: number of rows")
    ("c2", hpx::program_options::value<std::size_t>()->default_value(3), "matrix 2: number of columns");
    // clang-format on

    hpx::local::init_params init_args;
    init_args.desc_cmdline = cli;

    return hpx::local::init(hpx_main, argc, argv, init_args);
}