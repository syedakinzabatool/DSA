#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <ctime>
#include <conio.h>
#include <cstdlib>
#include <windows.h>

using namespace std;
// Structs
struct Customer
{
    int age;
    string name;
    string pizzaName;
    int quantity;
    double bill;
    time_t orderTime;
    string orderType;

    Customer() {}

    Customer(int age, string name, int quantity, string pizzaName, double bill, string orderType)
        : age(age), name(name), pizzaName(pizzaName), quantity(quantity), bill(bill), orderType(orderType)
    {
        orderTime = time(nullptr);
    }
};
struct takeAwayCustomer
{
    Customer customer;
    takeAwayCustomer *next = NULL;

    takeAwayCustomer(int age, string name, int quantity, string pizzaName, double bill, string orderType)
    {
        this->customer = Customer(age, name, quantity, pizzaName, bill, orderType);
    }
};

struct dineInCustomer
{
    Customer customer;
    dineInCustomer *next = NULL;

    dineInCustomer(int age, string name, int quantity, string pizzaName, double bill, string orderType)
    {
        this->customer = Customer(age, name, quantity, pizzaName, bill, orderType);
    }
};

struct PizzaShop
{
    string shopName;
    string *menu;
    int *price;
    string address;
    takeAwayCustomer *nextTakeAwayCustomer = NULL;
    dineInCustomer *nextDineInCustomer = NULL;
};

struct servedCustomer
{
    int age;
    string name;
    int quantity;
    string pizzaName;
    double bill;
    string CustomerType;
    time_t orderTime;
    int height = 1;
    servedCustomer *left;
    servedCustomer *right;

    servedCustomer(int age, string name, int quantity, string pizzaName, double bill, string CustomerType)
    {
        this->age = age;
        this->name = name;
        this->quantity = quantity;
        this->pizzaName = pizzaName;
        this->bill = bill;
        this->CustomerType = CustomerType;
        this->orderTime = time(nullptr);
        this->left = NULL;
        this->right = NULL;
    }
};

// Global Variables
PizzaShop *myPizzaShop = NULL;

takeAwayCustomer *currentTakeAwayCustomer = NULL;
dineInCustomer *currentDineInCustomer = NULL;

double total, takeAway, dineIn, servedTotal;
servedCustomer *root = NULL;

void saveTakeawayOrder(const takeAwayCustomer &customer)
{
    ofstream takeawayFile("takeaway_orders.txt", ios::app);
    if (takeawayFile.is_open())
    {
        takeawayFile << "Name: " << customer.customer.name << "\n"
                     << "Age: " << customer.customer.age << "\n"
                     << "Pizza: " << customer.customer.pizzaName << "\n"
                     << "Quantity: " << customer.customer.quantity << "\n"
                     << "Bill: " << customer.customer.bill << "\n"
                     << "Order Type: " << customer.customer.orderType << "\n"
                     << "-----------------------------------\n";
        takeawayFile.close();
    }
    else
    {
        cout << "Unable to open takeaway orders file." << endl;
    }
}

