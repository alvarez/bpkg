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


struct contents_struct
{
  int num_lines;
  char **data;
};


int
get_contents (struct local_struct *);

