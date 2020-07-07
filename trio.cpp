/* This program implements Trio tree */
#include <bits/stdc++.h>
using namespace std;

#define MAX_CHAR 26

class Trio {
private:
  typedef struct Node {
    Node *alphabets[MAX_CHAR];
    bool is_end;
  } Node;

  Node *root;

  Node *get_node(void) {
    Node *node = new Node;
    node->is_end = false;
    for (int i = 0; i < MAX_CHAR; i++) {
      node->alphabets[i] = NULL;
    }
    return node;
  }

public:
  Trio() { root = get_node(); }

  /** Inserts a word into the trie. */
  void insert(string word) {
    Node *walk = root;
    int index = 0;

    for (int i = 0; i < word.length(); i++) {
      index = word[i] - 'a';

      if (!walk->alphabets[index])
        walk->alphabets[index] = get_node();

      walk = walk->alphabets[index];
    }

    walk->is_end = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    Node *walk = root;
    int index = 0;

    for (int i = 0; i < word.length(); i++) {
      index = word[i] - 'a';

      if (!walk->alphabets[index])
        return false;

      walk = walk->alphabets[index];
    }

    return walk != NULL && walk->is_end == true;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool starts_with(string prefix) {
    Node *walk = root;
    int index = 0;

    for (int i = 0; i < prefix.length(); i++) {
      index = prefix[i] - 'a';

      if (!walk->alphabets[index])
        return false;

      walk = walk->alphabets[index];
    }

    return true;
  }
};

int main(int argc, char const *argv[]) {
  Trio trio = Trio();

  trio.insert("apple");
  cout << trio.search("apple") << endl;    // returns true
  cout << trio.search("app") << endl;      // returns false
  cout << trio.starts_with("app") << endl; // returns true
  trio.insert("app");
  cout << trio.search("app") << endl; // returns true
  return 0;
}
