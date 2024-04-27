#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <algorithm>

using namespace std;


class Product {
public:
    string name;
    double price;
    int quantity;

    Product(string n, double p, int q) : name(n), price(p), quantity(q) {}

    bool isEmpty() { //Является ли объеект пустым
        return name == "" && price <= 0 && quantity <= 0;
    }

    bool validate() {//Проверка на правильность значений
        return name != "" && price > 0 && quantity >= 0;
    }

    string getQuentity(bool show = true) {
        if (quantity == 0) {
            return "out of stock";
        }
        return (show) ? to_string(quantity) : "in stock";
    }


    void update() {
        Product from = formProduct();

        if (from.validate()) {
            name = from.name;
            price = from.price;
            quantity = from.quantity;

            return;
        }
        cout << "Wrong update" << endl;
        throw "Cant update";

    }
    void increment(int value = 1, bool clear = false) {
        (!clear) ? quantity += value : quantity = value;
    }

    static Product formProduct() { //форма для создания или обновления продукта
        string _name, _price, _quantity;

        cout << "Enter name: ";
        cin >> _name;
        cout << "Enter price: ";
        cin >> _price;
        cout << "Enter quantity: ";
        cin >> _quantity;

        return Product(_name, atof(_price.c_str()), atoi(_quantity.c_str()));
    }

};
int get_index(Product pr, vector<Product> products) {
    int col = 0;
    for (auto& p : products) {
        if (p.name == pr.name) return col;
        col++;
    }
    return -1;
}
class ShoppingCart {
public:
    vector<Product> products;

    void addProduct(Product p) {

        if (p.isEmpty()) return;

        if (p.quantity <= 0) {
            cout << "You can't add that much" << endl;
            return;
        }

        int index = get_index(p, products);
        if (index != -1) {

            get(index).increment();

            return;
        }

        products.push_back(copy(p));
    }

    void display() {
        double sum = 0; int col = 1;
        for (auto& p : products) {
            cout << col << ". Product: " << p.name << ", Price: $" << p.price << ", Quantity: " << p.quantity << endl;
            sum += p.price * p.quantity;
            col++;
        }
        cout << "______________________" << endl;
        cout << "Total Sum: " << sum << endl;
    }

    void updateProduct(int index) {
        try {
            string quantity;
            cout << "Enter quantity: " << endl;
            cin >> quantity;

            int q = atoi(quantity.c_str());
            if (q <= 0) throw "Wrong quantity";

            get(index).increment(q, true);

            cout << "Success update" << endl;
        }
        catch (const char* error) {
            cout << "No such product" << endl;
        }

    }

    void deleteProduct(int index) {
        try {

            products.erase(products.begin() + index);

            cout << "Success delete" << endl;
        }
        catch (const char* error) {
            cout << "No such product" << endl;
        }
    }
    Product& get(int index) {
        return products.at(index);
    }

    Product copy(Product pr) {
        return Product(pr.name, pr.price, 1);
    }

    bool checkCode(int index) {
        return products.size() > index && index >= 0;
    }
};

static class Store {
public:
    static vector<Product> inventory;


    static void addProductToInventory(Product p) {

        if (p.validate()) {

            int index = get_index(p, inventory);
            if (index != -1) {
                Product exist = get(index);
                exist.quantity += p.quantity;
            }
            else {
                inventory.push_back(p);
                return;
            }
        }
        cout << "It is impossible to add" << endl;
    }

    static void updateProduct(int index) {
        try {
            get(index).update();
            cout << "Success update" << endl;
        }
        catch (const char* error) {
            cout << "No such product" << endl;
        }

    }

    static void deleteProduct(int index) {
        try {
            inventory.erase(inventory.begin() + index);
            cout << "Success delete" << endl;
        }
        catch (const char* error) {
            cout << "No such product" << endl;
        }
    }

    static void display(bool admin = true) {
        int col = 1;
        for (auto& p : inventory) {

            cout << col << ". Product: " << p.name << ", Price: $" << p.price << ", Quantity: " << p.getQuentity(admin) << endl;
            col++;
        }
    }

    static Product findProductByName(string name, int quantity) {
        for (auto& p : inventory) {
            if (p.name == name && p.quantity >= quantity) {
                p.quantity -= quantity;
                return Product(p.name, p.price, quantity);
            }
        }

        cout << "There is no such product or there is not enough in stock" << endl;
        return Product("", 0.0, 0);
    }


