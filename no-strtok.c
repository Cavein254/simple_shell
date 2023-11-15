#include "c_shell.h"
/**
 * place_tkns - positions tokens correctly in malloc
 * Returns: 0 for success
 */
int place_tkns(char **tkns_v, char *str, char delimiter) {
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
      allocate_malloc(tkns_v, pos, tkn_size + 1, tkn_size + 1);
    }
    strlcpy(tkns_v[pos], str - tkn_size, tkn_size + 1);
  }
}
/**
 * no_tkns - counts the number of tokens in a string
 * Returns: number of tokens
 */
size_t no_tkns(*str, char delimiter) {
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
char **no_strtok(*str, char delimiter) {
  size_t tkns;
  char **tkns_v;

  tkns = 0;
  tkns = no_tkns(str, delimiter);
  if (str == NULL)
    return NULL;
  /**Allocate spaces to token pointers*/
  tkns_v = malloc((sizeof char *)*(tkns + 1));
  if (tkns_v == NULL)
    return NULL;
  /**argv must end in NULL*/
  tkns_v[tkns] = NULL;
  place_tkns(tkns_v, str, delimiter);
}

int main() { return (0); }
