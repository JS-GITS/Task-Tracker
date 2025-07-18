task-cli: src/main.cpp utilities/utils.cpp utilities/CLI.cpp
	g++ src/main.cpp utilities/utils.cpp utilities/CLI.cpp -o main
