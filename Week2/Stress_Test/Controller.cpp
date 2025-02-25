#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

const string Problem_Name = "TEST";
const int Num_Test = 10;

string current_working_directory()
{
    char working_directory[MAX_PATH+1];
    GetCurrentDirectoryA( sizeof(working_directory), working_directory ) ; // **** win32 specific ****
    return working_directory ;
}

string toString(int x){
    string result = "";
    while(x > 0){
        result += (x % 10) + '0';
        x /= 10;
    }   
    reverse(result.begin() , result.end());
    return result;
}

void doCopy(int numTest){
    string root = current_working_directory();

    string FolderDirectory = root + "\\Test" + toString(numTest);
    cout << FolderDirectory << endl;
    system(("mkdir " + FolderDirectory).c_str());
    
    string dummy_input = root + "\\dummy.inp";
    string test_input = FolderDirectory + "\\" + Problem_Name + ".INP";
    system(("copy " + test_input + " " + dummy_input).c_str());

    string dummy_output = root + "\\dummy.ans";
    string test_output = FolderDirectory + "\\" + Problem_Name + ".OUT";
    system(("copy " + test_output + " " + dummy_output).c_str());
}

int main(){

    const string codeFile = "sort.py";

    for(int i = 1 ; i <= Num_Test ; i++){
        doCopy(i);
        system((codeFile + " " + toString(i)).c_str());
        if(system("fc dummy.out dummy.ans") != 0){
            cout << "Code Sai roi cu em oi" << endl;
            return 0;
        }
    }
    
    return 0;
}