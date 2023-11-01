#ifndef INGREDIENT_H
#define INGREDIENT_H
using namespace std;

class Ingredient {
    private:
        std::string name; //name of ingredient
        std::string condition; //Fried or Grilled
        std::string cookingChoice; //Fried or Grilled
    public:
        std::string getName();
        std::string getCondition();
        std::string getChoice();
        void setCondition(std::string condition);
};

#endif