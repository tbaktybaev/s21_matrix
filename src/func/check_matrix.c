#include <s21_matrix.h>

int s21_check_matrix(matrix_t A) {
  int result = 1;
  if (A.rows > 0 || A.columns > 0 && A.matrix) result = 0;
  return result;
}