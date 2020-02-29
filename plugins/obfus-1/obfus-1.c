unsigned char byte_perm[] = {203, 246, 134, 22, 86, 218, 199, 116, 63, 192, 206, 35, 156, 247, 88, 222, 189, 55, 81, 60, 90, 198, 158, 19, 147, 195, 101, 76, 67, 40, 244, 64, 18, 2, 139, 37, 95, 249, 167, 140, 208, 91, 137, 51, 138, 9, 233, 196, 180, 104, 124, 58, 202, 220, 30, 251, 98, 65, 132, 42, 73, 34, 186, 232, 78, 154, 29, 177, 52, 109, 0, 182, 135, 194, 121, 230, 236, 226, 56, 10, 190, 125, 24, 175, 28, 3, 13, 219, 66, 122, 46, 172, 89, 94, 38, 16, 54, 151, 110, 163, 80, 1, 43, 165, 61, 41, 214, 149, 77, 191, 168, 197, 96, 173, 241, 128, 131, 221, 171, 114, 217, 153, 179, 213, 212, 74, 155, 48, 44, 4, 123, 164, 250, 75, 111, 228, 239, 133, 68, 12, 50, 57, 141, 243, 254, 26, 72, 49, 211, 112, 6, 108, 105, 126, 234, 129, 17, 118, 25, 136, 227, 169, 162, 99, 187, 159, 45, 93, 113, 204, 237, 33, 235, 62, 71, 185, 176, 231, 145, 166, 100, 117, 238, 252, 245, 248, 127, 119, 103, 157, 255, 27, 200, 142, 11, 178, 21, 97, 79, 210, 39, 225, 130, 8, 181, 193, 207, 31, 115, 70, 205, 174, 107, 224, 144, 201, 36, 209, 69, 7, 188, 82, 242, 53, 253, 216, 148, 32, 150, 106, 83, 84, 223, 146, 102, 160, 87, 184, 59, 5, 240, 85, 215, 143, 92, 183, 47, 152, 15, 161, 20, 229, 120, 23, 170, 14};

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
   unsigned char * input = (unsigned char *) inputString;
   unsigned char * output = (unsigned char *) outputString;

   output[0] = input[0];

   for (int k = 1; k < inputLengthInBytes; ++k)
   {
      output[k] = input[k] ^ byte_perm[output[k - 1]];
   }

   output[inputLengthInBytes - 1] ^= 131;

   for (int k = inputLengthInBytes - 2; k >= 0; --k)
   {
      output[k] = output[k] ^ byte_perm[output[k + 1]];
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
   unsigned char * input = (unsigned char *) inputString;
   unsigned char * output = (unsigned char *) outputString;

   for (int k = 0; k < inputLengthInBytes - 1; ++k)
   {
      output[k] = input[k] ^ byte_perm[input[k + 1]];
   }

   output[inputLengthInBytes - 1] = input[inputLengthInBytes - 1] ^ 131;

   for (int k = inputLengthInBytes - 1; k > 0; --k)
   {
      output[k] = output[k] ^ byte_perm[output[k - 1]];
   }

   return inputLengthInBytes;
}
