/*
 *
 * application: bpkg
 * file: packages.h
 * description: header file for packages.c 
 * author: alex alvarez
 * email: alex.alvarez@xbasics.com
 * license: gnu public license 2 (gpl2)
 * (http://www.gnu.org/licenses/gpl-2.0.txt)
 *
 * */


extern int
get_local_packages (struct local_struct *);


extern int
get_pkg_parts (char *, char **);


int
compare_pkgs (char **, char **);

