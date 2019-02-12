BUILD_DIR = bld/
SOURCE_DIR = src/
INCLUDE_DIR = inc/
PROG_DIR = prog/

CPPFLAGS += -Iinc

rfm-pi_LDFLAGS = -lwiringPi -lcryptopp -lzmq
rfm-pi_OBJS = main.o aes_ecb.o aes_exception.o args.o rfm9x_g.o rfm9x_lora.o

$(PROG_DIR)rfm-pi: Makefile $(addprefix $(BUILD_DIR), $(rfm-pi_OBJS)) | $(PROG_DIR)
	$(LINK.cpp) -g -o $@ $(filter %.o, $^) $(rfm-pi_LDFLAGS)

run-local: $(PROG_DIR)rfm-pi
	$<

run-remote: build-remote
	ssh hc2 "sudo rfm-pi/bld/rfm-pi"

build-remote: sync-source
	ssh hc2 "make -C ~/rfm-pi"

sync-source:
	rsync -arvz -e "ssh -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null" --exclude=bld --exclude=prog --progress . hc2:~/rfm-pi

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(PROG_DIR):
	mkdir $(PROG_DIR)

$(BUILD_DIR)%.o: $(SOURCE_DIR)%.cpp $(INCLUDE_DIR)%.hpp | $(BUILD_DIR)
	$(COMPILE.cpp) -g $< -o $@

$(BUILD_DIR)%.o: $(SOURCE_DIR)%.c $(INCLUDE_DIR)%.h | $(BUILD_DIR)
	$(COMPILE.c) -g $< -o $@

clean:
	rm -r $(PROG_DIR)
	rm -r $(BUILD_DIR)
