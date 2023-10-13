#include "s21_matrix.h"

double s21_determinant_recursive(matrix_t *A) {
  if (A->rows == 1) {
    return A->matrix[0][0];
  }
  if (A->rows == 2) {
    return A->matrix[0][0] * A->matrix[1][1] -
           A->matrix[0][1] * A->matrix[1][0];
  }
  double det = 0.0;
  for (int j = 0; j < A->columns; j++) {
    matrix_t minor;
    s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
    s21_remove_row_column(A, 0, j, &minor);
    double minor_det = s21_determinant_recursive(&minor);
    det += pow(-1, j) * A->matrix[0][j] * minor_det;
    s21_remove_matrix(&minor);
  }
  return det;
}

int s21_determinant(matrix_t *A, double *result) {
  if (A->rows != A->columns) {
    return INCORRECT_MATRIX;
  }

  *result = s21_determinant_recursive(A);

  return OK;
}