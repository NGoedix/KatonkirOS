#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include "boot/limine.h"

void fb_pixel(uint32_t x, uint32_t y, uint32_t colour);
void fb_clear(uint32_t colour);

#endif // FRAMEBUFFER_H