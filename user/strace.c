#include "kernel/types.h"
#include "kernel/param.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
  int i;
  char *newargv[64];

  if (argc < 3)
  {
    fprintf(2, "Invalid number of Arguments");
    exit(1);
  }

  if (trace(atoi(argv[1])) < 0)
  {
    fprintf(2, "Incorrect Mask value");
    exit(1);
  }
  for (i = 2; i < argc && i < MAXARG; i++)
  {
    newargv[i - 2] = argv[i];
  }
  exec(newargv[0], newargv);
  exit(0);
}