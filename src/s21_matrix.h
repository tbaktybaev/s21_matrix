#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

#define SUCCESS 1
#define FAILURE 0
#define EPSILON 1e-7

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);     // done
void s21_remove_matrix(matrix_t *A);                                // done
int s21_eq_matrix(matrix_t *A, matrix_t *B);                        // done
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);     // done
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);     // done
int s21_mult_number(matrix_t *A, double number, matrix_t *result);  // done
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);    // done
int s21_transpose(matrix_t *A, matrix_t *result);                   // done
int s21_calc_complements(matrix_t *A, matrix_t *result);            // done
int s21_determinant(matrix_t *A, double *result);                   // done
int s21_inverse_matrix(matrix_t *A, matrix_t *result);              // done

int s21_check_matrix(matrix_t A);
void s21_remove_row_column(matrix_t *A, int row, int col, matrix_t *minor);
double s21_determinant_recursive(matrix_t *A);
#endif
