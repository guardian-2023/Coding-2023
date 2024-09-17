struct Trie {
    bool isEndOfWord;
    unordered_map<char, Trie*> map;
};

Trie* getNewTrieNode()
{
    Trie* node = new Trie;
    node->isEndOfWord = false;
    return node;
}

void insert(Trie*& root, const string& str)
{
    if (root == nullptr)
        root = getNewTrieNode();

    Trie* temp = root;
    for (int i = 0; i < str.length(); i++) {
        char x = str[i];
        if (temp->map.find(x) == temp->map.end())
            temp->map[x] = getNewTrieNode();
        temp = temp->map[x];
    }
    temp->isEndOfWord = true;
}

bool search(Trie* root, const string& str)
{
    if (root == nullptr)
        return false;
    Trie* temp = root;
    for (int i = 0; i < str.length(); i++) {
        temp = temp->map[str[i]];
        if (temp == nullptr)
            return false;
    }
    return temp->isEndOfWord;
}

Trie* root = nullptr;
for(int i=0;i<words.size();i++){
    insert(root, words[i]);
}
// cout << search(root, "bcd") << " ";
