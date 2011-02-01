#
#
# application: bpkg
# file: Makefile 
# description: application building make instructions 
# Requirements: gcc, glibc
# author: alex alvarez
# email: alex.alvarez@xbasics.com
# license: gnu public license 2 (gpl2)
# (http://www.gnu.org/licenses/gpl-2.0.txt)
#
#


PROGNAME = bpkg
CC = gcc
OBJECTS = bpkg.o contents.o packages.o print.o errors.o #upgrade.o upgrade_curl.o upgrade_parse.o  
#LIBS = -lcurl

# These CFLAGS below are for x86_64.
# Use "CFLAGS = -02 -march=i686 -mtune=i686" for modern 32-bit computers.
CFLAGS = -O2 -fPIC -march=k8 -mtune=k8


all: $(PROGNAME) 

$(PROGNAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LIBS)

bpkg.o: bpkg.h 

#upgrade.o: upgrade.h

#upgrade_curl.o: upgrade_curl.h

#upgrade_parse.o: upgrade_parse.h

contents.o: contents.h

packages.o: packages.h

print.o: print.h

errors.o: errors.h

clean:
	rm -f bpkg *.o *~

