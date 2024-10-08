/**
 * File              : parser.hpp
 * Author            : Rustam Khafizov <super.rustamm@gmail.com>
 * Date              : 25.03.2021 15:05
 * Last Modified Date: 09.05.2021 19:33
 * Last Modified By  : Rustam Khafizov <super.rustamm@gmail.com>
 */

#ifndef PARSER_HPP
# define PARSER_HPP

# include <boost/program_options.hpp>
# include <exception>
# include <iostream>
# include <fstream>
# include <cstdint>
# include <random>
# include <string>
# include <ctime>

# include "state.hpp"
# include "program-state.hpp"

namespace po = boost::program_options;

class Parser
{
public:
    Parser() { }

    void parse_cmd_options(int argc, char **argv);

    State *get_initial_state();
    const State *get_final_state();

private:
    std::vector<std::string> possible_solution_patterns {
        "snail", "classic", "first-zero"
    };
    std::vector<std::string> possible_algorithm_types {
        "UCS+GREEDY", "UCS", "GREEDY"
    };
    std::vector<std::string> possible_heuristics {
        "hamming", "manhattan", "linear-conflicts"
    };
    std::vector<std::string> possible_algorithms {
        "A*", "IDA*"
    };

    State *from_random(int64_t n);
    State *from_lines(std::vector<std::string> &lines);
    static bool gen_snail_final_state(uint64_t size, std::vector<int64_t> &out, uint64_t &final_position);
};

#endif
