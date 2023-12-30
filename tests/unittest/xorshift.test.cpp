#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../../src/template/template.hpp"
#include "../../src/random/xorshift.hpp"

int main() {
    std::vector<uint64_t> sample = { 11373782495151020392, 8505512047393832734, 8278699350803616934, 220332960558298757, 9524873121654605887 };
    for (auto expected : sample) {
        assert(expected == rand64());
    }

    std::cout << "Hello World" << std::endl;
}
