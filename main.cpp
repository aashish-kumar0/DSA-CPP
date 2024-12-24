#include<iostream>
#include<string>
using namespace std;
void print(int n, int i){
    if(n<i){
        return ;
    }
    else{
        
        cout<<n<<endl;
        print(n-1,i);
    }
}
int main(){
    print(5,1);
    return 0;
}