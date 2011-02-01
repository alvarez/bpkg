/*
 *
 * application: bpkg
 * file: errors.c
 * description: error handling routines
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


void
error_handler (int status)
{
  char mesg [128];

  switch (status)
  {
    case 1:
      strcpy (mesg, "Cannot open the \"/var/log/packages.\" \
          Make sure you have access to this directory and try again.");
      break;
    case 2:
      strcpy (mesg, "Problem encounter reading the \"/var/log/packages\" directory \
          Make sure you have access to this directory and try again.");
      break;
    case 3:
      strcpy (mesg, "Problem encounter reading package files from \"/var/log/packages\" \
          Make sure you have access to this directory and try again.");
      break;
    case 10:
      strcpy (mesg, "Maximum length of allowed request exceeded. Please try again."); 
      break;
    case 11:
      strcpy (mesg, "Problem found with the provided string(s). Please try again."); 
      break;
    case 20:
      strcpy (mesg, "HTTP status unsuccessful. Report if condition continues."); 
      break;
    case 21:
      strcpy (mesg, "Problem while parsing data. Report if condition continues."); 
      break;
    case 22:
      strcpy (mesg, "Cannot retrieve file names. Report if condition continues."); 
      break;
    case 23:
      strcpy (mesg, "Cannot retrieve file names. Report if condition continues."); 
      break;
    default:
      strcpy (mesg, "Problem encountered and cannot continue. Please try again."); 
      break;
  }

  printf ("%s\n", mesg);
}
