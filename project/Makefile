include ../Make.inc

MPIFLGS = `mpicxx -showme:compile` -DUSE_MPI
MPILNK  = `mpicxx -showme:link` -DUSE_MPI


SRC_DIR = .
INCL_DIR = $(PROJECT_ROOT)/include
OBJ_DIR = build
LIB_DIR = $(PROJECT_ROOT)/lib
TST_DIR = $(PROJECT_ROOT)/test

HEADERS = \
	$(INCL_DIR)/fractal_land.hpp $(INCL_DIR)/ant.hpp $(INCL_DIR)/display.hpp $(INCL_DIR)/pheronome.hpp

SRCS = \
	$(SRC_DIR)/fractal_land.cpp $(SRC_DIR)/ant.cpp $(SRC_DIR)/display.cpp

OBJS = \
	$(OBJ_DIR)/fractal_land.o $(OBJ_DIR)/ant.o $(OBJ_DIR)/display.o


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "\033[33m Compiling " $@ "\033[0m"
	@$(CXX) $(CXXOPT) -I. -I$(INCL_DIR) -I$(OPENGLINC) -c $< -o $@

all: $(HPNUM_ROOT)/include $(LIB_DIR)/libsimants.so test #simants.exe

$(HPNUM_ROOT)/include:
	@mkdir -p $(INCL_DIR)
	@echo "\033[31m Copying includes\033[0m"
	@cp *.hpp $(INCL_DIR)


$(LIB_DIR)/libsimants.so: $(OBJS)
	@echo "\033[35m Linking " $@ "\033[0m"
	@$(CXX) -shared $(CXXOPT) -L$(OPENGLLIBROOT) -o $@ $(OBJS) -lglut -lGLU -lGL 


doc:
	doxygen Doxyfile.in

test: $(TST_DIR)/test_fractal_land.exe $(TST_DIR)/ant_simu.exe

$(TST_DIR)/test_fractal_land.exe: $(LIB_DIR)/libgui.so $(LIB_DIR)/libsimants.so test/test_fractal_land.cpp
	@mkdir -p $(TST_DIR)
	@echo "\033[34m Compiling " $@ "\033[0m"
	@$(CXX) $(CXXOPT) -I$(OPENGLINC) -L$(OPENGLLIBROOT) -L$(LIB_DIR) -I$(INCL_DIR) -o $@ $^ -lgui -lsimants -lglut -lGLU -lGL

$(TST_DIR)/ant_simu.exe: $(LIB_DIR)/libgui.so $(LIB_DIR)/libsimants.so $(SRC_DIR)/ant_simu.cpp
	@mkdir -p $(TST_DIR)
	@echo "\033[34m Compiling " $@ "\033[0m"
	@$(CXX) $(CXXOPT) -I$(OPENGLINC) -L$(OPENGLLIBROOT) -L$(LIB_DIR) -I$(INCL_DIR) -o $@ $^ -lgui -lsimants -lglut -lGLU -lGL

clean:
	@rm -f $(OBJ_DIR)/*.o
	@rm -f $(SRC_DIR)/*~
	@rm -f $(INCL_DIR)/*~
	@rm -f *.exe

# Les dépendances :
$(OBJ_DIR)/fractal_land.o: $(INCL_DIR)/fractal_land.hpp $(SRC_DIR)/fractal_land.cpp 
$(OBJ_DIR)/ant.o: $(INCL_DIR)/fractal_land.hpp $(INCL_DIR)/ant.hpp $(SRC_DIR)/ant.cpp 
$(OBJ_DIR)/display.o: $(INCL_DIR)/fractal_land.hpp $(INCL_DIR)/ant.hpp $(SRC_DIR)/display.cpp

.PHONY: $(HPNUM_ROOT)/include doc
	