#include "../common/jsf.c"

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

   jsf_ctx context;

   jsf_init(&context, (2105410373 * inputLengthInBytes) & 0xFFFFFFFF);

   for (int k = 0; k < inputLengthInBytes; ++k)
   {
      outputString[k] = outputString[k] ^ (jsf_val(&context) & 0xFF);
   }

   if (inputLengthInBytes > 3)
   {
      jsf_init(&context, (1940093673 * inputLengthInBytes) & 0xFFFFFFFF);

      for (int m = 0; m < 10; ++m)
      {
         int interval = jsf_val(&context) % inputLengthInBytes;
      
         for (int k = 0; k < inputLengthInBytes; ++k)
         {
            int index_0 = k;
            int index_1 = (k + interval) % inputLengthInBytes;
            int tmp = outputString[index_0];
            outputString[index_0] = outputString[index_1];
            outputString[index_1] = tmp;
         }
      }
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
   for (int k = 0; k < inputLengthInBytes; ++k)
   {
      outputString[k] = inputString[k];
   }

   jsf_ctx context;

   jsf_init(&context, (2936224219 * inputLengthInBytes) & 0xFFFFFFFF);

   if (inputLengthInBytes > 3)
   {
      jsf_init(&context, (1940093673 * inputLengthInBytes) & 0xFFFFFFFF);

      int intervals[10];
      
      for (int m = 0; m < 10; ++m)
      {
         intervals[m] = jsf_val(&context) % inputLengthInBytes;
      }
      
      for (int m = 10 - 1; m >= 0; --m)
      {
         for (int k = inputLengthInBytes - 1; k >= 0; --k)
         {
            int index_0 = k;
            int index_1 = (k + intervals[m]) % inputLengthInBytes;
            int tmp = outputString[index_0];
            outputString[index_0] = outputString[index_1];
            outputString[index_1] = tmp;
         }
      }
   }
   
   jsf_init(&context, (2105410373 * inputLengthInBytes) & 0xFFFFFFFF);

   for (int k = 0; k < inputLengthInBytes; ++k)
   {
      outputString[k] = outputString[k] ^ (jsf_val(&context) & 0xFF);
   }

   return inputLengthInBytes;
}
