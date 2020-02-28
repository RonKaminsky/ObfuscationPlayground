#include "../common/string.c"

#include "../common/rfc6234/sha384-512.c"

// receive a parameter value
void setParameter(int parameter_index, int parameter_value)
{
  // this transformation does not take parameters
}

// return the worst-case required size of memory for the output
int requiredForwardOutputLengthInBytes(int inputLengthInBytes)
{
   return 64;
}

// return the actual length in bytes
int forward(char *inputString, int inputLengthInBytes, char *outputString)
{
   if (inputLengthInBytes < 0)
   {
      return 0;
   }
   
   SHA512Context context;

   SHA512Reset(&context);
   SHA512Input(&context, (const uint8_t *) inputString, (unsigned int) inputLengthInBytes);
   SHA512Result(&context, (uint8_t *) outputString);

   return 64;
}

// return the worst-case required size of memory for the output
int requiredBackwardOutputLengthInBytes(int inputLengthInBytes)
{
   return 64;
}

// return the actual length in bytes
int backward(char *inputString, int inputLengthInBytes, char *outputString)
{
   return forward(inputString, inputLengthInBytes, outputString);
}
