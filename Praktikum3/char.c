#include <stdio.h>

char to_upper_case(char c);
void upper(char * text);

int main(void)
{
  char c = 'j';
  printf("to_upper_case(\'%c\')=\'%c\'\n", c, to_upper_case(c));

  char str[] = "Marvin*Marvin=Marvin_quadrat";
  printf("upper(\"%s\")=", str);
  upper(str);
  printf("\"%s\"\n", str);
}

char to_upper_case(char c)
{
  if((c >= 'a') && (c <= 'z'))
  {
    c -= 32;
  }
  return c;
}

void upper(char * text)
{
  while(*text != '\0')
  {
    *text = to_upper_case(*text);
    text++;
  }
}
