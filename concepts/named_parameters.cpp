#include <iostream>

struct Person {
    const char* name;
    unsigned int age;
};

#define get_person_age(...) _get_person_age((struct Person){__VA_ARGS__})
int _get_person_age(struct Person new_person) { return new_person.age; }

#define get_person_name(...) _get_person_name((struct Person){__VA_ARGS__})
const char* _get_person_name(struct Person new_person) {
    return new_person.name;
}

int main(void) {
    int person_age = get_person_age(.name = "Prince", .age = 18, );
    const char* person_name = get_person_name(.name = "Kwabena", .age = 23, );

    std::cout << person_name << person_age;
    std::cout << person_age * 12;

    return 0;
}