void saveDineInOrder(const dineInCustomer &customer)
{
    ofstream dineInFile("dinein_orders.txt", ios::app);
    if (dineInFile.is_open())
    {
        dineInFile << "Name: " << customer.customer.name << "\n"
                   << "Age: " << customer.customer.age << "\n"
                   << "Pizza: " << customer.customer.pizzaName << "\n"
                   << "Quantity: " << customer.customer.quantity << "\n"
                   << "Bill: " << customer.customer.bill << "\n"
                   << "Order Type: " << customer.customer.orderType << "\n"
                   << "-----------------------------------\n";
        dineInFile.close();
    }
    else
    {
        cout << "Unable to open dine-in orders file." << endl;
    }
}
string readAdminPassword()
{
    string password;
    ifstream passwordFile("admin_password.txt");
    if (passwordFile.is_open())
    {
        getline(passwordFile, password);
        passwordFile.close();
    }
    else
    {
        cout << "Error: Could not open password file." << endl;
    }
    return password;
}
void deleteTakeawayOrder(const string &customerName)
{
    ifstream takeawayFile("takeaway_orders.txt");
    ofstream tempFile("temp_takeaway_orders.txt");
    string line;
    bool found = false;

    if (takeawayFile.is_open() && tempFile.is_open())
    {
        while (getline(takeawayFile, line))
        {

            if (line.find("Name: " + customerName) != string::npos)
            {
                found = true;
                for (int i = 0; i < 5; i++)
                {
                    getline(takeawayFile, line);
                }
                getline(takeawayFile, line);
                continue;
            }
            tempFile << line << endl;
        }
        takeawayFile.close();
        tempFile.close();

        remove("takeaway_orders.txt");
        rename("temp_takeaway_orders.txt", "takeaway_orders.txt");

        if (found)
        {
            cout << "Order for " << customerName << " removed from takeaway orders file." << endl;
        }
        else
        {
            cout << "Order for " << customerName << " not found in takeaway orders file." << endl;
        }
    }
    else
    {
        cout << "Unable to open takeaway orders file." << endl;
    }
}
void deleteDineInOrder(const string &customerName)
{
    ifstream dineInFile("dinein_orders.txt");
    ofstream tempFile("temp_dinein_orders.txt");

    string line;
    bool found = false;
    if (dineInFile.is_open() && tempFile.is_open())
    {
        while (getline(dineInFile, line))
        {
            if (line.find("Name: " + customerName) != string::npos)

            {
                found = true;
                for (int i = 0; i < 5; i++)
                {
                    getline(dineInFile, line);
                }
                getline(dineInFile, line);
                continue;
            }
            tempFile << line << endl;
        }
        dineInFile.close();
        tempFile.close();

        remove("dinein_orders.txt");
        rename("temp_dinein_orders.txt", "dinein_orders.txt");
        if (found)
        {
            cout << "Order for " << customerName << " removed from dine-in orders file." << endl;
        }
        else
        {
            cout << "Order for " << customerName << " not found in dine-in orders file." << endl;
        }
    }
    else
    {
        cout << "Unable to open dine-in orders file." << endl;
    }
}

void printTakeawayOrders()
{
    ifstream takeawayFile("takeaway_orders.txt");
    string line;
    if (takeawayFile.is_open())
    {
        while (getline(takeawayFile, line))
        {
            cout << line << endl;
        }
        takeawayFile.close();
    }
    else
    {
        cout << "Unable to open takeaway orders file." << endl;
    }
}
void printDineInOrders()
{
    ifstream dineInFile("dinein_orders.txt");
    string line;
    if (dineInFile.is_open())
    {
        while (getline(dineInFile, line))
        {
            cout << line << endl;
        }
        dineInFile.close();
    }
    else
    {
        cout << "Unable to open dine-in orders file." << endl;
    }
}
void placeOrderTakeAwayCustomer(int age, string name, string pizzaName, int quantity, double bill)
{
    currentTakeAwayCustomer = new takeAwayCustomer(age, name, quantity, pizzaName, bill, "takeaway");
    if (myPizzaShop->nextTakeAwayCustomer == NULL)
    {
        myPizzaShop->nextTakeAwayCustomer = currentTakeAwayCustomer;
    }
    else
    {
        takeAwayCustomer *temp = myPizzaShop->nextTakeAwayCustomer;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        if (temp->customer.age < currentTakeAwayCustomer->customer.age)
        {
            takeAwayCustomer *firstCustomer = myPizzaShop->nextTakeAwayCustomer;
            myPizzaShop->nextTakeAwayCustomer = currentTakeAwayCustomer;
            currentTakeAwayCustomer->next = firstCustomer;
        }
        else
        {
            temp->next = currentTakeAwayCustomer;
            currentTakeAwayCustomer->next = NULL;
        }
    }
    saveTakeawayOrder(*currentTakeAwayCustomer);
}

