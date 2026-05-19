// 120. Triangle
// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

// Example 1:

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
// Example 2:

// Input: triangle = [[-10]]
// Output: -10
 

// Constraints:

// 1 <= triangle.length <= 200
// triangle[0].length == 1
// triangle[i].length == triangle[i - 1].length + 1
// -104 <= triangle[i][j] <= 104

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n,0) , cur(n,0);
        for(int j = 0 ; j<n ; j++) front[j]= triangle[n-1][j];
        for(int i = n-2 ; i>=0 ; i--){
            for(int j = i; j>=0 ; j--){
                
         int d = triangle[i][j]+ front[j];
         int dr = triangle[i][j]+ front[j+1];

          cur[j] = min(d,dr) ;
            }
            front = cur ;
        }
        return front[0];
    }
};
