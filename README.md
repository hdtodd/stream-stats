# stream-stats
### Compute basic statistics from an indeterminate stream of data (C and Python versions)

The usual method for computing the standard deviation of a list of numbers is to compute the mean and then sum the squares of the deviations of the individual values from that mean.  That requires storing the list of values.  If the length of the list is very long, or if it is a stream of data of indeterminate length, that approach does not work well.  The procedures here do not require storage of the list of values.

## Method

The algorithm used in the procedures here uses an interative method on the stream of data and does not require storing the individual values.

For a stream of data, these procedures compute:
* the count of number of values,
* the mean of that list of values,
* the standard deviation of those values from the mean,
* the minimum value in the stream, and
* the maximum value in the stream.

The C library uses a `struct` to store the basic statistics (the `struct` is defined in `stats.h`) and a set of functions to create and initialize the struct, append data from the stream, and return the basic statistics.

The Python library uses a `class` to provide the same functionality.

This distribution includes demonstration programs that show how to use the libraries and validate their correct functioning.

## Author
David Todd, hdtodd@gmail.com, 2022.05.22
