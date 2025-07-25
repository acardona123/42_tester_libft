#include "test_libft_functions_auto.h"

int main(void) {
  int error;

  error = 0;
  error += test_ft_isalpha();
  error += test_ft_isdigit();
  error += test_ft_isalnum();
  error += test_ft_isascii();
  error += test_ft_isprint();
  error += test_ft_strlen();
  error += test_ft_memset();
  error += test_ft_bzero();
  error += test_ft_memcpy();
  error += test_ft_memmove();
  error += test_ft_strlcpy();
  error += test_ft_strlcat();
  error += test_ft_toupper();
  error += test_ft_tolower();
  error += test_ft_strchr();
  error += test_ft_strrchr();
  error += test_ft_strncmp();
  error += test_ft_memchr();
  error += test_ft_memcmp();
  error += test_ft_strnstr();
  error += test_ft_atoi();
  error += test_ft_calloc();
  error += test_ft_strdup();
  error += test_ft_substr();
  error += test_ft_strjoin();
  error += test_ft_strtrim();
  error += test_ft_split();
  error += test_ft_itoa();
  error += test_ft_strmapi();
  error += test_ft_striteri();
  /*
  error += test_ft_putchar_fd();
  error += test_ft_putstr_fd();
  error += test_ft_putendl_fd();
  error += test_ft_putnbr_fd();
  */
  printf("\e[1m  ==> Bilan des tests automatiques de fonctions :\n");
  if (error == 0)
    printf("\e[1;32m\tOK\e[0m\n");
  else
    printf("\e[0;31m    /!\\ KO : erreur ou echec de malloc dans %d "
           "fonction(s).\e[0m\n",
           error);
  return (0);
}

void test_msgbilan(char *nom_fonction, int statut) {
  if (statut == 0)
    printf("\e[0;31m/!\\ KO : ft_%s\n\e[0m", nom_fonction);
  else if (statut == 1)
    printf("    OK : ft_%s\n", nom_fonction);
  else if (statut == 2)
    printf("/!\\ ?? : ft_%s , echec de malloc\n", nom_fonction);
  else
    printf("Statut de reussite indetermine\n");
}

int test_ft_isalpha(void) {
  int i;

  i = 0;
  while (i < 256) {
    if ((ft_isalpha(i) && !isalpha(i)) || (!ft_isalpha(i) && isalpha(i))) {
      test_msgbilan("isalpha", 0);
      return (1);
    }
    ++i;
  }
  if (ft_isalpha(EOF)) {
    test_msgbilan("isalpha", 0);
    return (1);
  }
  test_msgbilan("isalpha", 1);
  return (0);
}

int test_ft_isdigit(void) {
  int i;

  i = -5;
  while (i < 30) {
    if ((ft_isdigit(i + '0') && !isdigit(i + '0')) ||
        (!ft_isdigit(i + '0') && isdigit(i + '0'))) {
      test_msgbilan("isdigit", 0);
      return (1);
    }
    ++i;
  }
  if (ft_isdigit(EOF)) {
    test_msgbilan("isdigit", 0);
    return (1);
  }
  test_msgbilan("isdigit", 1);
  return (0);
}

int test_ft_isalnum(void) {
  int i;

  i = 0;
  while (i < 256) {
    if ((ft_isalnum(i) && !isalnum(i)) || (!ft_isalnum(i) && isalnum(i))) {
      test_msgbilan("isalnum", 0);
      return (1);
    }
    ++i;
  }
  if (ft_isalnum(EOF)) {
    test_msgbilan("isalnum", 0);
    return (1);
  }
  test_msgbilan("isalnum", 1);
  return (0);
}

int test_ft_isascii(void) {
  int i;

  i = -12;
  while (i < 280) {
    if (ft_isascii(i) != isascii(i)) {
      test_msgbilan("isascii", 0);
      return (1);
    }
    ++i;
  }
  if (ft_isascii(EOF) != isascii(EOF)) {
    test_msgbilan("isascii", 0);
    return (1);
  }
  test_msgbilan("isascii", 1);
  return (0);
}

int test_ft_isprint(void) {
  int i;

  i = -15;
  while (i < 280) {
    if ((ft_isprint(i) && !isprint(i)) || (!ft_isprint(i) && isprint(i))) {
      test_msgbilan("isprint", 0);
      return (1);
    }
    ++i;
  }
  if (ft_isprint(EOF) != isprint(EOF)) {
    test_msgbilan("isprint", 0);
    return (1);
  }
  test_msgbilan("isprint", 1);
  return (0);
}

