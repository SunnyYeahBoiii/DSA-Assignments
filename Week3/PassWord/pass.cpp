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

bool isNumber(char x){
    return '0' <= x && x <= '9';
}

bool isUpper(char x){
    return 'A' <= x && x <= 'Z';
}

bool isLower(char x){
    return 'a' <= x && x <= 'z';
}

char spec[] = {'!' , '@' , '#' , '$' , '%' , '^' , '&' , '*' , '?' , '_' , '~'};
bool isSpecial(char x){
    for(auto c : spec)
        if(x == c)
            return true;
    return false;
}

char banned[] = {'.' , '\\' , '/' , ' ' , ','};
bool isValid(string s){
    if(s.size() < 8)
        return false;

    for(auto x : s){
        for(auto c : banned)
            if(x == c)
                return false;
    }
    return true;
}

void solve(){
    string s;
    getline(cin , s);

    if(!isValid(s)){
        cout << "KhongHopLe" << endl;
        return;
    }
    
    int BaseScore = 40;
    int Bonus_Excess = 3;
    int Bonus_Upper = 4;
    int Bonus_Number = 5;
    int Bonus_Symbols = 5;
    int Bonus_Combo = 0;

    bool Uppercase = false;
    bool Special_Char = false;
    bool Number = false;

    for(auto x : s){
        if(isNumber(x)){
            Number = true;
        }else if(isUpper(x)){
            Uppercase = true;
        }else if(isSpecial(x)){
            Special_Char = true;
        }
    }

    if(Number + Uppercase + Special_Char == 3)
        Bonus_Combo = 25;
    else if(Number + Uppercase + Special_Char == 2)
        Bonus_Combo = 15;
    else Bonus_Combo = 0;
     
    int Bonus_FlatLower = 0;
    
    bool All_Lowercase = true;
    for(auto x : s){
        if(!isLower(x))
            All_Lowercase = false;
    }

    if(All_Lowercase)
        Bonus_FlatLower = -15;
    else Bonus_FlatLower = 0;
    
    int Bonus_FlatNumber = 0;
    bool All_Number = true;
    for(auto x : s){
        if(!isNumber(x))
            All_Number = false;
    }

    if(All_Number)
        Bonus_FlatNumber = -35;
    else Bonus_FlatNumber = 0;

    int Number_Execess = abs((int)s.size() - 8);

    int Number_Upper = 0;
    for(auto x : s){
        if(isUpper(x))
            Number_Upper++;
    }
    int Number_Numbers = 0;
    for(auto x : s){
        if(isNumber(x))
        Number_Numbers++;
    }
    int Number_Symbols = 0;
    for(auto x : s){
        if(isSpecial(x))
            Number_Symbols++;
    }

    int score = BaseScore + (Number_Execess*Bonus_Excess) + (Number_Upper*Bonus_Upper) + (Number_Numbers*Bonus_Number) + (Number_Symbols*Bonus_Symbols) + Bonus_Combo + Bonus_FlatLower + Bonus_FlatNumber;

    if(score < 50)
        cout << "Yeu" << endl;
    else if(score < 75)
        cout << "Vua" << endl;
    else if(score < 100)
        cout << "Manh" << endl;
    else cout << "RatManh" << endl;
}

int32_t main(){
    //();
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}