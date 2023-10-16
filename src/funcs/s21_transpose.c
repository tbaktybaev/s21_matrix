#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int response = OK;
  if (s21_check_matrix(*A)) response = INCORRECT_MATRIX;
  s21_create_matrix(A->columns, A->rows, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->rows; j++) result->matrix[j][i] = A->matrix[i][j];
  }
  return response;
}
