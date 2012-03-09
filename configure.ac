#  See LICENSE for details
#
#  The version number in AC_INIT is for the tmap package.
#  Developers - the version number should *NEVER* be changed except by, 
#  or with explicit permission from the SAMtools developers.

AC_PREREQ(2.61);
AC_INIT([samtools],[0.1.18],[samtools-help@lists.sourceforge.net],[samtools])
AC_COPYRIGHT([See LICENSE for copyright information.])
AC_CONFIG_AUX_DIR(config)
AM_INIT_AUTOMAKE([dist-bzip2 subdir-objects])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

# Sets build_cpu, build_vendor and build_os variables
AC_CANONICAL_BUILD

# Check for C and C++ compilers
AC_PROG_CC
AM_PROG_CC_C_O

AC_PROG_INSTALL
AC_GNU_SOURCE

# Check for libtool
LT_INIT

AC_PROG_RANLIB
AC_PROG_CXX
AC_PROG_LN_S

# set CFLAGS and CXXFLAGS
default_CFLAGS="-g -Wall -O2 -pthread";
extended_CFLAGS="-D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE";

# Check and store the GIT revision
AC_MSG_CHECKING(whether the git revision is available)
gitrev="`git log 2>/dev/null | grep -m 1 commit | awk '{print $2}'`";
if test -n "${gitrev}"; then
    GITREV="${gitrev}";
	echo "${gitrev}" > samtools.git.rev;
elif test -f "samtools.git.rev"; then
	GITREV="`head -n 1 samtools.git.rev`";
fi
if test -n "${GITREV}"; then
    AC_REVISION(["${GITREV}"])
    AC_DEFINE_UNQUOTED(GIT_REV, "${GITREV}", [Define to be the GIT revision number])
    AC_MSG_RESULT(yes)
else
	AC_MSG_RESULT(no)
fi

AC_ARG_ENABLE(intel64, [  --enable-intel64        optimize for Intel64 CPU such as Xeon and Core2], [extended_CFLAGS="${extended_CFLAGS} -mtune=nocona"], [])
AC_ARG_ENABLE(tcmalloc, [  --enable-tcmalloc      enable tcmalloc for memory allocation], [AC_CHECK_LIB([tcmalloc],malloc)], []) 
AC_ARG_ENABLE(perftools, [  --enable-perftools      enable google performance tools for profiling and heap checking], [LIBS="${LIBS} -lprofiler"], [])
AC_ARG_ENABLE(knetfile, [  --disable-knetfile        disable knetfile support], [], [extended_CFLAGS="${extended_CFLAGS} -D_USE_KNETFILE"])

CFLAGS="${CFLAGS} ${default_CFLAGS} ${extended_CFLAGS}";

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
# Checks for library functions.
AC_FUNC_MALLOC 
AC_FUNC_REALLOC
AC_FUNC_ALLOCA
AC_FUNC_FSEEKO
AC_FUNC_MEMCMP
AC_FUNC_SELECT_ARGTYPES
AC_FUNC_STAT
AC_FUNC_STRTOD
AC_FUNC_VPRINTF
AC_CHECK_LIB([z], [gzread])
AC_CHECK_LIB([m], [pow])
AC_CHECK_LIB([pthread], [pthread_create])
#AC_CHECK_LIB([libtcmalloc_minimal],malloc) # Use this to not include the heap profiler and checker
AC_CHECK_FUNCS([pow strdup memset strchr strdup strstr memmove getopt_long])

AC_CHECK_FUNCS([gethostbyaddr gethostbyname memchr select socket sqrt strerror strtol])

AC_HEADER_STDBOOL
AC_HEADER_TIME

# Check types
AC_TYPE_INT8_T
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_UINT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_SIZE_T
AC_TYPE_OFF_T

# Set proprocessor SIZEOF_short_int, SIZEOF_int, SIZEOF_long_int
AC_CHECK_SIZEOF([short int])
AC_CHECK_SIZEOF([int])
AC_CHECK_SIZEOF([long int])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h stdio.h stdint.h string.h sys/time.h])
AC_CHECK_HEADERS([unistd.h float.h zlib.h pthread.h limits.h])
AC_CHECK_HEADERS([netinet/in.h getopt.h])
AC_CHECK_HEADERS([arpa/inet.h fcntl.h netdb.h sys/socket.h]) 
# Some GNU/Linux systems (e.g., SuSE 4.3, 1996) don't have curses, but
# rather ncurses.  So we check for it.
CURSESLIB_VARIANTS="ncurses curses xcurses";
AC_CHECK_HEADERS([ncurses.h curses.h xcurses.h]) # NB: for some reason, do this outside the loop
for ncurseslib in ${CURSESLIB_VARIANTS}; 
do
	AC_CHECK_LIB(${ncurseslib}, tgetent, [LIBS="${LIBS} -l${ncurseslib}"; break])
done

AC_C_INLINE

AC_CONFIG_FILES([Makefile])

AC_OUTPUT
