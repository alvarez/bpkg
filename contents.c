/*
 *
 * application: bpkg
 * file: contents.c
 * description: extracts contents from package file
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


/* Reads package file */
int
get_contents (struct local_struct *local)
{
  FILE *pkg_file;
  char str_file [250];
  char *str_line;
  int size_line = 100;
  int counter = 0;

  
  /* Initial memory allocation of str_line */
  str_line = (char *) malloc (size_line + 1);
  
  
   /* Iterating through each package file */
  for (; counter < local->count; counter++)
  {
    /* Putting together the FQPN for each package file */
    strcpy (str_file, PKG_DIR);
    strcat (str_file, local->data [counter]);
   
    /* Opening each package file for reading only */
    pkg_file = fopen (str_file, "r");

    /* Verifying file access */
    if (pkg_file == NULL)
      return (3);

    while (fgets (str_line, size_line, pkg_file) != NULL)
    {
      printf ("%s", str_line);
    }

    /* Closing file descriptor */
    fclose (pkg_file);

    printf ("\n\n");
  }

  return 0;
}