int test_ft_strlen(void) {
  char *str;

  str = "";
  if (ft_strlen(str) != strlen(str)) {
    test_msgbilan("strlen", 0);
    return (1);
  }
  str = "vhrjhfnhehfiejcryhejdbhehcujenhwuec";
  if (ft_strlen(str) != strlen(str)) {
    test_msgbilan("strlen", 0);
    return (1);
  }
  test_msgbilan("strlen", 1);
  return (0);
}

int test_ft_memset(void) {
  int i;
  int c;
  char str[100] = "Ceci est un mega test";
  char str1[100] = "Ceci est un mega test";

  i = 12;
  c = '~';
  ft_memset(str, c, i * sizeof(char));
  memset(str1, c, i * sizeof(char));
  if (strcmp(str, str1) != 0) {
    test_msgbilan("memset", 0);
    return (1);
  }
  test_msgbilan("memset", 1);
  return (0);
}

int test_ft_bzero(void) {
  char str[100] =
      "Ceci est un mega test, bien qu'il puisse etre encore plus long";

  ft_bzero(str + 2, 4); /*On met quatre \0 a partir du 3eme terme de str*/
  if (strcmp(str, "Ce") != 0 || *(str + 2) != '\0' || *(str + 3) != '\0' ||
      *(str + 4) != '\0' || *(str + 5) != '\0' ||
      strcmp(str + 2 + 4,
             "st un mega test, bien qu'il puisse etre encore plus long") != 0) {
    test_msgbilan("bzero", 0);
    return (1);
  }
  test_msgbilan("bzero", 1);
  return (0);
}

int test_ft_memcpy(void) {
  char str[] = "TotoAaAaAaAaAa";

  ft_memcpy(str + 5, str, 4);
  if (strcmp(str, "TotoATotoaAaAa") != 0) {
    test_msgbilan("memcpy", 0);
    return (1);
  }
  test_msgbilan("memcpy", 1);
  return (0);
}

int test_ft_memmove(void) {
  char str[] = "TotoAaAaAaAaAa";

  ft_memmove(str + 3, str, 4);
  if (strcmp(str, "TotTotoaAaAaAa") != 0) {
    test_msgbilan("memmove", 0);
    return (1);
  }
  test_msgbilan("memmove", 1);
  return (0);
}

int test_ft_strlcpy(void) {
  char str_scr[] = "eehehchxgrf";
  char str_dest[] = "gewafwrgrereff";
  unsigned int n;

  n = ft_strlcpy(str_dest, str_scr, 30);
  if (strcmp(str_dest, "eehehchxgrf") != 0 || n != 11) {
    test_msgbilan("strlcpy t1", 0);
    return (1);
  }
  n = ft_strlcpy(str_dest, str_scr, 5);
  if (strcmp(str_dest, "eehe") != 0 || n != 11) {
    test_msgbilan("strlcpy t2", 0);
    return (1);
  }
  n = ft_strlcpy(str_dest, "", 5);
  if (strcmp(str_dest, "") != 0 || n != 0) {
    test_msgbilan("strlcpy t3", 0);
    return (1);
  }
  test_msgbilan("strlcpy", 1);
  return (0);
}

int test_ft_strlcat(void) {
  char dst[30];
  char *src = (char *)"AAAAAAAAA";
  size_t n;

  memset(dst, 0, 30);
  dst[0] = 'B';
  if (ft_strlcat(dst, src, 0) != strlen(src) || *dst != 'B') {
    test_msgbilan("strlcat t1", 0);
    return (1);
  }
  if (ft_strlcat(dst, src, 1) != strlen(src) + 1 || *dst != 'B') {
    test_msgbilan("strlcat t2", 0);
    return (1);
  }
  memset(dst, 'B', 4);
  n = ft_strlcat(dst, src, 3);
  if ((n != 3 + strlen(src)) || strcmp(dst, "BBBB") != 0) {
    test_msgbilan("strlcat t3", 0);
    return (1);
  }
  if (ft_strlcat(dst, src, 6) != 13 || strcmp(dst, "BBBBA") != 0) {
    test_msgbilan("strlcat t4", 0);
    return (1);
  }
  test_msgbilan("strlcat", 1);
  return (0);
}

int test_ft_toupper(void) {
  int i;

  i = 'A' - 1;
  while (i <= 'z' + 1) {
    if (ft_toupper(i) != toupper(i)) {
      test_msgbilan("toupper", 0);
      return (1);
    }
    ++i;
  }
  test_msgbilan("toupper", 1);
  return (0);
}

int test_ft_tolower(void) {
  int i;

  i = 'A' - 1;
  while (i <= 'z' + 1) {
    if (ft_tolower(i) != tolower(i)) {
      test_msgbilan("tolower", 0);
      return (1);
    }
    ++i;
  }
  test_msgbilan("tolower", 1);
  return (0);
}

