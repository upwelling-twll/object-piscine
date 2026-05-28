#include "Graph.hpp"

int main()
{
    try 
    {
        Graph graph(Vector2{5, 5});
        graph.addPoint(Vector2{0, 0});
        graph.addPoint(Vector2{2, 2});
        graph.addPoint(Vector2{4, 2});
        graph.addPoint(Vector2{2, 4});
        graph.draw();
    }
    catch (const char* msg)
    {
        std::cerr << "Error: " << msg << std::endl;
    }
    return 0;
}