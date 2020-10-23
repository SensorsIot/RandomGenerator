#define firstLetter 33
#define lastLetter 90
int ss[100];
const byte charProp[] = { 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50};
//const byte charProp[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 50, 50, 50, 50, 50, 50, 50, 50};
//const byte charProp[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};




void setup() {
    Serial.begin(9600);

}

void loop() {

    Serial.println("Begin");
    for (int i=0;i<100;i++) ss[i]=0;

    for (double i = 0; i < 1000; i++) {
        int hi = generateLetter();
        ss[hi] ++;
    }
    for (int i = 33; i <= 90; i++) {
        char buchstabe = i;
        Serial.print(buchstabe);
        Serial.print(",");
        Serial.println( ss[i]);
    }
    delay(5000);
}



char generateLetter()	//Random generate letter according its propability (higher propability means letter is generated more often)
{
    int _pointer;
    int _totProbabilities = 0;
    int _sum = 0;
    int _index = 0;

    for  (int _i = 0; _i <= lastLetter - firstLetter; _i++) _totProbabilities = _totProbabilities + charProp[_i]; // _tot = sum of all probabilities

    _pointer = random(0, _totProbabilities);

    while (_sum <= _pointer)    {
        _sum = _sum + charProp[_index];
        _index++;
    }
    return char(firstLetter + _index - 1);
}
