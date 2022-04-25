FLAGS = -Wall -Wextra -g
EXECUTABLE = Main
TEST = Test

$(EXECUTABLE): $(EXECUTABLE).cpp
	g++ $(FLAGS) $(EXECUTABLE).cpp -o $(EXECUTABLE)
  
run: $(EXECUTABLE)
	./$(EXECUTABLE)
  
$(TEST): $(TEST).cpp
	g++ $(FLAGS) $(TEST).cpp -o $(TEST)
  
run$(TEST): $(TEST)
	./$(TEST)
