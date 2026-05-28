#include "Graph.hpp"

int main()
{
    Graph graph(Vector2{5, 5});
    graph.addPoint(Vector2{0, 0});
    graph.addPoint(Vector2{2, 2});
    graph.addPoint(Vector2{4, 2});
    graph.addPoint(Vector2{2, 4});

    // graph.addPoint(Vector2{1, 3});
    // graph.addPoint(Vector2{2, 2});
    // graph.addPoint(Vector2{3, 4});
    // graph.addPoint(Vector2{1, 1});
    // graph.addPoint(Vector2{0, 2});
    // graph.addPoint(Vector2{2, 1});

    graph.draw();
    return 0;
}