#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

//coded by jhm69

using namespace std;

class Medicine {
public:
    Medicine();

    int id, unitePrice, quantity;
    bool isSold;
    string name, companyName, arrivalDate, expireDate;

    Medicine(int id, int unitePrice, int quantity, bool isSold, const string &name, const string &companyName,
             const string &arrivalDate, const string &expireDate) : id(id), unitePrice(unitePrice), quantity(quantity),
                                                                    isSold(isSold), name(name),
                                                                    companyName(companyName), arrivalDate(arrivalDate),
                                                                    expireDate(expireDate) {}

    int getId() const {
        return id;
    }

    void setId(int id) {
        Medicine::id = id;
    }

    int getUnitePrice() const {
        return unitePrice;
    }

    void setUnitePrice(int unitePrice) {
        Medicine::unitePrice = unitePrice;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int quantity) {
        Medicine::quantity = quantity;
    }

    bool isSold1() const {
        return isSold;
    }

    void setIsSold(bool isSold) {
        Medicine::isSold = isSold;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Medicine::name = name;
    }

    const string &getCompanyName() const {
        return companyName;
    }

    void setCompanyName(const string &companyName) {
        Medicine::companyName = companyName;
    }

    const string &getArrivalDate() const {
        return arrivalDate;
    }

    const bool getIsStock() const {
        if (quantity > 0) return true;
        return false;
    }


    void setArrivalDate(const string &arrivalDate) {
        Medicine::arrivalDate = arrivalDate;
    }

    const string &getExpireDate() const {
        return expireDate;
    }

    void setExpireDate(const string &expireDate) {
        Medicine::expireDate = expireDate;
    }

private:
};

class Sale {
public:
    Sale();

    int id, quantity;
    string date, customerName;
    Medicine medicine;

    Sale(int id, int quantity, const string &date, const string &customerName, const Medicine &medicine) : id(id),
                                                                                                           quantity(
                                                                                                                   quantity),
                                                                                                           date(date),
                                                                                                           customerName(
                                                                                                                   customerName),
                                                                                                           medicine(
                                                                                                                   medicine) {}

    int getTotalAmount() const {
        return medicine.getUnitePrice() * quantity;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        Sale::id = id;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int quantity) {
        Sale::quantity = quantity;
    }

    const string &getDate() const {
        return date;
    }

    void setDate(const string &date) {
        Sale::date = date;
    }

    const string &getCustomerName() const {
        return customerName;
    }

    void setCustomerName(const string &customerName) {
        Sale::customerName = customerName;
    }

    const Medicine &getMedicine() const {
        return medicine;
    }

    void setMedicine(const Medicine &medicine) {
        Sale::medicine = medicine;
    }


};

class Shop {
public:
    vector<Medicine> medicineList;
    vector<Sale> salesList;

    void initMedicineList() {
        Medicine medicine1 = Medicine(1, 40, 40, false, "Napa Extra", "Square ltd", "25-3-2021", "25-3-2022");
        medicineList.push_back(medicine1);
        Medicine medicine2 = Medicine(2, 10, 20, false, "Paracetamol ", "Vector ltd", "22-3-2021", "25-7-2022");
        medicineList.push_back(medicine2);
        Medicine medicine3 = Medicine(3, 20, 10, false, "Taxmen Syrup", "Cube ltd", "21-3-2021", "22-3-2022");
        medicineList.push_back(medicine3);
    }

    void printMedicines() {
        cout << "ID" << "\t" << "Name" << "\t\t" << "Company Name" << "\t" << "Unit Price" << "\t" << "In Stock" << "\t"
             << "Quantity" << "\t" << "Arrival Date" << "\t" << "Expire Date" << endl;
        for (int i = 0; i < medicineList.size(); i++) {
            Medicine medicine = medicineList[i];
            cout << i + 1 << "\t" << medicine.getName() << "\t" << medicine.getCompanyName() << "\t    "
                 << medicine.getUnitePrice() << "\t\t   " << medicine.getIsStock() << "\t\t  " << medicine.getQuantity()
                 << "\t\t  " << medicine.getArrivalDate() << "\t" << medicine.getExpireDate() << endl;
        }
    }