void placeOrderDineInCustomer(int age, string name, string pizzaName, int quantity, double bill)
{
    currentDineInCustomer = new dineInCustomer(age, name, quantity, pizzaName, bill, "dinein");

    if (myPizzaShop->nextDineInCustomer == NULL)
    {
        myPizzaShop->nextDineInCustomer = currentDineInCustomer;
    }
    else
    {
        dineInCustomer *temp = myPizzaShop->nextDineInCustomer;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = currentDineInCustomer;
        currentDineInCustomer->next = NULL;
    }
    saveDineInOrder(*currentDineInCustomer);
}
struct Cart
{
    queue<Customer> orders;
    int orderCount = 0;

public:
    void addOrder(Customer customer)
    {
        orders.push(customer);
        cout << "Order added to the cart for " << customer.name << ".\n";
        orderCount++;
    }
    void removeOrder(string customerName)
    {
        if (orders.empty())
        {
            cout << "Cart is empty. No orders to remove.\n";
            return;
        }

        queue<Customer> tempQueue;
        bool found = false;

        while (!orders.empty())
        {
            Customer current = orders.front();
            orders.pop();

            time_t currentTime = time(nullptr);
            double secondsSinceOrder = difftime(currentTime, current.orderTime);
            double minutesSinceOrder = secondsSinceOrder / 60.0;

            if (current.name == customerName)
            {
                if (minutesSinceOrder <= 5)
                {
                    found = true;
                    cout << "Order for " << customerName << " has been successfully canceled." << endl;
                    if (current.orderType == "takeaway")
                    {
                        deleteTakeawayOrder(customerName);
                    }
                    else if (current.orderType == "dinein")
                    {
                        deleteDineInOrder(customerName);
                    }
                    orderCount--;
                }
                else
                {
                    cout << "Order for " << customerName << " cannot be canceled after 5 minutes." << endl;
                    tempQueue.push(current);
                }
            }
            else
            {
                tempQueue.push(current);
            }
        }

        while (!tempQueue.empty())
        {
            orders.push(tempQueue.front());
            tempQueue.pop();
        }

        if (!found)
        {
            cout << "No order found for " << customerName << " to cancel." << endl;
        }
        else
        {
            cout << "Total number of orders in cart after cancellation: " << orderCount << "\n";
        }
    }
};
Cart cart;

void printTakeAwayCustomersforServing()
{
    cout << "Current Take-Away Customers:\n";
    takeAwayCustomer *tempTakeAway = myPizzaShop->nextTakeAwayCustomer;
    if (tempTakeAway == NULL)
    {
        cout << "No Take-Away Customers to serve.\n";
    }
    else
    {
        while (tempTakeAway != NULL)
        {
            cout << "Name: " << tempTakeAway->customer.name << "\n";
            cout << "Age: " << tempTakeAway->customer.age << "\n";
            cout << "Pizza: " << tempTakeAway->customer.pizzaName << "\n";
            cout << "Quantity: " << tempTakeAway->customer.quantity << "\n";
            cout << "Bill: Rs/-" << tempTakeAway->customer.bill << "\n";
            cout << "-----------------------------------\n";
            tempTakeAway = tempTakeAway->next;
        }
    }
}

void printDineInCustomersforServing()
{
    cout << "Current Dine-In Customers:\n";
    dineInCustomer *tempDineIn = myPizzaShop->nextDineInCustomer;
    if (tempDineIn == NULL)
    {
        cout << "No Dine-In Customers to serve.\n";
    }
    else
    {
        while (tempDineIn != NULL)
        {
            cout << "Name: " << tempDineIn->customer.name << "\n";
            cout << "Age: " << tempDineIn->customer.age << "\n";
            cout << "Pizza: " << tempDineIn->customer.pizzaName << "\n";
            cout << "Quantity: " << tempDineIn->customer.quantity << "\n";
            cout << "Bill: Rs/-" << tempDineIn->customer.bill << "\n";
            cout << "-----------------------------------\n";
            tempDineIn = tempDineIn->next;
        }
    }
}

void displayAllOrdersTakeAwayCustomers()
{
    if (myPizzaShop->nextTakeAwayCustomer == NULL)
    {
        cout << "There is no Order for Walking Customer till yet" << endl;
    }
    else
    {
        printTakeawayOrders();
    }
}

void displayAllOrdersDineInCustomers()
{
    if (myPizzaShop->nextDineInCustomer == NULL)
    {
        cout << "There is no Order for Dine-In Customer till yet" << endl;
    }
    else
    {
        printDineInOrders();
    }
}

