/********************************************/
/*                                          */
/*   GRAPHICS TABLES  -  WIN ICVGM v3.00    */
/*                                          */
/*        WARNING : RLE COMPRESSION         */
/*                                          */
/********************************************/

#include <coleco.h>

byte NAMERLE[] = {
  0xFE, 0x20, 0xFE, 0x20, 0xFE, 0x20, 0xFE, 0x20, 0xFE, 0x20, 0xFE, 0x20, 0x85, 0x20, 0xFF};
 

byte PATTERNRLE[] = {
  0x88, 0x00, 0x1D, 0x40, 0x24, 0x00, 0x89, 0x16, 0x89, 0x2A, 0x87, 0x6B, 0x15, 0x62, 0x14,
  0x20, 0x12, 0x00, 0x00, 0x40, 0x24, 0x00, 0x89, 0x16, 0x89, 0x2A, 0x87, 0x6B, 0x15, 0x62, 0x14,
  0x20, 0x12, 0xA0, 0x00, 0x81, 0x80, 0x1B, 0x49, 0x12, 0x10, 0xEA, 0x95, 0x8A, 0xD3, 0xF8, 0xE1,
  0xD8, 0x92, 0x09, 0x00, 0x00, 0x80, 0x80, 0x49, 0x12, 0x10, 0xEA, 0x95, 0x8A, 0xD3, 0xF8, 0xE1,
  0xD8, 0x92, 0x09, 0x99, 0x00, 0xBF, 0x10, 0xC9, 0x00, 0x04, 0x0C, 0x18, 0x30, 0x00, 0x60, 0x82,
  0x00, 0x81, 0x66, 0x85, 0x00, 0x21, 0x66, 0xFF, 0x66, 0xFF, 0x66, 0x00, 0x18, 0x3E, 0x60, 0x3C,
  0x06, 0x7C, 0x18, 0x00, 0xFF, 0x81, 0xB9, 0xA5, 0xB9, 0xA5, 0x81, 0xFF, 0x3C, 0x66, 0x3C, 0x38,
  0x67, 0x66, 0x3F, 0x80, 0x00, 0x00, 0x18, 0x30, 0x85, 0x00, 0x00, 0x18, 0x82, 0x30, 0x00, 0x18,
  0x82, 0x00, 0x00, 0x18, 0x82, 0x0C, 0x00, 0x18, 0x82, 0x00, 0x04, 0x5A, 0x3C, 0x7E, 0x3C, 0x5A,
  0x82, 0x00, 0x81, 0x18, 0x02, 0x7E, 0x18, 0x18, 0x85, 0x00, 0x01, 0x18, 0x30, 0x84, 0x00, 0x00,
  0x7E, 0x88, 0x00, 0x00, 0x18, 0x82, 0x00, 0x0F, 0x0C, 0x18, 0x30, 0x60, 0xC0, 0x00, 0x70, 0x88,
  0x98, 0xA8, 0xC8, 0x88, 0x70, 0x00, 0x20, 0x60, 0x83, 0x20, 0x2D, 0x70, 0x00, 0x70, 0x88, 0x08,
  0x30, 0x40, 0x80, 0xF8, 0x00, 0xF8, 0x08, 0x10, 0x30, 0x08, 0x88, 0x70, 0x00, 0x10, 0x30, 0x50,
  0x90, 0xF8, 0x10, 0x10, 0x00, 0xF8, 0x80, 0xF0, 0x08, 0x08, 0x88, 0x70, 0x00, 0x38, 0x40, 0x80,
  0xF0, 0x88, 0x88, 0x70, 0x00, 0xF8, 0x08, 0x10, 0x20, 0x82, 0x40, 0x0F, 0x00, 0x70, 0x88, 0x88,
  0x70, 0x88, 0x88, 0x70, 0x00, 0x70, 0x88, 0x88, 0x78, 0x08, 0x10, 0xE0, 0x82, 0x00, 0x02, 0x20,
  0x00, 0x20, 0x84, 0x00, 0x0C, 0x20, 0x00, 0x20, 0x20, 0x40, 0x00, 0x10, 0x20, 0x40, 0x80, 0x40,
  0x20, 0x10, 0x82, 0x00, 0x02, 0xF8, 0x00, 0xF8, 0x82, 0x00, 0x29, 0x40, 0x20, 0x10, 0x08, 0x10,
  0x20, 0x40, 0x00, 0x70, 0x88, 0x10, 0x20, 0x20, 0x00, 0x20, 0x00, 0x70, 0x88, 0xA8, 0xB8, 0xB0,
  0x80, 0x78, 0x00, 0x20, 0x50, 0x88, 0x88, 0xF8, 0x88, 0x88, 0x00, 0xF0, 0x88, 0x88, 0xF0, 0x88,
  0x88, 0xF0, 0x00, 0x70, 0x88, 0x82, 0x80, 0x03, 0x88, 0x70, 0x00, 0xF0, 0x84, 0x88, 0x0D, 0xF0,
  0x00, 0xF8, 0x80, 0x80, 0xF0, 0x80, 0x80, 0xF8, 0x00, 0xF8, 0x80, 0x80, 0xF0, 0x82, 0x80, 0x01,
  0x00, 0x78, 0x82, 0x80, 0x03, 0x98, 0x88, 0x78, 0x00, 0x82, 0x88, 0x00, 0xF8, 0x82, 0x88, 0x01,
  0x00, 0x70, 0x84, 0x20, 0x01, 0x70, 0x00, 0x84, 0x08, 0x0A, 0x88, 0x70, 0x00, 0x88, 0x90, 0xA0,
  0xC0, 0xA0, 0x90, 0x88, 0x00, 0x85, 0x80, 0x05, 0xF8, 0x00, 0x88, 0xD8, 0xA8, 0xA8, 0x82, 0x88,
  0x09, 0x00, 0x88, 0x88, 0xC8, 0xA8, 0x98, 0x88, 0x88, 0x00, 0x70, 0x84, 0x88, 0x05, 0x70, 0x00,
  0xF0, 0x88, 0x88, 0xF0, 0x82, 0x80, 0x01, 0x00, 0x70, 0x82, 0x88, 0x14, 0xA8, 0x90, 0x68, 0x00,
  0xF0, 0x88, 0x88, 0xF0, 0xA0, 0x90, 0x88, 0x00, 0x70, 0x88, 0x80, 0x70, 0x08, 0x88, 0x70, 0x00,
  0xF8, 0x85, 0x20, 0x00, 0x00, 0x85, 0x88, 0x01, 0x70, 0x00, 0x84, 0x88, 0x02, 0x50, 0x20, 0x00,
  0x82, 0x88, 0x81, 0xA8, 0x0D, 0xD8, 0x88, 0x00, 0x88, 0x88, 0x50, 0x20, 0x50, 0x88, 0x88, 0x00,
  0x88, 0x88, 0x50, 0x83, 0x20, 0x09, 0x00, 0xF8, 0x08, 0x10, 0x20, 0x40, 0x80, 0xF8, 0x00, 0xF8,
  0x84, 0xC0, 0x00, 0xF8, 0xFE, 0x00, 0xFE, 0x00, 0xE2, 0x00, 0xFE, 0x10, 0xC0, 0x10, 0xFE, 0x00,
  0xFE, 0x00, 0x85, 0x00, 0x0A, 0x01, 0x06, 0x01, 0x02, 0x07, 0x0B, 0x15, 0x02, 0x14, 0x00, 0x02,
  0x84, 0x00, 0x03, 0x01, 0x06, 0x01, 0x02, 0xA7, 0x00, 0x81, 0x80, 0x0A, 0x48, 0x10, 0x10, 0xE8,
  0x90, 0x88, 0xD0, 0xF0, 0xE0, 0xD0, 0x90, 0x82, 0x00, 0x81, 0x80, 0x05, 0x40, 0x10, 0x10, 0xE0,
  0x90, 0x80, 0xFE, 0x00, 0xFE, 0x00, 0xFE, 0x00, 0xAA, 0x00, 0xFF};

