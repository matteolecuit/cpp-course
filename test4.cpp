void testStack() {
  int i = 3;
}

void testHeap() {
  int * j = new int();
  *j = 3;
}

int main() {
  testStack();
  testHeap();
  return 0;
}