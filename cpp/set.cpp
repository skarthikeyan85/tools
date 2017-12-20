/*
Set
Sets are containers that store unique elements following a specific order.
In a set, the value of an element also identifies it (the value is itself the key, of type T), and each value must be unique. The value of the elements in a set cannot be modified once in the container (the elements are always const), but they can be inserted or removed from the container.
Internally, the elements in a set are always sorted following a specific strict weak ordering criterion indicated by its internal comparison object (of type Compare).
set containers are generally slower than unordered_set containers to access individual elements by their key, but they allow the direct iteration on subsets based on their order.
Sets are typically implemented as binary search trees.
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> tops;

        for (int num : nums) {
            tops.insert(num);
            if (tops.size() > 3)
               tops.erase(tops.begin()); 
        }
        
        return tops.size() == 3 ? *tops.begin() : *tops.rbegin();
    }
};
