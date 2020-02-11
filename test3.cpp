void testFunction(int a[60]) {
  a[0] = 32; 
}

int main() {
  int a1[60];
  a1[0] = 1;
  a1[1] = 2;
  a1[2] = 3;
  a1[3] = 4;
  a1[4] = 5;
  testFunction(a1);
}