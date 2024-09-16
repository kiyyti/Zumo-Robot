#include <EEPROM.h>
#define thR 150         //ค่าจุดตัดเจอ เส้นขาว ขวา
#define thL 150         //ค่าจุดตัดเจอ เส้นขาว ซ้าย
#define slowWalk 40//55     //ค่าความเร็วเดินช้า
#define attackWalk 55  //ค่าความเร็วชน
#define turnAttackSpeed 85   //ค่าความเร็วหันหาศัตรู
#define turnAttackTime 10    //ค่าเวลาการหัน
#define turnAttackSpeedboot 130   //ค่าความเร็วหันหาศัตรู
#define backSpeed 70  //ค่าความเร็วถอยหลังเจอเส้น
#define backTime 250   //ค่าเวลาถอยหลังเจอเส้น
#define turnSpeed 100  //ค่าความเร็วหันเจอเส้น
#define turnTime 190   //ค่าเวลาการหันเจอเส้น
#define thdc 300   //ค่าจุดตัดเจอ ศัตรู กลาง
#define thdri 300  //ค่าจุดตัดเจอ ศัตรู ขวา นอก
#define thdro 300  //ค่าจุดตัดเจอ ศัตรู ขวา ใน
#define thdli 300  //ค่าจุดตัดเจอ ศัตรู ซ้าย นอก
#define thdlo 300  //ค่าจุดตัดเจอ ศัตรู่ ซ้าย ใน
#define thdb 1300  //ค่าจุดตัดเจอ ศัตรู่ ซ้าย ใน
#define pulseHighTime 2//5
#define pulseLowTime 5
#define maxProgram 3
int fr, fl, dc, dri, dro, dli, dlo, db;
void setup() {
    Serial.begin(9600);
    delay(500);

    pinMode(13, OUTPUT);
    pinMode(12, INPUT);
    pinMode(11, INPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);

    int p = EEPROM.read( 0);
    if (p >   maxProgram) {
    EEPROM.write(0, 1); p = 1;
}


    delay(200);
    for (int i = 0; i < p; i++) {
        digitalWrite(13, 1);
        delay(200);
        digitalWrite(13, 0);
        delay(200);
    }



    while (1) {
    //  Serial.println(digitalRead(12));
    if (digitalRead(11) == 1)break;
    if (digitalRead(12) == 1) {
        p++;
        if (p > maxProgram) {
            p = 1;
    }
    EEPROM.write(0, p);
    while (digitalRead(12) == 1) {
        delay(100);
    }
    delay(500);
    for (int i = 0; i < p; i++) {
        digitalWrite(13, 1);
        delay(200);
        digitalWrite(13, 0);
        delay(200);
    }
}
    delay(10);
    }
    while (digitalRead(11) == 1) {}
        digitalWrite(13, 1);

        delay(4500);
        digitalWrite(13, 0);
        if (p == 1) {}
        if (p == 2) {
            f(150);
            delay(50);
            l(150);
            delay(80);//120
            s();
            delay(100);
            f(130);
            delay(50);
            fs(240, 70);
            delay(400);//400
            s();
            delay(100);
            r(150);
            delay(20);
            s();
            delay(100);

    }
        if (p == 3) {
            f(150);
            delay(50);
            r(150);
            delay(60);
            s();
            delay(100);
            f(130);
            delay(50);
            fs(70, 240);
            delay(400);//400
            s();
            delay(100);
            l(150);
            delay(20);
            s();
            delay(100);

    }
  //while(1){delay(1000);}
}

void loop() {
    if (1) {
        readSensor();
        if (fl > thL) {
            b(backSpeed); delay(backTime);
            r(turnSpeed); delay(turnTime);
    }   else if (fr > thR) {
            b(backSpeed); delay(backTime);
            l(turnSpeed); delay(turnTime);
    }   else if (dc > thdc) {
            f(attackWalk * 1);
    }   else {
    if (dlo > thdlo) {
        l(turnAttackSpeed); delay(turnAttackTime); s(); delay(1);
    } else if (dli > thdli) {
        l(turnAttackSpeed); delay(turnAttackTime / 3); s(); delay(1);
    } else if (dro > thdro) {
        r(turnAttackSpeed); delay(turnAttackTime); s(); delay(1);
    } else if (dri > thdri) {
        r(turnAttackSpeed); delay(turnAttackTime / 3); s(); delay(1);
    } else if (db > thdb) {
        r(turnAttackSpeedboot); delay(turnAttackTime * 1.5); s(); delay(1);
    } else {
        f(slowWalk * 1); delay(pulseHighTime);
        // s(); delay(pulseLowTime);
    } 
}
    } else
    shwData();
}

void readSensor() {
    dlo = analogRead(A0);
    dli = analogRead(A1);
    dro = analogRead(A4);
    dri = analogRead(A3);
    dc = analogRead(A2);
    db = analogRead(A5);
    fl = analogRead(A6);
    fr = analogRead(A7);
}
void shwData() {
    Serial.print(analogRead(A0));
    Serial.print("//");
    Serial.print(analogRead(A1));
    Serial.print("//");
    Serial.print(analogRead(A2));
    Serial.print("//");
    Serial.print(analogRead(A3));
    Serial.print("//");
    Serial.print(analogRead(A4));
    Serial.print("//");
    Serial.print(analogRead(A5));
    Serial.print("--");
    Serial.print(analogRead(A6));
    Serial.print("//");
    Serial.println(analogRead(A7));
    delay(300);
}
