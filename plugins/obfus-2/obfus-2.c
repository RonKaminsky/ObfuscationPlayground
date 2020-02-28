// Implements a modified Vigenere cipher where the single parameter
// generates the key via seeding a PRNG.

#include "../common/jsf.c"

int parameter[1] = {777};

// receive a parameter value
void setParameter(int parameter_index, int parameter_value)
{
  if (parameter_index == 0)
  {
     parameter[0] = parameter_value;
  }
}

// return the worst-case required size of memory for the output
int requiredForwardOutputLengthInBytes(int inputLengthInBytes)
{
   return inputLengthInBytes;
}

// return the actual length in bytes
int forward(char *inputString, int inputLengthInBytes, char *outputString)
{
   const int xor_length = 12;
   static unsigned char xor_data[xor_length];
   static jsf_ctx context;

   jsf_init(&context, parameter[0]);
   for (int k = 0; k < xor_length; ++k)
   {
      xor_data[k] = jsf_val(&context) & 0xFF;
   }
   
   for (int k = 0; k < inputLengthInBytes; ++k)
   {
      outputString[k] = inputString[k] ^ xor_data[k % xor_length];
   }

   return inputLengthInBytes;
}

// return the worst-case required size of memory for the output
int requiredBackwardOutputLengthInBytes(int inputLengthInBytes)
{
   return inputLengthInBytes;
}

// return the actual length in bytes
int backward(char *inputString, int inputLengthInBytes, char *outputString)
{
   return forward(inputString, inputLengthInBytes, outputString);
}