int test_ft_strchr(void) {
  char str[] = "Test de la fonction";
  if ((ft_strchr(str, 'e') != str + 1) ||
      (ft_strchr(str, '\0') != str + strlen(str)) ||
      (ft_strchr(str, 'w') != NULL) || (ft_strchr(str, 'e' + 256) != str + 1)) {
    test_msgbilan("strchr", 0);
    return (1);
  }
  test_msgbilan("strchr", 1);
  return (0);
}

int test_ft_strrchr(void) {
  char str[] = "Test de la fonction";
  if (ft_strrchr(str, 'e') != strrchr(str, 'e') ||
      ft_strrchr(str, 'e' + 256) != strrchr(str, 'e' + 256)) {
    test_msgbilan("strrchr", 0);
    return (1);
  }
  test_msgbilan("strrchr", 1);
  return (0);
}

static int is_same_signe(int a, int b) {
  return (a < 0 && b < 0) || (a > 0 && b > 0) || (!a && !b);
}

int test_ft_strncmp(void) {

  if (!is_same_signe(
          ft_strncmp("Test de la fonction", "Test de la fonction!", 0),
          strncmp("Test de la fonction", "Test de la fonction!", 0)) ||
      !is_same_signe(
          ft_strncmp("Test de la fonction", "Test de la fonction!", 24),
          strncmp("Test de la fonction", "Test de la fonction!", 24)) ||
      !is_same_signe(
          ft_strncmp("Test de la fonction", "Test de la fonction!", 12),
          strncmp("Test de la fonction", "Test de la fonction!", 12)) ||
      !is_same_signe(ft_strncmp("", "", 12), 0)) {
    test_msgbilan("strncmp", 0);
    return (1);
  }
  test_msgbilan("strncmp", 1);

  return (0);
}

int test_ft_memchr(void) {
  if (ft_memchr("Test de la fonction!", 't', 2) ||
      strcmp(ft_memchr("Test de la fonction!", 't', 28),
             memchr("Test de la fonction!", 't', 28)) != 0) {
    test_msgbilan("memchr", 0);
    return (1);
  }
  test_msgbilan("memchr", 1);
  return (0);
}

int test_ft_memcmp(void) {
  char *str1 = "Zest";
  char *str2 = "ZeSt";
  int n;

  n = 2;
  while (n <= 3) {
    if (memcmp(str1, str2, n) != ft_memcmp(str1, str2, n)) {
      test_msgbilan("memcmp", 0);
      return (1);
    }
    n++;
  }
  /*
  //Eliminé car la fonction de base affiche un warning dans la console, ce qui
  pollue le visuel if (memcmp("", str2, n) != ft_memcmp("", str2, n))
  {
          test_msgbilan("memcmp", 0);
          return (1);
  }
  if (memcmp(str1, "", n) != ft_memcmp(str1, "", n))
  {
          test_msgbilan("memcmp", 0);
          return (1);
  }
  */
  test_msgbilan("memcmp", 1);
  return (0);
}

int test_ft_strnstr(void) {
  char *big = "ceci est la botte de foin.";
  char *little = "est";

  if (strcmp(ft_strnstr(big, little, 30), "est la botte de foin.") != 0 ||
      ft_strnstr(big, little, 4) != NULL) {
    test_msgbilan("strnstr", 0);
    return (1);
  }
  test_msgbilan("strnstr", 1);
  return (0);
}

int test_ft_atoi(void) {
  if (ft_atoi("test") != atoi("test") || ft_atoi("-12") != atoi("-12") ||
      ft_atoi("2147483647") != atoi("2147483647") ||
      ft_atoi("-2147483648") != atoi("-2147483648")) {
    test_msgbilan("atoi", 0);
    return (1);
  }
  test_msgbilan("atoi", 1);
  return (0);
}

int test_ft_calloc(void) {
  char *ptr;
  size_t nmemb;
  size_t i;

  nmemb = 6;
  ptr = ft_calloc(nmemb, sizeof(char));
  i = 0;
  while (i < nmemb) {
    if (ptr[i]) {
      test_msgbilan("calloc", 0);
      return (1);
    }
    ++i;
  }
  free(ptr);
  test_msgbilan("calloc", 1);
  return (0);
}

