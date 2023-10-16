#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int response = OK;
  if (s21_check_matrix(*A)) response = INCORRECT_MATRIX;

  result->matrix = NULL;
  result->rows = 0;
  result->columns = 0;

  if (A->columns != A->rows) response = CALCULATION_ERROR;
  s21_create_matrix(A->rows, A->columns, &result);
  if (A->rows == 1)
    result->matrix[0][0] = 1;
  else
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor;
        s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        s21_remove_row_column(A, i, j, &minor);
        result->matrix[i][j] =
            pow(-1, i + j) * s21_determinant_recursive(&minor);
        s21_remove_matrix(&minor);
      }
  return response;
}