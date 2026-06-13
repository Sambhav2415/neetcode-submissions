/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const Interval &a,const Interval &b){
            if(a.start == b.start){
                return a.end < b.end;
            }
            return a.start < b.start;
        });
        int room = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(Interval i: intervals){
            int st = i.start;
            int en = i.end;

            while(!minHeap.empty() && st >= minHeap.top()){
                minHeap.pop();
            }
            minHeap.push(en);
            room = max(room, (int)minHeap.size());
        }

        return room;
    }
};
