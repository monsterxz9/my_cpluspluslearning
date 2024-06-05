//
// Created by Mark Tween on 2024/1/23.
//
//Extremely worse code is like this.
#include <iostream>
#include <string>


class Entity {
public:
    void PrintEntity(const Entity &e) {
        // Print
    }

    int x, y;

    Entity(int x, int y) {
        this->x = x;
        this->y = y;
        Entity &e = *this;
        PrintEntity(*this);
        delete this;
    }

    int GetX() const {
        const Entity &e = *this;
    }
};

std::ostream &operator<<(std::ostream &stream, const Entity &other) {
    stream << other.x << "," << other.y;
    return stream;
}

int main() {
    std::cout << __cplusplus << std::endl;
    Entity *entity;
    std::cout << entity << std::endl;
    std::cin.get();
}