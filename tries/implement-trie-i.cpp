#include <iostream>
using namespace std;

struct Node {
    Node* links[26];
    bool eow; // flag for marking the end of word

    bool containsKey(char ch) {
        return links[ch-'a']!=NULL;
    }

    // insert a new node with a specific key (letter) to the Trie
    void put(char ch,Node* node) {
        links[ch-'a'] = node;
    }

    // get the node associated to a specific key (letter)
    Node* get(char ch) {
        return links[ch-'a'];
    }

    // mark the end of the word 
    void setEnd() {
        eow = true;
    }

    // check is the key is the end of the word or not
    bool isEnd() {
        return eow;
    }
};

class Trie {
    private: 
        Node* root;
    public:
        Trie() {
            root = new Node();
        }

        // insert word into the Trie
        // time complexity : O(len) where len is length of the word
        void insert(string word) {
            Node* node = root;
            for (int i=0;i<word.length();i++) {
                if (!node->containsKey(word[i])) {
                    node->put(word[i],new Node());
                }
                node = node->get(word[i]);
            }
            node->setEnd();
        }

        // search for the word within the Trie
        bool search(string word) {
            Node* node = root;
            for (int i=0;i<word.length();i++) {
                if (!node->containsKey(word[i])) {
                    return false;
                }
                node = node->get(word[i]);
            }
            return node->isEnd();
        }

        // return whether any word with the given prefix
        bool startsWith(string prefix) {
            Node* node = root;
            for (int i=0;i<prefix.length();i++) {
                if (!node->containsKey(prefix[i])) {
                    return false;
                }
                node = node->get(prefix[i]);
            }
            return true;
        }
};

int main() {
    Trie trie;
    cout << "Inserting words: Striver, Striving, String, Strike" << endl;
    trie.insert("striver");
    trie.insert("striving");
    trie.insert("string");
    trie.insert("strike");
    
    cout << "Search if Strawberry exists in trie: " <<
    (trie.search("strawberry") ? "True" : "False")<< endl;
    
    cout << "Search if Strike exists in trie: " <<
   ( trie.search("strike") ? "True" : "False" )<< endl;
    
    cout << "If words is Trie start with Stri: " <<
    (trie.startsWith("stri") ? "True" : "False" )<< endl;

    return 0;
}