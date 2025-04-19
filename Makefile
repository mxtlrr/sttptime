CC := g++
CFLAGS_BACKEND  := -Wall -Wextra -pedantic -g -std=c++17 -Ibackend  -Iinclude
CFLAGS_FRONTEND := -Wall -Wextra -pedantic -g -std=c++17 -Ifrontend -Iinclude

all: sttptime-back sttptime-front

sttptime-back:
	@mkdir -p obj/ bin/
	@mkdir -p obj/backend obj/frontend
	@echo ==== COMPILING STTPTIME BACKEND ====
	@$(foreach file, $(wildcard backend/*.cpp), $(CC) $(CFLAGS_BACKEND) -c $(file) -o obj/backend/$(basename $(notdir $(file))).o; echo CC $(file);)
	@gcc $(CFLAGS_BACKEND) $(wildcard obj/backend/*.o) -o bin/sttptime-backend.exe
	@echo ==== COMPILED  STTPTIME BACKEND ====

sttptime-front:
	@echo ==== COMPILING STTPTIME FRONTEND ====
	@$(foreach file, $(wildcard frontend/*.cpp), $(CC) $(CFLAGS_FRONTEND) -c $(file) -o obj/frontend/$(basename $(notdir $(file))).o; echo CC $(file);)
	@gcc $(CFLAGS_FRONTEND) $(wildcard obj/frontend/*.o) -o bin/sttptime.exe
	@echo ==== COMPILED  STTPTIME FRONTEND ====

clean:
	@del /s /q bin/*.* obj/*.* || rm -rf bin/* obj/*