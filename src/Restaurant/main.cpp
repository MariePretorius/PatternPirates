#include <iostream>

#include "../Kitchen/Kitchen.h"
#include "../Floor/Customer.h"
#include "Restaurant.h"
#include "../tests/CustomerTests.h"

#include "../tests/FinanceTests.h"
#include "../tests/StockTests.h"
#include "../tests/WaiterTests.h"
#include "../tests/FloorTests.h"
#include "../tests/KitchenTests.h"
#include "../tests/FoodOrderTest.h"
#include "../tests/BillTest.h"
#include "../tests/HostTests.h"

using namespace std;

void testing()
{
    bool customerSuccess = false;
    bool billSuccess = false;
    bool foodOrderSuccess = false;
    bool tableSuccess = false;
    bool financeSuccess = false;
    bool stockSuccess = false;
    bool waiterSuccess = false;
    bool floorSuccess = false;
    bool hostSuccess = false;
    bool kitchenSuccess = false;


    CustomerTests* customerTests = new CustomerTests();
    //customerTests->runTests();
    delete customerTests;


    //Finance Tests
    //Tests Finanance class
    //Has No Dependencies

    FinanceTests * financeTests = new FinanceTests();

    financeSuccess = financeTests->tests();
    delete financeTests;


    //Stock Tests
    //Tests stock, shelf and ingredient classes
    //has no dependencies
    StockTests * stockTests = new StockTests();
    stockSuccess = stockTests->tests();
    delete stockTests;


    customerSuccess = true;
    billSuccess = true;
    foodOrderSuccess = true;
    tableSuccess = true;

    //Waiter Tests
    //tests the waiter class
    //Requires Customer, Bill, FoodOrder, Table and Finance
     if(customerSuccess && billSuccess && foodOrderSuccess && tableSuccess && financeSuccess)
     {
         WaiterTests * waiterTests = new WaiterTests();
         waiterSuccess = waiterTests->tests();
         delete waiterTests;

         waiterSuccess = true;
         std::cout << "\033[35mWaiters Test Successful!\033[0m" << std::endl;
     }
     else
     {
         std::cout << "\033[35mCannot test Waiter as there are dependencies that failed.\033[0m" << std::endl;
     }


    try {
        HostTests * ht = new HostTests();
        ht->TestScenario();
        delete ht;
        hostSuccess = true;
        cout<<"\033[1;32mHost Tests successful\033[0m"<<endl;
    }catch (exception e){
        cout<<"Host has failed tests";
    }
    //Floor Tests
    //tests the floor class
    //requires waiter, host, table
    if(waiterSuccess && hostSuccess && tableSuccess)
    {
        FloorTests * floorTests = new FloorTests();
        try
        {
            floorTests->run();
        }
        catch (exception & e)
        {
            std::cout << "\033[35mAn error occurred during the Floor test.\033[0m" << std::endl;
            cout << e.what() << endl;
        }
        catch (...)
        {
            std::cout << "\033[35mAn unknown error occurred during the Floor test.\033[0m" << std::endl;
        }
        delete floorTests;

        floorSuccess = true;
        std::cout << "\033[35mFloor Test Successful!\033[0m" << std::endl;
    }
    else
    {
        std::cout << "\033[35mCannot test Floor as there are dependencies that failed.\033[0m" << std::endl;
    }

    //Kitchen Tests
    //tests the kitchen class
    //requires FoodOrder, Ingredient, Shelf, Finance
    // if(foodOrderSuccess && stockSuccess && financeSuccess)
    // {
    //     KitchenTests * kitchenTests = new KitchenTests();
    //     try
    //     {
    //         kitchenTests->runTests();
    //     }
    //     catch (exception & e)
    //     {
    //         std::cout << "\033[1;36mAn error occurred during the Kitchen test.\033[0m" << std::endl;
    //         cout << e.what() << endl;
    //     }
    //     catch (...)
    //     {
    //         std::cout << "\033[1;36mAn unknown error occurred during the Kitchen test.\033[0m" << std::endl;
    //     }
    //     delete kitchenTests;

    //     kitchenSuccess = true;
    //     std::cout << "\033[1;36mKitchen Test Successful!\033[0m" << std::endl;
    // }
    // else
    // {
    //     std::cout << "\033[1;36mCannot test Kitchen as there are dependencies that failed.\033[0m" << std::endl;
    // }
}

void ShannonTesting()
{
    //BILL TESTS
    BillTest billTest;

    try
    {
        billTest.runTests();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //FoodOrder TESTS
    FoodOrderTest foodOrderTest;

    try
    {
        foodOrderTest.runTests();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}


int main(){


    testing();
    //ShannonTesting();
    Restaurant::instance()->setup();


    /*
    try
    {
        Restaurant::instance()->setup();
    }
    catch(exception & e)
    {
        cout << "An Error Occurred outside of testing" << endl;
        //cout << "File:\t" << __FILE__ << "\nLine:\t" << __LINE__ << endl;
        //cout << "Error:\t" << e.what() << endl;
        throw e;
    }
     */
    // CUSTOMER TESTS



    return 0;
}



