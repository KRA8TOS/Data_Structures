#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <array>
#include <map>
using namespace std;

int largest(int arr[], int n)
{
    // brute solution

    /* sort(arr,arr+n);
    return arr[n-1]; */
    // time :O(Nlog N)

    // optimal solution
    int largest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
            largest = arr[i];
    }
    return largest;
}

// second largest element without sorting
int secondlargest(int arr[], int n)
{
    /*  //if we have to find second largest then go into my sorting.cpp where i made a function about kth smallest element using    sorting
        //Brute Solution:
        sort(arr,arr+n);
        int largest=arr[n-1];
        int slargest=-1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]!=largest)
             return arr[i];
        }
        return -1;//if there is no second largest

        //Better Solution:
        int largest=INT_MIN;
        int s_largest=-1;
        for(int i=0;i<n;i++){
            if(arr[i]>largest)
            largest=arr[i];
        }
        for(int i=0;i<n;i++){
            if(arr[i]>slargest&&arr[i]!=largest)
            slargest=arr[i];
        }
        return slargest;
     */
    // Optimal solution :
    int largest = arr[0];
    int slargest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            slargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > slargest && arr[i] != largest)
            slargest = arr[i];
    }
    return slargest;
}

int secondsmallest(int arr[], int n)
{
    int smallest = arr[0];
    int ssmallest = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] > smallest && arr[i] < ssmallest && arr[i] != smallest)
        {
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}

// remove duplicates from a sorted array
// array should be sorted for optimal solution
int uniquearray(int arr[], int n)
{
    /* Brute Solution:
    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    return st.size(); */

    // Optimal Solution
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i + 1;
}

// left rotate an array by 1 place
void leftrotate(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// left rotate an array by k places
void kthleftrotate(int arr[], int n, int k)
{
    k = k % n;
    // Brute Solution
    /* vector<int> temp;
    for(int i=0;i<k;i++){
        temp.push_back(arr[i]);
    }
    for(int i=k;i<n;i++){
        arr[i-k]=arr[i];
    }
    for(int i=n-k;i<n;i++){
        arr[i]=temp[i-(n-k)];
    } */
    // optimal solution:
    // as time slightly increase but space is constant of 1
    reverse(arr, arr + k);
    reverse(arr + k, arr + n);
    reverse(arr, arr + n);

    // printing
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void kthrightrotate(int arr[], int n, int k)
{
    k = k % n;
    // brute
    /* vector <int> temp;
    for (int i=n-k;i<=n;i++){
        temp.push_back(arr[i]);
    }
    for(int i=n-k-1;i>=0;i--){
        arr[i+k]=arr[i];
    }
    for(int i=0;i<k;i++){
        arr[i]=temp[i];
    } */
    // optimal

    reverse(arr, arr + n);
    reverse(arr + k, arr + n);
    reverse(arr, arr + k);

    // printing
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// Count distinct elements
/*arr[]={10,20,30,10,20}
    O/P : 3
     */
int countdistinct(int arr[], int n) // time-O(n2) and space:O(1)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            ans++;
    }
    return ans;
}

// Efficient approach
// time-O(n) and space:O(n)
int Ecountdistinct(int arr[], int n)
{
    unordered_set<int> s;
    for (auto it = 0; it < n; it++)
    {
        s.insert(arr[it]);
    }
    for (auto it : s)
    {
        cout << it << endl;
    }
    return s.size();
}
// counts frequency of each and every element in an array
void frequency(int arr[], int n)
{
    map<int, int> mpp;
    for (int itr = 0; itr < n; itr++)
    {
        mpp[arr[itr]]++;
    } /*
     for(auto itr : mpp){
         cout<<itr.first<<" "<<itr.second<<endl;
     } */

    // if we have to count frequency of specific elements then
    int q;
    cin >> q;
    auto it = 0;
    while (q > 0)
    {
        int n;
        cin >> n;
        cout << n << " ";
        cout << mpp[n] << endl;
        q--;
    }
    return;
}

// intersection of two unsorted arrays
// prints in that format or order whose array size is large
void intersection(int arr1[], int arr2[], int m, int n)
{
    if (m > n)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr1[i] == arr2[j])
                {
                    cout << arr1[i] << " ";
                    break;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr2[i] == arr1[j])
                {
                    cout << arr2[i] << " ";
                    break;
                }
            }
        }
    }
    return;
}
// prints in that format or order whose array size is large
void Eintersection(int arr[], int arr1[], int m, int n)
{
    if (m > n)
    {
        unordered_set<int> s(arr, arr + m);
        /* for (int i = 0; i < m; i++)
        {
            auto it = s.find(arr[i]);
            if (it == s.end())
                break;
            else
                cout << arr[i];
        }
 */
        // for loop in another pattern
        for (int i = 0; i < n; i++)
        {
            if (s.find(arr1[i]) != s.end()) // if s.find didnt find the vslue it will have s.end value
                cout << arr1[i] << " ";
        }
    }
    else
    {
        unordered_set<int> s(arr1, arr1 + n);
        for (int i = 0; i < m; i++)
        {
            if (s.find(arr[i]) != s.end())
                cout << arr[i] << " ";
        }
    }
}

