#include "common.hpp"
#include "primes.hpp"
#include "validate.hpp"
#include "io.hpp"

std::vector<Storage_T> allFactors(SEARCH_LIMIT);
// Storage_T primes;

void generateAllFactors() {
    for (int i = 0; i < SEARCH_LIMIT; i++) {
        allFactors[i] = primes::getPrimeFactors(i);
    }
}

int main() {
    Storage_T sequence, boundsFactors;

    generateAllFactors();

    for (int start = SEARCH_BEGIN; start < SEARCH_LIMIT; start++) {
        // std::cout << "s" << start << "\n";
        for (int length = 2; length < LENGTH_LIMIT; length++) {
            // std::cout << start + length << " ";
            boundsFactors.reserve(allFactors[start].size() + allFactors[start + length].size());
            boundsFactors.insert(boundsFactors.end(), allFactors[start].begin(), allFactors[start].end());
            boundsFactors.insert(boundsFactors.end(), allFactors[start + length].begin(), allFactors[start + length].end());
            // io:: displayVector(boundsFactors, "bounds");

            if (validate::doesRangeShareFactors(start, length, boundsFactors, allFactors)) {
                std::cout << "start:" << start << " length:" << length << "\n";
                if (std::find(sequence.begin(), sequence.end(), length) == sequence.end())
                    sequence.push_back(length);
            }
            boundsFactors.clear();
        }
        // std::cout << std::endl;
    }

    io::displayVector(sequence, "Sequence");

    return 0;
}