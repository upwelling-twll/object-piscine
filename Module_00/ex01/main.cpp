#include "Graph.hpp"

int main()
{
    try 
    {
        Graph graph(Vector2{5, 5});
        graph.addLine(Line(Vector2{0, 0}, Vector2{0, 3}));
        graph.addLine(Line(Vector2{0, 3}, Vector2{3, 3}));
        graph.addLine(Line(Vector2{3, 3}, Vector2{0, 0}));

        // graph.addPoint(Vector2{0, 0});
        // graph.addPoint(Vector2{2, 2});
        // graph.addPoint(Vector2{4, 2});
        // graph.addPoint(Vector2{2, 4});
        graph.drawLines();
    }
    catch (const char* msg)
    {
        std::cerr << "Error: " << msg << std::endl;
    }
    return 0;
}