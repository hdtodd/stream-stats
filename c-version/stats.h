typedef struct {
  int    count;
  double mean;
  double std2;
  double min;
  double max;
  } bstats;

bstats  *stats_new(void);
void    stats_print(bstats *data);
bstats  *stats_get(bstats *data);
void    stats_append(double x, bstats *data);

