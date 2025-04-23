#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<numeric>
#include<string>

using namespace std;

void explainPair(){
    // Pair is in Std library so we need to use this
    pair <char, int> pr = {'A',2};
    cout << pr.first << " "<< pr.second;

    cout << endl;

    pair <int,pair<int,char>> pr1 = {1, {3,'C'}};
    cout << pr1.first << " " << pr1.second.first << " " << pr1.second.second;
}

void explainVectors(){
    // Array is container which is fixed container but vector is dynamic type
    vector<int> v1; //Empty container
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    cout << v1.size() << endl; //Gives the length of vector
    // We can use emplace back as well

    v1.emplace_back(4);

    //Vector traversing
    for(int i=0;i<v1.size();i++){
        cout << v1[i] << endl;
    }

    //Iterator
    cout << "Accessing the first element: ";
    auto i = v1.begin();
    cout << *i << endl;

    cout << "Accessing the last element: "; //End always points to last+1, so we give here end-1 which gives last element
    auto i1 = v1.end()-1;
    cout << *i1 << endl;

    // Iterating from begin to end
    for(auto j=v1.begin();j<v1.end();j++){
        cout << *j << " ";
    }
    cout << endl;

    //For each
    for(auto k: v1){
        cout << k << " ";
    }
    cout << endl;

    // Reverse Iterator
    auto reverse_begin = v1.rbegin(); //It will point to last elemeent
    auto reverse_end = v1.rend(); //It will point to somewhere before 1

    for(auto ii=reverse_begin;ii<reverse_end; ii++){
        cout << *ii << " ";
    }
    cout << endl;

    vector<int> vec(5); //It will print 5 zeros
    vector<int> vec1(5,8); // creates 5 elements of 8

    // duplicate vector of vector
    vector<int> dup(v1);

    //range of vector
    vector<int> dup2(v1.begin()+1,v1.end());
    for(auto i:dup2){
        cout << i << " ";
    } 
    cout << endl;

    // front - first element; back - last element; pop_back() - last element will be deleted

    // For erase we need to give a iterator
    vec1.erase(vec1.begin()+1,vec1.end()-2);
    for(auto i: vec1){
        cout << i << " ";
    }
    cout << endl;

    // vec.clear() - clears the element 

    // Vector Swap -
    vector<int> vs(5,8);
    vector<int> vss(5,7); 
    swap(vss,vs);

    for(auto i:vss){
        cout << i << " ";
    }
    cout << endl;

    // Vector Insert - It inserts the value based on the position
    vss.insert(vss.begin(),9);

    for(auto i:vss){
        cout << i << " ";
    }
    cout << endl;
}

void explainList(){
    // List is also a container same like vector, starts with 0 and end-1
    list<int> ls = {6, 7};
    // List allows us to insert at front, we have 
    ls.push_front(1);
    ls.push_front(2);
    for(auto i: ls){
        cout << i << " ";
    }
    cout << endl;
}

void explainDeque(){
    // Same like list we can insert at last as well
}

void explainStack(){
    // Stack is Last in First Out Data Structure
    stack<int> s;
    s.push(5);
    s.push(6);
    s.push(7);
    // size of stack is 
    s.size();

    // Top element in stack
    cout << s.top() << endl;

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
}

void explainQueue(){
    // Similar to stack but it is FIFO
    queue<int> q;
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

}

void explainPQ(){
    //Stores the highest element on the top and goes in the descending order, if character stores highest value
    // character stores on top this is maximum heap
    priority_queue<int> pq;
    pq.push(2);
    pq.push(10);
    pq.push(8);

    cout << pq.top() << endl;

    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    // Minimum Heap - Stores the least element at the top and the ascending order follows

    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(1);
    pq1.push(-1);
    pq1.push(10);
    pq1.push(20);

    while(!pq1.empty()){
        cout << pq1.top() << " ";
        pq1.pop();
    }
    cout << endl;
}

