/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <kernel.h>
#include <device.h>
#include <init.h>
#include <drivers/gpio.h>
#include <sys/sys_io.h>
#include <devicetree.h>

static int pinmux_anisectlc_init(const struct device *port) {
    ARG_UNUSED(port);

#if CONFIG_BOARD_ANISECTLC_10
    const struct device *p0 = device_get_binding("GPIO_0");
    gpio_pin_configure(p0, 5, GPIO_INPUT);
#endif
    return 0;
}

SYS_INIT(pinmux_anisectlc_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
