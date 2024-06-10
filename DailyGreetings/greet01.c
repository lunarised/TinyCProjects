#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  time_t now;
  struct tm *clock;
  int hour;
  char timeString[64];

  time(&now);

  clock = localtime(&now);
  hour = clock->tm_hour;
  int specialCase = 0;
  if (hour == 0)
  {
    specialCase = 1;
    printf("Thinking about bed soon");
  }
  else if (hour == 1)
  {
    specialCase = 1;
    printf("Burning the midnight oil");
  }
  else if (hour == 2)
  {
    specialCase = 1;
    printf("Working late");
  }
  else if (hour == 3)
  {
    specialCase = 1;
    printf("Still awake");
  }

  if (!specialCase)
  {
    printf("Good ");
    if (hour < 12)
    {
      printf("morning");
    }
    else if (hour < 17)
    {
      printf("afternoon");
    }
    else
    {
      printf("evening");
    }
  }

  if (argc > 1)
  {
    printf(", %s", argv[1]);
  }
  if (specialCase)
  {
    putchar('?');
  }
  putchar('\n');

  strftime(timeString, 64, "Today is %A, %B %d, %Y%nIt is %r%n", clock);
  printf("%s", timeString);
  return EXIT_SUCCESS;
}