void displayAllOrders()
{

    cout << "The Take-Away Customers Are :" << endl;
    displayAllOrdersTakeAwayCustomers();

    cout << "The Dine-IN Customers Are :" << endl;
    displayAllOrdersDineInCustomers();
}
void display(servedCustomer *root)
{
    cout << "Name :" << root->name << endl;
    cout << "Age  :" << root->age << endl;
    cout << "Pizza :" << root->pizzaName << endl;
    cout << "Quantity : " << root->quantity << endl;
    cout << "Bill : " << root->bill << endl;
    cout << "Customer Type: " << root->CustomerType << endl;
    cout << "Order Time: " << ctime(&root->orderTime);
}

// Served Customer Manipulation
int isEmpty(servedCustomer *root)
{
    return root == NULL;
}

int getheight(servedCustomer *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}

int getbalance(servedCustomer *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return getheight(root->left) - getheight(root->right);
}

servedCustomer *search(servedCustomer *root, string keyName)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->name == keyName)
    {
        return root;
    }
    else if (root->name < keyName)
    {
        return search(root->right, keyName);
    }
    else if (root->name > keyName)
    {
        return search(root->left, keyName);
    }

    return root;
}

servedCustomer *leftrotation(servedCustomer *root)
{
    servedCustomer *child = root->right;
    servedCustomer *childleft = child->left;
    child->left = root;
    root->right = childleft;

    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    return child;
}

servedCustomer *rightrotation(servedCustomer *root)
{

    servedCustomer *child = root->left;
    servedCustomer *childright = child->right;
    child->right = root;
    root->left = childright;

    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    return child;
}

servedCustomer *insertion(int age, string name, int quantity, string pizzaName, double bill, string CustomerType, servedCustomer *root)
{
    servedCustomer *newNode = new servedCustomer(age, name, quantity, pizzaName, bill, CustomerType);

    if (root == NULL)
    {
        root = newNode;
    }

    else if (newNode->name < root->name)
    {
        root->left = insertion(age, name, quantity, pizzaName, bill, CustomerType, root->left);
    }
    else if (newNode->name > root->name)
    {
        root->right = insertion(age, name, quantity, pizzaName, bill, CustomerType, root->right);
    }

    else
    {
        cout << "No duplicates Values are Allowed " << endl;
        return root;
    }

    int balance = getbalance(root);
    // RR Case
    if (balance < -1 && newNode->name > root->right->name)
    {
        return leftrotation(root);
    }
    // LL Case
    if (balance > 1 && newNode->name < root->right->name)
    {
        return rightrotation(root);
    }
    // LR Case
    if (balance > 1 && newNode->name > root->left->name)
    {
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }
    // RL Case
    if (balance < 1 && newNode->name < root->left->name)
    {
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }
    return root;
}

