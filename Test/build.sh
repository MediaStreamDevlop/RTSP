    g++ jsonTest.cpp -I../Include -L../Lib -ljsoncpp -o ../App/jsonTest
    g++ xmlTest.cpp -I../Include -L../Lib -lpugixml -o ../App/xmlTest
    g++ LogTest.cpp -I../Include -L../Lib -lLog -lfileUtils -o ../App/LogTest
