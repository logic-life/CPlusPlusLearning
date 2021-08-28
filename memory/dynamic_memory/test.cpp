#include "shape.h"

int main(int argc, char *argv[])
{
    Shape *triangleShape = nullptr;
    if (!(triangleShape = new Shape[6]))
    {
        std::cout << "out Of memory" << std::endl;
        exit(1);
    }
    delete[] triangleShape;
    return 0;
}