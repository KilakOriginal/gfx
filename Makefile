CC=g++
CFLAGS=-g -Wall -Werror -Wpedantic -I$(VULKAN_SDK_PATH)/include
LDFLAGS = -L$(VULKAN_SDK_PATH)/lib `pkg-config --static --libs glfw3` -lvulkan
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

SHADER=src/shaders
VERT=$(wildcard $(SHADER)/*.vert)
FRAG=$(wildcard $(SHADER)/*.frag)
SPV_VERT=$(VERT:.vert=.vert.spv)
SPV_FRAG=$(FRAG:.frag=.frag.spv)
SPV=$(SPV_VERT) $(SPV_FRAG)

TEST=tests
TESTS=$(wildcard $(TEST)/*.cpp)
TESTBINS=$(patsubst $(TEST)/%.cpp, $(TEST)/bin/%, $(TESTS))

LIBDIR=lib
LIB=$(LIBDIR)/gfx.a

$(SHADER)/%.vert.spv: $(SHADER)/%.vert
	glslc $< -o $@

$(SHADER)/%.frag.spv: $(SHADER)/%.frag
	glslc $< -o $@

shaders: $(SPV)

all:$(LIB)

debug: CFLAGS=-g -Wall -Wpedantic -O0
debug: clean
debug: $(LIB)

release: CFLAGS=-Wall -Werror -Wpedantic -O3 -DNDEBUG
release: clean
release: $(LIB)

$(LIB): $(LIBDIR) $(OBJ) $(OBJS)
	$(RM) $(LIB)
	ar -cvrs $(LIB) $(OBJS)

$(OBJ)/%.o: $(SRC)/%.cpp $(SRC)/%.hpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST)/bin/%: $(TEST)/%.cpp
	$(CC) $(CFLAGS) $< $(OBJS) -o $@ -lcriterion

$(TEST)/bin:
	mkdir $@

$(OBJ):
	mkdir $@

$(LIBDIR):
	mkdir $@

test: $(LIB) $(TEST)/bin $(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test ; done

clean:
	$(RM) -r $(LIBDIR) $(OBJ)

