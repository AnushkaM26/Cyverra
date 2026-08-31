class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int pos = 2;
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;
        
        while (curr != nullptr && curr->next != nullptr) {
            
            bool isMax = curr->val > prev->val &&
                         curr->val > curr->next->val;
            
            bool isMin = curr->val < prev->val &&
                         curr->val < curr->next->val;
            
            if (isMax || isMin) {
                
                if (first == -1) {
                    first = pos;
                } else {
                    minDist = min(minDist, pos - last);
                }
                
                last = pos;
            }
            
            prev = curr;
            curr = curr->next;
            pos++;
        }
        
        if (first == -1 || first == last) {
            return {-1, -1};
        }
        
        return {minDist, last - first};
    }
};