void explainSet(){
    // Stores only unique elements
    // But it is only in ascending order
    set<int> s;
    s.insert(50);
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(40);
    s.insert(40);
    s.insert(40);
    s.insert(40);

    for(auto i: s){
        cout << i << " ";
    }
    cout << endl;

    // find the element in the set
    auto it = s.find(12); //IF element is not there it returns the end iterator
    if(it!=s.end()){
        cout << *it;
    };

    // Same like find
    auto j= s.count(21); //It will return 1 or 0
    if(!j){
        cout << "There is no value" << endl;
    }

    // erase - It also uses iterator, we can remove either last element or last before element or the begin element anything
    auto iit = s.end();
    iit --;
    s.erase(50);
    for(auto i: s){
        cout << i << " ";
    }
    cout << endl;

    // Range of deletion elemeents in our case lets delete from 20 and 30, so only 10 will be left
    auto jk = s.begin();
    jk++;

    auto jk1 = s.end();
    jk1--;

    s.erase(jk,jk1);

    for(auto i:s){
        cout << i << " ";
    }
    cout << endl;

    set<int> s1 = {10, 20, 30, 40, 50};
    //lower bound - Give iterator to the first elemet that is greater than or equal than the given value
    // {10, 20, 30, 40, 50}
    // If you look for 20, it points to 20 which is in the list
    // If you look for 25, it points to 30 which is >=25 as 25 is not there
    // If you look for 69, it points past of the end

    auto ijt = s1.lower_bound(10);
    cout << *ijt << endl;

    cout << endl;

    //upper bound - Give iterator to the first element that is strictly greater than the given value
    // {10, 20, 30, 40, 50}
    // If you look for 20, it points to 30 which is greater than 20
    // If you look for 25, it also points to 30 which is greater than 25
    // If you look for 50, it points to the past of the end

    auto low = s1.lower_bound(5);
    auto high = s1.upper_bound(30);

    for(auto i=low;i!=high;i++){
        cout << *i << endl;
    }



}

void explainMuliSet(){
    // Same like set, but it will store repeated values, duplicates and stored in ascending order
    multiset<int> ms;
    ms.insert(21);
    ms.insert(21);
    ms.insert(21);
    ms.insert(21);
    // find 1 will point to first element 
    // erase 1 will erase all elements
    ms.erase(ms.find(21)); // It will just erase one 21 because find is a iterator which points to the location
    // count - all duplicates it will count
    ms.count(1);
}

void explainUnorderedSet(){
    // It is unorderded, there is no sorting here but it will store unique elements
    // There will be no upper bound or lower bound
    // It happens in constant time complexity O(1), O(N) is extreme rare scenario
    unordered_set<int> us;
    us.insert(80);
    us.insert(10);
    us.insert(20);
    us.insert(50);

    for(auto i:us){
        cout << i << " ";
    }
    cout << endl;
}

void explainMap(){
    //Map takes key and sort by it in ascending order
    //Whatever is initialized at the end it stores that in map data structure
    // An unordered map - There will be no order, the time complexity is constant O(1) unless there are collisions
    map<int, string> mp;
    mp.insert({5,"Bush"});
    mp[1] = "Sahan";
    mp[2] = "Raj";
    mp[3] = "Sahithi";
    mp.insert({4,"Finkle"});

    for(auto i:mp){
        cout << i.first << "->" << i.second << endl;
    }

    auto it = mp.find(4);
    cout<< (*it).first << "->" << (*it).second << endl;

    auto iit = mp.find(10);
    if(iit==mp.end()){
        cout << "Key not found" << endl;
    }

    // Lower_Bound gives the first key which is greater than or equal to the value
    // Upper_Bound gives the first key which is greater than the value

    auto lower = mp.lower_bound(-1);
    cout << (*lower).first << "->" << (*lower).second << endl;

    auto upper = mp.upper_bound(-1);
    cout << (*upper).first << "->" << (*upper).second << endl;
}

void explainMultiMap(){
    multimap<int, char> mpp;
    //Sorted based on key and contains duplicate keys
    mpp.insert({1,'b'});
    mpp.insert({1,'c'});
    mpp.insert({1,'a'});
    mpp.insert({2,'a'});
    mpp.insert({2,'b'});
    mpp.insert({2,'c'});
    mpp.insert({3,'a'});
    mpp.insert({3,'b'});
    mpp.insert({3,'c'});

    for(auto i=mpp.begin();i!=mpp.end();i++){
        cout << (*i).first << "->" << (*i).second << endl;
    }
    cout << endl;

    auto it = mpp.equal_range(2); // This will return the pair of first iterator
    // Equal range gives the elements list

    for(auto i=it.first;i!=it.second;i++){
        cout << (*i).first << "->" << (*i).second << endl;
    }

    cout << endl;
}

