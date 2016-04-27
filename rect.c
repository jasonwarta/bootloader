__asm__(".code16\n");
__asm__("jmpl $0x0000, $main\n");

#define COLS 320 //max columns
#define ROWS 200 //max rows

/*
 * printString
 * prints string to the screen
 */
void printString(const char* str) {
	//print chars from string until reach null character
    	 while(*str) {
        	  __asm__ __volatile__ (
	 	"int $0x10" : : "a"(0x0e00 | *str), "b"(0x0007)
          	);
         	str++;
     	}
}

/* 
 * getInput()
 * read and discard character from stdin
 */
void consumeInput () {
     	__asm__ __volatile__ ("xorw %ax, %ax\nint $0x16\n");
}

/* 
 * drawPixel
 * prints a pixel on the screen
 * color - the desired color of the pixel
 * col 	 - column to draw pixel at
 * row	 - row to draw pixel at
 */
void drawPixel(unsigned char color, int col, int row) {
     	__asm__ __volatile__ (
          	"int $0x10" : : "a"(0x0c00 | color), "c"(col), "d"(row)
     	);
}

/*
 * initEnv
 * clears screen, sets display mode to pixels
 * sets screen height and width to 320x200
 */
void initEnv() {
     	//clear screen
	__asm__ __volatile__ ( "int $0x10" : : "a"(0x03) );
     	//set video mode
	__asm__ __volatile__ ( "int $0x10" : : "a"(0x0013) );
}

/*
 * initGraphics
 * draw concentric rectangles in descending size
 */
void initGraphics() {
     	int i = 0, j = 0;
     	int m = 0;
     	int cnt1 = 0, cnt2 =0;
     	unsigned char color = 10;

     	while (1)  {
          	if(m < (ROWS - m)) {
               		++cnt1;
          	}
          	if(m < (COLS - m - 3)) {
               		++cnt2;
         	}

          	if(cnt1 != cnt2) {
               		cnt1 = 0;
               		cnt2 = 0;
               		m = 0;
               		if(++color > 255) color= 0;
          	}

          	//draw left side of the rectangle                             */
          	j = 0;
          	for(i = m; i < ROWS - m; ++i) {
               		drawPixel(color, j+m, i);
          	}
          	//draw bottom side of the rectangle                          */
          	for(j = m; j < COLS - m; ++j) {
               		drawPixel(color, j, i);
          	}

          	//draw right side of the rectangle                            */
          	for(i = ROWS - m - 1 ; i >= m; --i) {
               		drawPixel(color, COLS - m - 1, i);
          	}
          	//draw top side of the rectangle                              */
          	for(j = COLS - m - 1; j >= m; --j) {
               		drawPixel(color, j, m);
          	}
          	m += 6;
          	if(++color > 255)  color = 0;
     	}
}

void main() {
     	printString("Press the any key to continue...\n\r");
     	consumeInput();
     	initEnv();
     	initGraphics();
}
