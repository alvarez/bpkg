/*
 *
 * application: bpkg
 * file: main.c
 * description: main source file
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

#ifndef PACKAGES_H
#define PACKAGES_H
#include "packages.h"
#endif

#ifndef CONTENTS_H
#define CONTENTS_H
#include "contents.h"
#endif

#ifndef PRINT_H
#define PRINT_H
#include "print.h"
#endif

#ifndef ERRORS_H
#define ERRORS_H
#include "errors.h"
#endif


int
main (int argc, char *argv [])
{
  /* Function returned status */
  int status;

  /* Local installed packages */
  struct local_struct local = {0};


  /* Step 1: Getting package names from the main package directory: /var/log/packages */
  if ((status = get_local_packages (&local)) != 0)
  {
    error_handler (status);
    return (status);
  }


  /* Step 2: Determining and completing the particular action requested from the user */

  if (argc == 1)  /* Listing all package names */
  {
    print_packages (1, &local, (void *) 0);
  }
  else if (strncmp (argv [1], "-l", 2) == 0)  /* Listing package(s) (info) contents */
  {
    if (argc == 2)
      get_contents (&local);
    else
      get_contents (&local); 
  }
  else if (strncmp (argv [1], "-d", 2) == 0)  /* Listing package(s) (info) description */
  {
    printf ("got: -d\n");
  }
  else if (strncmp (argv [1], "-f", 2) == 0)  /* Listing package(s) (info) file list */
  {
    printf ("got: -f\n");
  }
  else /* If one/more arguments were provided */
  {
    //////status = print_packages (2, &local, argv [1]);

    int count = 1;

    /* Iterating through the provided strings */
    for (; count < argc; count++)
    {
      /* Showing complete name of packages matching the provided strings */
      if ((status = print_packages (2, &local, argv [count])) != 0)
        break;
    }
  }


  /* Exiting if everything had gone well */
  if (status == 0)
    exit (EXIT_SUCCESS);

  /* Showing error status and exiting accordingly */
  error_handler (status);
  exit (EXIT_FAILURE);
}

