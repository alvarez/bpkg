/*
 *
 * application: bpkg
 * file: packages.c
 * description: general multi-use code 
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

#define RE_ALPHA "\\[a-zA-Z\\]\\+";
#define RE_NUM "\\(\\[0-9\\]\\)";


/* Reads and saves content from the main package directory, /var/log/packages/ */
int
get_local_packages (struct local_struct *local)
{
  /* Local directory */
  DIR *pkgdir;

  /* Opening the main Slackware package directory: /var/log/packages */
  if ((pkgdir = opendir (PKG_DIR)) == NULL)
    return (1);

  /* Iterating through the directory entries */
  struct dirent *entry;
  int len = 0;
  local->count = 0;
  local->size = 0;

  while ((entry = readdir (pkgdir)) != NULL)
  {
    /* Only grabbing regular files. No "." and "..", for example. */
    if (entry->d_type != (unsigned char) DT_REG && entry->d_type != (unsigned char) DT_UNKNOWN)
      continue;

    /* Getting the size of the directory entry */
    local->size += strlen (entry->d_name) + 1;

    /* resizing the arrays with one more pointer */
    /*local->data = (char **) realloc (local->data, sizeof (char *) * (x + 1));*/
    local->data = (char **) realloc (local->data, local->size);

    /* Allocating memory and copying entry */
    local->data [local->count] = strdup (entry->d_name);

    ++local->count;
  }

  /* If nothing was read, we need to report it */
  if (local->size == 0)
    return (2);

  return (0);
}


/* Extracting the four parts/components of the package name */
int
get_pkg_parts (char *pkg, char *parts [4])
{

  char tmp [128];
  int pos, part, part_len, ch, len, last;


  /* Making a copy of the original pkg name string */
  strcpy (tmp, pkg);

  /* Getting the length the pkg name string */
  len = strlen (tmp);

  /* Position for last found match going backwards */
  last = 0;

  /* Retrieving parts 1 - 3 of the package name */
  for (ch = 0, part = 3; ch < len && part > 0; ch++)
    {
      pos = len - ch;

      if (pkg [pos] == '-')
        {
          /* Getting the length of this part/section */
          part_len = ch - last;

          /* Allocating memory for this part/section */
          parts [part] = malloc (sizeof (char) * part_len);

          /* Saving the identified part/section */
          strncpy (parts [part], tmp + strlen (tmp) - part_len - last + 1, part_len);

          /* Adding the string terminator */
          parts [part][part_len - 1] = '\0';

          /* Saving the current postion for the next round */
          last = ch;

          --part;
        }
    }

  /* Verifying all 4 parts of the package name were found, return otherwise */
  if (part != 0)
    return (1);

  /* Putting together part 0 */
  parts [part] = malloc (sizeof (char) * pos + 1);
  strncpy (parts [part], tmp, pos);
  parts [part][pos] = '\0';

  /* for testing only...
  printf ("%s : %s : %s : %s\n", parts[0], parts[1], parts[2], parts[3]);
  printf ("\n");
   */

  return (0);
}


int
compare_pkgs (char *lparts [4], char *pparts [4])
{
  char **ver;

  /* Step 1: We want to start by comparing architectures */
  if (strcmp (lparts [2], pparts [2]) != 0)
    return (1); /* System architectures are different */


  /* Step 2: Find out if alpha/letter characters are part of the version part */
  regex_t reg;
  if (regcomp (&reg, "\\[a-zA-Z\\]\\+", 0) != 0)
    return (2); /* Error with the regex compilation */

  if (regexec (&reg, lparts [1], 0, NULL, 0) == 0)
    {
      regfree (&reg);
      return (3); /* Alpha character found w/in the version section/part */
    }

  /* Given the previous check, this shouldn't be needed, but just in case... */
  if (regexec (&reg, pparts [1], 0, NULL, 0) == 0)
    {
      regfree (&reg);
      return (3);
    }

  regfree (&reg);


  /* Step 3: Substituting underscores with periods */
  char *found;
  while ((found = strchr (lparts [1], '_')) != NULL)
    lparts [1] [found - lparts [1]] = '.';

  while ((found = strchr (pparts [1], '_')) != NULL)
    pparts [1] [found - pparts [1]] = '.';


  /* Step 4: Retrieving the version numbers */
  int *ver_part = NULL;
  char *tmp = strtok (lparts [1], ".");

  if (tmp == NULL)
    return (4);

  ver_part = realloc (ver_part, sizeof (int));
  ver_part [0] = atoi (tmp);

  int x = 1;
  while ((tmp = strtok (NULL, ".")) != NULL)
    {
      ver_part = realloc (ver_part, sizeof (int) * (x + 1));
      ver_part [1] = atoi (tmp);
    }

  //NEED TO GET ARRAY OF VERSION NUMBERS

  //NEED TO TAKE INTO CONSIDERATION CHARS ADDED TO THE VERSION NUMBER(S)

  //NEED TO ADD THE LAST PKG NUMBER TO THE VERSION NUMBER 




  return (0);
}

