#pragma once

template <typename T>
struct Edge {
    int from, to;
    T cost;
    int id;

    Edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}
};

template <typename T>
struct Graph {
    bool is_directed;
    int N, M;
    std::vector<std::vector<Edge<T>>> adjacencies;

    Graph(bool is_directed = true) : is_directed(is_directed), N(0), M(0), adjacencies(0) {}

    Graph(int N, bool is_directed = true) : is_directed(is_directed), N(N), M(0), adjacencies(N) {}

    inline const std::vector<Edge<T>> &operator[] (int k ) const {return adjacencies[k]; }

    void init(int N_) {
        N = N_;
        M = 0;
        adjacencies.clear();
        adjacencies.resize(N);
    }

    int size() const { return N; }

    void add_edge(int from, int to, T cost, int id) {
        assert(0 <= from && from < N);
        assert(0 <= to && to < N);
        auto e = Edge<T>(from, to, cost, id);

        adjacencies[from].emplace_back(e);
        if (!is_directed) {
            auto e2 = Edge<T>(to, from, cost, id);
            adjacencies[to].emplace_back(e2);
        }

        M++;
    }
};
