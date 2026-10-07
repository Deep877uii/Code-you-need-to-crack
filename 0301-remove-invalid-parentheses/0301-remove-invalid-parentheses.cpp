class Solution {
public:

    void solve(string &s , unordered_set<string>&st,int i , string &curr,int count,int &max_len){
        if(count<0) return;

        if(i== s.size()){
            if(count==0){
                if(curr.length()>max_len){
                    max_len = curr.length() ;
                    st.clear();
                }

                if(curr.length()==max_len){
                    st.insert(curr);
                }
            }
            return ;
        }
        if(s[i]!='(' && s[i]!=')'){
            curr.push_back(s[i]);
            solve(s,st,i+1,curr,count,max_len);
            curr.pop_back();
            return;
        }
        curr.push_back(s[i]);
        solve(s,st,i+1,curr,count + (s[i]=='('?1 : -1),max_len);

        curr.pop_back();
        solve(s,st,i+1,curr,count,max_len);
    }

    vector<string> removeInvalidParentheses(string s) {
        int n = s.size() ; 
        unordered_set<string>st ;
        st.clear();

        int max_len = 0 ;
        string curr = "" ;
        solve(s,st,0,curr,0,max_len);

        return vector<string>(begin(st),end(st));
    }
};