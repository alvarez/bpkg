/*
 *
 * application: bpkg
 * file: pkgs.h 
 * description: main header file
 * author: alex alvarez
 * email: alex.alvarez@xbasics.com
 * license: gnu public license 2 (gpl2)
 * (http://www.gnu.org/licenses/gpl-2.0.txt)
 *
 * */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <dirent.h>
#include <curl/curl.h>
#include <curl/easy.h>


//#define NULL (void*) 0;

#define URL "http://slackware.mirrors.tds.net"

#define PKG_DIR "/var/log/packages/"


struct local_struct
{
    int count;
    int size;
    char **data;
};

struct file_struct
{
    int count;
    int size;
    char *data;
};

struct line_struct
{
    int count;
    char **data;
};

struct pkg_struct
{
    int count;
    char **address;
    char **hash;
};



