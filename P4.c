#include <stdio.h>
#include <string.h>

int main() {
  char text[100], cipher[100], plain[100];
  int key, k = 0;

  printf("Enter plaintext: ");
  fgets(text, sizeof(text), stdin);
  text[strcspn(text, "\n")] = '\0';

  printf("Enter key (columns): ");
  scanf("%d", &key);
  int len = strlen(text);

  for (int col = 0; col < key; col++)
    for (int i = col; i < len; i += key)
      cipher[k++] = text[i];
  cipher[len] = '\0';
  printf("Ciphertext: %s\n", cipher);

  k = 0;
  for (int col = 0; col < key; col++)
    for (int i = col; i < len; i += key)
      plain[i] = cipher[k++];
  plain[len] = '\0';
  printf("Decrypted: %s\n", plain);
  return 0;
}