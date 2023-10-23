cmake_minimum_required(VERSION 3.16)
project(Proj)

set(CMAKE_CXX_STANDARD 14)

include_directories(root/StockAndFinance)

add_executable(Proj
        root/StockAndFinance/Finance.cpp
        root/StockAndFinance/Finance.h
        root/StockAndFinance/Shelf.h
        root/StockAndFinance/Shelf.h
        root/StockAndFinance/Shelf.cpp
        root/StockAndFinance/StockAndFinanceFacade.h
        root/StockAndFinance/StockAndFinanceFacade.cpp
        root/StockAndFinance/Stock.h
        root/StockAndFinance/Stock.cpp
        root/main.cpp)
