#define size_t unsigned long

void* memcpy(void *dest, const void *src, size_t count)
{
   unsigned char *d = (unsigned char *) dest;
   unsigned char *s = (unsigned char *) src;
   
   for (int i = 0; i < count; ++i)
   {
      d[i] = s[i];
   }
   return dest;
}

void *memset(void *dest, int ch, size_t count)
{
   unsigned char *d = (unsigned char *) dest;
   
   for (int i = 0; i < count; ++i)
   {
      d[i] = ch;
   }

   return dest;
}
