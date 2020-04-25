void DelayMs(unsigned int Time)
{
	unsigned int i,j;
	for(i=0;i<Time;i++)
		for(j=0;j<3000;j++);
}

#define LED2CON (*(volatile unsigned long *)0x11000100)
#define LED2DAT (*(volatile unsigned long *)0x11000104)

int main()
{
	LED2CON = 0x00000001;
	while (1) {
		LED2DAT = 0x01;
		DelayMs(500);
		LED2DAT = 0x00;
		DelayMs(500);
	}
	return 0;
}
