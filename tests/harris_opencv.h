#ifndef HARRIS_OPENCV
#define HARRIS_OPENCV

#include <vector>


using namespace std;

/**
  *
  * Main function for computing Harris corners with OpenCV
  *
**/
  
void opencv_harris(
  float *I,        // input image
  std::vector<harris_corner> &corners, // output selected corners
  float k,         // Harris constant for the ....function
  float sigma_d,   // standard deviation for smoothing (image denoising)    
  float sigma_i,   // standard deviation for smoothing (pixel neighbourhood)
  float Th,        // threshold for eliminating low values
  int   strategy,  // strategy for the output corners
  int   cells,     // number of regions in the image for distributed output
  int   Nselect,   // number of output corners
  int   precision, // type of subpixel precision approximation
  int   nx,        // number of columns of the image
  int   ny,        // number of rows of the image
  int   verbose    // activate verbose mode
);

#endif
