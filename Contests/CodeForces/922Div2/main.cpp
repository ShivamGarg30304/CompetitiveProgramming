#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr; // Change NULL to nullptr
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0'); // Added a semicolon at the end of this line
    }

    void insertUtil(TrieNode* root, string word) {
        // Base Case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }
        // assumption word will be in Caps
        char ch = word[0];
        if (ch < 'A' || ch > 'Z') // Check if character is uppercase letter
            return;

        int index = ch - 'A';
        TrieNode* child;

        // Present
        if (root->children[index] != nullptr) { // Change NULL to nullptr
            child = root->children[index];
        }
        else {
            // Absent 
            child = new TrieNode(ch);
            root->children[index] = child;
        }

        // RECURSION
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        // Base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

        // Check if all characters are uppercase letters
        for (char ch : word) {
            if (ch < 'A' || ch > 'Z')
                return false;
        }

        char ch = word[0];
        int index = ch - 'A';
        TrieNode* child;

        // Present
        if (root->children[index] != nullptr) { // Change NULL to nullptr
            child = root->children[index];
        }
        else {
            //absent
            return false;
        }

        // Recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }
};

int main() {
    Trie* t = new Trie();

    t->insertWord("abcd");
    cout << "Present or Not " << t->searchWord("abcd") << endl;

    return 0;
}