#include<bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    set<string>st(wordList.begin(),wordList.end());
    queue<pair<string,int>>q;
    q.push({beginWord,1});
    st.erase(beginWord);
    while(!q.empty()){
        string word=q.front().first;
        int steps= q.front().second;
        q.pop();
        // if targetWord is found
        if(word==endWord){
            return steps;
        }
        for(int i=0;i<word.size();i++){
            char orignial= word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                // if word is found
                if(st.find(word)!= st.end()){
                    st.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i]=orignial;
        }
    }
    return 0;

}
int main(){
   string beginWord ="hit";
   string endWord ="cog";
   vector<string>wordList ={"hot","dot","dog","lot","log","cog"};
   cout<<"the shortest sequence is "<<ladderLength(beginWord,endWord,wordList);

return 0;
}