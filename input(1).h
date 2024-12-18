#ifndef __AX_HA_IT_INPUT__
#define __AX_HA_IT_INPUT__

#include <errno.h>

/*
  If something goes wrong all functions
  1) sets the global errno variable to EIO
  2) empties the input buffer
  3) returns 0
*/

/* Read an integer from standard input.
   Expects standard 'whitespace' delimiter (spaces/tabs/newline)
*/
int readInt(void);

/* Read an integer from standard input, preceded by a custom delimiter.
   Example: readIntAfter(',') expects an integer preceded by a comma.
*/
int readIntAfter(char delimiter);

/* Read an unsigned integer from standard input */
unsigned readUnsigned(void);
unsigned readUnsignedAfter(char delimiter);

/* Read a short integer from standard input */
short readShort(void);
short readShortAfter(char delimiter);

/* Read a long integer from standard input */
long readLong(void);
long readLongAfter(char delimiter);

/* Read a long long integer from standard input */
long long readLongLong(void);
long long readLongLongAfter(char delimiter);

/* Read a float from standard input */
float readFloat(void);
float readFloatAfter(char delimiter);

/* Read a double from standard input */
double readDouble(void);
double readDoubleAfter(char delimiter);

/* Read a char from standard input */
char readChar(void);
char readCharAfter(char delimiter);

#endif // __AX_HA_IT_INPUT__