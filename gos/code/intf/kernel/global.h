/**
 * @file global.h
 * @author Joshua Buchanan (joshuarobertbuchanan@gmail.com) (github: @natara1939344)
 * @brief contains the virtual addresses that the linker passes to the kernel's binary
 * @version 0.1
 * @date 2021-04-15
 * 
 * @copyright Copyright (C) 2021 under the 
 * 
 */

#ifndef GLOBAL_H
#define GLOBAL_H 1

#include <stdint.h>

#ifndef MSVC // my c_cpp_properties.json thinks MSVC is defined. but its not.
#include <efi.h>
#endif
// recreate the definitions in the efi-libraries to make the scary red squiggily lines go away!
#if defined(___VSCODE___) && defined(MSVC)
typedef EFI_BOOT_SERVICES* (*BOOT_SERVICES)();
typedef uint32_t (*LOCATE_HANDLE)(uint32_t, EFI_GUID*, void**, size_t*, void**);
typedef struct {
    BOOT_SERVICES BootServices;
} EFI_SYSTEM_TABLE;
typedef struct {
    LOCATE_HANDLE LocateHandle;
} EFI_BOOT_SERVICES;

typedef struct {
    uint8_t some_byte;
} EFI_HANDLE;

typedef struct {
    uint32_t one;
    uint32_t two;
    uint32_t tre;
    uint32_t fur;
} EFI_GUID;

#define SERIAL_IO_PROTOCOL {0, 0, 0, 0}

#endif

// recreate the definitions in bootboot.h to mak the scary red squiggily lines go away!
#if defined(___VSCODE___) && defined(MSVC)

typedef struct {
    uint64_t foobar;

    union {
        struct {
            uint64_t efi_ptr;
        } x86_64;
        struct {
            uint64_t efi_ptr;
        } aarch64;
    } arch;
} BOOTBOOT;

#endif

#include "bootboot.h"

#ifdef __cplusplus
extern "C" {
#endif


extern volatile BOOTBOOT bootboot;
extern volatile unsigned char environment[4096];
extern volatile uint8_t fb;
extern volatile uint8_t mmio;


#ifdef __cplusplus
}
#endif
#endif