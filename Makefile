SUBPROJECTS := linked_list dynamic_array array doubly_linked_list fifo_queue stack dynamic_circular_buffer fast_circular_buffer
BUILD_DIR := build

.PHONY: all $(SUBPROJECTS)

all: $(SUBPROJECTS)

clean:
	rm -rf $(BUILD_DIR)

$(SUBPROJECTS):
	mkdir -p $(BUILD_DIR)/$@ && \
	cd $(BUILD_DIR)/$@ && cmake ../../src/$@ && $(MAKE)
	#$(BUILD_DIR)/$@/$@

run-%:
	@$(BUILD_DIR)/$*/$*

debug-%: clean
	@echo "Building in Debug mode..."
	mkdir -p $(BUILD_DIR)/$* && \
	cd $(BUILD_DIR)/$* && cmake -DCMAKE_BUILD_TYPE=Debug ../../src/$* && $(MAKE)
