define DBG
    @echo *** $(1) ***
endef
################################################################################
OUTPUT_NAME		:=output
EXEC_EXT		:=
OBJ_EXT			:=.o
LIB_STAT_EXT		:=.a

PROJ_SRC_EXT		:=.c
PROJ_HEADER_EXT		:=.h

GT_HEADER_C_EXT 	:=.h
GT_SRC_EXT		:=.cc
	
UT_SRC_EXT		:=.cc
#------------------------------------------------------------------ DIRECTORIES-
#-------------------------------------------------------- PROJ dirs
PROJ_ROOT_DIR        	:=.
PROJ_HEADERS_ROOT_DIR	:=include
PROJ_SRCS_ROOT_DIR	:=src
PROJ_OBJS_ROOT_DIR 	:=build
PROJ_LIBS_ROOT_DIR	:=lib
PROJ_EXEC_ROOT_DIR 	:=bin
# ------------------------------------------------- googletest dirs
GT_ROOT_DIR		:=third_party/googletest/googletest
GT_HEADERS_ROOT_DIR	:= $(GT_ROOT_DIR)/include
GT_SRCS_ROOT_DIR	:= $(GT_ROOT_DIR)/src
# ------------------------------------------------- Unit tests dirs
UT_SRCS_ROOT_DIR	:=test
UT_OBJS_ROOT_DIR 	:=build
UT_LIBS_ROOT_DIR	:=lib
UT_EXEC_ROOT_DIR 	:=bin
#----------------------------------------------------------------- DEPENDENCIES-
#------------------------------------------------------- Proj Depen 
PROJ_DEP_HEADERS_ROOT_DIR	:=$(PROJ_HEADERS_ROOT_DIR)
PROJ_DEP_HEADERS_DIRS	:=						\
			$(PROJ_DEP_HEADERS_ROOT_DIR)
vpath %$(PROJ_HEADER_EXT) $(PROJ_DEP_HEADERS_DIRS)

PROJ_DEP_SRCS_ROOT_DIR	:=$(PROJ_SRCS_ROOT_DIR)
PROJ_DEP_SRCS_DIRS      :=						\
			$(PROJ_DEP_SRCS_ROOT_DIR)
vpath %$(PROJ_SRC_EXT) $(PROJ_DEP_SRCS_DIRS)

PROJ_DEP_OBJS_ROOT_DIR 	:=$(PROJ_OBJS_ROOT_DIR)
PROJ_DEP_OBJS_DIRS 	:=						\
			$(PROJ_DEP_OBJS_ROOT_DIR)
vpath %$(OBJ_EXT) $(PROJ_DEP_OBJS_DIRS)

PROJ_DEP_LIBS_ROOT_DIR	:=$(PROJ_SRCS_ROOT_DIR)
PROJ_DEP_LIBS_DIRS 	:= 						\
			$(PROJ_DEP_LIBS_ROOT_DIR)
vpath %$(LIB_STAT_EXT) 	$(PROJ_DEP_LIBS_DIRS)

PROJ_DEP_EXEC_ROOT_DIR 	:=$(PROJ_EXEC_ROOT_DIR)
PROJ_DEP_EXEC_DIRS 	:=						\
			$(PROJ_DEP_EXEC_ROOT_DIR)
vpath %$(EXEC_EXT) $(PROJ_DEP_EXEC_DIRS)
# ------------------------------------------------ googletest Depen
GT_DEP_HEADERS_ROOT_DIR := $(GT_ROOT_DIR)/include/gtest	
GT_DEP_HEADERS_DIRS	:=						\
			$(GT_DEP_HEADERS_ROOT_DIR)			\
			$(GT_DEP_HEADERS_ROOT_DIR)/internal		\
			$(GT_DEP_HEADERS_ROOT_DIR)/internal/custom
vpath %$(GT_HEADER_C_EXT) $(GT_DEP_HEADERS_DIRS)

GT_DEP_SRCS_ROOT_DIR	:= $(GT_ROOT_DIR)/src
GT_DEP_SRCS_DIRS	:=						\
			$(GT_DEP_SRCS_ROOT_DIR)
vpath %$(GT_SRC_EXT) $(GT_DEP_SRCS_DIRS)

# ------------------------------------------------ Unit tests Depen
UT_DEP_SRCS_ROOT_DIR 	:=$(UT_SRCS_ROOT_DIR)
UT_DEP_SRCS_DIRS	:=						\
			$(UT_DEP_SRCS_ROOT_DIR)
vpath %$(UT_SRC_EXT) $(UT_DEP_SRCS_DIRS)

#--------------------------------------------------------------- COMPILER FLAGS-
#------------------------------------------------ PROJ compilation falgs
#NOTE: MAYBE NEED TO ADD -I/ Instead of -I 
PROJ_CXX		:=g++

