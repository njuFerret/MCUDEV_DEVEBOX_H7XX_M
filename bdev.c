#include "storage.h"

#if !MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE

// External SPI flash uses QSPI interface

STATIC const mp_soft_qspi_obj_t qspi_bus = {
    .cs  = MICROPY_HW_QSPIFLASH_CS,
    .clk = MICROPY_HW_QSPIFLASH_SCK,
    .io0 = MICROPY_HW_QSPIFLASH_IO0,
    .io1 = MICROPY_HW_QSPIFLASH_IO1,
    .io2 = MICROPY_HW_QSPIFLASH_IO2,
    .io3 = MICROPY_HW_QSPIFLASH_IO3,
};

STATIC mp_spiflash_cache_t spi_bdev_cache;

const mp_spiflash_config_t spiflash_config = {
    .bus_kind = MP_SPIFLASH_BUS_QSPI,
    .bus.u_qspi.data = (void*)&qspi_bus,
    .bus.u_qspi.proto = &mp_soft_qspi_proto, 

#if MICROPY_HW_SPIFLASH_ENABLE_CACHE
    .cache = &spi_bdev_cache,
#endif

};


spi_bdev_t spi_bdev;

#endif
