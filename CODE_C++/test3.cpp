#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="a   god   example";
    int i=0,j;
    // while(cin>>s){
        for(j=0;j<s.size();j++){
            if(s[j]!=' '){
                if(i!=0){
                    s[i++]=' ';
                }
                while(s[j]!=' '&&j<s.size()){
                    s[i++]=s[j++];
                }
            }
        }
    // }
    s.resize(i);
    cout<<s<<i;
    return 0;
}