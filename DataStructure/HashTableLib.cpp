#include<iostream>
#include<fstream>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;

/*
    C++ có hỗ trợ các thư viện cho hash table như map, unodered_map hay multimap để xử lý va chạm, ngoài ra mình sẽ giới thiệu thêm
    set, unodered_set, multiset

    1. Map
    Dựa theo cdtl cây BST gồm pair<key, value>, mọi key và value được đưa vào sẽ được sắp xếp thep thứ tự của key, nếu ta ko có tham số thứ
    3(greater<int> hoặc less<int>) thì map sẽ mặc định là less. Nếu key là số -> sắp tăng dần theo số, nếu key là kí tự chữ -> sắp theo thứ tự
    bảng chữ cái, trong map không chứa 2 key có giá trị = nhau, value = nhau thì được

    .map<...,...>::iterator ptr = map.begin(): con trỏ để lặp qua hết các phần tử trong map từ begin -> end
    .map<...,...>::reverse_iterator ptr = map.rbegin(); ptr != map.rend(): con trỏ lặp qua hết các phần tử trong map từ end -> begin
    .ptr->first: là key, ptr->second: là value
    .map.size(): trả về số lượng cặp pair có trong map
    .map<...,...> copy_map(map_original.begin(), map_original.end()): copy map cũ vào map mới
    .map.insert(pair<...,...>()): insert cặp key, value vào map
    .map.find(key): tìm cặp pair có target là key trong map, map.find(Key) != map.end() -> tìm thấy
    .map.lower_bound(key_f): chặt nhị phân tìm kiếm phần tử tại vị trí đầu tiên mà nó tìm thấy đc sao cho key >= key_f, 
    nếu ko tìm thấy trả về map.end()
    .map.upper_bound(key_f):        //                                                 key > key_f,             //
    .map.erase(target): xóa cặp pair theo target chỉ định
    .map.erase(map.begin(), map.find(target)): nếu map đang có key tăng dần -> xóa tất cả cặp pair có key < target

    2. Unoder Map: cũng là kiểu dữ liệu (key, value) nhưng dựa theo ctdl hash table nên mọi cặp pair<key, value> đưa vào nó sẽ ko đc sắp xếp thứ tự
    như map thông thường, đúng như cái tên, unoder là ko theo thứ tự, searching, insert, delete đều có average là O(1), còn map thông thường là
    O(logn) do nó dùng cây BST

    .Unorder map ko có vụ reverse giống map

    3. Multi Map: cũng giống như map thông thường, nhưng nó hỗ trợ chứa cặp pair có key trùng nhau

    .multi_map.equal_range(target): trả về tất cả cặp pair có key = target, nếu không tìm thấy thì it->second sẽ trả về giá trị = 0
*/

void inputMap(map<int, int> &my_map){
    my_map.insert(pair<int, int>(4, 13));    
    my_map.insert(pair <int, int> (3, 14));
    my_map.insert(pair <int, int> (6, 14));
    my_map.insert(pair <int, int> (1, 15)); 
    my_map.insert(pair <int, int> (5, 11)); 
}
void MapMethod(map<int, int> my_map){
    //Xuất các phần tử
    for(map<int, int>::reverse_iterator temp = my_map.rbegin(); temp != my_map.rend();temp++){
        cout << "Key: " << temp->first << " | " << "Value: " << temp->second << endl;
    }
    cout << "=======================================" << endl;
    map<int, int, greater<int>> my_map_copy(my_map.begin(), my_map.end());
    for(map<int, int>::iterator temp = my_map_copy.begin(); temp != my_map_copy.end();temp++){
        cout << "Key: " << temp->first << " | " << "Value: " << temp->second << endl;
    }

    //Tìm kiếm
    if(my_map.find(7) != my_map.end()){
        cout << "Have" << endl;
    }
    else{
        cout << "dont have" << endl;
    }

    map<int, int>::iterator temp = my_map.lower_bound(4);
    cout << temp->first << " " << temp->second << endl;

    //Xóa
    cout << my_map_copy.size() << endl;

    my_map_copy.erase(3);
    for(auto temp = my_map_copy.begin();temp != my_map_copy.end();temp++){
        cout << "Key: " << temp->first << " | " << "Value: " << temp->second << endl;
    }
    cout << my_map_copy.size() << endl;

    my_map_copy.erase(my_map_copy.begin(), my_map_copy.find(4));
    for(auto temp = my_map_copy.begin();temp != my_map_copy.end();temp++){
        cout << "Key: " << temp->first << " | " << "Value: " << temp->second << endl;
    }
    cout << my_map_copy.size() << endl;

}

void inputUnOrderMap(unordered_map<int, int> &my_unordermap){
    my_unordermap.insert(pair<int, int>(4, 13));    
    my_unordermap.insert(pair <int, int> (3, 14));
    my_unordermap.insert(pair <int, int> (6, 14));
    my_unordermap.insert(pair <int, int> (1, 15)); 
    my_unordermap.insert(pair <int, int> (5, 11)); 
}

void UnorderMapMethod(unordered_map<int, int> my_unodermap){
    for(unordered_map<int, int>::iterator temp = my_unodermap.begin(); temp != my_unodermap.end();temp++){
        cout << "Key: " << temp->first << " | " << "Value: " << temp->second << endl;
    }

    //Tìm kiếm
    if(my_unodermap.find(7) != my_unodermap.end()){
        cout << "Have" << endl;
    }
    else{
        cout << "dont have" << endl;
    }

    my_unodermap.erase(3);
    for(auto temp = my_unodermap.begin();temp != my_unodermap.end();temp++){
        cout << "Key: " << temp->first << " | " << "Value: " << temp->second << endl;
    }
    cout << my_unodermap.size() << endl;

}

void inputMultiMap(multimap<int, int> &my_multimap){
    my_multimap.insert(pair <int, int> (4, 14)); 
    my_multimap.insert(pair <int, int> (3, 13));
    my_multimap.insert(pair <int, int> (3, 18));
    my_multimap.insert(pair <int, int> (1, 11)); 
    my_multimap.insert(pair <int, int> (5, 15)); 
}
void MultiMapMethod(multimap<int, int> my_multimap){
    //Xuất dữ liệu
    for(auto temp = my_multimap.begin();temp != my_multimap.end();temp++){
        cout << "Key: " << temp->first << " | " << "Value: " << temp->second << endl;
    }

    //Searching
    if(my_multimap.find(3) != my_multimap.end()){
        cout << "Have" << endl;
    }
    else{
        cout << "Dont have" << endl;
    }
    //search 1 phần tử
    auto it_search = my_multimap.find(3);
    cout << "Key: " << it_search->first << " | " << "Value: " << it_search->second << endl;

    //search tất cả phần tử có same key
    vector<int> stack;
    auto it_search_all = my_multimap.equal_range(2);
    for(auto temp = it_search_all.first; temp != it_search_all.second;temp++){
        stack.push_back(temp->first);
        cout << "Key: " << temp->first << " | " << "Value: " << temp->second << endl;
    }

}
int main(){
    //Map
    // map<int, int> my_map;
    // inputMap(my_map);
    // MapMethod(my_map);

    //Unorder map
    // unordered_map<int, int> my_unordermap;
    // inputUnOrderMap(my_unordermap);
    // UnorderMapMethod(my_unordermap);

    //Multi map
    multimap<int, int> multimap;
    inputMultiMap(multimap);
    MultiMapMethod(multimap);

    //searchMultimap(multi_map, 13);
    return 0;
}