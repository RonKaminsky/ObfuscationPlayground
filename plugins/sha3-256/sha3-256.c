#include "../common/string.c"

#include "../common/tiny_sha3/sha3.c"

// receive a parameter value
void setParameter(int parameter_index, int parameter_value)
{
  // this transformation does not take parameters
}

// return the worst-case required size of memory for the output
int requiredForwardOutputLengthInBytes(int inputLengthInBytes)
{
   return 32;
}

// return the actual length in bytes
int forward(char *inputString, int inputLengthInBytes, char *outputString)
{
   if (inputLengthInBytes < 0)
   {
      return 0;
   }

   sha3(inputString, inputLengthInBytes, outputString, 32);

   return 32;
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









