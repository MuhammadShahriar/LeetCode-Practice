class Trie {
public:
    struct vertex {
        int next[26];
        bool leaf = false;
        
        vertex() {
            fill(begin(next), end(next), -1);
        }
    };
    
    vector<vertex> trie;
    
    Trie() {
        trie.clear();
        trie.emplace_back();
    }
    
    void insert(string word) {
        int v = 0;
        for ( auto ch : word ) {
            int c;
            char d = ch;
            if ( isupper(d) ) d = tolower(d);
            c = d - 'a';
            
            if ( trie[v].next[c] == -1 ) {
                trie[v].next[c] = trie.size();
                trie.emplace_back();
            }
            
            v = trie[v].next[c];
        }
        
        trie[v].leaf = true;
    }
    
    bool search(string word) {
        int v = 0;
        for ( auto ch : word ) {
            int c;
            char d = ch;
            if ( isupper(d) ) d = tolower(d);
            c = d - 'a';
            
            if ( trie[v].next[c] == -1 ) {
                return false;
            }
            
            v = trie[v].next[c];
        }
        
        return trie[v].leaf;
        
    }
    
    bool startsWith(string prefix) {
        int v = 0;
        for ( auto ch : prefix ) {
            int c;
            char d = ch;
            if ( isupper(d) ) d = tolower(d);
            c = d - 'a';
            
            if ( trie[v].next[c] == -1 ) {
                return false;
            }
            
            v = trie[v].next[c];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */