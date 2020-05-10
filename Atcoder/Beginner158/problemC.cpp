#include <iostream>
#include<math.h>
using namespace std;
bool GoodPrice(int price, int a, int b)
{
    return (price * 8 / 100 == a)
        && (price * 10 / 100 == b);
}
 
int main()
{
    int a, b;
    cin >> a >> b;
 
    auto price_limit = max(a * 100 / 8, b * 100 / 10);
    for (int i = 1; i <= 2 * price_limit;++i) {
        if (GoodPrice(i, a, b)) {
            cout << i;
            return 0;
        }
    }
 
    cout << "-1";
    return 0;
}