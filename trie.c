#include<stdio.h>


typedef struct Trie {
    char letter;
    struct Trie *next[256];
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie *t = malloc(sizeof(Trie));
    t->letter = '*';
    int i;
    for (i = 0; i < 256; i++)
        t->next[i] = NULL;
    return t;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    int i, n;
    char c;
    Trie *t = obj;

    n = strlen(word);
    
    for (i = 0; i < n; i++) {
        Trie *nt;
        c = word[i];
        if (t->next[c] == 0) {
            nt = trieCreate();
            nt->letter = c;
            t->next[c] = nt;
        } else {
            nt = t->next[c];
            assert(nt->letter == c);
        }
        t = nt;
    }
    Trie *end = trieCreate();
    end->letter = '*';
    t->next['*'] = end;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    int i;
    char c;
    int n = strlen(word);
    Trie *t = obj;
    
    for (i = 0; i < n; i++) {
        c = word[i];
        if (t->next[c]) {
            t = t->next[c];
            assert(t->letter == c);
        } else {
            return false;
        }
    }
    if (t->next['*'] == NULL)
        return false;
    return true;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * word) {
    int i;
    char c;
    int n = strlen(word);
    Trie *t = obj;
    
    for (i = 0; i < n; i++) {
        c = word[i];
        if (t->next[c]) {
            t = t->next[c];
            assert(t->letter == c);
        } else {
            return false;
        }
    }
    return true;
}

void trieFree(Trie* obj) {
    int i;

    for (i = 0; i < 256; i++) {
        if (obj->next[i] != NULL)
            trieFree(obj->next[i]);
    }
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/

int main(void) {
    puts("Hello World!");
    Trie* obj = trieCreate();
    char* word = "Hypotenuse";
    char* prefix = "Hyp";
    trieInsert(obj, word);
    
    bool param_2 = trieSearch(obj, word);
 
    bool param_3 = trieStartsWith(obj, prefix);
 
    trieFree(obj);
    return 0;
}
