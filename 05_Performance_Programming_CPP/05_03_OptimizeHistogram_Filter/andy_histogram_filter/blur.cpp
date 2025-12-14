#include "headers/blur.h"
#include "headers/zeros.h"

using namespace std;

vector < vector <float> > blur(vector < vector < float> >& grid, float blurring)
// {

// 	// initialize variables
// 	vector < vector <float> > window;
// 	vector < vector <float> > newGrid;
// 	vector <float> row;
// 	vector <float> newRow;

// 	int height;
// 	int width;
// 	float center, corner, adjacent;

// 	height = grid.size();
// 	width = grid[0].size();

// 	// calculate blur factors
// 	center = 1.0 - blurring;
// 	corner = blurring / 12.0;
// 	adjacent = blurring / 6.0;

// 	int i, j;
// 	float val;

// 	// 2D vector reprenting the blur filter
// 	for (i=0; i<3; i++) {
// 		row.clear();
// 		for (j=0; j<3; j++) {
// 			switch (i) {
// 				case 0: 
// 				switch (j) {
// 					case 0: 
// 					val = corner;
// 					break;

// 					case 1: 
// 					val = adjacent;
// 					break;

// 					case 2: 
// 					val = corner;
// 					break;
// 				}
// 				break; 

// 				case 1:
// 				switch (j) {
// 					case 0: 
// 					val = adjacent;
// 					break;

// 					case 1: 
// 					val = center;
// 					break;
					
// 					case 2: 
// 					val = adjacent;
// 					break;
// 				}
// 				break;

// 				case 2:
// 				switch(j) {
// 					case 0: 
// 					val = corner;
// 					break;

// 					case 1: 
// 					val = adjacent;
// 					break;
					
// 					case 2: 
// 					val = corner;
// 					break;
// 				}
// 				break;
// 			}
// 			row.push_back(val);
// 		}
// 		window.push_back(row);
// 	}


// 	// variables for blur calculations
// 	vector <int> DX;
// 	vector <int> DY;

// 	DX.push_back(-1); DX.push_back(0); DX.push_back(1);
// 	DY.push_back(-1); DY.push_back(0); DY.push_back(1);

// 	int dx;
// 	int dy;
// 	int ii;
// 	int jj;
// 	int new_i;
// 	int new_j;
// 	float multiplier;
// 	float newVal;

// 	// initialize new grid to zeros
// 	for (i=0; i<height; i++) {
// 		newRow.clear();
// 		for (j=0; j<width; j++) {
// 			newRow.push_back(0.0);
// 		}
// 		newGrid.push_back(newRow);
// 	}

// 	// blur the grid and store in a new 2D vector
// 	for (i=0; i< height; i++ ) {
// 		for (j=0; j<width; j++ ) {
// 			val = grid[i][j];
// 			newVal = val;
// 			for (ii=0; ii<3; ii++) {
// 				dy = DY[ii];
// 				for (jj=0; jj<3; jj++) {
// 					dx = DX[jj];
// 					new_i = (i + dy + height) % height;
// 					new_j = (j + dx + width) % width;
// 					multiplier = window[ii][jj];
// 					newGrid[new_i][new_j] += newVal * multiplier;
// 				}
// 			}
// 		}
// 	}

// 	return newGrid;
// }

{
  static float GLOBAL_BLURRING = 0.12;

  static float CENTER = 1.0 - GLOBAL_BLURRING;
  static float CORNER = GLOBAL_BLURRING / 12.0;
  static float ADJACENT = GLOBAL_BLURRING / 6.0;

  static vector <int> DX = {-1, 0, 1};
  static vector <int> DY = {-1, 0, 1};

  static vector < vector <float> > GLOBAL_WINDOW = { {CORNER, ADJACENT, CORNER}, {ADJACENT, CENTER, ADJACENT}, {CORNER, ADJACENT, CORNER} };


  vector < vector <float> > newGrid;
  vector <float> row;
  vector <float> newRow;

  int height = grid.size();
  int width = grid[0].size();

  int i, j, ii, jj, new_i, new_j;
  int dx, dy;

  float multiplier;
  float newVal;

  // initialize new grid to zeros
  newGrid = zeros(height, width);

  // original way
  for (i=0; i< height; i++ ) {
    for (j=0; j<width; j++ ) {
      newVal = grid[i][j];
      for (ii=0; ii<3; ii++) {
        dy = DY[ii];
        for (jj=0; jj<3; jj++) {
          dx = DX[jj];
          new_i = (i + dy + height) % height;
          new_j = (j + dx + width) % width;
          multiplier = GLOBAL_WINDOW[ii][jj];
          newGrid[new_i][new_j] += newVal * multiplier;
        }
      }
    }
  }

  return newGrid;
}
