#include "c_shell.h"
/**
 * allocate_malloc - safely allocate memory
 * Returns: 0 for success, -1 otherwise
 */
int allocate_malloc(char **tkns_v, int pos, size_t buf) {
  int i;

  i = 0;
  tkns_v[pos] = malloc(buf);
  if (tkns_v[pos] == NULL) {
    while (i < pos)
      free(tkns_v[i++]);
    free(tkns_v);
    return (1);
  }
  return (0);
}
/**
 * tkn_cpy - copies the values of one string to the other
 * Return: does not return
 */
void tkn_cpy(char *dest, const char *source, size_t len) {
  while (*source && --len)
    *dest++ = *source++;
  *dest = '\0';
}
/**
 * place_tkns - positions tokens correctly in malloc
 * Returns: 0 for success
 */
int place_tkns(char **tkns_v, char const *str, char delimiter) {
  size_t tkn_size;
  int pos;

  pos = 0;
  while (*str) {
    tkn_size = 0;
    while (*str && *str == delimiter)
      ++str;
    while (*str && *str != delimiter) {
      ++tkn_size;
      ++str;
    }
    if (tkn_size) {
      if (allocate_malloc(tkns_v, pos, tkn_size + 1))
        return (-1);
    }
    tkn_cpy(tkns_v[pos], str - tkn_size, tkn_size + 1);
    ++pos;
  }
  return (0);
}
/**
 * no_tkns - counts the number of tokens in a string
 * Returns: number of tokens
 */
size_t no_tkns(const char *str, char delimiter) {
  size_t tkns;
  bool is_word;

  tkns = 0;
  while (*str) {
    is_word = false;
    while (*str && *str == delimiter)
      ++str;
    while (*str && *str != delimiter) {
      if (!is_word) {
        ++tkns;
        is_word = true;
      }
      ++str;
    }
  }
  return tkns;
}
/**
 *
 * */
char **no_strtok(const char *str, char delimiter) {
  size_t tkns;
  char **tkns_v;

  tkns = 0;
  tkns = no_tkns(str, delimiter);
  if (str == NULL)
    return NULL;
  /**Allocate spaces to token pointers*/
  tkns_v = malloc((sizeof(char *)) * (tkns + 1));
  if (tkns_v == NULL)
    return NULL;
  /**argv must end in NULL*/
  tkns_v[tkns] = NULL;
  if (place_tkns(tkns_v, str, delimiter))
    return NULL;
  return tkns_v;
}

int main() {
  char *str = "    hello there dude";
  char delimiter = ' ';
  char **tokens = no_strtok(str, delimiter);

  while (*tokens)
    printf("%s\n", *tokens++);
  return (0);
}
