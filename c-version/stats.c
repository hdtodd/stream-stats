/* stats.c -- function to accumulate basic statistics from a
   stream of data using iteration on the stream.

   Using this iterative method, the values in the list are
   not stored in memory but are processed individually
   into the mean and std dev as they arrive from the data stream.

   Basic statistics of the series of values includes:
   count of number of values, mean, standard deviation, minimum value
   in the stream, and maximum value in the stream.

   Usage:
   The basic statistics are accumulated in a data structure, bstats,
   which is defined in the .h file.

   Allocate a pointer for the structure with "bstats *xstats", for example.
   Create the structure to hold the basic statistics with
     xstats = stats_new()
   Iteratively, add new values from the stream to the basic stats with
     stats_append(xvalue, xstats)
   where (double) xvalue is the next value in the stream to ba included.
   WHEN FINISHED (as it disrupts the standard deviation calculation),
   retrieve the basic statistics with 
     stats_get(xstats)
   after which:
     xstats->count    is the number of values processed from the stream
     xstats->mean     is the mean value of the stream
     xstats->std2     is the standard deviation (NOT its square)
     xstats->min      is the smallest value in the stream
     xstats->max      is the largest value in the stream
   or  use
     stats_print(xstats)
   to print the accumulated statistics after performing the "stats_get".

   CAUTION NOTE:
   Note that the routines below accumulate the SQUARE of the
   standard deviation rather than invoking the sqrt() function
   for each new data point.  Use stats_get() to retrieve the
   data when the stream has closed: it converts the stddev**2
   to stddev in the bstats structure.

   Written by hdtodd@gmail.com, 2022.05.22
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "stats.h"

bstats *stats_new(void) {
  bstats *data;
  
  data = (bstats *) malloc(sizeof(bstats));
  if (data == NULL) {
      fprintf(stderr, "Unable to allocate space for a stats block!");
      exit(EXIT_FAILURE);
  };

  data->count = 0;
  data->mean  = 0.0e0;
  data->std2  = 0.0e0;
  data->min   = +INFINITY;
  data->max   = -INFINITY;
  return(data);
};

void stats_print(bstats *data) {
  printf("Count = %d, avg = %lf, std dev = %lf, min = %lf, max = %lf\n",
	 data->count, data->mean, data->std2, data->min, data->max);
  return;
};

bstats *stats_get(bstats* data) {
  data->std2 = sqrt(data->std2);
  return(data);
};

void stats_append(double x, bstats *self) {
  self->count += 1;
  self->mean   = ( (double)(self->count - 1) * self->mean + x)/(double)self->count;
  self->std2   = self->count<2 ? 0.0 :
    ( (self->count-2)*self->std2 +
      (double)(self->count)*(self->mean-x)*(self->mean-x)/(double)(self->count - 1) )/(double)(self->count-1);
  self->min    = x<self->min ? x : self->min;
  self->max    = x>self->max ? x : self->max;

  return;
};

  
