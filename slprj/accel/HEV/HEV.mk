# Copyright 1994-2013 The MathWorks, Inc.
#
# File    : accel_lcc.tmf   
#
# Abstract:
#	Accelerator template makefile for building a PC-based,
#       generated mex-file of Simulink model using generated C code. 
#	     LCC compiler version 2.4.
#
# 	This makefile attempts to conform to the guidelines specified in the
# 	IEEE Std 1003.2-1992 (POSIX) standard. It is designed to be used
#       with GNU Make (gmake) which is located in matlabroot/bin/win32.
#
# 	Note that this template is automatically customized by the Real-Time
#	Workshop build procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#	build:
#
#         MEX_OPTS       - User specific mex options.
#	  OPT_OPTS       - Optimization options. Default is none. To enable 
#                          debugging specify as OPT_OPTS=-g. 
#	  USER_SRCS      - Additional user sources, such as files needed by
#			   S-functions.
#	  USER_INCLUDES  - Additional include paths
#			   (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#			   (For Lcc, have a '/'as file seperator before the 
#			   file name instead of a '\' . 
#			   i.e.,  d:\work\proj1/myfile.c - reqd for 'gmake')
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see accel.tlc

#------------------------ Macros read by make_rtw ------------------------------
#
# The following macros are read by the build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the build procedure (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         = "%MATLAB%\bin\win32\gmake"
SHELL           = cmd
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = accel.tlc
COMPILER_TOOL_CHAIN = lcc

MAKEFILE_FILESEP = /

#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# build procedure.
#
#  MODEL_NAME      - Name of the Simulink block diagram
#  MODEL_MODULES   - Any additional generated source modules
#  MAKEFILE_NAME   - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT     - Path to where MATLAB is installed.
#  MATLAB_BIN      - Path to MATLAB executable.
#  S_FUNCTIONS     - List of S-functions.
#  S_FUNCTIONS_LIB - List of S-functions libraries to link.
#  SOLVER          - Solver source file name
#  NUMST           - Number of sample times
#  TID01EQ         - yes (1) or no (0): Are sampling rates of continuous task
#                    (tid=0) and 1st discrete task equal.
#  NCSTATES        - Number of continuous states
#  BUILDARGS       - Options passed in at the command line.
#  MEXEXT          - extension that a mex file has. See the MATLAB mexext 
#                    command

MODEL              = HEV
MODULES            = HEV_acc_data.c rtGetInf.c rtGetNaN.c rt_look.c rt_look1d.c rt_look2d_normal.c rt_nonfinite.c rt_zcfcn.c 
MAKEFILE           = HEV.mk
MATLAB_ROOT        = C:/Program Files (x86)/MATLAB/R2015a
ALT_MATLAB_ROOT    = C:/PROGRA~2/MATLAB/R2015a
MASTER_ANCHOR_DIR  = 
START_DIR          = C:/Users/Elena/Documents/MATLAB/HEV
MATLAB_BIN         = C:/Program Files (x86)/MATLAB/R2015a/bin
ALT_MATLAB_BIN     = C:/PROGRA~2/MATLAB/R2015a/bin
S_FUNCTIONS        = sf_sfun.c drive_engine.c sfun_spssw_discc.c
S_FUNCTIONS_LIB    = 
SOLVER             = 
NUMST              = 4
TID01EQ            = 0
NCSTATES           = 15
MEM_ALLOC          = RT_STATIC
BUILDARGS          =  ISPROTECTINGMODEL=NOTPROTECTING
MEXEXT             = mexw32

MODELREFS          = 
SHARED_SRC         = 
SHARED_SRC_DIR     = 
SHARED_BIN_DIR     = 
SHARED_LIB         = 
MEX_OPT_FILE       = -f C:/PROGRA~2/MATLAB/R2015a/bin/win32/mexopts/LCC-WI~1.XML
OPTIMIZATION_FLAGS = -DNDEBUG
ADDITIONAL_LDFLAGS = 

#--------------------------- Model and reference models -----------------------
MODELLIB                  = HEVlib.lib
MODELREF_LINK_LIBS        = 
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
MODELREF_TARGET_TYPE      = NONE

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif
ifneq ($(MATLAB_BIN),$(ALT_MATLAB_BIN))
MATLAB_BIN := $(ALT_MATLAB_BIN)
endif

#--------------------------- Tool Specifications ------------------------------

LCC = $(MATLAB_ROOT)\sys\lcc
include $(MATLAB_ROOT)\rtw\c\tools\lcctools.mak

MEX = $(MATLAB_BIN)\mex.bat
CC  = $(MATLAB_BIN)\mex.bat -c

