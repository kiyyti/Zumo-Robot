#define sigra 5  //6
#define sigrb 6 //5
#define sigla 10  //9
#define siglb 9 //10
#define slowfinetune 1.1 // จูนเดินตรงช้า
#define fastfinetune 0.8 //  จูนเดินตรงเร็ว
#define backfinetune 1 // จูดถอยหลัง
void fs(int d,int j) {
    analogWrite(sigra, j ); analogWrite(sigla, d);
    analogWrite(siglb, 0); analogWrite(sigrb, 0);
}
void f(int d) {
    analogWrite(sigra, d * slowfinetune); analogWrite(sigla, d);
    analogWrite(siglb, 0); analogWrite(sigrb, 0);
}
void fx(int d) {
    analogWrite(sigra, d * fastfinetune); analogWrite(sigla, d);
    analogWrite(siglb, 0); analogWrite(sigrb, 0);
}
void l(int d) {
    analogWrite(sigla, 0); analogWrite(sigrb, 0);
    analogWrite(siglb, d); analogWrite(sigra, d* slowfinetune);
}
void r(int d) {
    analogWrite(siglb, 0); analogWrite(sigra, 0);
    analogWrite(sigla, d); analogWrite(sigrb, d* slowfinetune);
}
void b(int d) {
    analogWrite(sigla, 0);
    analogWrite(sigra, 0);
    analogWrite(siglb, d);
    analogWrite(sigrb, d * backfinetune);//85
}
void s() {
    analogWrite(sigla, 0); analogWrite(sigrb, 0);
    analogWrite(sigra, 0); analogWrite(siglb, 0);
}
void ss() {
    analogWrite(sigla, 200); analogWrite(sigrb, 200);
    analogWrite(sigra, 200); analogWrite(siglb, 200);
}