// intersection of two sorted arrays
void sortedintersection(int a[], int b[], int m, int n)
{ // time:O(nlogn +2n) space : O(max(m,n))
    set<int> s(a, a + m);
    for (int i = 0; i < n; i++)
    {
        if (s.find(b[i]) != s.end())
        {
            cout << b[i] << " ";
        }
    }
}

// optimal solution
vector<int> optimalintersectionsorted(int a[], int b[], int m, int n)
{
    // time:O(m+n) space:O(1) when we are printing if we have to return an array of intersection space will be O(n);
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
            i++;
        else if (b[j] < a[i])
            j++;
        else
        {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}

// returns how many values are present and no duplicates should be present
int unionarray(int arr[], int arr1[], int m, int n)
{
    unordered_set<int> dis(arr, arr + m);
    for (auto i = 0; i < n; i++)
    {
        dis.insert(arr1[i]);
    }

    for (auto itr : dis)
    {
        cout << itr << endl;
    }

    return dis.size();
}
// optimal but time and space will be same as above

// union of two sorted arrays
void unionsortedarray(int a[], int b[], int m, int n)
{ // time:O(mlogm+nlogn)+O(m+n) for sorting and inserting and space:O(m+n) and if we are returning a funciton O(m+n)+O(m+n)
    set<int> s(a, a + m);
    for (int i = 0; i < n; i++)
    {
        s.insert(b[i]);
    }
    for (auto itr : s)
    {
        cout << itr << " ";
    }
}

// optimal solution
// time:O(m+n) and space:O(1) if printing and if returning O(m+n)
vector<int> optimalunionsorted(int a[], int b[], int m, int n)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < m && j < n)
    {
        if (a[i] <= b[j])
        {
            if (ans.size() == 0 || ans.back() != a[i])
            {
                ans.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (ans.size() == 0 || ans.back() != b[j])
            {
                ans.push_back(b[j]);
            }
            j++;
        }
    }
    while (i < m)
    {
        if (ans.size() == 0 || ans.back() != a[i])
        {
            ans.push_back(a[i]);
        }
        i++;
    }
    while (j < n)
    {
        if (ans.size() == 0 || ans.back() != b[j])
        {
            ans.push_back(b[j]);
        }
        j++;
    }
    return ans;
}
// returns true when there is a pair which is equal to the sum
bool pairsum(int arr[], int n, int sum)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.find(sum - arr[i]) != s.end())
        { // this condition means if element is found
            return true;
        }
        else
            s.insert(arr[i]);
    }
    return false;
}
// brute solution
// time : O(2n) and space O(n)
void movezerotoend(int a[], int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
            temp.push_back(a[i]);
    }
    for (int i = 0; i < temp.size(); i++)
    {
        a[i] = temp[i];
    }
    for (int i = temp.size(); i < n; i++)
    {
        a[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

// two pointer approach and it is optimal solution
// time:O(n) and space:O(1) if we returning array and O(n) if we are printing
void optimalmoveszerotoend(int a[], int n)
{
    int j;
    for (j = 0; j < n; j++)
    {
        if (a[j] == 0)
        {
            break;
        }
    }
    if (j == n)
        return;
    /* for(int i=j+1;i<n;i++){
        if(a[i]!=0){
            swap(a[i],a[j]);
            j++;
        }
    } */
    int i = j + 1;

    while (i < n && j < n - 1)
    {
        if (a[i] != 0)
        {
            swap(a[i], a[j]);
            j++;
        }
        i++;
    }
    // printing
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
    }
}
// time :O(n2) and space:O(1)
int brutemissingnumber(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        bool flag = false;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            return i;
    }
}
// time:O(2n) and space:O(1)
int bettermissingnumber(int arr[], int n)
{
    vector<int> hash(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 0)
            return i;
    }
    return 0;
}
// time :O(n) and space :O(1)
int optimalmissingnumber(int arr[], int n)
{
    long sum = n * (n + 1) / 2;
    int sum2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum2 += arr[i];
    }
    return sum - sum2;
}
// time:O(n) and space:O(1)
// it is slightly better as if n is very greater integer then n*n will be very large
int optimalmissingnumber2(int arr[], int n)
{
    int xor1 = 0;
    int xor2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i + 1);
    }
    xor1 = xor1 ^ n;
    return xor1 ^ xor2;
}
// time :O(n) and space:O(1)
int maximumconsecutivesone(int arr[], int n)
{
    int counter = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            counter += 1;
        }
        else if (arr[i] == 0)
        {
            counter = 0;
        }
        ans = max(ans, counter);
    }
    return ans;
}
// all element will appear twice and there is only one element who appears once
// time:O(n2) and space:O(1)
int bruteonce(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                count++;
            }
        }
        if (count == 1)
            return i;
    }
}
// time:O(2n) and space:O(n)
int betteronce(int arr[], int n)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]] += 1;
    }
    for (auto it : mpp)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
}
// time:O(n) and space:O(1)
int optimalonce(int arr[], int n)
{
    int xor1 = 0;
    for (int i = 0; i < n; i++)
    {
        xor1 = xor1 ^ arr[i];
    }
    return xor1;
}

