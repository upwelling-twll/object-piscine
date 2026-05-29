#include "Graph.hpp"

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        int fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
            std::cerr << "Error opening file: " << argv[1] << std::endl;
            return 1;
        }
        else
        {
            try 
            {
            Graph graph(Vector2{5, 5});
            graph.readPointsFromFile(fd);
            graph.draw();
            }
            catch (const char* msg)
            {
                std::cerr << "Error: " << msg << std::endl;
                close(fd);
                return 1;
            }
        }
    }
    else
    {
        try 
        {
            Graph graph(Vector2{5, 5});
            graph.addLine(Line(Vector2{0, 0}, Vector2{0, 3}));
            graph.addLine(Line(Vector2{0, 3}, Vector2{3, 3}));
            graph.addLine(Line(Vector2{3, 3}, Vector2{0, 0}));
            graph.addPoint(Vector2{1, 2});
            // graph.addPoint(Vector2{2, 2});
            // graph.addPoint(Vector2{4, 2});
            // graph.addPoint(Vector2{2, 4});
            graph.draw();
        }
        catch (const char* msg)
        {
            std::cerr << "Error: " << msg << std::endl;
        }
    }
    return 0;
}