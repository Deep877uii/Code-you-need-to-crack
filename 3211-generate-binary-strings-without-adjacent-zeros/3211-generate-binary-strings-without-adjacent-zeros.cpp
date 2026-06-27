class Solution {
public:


bool isValid(string &str){
    for(int i = 0 ; i<str.size()-1; i++){
        if(str[i] == '0' && str[i+1] == '0') return false;
    }
    return true;
}
vector<string>result;
void solve(string &curr , int n ){

    if(curr.length()==n){
        if(isValid(curr)){
        result.push_back(curr);
        }
        return ;
    }
    curr.push_back('1');
    solve(curr,n);
    curr.pop_back();

    curr.push_back('0');
    solve(curr,n);
    curr.pop_back();

}
    vector<string> validStrings(int n) {
        string curr ="";
        solve(curr,n);
        return result;
    }
};