byte COLORRLE[] = {
  0x87, 0x41, 0x8F, 0x91, 0x8F, 0xB1, 0x9F, 0x41, 0x8F, 0x91, 0x8F, 0xB1, 0x97, 0x41, 0x00,
  0xF1, 0x87, 0x11, 0x00, 0xF1, 0x87, 0x11, 0x00, 0xF1, 0x87, 0x11, 0x00, 0xF1, 0x87, 0x11, 0x00,
  0xF1, 0x87, 0x11, 0x00, 0xF1, 0x87, 0x11, 0x00, 0xF1, 0x87, 0x11, 0x00, 0xF1, 0xFE, 0x41, 0xFE,
  0x41, 0xFE, 0x41, 0xFE, 0x41, 0xFE, 0x41, 0xFE, 0x41, 0xFE, 0x41, 0xFE, 0x41, 0xFE, 0x41, 0xFE,
  0x41, 0xC9, 0x41, 0x97, 0xB1, 0xA7, 0x41, 0x97, 0xB1, 0xFE, 0x41, 0xFE, 0x41, 0xFE, 0x41, 0xAA,
  0x41, 0xFF};

byte SPATTERNRLE[] = {
  0x82, 0x01, 0x82, 0x03, 0x09, 0x23, 0x26, 0x24, 0x76, 0x7E, 0x27, 0x7B, 0x77, 0x27, 0x06,
  0x82, 0x00, 0x82, 0x80, 0x09, 0x88, 0xC8, 0x48, 0xDC, 0xFC, 0xE8, 0xBC, 0xDC, 0xC8, 0xC0, 0x85,
  0x01, 0x99, 0x00, 0x1D, 0x0C, 0x1E, 0x37, 0x6D, 0x7F, 0x6F, 0x6D, 0x7B, 0x48, 0x4D, 0x47, 0x06,
  0x02, 0x02, 0x01, 0x00, 0x60, 0xF0, 0xD8, 0x6C, 0xFC, 0xEC, 0x6C, 0xBC, 0x24, 0x64, 0xC4, 0xC0,
  0x80, 0x80, 0x83, 0x00, 0x0C, 0x06, 0x0E, 0x1A, 0x3B, 0x74, 0x69, 0x1B, 0x69, 0x74, 0x3B, 0x1A,
  0x0E, 0x06, 0x82, 0x00, 0x0C, 0xC0, 0xE0, 0xB0, 0xB8, 0x5C, 0x2C, 0xB0, 0x2C, 0x5C, 0xB8, 0xB0,
  0xE0, 0xC0, 0x85, 0x00, 0x04, 0x04, 0xFF, 0x77, 0x1F, 0x3F, 0x88, 0x00, 0x02, 0x08, 0x45, 0x3F,
  0x83, 0xFF, 0x00, 0x07, 0x84, 0x00, 0x81, 0x30, 0x02, 0x74, 0xFD, 0xAE, 0x84, 0xFF, 0x03, 0xF0,
  0x04, 0x02, 0x04, 0x82, 0x00, 0x09, 0x40, 0x80, 0x00, 0x04, 0xC8, 0xFE, 0xFF, 0xFE, 0xD0, 0x08,
  0x84, 0x00, 0x0F, 0x03, 0x02, 0x03, 0x02, 0x03, 0x02, 0x03, 0x02, 0x03, 0x02, 0x03, 0x02, 0x03,
  0x02, 0x03, 0x02, 0x8F, 0x80, 0x84, 0x06, 0x8A, 0x00, 0x84, 0x60, 0x8A, 0x00, 0x06, 0x38, 0x7C,
  0xAA, 0xD7, 0xAF, 0x56, 0x3C, 0x98, 0x00, 0x06, 0x3C, 0x6A, 0xF5, 0xFB, 0x65, 0x3E, 0x0C, 0x98,
  0x00, 0x06, 0x1C, 0x3E, 0x4F, 0xED, 0xF5, 0x6A, 0x3C, 0x98, 0x00, 0x06, 0x3C, 0x56, 0xAF, 0xBB,
  0xDA, 0x74, 0x38, 0x99, 0x00, 0x82, 0x01, 0x04, 0x03, 0x01, 0x03, 0x01, 0x01, 0x84, 0x03, 0x81,
  0x01, 0x83, 0x00, 0x04, 0x80, 0x00, 0x80, 0x00, 0x00, 0x84, 0x80, 0x83, 0x00, 0x0C, 0x06, 0x0E,
  0x1A, 0x3B, 0x74, 0x69, 0x1B, 0x69, 0x74, 0x3B, 0x1A, 0x0E, 0x06, 0x82, 0x00, 0x0C, 0xC0, 0xE0,
  0xB0, 0xB8, 0x5C, 0x2C, 0xB0, 0x2C, 0x5C, 0xB8, 0xB0, 0xE0, 0xC0, 0x82, 0x00, 0x0C, 0x06, 0x0E,
  0x1A, 0x3B, 0x77, 0x6F, 0x1F, 0x6F, 0x77, 0x3B, 0x1A, 0x0E, 0x06, 0x82, 0x00, 0x19, 0xC0, 0xE0,
  0xB0, 0xB8, 0xDC, 0xEC, 0xF0, 0xEC, 0xDC, 0xB8, 0xB0, 0xE0, 0xC0, 0x00, 0x07, 0x03, 0x27, 0x46,
  0x4C, 0x7E, 0x6E, 0x6A, 0x7D, 0x4E, 0x47, 0x23, 0x82, 0x02, 0x0C, 0x00, 0xC0, 0x80, 0xC8, 0xC4,
  0x64, 0xFC, 0xEC, 0xAC, 0x7C, 0xE4, 0xC4, 0x88, 0x82, 0x80, 0x31, 0x00, 0x06, 0x0E, 0x1E, 0x3F,
  0x76, 0x6C, 0x7C, 0x7D, 0x1F, 0x0D, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0xC0, 0xE0, 0xF0, 0xF8,
  0xDC, 0x6C, 0x7C, 0x7C, 0xF0, 0x60, 0xC0, 0xC0, 0x80, 0x80, 0x00, 0x00, 0x06, 0x0E, 0x0E, 0x0F,
  0x06, 0x0C, 0x0C, 0x05, 0x07, 0x05, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0xC0, 0x82, 0xE0, 0x00,
  0xC0, 0x82, 0x60, 0x09, 0xE0, 0x60, 0xC0, 0xC0, 0x80, 0x80, 0x00, 0x00, 0x01, 0x01, 0x82, 0x03,
  0x82, 0x02, 0x81, 0x03, 0x81, 0x01, 0x83, 0x00, 0x01, 0x80, 0xC0, 0x88, 0xE0, 0x81, 0xC0, 0x81,
  0x80, 0x00, 0x00, 0x83, 0x01, 0x83, 0x03, 0x03, 0x01, 0x00, 0x01, 0x01, 0x83, 0x00, 0x00, 0x80,
  0x82, 0xC0, 0x85, 0xE0, 0x82, 0xC0, 0x81, 0x80, 0x00, 0x00, 0x8F, 0x08, 0x8F, 0x10, 0x88, 0x00,
  0x02, 0x01, 0x03, 0x07, 0x83, 0x0F, 0x15, 0x01, 0x03, 0x06, 0x09, 0x1F, 0x3E, 0x3F, 0x7E, 0xFC,
  0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0xDE, 0xB4, 0xD8, 0x20, 0xE0, 0xA0, 0x9E, 0x00, 0x20,
  0x02, 0x01, 0x03, 0x03, 0x07, 0x0E, 0x14, 0x29, 0x1A, 0x71, 0xEF, 0x10, 0x28, 0x51, 0x60, 0xC5,
  0x8A, 0x11, 0x2B, 0x2B, 0x52, 0xC4, 0xA8, 0x50, 0xA0, 0x80, 0x00, 0x61, 0x82, 0x44, 0xA8, 0x50,
  0xA0, 0x9B, 0x00, 0x0C, 0x07, 0x0F, 0x1B, 0x37, 0x6F, 0x7F, 0x41, 0x7F, 0x6F, 0x37, 0x1B, 0x0F,
  0x07, 0x82, 0x00, 0x04, 0xC0, 0xE0, 0xB0, 0xD8, 0xEC, 0x82, 0xFC, 0x04, 0xEC, 0xD8, 0xB0, 0xE0,
  0xC0, 0x82, 0x00, 0x0C, 0x07, 0x0F, 0x1B, 0x37, 0x6F, 0x7F, 0x78, 0x7F, 0x6F, 0x37, 0x1B, 0x0F,
  0x07, 0x82, 0x00, 0x0C, 0xC0, 0xE0, 0xB0, 0xD8, 0xEC, 0xFC, 0x3C, 0xFC, 0xEC, 0xD8, 0xB0, 0xE0,
  0xC0, 0x82, 0x00, 0x04, 0x07, 0x0F, 0x1B, 0x37, 0x6F, 0x82, 0x7F, 0x04, 0x6F, 0x37, 0x1B, 0x0F,
  0x07, 0x82, 0x00, 0x0C, 0xC0, 0xE0, 0xB0, 0xD8, 0xEC, 0xFC, 0x04, 0xFC, 0xEC, 0xD8, 0xB0, 0xE0,
  0xC0, 0x87, 0x00, 0x02, 0x01, 0x03, 0x01, 0x8D, 0x00, 0x00, 0x80, 0x8B, 0x00, 0x06, 0x03, 0x04,
  0x09, 0x0B, 0x09, 0x04, 0x03, 0x88, 0x00, 0x06, 0x80, 0x40, 0x20, 0xA0, 0x20, 0x40, 0x80, 0x87,
  0x00, 0x08, 0x02, 0x03, 0x04, 0x09, 0x1B, 0x09, 0x04, 0x03, 0x02, 0x86, 0x00, 0x81, 0x80, 0x06,
  0x40, 0x20, 0xB0, 0x20, 0x40, 0x80, 0x80, 0x84, 0x00, 0x0C, 0x06, 0x0E, 0x1A, 0x3B, 0x74, 0x69,
  0x1B, 0x69, 0x74, 0x3B, 0x1A, 0x0E, 0x06, 0x82, 0x00, 0x2F, 0xC0, 0xE0, 0xB0, 0xB8, 0x5C, 0x2C,
  0xB0, 0x2C, 0x5C, 0xB8, 0xB0, 0xE0, 0xC0, 0x00, 0x3C, 0x66, 0x5A, 0x66, 0x5A, 0x66, 0x3D, 0x1B,
  0x1B, 0x3D, 0x66, 0x5A, 0x66, 0x5A, 0x66, 0x3C, 0x3C, 0x66, 0x5A, 0x66, 0x5A, 0x66, 0xBC, 0xD8,
  0xD8, 0xBC, 0x66, 0x5A, 0x66, 0x5A, 0x66, 0x3C, 0x3C, 0x66, 0x82, 0x5A, 0x05, 0x66, 0x3C, 0x18,
  0x18, 0x3C, 0x66, 0x82, 0x5A, 0x03, 0x66, 0x3C, 0x3C, 0x66, 0x82, 0x5A, 0x05, 0x66, 0x3C, 0x18,
  0x18, 0x3C, 0x66, 0x82, 0x5A, 0x0F, 0x66, 0x3C, 0x00, 0x00, 0x08, 0x2A, 0x3E, 0x3E, 0x3F, 0x2F,
  0x0F, 0x07, 0x07, 0x05, 0x01, 0x01, 0x83, 0x00, 0x01, 0x20, 0xA8, 0x82, 0xF8, 0x04, 0xE8, 0xE0,
  0xC0, 0xC0, 0x40, 0x84, 0x00, 0x0C, 0x07, 0x0F, 0x1B, 0x33, 0x63, 0x66, 0x64, 0x66, 0x63, 0x33,
  0x1B, 0x0F, 0x07, 0x82, 0x00, 0x0C, 0xC0, 0xE0, 0xB0, 0x98, 0x8C, 0xCC, 0x4C, 0xCC, 0x8C, 0x98,
  0xB0, 0xE0, 0xC0, 0x82, 0x00, 0x0C, 0x07, 0x0F, 0x18, 0x30, 0x63, 0x66, 0x64, 0x66, 0x6F, 0x3C,
  0x18, 0x0F, 0x07, 0x82, 0x00, 0x0C, 0xC0, 0xE0, 0x70, 0xF8, 0xEC, 0xCC, 0x4C, 0xCC, 0x8C, 0x18,
  0x30, 0xE0, 0xC0, 0x82, 0x00, 0x0C, 0x07, 0x0F, 0x18, 0x30, 0x63, 0x7E, 0x7C, 0x7E, 0x63, 0x30,
  0x18, 0x0F, 0x07, 0x82, 0x00, 0x0C, 0xC0, 0xE0, 0x30, 0x18, 0x8C, 0xFC, 0x7C, 0xFC, 0x8C, 0x18,
  0x30, 0xE0, 0xC0, 0x82, 0x00, 0x0C, 0x07, 0x0F, 0x1C, 0x3E, 0x6F, 0x66, 0x64, 0x66, 0x63, 0x30,
  0x18, 0x0F, 0x07, 0x82, 0x00, 0x0C, 0xC0, 0xE0, 0x30, 0x18, 0x8C, 0xCC, 0x4C, 0xCC, 0xEC, 0x78,
  0x30, 0xE0, 0xC0, 0x85, 0x00, 0x07, 0x01, 0x05, 0x07, 0x07, 0x05, 0x05, 0x01, 0x01, 0x88, 0x00,
  0x04, 0x40, 0xC0, 0xC0, 0x40, 0x40, 0x8A, 0x00, 0x05, 0x01, 0x05, 0x07, 0x07, 0x03, 0x01, 0x89,
  0x00, 0x05, 0x80, 0xA0, 0xE0, 0xE0, 0xC0, 0x80, 0x89, 0x00, 0x05, 0x01, 0x05, 0x07, 0x06, 0x03,
  0x01, 0x89, 0x00, 0x05, 0x80, 0xA0, 0xE0, 0x60, 0xC0, 0x80, 0x84, 0x00, 0x04, 0x02, 0x01, 0x03,
  0x03, 0x01, 0x8A, 0x00, 0x03, 0x80, 0x00, 0x80, 0x80, 0x8B, 0x00, 0x8F, 0x80, 0x90, 0x01, 0x23,
  0x56, 0x08, 0x08, 0x2B, 0x82, 0x43, 0x46, 0x00, 0x32, 0x4E, 0x23, 0x3B, 0x74, 0x28, 0x4E, 0x10,
  0x02, 0x4A, 0xC8, 0x80, 0x80, 0x8C, 0xC1, 0x48, 0xD4, 0xEC, 0x29, 0xBC, 0x5C, 0x1A, 0x40, 0x00,
  0x11, 0x25, 0x15, 0x01, 0x8A, 0x02, 0x04, 0x00, 0x10, 0x48, 0x50, 0x00, 0x8A, 0x80, 0x8C, 0x02,
  0x81, 0x03, 0x00, 0x02, 0x8D, 0x80, 0x81, 0x00, 0x0F, 0x02, 0x03, 0x02, 0x03, 0x02, 0x03, 0x02,
  0x03, 0x02, 0x03, 0x02, 0x03, 0x02, 0x03, 0x02, 0x03, 0x8F, 0x80, 0xFF};