void serveOrderTakeAwayCustomer()
{
    printTakeAwayCustomersforServing();

    if (myPizzaShop->nextTakeAwayCustomer == NULL)
    {
        cout << "No Take Away Customers to Serve" << endl;
        return;
    }

    string customerName;
    cout << "Enter the name of the Take Away Customer to serve: ";
    cin.ignore();
    getline(cin, customerName);

    takeAwayCustomer *current = myPizzaShop->nextTakeAwayCustomer;
    takeAwayCustomer *previous = NULL;

    while (current != NULL)
    {
        if (current->customer.name == customerName)
        {
            if (previous != NULL)
            {
                previous->next = current->next;
            }
            else
            {
                myPizzaShop->nextTakeAwayCustomer = current->next;
            }

            cout << "Take Away Customer Served: " << current->customer.name << endl;

            string CustomerType = "Take-Away";
            root = insertion(current->customer.age, current->customer.name, current->customer.quantity, current->customer.pizzaName, current->customer.bill, CustomerType, root);

            cout << "Order for " << current->customer.name << " has been inserted into served orders." << endl;

            delete current;
            return;
        }

        previous = current;
        current = current->next;
    }

    cout << "No Take Away Customer found with the name: " << customerName << endl;
}
void serveOrderDineInCustomer()
{
    printDineInCustomersforServing();

    if (myPizzaShop->nextDineInCustomer == NULL)
    {
        cout << "No Dine-In Customers to Serve" << endl;
        return;
    }

    string customerName;
    cout << "Enter the name of the Dine-In Customer to serve: ";
    cin.ignore();
    getline(cin, customerName);

    dineInCustomer *current = myPizzaShop->nextDineInCustomer;
    dineInCustomer *previous = NULL;

    while (current != NULL)
    {
        if (current->customer.name == customerName)
        {

            if (previous != NULL)
            {
                previous->next = current->next;
            }
            else
            {
                myPizzaShop->nextDineInCustomer = current->next;
            }

            cout << "Dine-In Customer Served: " << current->customer.name << endl;

            string CustomerType = "Dine-In";
            root = insertion(current->customer.age, current->customer.name, current->customer.quantity, current->customer.pizzaName, current->customer.bill, CustomerType, root);

            cout << "Order for " << current->customer.name << " has been inserted into served orders." << endl;

            delete current;
            return;
        }

        previous = current;
        current = current->next;
    }

    cout << "No Dine-In Customer found with the name: " << customerName << endl;
}
// Bill Management
void totalbillofPendingOrders()
{
    takeAwayCustomer *p = myPizzaShop->nextTakeAwayCustomer;
    while (p != NULL)
    {
        takeAway += p->customer.bill;
        p = p->next;
    }
    dineInCustomer *q = myPizzaShop->nextDineInCustomer;
    while (q != NULL)
    {
        dineIn += q->customer.bill;
        q = q->next;
    }

    total = takeAway + dineIn;

    cout << "The total bill of pending orders for Take-Away Customers are : " << takeAway << " RS/_" << endl;
    cout << "The total bill of pending orders for Dine-In Customers are : " << dineIn << " RS/_" << endl;
    cout << "The Total orders pending are : " << total << " RS/_" << endl;
}

servedCustomer *displayAllServedOrders(servedCustomer *root)
{

    if (root)
    {
        displayAllServedOrders(root->left);
        display(root);
        displayAllServedOrders(root->right);
    }

    return root;
}

double totalEarnings(servedCustomer *root)
{

    if (root)
    {
        totalEarnings(root->left);
        servedTotal += root->bill;
        totalEarnings(root->right);
    }

    return servedTotal;
}

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 0xF0);
    system("cls");

    myPizzaShop = new PizzaShop;

    myPizzaShop->shopName = "The Pizza Delight";

    myPizzaShop->address = "Liberty Chowk, Lahore";

    myPizzaShop->menu = new string[11]{"",
                                       "Chicken Tikka", "Arabic Ranch",
                                       "Chicken Fajita", "Cheese Lover",
                                       "Chicken Supreme", "All Veggie",
                                       "Garlic West", "Beef Bold",
                                       "Phantom", "Mexican Delight"};

    myPizzaShop->price = new int[11]{0, 2000, 2500, 2400, 2200, 2700, 2000, 2100, 3000, 3000, 2800};

    int option = -99;

    int age, quantity, pizzaIndex;
    double bill;
    string name;
    string userType;
