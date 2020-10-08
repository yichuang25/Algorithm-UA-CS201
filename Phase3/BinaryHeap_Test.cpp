#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include "Heap.cpp"
#include "BHeap.cpp"

using namespace std;

void func(Heap<int, int> x)
{
    x.printKey(); // should print contents properly
    return;
}

void func(Heap<char, char> x)
{
    x.printKey(); // should print contents properly
    return;
}

void func(Heap<string, string> x)
{
    x.printKey(); // should print contents properly
    return;
}

int main()
{
    srand(time(0));

    cout << "TESTING HEAPS!" << endl;
    cout << "BEGINNING WITH INTEGERS" << endl;
    cout << "TESTING BUILDHEAP (bottom up!): " << endl;

    int buildHeapKeys[] = {31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int buildHeapValues[] = {31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    Heap<int, int> x(buildHeapKeys, buildHeapValues, 31);

    x = x;

    cout << "INSIDE FUNCTION" << endl;
    func(x); // should print first line of below printKey
    cout << "DONE WITH FUNCTION" << endl;
    
    for (int i = 0; i < 31; i++)
    {
        x.printKey();
        cout << x.peekKey() << endl;
        cout << x.peekValue() << endl;
        cout << x.extractMin() << endl << endl;
    }

    // peekKey, peekValue & extractMin should each print the same value, counting up from 1 to 31

    // printKey should look as follows for each iteration (with peekKey peekVal & extractMin in between)
    /*
    * 1 9 2 13 10 5 3 15 14 11 21 7 6 4 17 16 24 28 23 12 22 27 30 8 20 26 19 31 18 25 29
    * 2 9 3 13 10 5 4 15 14 11 21 7 6 18 17 16 24 28 23 12 22 27 30 8 20 26 19 31 29 25
    * 3 9 4 13 10 5 17 15 14 11 21 7 6 18 25 16 24 28 23 12 22 27 30 8 20 26 19 31 29
    * 4 9 5 13 10 6 17 15 14 11 21 7 19 18 25 16 24 28 23 12 22 27 30 8 20 26 29 31
    * 5 9 6 13 10 7 17 15 14 11 21 8 19 18 25 16 24 28 23 12 22 27 30 31 20 26 29
    * 6 9 7 13 10 8 17 15 14 11 21 20 19 18 25 16 24 28 23 12 22 27 30 31 29 26
    * 7 9 8 13 10 19 17 15 14 11 21 20 26 18 25 16 24 28 23 12 22 27 30 31 29
    * 8 9 17 13 10 19 18 15 14 11 21 20 26 29 25 16 24 28 23 12 22 27 30 31
    * 9 10 17 13 11 19 18 15 14 12 21 20 26 29 25 16 24 28 23 31 22 27 30
    * 10 11 17 13 12 19 18 15 14 22 21 20 26 29 25 16 24 28 23 31 30 27
    * 11 12 17 13 21 19 18 15 14 22 27 20 26 29 25 16 24 28 23 31 30
    * 12 13 17 14 21 19 18 15 23 22 27 20 26 29 25 16 24 28 30 31
    * 13 14 17 15 21 19 18 16 23 22 27 20 26 29 25 31 24 28 30
    * 14 15 17 16 21 19 18 24 23 22 27 20 26 29 25 31 30 28
    * 15 16 17 23 21 19 18 24 28 22 27 20 26 29 25 31 30
    * 16 21 17 23 22 19 18 24 28 30 27 20 26 29 25 31
    * 17 21 18 23 22 19 25 24 28 30 27 20 26 29 31
    * 18 21 19 23 22 20 25 24 28 30 27 31 26 29
    * 19 21 20 23 22 26 25 24 28 30 27 31 29
    * 20 21 25 23 22 26 29 24 28 30 27 31
    * 21 22 25 23 27 26 29 24 28 30 31
    * 22 23 25 24 27 26 29 31 28 30
    * 23 24 25 28 27 26 29 31 30
    * 24 27 25 28 30 26 29 31
    * 25 27 26 28 30 31 29
    * 26 27 29 28 30 31
    * 27 28 29 31 30
    * 28 30 29 31
    * 29 30 31
    * 30 31
    * 31
    */

    cout << endl << endl << endl << "BEGINNING RANDOM TESTS..." << endl << endl << endl;

    Heap<int, int> y;

    int arraySize = (rand() % 20) + 20; // generates a random array size between 20 and 40, adjust as necessary to debug
    int max = 0;
    int min = 2000;

    int keys[arraySize];
    int values[arraySize];

    cout << "ARRAY SIZE: " << arraySize << endl;

    for (int i = 0; i < arraySize; i++)
    {
        int randomKey = rand() % 100;
        int randomValue = randomKey;

        if (randomKey > max) { max = randomKey; }
        if (randomKey < min) { min = randomKey; }

        // cout << "INSERTING KEY: " << randomKey << endl;
        // cout << "INSERTING VALUE: " << randomValue << endl << endl;
        // uncomment these if u want to debug with the visualizer

        keys[i] = randomKey;
        values[i] = randomValue;

        y.insert(randomKey, randomValue);
    }

    Heap<int, int> z(keys, values, arraySize);

    cout << "MIN VALUE INSERTED: " << min << endl;
    cout << "MAX VALUE INSERTED: " << max << endl;

    for (int i = 0; i < arraySize; i++)
    {
        y.printKey();
        z.printKey();
        cout << y.peekKey() << endl;
        cout << y.peekValue() << endl;
        cout << y.extractMin() << endl;
        cout << z.peekKey() << endl;
        cout << z.peekValue() << endl;
        cout << z.extractMin() << endl << endl;
    }

    // first 2 lines are printKeys with each heap, min val at root
    // note the printKeys should not be identical each time. bottom up method builds a different heap than repeated inserts
    // next 6 lines should print the root 6 times in a row. Each iteration will build ascendingly from min value inserted to max value inserted

    cout << endl << endl << endl << "BEGINNING LARGE TESTS..." << endl << endl << endl;
    Heap <int, int> a;
    arraySize = 10000000;
    max = 0;
    min = 10000001;

    clock_t start = clock();
    for (int i = 0; i < 10000000; i++)
    {
        int randomKey = rand() % 100000;
        int randomValue = randomKey;

        if (randomKey > max) { max = randomKey; }
        if (randomKey < min) { min = randomKey; }

        a.insert(randomKey, randomValue);
    }
    cout << "COMPLETED 10,000,000 INSERTS IN: " << (( clock() - start ) / (double) CLOCKS_PER_SEC) << " SECONDS." << endl << endl << endl << endl;
    // mine finished at around 2 seconds flat on average. not sure if thats good? let me know what you guys are getting 


    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------


    cout << "NOW FOR CHARACTERS" << endl;
    cout << "TESTING BUILDHEAP (bottom up!): " << endl;

    char buildHeapCharKeys[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
    char buildHeapCharValues[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};

    Heap<char, char> chX(buildHeapCharKeys, buildHeapCharValues, 26);

    chX = chX;

    cout << "INSIDE FUNCTION" << endl;
    func(chX); // should print first line of below printKey
    cout << "DONE WITH FUNCTION" << endl;
    
    for (int i = 0; i < 26; i++)
    {
        chX.printKey();
        cout << chX.peekKey() << endl;
        cout << chX.peekValue() << endl;
        cout << chX.extractMin() << endl << endl;
    }

    // peekKey, peekValue & extractMin should each print the same character, moving up from a to z

    // printKey should look as follows for each iteration (with peekKey peekVal & extractMin in between)
    /*
    * a d b h e c l j i f p o n m t k s w r g q v y x z u
    * b d c h e n l j i f p o u m t k s w r g q v y x z
    * c d l h e n m j i f p o u z t k s w r g q v y x
    * d e l h f n m j i g p o u z t k s w r x q v y 
    * e f l h g n m j i q p o u z t k s w r x y v
    * f g l h p n m j i q v o u z t k s w r x y
    * g h l i p n m j r q v o u z t k s w y x
    * h i l j p n m k r q v o u z t x s w 
    * i j l k p n m s r q v o u z t x y w
    * j k l r p n m s w q v o u z t x y
    * k p l r q n m s w y v o u z t x
    * l p m r q n t s w y v o u z x
    * m p n r q o t s w y v x u z
    * n p o r q u t s w y v x z
    * o p t r q u z s w y v x
    * p q t r v u z s w y x
    * q r t s v u z x w y
    * r s t w v u z x y
    * s v t w y u z x
    * t v u w y x z
    * u v x w y z
    * v w x z y
    * w y x z
    * x y z
    * y z
    * z
    */

    cout << endl << endl << endl << "BEGINNING RANDOM TESTS..." << endl << endl << endl;

    Heap<char, char> charY;

    int charArraySize = (rand() % 20) + 20; // generates a random array size between 20 and 40, adjust as necessary to debug
    char maxLet = 'A';
    char minLet = 'Z';

    char chrKeys[charArraySize];
    char chrValues[charArraySize];

    cout << "ARRAY SIZE: " << charArraySize << endl;

    for (int i = 0; i < charArraySize; i++) // capital letters
    {
        char rndLtrKey = rand() % (90 - 65 + 1) + 65;
        char rndLtrVal = rndLtrKey;

        if (rndLtrKey > maxLet) { maxLet = rndLtrKey; }
        if (rndLtrKey < minLet) { minLet = rndLtrKey; }

        // cout << "INSERTING KEY: " << randomKey << endl;
        // cout << "INSERTING VALUE: " << randomValue << endl << endl;
        // uncomment these if u want to debug with the visualizer

        chrKeys[i] = rndLtrKey;
        chrValues[i] = rndLtrVal;

        charY.insert(rndLtrKey, rndLtrVal);
    }

    Heap<char, char> charZ(chrKeys, chrValues, charArraySize);

    cout << "MIN VALUE INSERTED: " << minLet << endl;
    cout << "MAX VALUE INSERTED: " << maxLet << endl;

    for (int i = 0; i < charArraySize; i++)
    {
        charY.printKey();
        charZ.printKey();
        cout << charY.peekKey() << endl;
        cout << charY.peekValue() << endl;
        cout << charY.extractMin() << endl;
        cout << charZ.peekKey() << endl;
        cout << charZ.peekValue() << endl;
        cout << charZ.extractMin() << endl << endl;
    }

    // first 2 lines are printKeys with each heap, min val at root
    // note the printKeys should not be identical each time. bottom up method builds a different heap than repeated inserts
    // next 6 lines should print the root 6 times in a row. Each iteration will build ascendingly from min value inserted to max value inserted

    cout << endl << endl << endl << "BEGINNING LARGE TESTS..." << endl << endl << endl;
    Heap <char, char> charA;
    charArraySize = 10000000;
    maxLet = 'A';
    minLet = 'Z';

    clock_t newStart = clock();
    for (int i = 0; i < 10000000; i++)
    {
        char rndLtrKey = rand() % (90 - 65 + 1) + 65;
        char rndLtrVal = rndLtrKey;

        if (rndLtrKey > maxLet) { maxLet = rndLtrKey; }
        if (rndLtrKey < minLet) { minLet = rndLtrKey; }

        charA.insert(rndLtrKey, rndLtrVal);
    }
    cout << "COMPLETED 10,000,000 INSERTS IN: " << (( clock() - newStart ) / (double) CLOCKS_PER_SEC) << " SECONDS." << endl << endl << endl << endl;
    // mine finished at around 1.9 seconds on average. not sure if thats good? let me know what you guys are getting 

    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------


    cout << "NOW FOR STRINGS" << endl;
    cout << "TESTING BUILDHEAP (bottom up!): " << endl;

    string buildHeapStringKeys[] = {"Zoo", "Yard", "Xylophone", "Wumbo", "Vase", "Umbrella", "Tangle", "Slide", "Rust", "Quiz", "Platypus", "October", "Nap", "Mouse", "Lounge", "Kangaroo", "Jelly", "Inspect", "Hippo", "Giraffe", "Frog", "Earth", "Dog", "Computer", "Bandana", "Apple"};
    string buildHeapStringValues[] = {"Zoo", "Yard", "Xylophone", "Wumbo", "Vase", "Umbrella", "Tangle", "Slide", "Rust", "Quiz", "Platypus", "October", "Nap", "Mouse", "Lounge", "Kangaroo", "Jelly", "Inspect", "Hippo", "Giraffe", "Frog", "Earth", "Dog", "Computer", "Bandana", "Apple"};

    Heap<string, string> strX(buildHeapStringKeys, buildHeapStringValues, 26);

    strX = strX;

    cout << "INSIDE FUNCTION" << endl;
    func(strX); // should print first line of below printKey
    cout << "DONE WITH FUNCTION" << endl;
    
    for (int i = 0; i < 26; i++)
    {
        strX.printKey();
        cout << strX.peekKey() << endl;
        cout << strX.peekValue() << endl;
        cout << strX.extractMin() << endl << endl;
    }

    // peekKey, peekValue & extractMin should each print the same string, moving up from strings that start with A to those that start with Z

    // printKey should look as follows for each iteration (with peekKey peekVal & extractMin in between)
    /*
    * Apple Dog Bandana Hippo Earth Computer Lounge Jelly Inspect Frog Platypus October Nap Mouse Tangle Kangaroo Slide Wumbo Rust Giraffe Quiz Vase Yard Xylophone Zoo Umbrella
    * Bandana Dog Computer Hippo Earth Nap Lounge Jelly Inspect Frog Platypus October Umbrella Mouse Tangle Kangaroo Slide Wumbo Rust Giraffe Quiz Vase Yard Xylophone Zoo
    * Computer Dog Lounge Hippo Earth Nap Mouse Jelly Inspect Frog Platypus October Umbrella Zoo Tangle Kangaroo Slide Wumbo Rust Giraffe Quiz Vase Yard Xylophone
    * Dog Earth Lounge Hippo Frog Nap Mouse Jelly Inspect Giraffe Platypus October Umbrella Zoo Tangle Kangaroo Slide Wumbo Rust Xylophone Quiz Vase Yard
    * Earth Frog Lounge Hippo Giraffe Nap Mouse Jelly Inspect Quiz Platypus October Umbrella Zoo Tangle Kangaroo Slide Wumbo Rust Xylophone Yard Vase 
    * Frog Giraffe Lounge Hippo Platypus Nap Mouse Jelly Inspect Quiz Vase October Umbrella Zoo Tangle Kangaroo Slide Wumbo Rust Xylophone Yard 
    * Giraffe Hippo Lounge Inspect Platypus Nap Mouse Jelly Rust Quiz Vase October Umbrella Zoo Tangle Kangaroo Slide Wumbo Yard Xylophone 
    * Hippo Inspect Lounge Jelly Platypus Nap Mouse Kangaroo Rust Quiz Vase October Umbrella Zoo Tangle Xylophone Slide Wumbo Yard 
    * Inspect Jelly Lounge Kangaroo Platypus Nap Mouse Slide Rust Quiz Vase October Umbrella Zoo Tangle Xylophone Yard Wumbo 
    * Jelly Kangaroo Lounge Rust Platypus Nap Mouse Slide Wumbo Quiz Vase October Umbrella Zoo Tangle Xylophone Yard 
    * Kangaroo Platypus Lounge Rust Quiz Nap Mouse Slide Wumbo Yard Vase October Umbrella Zoo Tangle Xylophone 
    * Lounge Platypus Mouse Rust Quiz Nap Tangle Slide Wumbo Yard Vase October Umbrella Zoo Xylophone 
    * Mouse Platypus Nap Rust Quiz October Tangle Slide Wumbo Yard Vase Xylophone Umbrella Zoo 
    * Nap Platypus October Rust Quiz Umbrella Tangle Slide Wumbo Yard Vase Xylophone Zoo 
    * October Platypus Tangle Rust Quiz Umbrella Zoo Slide Wumbo Yard Vase Xylophone 
    * Platypus Quiz Tangle Rust Vase Umbrella Zoo Slide Wumbo Yard Xylophone 
    * Quiz Rust Tangle Slide Vase Umbrella Zoo Xylophone Wumbo Yard 
    * Rust Slide Tangle Wumbo Vase Umbrella Zoo Xylophone Yard 
    * Slide Vase Tangle Wumbo Yard Umbrella Zoo Xylophone 
    * Tangle Vase Umbrella Wumbo Yard Xylophone Zoo 
    * Umbrella Vase Xylophone Wumbo Yard Zoo 
    * Vase Wumbo Xylophone Zoo Yard 
    * Wumbo Yard Xylophone Zoo 
    * Xylophone Yard Zoo 
    * Yard Zoo 
    * Zoo
    */

    cout << endl << endl << endl << "BEGINNING RANDOM TESTS..." << endl << endl << endl;

    Heap<string, string> strY;

    int strArraySize = (rand() % 20) + 20; // generates a random array size between 20 and 40, adjust as necessary to debug
    string maxStr = "A";
    string minStr = "Z";

    string strKeys[strArraySize];
    string strValues[strArraySize];

    cout << "ARRAY SIZE: " << strArraySize << endl;

    for (int i = 0; i < strArraySize; i++) // random gibberish words composed of capital letters
    {
        int randomRange = rand() % ((10) - (4) + 1) + (4);

        string rndStrKey;

        for (int z = 0; z < randomRange; z++)
        {
            char val = rand() % (90 - 65 + 1) + 65;
            rndStrKey += val;
        }

        string rndStrVal = rndStrKey;

        if (rndStrKey > maxStr) { maxStr = rndStrKey; }
        if (rndStrKey < minStr) { minStr = rndStrKey; }

        // cout << "INSERTING KEY: " << randomKey << endl;
        // cout << "INSERTING VALUE: " << randomValue << endl << endl;
        // uncomment these if u want to debug with the visualizer

        strKeys[i] = rndStrKey;
        strValues[i] = rndStrVal;

        strY.insert(rndStrKey, rndStrVal);
    }

    Heap<string, string> strZ(strKeys, strValues, strArraySize);

    cout << "MIN VALUE INSERTED: " << minStr << endl;
    cout << "MAX VALUE INSERTED: " << maxStr << endl;

    for (int i = 0; i < strArraySize; i++)
    {
        strY.printKey();
        strZ.printKey();
        cout << strY.peekKey() << endl;
        cout << strY.peekValue() << endl;
        cout << strY.extractMin() << endl;
        cout << strZ.peekKey() << endl;
        cout << strZ.peekValue() << endl;
        cout << strZ.extractMin() << endl << endl;
    }

    // first 2 lines are printKeys with each heap, min val at root
    // note the printKeys should not be identical each time. bottom up method builds a different heap than repeated inserts
    // next 6 lines should print the root 6 times in a row. Each iteration will build ascendingly from min value inserted to max value inserted

    cout << endl << endl << endl << "BEGINNING LARGE TESTS..." << endl << endl << endl;
    Heap <string, string> strA;
    strArraySize = 10000000;
    maxStr = "A";
    minStr = "Z";

    clock_t newerStart = clock();
    for (int i = 0; i < 10000000; i++)
    {
        int randomRange = rand() % ((10) - (4) + 1) + (4);

        string rndStrKey;

        for (int z = 0; z < randomRange; z++)
        {
            char val = rand() % (90 - 65 + 1) + 65;
            rndStrKey += val;
        }

        string rndStrVal = rndStrKey;

        if (rndStrKey > maxStr) { maxStr = rndStrKey; }
        if (rndStrKey < minStr) { minStr = rndStrKey; }

        strA.insert(rndStrKey, rndStrVal);
    }
    cout << "COMPLETED 10,000,000 INSERTS IN: " << (( clock() - newerStart ) / (double) CLOCKS_PER_SEC) << " SECONDS." << endl;
    // mine finished at around 10.1 seconds on average. not sure if thats good? let me know what you guys are getting 

    return 0;
}