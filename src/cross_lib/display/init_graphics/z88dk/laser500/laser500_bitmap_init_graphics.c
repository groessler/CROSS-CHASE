// indirizzi precalcolati delle 192 righe nelle modalità GR3, GR4, GR5
unsigned int laser500_gr_rows[192] = {
   0x0000,0x0800,0x1000,0x1800,0x2000,0x2800,0x3000,0x3800,
   0x0100,0x0900,0x1100,0x1900,0x2100,0x2900,0x3100,0x3900,
   0x0200,0x0a00,0x1200,0x1a00,0x2200,0x2a00,0x3200,0x3a00,
   0x0300,0x0b00,0x1300,0x1b00,0x2300,0x2b00,0x3300,0x3b00,
   0x0400,0x0c00,0x1400,0x1c00,0x2400,0x2c00,0x3400,0x3c00,
   0x0500,0x0d00,0x1500,0x1d00,0x2500,0x2d00,0x3500,0x3d00,
   0x0600,0x0e00,0x1600,0x1e00,0x2600,0x2e00,0x3600,0x3e00,
   0x0700,0x0f00,0x1700,0x1f00,0x2700,0x2f00,0x3700,0x3f00,
   0x0050,0x0850,0x1050,0x1850,0x2050,0x2850,0x3050,0x3850,
   0x0150,0x0950,0x1150,0x1950,0x2150,0x2950,0x3150,0x3950,
   0x0250,0x0a50,0x1250,0x1a50,0x2250,0x2a50,0x3250,0x3a50,
   0x0350,0x0b50,0x1350,0x1b50,0x2350,0x2b50,0x3350,0x3b50,
   0x0450,0x0c50,0x1450,0x1c50,0x2450,0x2c50,0x3450,0x3c50,
   0x0550,0x0d50,0x1550,0x1d50,0x2550,0x2d50,0x3550,0x3d50,
   0x0650,0x0e50,0x1650,0x1e50,0x2650,0x2e50,0x3650,0x3e50,
   0x0750,0x0f50,0x1750,0x1f50,0x2750,0x2f50,0x3750,0x3f50,
   0x00a0,0x08a0,0x10a0,0x18a0,0x20a0,0x28a0,0x30a0,0x38a0,
   0x01a0,0x09a0,0x11a0,0x19a0,0x21a0,0x29a0,0x31a0,0x39a0,
   0x02a0,0x0aa0,0x12a0,0x1aa0,0x22a0,0x2aa0,0x32a0,0x3aa0,
   0x03a0,0x0ba0,0x13a0,0x1ba0,0x23a0,0x2ba0,0x33a0,0x3ba0,
   0x04a0,0x0ca0,0x14a0,0x1ca0,0x24a0,0x2ca0,0x34a0,0x3ca0,
   0x05a0,0x0da0,0x15a0,0x1da0,0x25a0,0x2da0,0x35a0,0x3da0,
   0x06a0,0x0ea0,0x16a0,0x1ea0,0x26a0,0x2ea0,0x36a0,0x3ea0,
   0x07a0,0x0fa0,0x17a0,0x1fa0,0x27a0,0x2fa0,0x37a0,0x3fa0
};

