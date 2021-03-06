# ----------------------------------------------------------------------------
# This file is part of the Synthetos g2core project


# To compile:
#   make BOARD=GTwo

# You can also choose a CONFIG from boards.mk:
#   make CONFIG=corexylaser BOARD=GTwo



# Backward compatibility with old projects that use PLATFORM instead, but with a warning:
ifneq ("$(PLATFORM:-)","")
    $(warning Using PLATFORM value of $(PLATFORM) as BOARD.)
    $(warning Please swich to using BOARD on the command line.)
    BOARD = $(PLATFORM)
endif


##########
# BOARDs for use directly from the make command line (with default settings) or by CONFIGs.

ifeq ("$(BOARD)","GTwo")
    # This is a due with a jpcivade GTwo shield. We'll use the Due platform, but set defines
    # for the code to get the pinout right.

    # Note: we call it "g2core-due2" instead of "due" since the Motate built-in provides
    # a "due" BASE_BOARD.
    BASE_BOARD = g2core-due2
    DEVICE_DEFINES += MOTATE_BOARD="GTwo"
    DEVICE_DEFINES += SETTINGS_FILE=${SETTINGS_FILE}
endif


##########
# The general g2core-due2 BASE_BOARD.

ifeq ("$(BASE_BOARD)","g2core-due2")
    _BOARD_FOUND = 1

    DEVICE_DEFINES += MOTATE_CONFIG_HAS_USBSERIAL=1

    FIRST_LINK_SOURCES += $(sort $(wildcard ${MOTATE_PATH}/Atmel_sam_common/*.cpp)) $(sort $(wildcard ${MOTATE_PATH}/Atmel_sam3x/*.cpp))

    CHIP = SAM3X8E
    export CHIP
    CHIP_LOWERCASE = sam3x8e

    # Note: we call it "g2core-due2" instead of "due" since the Motate built-in provides
    # a "due" BASE_BOARD.
    BOARD_PATH = ./board/GTwo
    SOURCE_DIRS += ${BOARD_PATH} device/step_dir_driver

    PLATFORM_BASE = ${MOTATE_PATH}/platform/atmel_sam

    include $(PLATFORM_BASE).mk
endif