start:
    system("cls");
    cout << "\n\t\t\t--------------------------PIZZA DELIGHT------------------------------------" << endl;
    cout << "\t\t\t-------------------------------------------------------------------------" << endl;
    cout << "\n\t\t\t------------------( WELCOME TO THE Pizza ORDERING SYSTEM )------------------" << endl;

    cout << "\n\t\t\tBRANCH: " << myPizzaShop->address << endl;

    cout << "\t\t\t---------------------------------INSTRUCTIONS FOR CUSTOMERS-----------------------------" << endl;
    cout << "\t\t\tYour comfort is our priority.Please read and follow the following instructions to avoid any inconvenience." << endl;
    cout << "\t\t\t\t1. Choose Your Order Type: Select whether you want to place a Take-Away or Dine-In order." << endl;
    cout << "\t\t\t\t2. Provide Personal Information:" << endl;
    cout << "\t\t\t\t   - Enter your Name (Original Name )." << endl;
    cout << "\t\t\t\t   - Enter your Age (Valid Digits)." << endl;
    cout << "\t\t\t\t3. Order Details:" << endl;
    cout << "\t\t\t\t   - Specify the quantity of pizza you wish to order (Valid Digit)." << endl;
    cout << "\t\t\t\t   - Choose your desired pizza flavor by entering the corresponding number from the menu (1 to 10)." << endl;
    cout << "\t\t\t\t4. Review Your Order: After placing your order, you will see the total bill amount." << endl;
    cout << "\t\t\t\t5. Cancellation: If you wish to cancel your order, you may do so by choosing option to cancel order within 5 minutes after placing order." << endl;
    cout << "\t\t\t\t6. Exit: After placing order you can enter '0' to exit." << endl;

    cout << "\t\t\t\t---------------------------------INSTRUCTIONS FOR ADMIN-----------------------------" << endl;
    cout << "\t\t\t\t1. Login: Enter the correct admin password to access the admin panel." << endl;
    cout << "\t\t\t\t2. Exit: To exit the admin panel, enter '0'." << endl;
    getch();
    system("cls");
    while (true)
    {
        cout << "Are you a Customer or an Admin? (Enter 'c' or 'a'): ";
        cin >> userType;

        if (userType == "c")
        {
            do
            {
                system("cls");

                cout << "\n\t\t\t--------------------------PIZZA DELIGHT------------------------------------" << endl;

                cout << "\t\t\t\t\t_----------(M E N U)--------------_" << endl;

                for (int i = 1; i <= 10; i++)
                {
                    cout << i << ". " << myPizzaShop->menu[i] << " - " << myPizzaShop->price[i] << endl;
                }
                cout << "\t\t\t-------------------------------------------------------------------------" << endl;
                cout << "\t\t\t---------------------------------OPERATIONS------------------------------" << endl;
                cout << "\t\t\t-------------------------------------------------------------------------" << endl;
                cout << "\t\t\t1. Place order for Take-Away Customer" << endl;
                cout << "\t\t\t2. Place order for Dine-In Customer" << endl;
                cout << "\t\t\t3. Cancel Order from Cart" << endl;
                cout << "\t\t\t0: Exit" << endl;

                cout << "Enter your choice: ";
                cin >> option;

                switch (option)
                {
                case 1:
                {
                    cout << "\t\t\tEnter your Name: ";
                    cin >> name;
                    cout << "\t\t\tEnter your Age: ";
                    cin >> age;
                    cout << "\t\t\tEnter the quantity of the pizza: ";
                    cin >> quantity;
                    cout << "\t\t\tChoose Pizza flavour: ";
                    cin >> pizzaIndex;

                    bill = quantity * myPizzaShop->price[pizzaIndex];
                    Customer customer(age, name, quantity, myPizzaShop->menu[pizzaIndex], bill, "takeaway");
                    placeOrderTakeAwayCustomer(age, name, myPizzaShop->menu[pizzaIndex], quantity, bill);
                    cart.addOrder(customer);
                    cout << "Order time is:" << ctime(&customer.orderTime) << endl;
                    cout << "Your bill is:" << bill << endl;
                    cout << "Your order will be ready in 20 minutes :) " << endl;
                    getch();
                    break;
                }

                case 2:
                {
                    cout << "\t\t\tEnter your Name: ";
                    cin >> name;
                    cout << "\t\t\tEnter your Age: ";
                    cin >> age;
                    cout << "\t\t\tEnter the quantity of the pizza: ";
                    cin >> quantity;
                    cout << "\t\t\tEnter the option for the pizza (1-10): ";
                    cin >> pizzaIndex;

                    bill = quantity * myPizzaShop->price[pizzaIndex];

                    Customer customer(age, name, quantity, myPizzaShop->menu[pizzaIndex], bill, "dinein");

                    placeOrderDineInCustomer(age, name, myPizzaShop->menu[pizzaIndex], quantity, bill);
                    cart.addOrder(customer);

                    cout << "Your bill is: " << bill << endl;
                    cout << "Order time is:" << ctime(&customer.orderTime) << endl;
                    cout << "Your order will be ready in 20 minutes :)." << endl;
                    getch();
                    break;
                }
                case 3:
                {
                    string customerName;
                    cout << "Take Away Customers are:" << endl;
                    printTakeawayOrders();
                    cout << "Dine In Customers are:" << endl;
                    printDineInOrders();

                    cout << "\t\t\tEnter the name of the Customer of which you want to cancel the order: ";
                    cin.ignore();
                    getline(cin, customerName);
                    cart.removeOrder(customerName);
                    cout << "\t\t\tOrder cancelled successfully!!" << endl;
                    cout << "Remaining Orders are:" << endl;
                    cout << "Take Away Orders:" << endl;
                    printTakeawayOrders();
                    cout << "Dine In Orders:" << endl;
                    printDineInOrders();
                    getch();
                    break;
                }
                case 0:
                {
                    cout << "Thank you for using our services! Have a great day!" << endl;
                    cout << "Exiting to choose role..." << endl;
                    getch();
                    goto start;
                }
                default:
                    cout << "Invalid option. Please try again." << endl;
                    getch();
                    break;
                }
            } while (option != 0);
        }
        else if (userType == "a")
        {
            string password;
            cout << "Enter password: ";
            cin >> password;

            string storedPassword = readAdminPassword();
            if (password == storedPassword)
            {
                int option = -99;
                do
                {
                    system("cls");
                    cout << "\t\t\t-------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t--------------------------PIZZA DELIGHT----------------------------------" << endl;
                    cout << "\t\t\t-------------------------------------------------------------------------" << endl;

                    cout << "\t\t\t1. Display all orders of Take-Away Customer" << endl;
                    cout << "\t\t\t2. Display all orders of Dine-In Customers" << endl;
                    cout << "\t\t\t3. Display all orders of all Customers" << endl;
                    cout << "\t\t\t4. Serve order for Take-Away Customer" << endl;
                    cout << "\t\t\t5. Serve order for Dine-In Customer" << endl;
                    cout << "\t\t\t6. Display all served Orders" << endl;
                    cout << "\t\t\t7. Search Served Orders " << endl;
                    cout << "\t\t\t8. Display total bill of Pending Orders " << endl;
                    cout << "\t\t\t9. Display the total Earnings of Served Orders " << endl;
                    cout << "\t\t\t0.  EXIT " << endl;

                    cout << "Enter your choice: ";
                    cin >> option;
                    system("cls");

                    switch (option)
                    {
                    case 1:
                        displayAllOrdersTakeAwayCustomers();
                        break;

                    case 2:
                        displayAllOrdersDineInCustomers();
                        break;

                    case 3:
                        displayAllOrders();

                        break;

                    case 4:
                        serveOrderTakeAwayCustomer();
                        break;

                    case 5:
                        serveOrderDineInCustomer();
                        break;
                    case 6:
                    {
                        cout << "Served Orders:\n";
                        servedCustomer *r = displayAllServedOrders(root);
                        if (!r)
                            cout << "No Served Customer yet. " << endl;
                    }
                    break;

                    case 7:
                    {
                        cout << "\t\t\tEnter the name of the Customer you want to search: " << endl;
                        cin >> name;
                        servedCustomer *searchedCustomer = search(root, name);
                        if (searchedCustomer == NULL)
                            cout << "\t\t\tNo such Customer was Served." << endl;
                        else
                        {
                            display(searchedCustomer);
                        }
                    }

                    break;

                    case 8:
                    {
                        takeAway = 0;
                        dineIn = 0;
                        total = 0;
                        totalbillofPendingOrders();
                    }
                    break;

                    case 9:
                    {
                        servedTotal = 0;
                        double totalx = totalEarnings(root);
                        cout << "\t\t\tThe Total Earnings are : " << totalx << endl;
                    }
                    break;
                    case 0:

                        cout << "\t\t\tExiting the program..." << endl;
                        goto start;
                        break;
                    }

                    cout << "Press any key to return to the Admin Panel...";
                    _getch();
                    system("cls");
                } while (option != 0);
            }
            else
            {
                cout << "Invalid password. Access denied." << endl;
            }
        }
        else
        {
            cout << "Invalid user type. Please restart the program." << endl;
        }

        return 0;
    }
}