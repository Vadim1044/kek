#include "roots.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <search.h>

void test_1() {
  double a = 1;
  double b = 0;
  double c = -1;
  double roots[2];
  int root_count;
  double e = 0;
  solveQuadratic(a, b, c, roots, &root_count, e);

  assert(2 == root_count);
  assert(-1 == roots[0]);
  assert(1 == roots[1]);
}


void test_2() {
  double a = 1;
  double b = 0;
  double c = 0;
  double roots[2];
  int root_count;
  double e = 0;
  solveQuadratic(a, b, c, roots, &root_count, e);

  assert(1 == root_count);
  assert(roots[0] == 0);
}
void test_3() {
  double a = 1;
  double b = 0;
  double c = 1;
  double roots[2];
  int root_count;
  double e = 0;
  solveQuadratic(a, b, c, roots, &root_count, e);

  assert(0 == root_count);
}
void test_4() {
  double a = 1;
  double b = 0;
  double c = -1E-7;
  double roots[2];
  int root_count;
  double e = 1e-8;
  solveQuadratic(a, b, c, roots, &root_count, e);

  assert(2 == root_count);
  assert(fabs(-3E-4 - roots[0]) < 0.0001);
  assert(fabs(3E-4 - roots[1]) < 0.0001);
}
void test_5() {
  double a = 1;
  double b = -1E+10;
  double c = -1;
  double roots[2];
  int root_count;
  double e = 1e-11;
  solveQuadratic(a, b, c, roots, &root_count, e);

  assert(2 == root_count);

  assert(fabs(-1E-10 - roots[0]) < e);
  assert(fabs(1E+10 - roots[1]) < e);
}
void test_6() {
  double a = 1;
  double b = 0;
  double c = -1e-8;
  double e = 1e-7;
  double roots[2];
  int root_count;
  solveQuadratic(a, b, c, roots, &root_count, e);
  assert(1 == root_count);
  assert(fabs(0 - roots[0]) < e);
}

int main() {
  test_1(); //все тесты
  test_2();
  test_3();
  test_4();
  test_5();
  test_6();
  return 0;
}