#------------------------------ Include Path -----------------------------------

# Additional includes

ADD_INCLUDES = \
	-I$(START_DIR)/slprj/accel/HEV \
	-I$(START_DIR) \
	-I$(MATLAB_ROOT)/toolbox/physmod/drive/c \
	-I$(MATLAB_ROOT)/toolbox/physmod/common/foundation/core/c \
	-I$(MATLAB_ROOT)/toolbox/physmod/powersys/facts/facts \
	-I$(MATLAB_ROOT)/toolbox/physmod/powersys/DR/DR \


# see MATLAB_INCLUES and COMPILER_INCLUDES from lcctool.mak

SHARED_INCLUDES =
ifneq ($(SHARED_SRC_DIR),)
SHARED_INCLUDES = -I$(SHARED_SRC_DIR) 
endif

INCLUDES = -I. -I$(RELATIVE_PATH_TO_ANCHOR) $(MATLAB_INCLUDES) $(ADD_INCLUDES) \
           $(COMPILER_INCLUDES) $(USER_INCLUDES) $(MODELREF_INC_PATH) $(SHARED_INCLUDES)

#------------------------ C and MEX optimization options -----------------------
MEX_OPTS  =
OPT_OPTS  = $(DEFAULT_OPT_OPTS)

ifneq ($(ADDITIONAL_LDFLAGS),)
MEX_LDFLAGS = LINKFLAGS="$$LINKFLAGS $(ADDITIONAL_LDFLAGS)"
else
MEX_LDFLAGS =
endif

ifneq ($(OPTIMIZATION_FLAGS),)
MEX_OPT_OPTS = OPTIMFLAGS="$(OPTIMIZATION_FLAGS)"    # passed to 'mex -c'
else
MEX_OPT_OPTS = $(OPT_OPTS)    # passed to 'mex -c'
endif

ifeq "$(MEX_OPTS)" "-g"
MEX_OPT_OPTS =
endif

#-------------------------------- Mex Options  ---------------------------------
MEX_FLAGS = -win32 $(MEX_OPT_OPTS) $(MEX_LDFLAGS) $(MEX_OPTS) $(MEX_OPT_FILE)

#----------------------------- Source Files -----------------------------------
USER_SRCS =

USER_OBJS       = $(USER_SRCS:.c=.obj)
LOCAL_USER_OBJS = $(notdir $(USER_OBJS))

SRCS      = $(MODEL)_acc.c $(MODULES)
OBJS      = $(SRCS:.c=.obj) $(USER_OBJS)
LINK_OBJS = $(SRCS:.c=.obj) $(LOCAL_USER_OBJS)

SHARED_OBJS := $(addsuffix .obj, $(basename $(wildcard $(SHARED_SRC))))
FMT_SHARED_OBJS = $(subst /,\,$(SHARED_OBJS))

#------------------------- Additional Libraries -------------------------------

LIBS =

ifeq ($(OPT_OPTS),$(DEFAULT_OPT_OPTS))
LIBS += $(MATLAB_ROOT)/toolbox/physmod/drive/lib/win32\drive_rtwsfcn_lcc.lib
else
LIBS += drive.lib
endif

ifeq ($(OPT_OPTS),$(DEFAULT_OPT_OPTS))
LIBS += $(MATLAB_ROOT)/toolbox/physmod/common/foundation/core/lib/win32\pm_rtwsfcn_lcc.lib
else
LIBS += pm.lib
endif



LIBUT = $(MATLAB_ROOT)\extern\lib\win32\lcc\libut.lib
LIBMWMATHUTIL = $(MATLAB_ROOT)\extern\lib\win32\lcc\libmwmathutil.lib
LIBMWSL_FILEIO = $(MATLAB_ROOT)\extern\lib\win32\lcc\libmwsl_fileio.lib
LIBMWSIGSTREAM = $(MATLAB_ROOT)\extern\lib\win32\lcc\libmwsigstream.lib
LIBMWSIMULINK = $(MATLAB_ROOT)\extern\lib\win32\lcc\libmwsimulink.lib
LIBMWSL_ASYNCIO = $(MATLAB_ROOT)\extern\lib\win32\lcc\libmwsl_AsyncioQueue.lib
LIBMWIPP = $(MATLAB_ROOT)\lib\win32\libmwipp.lib
LIBS += $(LIBUT) $(LIBMWMATHUTIL) $(LIBMWSL_FILEIO) $(LIBMWIPP) $(LIBMWSIGSTREAM) $(LIBMWSL_ASYNCIO) $(LIBMWSIMULINK)

