class Solution {
public:
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
        else return false;
    }
    int maxVowels(string s, int k) {
        int l=0, r=k-1, maxi=0, count = 0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i])) count++;
        }
        maxi=count;
        while(r<s.size()){
            if(isVowel(s[l])) count--;
            l++;
            r++;
            if(isVowel(s[r])) count++;
            maxi=max(maxi,count);
        }
        return maxi;  
    }
};