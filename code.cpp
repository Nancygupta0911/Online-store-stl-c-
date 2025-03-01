#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <string>
#include <ctime>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>

using namespace std;

// Product structure
struct Product {
    int productID;
    string name;
    string category;
};

// Order structure
struct Order {
    int orderID;
    int productID;
    int quantity;
    string customerID;
    time_t orderDate;
};

// Function to display the order date in a readable format
string formatTime(time_t orderDate) {
    char buffer[26];  // Buffer to store formatted time
    #ifdef _WIN32
        ctime_s(buffer, sizeof(buffer), &orderDate);  // Windows (MSVC)
    #else
        ctime_r(&orderDate, buffer);  // Linux/macOS (GCC/Clang)
    #endif
    return string(buffer);
}

int main() {
    // List of products
    vector<Product> products = {
        {101, "Laptop", "Electronics"},
        {102, "Smartphone", "Electronics"},
        {103, "Coffee Maker", "Kitchen"},
        {104, "Blender", "Kitchen"},
        {105, "Desk Lamp", "Home"}
    };

    // Recent customers in a deque
    deque<string> recentCustomers = {"C001", "C002", "C003"};
    recentCustomers.push_back("C004");
    recentCustomers.push_front("C005");

    // Order history in a list
    list<Order> orderHistory = {
        {1, 101, 1, "C001", time(0)},
        {2, 102, 2, "C002", time(0)},
        {3, 103, 1, "C003", time(0)}
    };

    // Unique product categories using a set
    set<string> categories;
    for (const auto &product : products) {
        categories.insert(product.category);
    }

    // Product stock (ProductID -> Quantity)
    map<int, int> productStock = {
        {101, 10},
        {102, 20},
        {103, 15},
        {104, 5},
        {105, 7}
    };

    // Customer orders stored in a multimap
    multimap<string, Order> customerOrders;
    for (const auto &order : orderHistory) {
        customerOrders.insert({order.customerID, order});
    }

    // Customer data using an unordered map
    unordered_map<string, string> customerData = {
        {"C001", "Nancy"},
        {"C002", "Prasanna"},
        {"C003", "Shreecha"},
        {"C004", "Abhinav"},
        {"C005", "Sauru"}
    };

    // Unique product IDs using an unordered set
    unordered_set<int> uniqueProductIDs;
    for (const auto &product : products) {
        uniqueProductIDs.insert(product.productID);
    }

    // OUTPUT
    cout << "===== PRODUCTS LIST =====\n";
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(15) << "Category" << "\n";
    cout << "---------------------------------------\n";
    for (const auto &p : products) {
        cout << left << setw(10) << p.productID << setw(20) << p.name << setw(15) << p.category << "\n";
    }
    cout << "\n";

    cout << "===== RECENT CUSTOMERS =====\n";
    for (const auto &cust : recentCustomers) {
        cout << cust << " ";
    }
    cout << "\n\n";

    cout << "===== ORDER HISTORY =====\n";
    cout << left << setw(10) << "OrderID" << setw(10) << "ProductID" << setw(10) << "Qty" << setw(10) << "CustomerID" << "Order Date\n";
    cout << "---------------------------------------------------------------\n";
    for (const auto &order : orderHistory) {
        cout << left << setw(10) << order.orderID << setw(10) << order.productID << setw(10) << order.quantity
             << setw(10) << order.customerID << formatTime(order.orderDate);
    }
    cout << "\n";

    cout << "===== PRODUCT CATEGORIES =====\n";
    for (const auto &cat : categories) {
        cout << cat << "\n";
    }
    cout << "\n";

    cout << "===== PRODUCT STOCK =====\n";
    cout << left << setw(10) << "ProductID" << "Stock\n";
    cout << "----------------------------\n";
    for (const auto &stock : productStock) {
        cout << left << setw(10) << stock.first << stock.second << "\n";
    }
    cout << "\n";

    cout << "===== CUSTOMER ORDERS =====\n";
    cout << left << setw(10) << "CustomerID" << setw(10) << "OrderID" << setw(10) << "ProductID" << setw(10) << "Qty" << "Order Date\n";
    cout << "------------------------------------------------------------\n";
    for (const auto &entry : customerOrders) {
        cout << left << setw(10) << entry.first << setw(10) << entry.second.orderID << setw(10) << entry.second.productID
             << setw(10) << entry.second.quantity << formatTime(entry.second.orderDate);
    }
    cout << "\n";

    cout << "===== CUSTOMER DATA =====\n";
    for (const auto &cust : customerData) {
        cout << "Customer ID: " << cust.first << ", Name: " << cust.second << "\n";
    }
    cout << "\n";

    cout << "===== UNIQUE PRODUCT IDs =====\n";
    for (const auto &id : uniqueProductIDs) {
        cout << id << " ";
    }
    cout << "\n";

    return 0;
}
