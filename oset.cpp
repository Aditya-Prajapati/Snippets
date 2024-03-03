#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
// <int> to <dataType>
// less<dataType> - Ascending order,  greater<dataType> - Descending order, less_equal<dataType> - Duplicates values
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int main(){
    oset st;
    st.insert(2);
    st.insert(4);
    st.insert(3);
    st.insert(3);
    // find ith element by index
    cout << *st.find_by_order(1) << endl;
    // smaller values than x
    cout << st.order_of_key(2) << endl;
    // Also, all normal methods of set are applicable 
    cout << *st.upper_bound(4) << endl; // first element greater than x
    st.erase(3);
    
    return 0;
}
