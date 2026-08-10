/**
 * @file platform_orion_stm32mp1.h
 * @brief Orion ST STM32MP157F-DK2 platform constants.
 *
 * This header centralizes platform paths and capability values used by HAL
 * modules. Deterministic/bit-precise I/O is expected to be delegated to the
 * Cortex-M4 real-time core and controlled from Linux via remoteproc + RPMsg.
 */

#pragma once

// CPU family: dual Cortex-A7.
static constexpr int    ORION_STM32MP1_CPU_CORES        = 2;
static constexpr double ORION_STM32MP1_CPU_MAX_FREQ_MHZ = 650.0;
static constexpr double ORION_STM32MP1_CPU_MIN_FREQ_MHZ = 200.0;
static constexpr double ORION_STM32MP1_CPU_TEMP_MAX_C   = 125.0;

// GPU: Vivante GCNanoLite (2D) on STM32MP15x.
static constexpr int    ORION_STM32MP1_GPU_SHADER_CORES = 1;
static constexpr double ORION_STM32MP1_GPU_MAX_FREQ_MHZ = 400.0;
static constexpr double ORION_STM32MP1_GPU_MIN_FREQ_MHZ = 150.0;
static constexpr double ORION_STM32MP1_GPU_TEMP_MAX_C   = 85.0;
static constexpr const char* ORION_STM32MP1_GPU_DEVFREQ_PATH = "/sys/class/devfreq/";
static constexpr const char* ORION_STM32MP1_GPU_DEVICE_PATH  = "/sys/devices/platform/";
static constexpr const char* ORION_STM32MP1_V3D_DEV_PATH     = "/dev/dri/card0";
static constexpr const char* ORION_STM32MP1_V3D_RENDER_PATH  = "/dev/dri/renderD128";

// Memory: LPDDR2/3 or DDR3.
static constexpr long long ORION_STM32MP1_MEM_8GB_BYTES = 8LL * 1024 * 1024 * 1024;
static constexpr long long ORION_STM32MP1_MEM_4GB_BYTES = 4LL * 1024 * 1024 * 1024;
static constexpr double ORION_STM32MP1_MEM_SPEED_MHZ    = 533.0;
static constexpr double ORION_STM32MP1_MEM_BW_GBS       = 4.2;
static constexpr int    ORION_STM32MP1_MEM_BUS_BITS     = 32;

// PCIe: none on STM32MP15x (external via expansion only).
static constexpr int    ORION_STM32MP1_PCIE_GEN    = 0;
static constexpr int    ORION_STM32MP1_PCIE_LANES  = 0;
static constexpr double ORION_STM32MP1_PCIE_BW_GBS = 0.0;
static constexpr const char* ORION_STM32MP1_PCIE_RC_PATH = "";

// USB.
static constexpr const char* ORION_STM32MP1_XHCI_DRIVER_PATH = "/sys/bus/platform/drivers/dwc3";
static constexpr int ORION_STM32MP1_USB3_PORT_COUNT = 0;
static constexpr int ORION_STM32MP1_USB2_PORT_COUNT = 2;

// Ethernet.
static constexpr const char* ORION_STM32MP1_ETH_IFACE      = "eth0";
static constexpr int         ORION_STM32MP1_ETH_SPEED_MBPS = 1000;

// Camera/video (V4L2).
static constexpr const char* ORION_STM32MP1_CSI_DEVICE0 = "/dev/video0";
static constexpr const char* ORION_STM32MP1_CSI_DEVICE1 = "/dev/video1";
static constexpr const char* ORION_STM32MP1_MEDIA_CTL0  = "/dev/media0";
static constexpr const char* ORION_STM32MP1_UNICAM_PATH = "/sys/bus/platform/devices";

// Display nodes.
static constexpr const char* ORION_STM32MP1_DRM_CARD0 = "/dev/dri/card0";
static constexpr const char* ORION_STM32MP1_DRM_CARD1 = "/dev/dri/card1";

// Audio.
static constexpr const char* ORION_STM32MP1_I2S_DEVICE = "/sys/bus/platform/devices";
static constexpr const char* ORION_STM32MP1_ALSA_CARDS = "/proc/asound/cards";

// Serial (STM32MP15 debug UARTs).
static constexpr const char* ORION_STM32MP1_DEBUG_UART = "/dev/ttySTM0";
static constexpr const char* ORION_STM32MP1_UART1      = "/dev/ttySTM1";

// Thermal thresholds.
static constexpr const char* ORION_STM32MP1_THERMAL_CPU_ZONE   = "/sys/class/thermal/thermal_zone0";
static constexpr const char* ORION_STM32MP1_THERMAL_SB_ZONE    = "/sys/class/thermal/thermal_zone1";
static constexpr double      ORION_STM32MP1_THERMAL_THROTTLE_C = 95.0;
static constexpr double      ORION_STM32MP1_THERMAL_SHUTDOWN_C = 110.0;

// GPIO via libgpiod.
static constexpr const char* ORION_STM32MP1_GPIOCHIP_PATH = "/dev/gpiochip0";
static constexpr int         ORION_STM32MP1_GPIO_PIN_COUNT = 128;

// Cortex-M4 remoteproc + RPMsg.
static constexpr int         ORION_STM32MP1_PRU_REMOTEPROC_ID = 0;
static constexpr const char* ORION_STM32MP1_PRU_REMOTEPROC_BASE = "/sys/class/remoteproc";
static constexpr const char* ORION_STM32MP1_PRU_RPMSG_DEVICE = "/dev/rpmsg_m4";
static constexpr const char* ORION_STM32MP1_PRU_FIRMWARE_DEFAULT = "stm32mp15-m4-fw";

// Storage paths.
static constexpr const char* ORION_STM32MP1_MMCBLK_PATH = "/dev/mmcblk0";
static constexpr const char* ORION_STM32MP1_NVME_PATH   = "/dev/nvme0n1";

// PMIC/power supply.
static constexpr const char* ORION_STM32MP1_POWER_SUPPLY_PATH = "/sys/class/power_supply";

// Optional external AI accelerators.
static constexpr const char* ORION_STM32MP1_HAILO8_PCIE_VENDOR = "1e60";
static constexpr const char* ORION_STM32MP1_CORAL_USB_VENDOR   = "18d1";

// Platform identification.
static constexpr const char* PLATFORM_NAME      = "Orion STM32MP1 Platform";
static constexpr const char* PLATFORM_SOC       = "ST STM32MP157F";
static constexpr const char* PLATFORM_IOBRIDGE  = "Cortex-M4";
static constexpr const char* ORION_STM32MP1_DT_MODEL_PATH = "/proc/device-tree/model";
