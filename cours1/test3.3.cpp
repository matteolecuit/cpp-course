class Entity {
  public:
    int a [50];
    Entity(int x) {
      this->a[0] = 1;
      this->a[1] = x;
      this->a[2] = 3;
      this->a[3] = 4;
      this->a[4] = 5;
      this->a[5] = 6;
      this->a[6] = 7;
      this->a[7] = 8;
      this->a[8] = 9;
      this->a[9] = 10;
    }
};

void testFunction(Entity &e) {
  e.a[0] = 300;
}

int main() {
  Entity e1(4);
  testFunction(e1);
}