// brute force-O(n3)
int getLongestSubarray(vector<int> &arr, long long k)
{
    int n = arr.size();

    int len = 0;
    for (int i = 0; i < n; i++)
    {
        long long s = 0;
        for (int j = i; j < n; j++)
        {
            s += arr[j];
            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

// better-o(n) and space -o(n) {PREFIX based}
int bettergetLongestSubarray(vector<int> &a, long long k)
{
    int n = a.size();

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        long long rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        // the left most prefix sum we will take
        // e.g.[2,0,0,3] then the length will be 3 not 1
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}
// brute
vector<int> twoSum(int n, vector<int> &arr, int target)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return {-1, -1};
}
// better :time-O(n) and space-O(n)
string bettertwoSum(int n, vector<int> &arr, int target)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end())
        {
            return "YES";
        }
        mpp[num] = i; // insert
    }
    return "NO";
}
// optimum:time-O(n+nlog n) and space:O(1)
string optimizedtwoSum(int n, vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            return "YES";
        }
        else if (sum < target)
            left++;
        else
            right--;
    }
    return "NO";
}

// better :O(2n) and space :O(1)
void sortArrayof012(vector<int> &arr, int n)
{

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            cnt0++;
        else if (arr[i] == 1)
            cnt1++;
        else
            cnt2++;
    }
    for (int i = 0; i < cnt0; i++)
        arr[i] = 0;
    for (int i = cnt0; i < cnt0 + cnt1; i++)
        arr[i] = 1;

    for (int i = cnt0 + cnt1; i < n; i++)
        arr[i] = 2;
}
// Dutch National Flag Algorithm
void sortArray012(vector<int> &arr, int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

// brute
int brutemajorityElement(vector<int> v)
{

    // size of the given array:
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        // selected element is v[i]
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            // counting the frequency of v[i]
            if (v[j] == v[i])
            {
                cnt++;
            }
        }

        // check if frquency is greater than n/2:
        if (cnt > (n / 2))
            return v[i];
    }

    return -1;
}

// better
int bettermajorityElement(vector<int> v)
{
    int n = v.size();

    map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        mpp[v[i]]++;
    }
    for (auto it : mpp)
    {
        if (it.second > (n / 2))
        {
            return it.first;
        }
    }

    return -1;
}

// optimized
int optimizedmajorityElement(vector<int> v)
{
    int n = v.size();
    int cnt = 0;
    int el;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i])
        {
            cnt++;
        }
        else
            cnt--;
    }
    if (cnt != 0)
    {
        return el;
    }
    return -1;

    // When we have to figure out that majorityelement is present or not then we have to check through another loop that it is crossing n/2 or not

    /*

    checking if the stored element is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) 
        return el;
    return -1; */
}

//brute
int brutemaxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]
            int sum = 0;

            //add all the elements of subarray:
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

//better
int bettermaxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            // current subarray = arr[i.....j]

            //add the current element arr[j]
            // to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];

            maxi = max(maxi, sum); // getting the maximum
        }
    }

    return maxi;
}

