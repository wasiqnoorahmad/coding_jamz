/* Given a string S, consider all duplicated substrings: (contiguous) substrings
of S that occur 2 or more times.  (The occurrences may overlap.)

Return any duplicated substring that has the longest possible length.  (If S
does not have a duplicated substring, the answer is "".)

Example 1:

Input: "banana"
Output: "ana"

Example 2:

Input: "abcd"
Output: ""

Note:

    2 <= S.length <= 10^5
    S consists of lowercase English letters.

 */
#include <bits/stdc++.h>
using namespace std;

const int prime = 10000007;
vector<int> power;

string rabin_karp(string s, int len) {
  if (len == 0)
    return "";
  int n = s.size(), curr = 0;
  // map hash values to start index of substrings with that hash value (same
  // hash values for different substrings can occur)
  unordered_map<int, vector<int>> hash;

  // compute hash value for first 'len' characters
  for (int i = 0; i < len; i++) {
    curr = (curr * 26 + (s[i] - 'a')) % prime;
  }
  hash[curr] = {0}; // map this initial hash value with index 0 (means substring
                    // of lenght 'len' starting at index 0)

  for (int i = len; i < n; i++) {
    // sliding window to maintain current substring's hash
    curr =
        ((curr - power[len - 1] * (s[i - len] - 'a')) % prime + prime) % prime;
    curr = (curr * 26 + (s[i] - 'a')) % prime;

    // if this new hash does not exist in map then store it with the new start
    // index (i-len+1)
    if (hash.find(curr) == hash.end())
      hash[curr] = {i - len + 1};
    // if hash already exists in map then for all start indices check if any
    // substrings match with the current window of substr
    else {
      for (int index : hash[curr]) {
        if (s.substr(index, len) == s.substr(i - len + 1, len))
          return s.substr(index, len);
      }
      // if none matches (happens when different substrings have same hash
      // value) simply map this new start index for current window to this hash
      // value
      hash[curr].push_back({i - len + 1});
    }
  }
  return ""; // if no duplicates exist
}

string longest_dup_substring(string S) {
  int n = S.size(), left = 0, right = n - 1;
  power = vector<int>(n);

  for (int i = 0; i < n; i++)
    if (i == 0)
      power[i] = 1;
    else
      power[i] = (power[i - 1] * 26) % prime;

  string res;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    string dup = rabin_karp(S, mid);

    if ((int)dup.size() > (int)res.size())
      res = dup, left = mid + 1;
    else
      right = mid - 1;
  }
  return res;
}

int main(int argc, char const *argv[]) {
  string src =
      "moplvidmaagmsiyyrkchbyhivlqwqsjcgtumqscmxrxrvwsnjjvygrelcbjgbpounhuyeall"
      "lginkitfaiviraqcycjmskrozcdqylbuejrgfnquercvghppljmojfvylcxakyjxnampmaky"
      "jbqgwbyokaybcuklkaqzawageypfqhhasetugatdaxpvtevrigynxbqodiyioapgxqknduje"
      "ranxgebnpgsukybyowbxhgpkwjfdywfkpufcxzzqiuglkakibbkobonunnzwbjktykebfcbo"
      "bxdflnyzngheatpcvnhdwkkhnlwnjdnrmjaevqopvinnzgacjkbhvsdsvuuwwhwesgtdzuct"
      "shytyfugdqswvxisyxcxoihfgzxnidnfadphwumtgdfmhjkaryjxvfquucltmuoosamjwqqz"
      "eleaiplwcbbxjxxvgsnonoivbnmiwbnijkzgoenohqncjqnckxbhpvreasdyvffrolobxzrm"
      "rbvwkpdbfvbwwyibydhndmpvqyfmqjwosclwxhgxmwjiksjvsnwupraojuatksjfqkvvfroq"
      "xsraskbdbgtppjrnzpfzabmcczlwynwomebvrihxugvjmtrkzdwuafozjcfqacenabmmxzcu"
      "eyqwvbtslhjeiopgbrbvfbnpmvlnyexopoahgmwplwxnxqzhucdieyvbgtkfmdeocamzenec"
      "qlbhqmdfrvpsqyxvkkyfrbyolzvcpcbkdprttijkzcrgciidavsmrczbollxbkytqjwbiupv"
      "sorvkorfriajdtsowenhpmdtvamkoqacwwlkqfdzorjtepwlemunyrghwlvjgaxbzawmikfh"
      "taniwviqiaeinbsqidetfsdbgsydkxgwoqyztaqmyeefaihmgrbxzyheoegawthcsyyrpyvn"
      "hysynoaikwtvmwathsomddhltxpeuxettpbeftmmyrqclnzwljlpxazrzzdosemwmthcvgwt"
      "xtinffopqxbufjwsvhqamxpydcnpekqhsovvqugqhbgweaiheeicmkdtxltkalexbeftuxvw"
      "nxmqqjeyourvbdfikqnzdipmmmiltjapovlhkpunxljeutwhenrxyfeufmzipqvergdkwptk"
      "ilwzdxlydxbjoxjzxwcfmznfqgoaemrrxuwpfkftwejubxkgjlizljoynvidqwxnvhngqakm"
      "mehtvykbjwrrrjvwnrteeoxmtygiiygynedvfzwkvmffghuduspyyrnftyvsvjstfohwwyxh"
      "mlfmwguxxzgwdzwlnnltpjvnzswhmbzgdwzhvbgkiddhirgljbflgvyksxgnsvztcywpvutq"
      "ryzdeerlildbzmtsgnebvsjetdnfgikrbsktbrdamfccvcptfaaklmcaqmglneebpdxkvcww"
      "pndrjqnpqgbgihsfeotgggkdbvcdwfjanvafvxsvvhzyncwlmqqsmledzfnxxfyvcmhtjrey"
      "kqlrfiqlsqzraqgtmocijejneeezqxbtomkwugapwesrinfiaxwxradnuvbyssqkznwwpsbg"
      "atlsxfhpcidfgzrc";
  cout << longest_dup_substring(src) << endl;
  return 0;
}
