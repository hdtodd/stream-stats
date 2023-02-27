/* test-stats.c
   A program to test and validate an interative method to
   calculate basic statistics of a stream of (double) values.
   Using this iterative method, the values in the list are
   not stored in memory but are processed individually
   into the mean and std dev as they arrive from the data stream.

   Basic statistics of the series of values includes:
   count of number of values, mean, standard deviation, minimum value
   in the stream, and maximum value in the stream.

   Written by hdtodd@gmail.com, 2022.05.22
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stats.h"

double x[] = {20,10, 5,19, 35,60,15,43,23, 8};
double y[] = {18,19,20,-21,22,23,24,25,26,27};

void main(void) {

  double avgx=0.0, avgy=0.0, stdx=0.0, stdy=0.0, minx=0.0, miny=0.0, maxx=0.0, maxy=0.0;
  int i, j, lenx, leny;
  bstats *xstats, *ystats;
  
  lenx = sizeof(x)/sizeof(x[0]);
  leny = sizeof(y)/sizeof(y[0]);
  
  for (i=0; i<lenx; i++) avgx += x[i];
  avgx /= (double)lenx;
  for (j=0; j<leny; j++) avgy += y[j];
  avgy /= (double)leny;
  for (i=0; i< lenx; i++) stdx += (x[i]-avgx)*(x[i]-avgx);
  stdx = sqrt(stdx/(double)(lenx-1));
  for (j=0; j< leny; j++) stdy += (y[j]-avgy)*(y[j]-avgy);
  stdy = sqrt(stdy/(double)(leny-1));

  xstats = stats_new();
  ystats = stats_new();
  for (i=0; i<lenx; i++) stats_append(x[i], xstats);
  for (j=0; j<leny; j++) stats_append(y[j], ystats);

  stats_get(xstats);
  stats_get(ystats);
  printf("X stats\nIteration: ");
  stats_print(xstats);
  printf("Std calc:              avg = %lf  std dev = %lf\n", avgx, stdx);

  printf("Y stats\nIteration: ");
  stats_print(ystats);
  printf("Std calc:              avg = %lf  std dev = %lf\n", avgy, stdy);

}
