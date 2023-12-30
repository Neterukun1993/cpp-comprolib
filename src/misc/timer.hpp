#include <chrono>
using namespace std::chrono;


struct Timer {
    system_clock::time_point start;

    Timer() { reset(); }

    void reset() { start = system_clock::now(); }

    double sec_elapsed() {
        return duration_cast<milliseconds>(system_clock::now() - start).count() / 1000.0;
    }
};
