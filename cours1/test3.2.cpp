class Entity {
  public:
    int a = 0;
    int b = 0;
    float c = 1.0;
    Entity(int x, int y) {
      this->a = x;
      this->b = y;
    }
};

void testFunction(Entity e) {
  e.a = 42;
}

int main() {
  Entity e1(5, 6);
  testFunction(e1);
}