    void printMedicine(int i) {
        cout << "ID" << "\t" << "Name" << "\t\t" << "Company Name" << "\t" << "Unit Price" << "\t" << "In Stock" << "\t"
             << "Quantity" << "\t" << "Arrival Date" << "\t" << "Expire Date" << endl;
        Medicine medicine = medicineList[i];
        cout << i + 1 << "\t" << medicine.getName() << "\t" << medicine.getCompanyName() << "\t    "
             << medicine.getUnitePrice() << "\t\t   " << medicine.getIsStock() << "\t\t  " << medicine.getQuantity()
             << "\t\t  " << medicine.getArrivalDate() << "\t" << medicine.getExpireDate() << endl;
    }

    void printSale(Sale sale) {
        cout << "ID" << "\t" << "Customer Name" << "\t" << "Medicine Name" << "\t" << "Medicine Company" << "\t"
             << "Quantity" << "\t" << "Unit Price" << "\t" << "Total Amount" << "\t" << "Date" << endl;
        Medicine medicine = sale.medicine;
        cout << sale.id << "\t" << sale.customerName << "\t" << medicine.getName() << "\t" << medicine.getCompanyName()
             << "\t" << sale.quantity << "\t" << medicine.unitePrice << "\t" << sale.getTotalAmount() << "\t"
             << sale.getDate() << endl;
    }

    void totalSalesReport() {
        if (salesList.size() == 0) {
            cout << "Empty sold list, No medicine sold yet. " << endl;
        } else {
            cout << "ID" << "\t" << "Customer Name" << "\t" << "Medicine Name" << "\t" << "Medicine Company" << "\t"
                 << "Quantity" << "\t" << "Unit Price" << "\t" << "Total Amount" << "\t" << "Date" << endl;

            for (int i = 0; i < salesList.size(); i++) {
                Medicine medicine = salesList[i].medicine;
                cout << salesList[i].id << "\t" << salesList[i].customerName << "\t\t   " << medicine.getName() << "\t"
                     << medicine.getCompanyName() << "\t\t" << salesList[i].quantity << "\t" << medicine.unitePrice
                     << "\t"
                     << salesList[i].getTotalAmount() << "\t" << salesList[i].getDate() << endl;
            }
        }
    }


    void addNewSale() {
        int index, ignore;
        int quantity;
        string name, date;

        cout << "Select the index of Medicine which you want to sell:" << endl;
        printMedicines();
        cin >> index;
        cout << "Your selected Medicine is:" << endl;
        printMedicine(index - 1);

        Medicine medicine = medicineList[index - 1];
        medicine.isSold = true;
        medicine.quantity--;
        medicineList[index - 1] = medicine;

        cout << "Enter Customer Name:" << endl;
        cin >> name;
        cout << "Enter Date:" << endl;
        cin >> date;
        cout << "Enter Quantity:" << endl;
        cin >> quantity;
        Sale s = Sale(salesList.size() + 1, quantity, date, name, medicine);

        cout << "Your New Sell Summery is:" << endl;
        printSale(s);

        cout << "Press any kew to Confirm:" << endl;
        cin >> ignore;
        salesList.push_back(s);

    }


    void addNewMedicine() {
        string name, companyName, arrivalDate, expireDate;
        int unitPrice, quantity;
        cout << "Enter Medicine Name:" << endl;
        cin >> name;
        cout << "Enter Medicine Company Name:" << endl;
        cin >> companyName;
        cout << "Enter Unit Price:" << endl;
        cin >> unitPrice;
        cout << "Enter Arrival date:" << endl;
        cin >> arrivalDate;
        cout << "Enter Expire date:" << endl;
        cin >> expireDate;
        cout << "Enter Quantity:" << endl;
        cin >> quantity;

        Medicine medicine = Medicine(medicineList.size() + 1, unitPrice, quantity, false, name, companyName,
                                     arrivalDate, expireDate);

        medicineList.push_back(medicine);

        cout << "Added Medicine, New Medicines List is:" << endl;
        printMedicines();
    }

