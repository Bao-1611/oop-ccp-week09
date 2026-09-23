#include <iostream>
#include <string>

using namespace std;

struct Food {
    string id;
    string name;
    double price;
    int quantity; 
};

struct Order {
    string id;
    string customerName;
    string address;
    Food food;
    int quantity;
    string status;
};

struct Restaurant {
    string name;
    string address;
    string phone;
    
    Food foods[100];
    int foodCount = 0;
    
    Order orders[100];
    int orderCount = 0;
};

// Chuc nang 1: Nhap thong tin cua hang
void inputRestaurantInfo(Restaurant &res) {
    cin.ignore();
    cout << "\n=== NHAP THONG TIN CUA HANG ===\n";
    cout << "Nhap ten cua hang: ";
    getline(cin, res.name);
    cout << "Nhap dia chi cua hang: ";
    getline(cin, res.address);
    cout << "Nhap so dien thoai: ";
    getline(cin, res.phone);
    cout << "=> Cap nhat thong tin cua hang thanh cong!\n";
}

// Chuc nang 2: Them mon an moi
void addFood(Restaurant &res) {
    if (res.foodCount >= 100) {
        cout << "Danh sach mon an da day!\n";
        return;
    }
    Food f;
    cout << "\n=== THEM MON AN MOI ===\n";
    cout << "Nhap ma mon: ";
    cin >> f.id;
    cin.ignore();
    cout << "Nhap ten mon: ";
    getline(cin, f.name);
    cout << "Nhap don gia: ";
    cin >> f.price;
    cout << "Nhap so luong con lai: ";
    cin >> f.quantity;

    res.foods[res.foodCount] = f;
    res.foodCount++;
    cout << "=> Them mon an thanh cong!\n";
}

// Chuc nang 3: Hien thi danh sach mon an
void displayFoods(const Restaurant &res) {
    cout << "\n=== DANH SACH MON AN ===\n";
    if (res.foodCount == 0) {
        cout << "(Chua co mon an nao trong danh sach)\n";
        return;
    }
    for (int i = 0; i < res.foodCount; i++) {
        cout << i + 1 << ". [Ma: " << res.foods[i].id << "] " 
             << res.foods[i].name 
             << " | Gia: " << res.foods[i].price << " VNĐ"
             << " | Con lai: " << res.foods[i].quantity << "\n";
    }
}

// Chuc nang 4: Tim mon an theo ma hoac ten
void searchFood(const Restaurant &res) {
    cin.ignore();
    string key;
    cout << "\nNhap ma hoac ten mon an can tim: ";
    getline(cin, key);

    bool found = false;
    for (int i = 0; i < res.foodCount; i++) {
        if (res.foods[i].id == key || res.foods[i].name.find(key) != string::npos) {
            cout << "Tim thay: [Ma: " << res.foods[i].id << "] " 
                 << res.foods[i].name << " - Gia: " << res.foods[i].price 
                 << " - So luong: " << res.foods[i].quantity << "\n";
            found = true;
        }
    }
    if (!found) cout << "Khong tim thay mon an phu hop!\n";
}

// Chuc nang 5: Cap nhat gia hoac so luong mon an
void updateFoodInfo(Restaurant &res) {
    string id;
    cout << "\nNhap ma mon an can cap nhat: ";
    cin >> id;

    for (int i = 0; i < res.foodCount; i++) {
        if (res.foods[i].id == id) {
            cout << "1. Cap nhat don gia\n";
            cout << "2. Cap nhat so luong con lai\n";
            cout << "Chon tuy chon (1-2): ";
            int opt;
            cin >> opt;
            if (opt == 1) {
                cout << "Nhap don gia moi: ";
                cin >> res.foods[i].price;
            } else if (opt == 2) {
                cout << "Nhap so luong moi: ";
                cin >> res.foods[i].quantity;
            }
            cout << "=> Cap nhat thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay mon an voi ma nay!\n";
}
