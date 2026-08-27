class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
    int n = s.size();
        if ((int)target.size() != n) return "";

        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        auto nextAtLeast = [&](int ch)->int {
            for (int x = ch; x < 26; ++x) if (cnt[x] > 0) return x;
            return -1;
        };
        auto nextGreater = [&](int ch)->int {
            for (int x = ch + 1; x < 26; ++x) if (cnt[x] > 0) return x;
            return -1;
        };
        auto fillAsc = [&](string &out) {
            for (int x = 0; x < 26; ++x)
                while (cnt[x]--) out.push_back(char('a' + x));
        };

        string ans;
        ans.reserve(n);

        for (int i = 0; i < n; ++i) {
            int need = target[i] - 'a';
            int k = nextAtLeast(need);
            if (k == -1) {
                // backtrack to bump an earlier position
                while (!ans.empty()) {
                    int j = (int)ans.size() - 1;
                    cnt[ans.back() - 'a']++;      // undo
                    ans.pop_back();
                    int g = nextGreater(target[j] - 'a');
                    if (g != -1) {
                        ans.push_back(char('a' + g));
                        cnt[g]--;
                        fillAsc(ans);
                        return ans;
                    }
                }
                return "";
            }
            if (k == need) {
                cnt[k]--;
                ans.push_back(char('a' + k));
                continue;
            }
            // k > need: place it and finish minimally
            ans.push_back(char('a' + k));
            cnt[k]--;
            fillAsc(ans);
            return ans;
        }

        // ans == target; need to bump some earlier position
        for (int i = n - 1; i >= 0; --i) {
            cnt[ans[i] - 'a']++;
            string pref = ans.substr(0, i);
            int g = nextGreater(target[i] - 'a');
            if (g != -1) {
                pref.push_back(char('a' + g));
                cnt[g]--;
                fillAsc(pref);
                return pref;
            }
        }
        return "";
    }
};