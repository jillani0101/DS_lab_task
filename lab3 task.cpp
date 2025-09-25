#include<iostream>
using namespace std;

int main() {
    float espresso_price = 3.0;
    float latte_price = 3.0;
    float cappuccino_price = 3.0;
    
    float* espresso_ptr = &espresso_price;
    float* latte_ptr = &latte_price;
    float* cappuccino_ptr = &cappuccino_price;
    
    int espresso_qty, latte_qty, cappuccino_qty;
    
    int* espresso_qty_ptr = &espresso_qty;
    int* latte_qty_ptr = &latte_qty;
    int* cappuccino_qty_ptr = &cappuccino_qty;
    
    cout << " quantity for Espresso: ";
    cin >> *espresso_qty_ptr;
    
    cout << " quantity for Latte: ";
    cin >> *latte_qty_ptr;
    
    cout << " quantity for Cappuccino : ";
    cin >> *cappuccino_qty_ptr;
    
    float espresso_total = (*espresso_ptr) * (*espresso_qty_ptr);
    float latte_total = (*latte_ptr) * (*latte_qty_ptr);
    float cappuccino_total = (*cappuccino_ptr) * (*cappuccino_qty_ptr);
    
    float* espresso_total_ptr = &espresso_total;
    float* latte_total_ptr = &latte_total;
    float* cappuccino_total_ptr = &cappuccino_total;
    
    float total_bill = *espresso_total_ptr + (*latte_total_ptr) + (*cappuccino_total_ptr);
    float* total_bill_ptr = &total_bill;
    
    cout << "prices" << endl;
    cout << "Espresso quantity : " <<*espresso_total_ptr<<endl;
    cout << "Latte: " <<*latte_total_ptr << endl;
    cout << "Cappuccino : " <<*cappuccino_total_ptr << endl;
    cout << "Total Bill :" << *total_bill_ptr << endl;
    
    return 0;
}
