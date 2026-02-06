# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -g3 -O0
INCLUDES = -I./imgui -I./imgui/backends
LIBS = -lglfw -lGL -ldl

# Directories
BUILD_DIR = ./build/Debug
SRC_DIR = .
IMGUI_DIR = ./imgui
IMGUI_BACKEND_DIR = ./imgui/backends

# Target executable
TARGET = $(BUILD_DIR)/outDebug

# Source files
SOURCES = SUVAT_GUI.cpp SUVAT_Proj.cpp
IMGUI_SOURCES = $(IMGUI_DIR)/imgui.cpp \
                $(IMGUI_DIR)/imgui_draw.cpp \
                $(IMGUI_DIR)/imgui_tables.cpp \
                $(IMGUI_DIR)/imgui_widgets.cpp \
                $(IMGUI_BACKEND_DIR)/imgui_impl_glfw.cpp \
                $(IMGUI_BACKEND_DIR)/imgui_impl_opengl3.cpp

# Object files
OBJECTS = $(SOURCES:%.cpp=$(BUILD_DIR)/%.o)
IMGUI_OBJECTS = $(BUILD_DIR)/imgui.o \
                $(BUILD_DIR)/imgui_draw.o \
                $(BUILD_DIR)/imgui_tables.o \
                $(BUILD_DIR)/imgui_widgets.o \
                $(BUILD_DIR)/imgui_impl_glfw.o \
                $(BUILD_DIR)/imgui_impl_opengl3.o

# Default target
all: $(TARGET)

# Link target
$(TARGET): $(OBJECTS) $(IMGUI_OBJECTS)
	@echo "Linking $@..."
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)
	@echo "Build successful!"

# Compile main source files
$(BUILD_DIR)/%.o: %.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Compile ImGui core files
$(BUILD_DIR)/imgui.o: $(IMGUI_DIR)/imgui.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/imgui_draw.o: $(IMGUI_DIR)/imgui_draw.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/imgui_tables.o: $(IMGUI_DIR)/imgui_tables.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/imgui_widgets.o: $(IMGUI_DIR)/imgui_widgets.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Compile ImGui backend files
$(BUILD_DIR)/imgui_impl_glfw.o: $(IMGUI_BACKEND_DIR)/imgui_impl_glfw.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/imgui_impl_opengl3.o: $(IMGUI_BACKEND_DIR)/imgui_impl_opengl3.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	rm -f $(BUILD_DIR)/*.o $(TARGET)
	@echo "Clean complete!"

# Run the program
run: $(TARGET)
	@echo "Running SUVAT Calculator..."
	$(TARGET)

.PHONY: all clean run
