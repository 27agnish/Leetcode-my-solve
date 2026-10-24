class Solution {
public:
    int isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return 1;
        else return 0;
    }
    int maxVowels(string s, int k) {
        int l=0, r=k-1, maxi=0, count = 0;
        for(int i=0;i<k;i++){
            count += isVowel(s[i]); 
        }
        maxi=count;
        while(r<s.size()){
            count -= isVowel(s[l++]);
            count += isVowel(s[++r]);
            maxi=max(maxi,count);
            if(maxi==k) return k;
        }
        return maxi;  
    }
};