// il font del Laser 500
unsigned char laser500_charset[256*8] = {
   0x00,0x00,0x00,0xf0,0x10,0x10,0x10,0x10,0x00,0x00,0x00,0xff,0x10,0x10,0x10,0x10,
   0x00,0x00,0x00,0x1f,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xf0,0x10,0x10,0x10,0x10,
   0x10,0x10,0x10,0xff,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1f,0x10,0x10,0x10,0x10,
   0x10,0x10,0x10,0xf0,0x00,0x00,0x00,0x00,0x10,0x10,0x10,0xff,0x00,0x00,0x00,0x00,
   0x10,0x10,0x10,0x1f,0x00,0x00,0x00,0x00,0x10,0x38,0x7c,0xfe,0xfe,0x7c,0x10,0x38,
   0x44,0xee,0xfe,0xfe,0x7c,0x38,0x10,0x00,0x10,0x38,0x54,0xfe,0x54,0x10,0x38,0x00,
   0x10,0x38,0x7c,0xfe,0x7c,0x38,0x10,0x00,0x00,0xfe,0x28,0x28,0x28,0x28,0x24,0x00,
   0x00,0x24,0x24,0x24,0x24,0x5c,0x02,0x00,0x30,0x48,0x08,0x1c,0x08,0x08,0x7c,0x00,
   0x00,0x80,0x5c,0x22,0x62,0x9c,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x0f,0x0f,0x0f,
   0x00,0x00,0x00,0x00,0xf0,0xf0,0xf0,0xf0,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff,
   0xf0,0xf0,0xf0,0xf0,0x00,0x00,0x00,0x00,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,
   0xf0,0xf0,0xf0,0xf0,0x0f,0x0f,0x0f,0x0f,0xf0,0xf0,0xf0,0xf0,0xff,0xff,0xff,0xff,
   0x0f,0x0f,0x0f,0x0f,0x00,0x00,0x00,0x00,0x0f,0x0f,0x0f,0x0f,0xf0,0xf0,0xf0,0xf0,
   0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0xff,0xff,0xff,0xff,
   0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff,0xf0,0xf0,0xf0,0xf0,
   0xff,0xff,0xff,0xff,0x0f,0x0f,0x0f,0x0f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x10,0x10,0x10,0x00,0x10,0x00,
   0x28,0x28,0x28,0x00,0x00,0x00,0x00,0x00,0x28,0x28,0x7c,0x28,0x7c,0x28,0x28,0x00,
   0x10,0x78,0x14,0x38,0x50,0x3c,0x10,0x00,0x0c,0x4c,0x20,0x10,0x08,0x64,0x60,0x00,
   0x08,0x14,0x14,0x08,0x54,0x24,0x58,0x00,0x10,0x10,0x10,0x00,0x00,0x00,0x00,0x00,
   0x20,0x10,0x08,0x08,0x08,0x10,0x20,0x00,0x08,0x10,0x20,0x20,0x20,0x10,0x08,0x00,
   0x10,0x54,0x38,0x10,0x38,0x54,0x10,0x00,0x00,0x10,0x10,0x7c,0x10,0x10,0x00,0x00,
   0x00,0x00,0x00,0x00,0x10,0x10,0x08,0x00,0x00,0x00,0x00,0x7c,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x40,0x20,0x10,0x08,0x04,0x00,0x00,
   0x38,0x44,0x64,0x54,0x4c,0x44,0x38,0x00,0x10,0x18,0x10,0x10,0x10,0x10,0x38,0x00,
   0x38,0x44,0x40,0x30,0x08,0x04,0x7c,0x00,0x7c,0x40,0x20,0x30,0x40,0x44,0x38,0x00,
   0x20,0x30,0x28,0x24,0x7c,0x20,0x20,0x00,0x7c,0x04,0x3c,0x40,0x40,0x44,0x38,0x00,
   0x70,0x08,0x04,0x3c,0x44,0x44,0x38,0x00,0x7c,0x40,0x20,0x10,0x08,0x08,0x08,0x00,
   0x38,0x44,0x44,0x38,0x44,0x44,0x38,0x00,0x38,0x44,0x44,0x78,0x40,0x20,0x1c,0x00,
   0x00,0x00,0x10,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x10,0x10,0x08,0x00,
   0x20,0x10,0x08,0x04,0x08,0x10,0x20,0x00,0x00,0x00,0x7c,0x00,0x7c,0x00,0x00,0x00,
   0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x00,0x38,0x44,0x20,0x10,0x10,0x00,0x10,0x00,
   0x38,0x44,0x54,0x74,0x34,0x04,0x78,0x00,0x10,0x28,0x44,0x44,0x7c,0x44,0x44,0x00,
   0x3c,0x44,0x44,0x3c,0x44,0x44,0x3c,0x00,0x38,0x44,0x04,0x04,0x04,0x44,0x38,0x00,
   0x3c,0x44,0x44,0x44,0x44,0x44,0x3c,0x00,0x7c,0x04,0x04,0x3c,0x04,0x04,0x7c,0x00,
   0x7c,0x04,0x04,0x3c,0x04,0x04,0x04,0x00,0x78,0x04,0x04,0x04,0x64,0x44,0x78,0x00,
   0x44,0x44,0x44,0x7c,0x44,0x44,0x44,0x00,0x38,0x10,0x10,0x10,0x10,0x10,0x38,0x00,
   0x40,0x40,0x40,0x40,0x40,0x44,0x38,0x00,0x44,0x24,0x14,0x0c,0x14,0x24,0x44,0x00,
   0x04,0x04,0x04,0x04,0x04,0x04,0x7c,0x00,0x44,0x6c,0x54,0x54,0x44,0x44,0x44,0x00,
   0x44,0x44,0x4c,0x54,0x64,0x44,0x44,0x00,0x38,0x44,0x44,0x44,0x44,0x44,0x38,0x00,
   0x3c,0x44,0x44,0x3c,0x04,0x04,0x04,0x00,0x38,0x44,0x44,0x44,0x54,0x24,0x58,0x00,
   0x3c,0x44,0x44,0x3c,0x14,0x24,0x44,0x00,0x38,0x44,0x04,0x38,0x40,0x44,0x38,0x00,
   0x7c,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x44,0x44,0x44,0x44,0x44,0x44,0x38,0x00,
   0x44,0x44,0x44,0x44,0x44,0x28,0x10,0x00,0x44,0x44,0x44,0x54,0x54,0x6c,0x44,0x00,
   0x44,0x44,0x28,0x10,0x28,0x44,0x44,0x00,0x44,0x44,0x28,0x10,0x10,0x10,0x10,0x00,
   0x7c,0x40,0x20,0x10,0x08,0x04,0x7c,0x00,0x7c,0x0c,0x0c,0x0c,0x0c,0x0c,0x7c,0x00,
   0x00,0x04,0x08,0x10,0x20,0x40,0x00,0x00,0x7c,0x60,0x60,0x60,0x60,0x60,0x7c,0x00,
   0x00,0x00,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7c,0x00,
   0x08,0x10,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x40,0x78,0x44,0x78,0x00,
   0x04,0x04,0x3c,0x44,0x44,0x44,0x3c,0x00,0x00,0x00,0x78,0x04,0x04,0x04,0x78,0x00,
   0x40,0x40,0x78,0x44,0x44,0x44,0x78,0x00,0x00,0x00,0x38,0x44,0x7c,0x04,0x78,0x00,
   0x30,0x48,0x08,0x3c,0x08,0x08,0x08,0x00,0x00,0x00,0x38,0x44,0x44,0x78,0x40,0x38,
   0x04,0x04,0x3c,0x44,0x44,0x44,0x44,0x00,0x10,0x00,0x18,0x10,0x10,0x10,0x38,0x00,
   0x20,0x00,0x30,0x20,0x20,0x20,0x24,0x18,0x04,0x04,0x44,0x24,0x1c,0x24,0x44,0x00,
   0x18,0x10,0x10,0x10,0x10,0x10,0x38,0x00,0x00,0x00,0x6c,0x54,0x54,0x54,0x44,0x00,
   0x00,0x00,0x3c,0x44,0x44,0x44,0x44,0x00,0x00,0x00,0x38,0x44,0x44,0x44,0x38,0x00,
   0x00,0x00,0x3c,0x44,0x44,0x3c,0x04,0x04,0x00,0x00,0x78,0x44,0x44,0x78,0x40,0x40,
   0x00,0x00,0x74,0x0c,0x04,0x04,0x04,0x00,0x00,0x00,0x78,0x04,0x38,0x40,0x3c,0x00,
   0x08,0x08,0x3c,0x08,0x08,0x48,0x30,0x00,0x00,0x00,0x44,0x44,0x44,0x64,0x58,0x00,
   0x00,0x00,0x44,0x24,0x28,0x18,0x10,0x00,0x00,0x00,0x44,0x44,0x54,0x54,0x6c,0x00,
   0x00,0x00,0x44,0x28,0x10,0x28,0x44,0x00,0x00,0x00,0x44,0x24,0x28,0x18,0x10,0x0c,
   0x00,0x00,0x7c,0x20,0x10,0x08,0x7c,0x00,0x70,0x18,0x18,0x0c,0x18,0x18,0x70,0x00,
   0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1c,0x30,0x30,0x60,0x30,0x30,0x1c,0x00,
   0x58,0x34,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f
};