PROJ_INC_ROOT_DIR       :=$(PROJ_ROOT_DIR)
PROJ_INC_DIRS		:= 						\
			$(PROJ_INC_ROOT_DIR)
#PROJ_INC_FLAGS		:=-I$(PROJ_ROOT_DIR)
PROJ_INC_FLAGS		:=$(addprefix -I,$(PROJ_INC_DIRS)) 
PROJ_CXX_FLAGS		:=-w -std=c++14 $(PROJ_INC_FLAGS) 
# ----------------------------------------- googletest compilation falgs
GT_INC_DIRS 		:=						\
			$(GT_ROOT_DIR)					\
			$(GT_HEADERS_ROOT_DIR)
GT_INC_FLAGS		:=$(addprefix -I,$(GT_INC_DIRS))
GT_CXX_FLAGS 		:=-isystem $(GT_HEADERS_ROOT_DIR) -g -Wall -Wextra -pthread
#use after creating the library gtest_main.a
GT_LIB_GTESTMAIN_FILE	:=$(PROJ_LIBS_ROOT_DIR)/gtest_main.a
# ----------------------------------------- Unit tests compilation falgs
UT_INC_ROOT_DIR 	:= $(PROJ_INC_DIRS) $(GT_INC_DIRS)
UT_INC_FLAGS		:=
UT_CXX_FLAGS 		:=
#---------------------------------------------------------------------- NAMEING-
#-------------------------------------------------- PROJ Files Naming 
PROJ_SRC_FILES_WITH_DIR	:=$(shell find ./$(PROJ_SRCS_ROOT_DIR) -name '*.c')
PROJ_SRC_FILES 		:=$(notdir $(PROJ_SRC_FILES_WITH_DIR))

PROJ_OBJ_FILES 		:=$(patsubst %$(PROJ_SRC_EXT),%$(OBJ_EXT),$(PROJ_SRC_FILES))
PROJ_OBJ_FILES_WITH_DIR :=$(addprefix $(PROJ_OBJS_ROOT_DIR)/,$(PROJ_OBJ_FILES))

#-------------------------------------------- googletest Files Naming 
#GT_INCLUDE_FILES_WITH_DIR	:=$(shell find ./$(GT_INCLUDE_ROOT_DIR) -name '*.h')
#GT_INCLUDE_FILES	:=$(notdir GT_INCLUDE_FILES_WTH_DIR)

# ------------------------------------------- Unit Tests Files Naming
UT_FILES_NAMETAG	:=_ut
UT_SRC_FILES_NAMETAG 	:=$(addsuffix $(GT_SRC_EXT),$(UT_FILES_NAMETAG))

UT_SRC_FILES_WITH_DIR	:=$(shell find ./$(UT_SRCS_ROOT_DIR) -name '*_ut.cc')
UT_SRC_FILES 		:=$(notdir $(UT_SRC_FILES_WITH_DIR))

UT_OBJ_FILES_NAMETAG 	:=$(addsuffix $(OBJ_EXT),$(UT_FILES_NAMETAG))
UT_OBJ_FILES 		:=$(patsubst %$(GT_SRC_EXT),%$(OBJ_EXT),$(UT_SRC_FILES))
UT_OBJ_FILES_WITH_DIR 	:=$(addprefix ./$(PROJ_OBJS_ROOT_DIR)/,$(UT_OBJ_FILES))

UT_FILES_BASENAME	:=$(basename $(UT_SRC_FILES))
UT_PROJ_OBJ_FILES	:=$(patsubst %$(UT_FILES_NAMETAG),%$(OBJ_EXT),$(UT_FILES_BASENAME))
# -------------------------------------------------------------------- BUILDING-
# ---------------------------------------------- OUTPUT - MAIN TARGET 
.PHONY: all
all:$(OUTPUT_NAME) $(UT_FILES_BASENAME) runapp runtest

.PHONY: app
app: $(OUTPUT_NAME)

.PHONY: test
test: $(UT_FILES_BASENAME)

#for NetBeans default test target name
.PHONY: build-tests
build-tests: $(UT_FILES_BASENAME)

.PHONY : testvar 
testvar:	
	@echo $(PROJ_OBJS_ROOT_DIR)
# Run ---------------------------------------------------------------
.PHONY: run
run:
	$(PROJ_EXEC_ROOT_DIR)/$(OUTPUT_NAME);$(PROJ_EXEC_ROOT_DIR)/$(UT_FILES_BASENAME)

.PHONY: runapp
runapp:
	$(PROJ_EXEC_ROOT_DIR)/$(OUTPUT_NAME)

.PHONY: runtest
runtest:
	$(PROJ_EXEC_ROOT_DIR)/$(UT_FILES_BASENAME)
