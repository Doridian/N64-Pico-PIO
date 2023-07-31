// -------------------------------------------------- //
// This file is autogenerated by pioasm; do not edit! //
// -------------------------------------------------- //

#pragma once

#if !PICO_NO_HARDWARE
#include "hardware/pio.h"
#endif

// ------ //
// n64out //
// ------ //

#define n64out_wrap_target 0
#define n64out_wrap 18

static const uint16_t n64out_program_instructions[] = {
            //     .wrap_target
    0x80a0, //  0: pull   block                      
    0x6030, //  1: out    x, 16                      
    0x002d, //  2: jmp    !x, 13                     
    0x6028, //  3: out    x, 8                       
    0x002e, //  4: jmp    !x, 14                     
    0x4078, //  5: in     null, 24                   
    0x3020, //  6: wait   0 pin, 0               [16]
    0x4001, //  7: in     pins, 1                    
    0x20a0, //  8: wait   1 pin, 0                   
    0x6061, //  9: out    null, 1                    
    0x00e6, // 10: jmp    !osre, 6                   
    0x8020, // 11: push   block                      
    0x0000, // 12: jmp    0                          
    0x6061, // 13: out    null, 1                    
    0x6067, // 14: out    null, 7                    
    0xe881, // 15: set    pindirs, 1             [8] 
    0x7081, // 16: out    pindirs, 1             [16]
    0xe880, // 17: set    pindirs, 0             [8] 
    0x00ef, // 18: jmp    !osre, 15                  
            //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program n64out_program = {
    .instructions = n64out_program_instructions,
    .length = 19,
    .origin = -1,
};

static inline pio_sm_config n64out_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + n64out_wrap_target, offset + n64out_wrap);
    return c;
}

static inline void n64out_program_init(PIO pio, uint sm, uint offset, uint pin) {
    pio_gpio_init(pio, pin);
    pio_sm_set_consecutive_pindirs(pio, sm, pin, 1, false);
    pio_sm_config c = n64out_program_get_default_config(offset);
    sm_config_set_in_pins(&c, pin);
    sm_config_set_out_pins(&c, pin, 1);
    sm_config_set_set_pins(&c, pin, 1);
    //sm_config_set_sideset_pins(&c, pin);
    sm_config_set_out_shift(&c, false, false, 32);
    sm_config_set_in_shift(&c, false, false, 32);
    float frac = (clock_get_hz(clk_sys) / 1000000) / 8;
    sm_config_set_clkdiv(&c, frac);
    // Load our configuration, and jump to the start of the program
    pio_sm_init(pio, sm, offset, &c);
    // Set the state machine running
    pio_sm_set_enabled(pio, sm, true);
}

#endif
