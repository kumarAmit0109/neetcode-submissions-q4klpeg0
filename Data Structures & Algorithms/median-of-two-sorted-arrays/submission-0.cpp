class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int>temp(n1 + n2);
        int i = 0, j = 0, k = 0;

        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]){
                temp[k] = nums1[i];
                i++;
                k++;
            }else{
                temp[k] = nums2[j];
                j++;
                k++;
            }
        }

        while( i < n1){
            temp[k] = nums1[i];
            i++;
            k++;
        }
        while( j < n2){
            temp[k] = nums2[j];
            j++;
            k++;
        }

        if((n1 + n2)%2 == 0){
            int elem1 = temp[(n1 + n2)/2];
            int elem2 = temp[(n1 + n2)/2 - 1];
            return (double)((elem1 + elem2)/2.0);
        }else{
            return temp[(n1 + n2)/2];
        }
    }
};
