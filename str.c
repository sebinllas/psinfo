/*given one string (s) and two chars (c and rep) replace all the occurrences of c in s by rep*/
void replace_str(char *s, char c, char rep)
{
  char *mem_add = s;
  int size = sizeof *mem_add;

  while (*mem_add != '\0')
  {

    if (*mem_add == c)
    {
      *mem_add = rep;
    }
    mem_add += size;
  }
}

/* return a pointer to the first occurrence of c in s*/
char *addres_of_char(char *s, char c)
{
  char *mem_add = s;
  while ((*mem_add != c) & (*mem_add != '\0'))
  {
    mem_add++;
  }
  return mem_add;
}

/* return the lenght of a given string*/
int len_str(char *c)
{
  return addres_of_char(c, '\0') - c;
}

//append a char to a string
void append_char(char *dest, char src)
{
  char *dest_add = addres_of_char(dest, '\0');
  *dest_add = src;
  *(dest_add + 1) = '\0';
}

//given a string with a lists of words separeted by s return a copy of the word on position n
char *get_word(char *words, int n, char s)
{
  int size = len_str(words);
  char *mem_add = words;
  char *word_add;
  int count = 0;
  for (int i = 0; i < size; i++)
  {
    if (n == 0)
    {
      break;
    }
    if (*mem_add == s)
    {
      count++;
    }
    if (count == n)
    {
      mem_add = mem_add + 1;
      break;
    }
    mem_add = mem_add + 1;
  }
  word_add = mem_add;
  int word_lenght = addres_of_char(word_add, s) - word_add;
  char *word = calloc(word_lenght + 1, 1);
  for (int i = 0; i < word_lenght; i++)
  {
    *((char *)(word + i)) = *((char *)(mem_add + i));
  }

  return word;
}

//append one string to another
void append_str(char *dest, char *src)
{
  char *mem_add = src;
  int size = sizeof *mem_add;
  char *dest_add = addres_of_char(dest, '\0');
  int src_lenght = len_str(src);
  for (int i = 0; i < src_lenght; i++)
  {
    *((char *)dest_add + i * size) = *((char *)mem_add + i * size);
  }
}