#include <iostream>
#include <cstring>

class Coffee {
protected:
    char _type[15];

public:
    Coffee() {}
    virtual ~Coffee() {}
    char *getType() { return _type; }
};

class Cappuccino : public Coffee {
public:
    Cappuccino() : Coffee(){
        strcpy(_type, "Cappuccino");
        printf("\nMaking a cup of cappuccino\n");
        printf("Grind and brew one scoop of expresso beans.\n");
        printf("Heat and foam milk.\n");
    }
};

class Espresso : public Coffee {
public:
    Espresso() : Coffee(){
        strcpy(_type, "Espresso");
        printf("\nMaking a cup of espresso\n");
        printf("Grind and brew one scoop of expresso beans.\n");
        printf("Heat and foam milk.\n");
    }
};

enum type_of_coffe {
    espresso = 1,
    cappuccino
};

class CoffeeMakerFactory {
private:
    Coffee * _coffee;

public:
    CoffeeMakerFactory() {}
    virtual ~CoffeeMakerFactory() {}
    Coffee * GetCoffee(char type_of_coffe){
        switch (type_of_coffe){
            case espresso: return new Espresso;
            case cappuccino: return new Cappuccino;
            default: printf("Invalid Selection\n"); return nullptr;
        }
    }
};

int main(){

    CoffeeMakerFactory coffeeMachine;
    Coffee *cup = coffeeMachine.GetCoffee(espresso);

    std::cout << "\nYou had asked for a(n) " << cup->getType() << "\n";

    printf("Done\n");
    return 0;
}
