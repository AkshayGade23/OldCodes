#include <iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    void rotation(vector<int>&arr,int n,int d){
        vector<int>temp(n);
        int j;               
       
        for(int i = 0; i < n ; i++){
            j = ((i + d) % n) ;
             
            temp[i] = arr[j];
        }

        for(int i = 0; i < n; i++)
	        arr[i] =temp[i];
	} 
};

int main() {
	int t; 
	cin >> t;
	
	while(t--){
	    int n;
	    int d;
       
	    cin >>n>>d;
	    
	    vector<int>arr(n);
	    
	    for(int i=0;i<n;i++){
	        cin >> arr[i];
	    }
        Solution sb;
	    sb.rotation(arr,n,d);
	    
	    cout<<endl;
	    for(int i = 0;i < n; i++){
	        cout << arr[i]<<' ';
	    }
	}
	return 0;
}