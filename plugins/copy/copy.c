// receive a parameter value
void setParameter(int parameter_index, int parameter_value)
{
  // this transformation does not take parameters
}

// return the worst-case required size of memory for the output
int requiredForwardOutputLengthInBytes(int inputLengthInBytes)
{
   return inputLengthInBytes;
}

// return the actual length in bytes
int forward(char *inputString, int inputLengthInBytes, char *outputString)
{
   for (int k = 0; k < inputLengthInBytes; ++k)
   {
      outputString[k] = inputString[k];
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
