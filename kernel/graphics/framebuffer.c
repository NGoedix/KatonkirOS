#include <stddef.h>
#include "framebuffer.h"

struct limine_framebuffer *framebuffer;

volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};

void fb_init(void);

void fb_pixel(uint32_t x, uint32_t y, uint32_t colour) {
    // Check if the framebuffer is initialized.
    if (framebuffer == NULL) {
        fb_init();
    }
    
    // Check if the pixel is within the framebuffer.
    if (x >= framebuffer->width || y >= framebuffer->height) {
        return;
    }

    // Calculate the framebuffer pitch.
    int fb_pitch = framebuffer->pitch / 4;

    // Calculate the framebuffer pointer.
    uint32_t *fb_ptr = (uint32_t*) framebuffer->address;

    // Set the pixel.
    *(fb_ptr + y * fb_pitch + x) = colour;
}

void fb_clear(uint32_t colour) {
    // Check if the framebuffer is initialized.
    if (framebuffer == NULL) {
        fb_init();
    }

    // Calculate the framebuffer pitch.
    int fb_pitch = framebuffer->pitch / 4;

    // Calculate the framebuffer pointer.
    uint32_t *fb_ptr = (uint32_t*) framebuffer->address;

    // Clear the framebuffer.
    for (long unsigned int i = 0; i < framebuffer->height; i++) {
        for (long unsigned int j = 0; j < framebuffer->width; j++) {
            *(fb_ptr + i * fb_pitch + j) = colour;
        }
    }
}

void fb_init(void) {
    // Send the framebuffer request.
    framebuffer = framebuffer_request.response->framebuffers[0];
}