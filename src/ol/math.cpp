/*
 * Copyright (C) 2018
 * All rights reserved.
 *
 */

#include "math.h"


std::vector<ol::number_t> ol::math::solveLinearSystem(std::vector<std::vector<number_t> > &mat)
{
	size_t n = mat.size();

	for (size_t i = 0; i < n; i++) {
		// Find max in the i-th column (ignoring i - 1 first rows)
		size_t maxRow = i;
		number_t maxEl = std::abs(mat[i][i]);
		for (size_t r = i + 1; r < n; r++) {
			number_t absValue = std::abs(mat[r][i]);
			if (absValue > maxEl) {
				maxEl = absValue;
				maxRow = r;
			}
		}

		if (maxEl == 0) {
			return std::vector<ol::number_t>(); // matrix is singular
		}

		// Swap max row with i-th (current) row
		auto tmp = mat[maxRow];
		mat[maxRow] = mat[i];
		mat[i] = tmp;

		// Subtract the i-th row to make all the remaining rows 0 in the i-th column
		for (size_t j = i + 1; j < n; j++) {
			number_t coef = -mat[j][i] / mat[i][i];
			for (size_t k = i; k < n + 1; k++) {
				if (i == k) {
					mat[j][k] = 0;
				}
				else {
					mat[j][k] += coef * mat[i][k];
				}
			}
		}
	}

	// Solve Ax=b for upper triangular matrix A (mat)
	std::vector<number_t> x (n);
	for (int l = int(n - 1); l >= 0; l--) {
		x[l] = mat[l][n] / mat[l][l];
		for (int m = int(l - 1); m >= 0; m--) {
			mat[m][n] -= mat[m][l] * x[l];
		}
	}
	return x;
}
