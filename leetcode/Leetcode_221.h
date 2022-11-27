#include <string>
#include <vector>

struct Leetcode_221 {
  /**
   * @brief brute force algorithm
   *
   * @param matrix
   * @return int
   */
  int maximalSquare(const std::vector<std::vector<char>> &matrix) {
    if (matrix.empty()) return 0;
    if (matrix.size() == 1 || matrix[0].size() == 1) {
      for (auto &i : matrix)
        for (auto &j : i)
          if (j == '1') return 1;

      return 0;
    }

    int row = matrix.size();
    int column = matrix[0].size();
    int maxlen = (row < column) ? row : column;
    std::vector<std::vector<std::vector<int>>> *aux_matrix =
        new std::vector<std::vector<std::vector<int>>>(
            row, std::vector<std::vector<int>>(
                     column, std::vector<int>(maxlen + 1, 0)));

    int maxSquarelen = 0;
    for (int i = 0; i < row; i++)
      for (int j = 0; j < column; j++)
        if (matrix[i][j] == '1') {
          (*aux_matrix)[i][j][1] = 1;
          maxSquarelen = 1;
        }

    if (maxSquarelen == 0) return 0;

    for (int i = 0; i < row - 1; i++)
      for (int j = 0; j < column - 1; j++) {
        int res_maxlen = row - i;
        res_maxlen = res_maxlen < (column - j) ? res_maxlen : (column - j);
        for (int L = 2; L <= res_maxlen; L++) {
          if (((*aux_matrix)[i][j][L] = (*aux_matrix)[i][j][L - 1]) == 1) {
            for (int k = 0; k <= L - 1; k++) {
              if ((matrix[i + L - 1][j + k] == '0') ||
                  (matrix[i + k][j + L - 1] == '0')) {
                (*aux_matrix)[i][j][L] = 0;
                break;
              }
            }
            if ((*aux_matrix)[i][j][L] == 1)
              maxSquarelen = (maxSquarelen < L) ? L : maxSquarelen;
          }
        }
        if (maxSquarelen == maxlen) return maxlen * maxlen;
      }

    return maxSquarelen * maxSquarelen;
  }
};

struct Leetcode_221_dynamicprogramming {
  int maximalSquare(const std::vector<std::vector<char>> &matrix) {
    if (matrix.empty()) return 0;
    if (matrix.size() == 1 || matrix[0].size() == 1) {
      for (auto &i : matrix)
        for (auto &j : i)
          if (j == '1') return 1;

      return 0;
    }

    int maxsquarelen = 0;
    std::vector<int> *msql = new std::vector<int>(matrix[0].size(), 0);
    std::vector<int> &r_msql = *msql;
    for (int i = 0; i < r_msql.size(); i++) {
      r_msql[i] = (matrix[0][i] == '1') ? 1 : 0;
      maxsquarelen = (maxsquarelen > r_msql[i]) ? maxsquarelen : r_msql[i];
    }

    for (int i = 1; i < matrix.size(); i++) {
      int left = (matrix[i][0] == '1') ? 1 : 0;
      maxsquarelen = (maxsquarelen > left) ? maxsquarelen : left;
      for (int j = 1; j < matrix[0].size(); j++) {
        if (matrix[i][j] == '0')
          r_msql[j - 1] = left = 0;
        else {
          r_msql[j - 1] =
              (r_msql[j] < r_msql[j - 1]) ? r_msql[j] : r_msql[j - 1];
          r_msql[j - 1] = (r_msql[j - 1] < left) ? r_msql[j - 1] : left;
          r_msql[j - 1] = r_msql[j - 1] + 1;
          left = r_msql[j - 1];
          maxsquarelen = (maxsquarelen > left) ? maxsquarelen : left;
        }
      }
      for (int k = matrix[0].size() - 1; k > 0; k--) r_msql[k] = r_msql[k - 1];
      r_msql[0] = (matrix[i][0] == '1') ? 1 : 0;
    }
    return maxsquarelen * maxsquarelen;
  }
};
