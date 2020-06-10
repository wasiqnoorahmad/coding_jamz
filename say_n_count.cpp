/* The count-and-say sequence is the sequence of integers with the first five
terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say
sequence. You can do so recursively, in other words from the previous member
read off the digits, counting the number of digits in groups of the same digit.

Note: Each term of the sequence of integers will be represented as a string.



Example 1:

Input: 1
Output: "1"
Explanation: This is the base case.

Example 2:

Input: 4
Output: "1211" */

#include <bits/stdc++.h>
using namespace std;

string count_and_say(int n) {
  int curr = 1, walk = 0;
  string sequence = "1", tmp;

  for (curr; curr < n; curr++) {
    walk = 0, tmp = "";
    while (walk < sequence.length()) {
      if (walk + 1 < sequence.length() && sequence[walk] == '1' &&
          sequence[walk + 1] == '1') {
        cout << "Found 11" << endl;
        tmp += "21", walk += 2;
      } else if (sequence[walk] == '2') {
        tmp += "12", walk++;
      } else if (walk + 1 < sequence.length() && sequence[walk] == '2' &&
                 sequence[walk + 1] == '1') {
        cout << "Found 21" << endl;
        tmp += "1211", walk += 2;
      } else if (sequence[walk] == '1') {
        cout << "Found 1" << endl;
        tmp += "11", walk++;
      }
    }
    sequence = tmp;
    cout << curr + 1 << ". " << sequence << endl << flush;
  }
  return sequence;
}

int main(int argc, char const *argv[]) {
  cout << count_and_say(5) << endl;
  return 0;
}
