class Solution {
public:
    int toDays(string date){
        int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int month = stoi(date.substr(0,2));
        int day = stoi(date.substr(3,2));
        for(int i=0;i<month-1;i++){
            day += days[i];
        }
        return day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int start = max(toDays(arriveAlice),toDays(arriveBob));
        int end = min(toDays(leaveAlice),toDays(leaveBob));
        int together = end-start+1;
        if(together>=0) return together;
        else return 0;  
    }
};