#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include "Heap.cpp"
#include "BHeap.cpp"

using namespace std;

void func(BHeap<int, int> x)
{
    x.printKey(); // should print contents properly
    return;
}

void func(BHeap<char, char> x)
{
    x.printKey(); // should print contents properly
    return;
}

void func(BHeap<string, string> x)
{
    x.printKey(); // should print contents properly
    return;
}

int main()
{
    srand(time(0));

    cout << "TESTING BHEAPS!" << endl;
    cout << "BEGINNING WITH INTEGERS" << endl;
    cout << "TESTING PARAMETERIZED CONSTRUCTOR (repeated insertion!): " << endl;

    int buildHeapKeys[] = {31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int buildHeapValues[] = {31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    BHeap<int, int> x(buildHeapKeys, buildHeapValues, 31);

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
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    1 

    B1
    2 3 

    B2
    4 6 7 5 

    B3
    8 12 14 15 13 10 11 9 

    B4
    16 24 28 30 31 29 26 27 25 20 22 23 21 18 19 17 
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    2 3 

    B2
    4 6 7 5 

    B3
    8 12 14 15 13 10 11 9 

    B4
    16 24 28 30 31 29 26 27 25 20 22 23 21 18 19 17 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    3 

    B2
    4 6 7 5 

    B3
    8 12 14 15 13 10 11 9 

    B4
    16 24 28 30 31 29 26 27 25 20 22 23 21 18 19 17 
    / -------------------------------------------------------------------------------------------------------------------------------
    B2
    4 6 7 5 

    B3
    8 12 14 15 13 10 11 9 

    B4
    16 24 28 30 31 29 26 27 25 20 22 23 21 18 19 17 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    5 

    B1
    6 7 

    B3
    8 12 14 15 13 10 11 9 

    B4
    16 24 28 30 31 29 26 27 25 20 22 23 21 18 19 17 
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    6 7 

    B3
    8 12 14 15 13 10 11 9 

    B4
    16 24 28 30 31 29 26 27 25 20 22 23 21 18 19 17 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    7 

    B3
    8 12 14 15 13 10 11 9 

    B4
    16 24 28 30 31 29 26 27 25 20 22 23 21 18 19 17
    / -------------------------------------------------------------------------------------------------------------------------------
    B3
    8 12 14 15 13 10 11 9 

    B4
    16 24 28 30 31 29 26 27 25 20 22 23 21 18 19 17 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    9 

    B1
    10 11 

    B2
    12 14 15 13 

    B4
    16 24 28 30 31 29 26 27 25 20 22 23 21 18 19 17
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    10 11 

    B2
    12 14 15 13 

    B4
    16 24 28 30 31 29 26 27 25 20 22 23 21 18 19 17
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    11 

    B2
    12 14 15 13 

    B4
    16 24 28 30 31 29 26 27 25 20 22 23 21 18 19 17 
    / -------------------------------------------------------------------------------------------------------------------------------
    B2
    12 14 15 13 

    B4
    16 24 28 30 31 29 26 27 25 20 22 23 21 18 19 17 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    13 

    B1
    14 15 

    B4
    16 24 28 30 31 29 26 27 25 20 22 23 21 18 19 17 
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    14 15 

    B4
    16 24 28 30 31 29 26 27 25 20 22 23 21 18 19 17 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    15 

    B4
    16 24 28 30 31 29 26 27 25 20 22 23 21 18 19 17 
    / -------------------------------------------------------------------------------------------------------------------------------
    B4
    16 24 28 30 31 29 26 27 25 20 22 23 21 18 19 17
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    17 

    B1
    18 19 

    B2
    20 22 23 21 

    B3
    24 28 30 31 29 26 27 25 
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    18 19 

    B2
    20 22 23 21 

    B3
    24 28 30 31 29 26 27 25 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    19 

    B2
    20 22 23 21 

    B3
    24 28 30 31 29 26 27 25 
    / -------------------------------------------------------------------------------------------------------------------------------
    B2
    20 22 23 21 

    B3
    24 28 30 31 29 26 27 25 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    21 

    B1
    22 23 

    B3
    24 28 30 31 29 26 27 25 
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    22 23 

    B3
    24 28 30 31 29 26 27 25 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    23 

    B3
    24 28 30 31 29 26 27 25 
    / -------------------------------------------------------------------------------------------------------------------------------
    B3
    24 28 30 31 29 26 27 25 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    25 

    B1
    26 27 

    B2
    28 30 31 29 
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    26 27 

    B2
    28 30 31 29 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    27 

    B2
    28 30 31 29 
    / -------------------------------------------------------------------------------------------------------------------------------
    B2
    28 30 31 29 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    29 

    B1
    30 31 
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    30 31 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    31 
    / -------------------------------------------------------------------------------------------------------------------------------
    */

    cout << endl << endl << endl << "BEGINNING RANDOM TESTS..." << endl << endl << endl;

    BHeap<int, int> y;

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

    BHeap<int, int> z(keys, values, arraySize);

    cout << "MIN VALUE INSERTED: " << min << endl;
    cout << "MAX VALUE INSERTED: " << max << endl;

    y.merge(z);

    for (int i = 0; i < arraySize * 2; i++)
    {
        // y.printKey(); uncomment if you want, if your print key worked above it should be ok here
        cout << y.peekKey() << endl;
        cout << y.peekValue() << endl;
        cout << y.extractMin() << endl;

        if (i % 2 == 1) { cout << endl; }
    }

    // 6 lines should print the root 6 times in a row. Each iteration will build ascendingly from min value inserted to max value inserted

    cout << endl << endl << endl << "BEGINNING LARGE TESTS..." << endl << endl << endl;
    BHeap <int, int> a;
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
    // mine finished at around 2.5 - 2.6 seconds on average. not sure if thats good? let me know what you guys are getting 


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
    cout << "TESTING PARAMETERIZED CONSTRUCTOR (repeated insertion!): " << endl;

    char buildHeapCharKeys[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
    char buildHeapCharValues[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};

    BHeap<char, char> chX(buildHeapCharKeys, buildHeapCharValues, 26);

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
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    a b 

    B3
    c g i j h e f d 

    B4
    k s w y z x u v t o q r p m n l 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    b 

    B3
    c g i j h e f d 

    B4
    k s w y z x u v t o q r p m n l 
    / -------------------------------------------------------------------------------------------------------------------------------
    B3
    c g i j h e f d 

    B4
    k s w y z x u v t o q r p m n l 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    d 

    B1
    e f 

    B2
    g i j h 

    B4
    k s w y z x u v t o q r p m n l 
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    e f 

    B2
    g i j h 

    B4
    k s w y z x u v t o q r p m n l 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    f 

    B2
    g i j h 

    B4
    k s w y z x u v t o q r p m n l 
    / -------------------------------------------------------------------------------------------------------------------------------
    B2
    g i j h 

    B4
    k s w y z x u v t o q r p m n l 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    h 

    B1
    i j 

    B4
    k s w y z x u v t o q r p m n l 
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    i j 

    B4
    k s w y z x u v t o q r p m n l 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    j 

    B4
    k s w y z x u v t o q r p m n l 
    / -------------------------------------------------------------------------------------------------------------------------------
    B4
    k s w y z x u v t o q r p m n l 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    l 

    B1
    m n 

    B2
    o q r p 

    B3
    s w y z x u v t 
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    m n 

    B2
    o q r p 

    B3
    s w y z x u v t 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    n 

    B2
    o q r p 

    B3
    s w y z x u v t 
    / -------------------------------------------------------------------------------------------------------------------------------
    B2
    o q r p 

    B3
    s w y z x u v t 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    p 

    B1
    q r 

    B3
    s w y z x u v t 
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    q r 

    B3
    s w y z x u v t
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    r 

    B3
    s w y z x u v t 
    / -------------------------------------------------------------------------------------------------------------------------------
    B3
    s w y z x u v t 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    t 

    B1
    u v 

    B2
    w y z x 
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    u v 

    B2
    w y z x 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    v 

    B2
    w y z x 
    / -------------------------------------------------------------------------------------------------------------------------------
    B2
    w y z x 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    x 

    B1
    y z 
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    y z 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    z 
    / -------------------------------------------------------------------------------------------------------------------------------
    */

    cout << endl << endl << endl << "BEGINNING RANDOM TESTS..." << endl << endl << endl;

    BHeap<char, char> charY;

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

    BHeap<char, char> charZ(chrKeys, chrValues, charArraySize);

    cout << "MIN VALUE INSERTED: " << minLet << endl;
    cout << "MAX VALUE INSERTED: " << maxLet << endl;

    charZ.merge(charY);

    for (int i = 0; i < charArraySize * 2; i++)
    {
        // charZ.printKey(); uncomment if you want, if your print key worked above it should be ok here
        cout << charZ.peekKey() << endl;
        cout << charZ.peekValue() << endl;
        cout << charZ.extractMin() << endl;

        if (i % 2 == 1) { cout << endl; }
    }

    // 6 lines should print the root 6 times in a row. Each iteration will build ascendingly from min value inserted to max value inserted

    cout << endl << endl << endl << "BEGINNING LARGE TESTS..." << endl << endl << endl;
    BHeap <char, char> charA;
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
    // mine finished at around 2.6 seconds on average. not sure if thats good? let me know what you guys are getting 

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
    cout << "TESTING PARAMETERIZED CONSTRUCTOR (repeated insertion!): " << endl;

    string buildHeapStringKeys[] = {"Zoo", "Yard", "Xylophone", "Wumbo", "Vase", "Umbrella", "Tangle", "Slide", "Rust", "Quiz", "Platypus", "October", "Nap", "Mouse", "Lounge", "Kangaroo", "Jelly", "Inspect", "Hippo", "Giraffe", "Frog", "Earth", "Dog", "Computer", "Bandana", "Apple"};
    string buildHeapStringValues[] = {"Zoo", "Yard", "Xylophone", "Wumbo", "Vase", "Umbrella", "Tangle", "Slide", "Rust", "Quiz", "Platypus", "October", "Nap", "Mouse", "Lounge", "Kangaroo", "Jelly", "Inspect", "Hippo", "Giraffe", "Frog", "Earth", "Dog", "Computer", "Bandana", "Apple"};

    BHeap<string, string> strX(buildHeapStringKeys, buildHeapStringValues, 26);

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
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    Apple Bandana 

    B3
    Computer Giraffe Inspect Jelly Hippo Earth Frog Dog 

    B4
    Kangaroo Slide Wumbo Yard Zoo Xylophone Umbrella Vase Tangle October Quiz Rust Platypus Mouse Nap Lounge 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    Bandana 

    B3
    Computer Giraffe Inspect Jelly Hippo Earth Frog Dog 

    B4
    Kangaroo Slide Wumbo Yard Zoo Xylophone Umbrella Vase Tangle October Quiz Rust Platypus Mouse Nap Lounge 
    / -------------------------------------------------------------------------------------------------------------------------------
    B3
    Computer Giraffe Inspect Jelly Hippo Earth Frog Dog 

    B4
    Kangaroo Slide Wumbo Yard Zoo Xylophone Umbrella Vase Tangle October Quiz Rust Platypus Mouse Nap Lounge 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    Dog 

    B1
    Earth Frog 

    B2
    Giraffe Inspect Jelly Hippo 

    B4
    Kangaroo Slide Wumbo Yard Zoo Xylophone Umbrella Vase Tangle October Quiz Rust Platypus Mouse Nap Lounge 
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    Earth Frog 

    B2
    Giraffe Inspect Jelly Hippo 

    B4
    Kangaroo Slide Wumbo Yard Zoo Xylophone Umbrella Vase Tangle October Quiz Rust Platypus Mouse Nap Lounge 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    Frog 

    B2
    Giraffe Inspect Jelly Hippo 

    B4
    Kangaroo Slide Wumbo Yard Zoo Xylophone Umbrella Vase Tangle October Quiz Rust Platypus Mouse Nap Lounge
    / -------------------------------------------------------------------------------------------------------------------------------
    B2
    Giraffe Inspect Jelly Hippo 

    B4
    Kangaroo Slide Wumbo Yard Zoo Xylophone Umbrella Vase Tangle October Quiz Rust Platypus Mouse Nap Lounge 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    Hippo 

    B1
    Inspect Jelly 

    B4
    Kangaroo Slide Wumbo Yard Zoo Xylophone Umbrella Vase Tangle October Quiz Rust Platypus Mouse Nap Lounge
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    Inspect Jelly 

    B4
    Kangaroo Slide Wumbo Yard Zoo Xylophone Umbrella Vase Tangle October Quiz Rust Platypus Mouse Nap Lounge
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    Jelly 

    B4
    Kangaroo Slide Wumbo Yard Zoo Xylophone Umbrella Vase Tangle October Quiz Rust Platypus Mouse Nap Lounge
    / -------------------------------------------------------------------------------------------------------------------------------
    B4
    Kangaroo Slide Wumbo Yard Zoo Xylophone Umbrella Vase Tangle October Quiz Rust Platypus Mouse Nap Lounge
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    Lounge 

    B1
    Mouse Nap 

    B2
    October Quiz Rust Platypus 

    B3
    Slide Wumbo Yard Zoo Xylophone Umbrella Vase Tangle 
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    Mouse Nap 

    B2
    October Quiz Rust Platypus 

    B3
    Slide Wumbo Yard Zoo Xylophone Umbrella Vase Tangle
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    Nap 

    B2
    October Quiz Rust Platypus 

    B3
    Slide Wumbo Yard Zoo Xylophone Umbrella Vase Tangle 
    / -------------------------------------------------------------------------------------------------------------------------------
    B2
    October Quiz Rust Platypus 

    B3
    Slide Wumbo Yard Zoo Xylophone Umbrella Vase Tangle 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    Platypus 

    B1
    Quiz Rust 

    B3
    Slide Wumbo Yard Zoo Xylophone Umbrella Vase Tangle 
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    Quiz Rust 

    B3
    Slide Wumbo Yard Zoo Xylophone Umbrella Vase Tangle 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    Rust 

    B3
    Slide Wumbo Yard Zoo Xylophone Umbrella Vase Tangle 
    / -------------------------------------------------------------------------------------------------------------------------------
    B3
    Slide Wumbo Yard Zoo Xylophone Umbrella Vase Tangle
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    Tangle 

    B1
    Umbrella Vase 

    B2
    Wumbo Yard Zoo Xylophone 
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    Umbrella Vase 

    B2
    Wumbo Yard Zoo Xylophone 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    Vase 

    B2
    Wumbo Yard Zoo Xylophone 
    / -------------------------------------------------------------------------------------------------------------------------------
    B2
    Wumbo Yard Zoo Xylophone 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    Xylophone 

    B1
    Yard Zoo
    / -------------------------------------------------------------------------------------------------------------------------------
    B1
    Yard Zoo 
    / -------------------------------------------------------------------------------------------------------------------------------
    B0
    Zoo
    / -------------------------------------------------------------------------------------------------------------------------------
 
    */

    cout << endl << endl << endl << "BEGINNING RANDOM TESTS..." << endl << endl << endl;

    BHeap<string, string> strY;

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

    BHeap<string, string> strZ(strKeys, strValues, strArraySize);

    cout << "MIN VALUE INSERTED: " << minStr << endl;
    cout << "MAX VALUE INSERTED: " << maxStr << endl;

    strY.merge(strZ);

    for (int i = 0; i < strArraySize * 2; i++)
    {
        // strY.printKey(); uncomment if u want, if your printkey worked above it should work here
        cout << strY.peekKey() << endl;
        cout << strY.peekValue() << endl;
        cout << strY.extractMin() << endl;

        if (i % 2 == 1) { cout << endl; }
    }

    // first 2 lines are printKeys with each heap, min val at root
    // note the printKeys should not be identical each time. bottom up method builds a different heap than repeated inserts
    // next 6 lines should print the root 6 times in a row. Each iteration will build ascendingly from min value inserted to max value inserted

    cout << endl << endl << endl << "BEGINNING LARGE TESTS..." << endl << endl << endl;
    BHeap <string, string> strA;
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
    // mine finished at around 6.7 - 6.9 seconds on average. not sure if thats good? let me know what you guys are getting 

    return 0;
}