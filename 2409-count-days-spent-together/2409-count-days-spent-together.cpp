class Solution {
public:

    int findDays(string date,vector<int>&monsum){
        int month = stoi(date.substr(0,2));
        int day   = stoi(date.substr(3));

        return monsum[month-1] + day ;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>month ={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int>monsum(13,0);
        monsum[1] = 31 ;

        for(int i =2 ; i <=12 ; i++){
            monsum[i]=monsum[i-1]+month[i-1];
        }
        int arriveAliceDay = findDays(arriveAlice,monsum);
        int leaveAliceDay  = findDays(leaveAlice,monsum) ;
        int arriveBobDay   = findDays(arriveBob,monsum)  ;
        int leaveBobDay    = findDays(leaveBob,monsum)   ;

        int overlap = min(leaveAliceDay,leaveBobDay) - max(arriveAliceDay,arriveBobDay) + 1;

        return overlap<0 ? 0 : overlap ;
    }
};