#define LASER500_GR_MODE_5   0b000
#define LASER500_GR_MODE_4   0b010
#define LASER500_GR_MODE_3   0b011
#define LASER500_GR_MODE_2   0b110
#define LASER500_GR_MODE_1   0b111
#define LASER500_GR_MODE_0   0b100
#define LASER500_GR_MODE_OFF 16

#define LASER500_PORT_44_LATCH  ((unsigned char *)0x8669)  

// utility function OUT port, value
void laser500_outp(unsigned char port, unsigned char value) {
   __asm     
   ld	 ix,0
   add ix,sp
   ld	a,(ix+2)    // value
   ld	c,(ix+4)    // port
   out (c),a   
	__endasm;
}

// utility function PEEK()
unsigned char laser500_peek(unsigned char *address) __z88dk_fastcall {
   return *address;
}

// utility function POKE
void laser500_poke(unsigned char *address, unsigned char value) {
   *address = value;
}

// writes into mapped i/o
void laser500_mapped_io_write(unsigned char value) __z88dk_fastcall __naked {
   __asm 
   di
   ld a, 2
   out (0x41), a

   ld a, l
   ld (0x6800), a
   
   ld a, (0x8666)
   out (0x41), a
   ei
   ret 
   __endasm;
}

// reads from mapped i/o
unsigned char laser500_mapped_io_read() __z88dk_fastcall __naked {
   __asm 
   di
   ld a, 2
   out (0x41), a
   
   ld a, (0x6800)
   ld h, 0
   ld l, a

   ld a, (0x8666)
   out (0x41), a
   ei
   ret 
   __endasm;
}


