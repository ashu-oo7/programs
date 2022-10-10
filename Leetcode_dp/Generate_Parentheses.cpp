// https://leetcode.com/problems/generate-parentheses/submissions/
class Solution {
public:
    vector<string>sol;
    void solve(int op,int cl,int n,string s){
        if(op == n && cl == n){
            sol.push_back(s);
            return;
        }
        if(op < n)
            solve(op+1,cl,n,s+'(');
        if(cl < op)
        solve(op,cl+1,n,s+')');
    }
    vector<string> generateParenthesis(int n) {
        solve(0,0,n,"");
        return sol;
    }
};