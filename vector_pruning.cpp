/**
 * Compile and run:
 * g++ -std=c++14 vector_pruning.cpp -o vector_pruning.out && ./vector_pruning.out
 * 
 * This snippet sorts a vector of x and y coordinates by x values and
 * remove data points with similar x values. This is a useful preprocessing
 * for modules such as Cubic Spline Interpolation:
 * http://kluge.in-chemnitz.de/opensource/spline/
 * since one of the requirements of data points used in spline library is
 * `x[i-1] < x[i]`.
 */

#include <algorithm>
#include <vector>
#include <iostream>
#include "lib/spline.h"

using namespace std;

template <typename T>
vector<size_t> SortIndexes(const vector<T> &v) {

  // initialize original index locations
  vector<size_t> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});

  return idx;
}

/**
 * Sort by x and remove similar points.
 */
void PruneWaypoint(vector<double> *wp_x, vector<double> *wp_y) {
  vector<double> wp_x_sorted;
  vector<double> wp_y_sorted;

  for (auto i: SortIndexes((*wp_x))) {
    wp_x_sorted.push_back((*wp_x)[i]);
    wp_y_sorted.push_back((*wp_y)[i]);
  }
  (*wp_x) = wp_x_sorted;
  (*wp_y) = wp_y_sorted;
}

int main() {
  vector<double> x = {0.1, 0.2, 0.5, 0.4, 0.5};
  vector<double> y = {0.2, 0.4, 1.0, 0.8, 0.7};
  tk::spline s;
  // This code produces error:
  // Assertion `m_x[i]<m_x[i+1]' failed.
  // s.set_points(x, y);

  // But this one works:
  PruneWaypoint(&x, &y);
  s.set_points(x, y);
}
