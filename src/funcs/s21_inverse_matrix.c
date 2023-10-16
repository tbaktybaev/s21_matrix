#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int response = OK;
  if (s21_check_matrix(*A)) response = INCORRECT_MATRIX;
  result->matrix = NULL;
  result->rows = 0;
  result->columns = 0;
  double det;
  s21_determinant(A, &det);
  if (A->columns != A->rows || det == 0) response = CALCULATION_ERROR;
  s21_calc_complements(A, result);
  matrix_t transponsed;
  s21_transpose(result, &transponsed);
  s21_remove_matrix(result);
  s21_mult_number(&transponsed, 1 / det, result);
  s21_remove_matrix(&transponsed);
  return response;
}