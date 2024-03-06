#include <iostream>
#include <string>

class Entity
{
public:
  int x, y;

  Entity(int x, int y) : x(x), y(y)
  {
    std::cout << "Entity has been created" << std::endl;
  }

  ~Entity() { std::cout << "Entity has been destroyed" << std::endl; }
};

int main()
{
  std::cout << __cplusplus << std::endl;

  // You need to allocate memory for the Entity object before using it
  Entity *e = new Entity(1, 1);

  // Accessing the members through a pointer requires the '->' operator
  e->x = 2;
  e->y = 2;

  // No need to explicitly call the destructor in most cases
  // The object will be automatically destroyed when it goes out of scope
  // delete e;  // If you allocated memory with 'new', you should use 'delete'

  std::cin.get();
  // getchar();  // You can use either cin.get() or getchar() to pause the
  // console

  putchar(getchar());
  // If you use 'new', make sure to delete the allocated memory before exiting
  delete e;

  return 0;
}
