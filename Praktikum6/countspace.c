int countspace(char s[])
{
  int pos = 0;
  int count = 0;
  while(*(s + pos) != '\0')
  {
    if (s[pos++] == ' ') count++;
  }
  return count;
}
