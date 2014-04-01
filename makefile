CXXFLAGS += -Wextra -Wall -O -I.

TARGET := testprog

.PHONY: all clean
all: $(TARGET)

$(TARGET): testprog.o
	$(CXX) $< -o $@

-include $(TARGET).dep

.cpp.o:
	$(CXX) -c  $(CXXFLAGS) $< -o $@
	$(CXX) -MM $(CXXFLAGS) $< > $(TARGET).dep

clean:
	$(RM) $(TARGET) $(TARGET).dep *.o *~ *.bak
