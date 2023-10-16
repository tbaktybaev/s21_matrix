#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int response = OK;
  if (s21_check_matrix(*A) || s21_check_matrix(*B)) response = INCORRECT_MATRIX;
  result->matrix = NULL;
  result->columns = 0;
  result->rows = 0;
  if (A->columns != B->rows) response = CALCULATION_ERROR;

  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      for (int k = 0; k < B->rows; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
  return response;
}
