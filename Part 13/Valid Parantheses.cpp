// PROBLEM :- https://leetcode.com/problems/valid-parentheses/

// LEETCODE | EASY | STACK

// Solution :- T.C. O(N) , S.C. O(N)

// Insert the opening braces into the stack, and whenever a closing brace appears, check if the top of stack have its equivalent brace. If NO, NOT valid parantheses.
// Also if at any point, a closing brace appears but the stack is empty (no opening braces left), NOT valid parantheses.
// At the end, if their are opening braces left in stack, NOT valid parantheses, else it is a valid parantheses.

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        for(int i = 0 ; i < s.length() ; i++){
            char ch = s[i];
            if(ch == '(' || ch == '[' || ch == '{'){
                stk.push(ch);
            }else{
                if(stk.empty()){
                    return false;
                }else{
                    char tp = stk.top();
                    if(ch == ')' && tp == '(' || ch == '}' && tp == '{' || ch == ']' && tp == '['){
                        stk.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        
        if(stk.empty()){
            return true;
        }else{
            return false;
        }
        
    }
};