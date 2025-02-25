#include<bits/stdc++.h>
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
    system(("copy " + dummy_input + " " + test_input).c_str());

    // cout <<"DEBUG" <<  test_input << endl;
    
    string dummy_output = root + "\\dummy.out";
    string test_output = FolderDirectory + "\\" + Problem_Name + ".OUT";
    system(("copy " + dummy_output + " " + test_output).c_str());
}

int main(){
    // chạy file generator 
    // file Generator chép input + output vào 2 file dummy
    // dummy.inp
    // dummy.out

    const string generatorFile = "generator.exe";
    const string SolutionFile = "Solution.exe";

    for(int i = 1 ; i <= Num_Test ; i++){
        system((generatorFile + " " + toString(i)).c_str());
        system((SolutionFile + " " + toString(i)).c_str());
        doCopy(i);
    }
    
    return 0;
}