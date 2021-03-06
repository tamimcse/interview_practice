/*
https://leetcode.com/problems/guess-number-higher-or-lower/
*/
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n){
	int start = 1, end = n, res;
  long mid;
  
  while (end >= start) {
    mid = ((long)start + end) >> 1;
    res = guess (mid);
    if (!res)
      return mid;
    else if (res == 1)
      start = mid + 1;
    else
      end = mid - 1;
  }
  return mid;
}
