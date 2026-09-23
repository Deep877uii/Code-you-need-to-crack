class Solution {
public:
    int compress(vector<char>& chars) { 
        int i = 0;
        int index = 0;

        while(i < chars.size()) {

            int j = i;

            while(j < chars.size() && chars[j] == chars[i]) {
                j++;
            }
            int count = j-i ; 
            chars[index++] = chars[i] ;
            if(count>1){
                string temp = to_string(count);
                for(auto it : temp){
                    chars[index++] = it ;
                }
            }
            i = j;
        }
        return index ;
    }
};