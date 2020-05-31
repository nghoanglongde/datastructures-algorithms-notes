void quickSort(string &str, int left, int right) {
          int i = left, j = right;
          int mid = str[(left + right) / 2];
          while (i <= j) {
                while (str[i] < mid)
                      i++;
                while (str[j] > mid)
                      j--;
                if (i <= j) {
                      swap(str[i], str[j]);
                      i++; j--;
                }
          };
          if (left < j)
                quickSort(str, left, j);
          if (i < right)
                quickSort(str, i, right);
    }
int main(){
    string s, t;
    cin >> s >> t;
    if(s.length() != t.length()){
        cout << "false";
        return 0;
    }
    else{
        quickSort(s, 0, s.length() - 1);
        quickSort(t, 0, t.length() - 1);
        for(int i = 0;i < s.length();i++){
            if(s[i] != t[i]){
                cout << "false";
                return 0;
            }
        }
        cout << "true";
    }
}