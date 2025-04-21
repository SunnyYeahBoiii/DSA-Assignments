/*
    Cred : SunnyYeahBoi
    It's my last chance (⌐■_■)
    Problem :
*/

#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define endl "\n"
#define NAME "a"

const int MAXN = 1e6 + 5;
const int inf = 1e18;
const int MOD = 1e9 + 7;

void FileInput(){
    if(fopen(NAME".inp" , "r") == NULL)
        freopen(NAME".inp" , "w" , stdout);
    freopen(NAME".inp" , "r" , stdin);
    freopen(NAME".out" , "w" , stdout);
}

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int _data = 0){
        data = _data;
        left = right = nullptr;
    }
};

Node* root = nullptr;

Node* Insert(Node* root , int data){
    if(root == nullptr){
        return new Node(data);
    }

    if(data <= root -> data){
        root -> left = Insert(root -> left , data);
    }else if(data > root -> data){
        root -> right = Insert(root -> right , data);
    }
    return root;
}

int n;

map<int , int> c;

void DFS(Node* root , int cur){
    queue<pair<Node* , int>> q;
    q.push({root , 0});

    while(!q.empty()){
        Node* cur = q.front().first;
        int t = q.front().second;
        q.pop();

        if(c.find(t) == c.end())
            c[t] = cur -> data;

        if(cur -> right)
            q.push({cur -> right , t - 1});
        if(cur -> left)
            q.push({cur -> left , t + 1});
    }
}

void solve(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        int x;
        cin >> x;
        root = Insert(root , x);
    }

    DFS(root , 0);

    vector<int> result;
    for(auto x : c)
        result.push_back(x.second);

    sort(result.begin() , result.end());

    for(auto x : result)
        cout << x << " ";
}

int32_t main(){
    //FileInput();
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}