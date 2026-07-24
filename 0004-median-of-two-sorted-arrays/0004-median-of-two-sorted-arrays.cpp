class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0 , j = 0 ;
        int count = 0 ; 
        int countel1 = -1 ; 
        int countel2 = -1 ;

        int n = nums1.size() + nums2.size() ;
        int indx2 = n/2 , indx1 = indx2-1 ;

        while(i<nums1.size() && j<nums2.size()){

            if(nums1[i]<nums2[j]){
                if(count==indx1) countel1 = nums1[i] ;
                if(count==indx2) countel2 = nums1[i] ;
                count++;
                i++;
            } 
            else{
                if(count==indx1) countel1 = nums2[j] ;
                if(count==indx2) countel2 = nums2[j] ;
                count++;
                j++;                
            }
        }
        while(i<nums1.size()){
                if(count==indx1) countel1 = nums1[i] ;
                if(count==indx2) countel2 = nums1[i] ;
                count++;
                i++;            
        }
        while(j<nums2.size()){
                if(count==indx1) countel1 = nums2[j] ;
                if(count==indx2) countel2 = nums2[j] ;
                count++;
                j++;            
        }
        if(n%2==1){
            return countel2 ;
        }
        return (double)(double)(countel2+countel1)/2.0;
    }
};