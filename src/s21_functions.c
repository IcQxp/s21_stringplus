#include "s21_string.h"
#include "stdio.h"
int main(){

const char a[] = "big boy abudabi";
printf("%d",s21_strlen(a));
printf("\n");
printf(s21_memchr(a,'b',4));
printf("\n");
//segfault
// printf(s21_memchr(a,'o',4));
printf("\n");

char *testcpy1 = "schesrdsfdsfdsfesr";
int testcpy2 = s21_strlen(testcpy1);
char testcpy3[50] = {};
printf(testcpy3);
s21_memcpy(testcpy3, testcpy1, testcpy2 + 1);
printf(testcpy3);
printf("\ntest-memset\n");

char testmemset[50] = " A rang";
s21_memset(testmemset, 's', 2);
printf(testmemset);

printf("\ntest-strncat\n");


char testcat[50] = "123 ";
char testcat2[50] = "456 ";
printf(s21_strncat(testcat,testcat2,s21_strlen(testcat)+s21_strlen(testcat2)));
  return 1;
}

void* s21_memchr(const void* str, int c, s21_size_t n) // Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n байтах строки, на которую указывает аргумент str.
{
  const unsigned char* char_ptr;
  char_ptr = (const unsigned char*)str;
  int flag = 0;

  while (n-- && !flag) {
    if (*char_ptr == (unsigned char)c) {
      flag = 1;
      break;
    }
    char_ptr++;
  }

  return flag ? (void*)char_ptr : s21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) // Сравнивает первые n байтов str1 и str2.
{
  const unsigned char* s1 = (const unsigned char*)str1;
  const unsigned char* s2 = (const unsigned char*)str2;
  int dif = 0;

  while (n-- > 0) {
    if (*s1 != *s2) {
      dif = (int)s1[0] - (int)s2[0];
      break;
    }
    s1++;
    s2++;
  }
  return dif;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) // Копирует n символов из src в dest.
{
 unsigned char* dest_ptr = (unsigned char*)dest;
  const unsigned char* src_ptr = (const unsigned char*)src;

  while (n--) *dest_ptr++ = *src_ptr++;
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) // Копирует символ c (беззнаковый тип) в первые n символов строки, на которую указывает аргумент str.
{
  unsigned char* str_ptr = (unsigned char*)str;
  while (n--) *str_ptr++ = (unsigned char)c;
  return str;
}


char *s21_strncat(char *dest, const char *src, s21_size_t n) // Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest, длиной до n символов.
 {
  s21_size_t i;
  s21_size_t j;

  i = 0;
  j = s21_strlen(dest);
  while (i < n && src[i]) {
    dest[j + i] = src[i];
    i++;
  }
  dest[j + i] = '\0';
  return (dest);
}

char* s21_strcpy(char* dest, const char* src) {
 return s21_memcpy(dest, src, s21_strlen(src) + 1);
}

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.
char* s21_strchr(const char* str, int c) {
 char* res = s21_NULL;
  c = (char)c;
  for (s21_size_t i = 0; i <= s21_strlen(str); i++) {
    if (str[i] == c) {
      res = (char*)&str[i];
      break;
    }
  }
  return res;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n); // Сравнивает не более первых n байтов str1 и str2.
char *s21_strncpy(char *dest, const char *src, s21_size_t n);      // Копирует до n символов из строки, на которую указывает src, в dest.
s21_size_t s21_strcspn(const char *str1, const char *str2);        // Вычисляет длину начального сегмента str1, который полностью состоит из символов, не входящих в str2.
char *s21_strerror(int errnum);                                    // Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает указатель на строку с сообщением об ошибке. Нужно объявить макросы, содержащие массивы сообщений об ошибке для операционных систем mac и linux. Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС осуществляется с помощью директив.

s21_size_t s21_strlen(const char *str)                     // Вычисляет длину строки str, не включая завершающий нулевой символ.
{
  s21_size_t len = 0;
  if (str) {
    while (str[len]) len++;
  }
  return len;
}
char *s21_strpbrk(const char *str1, const char *str2);      // Находит первый символ в строке str1, который соответствует любому символу, указанному в str2.
char *s21_strrchr(const char *str, int c);                  // Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.
char *s21_strstr(const char *haystack, const char *needle); // Находит первое вхождение всей строки needle (не включая завершающий нулевой символ), которая появляется в строке haystack.
char *s21_strtok(char *str, const char *delim);             // Разбивает строку str на ряд токенов, разделенных delim.