#include "s21_matrix.h"

int s21_check_matrix(matrix_t A) {
  int result = 1;
  if (A.rows > 0 || (A.columns > 0 && A.matrix)) result = 0;
  return result;
}

void s21_remove_row_column(matrix_t *A, int row, int col, matrix_t *minor) {
  int minor_row = 0, minor_col = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) continue;
    minor_col = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == col) continue;
      minor->matrix[minor_row][minor_col] = A->matrix[i][j];
      minor_col++;
    }
    minor_row++;
  }
}
