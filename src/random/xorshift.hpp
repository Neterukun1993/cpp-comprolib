#pragma once

uint64_t rand64() {
    static uint64_t x = 88172645463325252ULL;
    x = x ^ (x << 7);
    return x = x ^ (x >> 9);
}

double rand_p() { return rand64() * (1.0 / UINT64_MAX); }
