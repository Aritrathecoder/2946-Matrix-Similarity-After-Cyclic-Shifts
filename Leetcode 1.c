#include<stdio.h>
#include<string.h>
#include<stdbool.h>


bool checkStrings(char* s1, char* s2) {
    int n = strlen(s1);
    
    int even1[26] = {0}, odd1[26] = {0};
    int even2[26] = {0}, odd2[26] = {0};
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            even1[s1[i] - 'a']++;
            even2[s2[i] - 'a']++;
        } else {
            odd1[s1[i] - 'a']++;
            odd2[s2[i] - 'a']++;
        }
}
  for (int i = 0; i < 26; i++) 
  {
        if (even1[i] != even2[i] || odd1[i] != odd2[i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    char s1[] = "abcd";
    char s2[] = "cdab";
    if (checkStrings(s1, s2)) {
        printf("Strings can be made equal\n");
    } else {
        printf("Strings cannot be made equal\n");
    }
    return 0;
}