PROGRAM = ../$(MODEL)_acc.$(MEXEXT)

#--------------------------------- Rules --------------------------------------

$(PROGRAM) : $(OBJS) $(LIBS) $(SHARED_LIB)
	@echo ### Linking ...
	$(MEX) $(MEX_FLAGS) -outdir $(RELATIVE_PATH_TO_ANCHOR) $(LINK_OBJS) $(S_FUNCTIONS_LIB) $(SHARED_LIB) $(LIBS) 
	@echo ### Created mex file: $(MODEL)_acc.$(MEXEXT)

%.obj : %.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : $(MATLAB_ROOT)/toolbox/physmod/drive/c/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : $(MATLAB_ROOT)/toolbox/physmod/common/foundation/core/c/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : $(MATLAB_ROOT)/toolbox/physmod/powersys/powersys/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<



%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

# Libraries:



MODULES_drive = \
          drive_00086bb8.obj \
          drive_04d32aaa.obj \
          drive_06b3d5f7.obj \
          drive_09b42609.obj \
          drive_14095aa5.obj \
          drive_18bf41e1.obj \
          drive_24b97a0b.obj \
          drive_2eb0d43f.obj \
          drive_2f69c792.obj \
          drive_37da8b0a.obj \
          drive_3b6b9e79.obj \
          drive_3c08372a.obj \
          drive_3dd9ff85.obj \
          drive_3fb90b16.obj \
          drive_410ec910.obj \
          drive_42bd2888.obj \
          drive_4fde9639.obj \
          drive_53b24b68.obj \
          drive_53bff7a9.obj \
          drive_5769dfdf.obj \
          drive_5a0ddde3.obj \
          drive_5f018d7d.obj \
          drive_6dd6508c.obj \
          drive_7803c6e3.obj \
          drive_7bb44eb9.obj \
          drive_7d024e26.obj \
          drive_7d06989b.obj \
          drive_7eb1a98c.obj \
          drive_7eb471c2.obj \
          drive_7eb7cd5a.obj \
          drive_81b41582.obj \
          drive_856557c4.obj \
          drive_86ded01b.obj \
          drive_88018182.obj \
          drive_89dbfb38.obj \
          drive_91670bbf.obj \
          drive_93094e83.obj \
          drive_990ee54e.obj \
          drive_9e6825d5.obj \
          drive_9fbfe43c.obj \
          drive_a00782e0.obj \
          drive_a3bcbdd6.obj \
          drive_a5020cf1.obj \
          drive_a9b31829.obj \
          drive_a9b5c855.obj \
          drive_ad6deb4c.obj \
          drive_b6644a7b.obj \
          drive_b961df4c.obj \
          drive_bb0428e4.obj \
          drive_c0b2d23a.obj \
          drive_c6030848.obj \
          drive_c9039e0f.obj \
          drive_cab71e3f.obj \
          drive_cdd6dbbe.obj \
          drive_ce678e38.obj \
          drive_d20c8725.obj \
          drive_e10b9ab1.obj \
          drive_e4061127.obj \
          drive_e7b84bba.obj \
          drive_eadc2f29.obj \
          drive_f268bb40.obj \
          drive_f4da6f90.obj \
          drive_f76fec26.obj \
          drive_f865cda7.obj \
          drive_f9b3d817.obj \
          

drive.lib :  $(MAKEFILE) rtw_proj.tmw $(MODULES_drive)
	@echo ### Creating $@
	@if exist $@ del $@
	$(LIBCMD) /out:$@ $(MODULES_drive)
	@echo ### $@ Created 

MODULES_pm = \
          pm_26dc3230.obj \
          

pm.lib :  $(MAKEFILE) rtw_proj.tmw $(MODULES_pm)
	@echo ### Creating $@
	@if exist $@ del $@
	$(LIBCMD) /out:$@ $(MODULES_pm)
	@echo ### $@ Created 



clean :
	@echo ### Deleting the objects and $(PROGRAM)
	@del $(OBJS) ..\$(MODEL)_acc.$(MEXEXT) $(wildcard *.obj) $(wildcard *.lib)

#----------------------------- Dependencies -------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

$(SHARED_OBJS) : $(SHARED_BIN_DIR)/%.obj : $(SHARED_SRC_DIR)/%.c 
	$(CC) -outdir $(SHARED_BIN_DIR) $(MEX_FLAGS) $(INCLUDES) $<

$(SHARED_LIB) : $(SHARED_OBJS)
	@echo ### Creating $@ 
	$(LIBCMD) /out:$@ $(FMT_SHARED_OBJS)
	@echo ### $@ Created   


