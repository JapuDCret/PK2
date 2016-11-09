#include <stdlib.h>

char * stringcat(const char * str1, const char * str2)
{
  int length_1 = strlength(str1);
  int length_2 = strlength(str2);
  int length = length_1 + length_2 + 1;
  
  char * newstr = malloc(sizeof(char) * length);
  
  int i;
  for(i=0; i < length; i++)
  {
    char charToCopy = '\0';
    if(i < length_1)
    {
      charToCopy = *(str1 + i);
    } else if(i < (length_1 + length_2)) {
      charToCopy = *(str2 + i - length_1);
    }

    *(newstr + i) = charToCopy;
  }

  return newstr;
}

int strlength(const char * str)
{
  int length = 0;
  while(str[length] != '\0')
  {
    length++;
  }
  return length;
}