int test_ft_strdup(void) {
  char *cpy;
  char *cpy1;

  cpy = ft_strdup("Toto123");
  cpy1 = ft_strdup("");
  if (!cpy || !cpy1) {
    test_msgbilan("strdup", 2);
    return (1);
  }
  if (strcmp(cpy, "Toto123") != 0 || strcmp(cpy1, "") != 0) {
    free(cpy);
    free(cpy1);
    test_msgbilan("strdup", 0);
    return (1);
  }
  free(cpy);
  free(cpy1);
  test_msgbilan("strdup", 1);
  return (0);
}

int test_ft_substr(void) {
  char *sub;

  sub = ft_substr((const char *)"Ceci est la chaine d'origine", 6, 4);
  if (!sub) {
    test_msgbilan("substr", 2);
    return (1);
  }
  if (strcmp(sub, "st l") != 0) {
    free(sub);
    test_msgbilan("substr", 0);
    return (1);
  }
  free(sub);
  test_msgbilan("substr", 1);
  return (0);
}

int test_ft_strjoin(void) {
  char *s1 = "Premiere chaine de caractere!";
  char *s2 = "Seconde chaine de caractere!";
  char *s3;
  char *s4;

  s3 = ft_strjoin(s1, s2);
  s4 = ft_strjoin(s1, "");
  if (!s3 || !s4) {
    test_msgbilan("strjoin", 2);
    return (1);
  }
  if (strcmp(s3, "Premiere chaine de caractere!Seconde chaine de caractere!") !=
          0 ||
      strcmp(s4, "Premiere chaine de caractere!") != 0) {
    free(s3);
    free(s4);
    test_msgbilan("strjoin", 0);
    return (1);
  }
  free(s3);
  free(s4);
  test_msgbilan("strjoin", 1);
  return (0);
}

int test_ft_strtrim(void) {
  char *s1 = ".. ..1.Chaine a tester!..   .";
  char *s2;
  char const *set = ". ,1!w";

  s2 = ft_strtrim(s1, set);
  if (!s2) {
    test_msgbilan("strtrim", 2);
    return (1);
  }
  if (strcmp(s2, "Chaine a tester") != 0) {
    free(s2);
    test_msgbilan("strtrim", 0);
    return (1);
  }
  free(s2);
  test_msgbilan("strtrim", 1);
  return (0);
}

int test_ft_split(void) {
  char *scr;
  char **table;
  int i;
  int j;

  scr = " Bonjour, test split_";
  table = ft_split(scr, ' ');
  if (!table) {
    test_msgbilan("split", 2);
    return (1);
  }
  if (!table[0] || strcmp(table[0], "Bonjour,") != 0 || !table[1] ||
      strcmp(table[1], "test") != 0 || !table[2] ||
      strcmp(table[2], "split_") != 0 || table[3]) {
    j = 0;
    while (table[j])
      j++;
    j--;
    while (j >= 0)
      free(table[j--]);
    free(table);
    test_msgbilan("split", 0);
    return (1);
  }
  j = 0;
  while (table[j])
    j++;
  j--;
  while (j >= 0)
    free(table[j--]);
  free(table);
  test_msgbilan("split", 1);
  return (0);
}

int test_ft_itoa(void) {
  char *str;
  char *str1;
  char *str2;

  str = ft_itoa(-2147483648);
  str1 = ft_itoa(2147483647);
  str2 = ft_itoa(0);
  if (!str || !str1 || !str2) {
    if (!str)
      free(str);
    if (!str1)
      free(str1);
    if (!str2)
      free(str2);
    test_msgbilan("itoa", 2);
    return (1);
  }
  if (strcmp(str, "-2147483648") != 0 || strcmp(str1, "2147483647") != 0 ||
      strcmp(str2, "0") != 0) {
    free(str);
    free(str1);
    free(str2);
    test_msgbilan("itoa", 0);
    return (1);
  }
  test_msgbilan("itoa", 1);
  free(str);
  free(str1);
  free(str2);
  return (0);
}

static char ft_strmapi_test(unsigned int i, char c) { return (c + i); }
int test_ft_strmapi(void) {
  char *str;

  str = ft_strmapi("abcde", &ft_strmapi_test);
  if (!str) {
    test_msgbilan("strmapi", 2);
    return (1);
  }

  if (strcmp(str, "acegi") != 0) {
    free(str);
    test_msgbilan("strmapi", 0);
    return (1);
  }
  free(str);
  test_msgbilan("strmapi", 1);
  return (0);
}

static void ft_striteri_test(unsigned int i, char *c) { *c += i; }
int test_ft_striteri(void) {
  char str[] = "abcde";

  ft_striteri(str, &ft_striteri_test);
  if (strcmp(str, "acegi") != 0) {
    test_msgbilan("striteri", 0);
    return (1);
  }
  test_msgbilan("striteri", 1);
  return (0);
}
