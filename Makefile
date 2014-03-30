RES=-DXRES=1024 -DYRES=600
#RES=-DXRES=1920 -DYRES=1080
OPTS=-D_R=0xFF -D_G=0xFF -D_B=0xFF -DCELLSIZE=10 -DMARGIN=2 -DFPS=60 -std=gnu++11 -lpthread
FLAGS=-Wall -O2
TARGET=randwalk
FILES=main.cc

$(TARGET): $(FILES)
	g++ $^ $(FLAGS) -o $@ $(OPTS) $(RES)
	@sudo chown root $(TARGET)
	@sudo chmod 4755 $(TARGET)

info:
	@g++ info.cc -o info
	@sudo ./info
	@rm info

install: $(TARGET)
	sudo mv $(TARGET) /usr/local/bin/

uninstall:
	sudo rm /usr/local/bin/$(TARGET)

clean:
	sudo rm $(TARGET)

.PHONY: $(TARGET) info install uninstall clean
