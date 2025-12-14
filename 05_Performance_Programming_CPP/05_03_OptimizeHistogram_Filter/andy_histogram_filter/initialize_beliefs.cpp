#include "headers/initialize_beliefs.h"

using namespace std;

vector< vector <float> > initialize_beliefs(int height, int width) {

  float prob_per_cell = 1.0 / float(height * width);

  vector<float> row;
  vector< vector<float> > newGrid;

  // because the vectors are not of variable length, 
  // it is faster to reserve space in memory for the vectors
  row.reserve(width);
  newGrid.reserve(height);

  // avoiding nested for loops since in this case it is not needed
  // each element in the 2D vector has the exact same value
  for (int i = 0; i < width; i++) {
    row.push_back(prob_per_cell);
  }

  for (int i = 0; i < height; i++) {
    newGrid.push_back(row);
  }

	return newGrid;
}