// sets gr mode
void laser500_gr_mode(unsigned char mode) {
   unsigned char io = laser500_mapped_io_read();
   
   // turn on graphic mode
   laser500_mapped_io_write(io | 0b1000);      

   // sets specific mode
   unsigned char latch = (laser500_peek(LASER500_PORT_44_LATCH) & 0b11111000) | mode;
   laser500_outp(0x44, latch);
   laser500_poke(LASER500_PORT_44_LATCH, latch);
}

// pulisce lo schermo in modalità GR4 (riempe VRAM di zeri)
void laser500_gr4_cls() {
   __asm
   di
   ld    a, 7           ; selects video memory 
   out   (0x41), a      ; and switches it in bank 1

   ; *** fill routine taken from CPC wiki ***

   ld    hl, 16384      ; start of memory

   ld    e,l            ; DE = HL + 1
   ld    d,h
   inc   de

   ld    bc, 16384      ; fills the whole video mem, BC = length of block in bytes

   ld    (hl), 0        ; writes the first byte
	
   ; HL+BC-1 = end address of block

   ldir                 ; fills

   ld    a, 1           ; selects ROM
   out   (0x41), a      ; and switches it back in bank 1
   ei
   __endasm
}

void laser500_gr4_draw(unsigned char x, unsigned char y, unsigned char *image, unsigned char color) 
{

   __asm
   di
   ld    a, 7           ; selects video memory 
   out   (0x41), a      ; and switches it in bank 1 (0x4000-0x7FFF)
   __endasm;
      
   /*
   // ciclo di scrittura della grafica 

   unsigned char *hl = image;
   unsigned int *bc = &rows[y*8];
   for(uint8_t i=0; i<8; i++) {
      unsigned char *de = 0x4000 + *bc + x*2;   // offset in video mem
      *de++ = *hl++;                            // scrive grafica
      *de = color;                              // scrive colore
      bc++;                                      
   }
   */

   // loop srotolato

   unsigned char *hl = image;
   unsigned int *bc = &laser500_gr_rows[y*8];
   unsigned char *tmp = 0x4000 + x*2;
   unsigned char *de;

   de = *bc + tmp; *de++ = *hl++; *de = color; bc++; 
   de = *bc + tmp; *de++ = *hl++; *de = color; bc++; 
   de = *bc + tmp; *de++ = *hl++; *de = color; bc++; 
   de = *bc + tmp; *de++ = *hl++; *de = color; bc++; 
   de = *bc + tmp; *de++ = *hl++; *de = color; bc++; 
   de = *bc + tmp; *de++ = *hl++; *de = color; bc++; 
   de = *bc + tmp; *de++ = *hl++; *de = color; bc++; 
   de = *bc + tmp; *de++ = *hl++; *de = color; bc++; 
   
   __asm
   ld    a, 1           ; selects ROM
   out   (0x41), a      ; and switches it back in bank 1
   ei
   __endasm
}

void INIT_GRAPHICS(void) {
   
   laser500_gr_mode(LASER500_GR_MODE_4);  // imposta la modalita grafica 320x192 (40x24)
   laser500_gr4_cls();                    // pulisce schermo

   unsigned char ch = 0;   
   for(unsigned char x=0;x<40;x++) {
      for(unsigned char y=0;y<24;y++) {
         unsigned char colore = ch;  // (foreground << 4) | background  (colori da 0 a 15)
         unsigned char *sorgente = &laser500_charset[(ch & 127)*8];
         laser500_gr4_draw(x,y, sorgente, colore);
         ch++;
      }     
   }
   // while(1){};
}
