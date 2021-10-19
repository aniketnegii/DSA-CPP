class Solution {
public:
    int maxArea(vector<int>& h) {
        int n;
        n=h.size();
        int i=0,j=n-1,A1=INT_MIN,A;
        int m=n-1;
        while(i<=j)
        {
           if(h[i]<h[j])
           {
                 A=h[i]*m;
                  m=m-1;
                  i++;
           }
        
         else if(h[i]>h[j]) 
           {
               A=h[j]*m;
               m=m-1;
               j--;
           }
        else if(h[i]==h[j])
            {
                A=h[i]*m;
                m=m-1;
                i++;
            }
            A1=max(A1,A);
        }
     return A1;  
    }
            
};
