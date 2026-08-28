class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                     vector<int>& healths,
                                     string directions) {
        
        int n = positions.size();

        vector<int> indices(n);

        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        sort(indices.begin(), indices.end(),
             [&](int a, int b) {
                 return positions[a] < positions[b];
             });

        stack<int> st;

        for (int idx : indices) {

            if (directions[idx] == 'R') {
                st.push(idx);
            }
            else {
                while (!st.empty() && healths[idx] > 0) {

                    int rightRobot = st.top();

                    if (healths[rightRobot] < healths[idx]) {
                        healths[rightRobot] = 0;
                        st.pop();

                        healths[idx]--;
                    }
                    else if (healths[rightRobot] > healths[idx]) {
                        healths[idx] = 0;

                        healths[rightRobot]--;
                    }
                    else {
                        healths[rightRobot] = 0;
                        healths[idx] = 0;
                        st.pop();
                    }
                }
            }
        }

        vector<int> answer;

        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                answer.push_back(healths[i]);
            }
        }

        return answer;
    }
};