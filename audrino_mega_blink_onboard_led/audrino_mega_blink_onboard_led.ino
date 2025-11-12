//PB7 -orange led

#define PERIPH_BASE 0x00
#define DD_B_REGISTER  (*(volatile unsigned char*)0x24)
#define GPIO_B_REGISTER (*(volatile unsigned char*)0x25)
#define DELAY_MILLIS 5000 

void setup() {
  DD_B_REGISTER |= (1<<7);  
}

void loop() {
  GPIO_B_REGISTER |= (1<<7);   
  delay(DELAY_MILLIS);
  GPIO_B_REGISTER &= ~(1<<7);  
  delay(DELAY_MILLIS);
}

