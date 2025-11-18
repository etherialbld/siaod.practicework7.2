#include "App.h"

int main()
{
    App app;

    /*std::vector < std::vector <int> > graph = { {0, 2, 0, 6, 0},
                                                {2, 0, 3, 8, 5},
                                                {0, 3, 0, 0, 7},
                                                {6, 8, 0, 0, 9},
                                                {0, 5, 7, 9, 0} };*/

    app.primsAlgorithm(app.graphInit());
}
