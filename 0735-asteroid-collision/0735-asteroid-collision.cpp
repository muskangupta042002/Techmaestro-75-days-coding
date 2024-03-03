class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n=asteroids.size();
        int i=0;
        vector<int> ans;
        while(i<n){
            if(st.empty()){
                st.push(asteroids[i]);
            }
            else{
                while(!st.empty() && st.top()>0 && asteroids[i]<0){
                    if(st.top()<abs(asteroids[i])){
                        st.pop();
                    }
                    else{
                        break;
                    }
                }
                if(!st.empty()){
                    if(st.top()<0 && asteroids[i]<0){
                        st.push(asteroids[i]);
                    }
                    else if(st.top()>0 && asteroids[i]>0){
                        st.push(asteroids[i]);
                    }
                    else if(st.top()<0  && asteroids[i]>0){
                        st.push(asteroids[i]);
                    }
                    else {
                        if(st.top()==abs(asteroids[i])){
                            st.pop();
                        }
                    }
                }
                else{
                    if(st.empty()){
                        st.push(asteroids[i]);
                    }
                }
                
            }
            i++;
        }
        while(!st.empty()){
            ans.push_back(st.top());st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};