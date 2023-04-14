#include <iostream>

struct Exercise {
    char unit_0;
    bool unit_bool;
    int unit_1;
    double unit_2;
    long double unit_3;

    void print()
    {
        std::cout << unit_0 << unit_1 << unit_2 << unit_3 << unit_bool;
    }
};

int main()
{
    Exercise n_obj;
    std::cout << "Structs have been created successfully";
}