void explainSort(){
    int arr[5] = {1, -1, 8, 7, 0};
    //sort(arr,arr+5); //First position of array to the last which is arr+1
    //for(int i=0; i<5; i++){
    //    cout << arr[i] << endl;
    //}

    //cout << endl;

    // we can sort based on the range as well
    sort(arr+2,arr+4);
    for(int j=0; j<5; j++){
        cout << arr[j] << endl;
    }

    //For vectors we use begin()
}

void explainAccumulate(){
    int arr[6] = {1, 2, 3, 4, 5, 6};
    cout << accumulate(arr, arr+5, 0); //Starts with 0 sum, if we replace the 0 with 1 sum starts with 1
    cout << endl;
}

void explainCount(){
    int arr[5] = {1, 2, 3, 4, 5};
    int num =1;
    cout << count(arr, arr+5, num); // Gives the count of how many times the number appeared
    cout << endl;
}

void explainFind(){
    int arr[5] = {1, 2, 3, 4, 5};
    int num = 7;

    auto it = find(arr, arr+5, 1); //Returns the first value

    //If the value is not present

    auto i = find(arr, arr+5, 8);
    if(i==(arr+5)){
        cout << "Iterator not found" << endl;
    }


}

void explainNextPermutation(){
    string s = "abc";
    do{
        cout << s << endl;
    }while(next_permutation(s.begin(),s.end())); //Permutations will print in sorted order, if there is no next permutation it will print NULL
    // if I give "bca" then it will give cab cba and null
    // We can do part of string as well s.begin(),s.begin+2 ==> it will consider ab only
    // we will have prev_permutation as well
}

void explainMaxElement(){
    int arr[6] = {7, 6, 5, 10, 9};
    auto it = max_element(arr,arr+5); //It will always point to an iterator
    cout << *it << endl;
    // Same thing we can do for minimum using min_element
}

void explainReverse(){
    // Reverse the array
    int arr[6] = {7, 6, 5, 10, 9};
    reverse(arr, arr+5);
    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool comparatortest(int e1, int e2){
    // tells True if e1 is before e2
    // tells False if e1 has to be after e2
    if(e1<e2) return false;
    return true;
}

void explainComparator(){
    // Internally entire array goes
    // ele1 is 5 and ele2 is 6
    // We are checking if ele1 should be before ele2, 5<6, there is internal comparator and it keeps on repeating

    int arr[6] = {7, 6, 5, 10, 9};
    sort(arr,arr+5,comparatortest);
    for(int i=0; i<5;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // By default sort is ascending order, but if we use intenal comparator we can replace it with our logic
    sort(arr,arr+5);
    for(int i=0; i<5;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool internalcomparatot(pair<int,int> el1, pair<int,int> el2){
    if (el1.second > el2.second) return true;
    if (el1.second < el2.second) return false;
    if(el1.first < el2.first) return true;
    return false;
}
void exampleComparator(){
    pair<int,int> arr[] = {{1, 6},{1, 5},{2,6},{2,9},{3,9}};
    sort(arr,arr+5,internalcomparatot);
    for(int i=0;i<5;i++){
        cout << "{" << arr[i].first << "," << arr[i].second << "}" << ",";
    }
    // Question: sort according to the second element, if the elements are same get the smallest first
    // {2,9},{3,9},{1,6},{2,6},{1,5}
}


int main(){
    explainPair();
    explainVectors();
    explainList();
    explainDeque();
    explainStack();
    explainQueue();
    explainPQ();
    explainSet();
    explainMuliSet();
    explainUnorderedSet();
    explainMap();
    explainMultiMap();
    explainSort();
    explainAccumulate();
    explainCount();
    explainFind();
    explainNextPermutation();
    explainMaxElement();
    explainReverse();
    explainComparator();
    exampleComparator();
}