SRCDIRS := . SourceFiles
INCDIR := HeaderFiles

SRCS := $(foreach d,$(SRCDIRS),$(wildcard $(d)/*.cpp))
OBJDIR := build
OBJS := $(patsubst %.cpp,$(OBJDIR)/%.o,$(notdir $(SRCS)))

CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++20 -g
CPPFLAGS := -I"$(INCDIR)"

vpath %.cpp $(SRCDIRS)

ifeq ($(OS),Windows_NT)
RM = del /Q
RMRF = rmdir /S /Q
MKDIR = if not exist $(OBJDIR) mkdir $(OBJDIR)
else
RM = rm -f
RMRF = rm -rf
MKDIR = mkdir -p $(OBJDIR)
endif

all: CppLearning.exe

CppLearning.exe: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(MKDIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJDIR):
	$(MKDIR)

clean:
	$(RM) $(OBJDIR)\*.o CppLearning.exe
	$(RMRF) $(OBJDIR)