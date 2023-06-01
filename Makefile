# Modify this variable to fit your NEORV32 setup (neorv32 home folder)
NEORV32_HOME ?= ../neorv32
APP_SRC = main.c art_reg_if.c

include $(NEORV32_HOME)/sw/common/common.mk
