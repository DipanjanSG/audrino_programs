#define DD_H_REGISTER  (*(volatile unsigned char*)0x101)
#define OCR4C (*(volatile unsigned char*)0xAD)
#define TCCR4A (*(volatile unsigned char*)0xA0)
#define TCCR4B (*(volatile unsigned char*)0xA1)

void setup() {

  DD_H_REGISTER |= (1<<5);

  TCCR4A |= (1 << 3) | ( 1<< 0);
  TCCR4B |= (1 << 3) | ( 1<< 1);

  OCR4C = 20;
}


void loop()
{

}


