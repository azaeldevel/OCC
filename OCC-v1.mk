

$(TARGET_OUTPUT_DIR)AI/intel.l : $(TARGET_OUTPUT_DIR)/generator
	$(TARGET_OUTPUT_DIR)generator --output $(TARGET_OUTPUT_DIR)AI/intel.l --lang AI --comp lexer
	
$(TARGET_OUTPUT_DIR)AI/occ-intel.lexer.cc : $(TARGET_OUTPUT_DIR)AI/intel.l
	flex --header-file=$(TARGET_OUTPUT_DIR)AI/occ-intel.lexer.hh -o $(TARGET_OUTPUT_DIR)AI/occ-intel.lexer.cc  $(TARGET_OUTPUT_DIR)AI/intel.l
	
	
	
	
$(TARGET_OUTPUT_DIR)AI/intel.y : $(TARGET_OUTPUT_DIR)/generator
	$(TARGET_OUTPUT_DIR)generator --output $(TARGET_OUTPUT_DIR)AI/intel.y --lang AI --comp parser
	
$(TARGET_OUTPUT_DIR)AI/occ-intel.parser.cc : $(TARGET_OUTPUT_DIR)AI/intel.y
	bison  --warnings --debug --report=cex,solved  --report-file=$(TARGET_OUTPUT_DIR)AI/report.txt --header=$(TARGET_OUTPUT_DIR)AI/occ-intel.parser.hh -o $(TARGET_OUTPUT_DIR)AI/occ-intel.parser.cc  $(TARGET_OUTPUT_DIR)AI/intel.y
	
all : $(TARGET_OUTPUT_DIR)AI/occ-intel.parser.cc $(TARGET_OUTPUT_DIR)AI/occ-intel.lexer.cc