    static Product& get(int index) {
        return inventory.at(index);
    }

    static bool checkCode(int index) {
        return inventory.size() > index && index >= 0;
    }
};



//Generic-метод для получения кода продукта из списка
template <typename T>
int getCode(T& obj, bool clientFlag = true) {
    (clientFlag) ? obj.display() : Store::display(clientFlag);

    string code;

    try {
        cout << "Enter product code: ";
        cin >> code;

        int cmd = atoi(code.c_str());

        if (obj.checkCode(cmd - 1)) return cmd - 1;
        throw "Code is not exist";

    }
    catch (const char* error) {
        cout << "Wrong code or format" << endl;
        return -1;
    }
}

//Запрос на ввод пароля
bool get_pwd(string true_pwd) {

    string password = "";
    char ch;

    cout << "Enter password: ";

    // Считываем символы с клавиатуры до нажатия клавиши Enter
loop:while ((ch = _getch()) != '\r') { // В Windows символ Enter имеет код '\r', в Linux/Mac - '\n'
    if (ch == '\b') { // Если нажата клавиша Backspace
        if (!password.empty()) {
            cout << "\b \b"; // Удаляем последний символ из вывода
            password.pop_back(); // Удаляем последний символ из строки пароля
        }
    }
    else {
        cout << '*'; // Выводим символ * вместо вводимых символов
        password += ch; // Добавляем символ к строке пароля
    }
}
cout << endl;

if (password != "" && password != true_pwd) {
    cout << "Wrong password!" << endl;
    cout << "Try again: ";
    password = "";
    goto loop;
}

return password != "" && password == true_pwd;
}

//Создает окно админа
void admin() {
    const string pwd = "1234";

    if (!get_pwd(pwd)) return;
    else {
        string cmd;
        Store store;
        do {
            cout << "____________________" << endl;
            cout << "1. Add product" << endl;
            cout << "2. Update product" << endl;
            cout << "3. Delete product" << endl;
            cout << "4. Show products" << endl;
            cout << "5. Exit" << endl;
            cout << "____________________" << endl;


            cin >> cmd;

            if (cmd == "1") Store::addProductToInventory(Product::formProduct());
            else if (cmd == "2") {

                int code = getCode<Store>(store);
                if (code < 0) continue;

                Store::updateProduct(code);
            }
            else if (cmd == "3") {
                int code = getCode<Store>(store);
                if (code < 0) continue;

                Store::deleteProduct(code);
            }
            else if (cmd == "4") Store::display();
            else if (cmd == "5") break;
            else cout << "No such command" << endl;


        } while (true);
    }
}

//Создает окно клиента
void client() {

    ShoppingCart cart;
    Store store;
    do {
        string cmd;

        cout << "____________________" << endl;
        cout << "1. Show store" << endl;
        cout << "2. Add product to backet" << endl;
        cout << "3. Delete from backet" << endl;
        cout << "4. Change quantity" << endl;
        cout << "5. Show backet" << endl;
        cout << "6. Exit" << endl;
        cout << "____________________" << endl;

        cin >> cmd;

        if (cmd == "1") Store::display(false);
        else if (cmd == "2") {

            int code = getCode<Store>(store, false);
            if (code < 0) continue;

            cart.addProduct(Store::get(code));
        }
        else if (cmd == "3") {
            cart.display();

            int code = getCode<ShoppingCart>(cart);
            if (code < 0) continue;

            cart.deleteProduct(code);
        }
        else if (cmd == "4") {
            cart.display();

            int code = getCode<ShoppingCart>(cart);
            if (code < 0) continue;

            cart.updateProduct(code);
        }
        else if (cmd == "5") cart.display();
        else if (cmd == "6") break;
        else cout << "No such command" << endl;;



    } while (true);
}

vector<Product> Store::inventory;//инициализация статического поля (во избежании ошибки)

int main() {
    string cmd;

    do {
        cout << "____________________" << endl;
        cout << "1. Log in as an admin" << endl;
        cout << "2. Log in as an client" << endl;
        cout << "3. Exit" << endl;
        cout << "____________________" << endl;

        cin >> cmd;

        if (cmd == "1") admin();
        else if (cmd == "2") client();
        else if (cmd == "3") break;
        else cout << "No such command" << endl;


    } while (true);



    return 0;
}
