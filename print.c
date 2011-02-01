/*
 *
 * application: bpkg
 * file: print.c
 * description: handles all printing-related code
 * author: alex alvarez
 * email: alex.alvarez@xbasics.com
 * license: gnu public license 2 (gpl2)
 * (http://www.gnu.org/licenses/gpl-2.0.txt)
 *
 * */


#ifndef BPKG_H
#define BPKG_H
#include "bpkg.h"
#endif


int
print_packages (int action, struct local_struct *local, char *rexp)
{
  struct dirent *entry;
  regex_t reg;

  /* Setting up the regular expression, as needed */
  if (action > 1)
  {
    /* Verifying max string size. Oh, you kids with your games! */
    if (strlen (rexp) > 128)
      return (10);

    /* Compiling the received regex string */
    if (regcomp (&reg, rexp, REG_ICASE) != 0)
      return (11);
  }

  /* Iterating through the directory entries (aka installed packages) */
  int x;
  for (x = 0; x < local->count; x++)
  {
    /* Printing complete, installed package list */
    if (action == 1)
    {
      printf ("%s\n", local->data [x]);
    }
    else if (action > 1)  /* Printing package list based on input strings */
    {
      if (regexec (&reg, local->data [x], 0, NULL, 0) != 0)
        break; /* Nothing to do  */

      /* Printing all packages matching regex */
      if (action == 2)
      {
        printf ("%s\n", local->data [x]);
      }
      else if (action == 3)
      {
return;
      }
    }
    else
      break; /* Otherwise, do nothing. */
  }

  /* Freeing the buffer */
  if (action > 1)
    regfree (&reg);

  return (0);
}