//optimized
long long optimizedmaxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;
    for (int i = 0; i < n; i++) {

        sum += arr[i];
        maxi=max(sum,maxi);
        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}

//brute
vector<int> RearrangebySign(vector<int>A, int n){
    
  // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array.
  vector<int> pos;
  vector<int> neg;
  
  // Segregate the array into positives and negatives.
  for(int i=0;i<n;i++){
      
      if(A[i]>0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
  }
  
  // Positives on even indices, negatives on odd.
  for(int i=0;i<n/2;i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
  }
  
  
  return A;
    
}
//optimal
vector<int> RearrangebySign(vector<int>A){
    
  int n = A.size();
  
  // Define array for storing the ans separately.
  vector<int> ans(n,0);
  
  // positive elements start from 0 and negative from 1.
  int posIndex = 0, negIndex = 1;
  for(int i = 0;i<n;i++){
      
      // Fill negative elements in odd indices and inc by 2.
      if(A[i]<0){
          ans[negIndex] = A[i];
          negIndex+=2;
      }
      
      // Fill positive elements in even indices and inc by 2.
      else{
          ans[posIndex] = A[i];
          posIndex+=2;
      }
  }
  
  return ans;
    
}

/* ******************************************   Variety 2          ********************************************/

 vector<int> RearrangebySign(vector<int>A, int n){
    
  // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array.
  vector<int> pos;
  vector<int> neg;
  
  // Segregate the array into positives and negatives.
  for(int i=0;i<n;i++){
      
      if(A[i]>0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
  }
  
  // If positives are lesser than the negatives.
  if(pos.size() < neg.size()){
      
    // First, fill array alternatively till the point 
    // where positives and negatives ar equal in number.
    for(int i=0;i<pos.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
    }
    
    // Fill the remaining negatives at the end of the array.
    int index = pos.size()*2;
    for(int i = pos.size();i<neg.size();i++){
        
        A[index] = neg[i];
        index++;
    }
  }
  
  // If negatives are lesser than the positives.
  else{
      
      // First, fill array alternatively till the point 
      // where positives and negatives ar equal in number.
      for(int i=0;i<neg.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
  }
    
    // Fill the remaining positives at the end of the array.
    int index = neg.size()*2;
    for(int i = neg.size();i<pos.size();i++){
        
        A[index] = pos[i];
        index++;
    }
  }
  return A;
    
}

vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size(); // size of the array.

    // Step 1: Find the break point:
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            // index i is the break point
            ind = i;
            break;
        }
    }

    // If break point does not exist:
    if (ind == -1) {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: reverse the right half:
    reverse(A.begin() + ind + 1, A.end());

    return A;
}

//brute
vector<int> printLeadersBruteForce(int arr[], int n) {

  vector<int> ans;
  
  for (int i = 0; i < n; i++) {
    bool leader = true;

    //Checking whether arr[i] is greater than all 
    //the elements in its right side
    for (int j = i + 1; j < n; j++)
      if (arr[j] > arr[i]) {
          
        // If any element found is greater than current leader
        // curr element is not the leader.
        leader = false;
        break;
      }

    // Push all the leaders in ans array.
    if (leader)
    ans.push_back(arr[i]);

  }
  
  return ans;
}

vector<int> optimizedprintLeaders(int arr[], int n) {

  vector<int> ans;
  
 // Last element of an array is always a leader,
 // push into ans array.
 int max = arr[n - 1];
 ans.push_back(arr[n-1]);

  // Start checking from the end whether a number is greater
  // than max no. from right, hence leader.
  for (int i = n - 2; i >= 0; i--)
    if (arr[i] > max) {
      ans.push_back(arr[i]);
      max = arr[i];
    }

  
  return ans;
}

bool linearSearch(vector<int>&a, int num) {
    int n = a.size(); //size of array
    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}
int brutelongestSuccessiveElements(vector<int>&a) {
    int n = a.size(); //size of array
    int longest = 1;
    //pick a element and search for its
    //consecutive numbers:
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int cnt = 1;
        //search for consecutive numbers
        //using linear search:
        while (linearSearch(a, x + 1) == true) {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}

int betterlongestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    //sort the array:
    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    //find longest sequence:
    for (int i = 0; i < n; i++) {
        if (a[i] - 1 == lastSmaller) {
            //a[i] is the next element of the
            //current sequence.
            cnt += 1;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;

}

int optimizedlongestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    kthrightrotate(arr, n, 3);
    return 0;
}
