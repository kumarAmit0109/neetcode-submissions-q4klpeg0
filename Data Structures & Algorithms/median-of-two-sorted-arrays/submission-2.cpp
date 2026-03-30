class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0, k = 0;
        int size = (n1 + n2)/2;
        int idx1 = (n1 + n2)/2;
        int idx2 = (n1 + n2)/2 - 1;
        int element1 = -1, element2 = -1;

        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]){
                if(k == idx1) {
                    element1 = nums1[i];
                }
                if(k == idx2) {
                    element2 = nums1[i];
                }
                i++;
            }else{
                if(k == idx1) {
                    element1 = nums2[j];
                }
                if(k == idx2) {
                    element2 = nums2[j];
                }
                j++;
            }
            k++;
        }

        while( i < n1){
            if(k == idx1) {
                element1 = nums1[i];
            }
            if(k == idx2) {
                element2 = nums1[i];
            }    
            i++;
            k++;
        }
        while( j < n2){
            if(k == idx1) {
                element1 = nums2[j];
            }
            if(k == idx2) {
                element2 = nums2[j];
            }
            j++;
            k++;
        }

        if((n1 + n2)%2 == 0){
            return (double)((element1 + element2)/2.0);
        }else{
            return element1;
        }
    }
};
