SUBPROJECTS := linked_list dynamic_array array stack_dynamic_array
BUILD_DIR := build

.PHONY: all $(SUBPROJECTS)

all: $(SUBPROJECTS)

$(SUBPROJECTS):
	mkdir -p $(BUILD_DIR)/$@ && \
	cd $(BUILD_DIR)/$@ && cmake ../../src/$@ && $(MAKE)
	#$(BUILD_DIR)/$@/$@

run_%:
	@$(BUILD_DIR)/$*/$*

# Clean all subprojects
clean:
	rm -rf $(BUILD_DIR)
