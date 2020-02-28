#include "../common/string.c"

#include "./rmd160.c"

#define RMDsize 160

// receive a parameter value
void setParameter(int parameter_index, int parameter_value)
{
  // this transformation does not take parameters
}

// return the worst-case required size of memory for the output
int requiredForwardOutputLengthInBytes(int inputLengthInBytes)
{
   return 20;
}

// return the actual length in bytes
int forward(char *inputString, int inputLengthInBytes, char *outputString)
{
   dword context[5];
   
   dword         MDbuf[RMDsize/32];   /* contains (A, B, C, D(, E))   */
   static byte   hashcode[RMDsize/8]; /* for final hash-value         */
   dword         X[16];               /* current 16-word chunk        */
   unsigned int  i;                   /* counter                      */
   dword         length;              /* length in bytes of message   */
   dword         nbytes;              /* # of bytes not yet processed */

   /* initialize */
   MDinit(MDbuf);
   length = (dword) inputLengthInBytes;

   char *current = inputString;
   
   /* process message in 16-word chunks */
   for (nbytes=length; nbytes > 63; nbytes-=64)
   {
      for (i=0; i<16; i++)
      {
         X[i] = BYTES_TO_DWORD(current);
         current += 4;
      }
      compress(MDbuf, X);
   }                                    /* length mod 64 bytes left */

   /* finish: */
   MDfinish(MDbuf, (byte *) current, length, 0);

   for (i=0; i<RMDsize/8; i+=4)
   {
      hashcode[i]   =  MDbuf[i>>2];         /* implicit cast to byte  */
      hashcode[i+1] = (MDbuf[i>>2] >>  8);  /*  extracts the 8 least  */
      hashcode[i+2] = (MDbuf[i>>2] >> 16);  /*  significant bits.     */
      hashcode[i+3] = (MDbuf[i>>2] >> 24);
   }

   for (int i = 0; i < 20; ++i)
   {
      outputString[i] = hashcode[i];
   }

   return 20;
}

// return the worst-case required size of memory for the output
int requiredBackwardOutputLengthInBytes(int inputLengthInBytes)
{
   return requiredForwardOutputLengthInBytes(inputLengthInBytes);
}

// return the actual length in bytes
int backward(char *inputString, int inputLengthInBytes, char *outputString)
{
   return forward(inputString, inputLengthInBytes, outputString);
}
