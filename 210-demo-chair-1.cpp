#include <iostream>
#include <iomanip>

using namespace std;
const int SIZE = 3, MIN = 10000, MAX = 99999, MIN_LEGS = 3, LEGS_RANGE = 2;

class Chair {
private:
    int legs;
    double * prices;
public:
    // Default constructor
    // Randomly selects 3 or 4 legs and generates random prices between $100.00 and $999.99
        Chair() {
        prices = new double[SIZE];
        legs = rand() % LEGS_RANGE + MIN_LEGS;
        for (int i = 0; i < SIZE; i++){
            prices[i] = (rand() % (MAX - MIN + 1) + MIN) / 100.0;
        }
    }
    // Parameterized constructor
    // Takes the number of legs and initializes prices to 0
    Chair(int l) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = 0;
    }
    // Parameterized constructor
    // Takes the number of legs and an array of prices
    Chair(int l, double p[SIZE]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = p[i];
    }
    // Destructor
    ~Chair(){
        delete[] prices;
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->print();

    //creating dynamic chair object with single-parameter constructor
    Chair *livingChair = new Chair(3);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic chair object with double-parameter constructor
    double p[SIZE];
    for (int i = 0; i < SIZE; i++)
        p[i] = (rand() % (MAX - MIN + 1) + MIN) / 100.0;
    livingChair = new Chair(3, p);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    
    delete[] collection;
    return 0;
}