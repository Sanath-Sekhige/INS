#include <ctype.h>
#include <stdio.h>
#include <string.h>

void vigenere(char text[], char key[], int dir) {
  int k = strlen(key);
  for (int i = 0, j = 0; text[i]; i++)
    if (isalpha(text[i])) {
      char base = isupper(text[i]) ? 'A' : 'a';
      int shift = toupper(key[j++ % k]) - 'A';
      text[i] = (text[i] - base + dir * shift + 26) % 26 + base;
    }
}

int main() {
  char msg[100], key[100];

  printf("Enter plaintext: ");
  fgets(msg, sizeof(msg), stdin);
  msg[strcspn(msg, "\n")] = '\0';

  printf("Enter key: ");
  fgets(key, sizeof(key), stdin);
  key[strcspn(key, "\n")] = '\0';

  vigenere(msg, key, 1);
  printf("Encrypted: %s\n", msg);

  vigenere(msg, key, -1);
  printf("Decrypted: %s\n", msg);
  return 0;
}