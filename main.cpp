#include <iostream>

struct vector2 {
    float x, y;

    vector2(float x, float y) : x(x), y(y) {}

    [[nodiscard]] vector2 add(const vector2 &other) const { return *this + other; }

    [[nodiscard]] vector2 multiply(const vector2 &other) const {
        return {x * other.x, y * other.y};
    }

    vector2 operator+(const vector2 &other) const {
        return {x + other.x, y + other.y};
    }

    vector2 operator*(const vector2 &other) const { return multiply(other); }

    bool operator==(const vector2 &other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const vector2 &other) const { return !(*this == other); }
};

std::ostream &operator<<(std::ostream &stream, const vector2 &other) {
    stream << other.x << "," << other.y;
    return stream;
}

int main() {
    vector2 position(4.0f, 4.0f);
    vector2 speed(0.5f, 1.5f);
    vector2 PowerUp(1.1f, 1.1f);
    vector2 result1 = position.add(speed.multiply(PowerUp));
    vector2 result2 = position + speed * PowerUp;
    char b = 2;
    [[maybe_unused]] char *a = &b;
    std::cout << result2 << "\n" << result1 << std::endl;
    std::cout << __cplusplus << std::endl;
    std::cout << sizeof(a) << std::endl;
    std::cin.get();
}