int SPRITESINITSIZE = 192;

byte SPRITESINIT[] = {
  204, 0, 0, 11,
  204, 0, 4, 15,
  204, 0, 8, 4,
  204, 0, 12, 13,
  204, 0, 16, 14,
  204, 0, 20, 14,
  204, 0, 24, 15,
  204, 0, 28, 15,
  204, 0, 32, 6,
  204, 0, 36, 6,
  204, 0, 40, 6,
  204, 0, 44, 6,
  204, 0, 48, 10,
  204, 0, 52, 15,
  204, 0, 56, 15,
  204, 0, 60, 15,
  204, 0, 64, 15,
  204, 0, 68, 15,
  204, 0, 72, 15,
  204, 0, 76, 15,
  204, 0, 80, 15,
  204, 0, 84, 15,
  204, 0, 88, 15,
  204, 0, 92, 15,
  204, 0, 96, 15,
  204, 0, 100, 15,
  204, 0, 104, 15,
  204, 0, 108, 15,
  204, 0, 112, 15,
  204, 0, 116, 15,
  204, 0, 120, 15,
  204, 0, 124, 15,
  204, 0, 128, 3,
  204, 0, 132, 3,
  204, 0, 136, 2,
  204, 0, 140, 15,
  204, 0, 144, 15,
  204, 0, 148, 15,
  204, 0, 152, 15,
  204, 0, 156, 15,
  204, 0, 160, 15,
  204, 0, 164, 15,
  204, 0, 168, 15,
  204, 0, 172, 15,
  204, 0, 176, 15,
  204, 0, 180, 15,
  204, 0, 184, 15,
  204, 0, 188, 15};
