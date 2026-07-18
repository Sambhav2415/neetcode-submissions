class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int k = hand.size();
        if(k%groupSize !=0){
            return false;
        }
        map<int, int> freq;
        sort(hand.begin(),hand.end());
        for(int num: hand){
            if(!freq.count(num)){
                freq[num] =0 ;
            }
            freq[num]++;
        }

        while(!freq.empty()){
            int start = freq.begin()->first;
            for(int i=0;i<groupSize;i++){
                int num = start + i;
                if(!freq.count(num)){
                    return false;
                }
                freq[num]--;
                if(freq[num]==0){
                    freq.erase(num);
                }
            }
        }

        return true;
    }
};