    void deleteMedicineFromStock() {
        try {
            int index, ignore;
            cout << "You need to Enter the Medicine id to delete: So select medicine id from here" << endl;
            printMedicines();
            cin >> index;
            cout << "Your selected Medicine is:" << endl;
            printMedicine(index - 1);
            cout << "Press any kew to confirm:" << endl;
            cin >> ignore;
            medicineList.erase(medicineList.begin() + index - 1);
            cout << "Deleted. New Medicine List is:" << endl;
            printMedicines();
        } catch (exception d) {
            cout << "error occurs" << endl;
        }
    }

    void updateMedicineDetails() {
        int index;
        cout << "You need to Enter the Medicine id to Edit: So select medicine id from here" << endl;
        printMedicines();
        cin >> index;
        cout << "Your selected Medicine is:" << endl;
        printMedicine(index - 1);
        cout << "What do you want to update? " << endl;

        Medicine medicine = medicineList[index - 1];

        cout << "Enter Updated Medicine Name:" << endl;
        cin >> medicine.name;
        cout << "Enter Updated Medicine Company Name:" << endl;
        cin >> medicine.companyName;
        cout << "Enter Updated Unit Price:" << endl;
        cin >> medicine.unitePrice;
        cout << "Enter Updated Arrival date:" << endl;
        cin >> medicine.arrivalDate;
        /* cout<<"Enter Updated Expire date:"<<endl;
         cin>>medicine.expireDate;*/
        cout << "Enter Updated Quantity date:" << endl;
        cin >> medicine.quantity;

        medicineList[index - 1] = medicine;

        cout << "Edited. New Medicine List is:" << endl;
        printMedicines();
    }


    void soldMedicinesList() {
        if (salesList.size() == 0) {
            cout << "No medicine sold yet" << endl;
        } else {
            int amount=0;
            cout << "ID" << "\t" << "Name" << "\t" << "Company Name" << "\t" << "Unit Price" << "\t" << "In Stock"
                 << "\t" << "Arrival Date" << "\t" << "Expire Date" << endl;
            for (int i = 0; i < medicineList.size(); i++) {
                Medicine medicine = medicineList[i];
                if (medicine.isSold) {
                    cout << i + 1 << "\t" << medicine.getName() << "\t" << medicine.getCompanyName() << "\t"
                         << medicine.getUnitePrice() << "\t" << false << "\t" << medicine.getArrivalDate() << "\t"
                         << medicine.getExpireDate() << endl;
                }
                amount+=salesList[i].getTotalAmount();
            }
            cout<<"Total medicines sold: "<<salesList.size()<<endl;
            cout<<"Total Amount: "<<amount<<endl;

        }
    }
};

int main() {
    system("COLOR 0");
    Shop shop;
    shop.initMedicineList();
    int menu;
    do {
        system("cls");
        cout << "Please chose an option: \n \n";

        cout << "\t1. Add New Sale \t\n";
        cout << "\t2. View All Medicine \t\n";
        cout << "\t3. Sold Medicines List \t\n";
        cout << "\t4. Add New Medicines\t\n";
        cout << "\t5. Update Medicine Details \t\n";
        cout << "\t6. Delete Medicine From Stock \t\n";
        cout << "\t7. Total Sales Report\t\n\n";
        cout << "Enter your choice: ";

        cin >> menu;

        switch (menu) {
            case 1: {
                shop.addNewSale();
                system("PAUSE");
                break;
            }

            case 2: {
                shop.printMedicines();
                system("PAUSE");
                break;
            }

            case 3: {
                shop.soldMedicinesList();
                system("PAUSE");
                break;
            }

            case 4: {
                shop.addNewMedicine();
                system("PAUSE");
                break;
            }
            case 5: {
                shop.updateMedicineDetails();
                system("PAUSE");
                break;
            }
            case 6: {
                shop.deleteMedicineFromStock();
                system("PAUSE");
                break;
            }
            case 7: {
                shop.totalSalesReport();
                system("PAUSE");
                break;
            }
            default: {
                cout << "You enter invalid input\nre-enter the input\n" << endl;
                break;
            }
        }
    } while (menu != 7);
    return 0;
}