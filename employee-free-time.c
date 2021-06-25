/*
https://leetcode.com/problems/employee-free-time/

We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

(Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined).  Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.

 

Example 1:

Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation: There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.
Example 2:

Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output: [[5,6],[7,9]]
 

Constraints:

1 <= schedule.length , schedule[i].length <= 50
0 <= schedule[i].start < schedule[i].end <= 10^8


My current solution gets TLE..
*/
/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
      int start = 100000001, end = -1, i;
      
      for (auto e : schedule) {
        if (e.begin()->start < start)
          start = e.begin()->start;
        if (e.back().end > end)
          end = e.back().end;
      }
      
      int arr_len = end - start + 1;
      int *cnt = (int *) calloc (arr_len, sizeof (*cnt));
      
      for (auto s : schedule) {
        for (auto i : s) {
          cnt[i.start - start] += 1;
          cnt[i.end - start] -= 1;
        }
      }
      
      for (i = 1; i < arr_len; i++) {
        cnt[i] += cnt[i-1];
      }
      
      vector<Interval> res;
      for (i = 0; i < arr_len - 1; i++) {
        if (!cnt[i] && cnt[i-1]) {
          Interval intv;
          intv.start = i + start;
          res.push_back(intv);
        }
        if (!cnt[i] && cnt[i+1]) {
          res.back().end = i + 1 + start;
        }
      }
      return res;
    }
};