# Clean -------------------------------------------------------------
.PHONY : clean
clean:	
	rm -f -r $(PROJ_OBJS_ROOT_DIR)
	rm -f -r $(PROJ_LIBS_ROOT_DIR)
	rm -f -r $(PROJ_EXEC_ROOT_DIR)
# ------------------------------------------------- Proj Dependencies
main.o:					\
	linked_list.h

linked_list.o:				\
	linked_list.h			\
	linked_list.c
#-------------------------------------------- Unit Test Dependencies 
linked_list_ut.o: 			\
	linked_list.h			\
	linked_list.c			\
	linked_list_ut.cc
# --------------------------------------------------- GTESTLIBS PREPS
gtest-all.o :
	@echo --------------------------------------------------------* Creating $@ *-
	mkdir -p $(PROJ_OBJS_ROOT_DIR)
	$(PROJ_CXX) $(GT_CXX_FLAGS) $(GT_INC_FLAGS) -c $(GT_SRCS_ROOT_DIR)/gtest-all.cc -o $(PROJ_OBJS_ROOT_DIR)/$@

gtest_main.o :
	@echo --------------------------------------------------------* Creating $@ *-
	mkdir -p $(PROJ_OBJS_ROOT_DIR)
	$(PROJ_CXX) $(GT_CXX_FLAGS) $(GT_INC_FLAGS) -c $(GT_SRCS_ROOT_DIR)/gtest_main.cc -o $(PROJ_OBJS_ROOT_DIR)/$@

#gtest.a : gtest-all.o
	#@echo --------------------------------------------------------* Creating $@ *-
	#mkdir -p $(PROJ_LIBS_ROOT_DIR)
	#$(AR) $(ARFLAGS) $(PROJ_LIBS_ROOT_DIR)/$@ $(addprefix $(PROJ_OBJS_ROOT_DIR)/,$^)	
	#$(AR) $(ARFLAGS) $(PROJ_LIBS_ROOT_DIR)/$@ $^

gtest_main.a : gtest-all.o gtest_main.o 
	@echo --------------------------------------------------------* Creating $@ *-
	mkdir -p $(PROJ_LIBS_ROOT_DIR)
	#$(AR) $(ARFLAGS) $(PROJ_LIBS_ROOT_DIR)/$@ $(addprefix $(PROJ_OBJS_ROOT_DIR)/,gtest-all.o gtest_main.o)

	$(AR) $(ARFLAGS) $(PROJ_LIBS_ROOT_DIR)/$@ $(addprefix $(PROJ_OBJS_ROOT_DIR)/,$^)
	#$(AR) $(ARFLAGS) $(PROJ_LIBS_ROOT_DIR)/$@ $^

# ------------------------------------------------------ Proj Linking
$(OUTPUT_NAME): $(PROJ_OBJ_FILES)
	@echo --------------------------------------------------------* Creating $@ *-
	mkdir -p $(PROJ_EXEC_ROOT_DIR) 
	$(PROJ_CXX) $(PROJ_OBJ_FILES_WITH_DIR) -o $(PROJ_EXEC_ROOT_DIR)/$@
	@echo ========================================================* DONE Stage 1-
# -------------------------------------------------------- UT Linking
$(UT_FILES_BASENAME): $(UT_PROJ_OBJ_FILES) $(UT_OBJ_FILES)  gtest_main.a
	@echo --------------------------------------------------------* Creating $@ *-
	mkdir -p $(UT_EXEC_ROOT_DIR)
	$(PROJ_CXX) $(GT_CXX_FLAGS) -lpthread $(addprefix $(PROJ_OBJS_ROOT_DIR)/,$(UT_OBJ_FILES)) $(addprefix $(PROJ_OBJS_ROOT_DIR)/,$(UT_PROJ_OBJ_FILES)) $(GT_LIB_GTESTMAIN_FILE) -o $(UT_EXEC_ROOT_DIR)/$@
	@echo ========================================================* DONE Stage 2 -

# --------------------------------------------- OBJ Buliding Patterns
%$(OBJ_EXT):%$(PROJ_SRC_EXT)
	@echo --------------------------------------------------------* Creating PROJ_OBJ $@ *-
	mkdir -p $(PROJ_OBJS_ROOT_DIR)
	$(PROJ_CXX) $(PROJ_CXX_FLAGS) -c $< -o $(PROJ_OBJS_ROOT_DIR)/$@ 

# ---------------------------------------------- UT Buliding Patterns
$(UT_OBJ_FILES):%$(OBJ_EXT):%$(GT_SRC_EXT) 
	@echo --------------------------------------------------------* Creating UT_PROJ_OBJ $@ *-
	mkdir -p $(PROJ_OBJS_ROOT_DIR)
	$(PROJ_CXX) $(PROJ_CXX_FLAGS) $(GT_CXX_FLAGS) $(GT_INCLUDE_FLAGS)\
	-c $< -o $(PROJ_OBJS_ROOT_DIR)/$@
	

