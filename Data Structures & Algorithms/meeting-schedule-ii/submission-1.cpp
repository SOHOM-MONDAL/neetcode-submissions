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
        if (intervals.empty()) return 0;
        priority_queue<int , vector<int> , greater<int>> pq;
        sort(intervals.begin() ,intervals.end() , [](auto const & a , auto const & b){
            return a.start < b.start;
        });
        pq.push(intervals[0].end);
        for(int i = 1 ; i < intervals.size() ; i++){
            if(pq.top() <= intervals[i].start){
                pq.pop();
            }
            pq.push(intervals[i].end);
        }
        return pq.size();

    }
};
