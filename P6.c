#include <ctype.h>
#include <stdio.h>

int main() {
  char eng[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
  char text[1000], map[26];
  int freq[26] = {0};

  printf("Enter ciphertext: ");
  fgets(text, sizeof(text), stdin);

  for (int i = 0; text[i]; i++)
    if (isalpha(text[i]))
      freq[toupper(text[i]) - 'A']++;

  for (int r = 0; r < 26; r++) {
    int best = 0;
    for (int i = 1; i < 26; i++)
      if (freq[i] > freq[best])
        best = i;
    map[best] = eng[r];
    printf("%c -> %c\n", 'A' + best, eng[r]);
    freq[best] = -1;
  }

  for (int i = 0; text[i]; i++)
    if (isalpha(text[i])) {
      char m = map[toupper(text[i]) - 'A'];
      text[i] = islower(text[i]) ? tolower(m) : m;
    }

  printf("Decrypted: %s", text);
  return 0;
}