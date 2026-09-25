#include "uart.h"

//1.enable clock access to uart (we have to know uart is connected to which bus , we find this in refernece manual/datasheet see block diagram)
// uart use 2 pins one for TX and other for RX , so we have to configure 2 pins as GPIO Alternate Function (AF) mode , the AF will set the exact pin(PA2,PA3,..) as GPIO of UART 
//2.Enable Clock access port A
//3.Enable pins for AF , PA9,PB7 (you can find that VCP is associated to these pins in UM1907 pages 31 and 33 , also USART1 RX and TX is assocaited to PA9 and PB7 see Data sheet page65/70 )
//4.Configure type of AF
//5.Configure uart and then configure it to read/write
void USART1_Init(void){
	// 1.enable clock access to uart => to do this we need the bus that this uart is connected to 
	RCC->APB2ENR |= 1<<4; // only bit number 4 is changed to 1 , other bits remains as them
	// enbale clock access to portA and port B
	RCC->AHB1ENR |= (1U << 0) | (1U << 1);
	// 3.Enable pins for alternate functions , PA9(for TX) , PB7(for RX) (look for alternate function mapping in datasheet) ,PA9 and PB7 because these the ports that virtual COM USB-UART adapter use
	// Put PA9,PB7 in Alternate Function mode (00:input mode , 01:outut mode , 10:AF mode , 11:Analog mode)
	GPIOA->MODER &= ~(0x3U << 18); // clear PA9 mode bits
	GPIOA->MODER |= (0x2U << 18);	 // PA9 = AF mode
	GPIOB->MODER &= ~(0x3U << 14); // clear PB7 mode bits
	GPIOB->MODER |= (0x2U << 14);	 // PB7 = AF mode
	// 4.Configure  type of alternate funciton
	// PA9 -> AF7
	// PA9 is AFRH, and AFR9 occupies bits [7:4]
	GPIOA->AFR[1] &= ~(0xFU << 4);// 0111 correspond to AF7 and thay are set in AFR9[3:0]
	GPIOA->AFR[1] |=  (0x7U << 4);
	// PB7 -> AF7
	// PB7 is AFRL, and AFR7 occupies bits [31:28]
	GPIOB->AFR[0] &= ~(0xFU << 28);// 0111 correspond to AF7 and thay are set in AFR9[3:0]
	GPIOB->AFR[0] |=  (0x7U << 28);
	// Configure uart 
  USART1->CR1 = 0x0000; // USART disabled while configuring it
	USART1->BRR = 0x2BF2; // 108 MHz clock, 9600 baud, oversampling by 16
	USART1->CR2 = 0x0000; //// 1 stop bit
	USART1->CR3 = 0x000;
	USART1->CR1 = (1 << 3) |   // TE
							  (1 << 2) |   // RE
							  (1 << 0);    // UE 
}

//Now we will write a function that write/send a character to a pc

int USART1_write(int ch){
	//ensure transfer buffer is empty before sending character
	while (!(USART1->ISR	& 1<<7)); //TXE — (Transmit data register empty) is bit number 7 in ISR regiter , if it is 1 mean that TDR is empty
	USART1->TDR= (ch & 0xFF); // 0xFF because only write 8-bit data and this correspond to a character in ASCII , TDR : Transmitted Data Register
	return ch;
}
//Now we will write a function that read a character 
int USART1_read(void){
	//we have to wait for a character to arrive before reading
	while (!(USART1->ISR	& 1<<5)); //RXNE(Read data register not empty) is bit 5 of ISR ,when it is set to 1 mean : 1: Received data is ready to be read.
	return USART1->RDR;
}

// The code below is  the interface to the C standard I/O library , ALL the I/O are directed to the console

FILE 	_stdin = {0};
FILE 	_stdout = {1};
FILE 	_stderr = {2};


// fgetc() is a standard C I/O function; the library knows its interface, and we provide its implementation to redirect input to our UART4.

int fgetc(FILE *f){
	int c;
	c = USART1_read(); //read the character from the console
	if (c=='\r'){
		USART1_write(c) ;
		c='\n';
	}
	USART1_write(c) ; //echo
	return c;
}

//called by C library console file/output 
int fputc(int c,FILE *f){
	return USART1_write(c);//write character to the console
}

int n ;
char str[80];

void test_setup(void){
	printf("please enter a number: ");
	scanf("%d",&n);
	printf("the number entered is : %d\r\n",n);
	printf("please type a character string :");
	fgets(str, sizeof(str), stdin);
	printf("the character string entered is : ");
	puts(str);
	printf("\r\n");
}