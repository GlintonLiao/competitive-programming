/*
    Dynamic
*/
struct Node {
    // mark as tail node, may be id, cnt, ...
    int id;
    Node* son[26];
    Node() {
        id = -1;
        for (int i = 0; i < 26; i++) son[i] = NULL;
    }
};

// dummy
Node* root;

void insert(string& word, int id) {
    auto p = root;
    for (auto& c : word) {
        int u = c - 'a';
        if (!p->son[u]) p->son[u] = new Node();
        p = p->son[u];
    }
    p->id = id;
}
