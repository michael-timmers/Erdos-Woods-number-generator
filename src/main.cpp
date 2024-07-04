#include <iostream>
#include <vector>
#include <algorithm>

using Storage_T = std::vector<int>;

const int SEARCH_LIMIT = 100000;
const int LENGTH_LIMIT = 20;

// from https://stackoverflow.com/questions/23287/algorithm-to-find-largest-prime-factor-of-a-number
void getPrimeFactors(int n, Storage_T& factors) {
    // std::cout << "factors:\n";

    for (int d = 2; n > 1;) {
        while (n % d == 0) {
            factors.push_back(d);
            n /= d;
            // std::cout << " " << i;
        }
        d++;
        if (d * d > n) {
            if (n > 1) {
                factors.push_back(n);
                break;
            }
        }
    }
    // std::cout << "\n";
}

bool hasIntersection(Storage_T set1, Storage_T set2) {
    Storage_T intersection;
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(intersection, intersection.begin()));
    return intersection.size() != 0;
}

bool doesRangeShareFactors(int currentStart, int currentLength, Storage_T factors) {
    for (int i = 1; i <= currentLength; i++) {
        // std::cout << "i" << currentStart + i << " ";
        Storage_T currentFactors;
        getPrimeFactors(currentStart + i, currentFactors);
        if (!hasIntersection(factors, currentFactors)) {
            // std::cout << "no intersection:" << currentStart + i << "\n";
            return false;
        }
    }
    return true;
}

int main() {
    Storage_T theNumbers;
    for (int start = 2; start < SEARCH_LIMIT; start++) {
        // std::cout << "s" << start << " ";
        Storage_T startFactors;
        getPrimeFactors(start, startFactors);
        for (int length = 2; length < LENGTH_LIMIT; length++) {
            // std::cout << start + length << " ";
            Storage_T endFactors;
            getPrimeFactors(start + length, endFactors);
            Storage_T factors;
            std::set_union(startFactors.begin(), startFactors.end(), endFactors.begin(), endFactors.end(), std::inserter(factors, factors.begin()));

            if (doesRangeShareFactors(start, length, factors)) {
                std::cout << "start:" << start << " length:" << length << "\n";
                theNumbers.push_back(length);
            }
        }
        // std::cout << std::endl;
    }

    std::cout << "result:\n";
    for (const int& num : theNumbers) {
        std::cout << num << ",";
    }

    return 0;
}