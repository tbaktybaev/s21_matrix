#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int response = SUCCESS;
  if (s21_check_matrix(*A) || s21_check_matrix(*B)) response = FAILURE;
  if (A->columns != B->columns || A->rows != B->rows)
    response = CALCULATION_ERROR;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 0.000001) {
        response = FAILURE;
        break;
      }
    }
    return response;
  }