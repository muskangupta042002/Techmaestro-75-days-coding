class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        
        int mid1,mid2;
        double ans;
        if((n+m )% 2 != 0)
        {
            int i=0,j=0;
            mid1=(n+m)/2;
            int c=0;
            while(i<n && j<m)
            {
                if(nums1[i]<=nums2[j])
                {
                    if(c==mid1)
                    {
                        return double(nums1[i]);
                        break;
                    }
                    c++;
                    i++;
                }
                else 
                {
                    if(c==mid1)
                    {
                        return double(nums2[j]);
                        break;
                    }
                    c++;
                    j++;
                }
            }
            while(i<n)
            {
                if(c==mid1)
                    {
                        return double(nums1[i]);
                        break;
                    }
                    c++;
                    i++;
            }
            while(j<m)
            {
                if(c==mid1)
                    {
                        return double(nums2[j]);
                        break;
                    }
                    c++;
                    j++;
            }
        }
        else
        {
            int i=0,j=0;
            mid1=(n+m)/2;
            mid2=mid1-1;
            double a,b;
            int c=0;
            while(i<n && j<m)
            {
                if(nums1[i]<=nums2[j])
                {
                    if(c==mid1)
                    {
                        a=nums1[i];
                        
                    }
                    else if(c==mid2)
                    {
                        b=nums1[i];
                    }
                    c++;
                    i++;
                }
                else 
                {
                    if(c==mid1)
                    {
                        a=nums2[j];
                        
                    }
                    else if(c==mid2)
                    {
                        b=nums2[j];
                    }
                    c++;
                    j++;
                }
            }
            cout<<"N0"<<n;
            while(i<n)
            {
                if(c==mid1)
                    {
                        a=nums1[i];
                        
                    }
                    else if(c==mid2)
                    {
                        b=nums1[i];
                    }
                    c++;
                    i++;
            }
            while(j<m)
            {
                if(c==mid1)
                    {
                        a=nums2[j];
                        
                    }
                    else if(c==mid2)
                    {
                        b=nums2[j];
                    }
                    c++;
                    j++;
            }
            cout<<a<<b;
            ans=(a+b)/2.0;
        
        }
        return ans;
    }
};